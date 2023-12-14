use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity RYG is
port(CLK : in std_logic;
    RS : in std_logic_vector(1 downto 0);
    LI : out std_logic_vector(2 downto 0));
end RYG;

architecture SWITCH of RYG is
  type STATE_TYPE is (R0, Y1, G2, G3, G4); -- R0 for red, Y1 for yellow, G2 for green. G3, G4, G5 for waiting
  signal START_REQ : std_logic;
  signal STATE: STATE_TYPE;
begin

STR : process(CLK, RS(0))
begin
  if(RS(0) = '0') then
    START_REQ <= '1';
  elsif(CLK'event and CLK = '1') then 
    if(STATE /= R0) then
      START_REQ <= '0';
    end if;
  end if;
end process;

CONTROL : process (CLK, RS(1))
begin
  if(RS(1) = '0') then
    STATE <= R0;
  elsif (CLK'event and CLK = '1' and START_REQ = '1') then
    case STATE is
      when R0 => 
        STATE <= Y1; -- Next state is Y1 (yellow)
      when Y1 => 
        STATE <= G2; -- Next state is G2 (green)                       
      when G2 => 
        STATE <= G3; -- Next state is G3 (green)
      when G3 =>
        STATE <= G4; -- Next state is G4 (green)   
      when G4 =>
        STATE <= R0; -- Next state is R0 (red)        
    end case;    
  end if;
end process CONTROL;

OUTPUT: process (STATE, CLK)  -- Here is where we need to add the time delay. 
begin
    case STATE is
      when R0 =>      -- Red is active
        LI <= "100";
      when Y1 =>      -- Yellow is active
        LI <= "010";
      when G2 =>      -- Green is active (1s)
        LI <= "001";
      when G3 =>      -- Green is active (2s)
        LI <= "001";
      when G4 =>      -- Green is active (3s)
        LI <= "001";
    end case;
end process OUTPUT;
end SWITCH;


-- Lecture code.
use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

entity race_light is
  port(reset, start : in std_logic;
       clock : in std_logic;        -- 50 Mhz clock
       clock_1hz_en : in std_logic; -- 1Hz clock enable
       red, yellow, green : out std_logic
       );

-- State machine descirption

architecture rtl of race_light is
  type t_state is (red_state, yellow_state, green_state1, green_state2, green_state3);
  signal START_REQ : std_logic;
  signal state : t_state;
begin

  START_PRESS : process(clock)
  begin
  if(clock'event and clock = '1') then
    if(start = '0') then
      start_req <= '1';
    elsif(state /= red_state) then
      start_req <= '0';
    end if;
  end if;
end process;

CONTROL : process (clock)
begin 
  if(clock'event and clock = '1') then
    if(reset = '0') then
        state <= red_state;
    elsif(clk_1hz_en) then
      case state is
        when red_state =>
          if(start_req = '1') then
            state <= yellow_state;
          end if;
        when yellow_state => 
            state <= green_state1;
        when green_state1 =>
            state <= green_state2;
        when green_state2 =>
            state <= green_state3;
        when green_state3 =>
            state <= red_state;
        when others =>
            state <= red_state;
      end case;
    end if;
end process CONTROL;

red <= '1' when state = red_state else '0';
yellow <= '1' when state = yellow_state else '0';
green <= when state /= red_state and state /= yellow_state else '0';

end rtl;


      