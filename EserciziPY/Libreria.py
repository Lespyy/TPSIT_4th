import math

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

    def trovaAltezza(self, Kl = 0, Kr = 0):
        if self.sinistro is not None:
            Kl = self.sinistro.trovaAltezza(Kl + 1, Kr)
        if self.destro is not None:
            Kr = self.destro.trovaAltezza(Kl, Kr + 1)
        return max(Kl, Kr)

    def isBilanciato(self):
        return self.trovaAltezza() == int(math.log2(self.ContaNodi()))


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
        
def albero_bilanciato(lista, nodo=None):
    if not lista:
        return None
    centro = len(lista) // 2
    nodo = Node(lista[centro])
    nodo.sinistro = albero_bilanciato(lista[:centro], nodo.sinistro)
    nodo.destro = albero_bilanciato(lista[centro + 1:], nodo.destro)
    return nodo

        

def main():
    lista = [1, 2, 3, 4, 5, 6]
    lista.sort()
    radice = Node(None)
    radiceNonBlinaciata = Node(None)
    albero_bilanciato(lista, radice)
    for element in lista:
        radiceNonBlinaciata.inserisci(element)

    print("\n--------------------------------\n")

    radice.stampa_albero()

    #numero = radice.ContaNodi()
    
    print("\n--------------------------------\n")

    #print(numero)

    if (radice.isBilanciato()):
        print("si")
    else:
        print("no")

    if (radiceNonBlinaciata.isBilanciato()):
        print("si")
    else:
        print("no")


if __name__ == "__main__":
    main()
        
