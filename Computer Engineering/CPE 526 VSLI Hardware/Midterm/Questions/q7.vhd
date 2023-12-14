use WORK.all;
library ieee;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_textio.all;
use std.TEXTIO.all;

signal b : std_logic_vector(7 downto 0); -- this is the input to the function;                                             -- b0 through b7 in the column above 
signal b_prime : std_logic_vector(7 downto 0); -- this is the output 
constant c : std_logic_vector(7 downto 0) := x”63”; -- this is the constant addend

entity num7 is
    port(b0, b1, b2, b3, b4, b5, b6, b7 : std_logic_vector(7 downto 0);
         bin : in std_logic_vector(7 downto 0);
         bp : out std_logic_vector (7 downto 0));
end num7;

process num7
begin
    b0 <= "10001111";
    b1 <= "11000111";
    b2 <= "11100011";
    b3 <= "11110001";
    b4 <= "11111000";
    b5 <= "01111110";
    b6 <= "00111110";
    b7 <= "00011111";
    for loop
        b_prime <= b0 xor b;
        -- running out of time... would continue down with b1, b2 etc.
    end loop;
end process num7
