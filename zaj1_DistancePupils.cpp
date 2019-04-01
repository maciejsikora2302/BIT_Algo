#include <iostream>

/*
 * dzieci z dwiema koszulkami
 * dystans ich pokonany to
 * każdy przed połową musi pokonać odległość do połowy, ale ta sama odległość zostanie pokonana dwa razy
 * daje nam to algorytm, że liczymy ile osób przed połową znajduje się nie na swoim miejscu i liczymy ich odległość do połowy
 * mnożymy ją dwa razy i powtarzamy tą samą operacje dla drugiej połowy uwzględniając drugą grupe
 * */

struct pupil {
    int group;
    pupil *next;
};

int len(pupil *p) {} //funkcja zwracająca długość listy

int distance(pupil *p) {
    int n = len(p);
    int t = 0;
    int sum = 0;
    while (t != n / 2) {
        if (p->group == 1) {
            sum += n / 2 - t;
        }
        p = p->next;
        t++;
    }
    while (t != n) {
        if (p->group == 0) {
            sum += t - n / 2;
            p = p->next;
            t++;
        }
    }
}