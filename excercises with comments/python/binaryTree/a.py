def searchTree(root, toFind):
     if root is None:# בדיקה ראשונה - האם קיבלתי אובייקט שאני מחפש או הגיוני
          return False
     value, left, right = root[0],root[1],root[2]
     if value == toFind:
          return True
     return searchTree(left,value) or searchTree(right,value)


def makeTree(numbers):
     if len(numbers)==0:
          return None

     result = []
     median = numbers[int(len(numbers)/2)]

     result.append(median)
     result.append(makeTree(numbers[:int(len(numbers)/2)]))
     result.append(makeTree(numbers[int(len(numbers)/2)+1:]))
     return result



print(makeTree([1,2,4,5,8]))


