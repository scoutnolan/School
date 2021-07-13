# Grocery store code
#Nolan Anderson
# ENG 101
# 4/17/19

#### D I S C L A I M E R
# to make this easier to grade, look at the grocery_fun file first.

#4f, 6d 
from grocery_fun import grocery_cost


# COMMENT THIS OUT TO GRADE PARTS 1-3
from grocery_fun import stock_check 

stock = {} # grocery items and values are # of stock
prices ={} # grocery items = prices
size = {} # grocery itmes = unit sizes
all3 = {} # dictionary so i can output all the items

#1

with open("grocery_catalog.txt","r+") as gc:
    # opens and reads the file as the variable gc
    for line in gc: # for each line in the file...
        line = line.strip('\n') # gets rid of \n
        line = line.split(',')  # splits each line with a comma
        stock[(line[0])] = ''.join(line[2]) # makes the dictionary have the item as the "word" and the stock amount as the "definition"
        prices[(line[0])] = ''.join(line[3]) # makes the dictionary have the item as the "word" and the price as the "definition"
        size[(line[0])] = ''.join(line[1])# makes the dictionary have the item as the "word" and the size value as the "definition"
        all3[(line[0])] = ' - '.join(line[1:]) # combines all 3 together, only a print statement dictionary however.

#prices = dict(zip(prices.keys(), [float(value) for value in prices.values()]))

print('') # online store "welcome" page print statements
print("=======================================================================================")
print('')
print("             |~W E L C O M E  T O  P Y T H O N  O N L I N E  S T O R E~|")
print('')
print("=======================================================================================")
print('')
print("                          -Here's what we have in stock--")
print('')
print('|I T E M| - |S I Z E| - |A M O U N T| - |P R I C E|')
print('')


#2 
for item, stock in all3.items(): # for the 2 positions in the dictionary all3
    print('*',item, '-', stock,'per unit\n') # prints out the item, size, stock, and price for each unit.


#3
groc_list = [] # empty lists for the type of grocery
unit_list = [] # empty list for the amount of each item
x = True
while x is True:#while the variable x is true, run through this until it is false
    item_selected = input(str("What would you like to add to your shopping cart?  ")) #input for  item customer wants
    print('Type ''Done'' when you are finished adding to your shopping cart') #if the user types done, they it will end
    item_selected.lower() #makes it easier to make if and elif statements.
    if item_selected == 'egg' or item_selected == 'eggs':
        egg_unit = input('How many dozen eggs would you like?   ')
        groc_list.append('Eggs') # for each if statement, adds the specific item to the list of grocery items
        unit_list.append(egg_unit) # for each if statement, adds the amount of the specific item to the unit_list
    elif item_selected == 'bacon':
        bacon_unit = input('How many pounds of bacon would you like?   ')
        groc_list.append('Bacon')
        unit_list.append(bacon_unit)
    elif item_selected == 'bread':
        bread_unit = input('How many loaves of bread would you like?   ')
        groc_list.append('Loaf')
        unit_list.append(bread_unit)
    elif item_selected == 'coffee':
        coffee_unit = input('How many pounds of coffee would you like?   ')
        groc_list.append('Coffee')
        unit_list.append(coffee_unit)
    elif item_selected == 'juice':
        juice_unit = input('How many gallons of juice would you like?   ')
        groc_list.append('Juice')
        unit_list.append(juice_unit)
    elif item_selected == 'butter':
        butter_unit = input('How many pounds of butter would you like?   ')
        groc_list.append('Butter')
        unit_list.append(butter_unit)
    elif item_selected == 'jelly':
        jelly_unit = input('How many jars of jelly would you like?   ')
        groc_list.append('Jelly')
        unit_list.append(jelly_unit)
    elif item_selected == 'bananas' or item_selected == 'banana':
        banana_unit = input('How many bunches of bananas would you like?   ')
        groc_list.append('Bananas')
        unit_list.append(banana_unit)
    elif item_selected == 'apples' or item_selected == 'apple':
        apple_unit = input('How many bags of apples would you like?   ')
        groc_list.append('Apples')
        unit_list.append(apple_unit)
    elif item_selected == 'donut' or item_selected == 'donuts':
        donut_unit = input('How many dozen donuts would you like?   ')
        groc_list.append('Donuts')
        unit_list.append(donut_unit)
    elif item_selected == 'milk':
        milk_unit = input('How many gallons of milk would you like?   ')
        groc_list.append('Milk')
        unit_list.append(milk_unit)
    elif item_selected == 'salt':
        salt_unit = input('How many jars of salt would you like?   ')
        groc_list.append('Salt')
        unit_list.append(salt_unit)
    elif item_selected == 'pepper':
        pepper_unit = input('How many jars of pepper would you like?   ')
        groc_list.append('Pepper')
        unit_list.append(pepper_unit)
    elif item_selected == 'ham':
        ham_unit = input('How many pounds of ham would you like?   ')
        groc_list.append('Ham')
        unit_list.append(ham_unit)
    elif item_selected == 'potatoes' or item_selected == 'potato':
        potato_unit = input('How many pounds of potatoes would you like?   ')
        groc_list.append('Potatoes')
        unit_list.append(potato_unit)
    elif item_selected == 'biscuits' or item_selected == 'biscuit':
        biscuit_unit = input('How many dozen biscuits would you like?   ')
        groc_list.append('Biscuit')
        unit_list.append(biscuit_unit)

#5 - part of printing out the receipt
    elif item_selected == 'done':
        donep2 = input(str('Are you sure you are done?  \n'))
        donep2.lower() # makes the input lowercase for easier if statements. also only takes first letter.
        donep2 = donep2[0]
        if donep2 == 'y':
            print('Ok here is you receipt\n')# essentially breaks the while loop and will show the receipt.
            unit_list = list(map(int,unit_list)) # changes the unit_list values to an integer so i can use them
            x = False
            break
        else:
            print('ok')
    
    else: # if the user spells something wrong, it just goes back to the top.
        print('Hmmmmm... Did''nt quite get that. Maybe try spelling it a different way?')
#4f
grocery_cost()
#6d

# COMMENT THIS OUT TO GRADE PARTS 1-3
stock_check()
