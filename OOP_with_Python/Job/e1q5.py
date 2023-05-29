import pyautogui
import time

def draw_pyramid(num_rows, start_x, start_y, block_size):
    for row in range(num_rows):
        num_blocks = row + 1
        row_x = start_x - (num_blocks * block_size // 2)
        for _ in range(num_blocks):
            pyautogui.moveTo(row_x, start_y)
            pyautogui.write("#", interval=0.05)
            row_x += block_size
        start_y -= block_size

def main():
    num_rows = int(input("Enter the number of rows for the pyramid: "))
    start_x = 500
    start_y = 500
    block_size = 20
    draw_pyramid(num_rows, start_x, start_y, block_size)
    time.sleep(2)

if __name__ == "__main__":
    main()

