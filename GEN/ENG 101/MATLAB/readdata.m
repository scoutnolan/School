% read and write example

raw_data = xlsread('data_ex.xlsx');
new_data = [];
for i = 1:length(raw_data)
    if raw_data(i)<=0.2
        new_data(i) = 0;
    elseif raw_data(i)>=0.8
        new_data(i) = 1;
    end
end
xlswrite('data_ex.xlsx', new_data,'B1:B1000')


        
        

