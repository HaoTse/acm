#include <cstdio>

int main(){
    int Ca, Cb, N, cura = 0, curb = 0;

    while(scanf("%d %d %d", &Ca, &Cb, &N) != EOF){
        cura = curb = 0;
        while(1){
            if(curb == N){
                printf("success\n");
                break;
            }
            else if(cura == Ca){
                printf("empty A\n");
                cura = 0;
            }
            else if(curb == 0){
                printf("fill B\n");
                curb = Cb;
            }
            else{
                printf("pour B A\n");
                int tmpa = cura, tmpb = curb;
                curb = ((tmpa + tmpb) <= Ca) ? 0 : (tmpa + tmpb - Ca);
                cura = ((tmpa + tmpb) <= Ca) ? (tmpa + tmpb) : Ca;
            }
        }
    }
    return 0;
}
