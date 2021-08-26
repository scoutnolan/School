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