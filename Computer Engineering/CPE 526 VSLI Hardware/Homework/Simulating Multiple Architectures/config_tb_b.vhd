configuration BEHAVIORAL of TEST_BENCH is
  for CONVERTER_TEST
    for L1 : CONVERTERC 
      use entity CONVERTER(BEHAVE);
    end for;
  end for;
end BEHAVIORAL;
