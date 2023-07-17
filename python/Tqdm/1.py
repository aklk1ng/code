import time
import tqdm

names = ["cjh", "akl", "test"]

for name in tqdm.tqdm(names):
    time.sleep(1)

print("Ok")
