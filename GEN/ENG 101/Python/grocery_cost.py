# Online Grocery functions
# Nolan Anderson
# ENG 101
# 4/17/19


#Function 1: cost 
def grocery_cost():
    total_cost = 0
    from datetime import datetime
    now = datetime.now()
    now = now.replace(microsecond = 0)
    from grocery_store import groc_list, unit_list, prices, stock
    amount_selected = dict(zip(groc_list, unit_list))
    for i,k in amount_selected.items():
        #5 (part of the receipt process.)
        print('Item: ', i, '            Amount: ', k)
    eggs = 'Eggs' in groc_list # sees if the item is in the grocery list
    bacon = 'Bacon' in groc_list
    loaf = 'Loaf' in groc_list
    coffee = 'Coffee' in groc_list
    juice = 'Juice' in groc_list
    butter = 'Butter' in groc_list
    jelly = 'Jelly' in groc_list
    banana = 'Bananas' in groc_list
    apple = 'Apples' in groc_list
    donut = 'Donuts' in groc_list
    milk = 'Milk' in groc_list
    salt = 'Salt' in groc_list
    pepper = 'Pepper' in groc_list
    ham = 'Ham' in groc_list
    potato = 'Potatoes' in groc_list
    biscuit = 'Biscuit' in groc_list
    for k in unit_list: # this is a thing to find the pricing of the cart
        #gc2 = open("grocery_catalog.txt", "w+") 
        if eggs == 1: # essentially, if the above statements are True(1)
            total_cost = total_cost + k * 1.99 # then it will add the price * the amount selected
            # if eggs are in it, reduce the amount in the stock by k
            # essentially take k in this, and subtract the value in the stocks
            
        elif bacon == 1:
            total_cost = total_cost + k * 7.85 # best i could do for the prices. have no clue how to pull from the dictionary
        elif loaf == 1:
            total_cost = total_cost + k * 1.58
        elif coffee == 1:
            total_cost = total_cost + k * 5.99
        elif juice == 1:
            total_cost = total_cost + k * 4.99
        elif butter == 1:
            total_cost = total_cost + k * 2.39
        elif jelly == 1:
            total_cost = total_cost + k * 1.98
        elif banana == 1:
            total_cost = total_cost + k * 2.89
        elif apple == 1:
            total_cost = total_cost + k * 3.99
        elif donut == 1:
            total_cost = total_cost + k * 2.50
        elif milk == 1:
            total_cost = total_cost + k * 2.99
        elif salt == 1:
            total_cost = total_cost + k * 3.99
        elif pepper == 1:
            total_cost = total_cost + k * 5.00
        elif ham == 1:
            total_cost = total_cost + k * 8.99
        elif potato == 1:
            total_cost = total_cost + k * 2.58
        elif biscuit == 1:
            total_cost = total_cost + k * 6.89
    #5        
    print('Total price of items: ', total_cost)
    print('Time of day: ',now)
grocery_cost()







# function 2: stock update
def stock_check():
    stock_update = open('stock_update.txt','w+') #opens a new file to say what needs to be updated
    from grocery_store import stocks, unit_list
    from grocery_cost import amount_selected
        
    
#6a
    stock_update.write('You need to restock these items')
#6b
    for i,k in stock.items(): # for the items in the stock list:
        if k < 5: # if the number found is less than 5
            stock_update.write('You need to restock ', i, ' there is only ', k, ' left of it') # it provides the item and that you need to restock it
#6c    
    grocery_store = open('grocery_catalog.txt','w')
    for i,k in amount_selected:
        grocery_store.update('')# something that takes away from what is in the txt file
        




#issues im having:
        #cannot 
