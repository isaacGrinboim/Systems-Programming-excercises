from itertools import product


def find_best_selling_product(file_name):
     has_been_sold = {}
     products = {}
     with open (file_name) as f:
          lines = f.read().splitlines()
     for line in lines:
          command = line.split(" ")
          if command[0] == "add":
               if command[2] in products:
                    continue
               products[command[2]] = (float(command[3]),float(command[4]))
          if command[0] == "change":
               if (command[2] not in products) or ((products[command[2]][1]-float(command[4]))<0):
                    continue
               products[command[2]][1]-=float(command[4])
          if command[0] == "ship":
               orders = len(line[11::].split('--'))
               for order in orders:
                    name,amount = order.split(",")
                    if name not in products or amount>products[name][1]:
                         continue
                    products[name][1]-=amount
                    if name not in has_been_sold:
                         print(" now added "+ name +" to has been")
                         has_been_sold[name] = 0
                    has_been_sold[name] += products[name][0]     
          print("here")
          print(has_been_sold)          
          result_list = [(name,current_price)   for   name,current_price in has_been_sold.items()]
          print(result_list) 
          return sorted(result_list, key = lambda x: x[1])
          

def find_k_most_expensive_products(file_name, k):
     with open(file_name) as f:
          lines = f.read().splitlines()
     products = {}     
     for line in lines:
          command = line.split(" ")
          if command[0] == "add":  
               products[command[2]] = command[3]
     result = []
     for i in range(0,k):
          result.append(most_expensive_product(products))
          del products[product]
     return result

def most_expensive_product(products):
     print(max(products.items(), key = lambda x: x[1]))
     return max(products.items(), key = lambda x: x[1])




print(find_best_selling_product("commands.txt"))
find_k_most_expensive_products("commands.txt", 2)
