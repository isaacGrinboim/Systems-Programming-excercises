def get_palindrom_dict(str):
     result = {}
     for t in range(1,len(str)):
          temp_list = []
          for i in range(0,len(str)):
               if i>=0 and i+t-1 <= len(str)-1:
                    if is_polyndrom(str[i:i+t]):
                         temp_list.append(str[i:i+t])
          if temp_list  != []:
               result[t] = temp_list
     return result

def is_polyndrom(str):
     left,right = 0, len(str)-1
     while left<right:
          if str[left]!=str[right]:
               return False
          left+=1
          right-=1
     return True     



def check_match(str):     
     new_str = str[1::]
     if len(new_str)%2 != 0:
          return False
     str2 = new_str[1:len(new_str):2]
     str1 = new_str[0:len(new_str):2]
     for i in range(0,len(str1)):
          temp_str1_letter = str1[i]
          temp_str2_letter = str2[i]
          for j in range(0,len(str1)):
               if str1[j]==temp_str1_letter:
                    if str2[j]!=temp_str2_letter:
                         return False
     return True     
     
     
#print(check_match("jsdadgkdgugduuuddgadd"))     
     #i love you



     #  ________  ________
     # /        \/        \
     # \                  /
     #  \                /
     #   \              /
     #    \            /
     #     \          /
     #      \        /
     #       \      /
     #        \    /
     #         \  /
     #          \/
print(get_palindrom_dict("abbasa"))

