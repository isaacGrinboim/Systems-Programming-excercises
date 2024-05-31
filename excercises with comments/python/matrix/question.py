from cmath import sqrt
def readMatrix(fileName):
     with open(fileName) as f:
          lines = f.read().splitlines()
     list = []
     for line in lines:
          temp = []
          for word in line.split(" "):
               temp.append(word)
          list.append(temp)
     return list

def frob(matrix):
     result = 0
     for line in matrix:
          for num in line:
               result+=int(num)*int(num)
     return result**0.5          
     
def squaresVector(matrix):
     return [rowSquared(line) for line in matrix]
     

               
print(readMatrix("text.txt")) 
print(frob(readMatrix("text.txt"))) 

