

import pyautogui
import time


time.sleep(5)

s=""
for i in range(20):
    s=""
    s+="sending "+i
    pyautogui.write(s)
    pyautogui.press('enter')


