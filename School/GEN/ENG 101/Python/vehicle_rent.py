#### Charge for vehicle rent ####
# Nolan Anderson
# 4/1/2019

print("What type of car did you rent?")
car_type = input(str("C (compact) ; M (mid-size) ; L (luxury) ; S (SUV) ; or V (van)  ")).lower() #.lower() makes everything lowercase
car_type = car_type[0] # makes car_type equal to the first letter of the string
days_rented = int(input("How many days did you rent the car for? "))
odometer_initial = int(input("What was the odometer when you initially got in the car? "))
odometer_final = int(input("What does the odometer read now? "))
cleaned = input(str("Does the car need to be cleaned? ")).lower() 
cleaned = cleaned[0] # first value in the string
odometer_delta = (odometer_final-odometer_initial) # difference in the final and inital odometer, easier to refer to
average_mileage = odometer_delta / days_rented # average mileage for the van pricing




charge = 0 # initially state charge value
## If statements to calculate mileage / day charges
if car_type == ('c'):
    charge = (20*days_rented + (odometer_delta)*0.25)
elif car_type == ('m'):
    charge = (29.50*days_rented + (odometer_delta)*0.29)
elif car_type == ('l'):
    charge = (44.25*days_rented + (odometer_delta)*0.48)
elif car_type == ('s'):
    charge = (40*days_rented + (odometer_delta)*0.53)
elif car_type == ('v'): # if statement for van, since it is a different cost
    if average_mileage > 100:
        charge = (60*days_rented + (average_mileage-100)*.25)
    else:
        charge = (60*days_rented)




# here so if the first letter of the car_type is not equal to c,v,s,m, or l.
else:
    print("Please run the program again, this is not a valid type of car to rent.")




# adds the charge of the cleaning process if it needs to be cleaned, prints normal charge if not.
if cleaned == ('y'): 
    if car_type == ('s'):
        charge = charge + 40 # cleaning if statement for SUV since it costs more
        print("The charge for you rental is", + charge) 
    else:
        charge = charge + 20 # else for the other cars
        print("The charge for you rental is", + charge) 
    
if cleaned == ('n'): # if statement if the car doesnt need to be cleaned
    print("The charge for you rental is", + charge)    
