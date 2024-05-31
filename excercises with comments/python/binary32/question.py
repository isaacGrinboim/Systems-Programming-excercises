def binary32ToInt(string):
     result = 0
     for i in range(0,len(string)):
          if string[i]=='1':
               result += 2**(len(string)-1-i)     
     return result     


def intToBinary32(int):
     return str(int)


def serialization(fileName, list):
     with open(fileName,'r') as f:
          f.write(intToBinary32(len(list)))
          for num in list[1:len[list]-1]:
               f.write(intToBinary32(num))


def deserialization(fileName):
     list = []
     with open(fileName, 'r') as f:
          text = f.read()
     numAmount = binary32ToInt(text[0:32])
     # print(numAmount)
     print(text[0:32])
     for i in range(1,numAmount+1):
          list.append(binary32ToInt(text[32*i:32*i+32]))
     return list

print(deserialization("numbers.txt"))

