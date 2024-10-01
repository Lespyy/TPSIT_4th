import socket 

SERVER_ADDRESS = ("192.168.1.146", 8000)
BUFFER_SIZE = 4096

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(SERVER_ADDRESS)

    while True:

        com = input("Che comando vuoi mandare?\n->")
        s.sendall(com.encode())

        message = s.recv(BUFFER_SIZE)
        print(f"ricevuto il mesaggio \"{message.decode()} dal bot")

    s.close()

if __name__ == "__main__":
    main()