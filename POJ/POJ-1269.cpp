#include <cstdio>

struct POINT{
    int x, y;
};

struct LINE{
    POINT a, b;
}L1, L2;

int main(){
    int Case;

    scanf("%d", &Case);
    puts("INTERSECTING LINES OUTPUT");
    while(Case--){
        scanf("%d %d %d %d", &L1.a.x, &L1.a.y, &L1.b.x, &L1.b.y);
        scanf("%d %d %d %d", &L2.a.x, &L2.a.y, &L2.b.x, &L2.b.y);
        int L1_y = L1.a.y - L1.b.y, L1_x = L1.b.x - L1.a.x, L2_y = L2.a.y - L2.b.y, L2_x = L2.b.x - L2.a.x;
        int tmp1 = L1_y * L1.a.x + L1_x * L1.a.y, tmp2 = L2_y * L2.a.x + L2_x * L2.a.y;
        int delta = L1_y * L2_x - L2_y * L1_x, deltax = tmp1 * L2_x - tmp2 * L1_x, deltay = tmp2 * L1_y - tmp1 * L2_y;
        if(delta)
            printf("POINT %.2f %.2f\n", (double) deltax/delta, (double) deltay/delta);
        else if(deltax || deltay)
            puts("NONE");
        else
            puts("LINE");

    }
    puts("END OF OUTPUT");
    return 0;
}
