## Divisible by four and nine
# Nolan Anderson
# ENG 101
#3/6/2019



factors = [] # Empty list to put numbers into 


for i in range(1,101,1): # range from 1-100, counting by 1. # i is the new variable 
    if i%4 == 0 or i%9 == 0: # If the remainders of i/4ori/9 = 0, do this.
        factors.append(i) # Puts the numbers found in the before if statement into the empty list factors


print(factors) # Outputs the new list of numbers according to the calculations defined by i

