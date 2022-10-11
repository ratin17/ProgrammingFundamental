data="jhsdgvf'fd[sbdfghe[]f;'\n\n.,p[gaterwq  JK>>MHG^&*_)_++_)*$!@#FCBNMN><>><?MNBVXZAWETUIPPOKNBVDSSXCV  nbbvnmxcvipougfbhvfhbdf  hjhrbvfdsdew/,;[-=087125284vnxmzaavnmiyrtrhf"

cleanData=""

for char in data:
    if char.lower()=='a' or char.lower()=='e' or char.lower()=='i' or char.lower()=='o' or char.lower()=='u':
        if len(cleanData)!=0:
            cleanData+=f"{char}"
        else:
            cleanData+=char

print(cleanData)


