entity PULSE_GEN is
  generic(N: INTEGER; PER: TIME);
  port(START: in BIT; PGOUT: out BIT_VECTOR(N-1 downto 0));
end PULSE_GEN;
architecture ALG of PULSE_GEN is
  function INT_TO_BIN (INPUT : INTEGER;N : POSITIVE)
    return BIT_VECTOR is
    variable FOUT: BIT_VECTOR(0 to N-1);
    variable TEMP_A: INTEGER:= 0;
    variable TEMP_B: INTEGER:= 0;
  begin   -- Beginning of function body.
    TEMP_A := INPUT;
    for I in N-1 downto 0 loop
      TEMP_B := TEMP_A/(2**I);
      TEMP_A := TEMP_A rem (2**I);
      if (TEMP_B = 1) then
        FOUT(N-1-I) := '1'; else
        FOUT(N-1-I) := '0';
      end if;
    end loop;
    return FOUT;
  end INT_TO_BIN;
begin    -- Beginning of architecture body.
 process(START)
 begin
    for I in 0 to 2**N-1 loop
      PGOUT <= transport INT_TO_BIN(I,N) after I*PER;
    end loop;
  end process;
end ALG;
--Figure 4.43 Input combination generator.
