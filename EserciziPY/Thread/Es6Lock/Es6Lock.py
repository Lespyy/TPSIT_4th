import threading
import time 

balance = 1000 #importo iniziale
#creo un oggett di tipo Lock che è un blocco
lock = threading.Lock()

class Prelievo (threading.Thread):
    def __init__(self, percent):
        super().__init__()
        self.percent = percent

    def run (self):
        while True:
            global balance
            number = balance * (self.percent / 100)
            time.sleep(1) 
            """
            fa si che il primo thread che acquisiche la lock è l'unico che opera dulla variabile poi lo rilascia quando a concluso l'operazione E QUINDI E' BLOCCANTE
            si può chiamare anche mutex = mutuamente esclusivo 
            """
            lock.acquire()
            balance -= number
            lock.release()
            print(f"il saldo aggiornato è {balance}")
            time.sleep(5)


def main():

    luca = Prelievo(5) #preleva
    mario = Prelievo(-6) #deposita

    mario.start()
    luca.start()
    

if __name__ == "__main__":
    main()


"""
Cercando di utilizzare la stessa risorsa i due thread si trovano nella race condition

Per gestire una race condition bisogna capire quale è la sezione critica del codice

    quindi il comando che modifica la variabile comune

la situazione critica di un thread è la porzione crtica di un codice in cui il trhead opera in scrittura sulla risolrsa condivisa


"""

