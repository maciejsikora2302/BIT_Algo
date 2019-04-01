
/*
 * zadanie drugie opierało sięna pamięci cache
 * trzymaliśmy ostatnie n elementów
 * chcieliśmy, abyśmy mieli liniowy dostęp do elementów w cachu
 * polegało to na tym, że mamy w hash table n ostatnich elementów i w kolejce pamiętamy jaka była ich kolejność
 * dodając nowy element, sprawdzamy czy jest w hash table, jeżeli jest to musimy odpowiednio przesunąć kolejkę tak aby element dodawany był najnowszym
 * problem jest gdy mamy usunąć element który jest gdzieś w środku kolejki
 * dlatego musimy posiadaćwskaźniki dwukierunkowe od hash table do każdego elementu w kolejce
 * i to działa
 * */
