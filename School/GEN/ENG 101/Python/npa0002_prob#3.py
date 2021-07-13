# Nolan Anderson
# ENG 101 Exam #3
# 4/25/2019

# Determines a customers water bill.
print('Code values: "r" for residential, "c" for commercial, and "i" for industrial')

code = input('What is your usage code? ')
start = int(input('What did the meter initially read? '))
finish = int(input('What does the meter read now? '))
delta = (finish-start) # delta is the change in the meter, makes it easier to refer to later

if code == 'r': # if the code is equal to r, do this
    price = (5 + delta*0.0005) # price function for residential
    code = 'residential'
    
if code == 'c':
    code = 'commercial'
    delta_new = delta - 4e6 # new delta to refer to things over 4 million
    if delta < 4e6: #less than 4 million charge this amount
        price = (1000) # price if it is less than 4 million gallons
    if delta > 4e6:# greater than 4 million, charge this
        price = (1000 + delta_new*0.00025) # price if it is greater than 4 million gallons


if code == 'i':
    code = 'industrial'
    delta_new = delta - 10e6 # new delta to refer to things over 10 million
    if delta < 4e6: # if its less than 4 million, charge this amount
        price = (1000) #price if less than 4 mill
    if delta > 4e6 and delta <= 10e6: # if it is less than 10 mil and greater than 4 mil charge this
        price = 2000 # price between 4 and 10 mill gallons
    if delta > 10e6: # if it is greater than 10 million gallons, charge this
        price = 2000 + delta_new*0.00025 # price for over 10 million gallons



print('You are a ',code, 'customer who used ',delta,' gallons last month.\n Your total bill is $',price)
