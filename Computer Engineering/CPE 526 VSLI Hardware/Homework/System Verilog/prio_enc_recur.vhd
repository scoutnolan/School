library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_misc.all;

entity prio_enc_recur is
  generic (
    chunk_log : integer:=2;
    width     : integer:=44;
    width_log : integer:=6
  );  
  port (
    in_vec    : in  std_logic_vector(width-1 downto 0);    -- vector to be encoded
    out_vec   : out std_logic_vector(width_log-1 downto 0);-- encoded value
    out_vld   : out std_logic                              -- input vector is all zeros when '0'
  );
end prio_enc_recur;

architecture rtl of prio_enc_recur is

  function max (
     x: integer;
     y: integer)
  return integer is begin
     if x>y then
       return x;
     else
       return y;
     end if;
  end max;

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

  constant chunk         : natural := (2**chunk_log);
  constant sub_width_log : natural := max(width_log-chunk_log,0);
  constant sub_width     : natural := (2**sub_width_log);
  constant num_inst      : natural := ((width-1)/sub_width)+1;

  signal in_vec_ext  : std_logic_vector((2**width_log)-1 downto 0):=(others=>'0');

begin

  g_ext : if (2**width_log)>width generate
     in_vec_ext((2**width_log)-1 downto in_vec'length) <= (others=>'0');
  end generate;
  in_vec_ext(in_vec'range) <= in_vec;

  -- recursively instantiate the same unit
  g_recur : if width_log>chunk_log generate
    type t_vecN is array (natural range <>) of std_logic_vector(sub_width_log-1 downto 0);
    signal sub_vec     : t_vecN(0 to num_inst-1):=(others=>(others=>'0'));
    signal sub_vld     : std_logic_vector(0 to num_inst-1):=(others=>'0');
  begin
    g_units : for i in 0 to num_inst-1 generate
       urecur : prio_enc_recur
       generic map (
          chunk_log => chunk_log,
          width     => sub_width,
          width_log => sub_width_log
       ) port map (
          in_vec    => in_vec_ext(((i+1)*sub_width)-1 downto i*sub_width),
          out_vec   => sub_vec(i),
          out_vld   => sub_vld(i)
       );
    end generate;

    process (sub_vec,sub_vld)
    begin
       out_vld <= '0';
       out_vec <= (others=>'0');
       for i in num_inst-1 downto 0 loop
          if (sub_vld(i)='1') then
             out_vld <= '1';
             out_vec(width_log-1 downto sub_width_log) <= conv_std_logic_vector(i,width_log-sub_width_log);
             out_vec(sub_width_log-1 downto 0) <= sub_vec(i);
          end if;
       end loop;
    end process;
  end generate;
   
  -- this is the lowest level of the unit - encode this vector and return the status
  g_norecur : if width_log<=chunk_log generate
    process (in_vec)
    begin
       out_vld <= '0';
       out_vec <= (others=>'0');
       for i in width-1 downto 0 loop
          if (in_vec(i)='1') then
             out_vld <= '1';
             out_vec <= conv_std_logic_vector(i,width_log);
          end if;
       end loop;
    end process;
  end generate;

end rtl;