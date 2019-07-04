#include <limits.h>

using namespace std;

//topological sort
//zadanie Ciasto
enum color {
    white, grey, black
};
struct ver {
    int size;
    int time_odw = 0;
    int time_wy = 0;
    enum color color = white;
    int neighbour[];
};

//trzeba zrobić dfs i otem wypisać w kolejności time_wy


//zadanie mosty
struct vert {
    int p;//parent
    color color = white;
    int low;
    int val;
    int time;
    int size;
    bool most = false;
    int n[];//neighbour
};

int min(int a, int b){
    if(a<b) return a;
    return b;
}
#define v ver[u].n[i]
void f(vert ver[], int u, int &time) {
    ver[u].color = grey;
    ver[u].time = time;
    ver[u].low = time++;
    for (int i = 0; i < ver[u].size; i++) {
        if (ver[v].color == white) {
            ver[v].p = u;
            f(ver, v, time);
            ver[u].low = min(ver[u].low, ver[v].low);
        }else if(v!=ver[u].p){
            ver[u].low=min(ver[u].low,ver[v].low);
        }
        if(ver[u].time == ver[u].low){ //jezeli nasz czas odwiedzenia jest rowny naszemu low to oznacza, że od nas do parenta jesteśmy mostem
            ver[u].most = true;
        }
        ver[u].color=black;
    }
}

struct vert_pa {
    int p;//parent
    color color = white;
    int low;
    int val;
    int time;
    int size;
    bool pa = false;
    int n[];//neighbour
};
//wyznaczanie punktow artykulacji

void f_pa(vert_pa ver[], int u, int &time) {
    ver[u].color = grey;
    ver[u].time = time;
    ver[u].low = time++;
    for (int i = 0; i < ver[u].size; i++) {
        if (ver[v].color == white) {
            ver[v].p = u;
            f_pa(ver, v, time);
            ver[u].low = min(ver[u].low, ver[v].low);
        }else if(v!=ver[u].p){
            ver[u].low=min(ver[u].low,ver[v].low);
        }
        for(int i=0;i<ver[u].size;i++){
            ver[u].pa=ver[u].pa || (ver[u].p!=v and ver[v].low>ver[u].low); //sprawdzamy czy któryś z naszych sąsiadów ma krawędź prowadzącą ponad nas samych
        }
        ver[u].color=black;
    }
}

//znajdowanie cyklu eulera mając listę krawędzi
//=========================================
//algorytm bellmana-forda


//v-1 razy, na każdej krawędzi robimy relaksację
//releksacja, jeżeli jakąś ścieżką możemy przejść krócej no to ją aktualizujemy na mniejszą

//przechodzimy po każdej krawędzi i sprawdzamy czy możemy zrelaksować
//przechodzimy wszystkie krawędzie v-1 razy, za każdym razem mamy ścieżkę która jest o jeden krok dłuższa i jest pewna

//po przejsciu v-1 razy przechodzimy to jeszcze raz i sprawdzamy czy coś  zrelaksowaliśmy, jeżeli tak, to oznacza, że istnieje cykl ujemny
//wiemy, że po przejściu v-1 razy powinniśmy mieć najoptymalniejszą drogę z punktu startowego do każdego innnego

struct Edge{
    int u,k;//które wierzchołki są połączone
    int w;//waga
};
bool relax(Edge edges[],int i,int dist[i]){
    Edge e=edges[i];
    bool relaxed=false;
    if(dist[e.k]>dist[e.u]+e.w){
        dist[e.w]=dist[e.u]+e.w;
        relaxed=true;
    }
    return relaxed;
}

const int E=100;
bool BF(Edge edges[E],int V,int s){
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    int t=V-1;
    while(t--){
        for(int i=0;i<E;i++){
            relax(edges,i,dist);
        }
    }
    for(int i=0;i<E;i++){
        if(relax(edges,i,dist)) return false;//błąd
    }
    return true;
}

int main() {

}