package utility is
  procedure scan_results(results : in BIT_VECTOR;
                         majority_value : out BIT;
                         majority_count : out NATURAL;
                         tie : out BOOLEAN);
end package utility;
package body utility is
   procedure scan_results(results : in BIT_VECTOR;
                         majority_value : out BIT;
                         majority_count : out NATURAL;
                         tie : out BOOLEAN) is
     variable  z_count, o_count : natural := 0;
   begin
     tie := FALSE;
     majority_value := '1';
     for i in results'range loop
       if (results(i) = '1') then
         o_count := o_count + 1;
       else
         z_count := z_count + 1;
       end if;
     end loop;
     if (z_count > o_count) then
       majority_count := z_count;
       majority_value := '0';
     elsif (o_count > z_count) then
       majority_count := o_count;
     else
       majority_count := o_count;
       tie := TRUE;
     end if;
   end scan_results;
end package body utility;

use work.utility.all;

entity scan_entity is
end scan_entity;

architecture procedure_calls of scan_entity is
begin
  process
    variable majority_value : BIT;
    variable majority_count : NATURAL;
    variable tie : BOOLEAN;
  begin
    scan_results("00001000", majority_value, majority_count, tie);
    report ("Majority value is " & to_string(majority_value) & ". ");
    report ("Majority count is " & to_string(majority_count) & ".");
    report ("Tie is " & to_string(tie) & ".\n");
    wait for 10 ns;
    scan_results("11110111", majority_value, majority_count, tie);
    report ("Majority value is " & to_string(majority_value) & ". ");
    report ("Majority count is " & to_string(majority_count) & ".");
    report ("Tie is " & to_string(tie) & ".\n");
    wait for 10 ns;
    scan_results("00001111", majority_value, majority_count, tie);
    report ("Majority value is " & to_string(majority_value) & ". ");
    report ("Majority count is " & to_string(majority_count) & ".");
    report ("Tie is " & to_string(tie) & ".\n");
    wait;
  end process;
end procedure_calls;
     