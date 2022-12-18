
file = open ( 'words.dat' , 'r' ) 
lines=file.readlines() 

for line in range(len(lines)):
    # end="" is sed because data file 
    # already contains \n after each line
    print(f"{line+1}: {lines[line]}",end="")

file.close ( )


