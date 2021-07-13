#Nolan Anderson
#ENG 101 Exam #4
#4/26/2019


import random # imports random function
num_list = [] # empty list
for i in range(100): # range of 100
    i = random.randint(0,1000) # creates a random number
    num_list.append(i) # adds the number to the list
    #for i in num_list:
    avg = sum(num_list)/len(num_list) # average for the list
    # uses the sum of the values in the list and the length of the list
print(num_list) # prints the list of numbers
print('Average of list is: ', avg)  #prints the average of numbers
