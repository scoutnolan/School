# Hourly Pay assignment
# Nolan Anderson
# 3/4/2019
# ENG 101

# Hourly wage print statement code with concantenation

name = input("What is your name? ")
ID = int(input('What is your 4 digit ID number? ')) # Inputs an integer
wage = float(input('What is your pay per hour? ')) # Float allows for a decimal wage
hours = float(input('How many hours did you work '))
pay = hours * wage # pay based off of hours and wage earned
print(name + ' is hourly employee:     ' +str(ID))
print(name + ' worked ' +str(hours)+ ' hours last week.')
print('') # Creates a empty line
print(name+ ' earned $' +str(pay)+ ' this week.')