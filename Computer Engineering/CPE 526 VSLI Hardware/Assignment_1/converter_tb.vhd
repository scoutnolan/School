use WORK.all;
entity TEST_BENCH is
end TEST_BENCH;

architecture CONVERTER_TEST of TEST_BENCH is
  signal RUN, CLK : BIT;
  signal PG : BIT_VECTOR(3 downto 0);
  signal Z : BIT_VECTOR(3 downto 0);

  component CONVERTERC
    port (B : in BIT_VECTOR(3 downto 0);
          E : out BIT_VECTOR(3 downto 0));
  end component;

  --component ICG
 --   generic (N : INTEGER; PER : TIME);
 --   port (START : in BIT; PGOUT : out BIT_VECTOR (N-1 downto 0));
 -- end component;
    
  --for L2: ICG use entity PULSE_GEN(ALG);

begin
  L1: CONVERTERC
    port map(PG,  Z);

  L2 : entity pulse_gen(alg)
    generic map(4, 20 ns)
    port map(RUN, PG);

  process
  begin
    RUN <= '1', '0' after 10 ns;
    wait;
  end process;
end CONVERTER_TEST;
