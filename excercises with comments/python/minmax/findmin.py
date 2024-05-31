def findmin(array):
     if len(array)==0:
          return 10**12

     minRestOfArray =findmin(array[1:])
     if array[0]< minRestOfArray:
          return array[0]
     else:
          return minRestOfArray   


