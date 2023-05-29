class Shopping:

    def __init__(self, name):
        self.name = name
        self.cart = []

    def add_to_cart(self, item, price, quantity):
        product = {"item": item, "price": price, "quantity": quantity}
        self.cart.append(product)

    def checkOut(self):
        total = 0
        for item in self.cart:
            total += item["price"] * item["quantity"]
        return total

    def remove_item(self, item):

        for k in enumerate(self.cart):

            indx=k[0]
            product=k[1]

            for _,(_,ITEM) in enumerate(product.items()):
                if ITEM==item:
                    self.cart.pop(indx)


    def showCart(self):

        print("\nShowing Cart Details:\n")

        for products in self.cart:
            for _,(field,val) in enumerate(products.items()):
                print(f'{field}: {val} | ',end='')
            print()


Juel = Shopping("Juel")

Juel.add_to_cart("Shirt", 2, 100)
Juel.add_to_cart("Juta", 3, 200)
Juel.add_to_cart("Pant", 5, 600)

Juel.showCart()


# Juel.checkOut()
# print(total_shopping)

Juel.remove_item("Juta")

Juel.showCart()