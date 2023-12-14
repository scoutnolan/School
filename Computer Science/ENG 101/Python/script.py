""" DoS RPG by Parker Nordstrom v0.31.8.6
    Ascii by DomZ Ninja
    Special thanks to friends for ideas
    Special thanks to play testers
    Shoutouts to SimpleFlips"""

import random, time  # Importing time and random which will be used later to wait and to roll.
level = 1  # Setting up the default conditions.
turn = True
parry = False
win = False

print(" Welcome to Dawn of Souls!")  # Opening message! Followed up by a filename input.
print("    A turn based RPG")
print("     made in Python")
print("       by Parker")
name = input(" FILENAME: ").replace(" ", "")


def start():
    global turn, level, mindps, maxdps, minheal, maxheal, name, parry, win, xx
    phealth = 300  # Sets both of the player's healths to 300, with the enemy health scaling.
    ehealth = 200 + 100 * level
    mindps = 10 + (8 * level)  # This is the formula used to determine the minimum and maximum for healing and damage.
    maxdps = 30 + (8 * level)
    minheal = 6 + (4 * level)
    maxheal = 25 + (8 * level)
    shield = 4 + level  # The number of uses the player's block option has.
    if name == "ibaacmode":  # 'Ibaac mode' Infinite Health. Destruction. Decimation.
        phealth = 9000000
    play = False
    xx = False
    print("\n" * 20)
    print(" " * 80, "                                    '''''''''''")  # Title card flair.
    time.sleep(.4)
    print(" " * 80, "                                   '''''''''''''")
    time.sleep(.4)
    print(" " * 80, "                                 '''''''''''''''''")
    time.sleep(.1)
    print(" " * 80, "       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM")
    time.sleep(.1)
    print(" " * 80, "       MM   __   __                 __   ___     __   __            __   MM")
    time.sleep(.1)
    print(" " * 80, "       MM  |  \ |__| | | | |\ |    |  | |__     |__  |  | |  | |   |__   MM")
    time.sleep(.1)
    print(" " * 80, "       MM  |__/ |  | |_|_| | \|    |__| |        __| |__| |__| |__  __|  MM")
    time.sleep(.1)
    print(" " * 80, "       MM                                                                MM")
    time.sleep(.1)
    print(" " * 80, "       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM")
    time.sleep(.4)
    print(" " * 80, "                                 '''''''''''''''''")
    time.sleep(.4)
    print(" " * 80, "                                   '''''''''''''")
    time.sleep(.4)
    print(" " * 80, "                                    '''''''''''")
    time.sleep(.4)
    print("\n")
    time.sleep(.4)
    begin = input("||BEGIN?||LEVEL: " + str(level) + "||").lower().replace(" ", "")  # Shows the player level.
    if begin == 'y' or begin == 'yes' or begin == 'yeah' or begin == 'ye':
        play = True  # Allows the main loop to run.
        print("\n" * 50)
    elif begin == 'n':
        print("||THANKS FOR PLAYING!||")
        quit()
    while play:
        print(" " * 108, "ENEMY HP: " + str(ehealth))  # This is the command line gui displayed every turn.
        print("\n" * 2)  # Shows health, level and other things.
        print(" " * 80, "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|")
        print(" " * 80, " " * 27, name, " LEVEL ", level)
        print(" " * 80, "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|")
        print(" " * 80, "|M|  HEAL  |MMM|  ATTACK  |MMM|  BLOCK  |MMM|  HP: " + str(phealth) + "  |MMMMMMMMMMMM|")
        print(" " * 80, "|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|")
        if turn:  # The player's turn!
            print("\n" * 2)
            pmove = input(" " * 79 + "MMMMMMM|                      CHOOSE A MOVE                       |MMMMMMM").lower().replace(" ", "")
            if pmove == 'heal' or pmove == '1':  # The heal option! Lets the player recover in the heat of battle.
                if phealth >= 200:
                    if name == "ibaacmode":  # Tests for the filename ibaacmode, where overhealing is allowed.
                        heal = random.randint(minheal, maxheal)
                        print("\n" * 50)
                        print(" " * 80, "=================================================================")
                        print("")
                        print(" " * 98, str(name) + " HAS HEALED " + str(heal) + " HEALTH")
                        print("")
                        print(" " * 80, "=================================================================")
                        time.sleep(2)
                        print("\n" * 50)
                        phealth = phealth + heal
                        turn = False  # Sets the turn to false and then continues the loop, allowing the enemy to go.
                        continue
                    else:  # No overhealing!
                        print("\n" * 50)
                        print(" " * 80, "=================================================================")
                        print("")
                        print(" " * 80, "                  YOU CANT OVERHEAL, TRY AGAIN!")
                        print("")
                        print(" " * 80, "=================================================================")
                        time.sleep(2)
                        print("\n" * 50)
                        phealth = 200
                        turn = True  # Sets the turn to true, letting the player move again.
                        continue
                else:
                    heal = random.randint(minheal, maxheal)  # Heal is rolled for using the formula in lines 26, 27
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 98, str(name) + " HAS HEALED " + str(heal) + " HEALTH")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    phealth = phealth + heal
                    if phealth >= 200:
                        phealth = 200
                    turn = False
                    continue
            elif pmove == 'attack' or pmove == '2':  # When the player chooses attack! Defeat the enemy!
                miss = random.randint(1, 5)  # See line 220.
                if miss == 3:
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 80, "                YOU TRIED TO ATTACK, BUT IT MISSED")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    turn = False
                    continue
                else:  # When the attack connects, it rolls for the formula in lines 24, 25
                    damage = random.randint(mindps, maxdps)
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 96, str(name) + " HAS STRUCK THE ENEMY FOR " + str(damage) + " DAMAGE")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    ehealth = ehealth - damage
                    turn = False
                    continue
            elif pmove == 'block' or pmove == '3':  # When the player blocks. It has 5 uses, blocks the next attack.
                if shield == 0:  # Tests for the amount of uses the shield has. If it is 0 it can not be used again.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 80, "                     OUT OF USES, TRY AGAIN!")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    phealth = 200
                    turn = True
                    continue
                shield = shield - 1  # Reduces the number of uses the shield has.
                print("\n" * 50)
                print(" " * 80, "=================================================================")
                print("")
                print(" " * 98, str(name) + " HAS BLOCKED! " + str(shield) + " USES LEFT!")
                print("")
                print(" " * 80, "=================================================================")
                time.sleep(2)
                print("\n" * 50)
                parry = True  # Activates the parry status. While this is on, no attacks can be connected except magic.
                turn = False
                continue
            else:  # If no moves are selected, asks the player to try again.
                print("\n" * 50)
                print(" " * 80, "=================================================================")
                print("")
                print(" " * 80, "                      NOT A MOVE, TRY AGAIN!")
                print("")
                print(" " * 80, "=================================================================")
                time.sleep(2)
                print("\n" * 50)
                turn = True
                continue
        if ehealth <= 0:  # This is the win condition
            print("\n" * 50)
            print(" " * 80, "=================================================================")
            print("")
            print(" " * 80, "                         VICTORY ACHIEVED")
            print("")
            print(" " * 80, "=================================================================")
            level = level + 1  # Increases the player level, all stats raised!
            win = True
            time.sleep(2)
            break
        if not turn:  # The start of the enemy turn.
            print("\n" * 2)  # The diplay message for the enemy choosing a move. It waits 4 seconds, then continues.
            print(" " * 74, "MMMMMMMMMM|                     ENEMY IS CHOOSING                    |MMMMMMMMMM")
            time.sleep(4)
            emove = random.randint(1, 3)  # Rolls between 1 in 3 for the options the enemy has.
            if emove == 1:  # When the enemy chooses heal.
                if ehealth >= 200 + 100 * level:  # This is a chk for if it has over health. No overhealing!
                    turn = False
                    print("\n" * 50)
                    continue
                else:
                    heal = random.randint(6, 18)  # When heal connects, it rolls between 6 and 18 for the total healing.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 98, "THE ENEMY HAS HEALED " + str(heal) + " HEALTH")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    ehealth = ehealth + heal
                    turn = True
                    parry = False
                    continue
            elif emove == 2:
                emiss = random.randint(1, 5)
                if emiss == 3:  # Rolls between 1 in 5 for the attack missing.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 80, "            THE ENEMY TRIED TO ATTACK, BUT IT MISSED")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    turn = True
                    parry = False
                    continue
                elif parry:  # If block was used the turn before, the enemy's attack will do no damage.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 80, "                ATTACK BLOCKED! 0 DAMAGE DEALT!")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    turn = True
                    parry = False
                    continue
                else:  # If damage connects, it rolls between 8 and 23 for how much it will do.
                    damage = random.randint(8, 23)
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 96, "THE ENEMY HAS STRUCK YOU FOR " + str(damage) + " DAMAGE")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    phealth = phealth - damage
                    turn = True
                    parry = False
                    continue
            elif emove == 3:  # This option is magic, a 1 in 7 chance true 50 damage attack.
                connect = random.randint(1, 7)
                if connect == 7:  # If the random integer is a 7, the move carries on.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 96, "THE ENEMY USED MAGIC!! 50 DAMAGE DEALT!")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    phealth = phealth - 50
                    turn = True
                    parry = False
                    continue
                else:  # This message is displayed when magic misses.
                    print("\n" * 50)
                    print(" " * 80, "=================================================================")
                    print("")
                    print(" " * 94, "THE ENEMY TRIED TO USE MAGIC, BUT IT FAILED!")
                    print("")
                    print(" " * 80, "=================================================================")
                    time.sleep(2)
                    print("\n" * 50)
                    turn = True
                    parry = False
                    continue
        if ehealth >=  200 + 100 * level:
            ehealth = 200 + 100 * level
        if phealth <= 0:  # When the player health is below or equal to zero, they die
            phealth = 0
            print("\n" * 50)
            print(" " * 80, "=================================================================")
            print("")
            print(" " * 80, "                            YOU DIED")
            print("")
            print(" " * 80, "=================================================================")
            time.sleep(2)
            pass


# Runs the main code
start()

print("\n" * 50)


def restart():  # 5 Restart options, each with increasing stats.
    global turn, parry, xx
    playagain = input("||PLAY AGAIN?|| Y/N").lower().replace(" ", "")
    if playagain == "y":
        turn = True
        parry = False
        xx = True
    while xx:
        start()
        continue
    else:
        print("SEE YOU NEXT TIME!")
        quit()


for i in range(1, 5):
    restart()
