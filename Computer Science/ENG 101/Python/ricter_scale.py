# Richter scale assignment
# Nolan Anderson
# 4/1/2019


richter_m = [1, 5, 9.1, 9.2, 9.5]
richter_energy = [] # empty list for energy values to go into
for i in richter_m:
    E = 10**((1.5*i)+4.8) # formula to find the energy
    richter_energy.append(E) # puts the calculated numbers into the empty energy list
    richter_energy = list(map(int, richter_energy)) # converts the elements in the list to integers
    richter_m = list(map(str, richter_m)) # converts the elements in the list to strings
    




for i, j in zip(richter_energy, richter_m): # allows the for loop to loop through richter_m and richter_energy
    # zip allows you to iterate in parallel
    richter_formatted = str(float("%.2f" % (i))) # formats the richter energy into a string and lowers # of decimals to one
    print("The amount of energy for a reading of " + j + " is " + richter_formatted + " joules")
    tnt_tons = i/4.184e+9 # calculation to find tons of TNT
    tnt_formatted = str(float("%.2f" % (tnt_tons))) # converts it into a string for prints statement
    print("The amount of tons of TNT in energy produced is " +tnt_formatted+ " tons\n")







