use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity RYG_TB is
end RYG_TB;

library ieee;
use IEEE.std_logic_1164.all;

architecture TEST of RYG_TB is
    signal RS : std_logic_vector(1 downto 0); -- RS value
    signal LI : std_logic_vector(2 downto 0); -- RYG value
    signal LI_EXP : std_logic_vector(2 downto 0); -- RYG value from txt
    signal TIME_BCD : std_logic_vector(7 downto 0); 
    signal CYC : std_logic_vector(7 downto 0):=x"00";
    signal TIME_EXP : integer range 0 to 99;
    signal MATCH : boolean;
    component RYG
        port(CLK : in std_logic;
            RS : in std_logic_vector(1 downto 0);
            LI : out std_logic_vector(2 downto 0));
    end component;
    component Clock_Divider is
      port (clock, reset: in std_logic;
            clock_out: out std_logic);
    end component;
    signal CLK : std_logic := '0';
begin
serToPar : RYG port map (
    RS => RS,
    LI => LI,
    CLK => CLK);

process(CLK) -- process CLK for RYG and assign it to the Clock_Divider.
begin
    CLK <= not CLK after 5 ns;
end process;

process
    variable VLINE: LINE;
    variable C : std_logic; -- clock
    variable V : std_logic_vector (1 downto 0); -- RS
    variable Y : std_logic_vector (2 downto 0); -- RYG
    variable H : std_logic_vector (7 downto 0); -- TIME
    file INVECT : TEXT is "/home/student/npa0002/CPE526_SP22/Assignment_3/race_active_low.txt";
  begin
    READLINE(INVECT, VLINE); -- read past header
    READLINE(INVECT, VLINE); -- read in the first line
    READ(VLINE, V(1 downto 0)); -- read in RS
    RS <= V(1 downto 0);
    READ(VLINE, Y(2 downto 0)); -- read in RYG
    LI_EXP <= Y(2 downto 0);
    HREAD(VLINE, H(7 downto 0));
    if (H(3)='U') then -- only read out one digit, and it ended up in the MSB nibble
      TIME_EXP <= conv_integer(H(7 downto 4));
    else -- two digits
      TIME_EXP <= conv_integer(H(7 downto 4))*10 + conv_integer(H(3 downto 0));
    end if;
    while not(ENDFILE(INVECT)) loop
      wait until CLK = '0'; -- change inputs on falling edge
      CYC <= CYC + 1;
      READLINE(INVECT, VLINE); -- read in the first line
      READ(VLINE, V(1 downto 0)); -- read in RS
      RS <= V(1 downto 0);
      READ(VLINE, Y(2 downto 0)); -- read in RYG
      LI_EXP<= Y(2 downto 0);
      HREAD(VLINE, H(7 downto 0));
      TIME_BCD <= H;
      if (H(3)='U') then -- only read out one digit, and it ended up in the MSB nibble
        TIME_EXP <= conv_integer(H(7 downto 4));
      else -- two digits
        TIME_EXP <= conv_integer(H(7 downto 4))*10 + conv_integer(H(3 downto 0));
      end if;
      wait until CLK = '1';
      wait for 4 ns;
      MATCH <= LI=LI_EXP and TIME_EXP=conv_integer(CYC);
      assert LI=LI_EXP report "mismatch on LIGHT output" severity error;
      assert TIME_EXP=CYC  report "mismatch on CYC output" severity error;
    end loop;
    wait;
  end process;
end TEST;

