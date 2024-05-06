import threading
import time

class ContoBancario(threading.Thread):
    def __init__(self, numero, saldo_iniziale):
        super().__init__()
        self.numero = numero
        self.saldo = saldo_iniziale
        self.lock = threading.Lock()  # Lock per garantire la sincronizzazione

    def run(self):
        pass  # Non facciamo nulla nel metodo run di ContoBancario

    def deposita(self, quantita):
        with self.lock:
            print("Deposito di", quantita, "sul conto", self.numero)
            self.saldo += quantita

    def preleva(self, quantita):
        with self.lock:
            print("Tentativo di prelievo di", quantita, "dal conto", self.numero)
            if self.saldo >= quantita:
                print("Prelievo di", quantita, "dal conto", self.numero)
                self.saldo -= quantita
            else:
                print("Saldo insufficiente sul conto", self.numero)

class ContoRisparmio(ContoBancario):
    def __init__(self, numero, saldo_iniziale):
        super().__init__(numero, saldo_iniziale)

def main():
    conto1 = ContoBancario(1, 1000)
    conto2 = ContoRisparmio(2, 500)

    operazioni_conto1 = [
        conto1.deposita,
        conto1.preleva,
        conto1.preleva,
    ]

    operazioni_conto2 = [
        conto2.preleva,
        conto2.deposita,
        conto2.preleva,
    ]

    threads = []
    for operazioni in [operazioni_conto1, operazioni_conto2]:
        thread = threading.Thread(target=esegui_operazioni, args=(operazioni,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    print("Saldo finale conto 1:", conto1.saldo)
    print("Saldo finale conto 2:", conto2.saldo)

def esegui_operazioni(operazioni):
    for operazione in operazioni:
        operazione(200)

if __name__ == "__main__":
    main()
