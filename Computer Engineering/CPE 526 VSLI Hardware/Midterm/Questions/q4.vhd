entity lfsr_multi_comp is 
  generic ( 
    poly_size         : integer;  -- polynomial size (degree) 
    vec_size          : integer;  -- output vector size 
    num_bits_gen      : integer;  -- number of bits to generate at a time 
    tap_vec           : std_logic_vector  -- msb tap is implied 
  ); 
  port ( 
    lfsr_state        : in  std_logic_vector(poly_size-1 downto 0);-- input lfsr state 
    lfsr_state_next   : out std_logic_vector(poly_size-1 downto 0);-- output lfsr state  
    bits_vec          : out std_logic_vector(vec_size-1 downto 0)  -- output bits generated 
  ); 
end lfsr_multi_comp; 
architecture rtl of lfsr_multi_comp is 
begin 
   process (lfsr_state) 
      variable lfsr, lfsr_next : std_logic_vector(poly_size-1 downto 0); 
   begin 
      lfsr := lfsr_state; 
      for i in vec_size-1 downto 0 loop 
         if i>=(vec_size-num_bits_gen) then  -- generate a bit 
            lfsr_next(poly_size-1 downto 1) := lfsr(poly_size-2 downto 0); 
            lfsr_next( 0) := lfsr(poly_size-1);  -- implied msb tap 
            for j in 0 to poly_size-1 loop 
               if tap_vec(j)='1' then 
                  lfsr_next( 0) := lfsr_next( 0) xor lfsr(j); 
               end if; 
            end loop; 
            lfsr := lfsr_next; 
            bits_vec(i) <= lfsr(0); 
         else 
            bits_vec(i) <= '0';  -- zero pad 
         end if; 
      end loop; 
      lfsr_state_next <= lfsr; 
   end process; 
end rtl;


library ieee; 
use ieee.std_logic_1164.all; 
entity myLfsr is 
   port ( 
      clk           : in  std_logic;  -- system clock 
      srst          : in  std_logic;  -- sync 
      clk_en        : in  std_logic; 
      lfsr_out      : out std_logic_vector(15 downto 0) 
   ); 
end myLfsr; 
architecture rtl of myLfsr is 
   component lfsr_multi_comp 
      generic ( 
         poly_size  : integer;  -- polynomial size (degree) 
         vec_size   : integer;  -- output vector size 
         num_bits_gen   : integer;  -- number of bits to generate at a time 
         tap_vec    : std_logic_vector  -- msb tap is implied
         ); 
         port ( 
            lfsr_state : in  std_logic_vector(poly_size-1 downto 0);  -- input lfsr state 
            lfsr_state_next : out std_logic_vector(poly_size-1 downto 0);  -- output lfsr state  
            bits_vec : out std_logic_vector(vec_size-1 downto 0)    -- output bits generated 
         ); 
      end component; 
      signal prbs_state_in    : std_logic_vector(35 downto 0); 
      signal prbs_state_out   : std_logic_vector(35 downto 0); 
   begin 
     lfsr_inst : lfsr_multi_comp 
      generic map( 
         poly_size  => 36, 
         vec_size => 16, 
         num_bits_gen => 16, 
         tap_vec => x"000000800" -- x^36 + x^12 + 1 
      ) 
      port map( 
         lfsr_state => prbs_state_in, 
         lfsr_state_next => prbs_state_out, 
         bits_vec => lfsr_out 
      ); 
      process (clk) 
      -- MODIFICATIONS 
         if(clk'event) then
            if(clk_en = '1') then
               if(srst = '1') then
                  prbs_state_out <= x"111111111"
            else if (clk_en  = '0')
                  prbs_state_out <= prbs_state_in;
      end if;
      end if;
      end if;
      end if;               
      begin          
end process;
end rtl;