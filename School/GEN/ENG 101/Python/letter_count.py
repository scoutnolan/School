import string

lc = list(string.ascii_lowercase)

v_list = []
c_list = []
for x in lc:
    if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u'):
        v_list += x
    else:
        c_list += x

string = input('Please enter a string ')
v_count = 0 # initial vowel count
c_count = 0 # initial consonant count
other = 0 # initial other chatacter count 
string = string.lower() # makes input lowercase
string = list(string)
print(string)
for i in string:
    if i in v_list:
        v_count += 1
    elif i in c_list:
        c_count += 1
    else:
        other += 1
        
# if len(string) == (v_count+c_count+other):
##print(v_list)
##print(c_list)
print('Vowels: ', + v_count)
print('Consonants: ', + c_count)
print('Other characters: ', + other)


def letter_count(words):
    """Counts vowels, consonants, and other characters"""
    import string
    # create list that contains consonants
    lc = list(string.ascii_lowercase)
    vlist = []
    clist = []
    for x in lc:
        if x in 'aeiou':
            vlist += x
        else:
            clist += x
    words = words.lower() # puts all the characters in lowercase
    # start counters
    v = 0
    c = 0
    other_new = 0
    for i in words:
        if i in vlist:
            v += 1
        elif i in clist:
            c += 1
        else:
            other_new += 1
    print('Vowels ', + v)
    print('Conosonants ', + c)
    print('Other characters ', + other_new)

    
    
