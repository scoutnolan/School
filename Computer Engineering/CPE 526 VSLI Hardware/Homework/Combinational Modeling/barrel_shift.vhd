library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity barrel2 is  
port (a : in std_logic_vector (7 downto 0);  
      s : in std_logic_vector (2 downto 0);  
      en : in std_logic; 
      c : out std_logic_vector (7 downto 0));  
end entity barrel2;

architecture behave of barrel2 is 
      -- signal data : unsigned(7 downto 0);
      -- signal shft : unsigned(2 downto 0);
      -- signal shft_result : unsigned(7 downto 0);
begin
      shift: process(a, s, en)
      variable shft_result: std_logic_vector(7 downto 0);
      -- data <= unsigned(a);
      -- shft <= unsigned(s);
      -- process(all)
      begin
            if(en = '1') then
                  shft_result := "ZZZZZZZZ";
            elsif(en = '0') then
                  shft_result := a;
                  case s is
                        when "001" => shft_result := shft_result(7-1 downto 0)&shft_result(7 downto 8-1);
                        when "010" => shft_result := shft_result(7-2 downto 0)&shft_result(7 downto 8-2);
                        when "011" => shft_result := shft_result(7-3 downto 0)&shft_result(7 downto 8-3);
                        when "100" => shft_result := shft_result(7-4 downto 0)&shft_result(7 downto 8-4);
                        when "101" => shft_result := shft_result(7-5 downto 0)&shft_result(7 downto 8-5);
                        when "110" => shft_result := shft_result(7-6 downto 0)&shft_result(7 downto 8-6);
                        when "111" => shft_result := shft_result(7-7)&shft_result(7 downto 8-7);
                        when others => null;
                  end case;
                  c <= shft_result;
            end if;
      end process shift;
end behave;