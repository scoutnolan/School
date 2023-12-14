### Username and password validation ###
import string



username = list(input(str("Please enter a username, six characters long: "))) # takes a username input, changes into a string.

while len(username) < 6:
    username = input(str("Please enter a username, six characters long: "))
    
if len(username) > 6:
    print('Password must contain:one lowercase, one uppercase, one number, one [$ # @ & * !], > 6 characters, < 16 characters')
    password = list(input('Please enter a password: '))
    



    #password = input(str("Please enter a password, must contain: : ")
