pizza_pref = {} # create empty dictionary

for line in open("pizza.txt"):
    line = line.strip()
    parts = line.split(" - ")
    pizza_pref[parts[0]] = parts[1]

print(pizza_pref)


# how many people chose pepperoni
pep_count = 0
pep_lovers = []
for line in open("pizza.txt"):
    line = line.strip()
    parts = line.split(" - ")
    if "pepperoni" in parts[1]:
        pep_count += 1
        pep_lovers.append(parts[0])
        
print(pep_count)
print(pep_lovers)

