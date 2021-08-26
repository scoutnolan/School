### Radishes assignment ###
# Nolan Anderson
# 4/1/2019

reading = open('radishsurvey.txt') # reads the text file
name_preference = {} # empty dictionaries
favtype_amount = {}

for i in reading: # loops through the txt file, i is each value of the text file
    j = i.strip().split(' - ') # set j equal to the strip of i, which is each value of the text file. (so that you do not have to strip everytime)
    name_preference[j[0].strip()] = j[1].strip() # sets the name and type of radish equal to each other in the dictionary
    if j[1].lower().strip() in favtype_amount:  # looks at the second position in favtype_amount, and strips it.
        favtype_amount[j[1].lower().strip()] += 1 # adds count to amount of people who like each certain type of radish
    else:
        favtype_amount[j[1].capitalize().strip()]=1 # captializes the first letter of each type of radish, which is in position one of each list

print("These people prefer these types of radishes: ", name_preference)
print("Radish type: How many people prefer this type: \n", favtype_amount)
reading.close() # closes the text file