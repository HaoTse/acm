#include <cstdio>
#include <algorithm>

using namespace std;

struct input{
    int time;
    int fine;
    int order;
    double cost;
};

bool cmp(input a, input b){
    return a.cost > b.cost;
}

int main(){
    int num, n;

    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        scanf("");
        scanf("%d", &n);

        input in[n];
        for(int j = 0; j < n; j++){
            scanf("%d %d", &in[j].time, &in[j].fine);
            in[j].order = j + 1;
            in[j].cost = in[j].fine * 1.0 / in[j].time;
        }

        sort(in, in + n, cmp);

        for(int k = 0; k < n; k++){
            if(k != n - 1)
                printf("%d ", in[k].order);
            else
                printf("%d", in[k].order);
        }
        printf("\n");

        if(i != num -1)
            printf("\n");
    }

    return 0;
}
