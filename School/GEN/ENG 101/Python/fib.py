def fib(n): 
    """Function returns the Fibonacci series from 1 to n in a list"""
    result = []
    a=0
    b=1
    c=b
   
    while b < n:
        result.append(c)
        c=a+b
        a=b
        b=c
    return result
