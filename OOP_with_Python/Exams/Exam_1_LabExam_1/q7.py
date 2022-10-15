def replace_comma_with_space(text):
    withSpace=""
    for i in text:
        if i==',':
            withSpace+=" "
        else:
            withSpace+=i
    return withSpace

s = "I,have,been,practising,python,since,the,course,started"

output = replace_comma_with_space(s)
print(output)
