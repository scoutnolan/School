import random
a = 1
b = 100
num = random.randint(a,b)
guess = 0
while guess != "quit":
    print("Take a guess betweem 0 and 100")
    print("Enter 'quit' to exit the program")
    guess = input('guess \n \n')
    if int(guess) < num:
        print("low")
    if int(guess) > num:
        print("high")
    if int(guess) == num:
        print("Correct!")
        break