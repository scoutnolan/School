configuration DATAFLOW of TEST_BENCH is
  for CONVERTER_TEST
    for L1 : CONVERTERC 
      use entity CONVERTER(DATAFLOW);
    end for;
  end for;
end DATAFLOW;
