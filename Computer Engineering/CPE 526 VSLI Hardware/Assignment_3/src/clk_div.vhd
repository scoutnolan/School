library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
  
entity Clock_Divider is
    port (clock, reset: in std_logic;
          clock_out: out std_logic);
end Clock_Divider;
  
architecture bhv of Clock_Divider is

signal count: integer:=1;
signal tmp : std_logic := '0';
  
begin
process(clock,reset)
begin
    if(reset='1') then
    count <= 1;
    tmp <= '0';
    elsif(clock'event and clock='1') then
        count <= count+1;
        if (count = 50000000) then
            tmp <= NOT tmp;
            count <= 1;
        end if;
    end if;
    clock_out <= tmp;
    end process;
end bhv;
