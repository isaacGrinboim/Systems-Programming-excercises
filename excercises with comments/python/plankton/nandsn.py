def sum_of_digits(n):
     result = 0
     while n!=0:
          result+=int(n%10)
          n=int(n/10)
     return result

import time
start_time = time.time()
for i in range (1,2000000):
     if i + sum_of_digits(i) == 2000:
          print(i)         
print("--- %s seconds ---" % (time.time() - start_time))
