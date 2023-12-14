library ieee;
use ieee.std_logic_1164.all;

entity JK is
  generic (TPLH : time := 2 ns; 
           TPHL : time := 4 ns);
  port ( J, K, CLK, R : in std_logic;
         Q, QN : out std_logic);
end JK;

architecture JK of JK is
  signal temp : std_logic;
begin
  process (CLK)
  begin
    if (CLK'event and CLK = '0') then
      if (R = '1') then
        temp <= '0';
      else
        case J&K is
          when "00" => null;
          when "01" => temp <= '0';
          when "10" => temp <= '1';
          when "11" => temp <= not temp;
          when others => null;
       end case;
      end if;
    end if;
  end process;
  process (temp)
  begin
    if (temp = '0' and Q = '1') then
      Q <= temp after TPHL;
    elsif (temp = '1' and Q = '0') then
      Q <= temp after TPLH;
    else
      Q <= temp;
    end if;
  end process;
  QN <= not Q;
end JK;

architecture JK_ALT of JK is
  --signal temp : std_logic;
begin
  process (CLK)
    variable temp : std_logic;
  begin
    if (CLK'event and CLK = '0') then
      if (R = '1') then
        temp := '0';
      else
        case J&K is
          when "00" => null;
          when "01" => temp := '0';
          when "10" => temp := '1';
          when "11" => temp := not temp;
          when others => null;
       end case;
      end if;
      if (temp = '0' and Q = '1') then
        Q <= temp after TPHL;
      elsif (temp = '1' and Q = '0') then
        Q <= temp after TPLH;
      else
        Q <= temp;
      end if;
    end if;
  end process;
  QN <= not Q;
end JK_ALT;