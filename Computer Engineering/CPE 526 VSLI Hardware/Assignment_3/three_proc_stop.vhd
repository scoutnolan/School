library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;


entity STOP is
  port (R, A, D, CLK: in std_logic;
        Z: out std_logic_VECTOR(3 downto 0);
        DONE: out std_logic);
end STOP;

-- State Machine Description
-- for Serial to Parallel Converter (STOP)
architecture THREE_PROC OF STOP is
  type STATE_TYPE is (S0, S1, S2, S3, S4, S5);
  signal STATE: STATE_TYPE;
  signal SHIFT_REG: std_logic_VECTOR (3 downto 0);
begin

-- Process to perform data operations
DATA : process (CLK)
begin
  if (CLK'event and CLK = '1') then
  case STATE is
    when S0|S5       => null;
    when S1|S2|S3|S4 => SHIFT_REG <= D & SHIFT_REG(3 downto 1);
  end case;
end if;
end process DATA;

CONTROL : process (CLK)
begin
  if (CLK'event and CLK = '1') then
    STATE <= S0;
    case STATE is
      when S0 => if (R = '0' and A = '1') then
                   STATE <= S1;
                 end if;
      when S1 => if (R = '0') then
                   STATE <= S2;
                 end if;
      when S2 => if (R = '0') then
                   STATE <= S3;
                 end if;
      when S3 => if (R = '0') then
                   STATE <= S4;
                 end if;
      when S4 => if (R = '0') then
                   STATE <= S5;
                 end if;
      when S5 => if (R = '0' and A = '1') then
                   STATE <= S1;
                 end if;
    end case;
  end if;
end process CONTROL;

--
-- Output process
--
  OUTPUT: process (STATE, CLK)
  begin
    if (CLK'EVENT and CLK = '0') then
      case STATE is
        when S0 to S4 =>
          DONE <= '0';
        when S5 =>
          DONE <= '1';
          Z <= SHIFT_REG;
      end case;
    end if;
  end process OUTPUT;
end THREE_PROC;
