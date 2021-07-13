import time
import random # imports the random function
computercount = 0 # initializes count for wins, computer and player 
playercount = 0


while playercount < 3 and computercount < 3:
    weapons = random.randint(1,3)
    time.sleep(1) # adds a timer of one second so that the code outputs a little less quickly. Gives you time to read outputs
    print('\n=========================================================================='
          '\n\t(1)ROCK                ''(2)PAPER             ''(3)SCISSORS'
          '\n==========================================================================')
    print('') # empty line for good spacing
    weaponpick = int(input('Choose your weapon  '))
    if weapons == 1: # assigns weapons to a string (in this case the specific weapon chosen)
        weapon = ('rock')
    if weapons == 2:
        weapon = ('paper')
    if weapons  == 3:
        weapon = ('scissors')
    if weaponpick > 3: # if the choice is above 3, then it promts the user to input again since it is not valid. 
        weaponpick = int(input('Not valid for this game: Chose your weapon:  '))
    if weapons == 1 and weaponpick == 2: # conditional statements, outputs whether or not the user won or lost.
        # compares input and output to decide who won.
        print('\nYou win! Paper beats ', weapon)
        playercount += 1 # adds count to the players wins
    elif weapons == 1 and weaponpick == 3:
        print('\nYou lose! The computer chose ', weapon)
        computercount += 1 # adds count to the computers wins
    elif weapons == 2 and weaponpick == 1:
        print('\nYou lost. The computer chose ', weapon)
        computercount += 1
    elif weapons == 2 and weaponpick == 3:
        print('\nYou win! Scissors beats ', weapon)
        playercount += 1
    elif weapons == 3 and weaponpick == 1:
        print('\nYou win. Rock beats', weapon)
        playercount += 1
    elif weapons == 3 and weaponpick == 2:
        print('\nYou lose! The computer chose ', weapon)
        computercount += 1
    elif weapons == weaponpick:
        print('\nDraw! The computer chose ', weapon, ' as well!')
if playercount == 3: # if the win count gets to three, it will output who got to it first.
    print('\nYou won 3 times!')
if computercount == 3:
    print('\nThe computer won 3 times!')


