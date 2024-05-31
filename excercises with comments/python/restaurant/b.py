from re import A
from subprocess import HIGH_PRIORITY_CLASS


def get_most_expensive_dish (cal):
     with open("dishes.txt") as f:
          lines = f.read().splitlines()
     result = "" 
     max = 0
     dish = ""
     
     for line in lines:
          dish = line.split(',')[0]
          if get_price(dish)>max and get_cal_value(dish)>cal:
               max = get_price(dish)
               result = dish

     if result == "":
          return -1

     return result     

def get_cal_value(dish_name):
     with open("products.txt") as f:
          lines = f.read().splitlines()
     products = {}
     for line in lines:
          products[line.split(',')[0]] = int(line.split(',')[2])
     
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
     products_in_dish_with_amounts = {}          
     for i in range(1,len(dish),2):
          products_in_dish_with_amounts[dish[i]]=int(dish[i+1])
     products_in_dish = sorted([(info,product) for product,info in products.items() if product in dish[1:len(dish):2]])        
     result = 0


     for i in range(0,len(products_in_dish)):
          result+=products[products_in_dish[i][1]]*products_in_dish_with_amounts[products_in_dish[i][1]]
     return result
     
     



print(get_cal_value("sushi"))




get_most_expensive_dish(12)


























def get_price (dish_name):
     with open("products.txt") as f:
          lines = f.read().splitlines()
     
     products = {}
     for line in lines:
          products[line.split(',')[0]] = int(line.split(',')[1])
     
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
     products_in_dish_with_amounts = {}          
     for i in range(1,len(dish),2):
          products_in_dish_with_amounts[dish[i]]=int(dish[i+1])
     products_in_dish = sorted([(info,product) for product,info in products.items() if product in dish[1:len(dish):2]])        
     result = 0


     for i in range(0,len(products_in_dish)):
          if i>=0 and i<= 2:
               result += products[products_in_dish[i][1]]*products_in_dish_with_amounts[products_in_dish[i][1]]* 0.9
          if i>= 3 and i <= 6:
               result += products[products_in_dish[i][1]]*products_in_dish_with_amounts[products_in_dish[i][1]]*0.95
          else:
               result+=products[products_in_dish[i][1]]*products_in_dish_with_amounts[products_in_dish[i][1]]
     return result
     
     

