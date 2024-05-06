"""
Alberi di ricerca binari:

    un grafo in cui io non posso fare percorsi chiusi allora è un albero

        ogni può avere dagli 0 ai 2 nodi figli

    è binario fino al momento in cui i figli di ogni nodo vadano da 0 a 2

        per diventare un albero di RICERCA ogni non deve avere un valore numerico univoco

    e infine se è il figlio destro DEVE avere un valore maggiore se è quello sinistro deve avere un valore minore

        o come ci gira

    e poi quelli a destra 

    gli ultimi figli sono le foglie

        letteralmente

    tutti i nodi hanno un nodo padre meno che la radice

    ogni nodo ha una chiave univoca

    ogni sotto albero sinistro ha un valore inferiore del padre

    un albero ha due proprietà

        il fatto se è bilanciato o no

            se un albero ha N nodi con altezza h

            è bilanciato se l'altezza è uguale al int(log base 2 di N)

            e gli alberi bilanciati sono quelli di altezza minima

        o altezza (h)

            il numero di cplegamenti tra la radice e la foglia più profonda



"""
class Node():

    def __init__(self, valore):
        self.valore = valore
        self.sinistro = None
        self.destro = None

    def inserisci(self, valore):
        if self.valore is not None:
            #capire se insrire valore in figlio sinistro o destro
            #se non ha un figlio allora assegnamo un nuovo nodo
            #se ha un figlio applico la ricorsione sul nodo successivo
            pass
            #if sx 
                #if sx == none
                    #new nodo
                #else
                    #ricorsione
            #else
                #if dx == none
                    #new nodo
                #else
                    #ricorsione
        
            if valore < self.valore:
                if self.sinistro == None:
                    self.sinistro = Node(valore)
                else:
                    self.sinistro.inserisci(valore)
            
            elif valore > self.valore:
                if self.destro == None:
                    self.destro = Node(valore)
                else:
                    self.destro.inserisci(valore)
        else:
            self.valore = valore
    
    def stampa_albero(self, lvl = 0):            
        if self.destro is not None:
            self.destro.stampa_albero(lvl + 1)
        print("  " * lvl + str(self.valore))
        if self.sinistro is not None:
            self.sinistro.stampa_albero(lvl + 1)
            
    

    def trova(self, valore):
        if valore == self.valore:
            return self
        elif valore < self.valore and self.sinistro is not None:
            return self.sinistro.trova(valore)
        elif valore > self.valore and self.destro is not None:
            return self.destro.trova(valore)
        else:
            return None
        
    def ContaNodi(self, numero = 1):

        if self.destro is not None:
            numero = self.destro.ContaNodi(numero + 1)
        if self.sinistro is not None: 
            numero = self.sinistro.ContaNodi(numero + 1)
        
        return numero

def albero_bilanciato(lista, n):
        
        centro = len(lista) // 2
        print(lista)
        n.inserisci(lista[centro])
        if centro != 0:
            listaSx = lista[0: centro]
            listaDx = lista[centro + 1:]
            if len(listaSx) > 0:
                albero_bilanciato(listaSx, n)
            if len(listaDx) > 0:
                albero_bilanciato(listaDx, n)
        
        else:
            return None

"""fai un afunzione che ritorna se l'albero è bilanciato"""
"""
def main():

    n = Node(None)    

    n.stampa_albero()
    n.inserisci(4)

    print("\n--------------------------------\n")

    n.stampa_albero()
    n.inserisci(3)

    print("\n--------------------------------\n")

    n.stampa_albero()
    n.inserisci(2)

    print("\n--------------------------------\n")

    n.stampa_albero()
    n.inserisci(6)

    print("\n--------------------------------\n")

    n.stampa_albero()
    n.inserisci(7)

    print("\n--------------------------------\n")

    n.stampa_albero()

    # Esempio di utilizzo della funzione trova
    nodo_trovato = n.trova(10)
    if nodo_trovato:
        print("\n\nNodo trovato con valore:", nodo_trovato.valore)
    else:
        print("\n\nNodo non trovato.")

    nodo_trovato = n.trova(6)
    if nodo_trovato:
        print("\n\nNodo trovato con valore:", nodo_trovato.valore)
    else:
        print("\n\nNodo non trovato.")

    nodo_trovato = n.trova(2)
    if nodo_trovato:
        print("\n\nNodo trovato con valore:", nodo_trovato.valore)
    else:
        print("\n\nNodo non trovato.")
"""
def main():
    lista = [1, 2, 3, 4, 5, 6]
    lista.sort()
    radice = Node(None)
    albero_bilanciato(lista, radice)

    print("\n--------------------------------\n")

    radice.stampa_albero()

    numero = radice.ContaNodi()
    
    print("\n--------------------------------\n")

    print(numero)


if __name__ == "__main__":
    main()