entity AND3 is 
  port (I2, I1, I0 : in BIT; 
        O : out BIT); 
end entity; 

architecture BEHAVE of AND3 is 
begin 
  O <= I2 and I1 and I0 after 1 ns; 
end BEHAVE;

entity AND2 is
  port (I1, I0 : in BIT;
          O : out BIT);
end entity;

architecture BEHAVE of AND2 is
begin
  O <= I1 and I0 after 1 ns;
end;

entity OR3 is
  port (I2, I1, I0 : in BIT;
          O : out BIT);
end entity;

architecture BEHAVE of OR3 is
begin
  O <= I2 or I1 or I0 after 1 ns;
end BEHAVE;

entity OR4 is
  port (I3, I2, I1, I0 : in BIT;
          O : out BIT);
end entity;

architecture BEHAVE of OR4 is
begin
  O <= I3 or I2 or I1 or I0 after 1 ns;
end BEHAVE;

entity OR5 is
  port (I4, I3, I2, I1, I0 : in BIT;
          O : out BIT);
end entity;

architecture BEHAVE of OR5 is
begin
  O <= I4 or I3 or I2 or I1 or I0 after 1 ns;
end BEHAVE;

entity INV is
  port (I : in BIT;
        O : out BIT);
end INV;

architecture BEHAVE of INV is
begin
  O <= not I after 1 ns;
end BEHAVE;

 architecture STRUCTURAL of CONVERTER is
  
  component AND2
    port (I1, I0 : in BIT;
          O : out BIT);
  end component;

  component AND3
    port (I2, I1, I0 : in BIT;
          O : out BIT);
  end component;

  component OR3
    port (I2, I1, I0 : in BIT;
          O : out BIT);
  end component;
       
  component OR4
    port (I3, I2, I1, I0 : in BIT;
          O : out BIT);
  end component;

  component OR5
    port (I4, I3, I2, I1, I0 : in BIT;
          O : out BIT);
  end component;
  
  component INV
    port (I : in BIT;
          O : out BIT);
  end component;

  for all : AND2 use entity work.AND2(BEHAVE);
  for all : AND3 use entity work.AND3(BEHAVE);
  for all : OR3 use entity work.OR3(BEHAVE);
  for all : OR4 use entity work.OR4(BEHAVE);
  for all : OR5 use entity work.OR5(BEHAVE);
  for all : INV use entity work.INV(BEHAVE);
 
  signal T0, T1, T2, T3, T4, T5, T6, T7, T8, T9,
         T10, T11, T12, T13, T14 : BIT;

begin
  
  U0 : INV port map(B(0), T0);
  U1 : INV port map(B(1), T1);
  U2 : INV port map(B(2), T2);
  U3 : INV port map(B(3), T3);
  U4 : AND2 port map(B(3), B(2), T4);
  U5 : AND2 port map(T2, B(0), T5);
  U6 : AND2 port map(T2, B(1), T6);
  U7 : AND2 port map(T1, B(0), T7);
  U8 : AND2 port map(B(1), T0, T8);
  U9 : AND3 port map(B(3), T1, T0, T9);
  U10 : AND3 port map(T3, T2, B(0), T10);
  U11 : AND3 port map(T3, T2, B(1), T11);
  U12 : AND3 port map(B(3), B(2), T1, T12);
  U13 : AND3 port map(B(3), B(1), T0, T13);
  U14 : AND3 port map(B(2), T1, T0, T14);
  U15 : OR3 port map(B(0), T4, T11, E(0));
  U16 : OR4 port map(T4, T9, T10, T11, E(3));
  U17 : OR4 port map(T7, T8, T10, T12, E(1));
  U18 : OR5 port map(T5, T6, T12, T13, T14, E(2));
  
end STRUCTURAL;
