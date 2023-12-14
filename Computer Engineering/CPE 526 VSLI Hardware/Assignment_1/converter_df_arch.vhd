architecture DATAFLOW of CONVERTER is
begin
  E(3) <= (B(3) and B(2)) or (B(3) and not B(1) and not B(0)) or 
          (not B(3) and not B(2) and B(0)) or 
          (not B(3) and not B(2) and B(1));
  E(2) <= (not B(2) and B(0)) or (B(3) and B(2) and not B(1)) or
          (B(3) and B(1) and not B(0)) or (not B(2) and B(1)) or
          (B(2) and not B(1) and not B(0));
  E(1) <= (not B(1) and B(0)) or (B(1) and not B(0)) or 
          (B(3) and B(2) and not B(1)) or
          (not B(3) and not B(2) and B(0));
  E(0) <= B(0) or (B(3) and B(2)) or (not B(3) and not B(2) and B(1));
end DATAFLOW;
