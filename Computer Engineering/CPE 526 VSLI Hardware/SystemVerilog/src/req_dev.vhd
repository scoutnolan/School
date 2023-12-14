library ieee;
use ieee.std_logic_1164.all;

entity REQ_DEV is
  port(GEN_REQ : in std_logic;
       REQ_TIME : in integer range 0 to 100;
       REQUEST : out std_logic;
       GRANT : in std_logic;
       RESET, CLK : in std_logic);
end REQ_DEV;

architecture BEHAV of REQ_DEV is
  type STATE_TYPE is (IDLE, COUNT_LOAD, COUNT_DOWN);
  signal STATE : STATE_TYPE;
  signal DEBUG : integer range 0 to 100;
begin
  cntdwn : process(RESET, CLK)
    variable COUNT : integer range 0 to 100;
  begin
    if (RESET = '1')then
      STATE <= IDLE;
      REQUEST <= '0';
    elsif (CLK'event and CLK = '1') then
      case STATE is
        when IDLE => COUNT := 0; 
                     if (GEN_REQ = '1') then
                       STATE <= COUNT_LOAD;
                     else
                       STATE <= IDLE;
                     end if;
                     REQUEST <= '0';
        when COUNT_LOAD => COUNT := REQ_TIME;
                            STATE <= COUNT_DOWN;
                            REQUEST <= '1';
        when COUNT_DOWN => COUNT := COUNT - 1;
                           if (COUNT = 0) then 
                             STATE <= IDLE;
                           else
                             STATE <= COUNT_DOWN;
                           end if;
                           REQUEST <= '1';
      end case;
    end if;
    DEBUG <= COUNT;
  end process cntdwn;
end BEHAV;
