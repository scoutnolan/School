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