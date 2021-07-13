### Dog's age in years

dog_human_age = input('How old is your dog in "human" years? ')
dog_human_age = int(dog_human_age)

if dog_human_age > 2:
    dog_true_age = (10.5*2)+((dog_human_age-2)*4)
if dog_human_age <= 2:
    dog_true_age = dog_human_age*10.5
print('Your dog is ',dog_true_age,' years old.')
