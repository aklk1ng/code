import curses
import threading
import time


def update_file_content(window, path):
    while True:
        with open(path, "r") as file:
            lines = file.readlines()

        window.clear()
        for i, line in enumerate(lines):
            window.addstr(i, 0, line)
        window.refresh()
        time.sleep(1)  # Update every second


def input_box(stdscr):
    curses.echo()

    # Setup the window for file content
    file_content_height = curses.LINES - 3
    file_content_window = curses.newwin(file_content_height, curses.COLS, 0, 0)
    file_content_window.scrollok(True)

    # Setup the window for input box
    input_box_window = curses.newwin(3, curses.COLS, curses.LINES - 3, 0)
    input_box_window.box()
    input_box_window.addstr(1, 1, "Input: ")
    input_box_window.refresh()

    # Start thread for updating file content
    file_path = "/usr/bin/asciiquarium"  # Change this to your file path
    threading.Thread(
        target=update_file_content, args=(file_content_window, file_path), daemon=True
    ).start()

    while True:
        # Get input from the user
        input_str = input_box_window.getstr(1, 8, 20)

        # Process the input (Here, just print it to the console)
        print(input_str.decode("utf-8"))

        # Clear the input box after getting input
        input_box_window.clear()
        input_box_window.box()
        input_box_window.addstr(1, 1, "Input: ")
        input_box_window.refresh()


def main():
    curses.wrapper(input_box)


if __name__ == "__main__":
    main()
