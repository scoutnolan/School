# Hourly Pay assignment
# Nolan Anderson
# 3/4/2019
# ENG 101

# Hourly wage print statement code with concantenation

name = input("What is your name? ")
ID = int(input('What is your 4 digit ID number? ')) # Inputs an integer
wage = int(input('What is your pay per hour? '))
hours = int(input('How many hours did you work '))
print(name +"'s ID is " + str(ID) + " and worked " + str(hours) + " hours this week at $" + str(wage) + " per hour")
# str(variable_name) changes the integer variable into a string so that print can display it
