import os

path = os.getcwd()
print("old path:" + path)
parent_dir_pos = path.rfind('/')
new_path = path[:parent_dir_pos]
os.chdir(new_path)
print("new paht:" + os.getcwd())
