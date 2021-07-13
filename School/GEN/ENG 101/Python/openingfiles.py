## Opening a file ##


m = open('months.txt','r')
# r for read, w for write, x for creating a writing to a new files, a for appending, r+ for reading and writing to the same file
#x = m.read()
# string with \n between each month


############
#y = m.readline()
# each time m.readlin() is run, the next line of the months of the months.txt file appears as the output
# have to run it individually each time in the shell

############
#z = m.readlines()
# each line of the text file appears as an element in a list, but the \n (new line) still appears
# Once a file has been read using either the read, readlineor readlinescommands, ->
# it cannot be read again without rerunning the program

############
# to get rid of \n, use .strip() command
##m = open("months.txt")
##next = m.readline()
##while next != "":
##    print(next.strip())
##    next = m.readline()



##### OR ###
##M = []
##m = open("months.txt")
##for month in m.readlines():
##    month = month.strip()
##    M.append(month)



##### OR ###
##m = open("months.txt")
##for month in m:
##    print("Month: " + month.strip())



#### pizza.txt ###
for line in open("pizza.txt",'r'):
    line = line.strip()
    print(line)


### splitting up the line data ###
# we can split the toppings and people
# use split.(specifier)
for line in open("pizza.txt"):
    line = line.strip()
    parts = line.split(" - ")
    name = parts[0]
    topping = parts[1]
    print(name+" wants " +topping+" on their pizza.")
