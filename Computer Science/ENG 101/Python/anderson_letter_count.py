def letter_count(words):
    """Counts vowels, consonants, and other characters"""
    import string
    # create list that contains consonants
    # adds consonants and vowels to a list
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
    v = 0 # initial count for vowels(v), consonants(c) and other.
    c = 0
    other = 0
    # counts the amount of vowels and consonants stored in vlist/clist
    for i in words:
        if i in vlist:
            v += 1
        elif i in clist:
            c += 1
        else:
            other += 1
    print('Vowels: ', + v) # print statements for amount of consonants, vowels, and other
    print('Conosonants: ', + c)
    print('Other characters: ', + other)
    
