
### Username and password validation ###
# Nolan Anderson
# 4/1/2019

import string
import re # re is a function that contains the .search() command


username = list(input(str("Please enter a username, six characters long: "))) # takes a username input, changes into a string.

while len(username) < 6: # if the username is less that 6 digits, ask for a new username
    username = input(str("Please enter a username, six characters long: "))
    
if len(username) >= 6: # if the username meets the condition...
    print('Password must contain:one lowercase, one uppercase, one number, one [$ # @ & * !], > 6 characters, < 16 characters')
    
    
    x=0
    while x < 999: # essentially you have 999 attempts 
        p = str(input('Please enter a password: ')) # password input
        d = len(p)
        if d < 6 or d > 16:
            print('Make sure your password is between 6 and 16 characters')
            x+=1
        elif re.search('[0-9]', p) is None: # re.search is a function that looks through the characters
            print('Make sure your password has a number in it')
            x+=1
        elif re.search('[a-z]',p) is None: # is None basically will ask this if re.search does not find what it is looking for
            print('Make sure your password has a lowercase character')
            x+=1
        elif re.search('[A-Z]',p) is None:
            print('Make sure your password has a uppercase character')
            x+=1
        elif re.search('[&#@&*!]',p) is None:
            print('Make sure you have a [&#@&*!]')
            x+=1
        else:
            print('Your password is fine')
            x+=1000
            x=True
            break

