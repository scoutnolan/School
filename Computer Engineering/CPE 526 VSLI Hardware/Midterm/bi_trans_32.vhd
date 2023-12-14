library ieee;
use ieee.std_logic_1164.all;

entity BI_TRANS_8 is
  generic(DEL: TIME);
  port(A, B : inout std_logic_vector(7 downto 0); OE_N: in std_logic;
       DIR : in std_logic);
end BI_TRANS_8;

library ieee;
use ieee.std_logic_1164.all;
use work.all;

entity BI_TRANS_32 is
  generic ( DEL : TIME);
  port ( A, B : inout std_logic_vector(31 downto 0);
         OE_N : in std_logic;
         DIR : in std_logic);
end BI_TRANS_32;

architecture STRUCTURAL of BI_TRANS_32 is
begin
  U0 : entity BI_TRANS_8
         generic map (DEL)
         port map (A => A(7 downto 0), B => B(7 downto 0), OE_N => OE_N, DIR => DIR);
  U1 : entity BI_TRANS_8
         generic map (DEL)
         port map (A => A(15 downto 8), B => B(15 downto 8), OE_N => OE_N, DIR => DIR);
  U2 : entity BI_TRANS_8
         generic map (DEL)
         port map (A => A(23 downto 16), B => B(23 downto 16), OE_N => OE_N, DIR => DIR);
  U3 : entity BI_TRANS_8
         generic map (DEL)
         port map (A => A(31 downto 24), B => B(31 downto 24), OE_N => OE_N, DIR => DIR);
end STRUCTURAL;