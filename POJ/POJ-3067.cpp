#include <cstdio>
#include <algorithm>

using namespace std;

struct way{
    int east;
    int west;
};

long long ans = 0;

bool cmp(way a, way b){
    if(a.east == b.east)
        return a.west < b.west;
    return a.east < b.east;
}

void combine(way in[], int l, int h){

    int out[h - l + 1];
    int i, j, cur = 0;
    int mid = (l + h) / 2;

    for(i = l, j = mid + 1; i <= mid || j <= h;){
        if(i > mid)
            out[cur++] = in[j++].west;
        else if(j > h)
            out[cur++] = in[i++].west;
        else if(in[i].west > in[j].west){
            out[cur++] = in[j++].west;
            ans += (mid - i + 1);
        }
        else
            out[cur++] = in[i++].west;
    }

    for(cur = 0, i = l; i <= h; i++, cur++)
        in[i].west = out[cur];
}

void mergesort(way in[], int l, int h){

    if(h > l){
        mergesort(in, l, (l + h) / 2);
        mergesort(in, ((l + h) / 2) + 1, h);
        combine(in, l, h);
    }
}

int main(){
    int Case;
    int N, M, K;

    scanf("%d", &Case);
    for(int i = 1; i <= Case; i++){
        ans = 0;
        scanf("%d %d %d", &N, &M, &K);
        way in[K];
        for(int j =  0; j < K; j++){
            scanf("%d %d", &in[j].east, &in[j].west);
        }
        sort(in, in + K, cmp);
        mergesort(in, 0, K - 1);

        printf("Test case %d: %lld\n", i, ans);
    }

    return 0;
}
