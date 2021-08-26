%% while end loop 5000
balance = 5000; %initial deposit
year = 0; %initial year
while balance <1000000
    balance = balance*(1.09)+5000;
    year = year+1
    
end
fprintf('Dr. English''s will reach or exceed $1,000,000,000 in %g years. \n', year)
fprintf('The amount in the annutiy is $%8.2f. \n', balance)