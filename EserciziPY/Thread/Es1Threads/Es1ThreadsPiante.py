"""
Es1. 
Implementare un sistema per gestire le piante 
in un giardino utilizzando il concetto di multithreading 
e l'ereditarietà delle classi, gestire in modo corretto 
l'avvio dei thread, l'attesa del completamento dei thread 
e la sincronizzazione tra i thread, utilizzare l'ereditarietà 
delle classi per evitare la duplicazione del codice.

Danilo

"""

import threading
import time

class Plant(threading.Thread): # MyThread è una sottoclasse di threading.Thread

# Il metodo __init__ è il costruttore della classe, prende i parametri name, delay e inizializza gli attributi delay e name
    def __init__(self, name, delay):
        super().__init__()
        self.name = name
        self.delay = delay

    def run(self): #run è un metodo che viene eseguito quando si avvia il thread
        print("Thread %s avviato" % self.name)
        print("In attesa di %d secondi" % self.delay)
        time.sleep(self.delay) # attesa dell'attributo delay
        print("Thread %s completato" % self.name)

# Sottoclasse che eredita da MyThread
class Flower(Plant): # sottoclasse di MyThread eredita tutti gli attributi e i metodi di MyThread
# il costruttore inizializza l'attributo repeat e permette di specificare il numero di ripetizioni per l'operazione
    def __init__(self, name, delay, repeat):
        super().__init__(name, delay)
        self.repeat = repeat

    def run(self):
        print("Thread %s avviato" % self.name)
    # questo metodo esegue un ciclo specificato dal parametro repeat stampando un messaggio per ogni iterazione e attende per un certo arco di tempo tra le iterazioni
        for i in range(self.repeat):
            print("Ciclo %d di %s" % (i+1, self.name))
            time.sleep(self.delay)
        print("Thread %s completato" % self.name)

def main():

    # Creazione di istanze di classi thread
    thread1 = Plant("Thread 1", 2) # istanza di MyThread
    thread2 = Flower("Thread 2", 3, 2)  # istanza di MyThreadSubclass

    # Avvio dei thread con utilizzo del metodo start che fa eseguire il metodo run
    thread1.start()
    thread2.start()

    # il metodo join attende che entrambi i thread bbiano terminato l'esecuzione prima di procedere con il resto del codice+
    thread1.join()
    thread2.join()

    print("Fine del programma")

if __name__ == "__main__":
    main()