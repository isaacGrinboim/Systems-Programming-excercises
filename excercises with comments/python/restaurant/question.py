def get_price (dish_name):
     with open("products.txt") as f:
          lines = f.read().splitlines()
     products = {}     
     for line in lines:
          prod_name, price, calories = line.split(",")
          products[prod_name] = (int(price), int(calories)) 
     with open("dishes.txt") as f:
          lines = f.read().splitlines()
     dish = []
     for line in lines:
          temp_line = line.split(",")
          if temp_line[0] == dish_name:
               dish = temp_line
               break
     if dish == []:
          return -1
     for temp_product in dish[1:len(dish):2]:
          if temp_product not in products:
               return -1
    
     for i in range(1,len(dish),2):
          products_in_dish = [(dish[i],dish[i+1]) for i in range(1,len(dish),2)]
     print(products_in_dish)
     products_names = []
     for i in range(0, len(products_in_dish)):
          products_names.append(return_chipest(products_in_dish))
          for product in products_in_dish:
               temp,_ = product
               if temp == return_chipest(products_in_dish):
                    products_in_dish.remove(product)
     result = 0
     # for i in range(0,len(products_names)):
     #      temp = 
     #      if(i>=0 and i<=2):
     #           result += product[]



     print(products_names)     




def return_chipest(list):
     min_name, min = list[0]      
     for pair in list:
          temp_min_name, temp_min = pair
          if temp_min < min:
               min_name = temp_min_name
               min = temp_min
     return min_name                                             


    
     
     
     #for product,value in products_in_dish.items():



get_price("sushi")


          