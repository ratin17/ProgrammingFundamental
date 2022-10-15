
def create_list(d):
    toList=list()
    for key,value in d.items():
        toList.append(key)
        toList.append(value)
    return toList


d = {'!': 1, '@' : 2, '#': 3, '$' : 4, '%' : 5, '^' : 6}

print(create_list(d))