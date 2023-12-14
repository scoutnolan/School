library ieee;
use ieee.std_logic_1164.all;

entity SHIFTER is
  port(DATA_IN: in BIT_VECTOR(3 downto 0);
       SR, SL: in BIT; IL, IR: in BIT;
       ASR : in BIT;
       DATA_OUT: out BIT_VECTOR(3 downto 0));
end SHIFTER;

architecture  ALG of SHIFTER is
begin
  process(SR, SL, DATA_IN, IL, IR, ASR)
    variable CON: BIT_VECTOR(0 to 1);
  begin
    CON := SR&SL;
    case CON is
      when "00" => DATA_OUT <= DATA_IN;
      when "01" => DATA_OUT <= DATA_IN(2 downto 0) & IL;
      when "10" => 
        if (ASR = '0') then
          DATA_OUT <= IR & DATA_IN(3 downto 1);
        else
          DATA_OUT <= DATA_IN(3) & DATA_IN(3 downto 1);
        end if;
      when "11" => DATA_OUT <= DATA_IN;
    end case;
  end process;
end ALG;

architecture CONCURRENT of SHIFTER is
  signal RSHIFT : BIT;
begin
  RSHIFT <= IR when ASR = '0' else DATA_IN(3);
  DATA_OUT <= DATA_IN when SR&SL = "00" else 
             DATA_IN(2 downto 0) & IL when SR&SL = "01" else
             RSHIFT & DATA_IN(3 downto 1) when SR&SL = "10" else
             DATA_IN;
end CONCURRENT;
  

