##pep_people=[]
##pep_top=0
##
##for line in open("pizza.txt", 'r+'):
##    line = line.strip()
##    parts = line.split(" - ")
##    ##print(parts)
##    name = parts[0]
##    topping = parts[1]
##    if 'pepperoni' in topping:
##        pep_top+=1
##        pep_people.append(name)
##
##
##pep_file=open('pep_lover.txt', 'w')
##
##for i in range (0,len(pep_people)): 
##    pep_file.write('%s - pepperoni\n'%(pep_people[i])) # the - is the delimeter, (in between the two values)
##    
##pep_file.close()

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
  

        
            
