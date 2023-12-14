library ieee;
use ieee.std_logic_1164.all;

entity LCD is
  port(A : in std_logic_vector(3 downto 0);
       S : out std_logic_vector(1 to 5));
end LCD;

architecture BEHAV of LCD is
begin
  S <= "11011" when A(0) = '0' else
       "11101" when A(0) = '1' else
       "00000";
end BEHAV;