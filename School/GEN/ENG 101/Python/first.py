# First program

x = 5/9
y = 12 * 6.27
z = 8000 * 4000




print('%.5f'%(x))
print('%10.5f'%(x))
print('%.e'%(z))
print('%.4e'%(z))
print('%g'%(y))
print('%.3g'%(y))
print('%8.3g'%(y))
print('The value stored in x is %.3f and the value stored in y is %8.4g. \n\n' %(x,y))




list_1 = ['a','b','c','d','e','f']
print(list_1)

quarter = ['Janruary', 'February', 'March']
print('First month is', quarter[0])
print('Second month is', quarter[1])
print('Third month is', quarter[2])


coord= [[1,2,3],[4,5,6]]
print(coord[1][2])
print(coord[-1][1])
print('The first letter of the third month is', quarter[2][0])
print('The last letter of the first month is', quarter[0][-1])

print(len(quarter))
