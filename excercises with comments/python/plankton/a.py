def is_permutation(str1,str2):
     letters = {}
     for letter in str1:
          if letter not in letters:
               letters[letter] = 0
          letters[letter]+=1
     for letter in str2:
          if letter not in letters:
               return False
          letters[letter]-=1
     for amount in letters.values():
          if amount != 0:
               return False
     return True
