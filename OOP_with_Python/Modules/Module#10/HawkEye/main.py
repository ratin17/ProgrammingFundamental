

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPixmap,QImage,QIcon
from PyQt5.QtCore import QTimer
import cv2
from cv2 import VideoCapture

class Window(QWidget):

    def __init__(self):
        super().__init__()

        self.window_width=640
        self.window_height=480

        self.img_width=640
        self.img_height=480

        self.setWindowTitle("HakEye App")
        self.setGeometry(0,0,self.window_width,self.window_height)
        self.setFixedSize(self.window_width,self.window_height)


        self.timer=QTimer()
        self.timer.timeout.connect(self.update)
        

        self.ui()




    def ui(self):
        self.image_label=QLabel(self)
        self.image_label.setGeometry(0,0,self.img_width,self.img_height)

        if not self.timer.isActive():
            self.cap=cv2.VideoCapture(0)
            self.timer.start()


        self.show()


    def update(self):
        _,self,frame=self.cap.read()

        frame=cv2.cvtColor(self.frame,cv2.COLOR_BGR2RGB)
        height,width,channel=frame.shape
        step=channel*width




    def save_img(self):
        pass


    def record(self):
        pass
        


app=QApplication(sys.argv)
win=Window()
sys.exit(app.exec_())