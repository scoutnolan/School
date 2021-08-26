#Sequence Types

party='Spring_Break'

food=['pizza', 'wings', 'cake', 'chips', 'BBQ']

drinks=('soda', 'water', 'juice', 'tea')

rsvps=[1, 2, 3, 5, 2, 4, 2, 6, 8, 2, 5, 1, 8, 2]

#Common Sequence Operations
print('in function')
x = 'wings' in food
print(x)

y = 'beer' in drinks
print(y)

z = 'B' in party
print(z)
##
print('\nnot in function')
x1 = 'pizza' not in food
print(x1)

y1 = 'gatorade' not in drinks
print(y1)

z1 = 'ig' not in party
print(z1)

##
print('\n\n\n')

print('concatenation function')

x2 = 'nachos'
x2a=['nachos']
print(food+list(x2))
print(food+x2a)

y2 = ('gatorade', 'lemonade')
print(drinks+y2)

z2 = " at the Beach"
print(party+z2)

##
print('\n\n\n')
print('\nindexing')

print(party[10])
print(food[1:3])
print(drinks[0:2])

##
print('\n\n\n')

print('\nlength')

print(len(party))
print(len(food))
print(len(drinks))

##
print('\n\n\n')
print('\ncount')

x3=rsvps.count(5)
print(x3)

##
print('\n\n\n')
print('for loops')

for drink in drinks:
    print('Do you like', drink +'?')

for item in food:
    print('Who likes', item +'.')

print('\n\n\n')
print('append, extend, etc')
f1=food.pop(2)
print(f1)
food.append('cookies')
print(food)
food2=['ice cream', 'cake', 'popcorn']
food.extend(food2)
print(food)
drinks2=('cider', 'gatorade')
drinks_l1=list(drinks)
drinks_l2=list(drinks2)
drinks_l1.extend(drinks2)
print(drinks_l1)