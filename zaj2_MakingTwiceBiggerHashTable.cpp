#include <iostream>

struct HT {
    int *table;
    int size;
};
//w oryginale nie wolno zmieniać ht oraz funkcja enlarge jest voidowa

int hash(int a) {
    return a ^ 2; //tu powinna byc funckja ktora ladnie hashuje
}

int hash(int a, int proba, HT *ht) {
    return (hash(a) + proba) % ht->size;
}

HT *enlarge(HT *ht) {
    HT *tab = new (HT);
    tab->size = 2 * ht->size;
    tab->table = new(int[tab->size]);
    for (int i = 0; i < tab->size; i++)tab->table[i] = -1;
    for (int i = 0; i < ht->size; i++) {
        if (tab->table[hash(ht->table[i])] < 0 and ht->table[i] > 0) {
            tab->table[hash(ht->table[i])] = ht->table[i];
            ht->table[i] = -1;
        }
    }
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] < 0) continue;
        int b = 0;
        while (tab->table[hash(ht->table[i], b, tab)] >= 0) b++;
        tab->table[hash(ht->table[i], b, tab)] = ht->table[i];
    }

    return tab;
}

/*
 * dana jest tablice. Kolejną większą liczbą .kcby x jest najbliższe (przeglądające kolejne elementy w prawą stronę)
 * większa od niej liczba występująca w tablicy. Jeśli KWL dla x nie istnieje, wypisz -1 dla tego numeru. Należy, założyć,
 * że tablica jest "cykliczna"
 *
 * Mamy stos, odkładamy kolejne elementy (pamiętając ich elementy)
 * pamiętamy cały czas jaki element jest na samym dole
 * odkłądając element sprawdzamy, czy poprzednie elementy nei są mniejsze i odkładany element musi być mniejszy od elementu na samym dole,
 * wtedy ściągamy wszystkie elementy mniejsze od obecnego dopóki nie trafimy na element większy
 * w momencie jak trafimy na coświększego do tego co mamy na samym dole, ściągamy wszystko ze stosu i wypisujemty sprawdzany element tyle razy
 * ile było elementów na stosie
 * indeksy pamiętamy, żeby wiedzieć w jakie miejsce wypisać elementy
 * */



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}