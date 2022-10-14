

import pyautogui
import time


time.sleep(5)


for i in range(20):
    pyautogui.write('hello')
    pyautogui.press('enter')


