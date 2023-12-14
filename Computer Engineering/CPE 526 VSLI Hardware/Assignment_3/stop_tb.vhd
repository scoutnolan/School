use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity STOP_TB is
end STOP_TB;

library ieee;
use IEEE.std_logic_1164.all;

architecture  TEST of STOP_TB is
  signal R, A, D, DONE : std_logic;
  signal Z : std_logic_vector(3 downto 0);
  signal DONE_EXP : std_logic;
  signal Z_EXP : std_logic_vector(3 downto 0);
  signal CYC : std_logic_vector(7 downto 0):=x"00";
  signal TIME_BCD : std_logic_vector(7 downto 0);
  signal TIME_EXP : integer range 0 to 99;
  signal MATCH : boolean;
  component STOP 
    port (R, A, D, CLK : in std_logic;
          Z : out std_logic_vector(3 downto 0);
          DONE : out std_logic);
  end component;
  signal CLK : std_logic := '0';
begin
  serToPar : STOP port map (
    R => R,
    A => A,
    D => D,
    CLK => CLK,
    Z => Z,
    DONE => DONE);

  process(CLK)
  begin
    CLK <= not CLK after 5 ns;
  end process;

  process
    variable VLINE: LINE;
    variable V : std_logic_vector (3 downto 0);
    variable H : std_logic_vector (7 downto 0);
    file INVECT : TEXT is "c:/projects/cpe526/hw3/stop/stop_stim.txt";
  begin
    READLINE(INVECT, VLINE); -- read past header
-- Note from Dr. Detwiler: the following lines could be incorporated in a VHDL procedure to skip repeating them throughout
    READLINE(INVECT, VLINE); -- read in the first line
    READ(VLINE, V(0)); -- read in the first character
    R <= V(0);
    READ(VLINE, V(0)); -- read in the next character
    A <= V(0);
    READ(VLINE, V(0)); -- read in the next character
    D <= V(0);
    READ(VLINE, V(0)); -- read in the next character
    DONE_EXP <= V(0);
    READ(VLINE, V(3 downto 0)); -- read in the next 4 characters
    Z_EXP <= V(3 downto 0);
    HREAD(VLINE, H(7 downto 0));
    if (H(3)='U') then -- only read out one digit, and it ended up in the MSB nibble
      TIME_EXP <= conv_integer(H(7 downto 4));
    else -- two digits
      TIME_EXP <= conv_integer(H(7 downto 4))*10 + conv_integer(H(3 downto 0));
    end if;
-- End Note
    while not(ENDFILE(INVECT)) loop
      wait until CLK = '0'; -- change inputs on falling edge
      CYC <= CYC+1;
-- Note from Dr. Detwiler: the following lines could be incorporated in a VHDL procedure to skip repeating them throughout
      READLINE(INVECT, VLINE); -- read in the first line
      READ(VLINE, V(0)); -- read in the first character
      R <= V(0);
      READ(VLINE, V(0)); -- read in the next character
      A <= V(0);
      READ(VLINE, V(0)); -- read in the next character
      D <= V(0);
      READ(VLINE, V(0)); -- read in the next character
      DONE_EXP <= V(0);
      READ(VLINE, V(3 downto 0)); -- read in the next 4 characters
      Z_EXP <= V(3 downto 0);
      HREAD(VLINE, H(7 downto 0));
      TIME_BCD <= H;
      if (H(3)='U') then -- only read out one digit, and it ended up in the MSB nibble
        TIME_EXP <= conv_integer(H(7 downto 4));
      else -- two digits
        TIME_EXP <= conv_integer(H(7 downto 4))*10 + conv_integer(H(3 downto 0));
      end if;
-- End Note
      wait until CLK = '1';
      wait for 4 ns;
-- evaluate outputs some time after rising edge
      MATCH <= DONE_EXP=DONE and Z_EXP=Z and TIME_EXP=conv_integer(CYC);
      assert DONE_EXP=DONE report "mismatch on DONE output" severity error;
      assert Z_EXP=Z       report "mismatch on Z output" severity error;
      assert TIME_EXP=CYC  report "mismatch on CYC output" severity error;
    end loop;
    wait;
  end process;
end TEST;

