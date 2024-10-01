import socket

SERVER_ADDRESS = ("127.0.0.1", 9090)
BUFFER_SIZE = 4096

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(SERVER_ADDRESS)

    perc = int(input("che percentuale vuoi prelevare?"))
    s.sendall(str(perc).encode())

    message = s.recv(BUFFER_SIZE)

    print(f"ricevuto il mesaggio \"{message.decode()} dal server")

    s.close()

if __name__ == "__main__":
    main()
    