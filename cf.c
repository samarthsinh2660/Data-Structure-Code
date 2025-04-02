#include<stdio.h>

#include <stdio.h>

int main() {
    int np;
    scanf("%d", &np);
    int count = 0;

    for (int i = 0; i < np; i++) {
        int p, v, t;
        scanf("%d %d %d", &p, &v, &t);

        if (p + v + t >= 2) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
