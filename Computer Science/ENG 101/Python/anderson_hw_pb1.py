#richter scale assignment

# E = 10^((1.5*r)+4.8)
# tnt energy: 4.184e9

# make a list of energy based on the richter scale measurements
# 1, 5, 9.1, 9.2, 9.5

richter_m = [1, 5, 9.1, 9.2, 9.5]
richter_energy = []
for i in richter_m:
    E = 10**((1.5*i)+4.8)
    richter_energy.append(E)

    richter_energy = list(map(str, richter_energy))
    richter_m = list(map(str, richter_m))
print(richter_energy)
print(richter_m)
    








#for i in range(len(richter_energy)):
    #print (richter_energy[i])
