#include <cstdio>

int num = 0;
long long ans = 0;

void combine(int in[], int l, int h){

    int out[h- l + 1];
    int i, j, cur = 0;
    int mid = (l + h) / 2;

    for(i = l, j = mid + 1; i <= mid || j <= h;){
        if(i > mid)
            out[cur++] = in[j++];
        else if(j > h)
            out[cur++] = in[i++];
        else if(in[i] > in[j]){
            out[cur++] = in[j++];
            ans += (mid - i + 1);
        }
        else
            out[cur++] = in[i++];
    }

    for(cur = 0, i = l; i <= h; i++, cur++)
        in[i] = out[cur];
}

void mergesort(int in[], int l, int h){

    if(h > l){
        mergesort(in, l, (l + h) / 2);
        mergesort(in, ((l + h) / 2) + 1, h);
        combine(in, l, h);
    }
}

int main(){

    while(scanf("%d", &num)){
        if(num == 0)
            break;

        int in[num];
        ans = 0;

        for(int i = 0; i < num; i++){
            scanf("%d", &in[i]);
        }
        mergesort(in, 0, num - 1);

        printf("%lld\n", ans);
    }
    return 0;
}
