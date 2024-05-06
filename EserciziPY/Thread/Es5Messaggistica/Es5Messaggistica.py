import threading
import socket

# Funzione per inviare messaggi tramite socket
def invia_messaggio(indirizzo, messaggio):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((indirizzo, 12345))  # Assicurati di sostituire 12345 con il numero di porta appropriato
    client_socket.send(messaggio.encode())
    client_socket.close()

# Funzione per ricevere messaggi tramite socket
def ricevi_messaggio():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 12345))  # Assicurati di sostituire 12345 con il numero di porta appropriato
    server_socket.listen(1)
    while True:
        conn, _ = server_socket.accept()
        messaggio = conn.recv(1024).decode()
        print("Messaggio ricevuto:", messaggio)
        conn.close()

# Creazione di due thread per l'invio e la ricezione dei messaggi
thread_invio = threading.Thread(target=invia_messaggio, args=("127.0.0.1", "Ciao!"))
thread_ricezione = threading.Thread(target=ricevi_messaggio)

# Avvio dei thread
thread_invio.start()
thread_ricezione.start()

# Attendi il completamento dei thread
thread_invio.join()
thread_ricezione.join()
