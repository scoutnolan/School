#palindrome
string = input('Please give me a string: ')
left_pos = 0 #The first character in the string
right_pos = len(string) - 1
np = 0 # If np > 0, there is a mismatch

while right_pos >= left_pos:
    if string[left_pos] != string[right_pos]:
        np += 1
    left_pos += 1
    right_pos -= 1
if np > 0:
    print(string, ' is not a palindrome')
else:
    print(string, ' is a palindrome')
    
    
