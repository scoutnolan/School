use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity RYG_TB is
end RYG_TB;

library ieee;
use IEEE.std_logic_1164.all;

architecture  TEST of RYG_TB is
  signal R, FS, MS, C, FM, MM : std_logic;
  component ALARM 
    port (CLK, FS, MS, R, C : in std_logic;
          FM, MM : out std_logic);
  end component;
  for U1 : ALARM use entity work.alarm(synth);
  signal CLK : std_logic := '0';
begin
  U1: ALARM port map (CLK, FS, MS, R, C, FM, MM);
  process(CLK)
  begin
    CLK <= not CLK after 5 ns;
  end process;
  process
    variable VLINE: LINE;
    variable V : bit_vector (3 downto 0);
    file INVECT : TEXT is "alarm.txt";
  begin
    READLINE(INVECT, VLINE);
    READLINE(INVECT, VLINE);
    READ(VLINE, V);
    FS <= V(3);
    MS <= V(2);
    R <= V(1);
    C <= V(0);
    while not(ENDFILE(INVECT)) loop
      wait until CLK = '0';
      READLINE(INVECT, VLINE);
      READ(VLINE, V);
      FS <= V(3);
      MS <= V(2);
      R <= V(1);
      C <= V(0);
      wait until CLK = '1';
      wait for 2 ns;
    end loop;
    wait;
  end process;
end TEST;

