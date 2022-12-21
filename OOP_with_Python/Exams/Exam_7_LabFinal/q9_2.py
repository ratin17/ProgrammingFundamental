file = open ( 'words.dat' , 'w' ) 
word = " "
while word != "" : 
    word =input ( 'Enter a word (enter only ENTER to quit): ')
    file.write ( word + '\n' ) 
file.close ( )

