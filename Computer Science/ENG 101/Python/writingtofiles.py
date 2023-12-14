### Writing to a file ###
# first open the file using 'w'


file = open('myfile.txt','w')
file.write('Hello World\n')
file.write('This is our new text file\n')
file.write('I can write new text to it\n')
file.write('Did you know that 2*2 is '+str(2*2)+' ?\n')
file.close()
