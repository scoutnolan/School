library ieee;
use ieee.std_logic_1164.all;

entity ARBITER is
  port(REQ : in   std_logic_vector(0 to 3);
       GRANT : out std_logic_vector(0 to 3);
       RESET, CLK : in std_logic);
end ARBITER;

architecture BEHAV of ARBITER is
  type STATE_TYPE is (INIT, REQ0, GNT0, REQ1, GNT1, REQ2, GNT2, REQ3, GNT3);
  signal CURRENT_STATE, NEXT_STATE : STATE_TYPE;
begin
  process(CURRENT_STATE, REQ)
  begin
    if (CURRENT_STATE = INIT) then
      NEXT_STATE <= REQ0;
    elsif (CURRENT_STATE = REQ0) then
      if (REQ(0) = '1') then
        NEXT_STATE <= GNT0;
      else
        NEXT_STATE <= REQ1;
      end if;
    elsif (CURRENT_STATE = GNT0) then
      if (REQ(0) = '1') then
        NEXT_STATE <= GNT0;
      else
        NEXT_STATE <= REQ1;
      end if;
    elsif (CURRENT_STATE = REQ1) then
      if (REQ(1) = '1') then
        NEXT_STATE <= GNT1;
      else
        NEXT_STATE <= REQ2;
      end if;
    elsif (CURRENT_STATE = GNT1) then
      if (REQ(1) = '1') then
        NEXT_STATE <= GNT1;
      else
        NEXT_STATE <= REQ2;
      end if;
    elsif (CURRENT_STATE = REQ2) then
      if (REQ(2) = '1') then
        NEXT_STATE <= GNT2;
      else
        NEXT_STATE <= REQ3;
      end if;
    elsif (CURRENT_STATE = GNT2) then
      if (REQ(2) = '1') then
        NEXT_STATE <= GNT2;
      else
        NEXT_STATE <= REQ3;
      end if;
   elsif (CURRENT_STATE = REQ3) then
      if (REQ(3) = '1') then
        NEXT_STATE <= GNT3;
      else
        NEXT_STATE <= REQ0;
      end if;
    elsif (CURRENT_STATE = GNT3) then
      if (REQ(3) = '1') then
        NEXT_STATE <= GNT3;
      else
        NEXT_STATE <= REQ0;
      end if;
    else
      NEXT_STATE <= INIT;
    end if;
  end process;

  process (RESET, CLK)
  begin
    if (RESET = '1') then
      CURRENT_STATE <= INIT;
    elsif (CLK'event and CLK = '1') then
      CURRENT_STATE <= NEXT_STATE;
    end if;
  end process;

  process (RESET, CLK)
  begin
    if (RESET = '1') then
      GRANT <= "0000";
    elsif (CLK'event and CLK = '0') then
      case CURRENT_STATE is
        when INIT|REQ0|REQ1|REQ2|REQ3 => GRANT <= "0000";
        when GNT0 => GRANT <= "1000";
        when GNT1 => GRANT <= "0100";
        when GNT2 => GRANT <= "0010";
        when GNT3 => GRANT <= "0001";
      end case;
    end if;
  end process;
end BEHAV;
