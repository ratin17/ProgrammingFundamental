import cv2 as c

cap=c.VideoCapture(0)

while True:
    _,frame=cap.read()
    c.imshow("output",frame)

    if c.waitKey(10)==ord('q'):
        break

cap.release()
c.destroyAllWindows()

