import threading
import time

class Magazzino:
    def __init__(self):
        self.merce = 0
        self.semaforo = threading.Semaphore(1)  # Creazione del semaforo con capacità di 1 (accesso esclusivo)

    def aggiungi_merce(self, quantita):
        self.semaforo.acquire()  # Acquisizione del semaforo
        print(f"Aggiunta di {quantita} merce al magazzino.")
        self.merce += quantita
        print(f"Merce totale nel magazzino: {self.merce}")
        self.semaforo.release()  # Rilascio del semaforo

def processo_aggiunta_merce(magazzino, quantita):
    for _ in range(3):
        magazzino.aggiungi_merce(quantita)
        time.sleep(1)

def main():
    magazzino = Magazzino()
    
    t1 = threading.Thread(target=processo_aggiunta_merce, args=(magazzino, 5))
    t2 = threading.Thread(target=processo_aggiunta_merce, args=(magazzino, 3))
    t3 = threading.Thread(target=processo_aggiunta_merce, args=(magazzino, 2))
    
    t1.start()
    t2.start()
    t3.start()
    
    t1.join()
    t2.join()
    t3.join()

if __name__ == "__main__":
    main()
