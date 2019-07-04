//Szukamy elementu który jest k-ty w kolejności w drzewie
//"Losowy element drzewa"
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    int elements_in_right_tree;
};

//zakladamy, że jeżeli funkcja random() zwróci 0 to my mamy wypisać element o największej wartości
//numerujemy oczywiście od zera


int find(node* T, int x){
    if(T->elements_in_right_tree == x)   return T->val; //indexowanie od 1
    if(T->elements_in_right_tree<x) return find(T->left,x-T->elements_in_right_tree-1);
    return find(T->right,x);
}

int findRando(node* T)


int main(){

}