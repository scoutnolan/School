Library ieee; 
Use ieee.std_logic_1164.all; 
entity rst_sync is 
   port ( 
      pin_arst : in  std_logic;  -- async reset 
      clk      : in  std_logic;  -- system clock 
      logic_arst     : out std_logic   -- async assert, sync. negate 
   ); 
end rst_sync; 
architecture student of rst_sync is 
-- your code here, don’t forget to separate your declarations from your  
-- arch body with keyword “begin”
    signal inputFF1 : std_logic;
    signal inputFF2 : std_logic;
    signal inputFF3 : std_logic;
begin;
    process(clk)
    begin
        if clk'event and clk = '1' then
            if(pin_arst = '1') then     -- if the reset pin is activated...
                inputFF1 <= null;
                inputFF2 <= inputFF1;
                inputFF3 <= inputFF2;                
            else                        -- else the reset pin is not activated.
                inputFF1 <= inputFF1;
                inputFF2 <= inputFF1;
                inputFF3 <= inputFF2;
            end if;
        end if;
    end process;
    logic_arst <= inputFF3;
end student;


