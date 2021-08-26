new_pizza=0
new_name_list=[]
new_topping_list=[]
slices=[]

while new_pizza<3:
    new_name=input('Enter your name. ')
    new_top=input('What do you like on your pizza? ')
    s_pref=int(input('How many slices do you want? '))
    new_name_list.append(new_name)
    new_topping_list.append(new_top)
    slices.append(s_pref)
    new_pizza+=1

update_pizza=open('pizza.txt', 'w+')

for x in range(0,(len(new_name_list))):
    update_pizza.write('%s***%s***%g\n'%(new_name_list[x], new_topping_list[x],(slices[x])))
update_pizza.close()
  

        
            
