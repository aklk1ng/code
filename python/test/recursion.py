import os


def get_files(path):
  file_list = []
  if not os.path.exists(path):
    print("There is no file or directory!")
    return []
  else:
    for f in os.listdir(path):
      if path.endswith('/'):
        absolute_path = path + f
      else:
        absolute_path = path + '/' + f
      if not os.path.isdir(absolute_path):
        file_list.append(absolute_path)
      else:
        file_list += get_files(absolute_path)

  return file_list

if __name__ == "__main__":
  print(get_files("/home/cjh/code/python/test/"))
