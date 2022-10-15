
def make_upper(str):
    return str.upper()

def make_lower(str):
    return str.lower()

def make_capital(str):
    return str.capitalize()

def test_script():
    upper=make_upper("Abc xYz")
    lower=make_lower("Abc xYz")
    capital=make_capital("aBc xYz")

    up=False
    low=False
    cap=False

    if(upper.isupper()):
        up=True
    if(lower.islower()):
        low=True
    if(capital[0]=="A"):
        cap=True
    
    assert up and low and cap