import socket
import threading

class client_handler(threading.Thread):

    def __init__(self, connection):
        super().__init__()
        self.connection = connection
        self.running = True

    def run(self):
        message = self.connection.recv(BUFFER_SIZE)
        if message.decode() != "0":
                
            lock.acquire()
            num = 0

            with open(PATH_FILE, "r") as file:#posso fare anche rw

                print(f"{file}")

                try:
                    
                    balance = float(file.readline())
                    print(balance)
                    num = balance * int(message.decode()) / 100

                except:
                    print("non ho letto bene")

            with open(PATH_FILE, "w") as file: 

                balance -= num

                if (balance >= 0):

                    print(str(balance))

                    file.write(str(balance))
                    
                else:
                    print("il bilancio diventerebbe negativo")
                    balance += num
                    print(str(balance))
                    file.write(str(balance))
                

                

            lock.release()

            self.connection.sendall("Cambiamento apportato".encode())
        
        else:

            self.connection.sendall("Chiusura in Corso".encode())
            print("booooh")
            self.kill()

    def kill(self):
        self.running = False
        self.connection.close()


MY_ADDRESS = ("127.0.0.1", 9090)
BUFFER_SIZE = 4096

PATH_FILE = "Balance.txt"

lock = threading.Lock()

def main():

    with open(PATH_FILE, "w") as file:
        file.write("1000")
        
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(MY_ADDRESS)
    s.listen()
    list = []

    while True:
        connection, client_address = s.accept()#bloccante
        thread = client_handler(connection)
        thread.start()

        list.append(connection)
        print(list)

        for thr in list:
            if thr.running == False:
                thr.join()

if __name__ == "__main__":
    main()