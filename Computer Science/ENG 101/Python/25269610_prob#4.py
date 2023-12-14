# Creates a list of 100 random numbers between 0 and 1000

import random
num_list = []
for i in range(100):
    i = i.randint(0,1000)
    num_list.append(i)
    
