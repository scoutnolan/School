architecture BEHAVE of CONVERTER is
begin
  process(B)
    variable temp : bit_vector (3 downto 0);
  begin
    temp := B;
    case B is
      when "0000" => E <= "0000";
      when "0100" => E <= "0100";
      when "0101" => E <= "0011";
      when "0110" => E <= "0010";
      when "0111" => E <= "0001";
      when "1000" => E <= "1000";
      when "1001" => E <= "0111";
      when "1010" => E <= "0110";
      when "1011" => E <= "0101";
      when "1111" => E <= "1001";
      when "0001"|"0010"|"0011"|"1100"|"1101"|"1110" => E <= "1111";
    end case;
  end process;
end BEHAVE;
