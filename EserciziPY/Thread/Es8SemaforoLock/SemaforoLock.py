import threading 
import time

lock = threading.Lock()

semaforo =threading.Semaphore(1)#indica il numero di thread che alla volta possono usare la parte critica


class stampaNome(threading.Thread):
    
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    def run(self):
        for _ in range(5):
                semaforo.acquire()
                print("Ciao ", end="")
                time.sleep(1)
                print(self.nome)
                semaforo.release()

def main():
    """thread = stampaNome("Mario")
    thread.start()
    thread.join()"""

    nomi = ["Mario", "Luca", "Alice", "Bob"]
    listaThread=[stampaNome(nome) for nome in nomi]
    for thread in listaThread:
        thread.start()

    for thread in listaThread:
        thread.join()







if __name__ == "__main__":
    main()