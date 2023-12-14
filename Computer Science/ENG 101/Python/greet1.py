##def greet1():
##    """Display a simple greeting"""
##    print("Hello!")
##    
##greet1()

def greet2(username):
    """DIsplay a simple greeting"""
    print("Hello.", username.title() + "!")
greet2("Nolan")


def pet_info(animal,name):
    """Display info about a pet"""
    print("I have a " +animal+".")
    print("My " +animal+ "'s name is " +name.title() + ".\n")
pet_info('dog','george')
