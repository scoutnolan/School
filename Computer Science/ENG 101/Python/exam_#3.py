'''Exam problem #3'''

import random
songs={1:"Havana",
2:"No Limit",
3:"Bad at Love",
4:"Finesse",
5:"Filthy",
6:"New Rules",
7:"God's Plan", 
8:"Diplomatic Immunity", 
9:"Say Something",
10:"Pray for Me",
11:"Stir Fry",
12:"Meant to Be",
13:"Look Alive",
14:"All the Stars",
15:"Psycho",
16:"The Middle",
17:"Sad!",
18:"Freaky Friday",
19:"Call Out My Name", 
20:"Walk It Talk It",
21:"Nice for What",
22:"I Like It",
23:"Chun-Li",
24:"Rockstar", 
25:"Thunder",
26:"Perfect",
27:"Gucci Gang",
28:"MotorSport",
29:"Too Good at Goodbyes",
30:"Louie, Louie"
       }
print('Shuffling: \n')
my_play_list = {}
list1 =[]
i = 1
while len(list1)<=11:
    random_song = (random.randint(1,len(songs)))#,len(songs))
    if random_song not in list1:
        list1.append(random_song)
        print(i,':', random_song,'.',songs[random_song])
        my_play_list[i] = songs[random_song]
        i+=1
print(my_play_list)
