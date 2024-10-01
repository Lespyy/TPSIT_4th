import threading
import time 
from random import randint

#creo un oggett di tipo Lock che è un blocco
lock = threading.Lock()

class Prelievo (threading.Thread):
    def __init__(self, percent):
        super().__init__()
        self.percent = int(percent)

    def run (self):
        while True:

            lock.acquire()

            with open("Balance.txt", 'r') as file:
                balance = file.read()
                print(balance)
                number = balance * (self.percent / 100)

            with open("Balance.txt", 'w') as file:
                
                if(balance - number >= 0):
                    balance -= number
                    file.write(f"{balance}")
                else:
                    print("non hai abbastanza soldi")
                    self.running = False

            lock.release()
            #print(f"il saldo aggiornato è {balance}")
            time.sleep(5)


def main():

    lista = []
    for i in range(0, 10):
        lista.append(Prelievo(randint(-5, 5)))
        lista[i].start()
    


    

if __name__ == "__main__":
    main()


"""
Il balance non è più una variabile ma un valore su un file

ogni volta che vi opero apro il file leggo aggiorno e chiudo il file 

dentro al thread implementa il meccanismo che impedisca al saldo di diventare negativo

creiamo una lista di 10 thread ciascuno con una percentuale diversa dagli altri e li eseguiamo

dentro la classe thread implentiamo il metodo kill

il main thread lascia eseguire i thread per un minuto poi li killa e fa la join

"""

