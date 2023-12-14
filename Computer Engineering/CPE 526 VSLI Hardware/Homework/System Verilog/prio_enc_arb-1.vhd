library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_misc.all;

entity prio_enc_arb is
  generic (
    width     : integer:=8
  );  
  port (
    clk       : in  std_logic;
    reset     : in  std_logic;
    req       : in  std_logic_vector(width-1 downto 0);
    grant     : out std_logic_vector(width-1 downto 0)
  );
end prio_enc_arb;

architecture rtl of prio_enc_arb is
  function ceil_log2 (
     x: natural)
  return natural is begin
     for i in 0 to 31 loop
       if x<=2**i then
         return i;
       end if;
     end loop;
     return 32;
  end ceil_log2;

  component prio_enc_recur
  generic (
    chunk_log : integer:=6;
    width     : integer:=64;
    width_log : integer:=6
  );  
  port (
    in_vec    : in  std_logic_vector(width-1 downto 0);
    out_vec   : out std_logic_vector(width_log-1 downto 0);
    out_vld   : out std_logic
  );
  end component;

  type t_fsm is (idle, sel, ack);
  signal state : t_fsm;
  signal grant_i : std_logic_vector(width-1 downto 0);
  signal req_enc : std_logic_vector(ceil_log2(width)-1 downto 0);
  signal req_enc_vld : std_logic;
  signal req_enc_sel : std_logic_vector(ceil_log2(width)-1 downto 0);
begin

    prio_enc : prio_enc_recur
    generic map (
      chunk_log => 2,
      width     => width,
      width_log => ceil_log2(width)
    ) port map (
      in_vec    => req,
      out_vec   => req_enc,
      out_vld   => req_enc_vld
    );

   process (clk)
   begin
      if (clk'event and clk='1') then
         grant <= (others=>'0');

         if (reset='1') then
            state <= idle;
            req_enc_sel <= (others=>'0');
         else
            if (state=idle) then
              if (req_enc_vld='1') then
                state <= sel;
                req_enc_sel <= req_enc;
              end if;
            elsif (state=sel) then
              grant(conv_integer(req_enc_sel)) <= '1';
              state <= ack;
            else -- ack
              grant(conv_integer(req_enc_sel)) <= '1';
              if (req(conv_integer(req_enc_sel))='0') then
                 state <= idle;
              end if;
            end if;
         end if;
      end if;
   end process;

end rtl;
