#include <cstdio>

#define N 100

struct POINT{
    int x, y;
}a1, a2, b1, b2;

int main(){
    int Case;

    scanf("%d", &Case);
    for(int c = 1; c <= Case; c++){
        scanf("%d %d %d %d", &a1.x, &a1.y, &a2.x, &a2.y);
        scanf("%d %d %d %d", &b1.x, &b1.y, &b2.x, &b2.y);
        int max_xtmp, max_ytmp, min_xtmp, min_ytmp;
        max_xtmp = (a1.x > b1.x) ? a1.x : b1.x;
        max_ytmp = (a1.y > b1.y) ? a1.y : b1.y;
        min_xtmp = (a2.x < b2.x) ? a2.x : b2.x;
        min_ytmp = (a2.y < b2.y) ? a2.y : b2.y;
        int ansA, ansB, ansC;
        ansA = (a2.x - a1.x) * (a2.y - a1.y);
        ansB = (b2.x - b1.x) * (b2.y - b1.y);
        ansC = (min_xtmp - max_xtmp) * (min_ytmp - max_ytmp);
        int tmp = ansA + ansB;

        printf("Night %d: ", c);
        if(max_xtmp >= min_xtmp || max_ytmp >= min_ytmp)
            printf("0 %d %d\n", tmp, N * N - tmp);
        else
            printf("%d %d %d\n", ansC, tmp - 2 * ansC, N * N - tmp + ansC);

    }

    return 0;
}
