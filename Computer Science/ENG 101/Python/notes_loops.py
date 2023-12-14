
#Examples

#Example 1
##groceries = ['eggs','milk','bread','cheese']
##for grocery in groceries:
##    print('I need: ' + grocery)
    
    

#Example 2

##squares=[]
##numbs=[1,2,3,4,5,6,7,8,9,10]
##
##for numb in numbs:
##    square = numb**2 ## PAY ATTENTION TO SPACING
##    squares.append(square)
##    print(square)
##print(squares)


##for number in range(1,5):
##    print(number)
##for x in range(0,100,5):
##    print(x)


import math
#Empty list for squares and roots
squares=[]
roots = []

## For loop for the roots
for number in range(1,6): # for loop 1-5
    root = math.sqrt(number) # find the root of the current number
    roots.append(root)       # append the root value to the roots list
    print("Root of ", number, ": ", root) # print out the current number and its
                                          # root value
print("Roots of 1-5: ")
print(roots) #output the whole roots list of 105
print("\n")
## For loop for the squares
for number in range(6,11): # for loop 6-10
    square = number**2     # find the square of the current number
    squares.append(square) # append the current number's square to the squares list
    print("Square of ", number, ": ", square) # same thing as above
print("Squares 6-10")
print(squares)


roots.extend(squares) # append the roots to the squares list and output 
print("Roots and squares combined:")
print(roots)

# True false values are boolean values, have a value of 1 and 0



## LOOPS

# for item in list:
    # task/operator on item
    ##..
    ##..
    # Task / operation on item
# no indent when done in for loop


## IF STATEMENTS

#if<conditional statement>:
    #operation/task
    #:
    #:
    #operation/task
#Other code

#else
#elif<conditional statement>










    

