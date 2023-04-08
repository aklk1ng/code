import threading
import time


def sing(msg):
    while True:
        print("Hello..." + msg)
        time.sleep(1)


def dance(msg):
    while True:
        print(f"World...{msg}")
        time.sleep(1)


if __name__ == "__main__":
    sing_thread = threading.Thread(target=sing, args=("sing", ))
    dance_thread = threading.Thread(target=dance, args=("dance", ))
    sing_thread.start()
    dance_thread.start()
