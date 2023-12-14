library ieee; 
use ieee.std_logic_1164.all; 
entity pulse_ext is 
   generic ( 
      arst0_srst1  : std_logic := '0' 
      len : natural := '0'  -- MODIFICATION
   ); 
   port ( 
      clk         : in  std_logic; 
      arst_g      : in  std_logic; 
      srst_g      : in  std_logic; 
      sig         : in  std_logic; 
      pulse       : out std_logic 
   ); 
end pulse_ext; 
architecture rtl of pulse_ext is 
   signal count : natural range 0 to 7; 
begin 
   p : process(arst_g, clk) 
      procedure reset_signals is 
      begin 
         count   <= 0; 
         pulse   <= '0'; 
      end procedure; 
   begin 
        if arst0_srst1 = '0' and arst_g=’1’  then 
            reset_signals; 
        elsif clk'event and clk = '1' then 
            if arst0_srst1 = '1' and srst_g=’1’  then 
                reset_signals; 
            else 
                if sig = '1' then 
                    pulse <= '1'; 
                    count <= 0; 
                else 
                    if count = 7 then 
                    pulse <= '0'; 
                else 
                    count <= count + 1; 
            end if; 
            end if; 
        end if; 
        end if;
        -- MODIFICATION, if we are outside of the loop and pulse is high,
        -- then increment the natural variable len. 
        if pulse = '1' then 
            len := len + 1;
        else 
            len := len;
        end if;
end process; 
end rtl; 