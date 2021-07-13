import random
print('Here are tn random numbers selected between 0 and 100 in increments of 2')
t = 0
while t != 10:
    x = random.randrange(0,100,2)
    print(x)
    t += 1
print('\nHere are 15 random numbers from one to ten')
s = 0
while s!=15:
    y = random.randint(1,10)
    print(y)
    s += 1
    
    
