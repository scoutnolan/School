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

        



# radishdict = {"April Cross" : 0, "Champion" : 0, "Cherry Belle":0,"Snow Belle":0,"Bunny Tail":0,\
#     "Sicily Giant" : 0,"Plum Purple":0,"Red King":0,"Daikon":0,"White Icicle":0,"French Breakfast":0}
# AC= 0
# C = 0
# CB= 0 
# SB= 0
# BT= 0
# SG= 0
# PP= 0
# RK= 0
# D = 0
# WI= 0
# FB= 0

# for line in open("radishsurvey.txt"):
#     line = line.strip()
#     part = line.split(" - ")
#     name = part[0]
#     radish = part[1].title()

#     print(name,"likes:",radish,"radishes")

#     if radish == "April Cross":
#         AC +=1
#         radishdict["April Cross"] = AC
#     if radish == "Champion":
#         C +=1
#         radishdict["Champion"] = C
#     if radish == "Cherry Belle":
#         CB +=1
#         radishdict["Cherry Belle"] = CB
#     if radish == "Snow Belle":
#         SB +=1
#         radishdict["Snow Belle"] = SB
#     if radish == "Bunny Tail":
#         BT +=1
#         radishdict["Bunny Tail"] = BT
#     if radish == "Sicily Giant":
#         SG +=1
#         radishdict["Sicily Giant"] = SG
#     if radish == "Plum Purple":
#         PP +=1
#         radishdict["Plum Purple"] = PP
#     if radish == "Red King":
#         RK +=1
#         radishdict["Red King"] = RK
#     if radish == "Daikon":
#         D +=1
#         radishdict["Daikon"] = D
#     if radish == "White Icicle":
#         WI +=1
#         radishdict["White Icicle"] = WI
#     if radish == "French Breakfast":
#         FB +=1
#         radishdict["French Breakfast"] = FB

# print(radishdict)