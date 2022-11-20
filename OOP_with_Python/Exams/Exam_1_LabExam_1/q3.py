import pyjokes
import random

affirmative=["yes","yup","sure","yeh","obvoiusly","okay","ok","tell","want","ha","like"]
negative=["no","nope","na","dont","never","not"]


def tell_some_jokes(commands):
    while True:
        decided=False
        commands=commands.lower()
        words=commands.split(" ")
        for word in words:
            if word in affirmative:
                decided=True
                jokes=list()
                jokes=pyjokes.get_jokes(language="en",category="all")
                n=random.randint(1,3)
                print("\nI have",n,"jokes for you !")
                print("--------------------------")
                for i in range (1,n+1):
                    print("Joke :",i)
                    print(jokes[i])
                    print("--------------------------")
                commands=input("\nWant to hear more Jokes?:")
                break
            elif word in negative:
                print("\nI understand we dont always like hearing jokes")
                print("Call me again when you want\n")
                return
        if not decided:
            decided=False
            print("\nI am not sure whether you want or not to hear jokes")
            print("Tell me more clearly")
            commands=input("Like, you can tell me 'Yes' or 'No':" )


    
commands=input("\nHi! this is from JokesBot. Want to hear Jokes?:")
tell_some_jokes(commands)

