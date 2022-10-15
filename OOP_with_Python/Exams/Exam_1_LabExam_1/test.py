import q8
def test_script():
    upper=q8.make_upper("Abc xYz")
    lower=q8.make_lower("Abc xYz")
    capital=q8.make_capital("aBc xYz")

    up=False
    low=False
    cap=False

    if(upper.isupper()):
        up=True
    if(lower.islower()):
        low=True
    if(capital[0]=="A"):
        cap=True
    
