-- fpga4student.com: FPGA projects, Verilog projects, VHDL projects
-- VHDL project: VHDL code for single-cycle MIPS Processor
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE IEEE.numeric_std.all;  
-- VHDL code for the Instruction Memory of the MIPS Processor
entity Instruction_Memory_VHDL is
port (
 pc: in std_logic_vector(15 downto 0);
 instruction: out  std_logic_vector(15 downto 0)
);
end Instruction_Memory_VHDL;

architecture Behavioral of Instruction_Memory_VHDL is
signal rom_addr: std_logic_vector(3 downto 0);
 -- lw $3, 0($0) -- pc=0
 -- Loop: sltiu  $1, $3, 11= pc = 2
 -- beq $1, $0, Skip = 4 --PCnext=PC_current+2+BranchAddr
 -- add $4, $4, $3 = 6
 -- addi $3, $3, 1 = 8
 -- beq $0, $0, Loop--a
 -- Skip c = 12 = 4 + 2 + br
 type ROM_type is array (0 to 15 ) of std_logic_vector(15 downto 0);
 constant rom_data: ROM_type:=(
      "1110100010001010", -- addi $1, $2, 10
      "0000010010100000", -- add $2, $1, $1
      "0000100010110001", -- sub $3, $2, $1
      "0000010111000010", -- and $4, $3, $1
      "0000110011000011", -- or $4, $3, $1
      "0000010101000100", -- slt $4, $1, $2
      "0010011000001100", -- slti $4, $1, 12
      "1001010010000000", -- lw $5, 0($1)
      "1011010010000000", -- sw $5, 0($1)
      "0100000111110100", -- j 1000
      "0110000111110100", -- jal 1000
      "1100010100000111", -- beq $1, $2, 7
      "0000010000001000", -- jr $1
      "0000000000000000", -- no instruction
      "0000000000000000",  -- no instruction
      "0000000000000000"  -- no instruction
  );
begin

 rom_addr <= pc(4 downto 1);
  instruction <= rom_data(to_integer(unsigned(rom_addr))) when pc < x"0020" else x"0000";

end Behavioral;

   -- "Out of the box" instructions
   --"1000000110000000",
   --"0010110010001011",
   --"1100010000000011",
   --"0001000111000000",
   --"1110110110000001",
   --"1100000001111011",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000",
   --"0000000000000000"