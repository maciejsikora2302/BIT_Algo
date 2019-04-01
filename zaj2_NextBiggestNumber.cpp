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

