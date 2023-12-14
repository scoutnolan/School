# Nolan Anderson
# ENG 101 Exam #2
# 4/25/2019

list_1=['kingdom', 'phylum', 'class', 'order', 'family', 'genus']
list_2=['animalia', 'chordata', 'mammalia', 'canivora', 'ursidae', 'ailuropoda']


def taxonomy(a,b):
    new_dict = dict(zip(a,b)) # makes a dictionary and zips the items in the list
    return(new_dict) # returns the new list

panda = taxonomy(list_1,list_2) # carries out function
print(panda) # outputs the function

