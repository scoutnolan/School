#Working with dictionaries

#this is a dictionary for a paint color

paint_1 = {'color': 'charger blue', 'sheen': 'matte'}

#add key/value pair to paint_1

paint_1['grade']='high'	# {'grade' : 'high'}
print('paint_1=', paint_1)


#We can print a particular value for a key
print(paint_1['sheen'])

#We can print all the keys
print(paint_1.keys())

paint_2={ }
paint_2['color']='white'
paint_2['sheen']='gloss'
paint_2['grade']='medium'
print('paint_2 =', paint_2)

##Other ways to create dictionaries

paint_keys=['color', 'sheen', 'grade', 'type']
paint_3_list=['orange', 'semi-gloss', 'low', 'oil']
paint_3 = {}
for i in range(len(paint_keys)):
    paint_3[paint_keys[i]] = paint_3_list[i]
print('paint_3 =', paint_3)



paint_4=dict([('color', 'grey'), ('sheen','eggshell'),('type','water')])
print('paint_4 = ', paint_4)



paint_5 = dict(color='pink',sheen = 'gloss', grade = 'high') 
print('paint_5 = ',paint_5)


paint_keys=['color', 'sheen', 'grade', 'type']
paint_6_list=['red','gloss', 'super', 'water']


paint_6_pairs=list(zip(paint_keys, paint_6_list))
print('paint_6_pairs = ',paint_6_pairs)

paint_6=dict(paint_6_pairs)
print('paint_6 = ',paint_6)


###

fw1={"pink" : "rose", "orange": "orange", "red": "rouge", "yellow": "jaune"}
fw2={"green" : "vert", "blue" : "bleu", "purple" : "violet", "black": "noir"}
fw1.update(fw2)
print('fw1 = ',fw1)
fw3 = fw1.copy()
fw3.update(fw2)

french_words = {'fw1' : fw1, 'fw2' : fw2}
print(french_words['fw1']['yellow'])



#############################################

x1 = {'a':10,'b':20}
x2 = {'c':30,'d':40}
x3 = {'e':50,'f':60}
x4 = {}
for d in (x1,x2,x3):
    x4.update(d)
print('x4 = ',x4)


      
