

class Product:
    def __init__(self, name, quantity, price):
        self.product_name = name
        self.product_quantity = quantity
        self.product_price = price


class Store():
    def __init__(self):
        self.product_quantity = {}
        self.product_price = {}

    def add_product(self,name,quantity,price):
            product = Product(name,quantity,price)
            
            self.product_quantity[product.product_name] = product.product_quantity
            self.product_price[product.product_name] = product.product_price

    def show_product(self):
            print("all product quantity:",self.product_quantity)
            print("all product price:",self.product_price)


class Shop(Store):
    # shop_name ='apple Bd'
    def __init__(self,name):
        self.shop_name = name
        super().__init__()

shop_1 = Shop('bd shop')
shop_1.add_product('apple 13',20,400)
shop_1.show_product()

