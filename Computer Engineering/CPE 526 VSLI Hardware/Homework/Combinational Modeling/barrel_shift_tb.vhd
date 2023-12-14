library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;
entity TEST_BENCH is 
end TEST_BENCH;
architecture BARRELTB of TEST_BENCH is
    signal run, clk : BIT;
    signal pg : BIT_VECTOR(3 downto 0);
    signal C : std_logic_vector(7 downto 0);
    component barrel
        port(a  : in std_logic_vector (7 downto 0);
             s  : in std_logic_vector (2 downto 0);
             en : in std_logic;
             c  : out std_logic_vector (7 downto 0));
    end component barrel;
begin
    L1: barrel
        port map("10000000", to_stdlogicvector(pg(2 downto 0)), to_stdulogic(pg(3)), C);
    L2 : entity PULSE_GEN(alg)
        generic map(4, 20 ns)
        port map(run, pg);
    process
    begin
        run <= '1', '0' after 10ns;
        wait;
    end process;
end BARRELTB;