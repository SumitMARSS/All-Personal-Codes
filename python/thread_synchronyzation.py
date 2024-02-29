#thread synchronization
from threading import *
import time

cond = Condition()
done =1
def task(name):
    global done
    with cond:
        if done ==1:
            done = 2
            print("Waiting for cond var..",name)
            cond.wait()#wait for the notification or cond to be true
            print("Wait is over for task...//condition met",name)
        else:
            for i in range (5):
                print("...")
                time.sleep(2)
            print("Signaling Execution of task",name)
            cond.notify_all()#send notification or cond to be true
            print("notification done",name)

if __name__ == "__main__":
    t1 = Thread(target= task ,args="t1")
    t2 = Thread(target= task ,args="t2")
    t1.start()
    t2.start()
    t1.join()
    t2.join()

