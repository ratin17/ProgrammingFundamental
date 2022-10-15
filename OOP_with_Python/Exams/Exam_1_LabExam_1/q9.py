
replace_with = ["chief", "thief", "superintendent", "sweeper", "married", "left", "tried", "died"]


def replace_word(story):
    words=story.split(" ")
    for word in words:
        if word in replace_with:
            replacer=replace_with[replace_with.index(word)+1]
            newStory=story.replace(word,replacer)
            story=newStory
    return newStory

s = "I am the chief of Baghdad. Before that I used to be a superintendent of Bank Asia. Things have changed a lot since Jorina married me. A lot of girls tried to marry me."

print(replace_word(s))