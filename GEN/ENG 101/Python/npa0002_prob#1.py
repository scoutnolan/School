# Nolan Anderson
# ENG 101 Exam #1
# 4/25/2019


wlist=['promise', 'superb', 'husky', 'torpid', 'field', 'ill', 'macho', 'want',\
       'warm', 'high', 'callous', 'star', 'twist', 'high', 'worm', 'grate', 'lame',\
       'previous', 'righteous', 'push', 'release', 'pass', 'striped', 'quick',\
       'desert', 'crash', 'repeat', 'time', 'star', 'kittens', 'sky', 'shape', \
       'excuse', 'dam', 'vague', 'brass', 'neat', 'frail', 'shop', 'frequent', 'slap',\
       'dance', 'cast', 'thread', 'helpless', 'paddle', 'old', 'morning', 'pastoral', \
       'thing', 'growth', 'poke', 'sail', 'ill', 'deceive', 'stale', 'giraffe', 'slap',\
       'dam', 'reply', 'trucks', 'start', 'beg', 'peep', 'panoramic', 'wink', 'holiday',\
       'adaptable', 'breezy', 'sun', 'crabby', 'apologise', 'aloof', 'taboo', \
       'disastrous', 'dizzy', 'reaction', 'reading', 'wave', 'pull', 'noxious', 'bells', \
       'request', 'disarm', 'cause', 'wing', 'telling', 'seal', 'habitual', 'gleaming', \
       'picture', 'science', 'trouble', 'luxuriant', 'aware', 'lick', 'clover',\
       'existence', 'road', 'profit', 'pen', 'alive', 'queue', 'wing']

new_list = []

for i in wlist:# for each item in wlist, do this
    if len(i) < 5 and i not in new_list: # if the length is less than 5 and it is not in the new list, do this
        new_list.append(i) # appends the items to the new_list
print(new_list)# prints the new list with the correct items
    
        
    
