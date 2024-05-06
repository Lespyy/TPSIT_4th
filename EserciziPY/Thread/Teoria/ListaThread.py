from threading import Thread
import time

class MioThread(Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome
        self.running = True

    def run(self):
        # Codice del Thread
        while self.running:
            print(f"Sono il thread {self.nome}")
            time.sleep(1)

    def kill(self):
        self.running = False

def main():
    lista_nomi = ["alice", "bob", "Trudy"]
    lista_Thread = [MioThread(n) for n in lista_nomi]
    for t in lista_Thread:
        t.start()
    for _ in range(4):
        print("Sono il main Thread")
        time.sleep(1)
        print("\n")
    for t in lista_Thread:
        t.kill()
        t.join()
    print("Sono il main thread è ho killato tutti gli altri")

if __name__ == "__main__":
    main()
