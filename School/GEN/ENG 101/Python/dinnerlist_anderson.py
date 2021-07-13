# Dinner list assignment
# Nolan Anderson
# 3/4/2019
# ENG 101

# 1
people = ["Wraith","Caustic","Mirage"] # Apex gang
location = ('Cascades')
date = ('February 4th')

# 2
print(people[0] + ', you''re invited to dinner at ' +location+ ' on ' + date) # Prints the first person in the list and provides them with time and place
print(people[1] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[2] + ', you''re invited to dinner at ' +location+ ' on ' + date)

# 3
del people[1] # Deletes the second person in the list
people.insert(1,'Pathfinder') # Replaces someone in the second spot on the list
print(people[1] + ', you''re invited to dinner at ' +location+ ' on ' + date)

# 4
people.insert(0,'Dr. English') # Inserts the people into the list according to position as well
people.insert(2,'Lifeline')
people.insert(5,'Bangalore')

print(people[0] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[1] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[2] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[3] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[4] + ', you''re invited to dinner at ' +location+ ' on ' + date)
print(people[5] + ', you''re invited to dinner at ' +location+ ' on ' + date)

# 5
print('I''m sorry, ' + people[5] + ', but you cannot come to my house for dinner')
print('I''m sorry, ' + people[4] + ', but you cannot come to my house for dinner')
people.pop() # Deletes the last person in the list
people.pop()
people.sort() # Sorts the people in alphabetical order
print(people) # Outputs the list of people still invited








