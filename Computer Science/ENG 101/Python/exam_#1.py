 #cosine function



import math
def cosine(x,z):

    '''finds the cos of an angle in degrees'''
    x = math.radians(x)
    z = int(z)
    i = 0
    co_sine = 1
    sign = -1

    while i<z:
        i+=2
        co_sine = co_sine+(sign)*(x**i)/math.factorial(i)
        sign = -sign

    return(co_sine)
r = cosine(60,100)
print(r)






##x = 5/9
##y = 12*6.27
##z = 8000*4000
##print("%.5f"%(x))
##print("%15.5f"%(x))
##print("%.e"%(z))
##print("%.4e"%(z))
##print("%g"%(y))
##print("%.3g"%(y))
##print("%8.3g"%(y))
##print(y)
##print("%.2f"%(y))












##squares = []
##numbs = [1,2,3,4,5,6,7,8,9,10]
##for numb in numbs:
##    square = numb**2
##    squares.append(square)
##    print(square)
##print(squares)
##
##groceries = ['eggs','milk','bread','cheese']
##for i in groceries:
##    print("I need: " +i)
##    


##import math
##y = math.cos(45)
##print(y)

##def cube(x):
##    g = x*x*x
##    return g
##g = cube(3)
##print(g)
