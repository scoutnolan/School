configuration BEHAVIORAL of TEST_BENCH is
  for BARRELTB
    for L1 : barrel 
      use entity barrel2(behave);
    end for;
  end for;
end BEHAVIORAL;
