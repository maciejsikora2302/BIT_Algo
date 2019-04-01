#include <iostream>

struct node {
    int val;
    node *next;
};


// nie wiadomo jak jest lista posortowana
bool isUP(node *first) {
    int rosnie = 0;
    if (first->val <= first->next->val) {
        rosnie++;
    } else {
        rosnie--;
    }
    first = first->next;
    if (rosnie > 0) return true;
    return false;
}

void insert(node *element_do_wstawienia, node *&first) {

}

//łatwiej jest wykorzystać wersję z isUP() potem trzeba tylko odpowiednio wstawić
node *fixSoretedList(node *&first) {
    bool isUp;
    if (first->val <= first->next->val) isUp = true;
    else isUp = false;
    node *prev = first;
    node *curr = first->next;
    if (isUp) {
        if (prev->val > curr->val) {
            insert(prev, first);
            insert(curr, first);
            insert(curr->next, first);
        }
        prev = prev->next;
        curr = curr->next;
    } else {
        if (prev->val < curr->val) {
            //reszta do dokonczenia
        }
    }

}
