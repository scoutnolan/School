g_catalog_list=['eggs', 'bacon', 'bread', 'coffee', 'orange juice', 'butter',\
                'grape jelly', 'bananas', 'apples', 'donuts', 'milk', 'salt',\
                'pepper', 'ham', 'potatoes', 'biscuits']

sizes_list=['dozen', 'lb', 'loaf', 'lb', 'gallon', 'lb', '16 oz jar', 'bunch', '5 lb bag',\
            'dozen', 'gallon', 'jar', 'jar', 'lb', 'lb', 'dozen']

stock_list=[20, 18, 40, 2, 5, 90, 7, 25, 12, 50, 3, 16, 13, 42, 57, 108]

price_list=[1.99, 7.85, 1.58, 5.99, 4.99, 2.39, 1.98, 2.89, 3.99, 2.50, 2.99, 3.99, 5.00, 8.99, 2.58, 6.89]

# create a dictionary with g_catalog_list as keys and sizes_list as values

g_size = {}
for i in range (len(g_catalog_list)):
    g_size[g_catalog_list[i]] = sizes_list[i]
#print(g_size)

#create a dictionary with g_catalog_list as keys and stock_list as values

g_stock = dict(zip(g_catalog_list, stock_list))
print(g_stock)

#creates a dictionary with g_catalog_list as keys and price_list as values
g_price = {}
for i in range (len(g_catalog_list)):
    g_price[g_catalog_list[i]] = price_list[i]
print(g_price)

for i in g_stock:
    print(i+': ' + str(g_stock[i]) + ' in stock.')  

    



