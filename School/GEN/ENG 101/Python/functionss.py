def greet1():
    """Display a simple greeting"""
    print("Hello!")
    
greet1()

################################

def greet2(username):
    """DIsplay a simple greeting"""
    print("Hello.", username.title() + "!")
greet2("Nolan")

################################

def pet_info(animal,name):
    """Display info about a pet"""
    print("I have a " +animal+".")
    print("My " +animal+ "'s name is " +name.title() + ".\n")
pet_info('dog','max')
## or
pet_info(animal = 'dog', name = 'max')

################################

def fahrenheit(Tc):
    """Returns the temperature in degrees Fahrenheit"""
    return (Tc * 9/5) + 32 # returns the info
for t in (22.6, 25.8, 27.3, 29.8):
    print(t,": ", fahrenheit(t))

################################

def format_name(f_name,l_name):
    """Return a full name neatly formatted"""
    full_name = f_name+' '+l_name
    return full_name.title()
fav_prof = format_name('jennifer', 'english')
print("My favorite professor is" ,fav_prof)

################################

def format_name_new(f_name,l_name,tp):
    """Return a title and full name in dictionary"""
    full_name_new = f_name.title()+' '+l_name.title()
    prefix = tp.title()
    return {'t':prefix,'full':full_name_new}

