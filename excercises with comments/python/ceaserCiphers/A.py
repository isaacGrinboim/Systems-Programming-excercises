from msilib import _directories
import os
import os.path as osp

def encrypt_char(c,k):
     num_alpha = ord('z')-ord('a')+1
     if not c.isalpha():
          return c
     else:
          if c.islower():
               return chr((ord(c)-ord('a')+k)%num_alpha +ord('a'))
          else:
               return  chr((ord(c)-ord('A')+k)%num_alpha +ord('A')) 
     
def encrypt_file(in_path, out_path, k):
     with open(in_path, 'r') as f:
          to_decrypt = f.read()
     with open(out_path,'w')as f:  
          for character in to_decrypt:
               f.write(encrypt_char(character))   

def encrypt_text_files(dir_path, k):
     if not dir_path.is_dir():
          raise IOError("Invalid directory")
     file_list = os.listdir(dir_path)
     for file in file_list:
          path_to_file = osp.join(dir_path, file)
          if file[-4:-1] == ".txt":
               new_file_path = osp.join(dir_path,file[0:-3],"enc")
               encrypt_file(path_to_file,new_file_path,k)




