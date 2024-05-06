from threading import Thread    #classe genitore dei nostri thread
import time

class MyThread(Thread):

    def __init__(self, incr):
        super().__init__()
        self.var = 0
        self.incr = incr
    
    def run(self):
        #codice thread
        while True: 
            self.var+= self.incr
            time.sleep(1)
            print("thread " + str(self.var)+ "  " + str(self.incr))

def main():

    threads = MyThread(2)#alloco uno spazio in memoria
    threading = MyThread(4)#alloco uno spazio in memoria
    threads.start()
    threading.start()

    while True:
        threads.var += 1
        time.sleep(1)
        print("main " +  str(threads.var))

if __name__ == "__main__":
    main()