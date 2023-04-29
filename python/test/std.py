import os
import random
import glob
import math
import sys
import statistics
import zlib
from urllib.request import urlopen
from datetime import date
from timeit import Timer
import threading, zipfile
from collections import deque
from heapq import heapify, heappop, heappush

print(os.getcwd())
os.system("echo 'this is a python system call'")
print(dir(os))
# print(help(os))
print(glob.glob("*.py"))

sys.stderr.write("Warning, log file not found starting a new one\n")

print(math.cos(math.pi / 4))
print(math.log(1024, 2))
print(random.choice(["app", "2", "3"]))
print(random.sample(range(100), 10))
print(random.random())  # random float
print(random.randrange(8))  # random integer chosen from range(8)

data = [2.75, 1.75, 1.25, 0.25, 0.5, 1.25, 3.5]
print(statistics.mean(data))  # Return the sample arithmetic mean of data
print(statistics.median(data))  # Return the median (middle value) of numeric data
print(statistics.variance(data))  # Return the sample variance of data


with urlopen("http://google.com") as response:
    for line in response:
        line = line.decode()  # convert bytes to a str
        print(line.rstrip())


print(date.today())
print(date.today().strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B."))

s = b"witch which has which witches wrist watch"
print(len(s))
print(zlib.compress(s).__len__())
print(zlib.decompress(zlib.compress(s)))
print(zlib.crc32(s))


print(Timer("t=a; a=b; b=t", "a=1; b=2").timeit())


class AsyncZip(threading.Thread):
    def __init__(self, infile, outfile):
        threading.Thread.__init__(self)
        self.infile = infile
        self.outfile = outfile

    def run(self):
        f = zipfile.ZipFile(self.outfile, "w", zipfile.ZIP_DEFLATED)
        f.write(self.infile)
        f.close()
        print("Finished background zip of:", self.infile)


# background = AsyncZip("./std_test/data.txt", "./std_test/data.zip")
# background.start()
# print("The main program continues to run in foreground,")
# background.join()
# print("Main program watied until background was done.")

starting_node = ["task1", "task2", "task3"]
d = deque(starting_node)
d.append("task4")
print(d.popleft())

text = [1, 3, 5, 6, 8, 2, 4]
heapify(text)  # rearrange the list into heap order
print([heappop(text) for i in range(3)])  # fetch the three smallest entries
