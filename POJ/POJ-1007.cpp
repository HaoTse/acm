#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct IN{
    int n;
    char s[55];
};

int ans = 0;

void combine(char in[], int l, int h){

    char out[h- l + 1];
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

void mergesort(char in[], int l, int h){

    if(h > l){
        mergesort(in, l, (l + h) / 2);
        mergesort(in, ((l + h) / 2) + 1, h);
        combine(in, l, h);
    }
}

bool cmp(const IN a, const IN b){
    return a.n < b.n;
}

int main(){
    int n, m;
    char tmp[55];
    IN in[105];

    scanf("%d %d", &n, &m);

    getchar();
    for(int i = 0; i < m; i++){
        gets(tmp);
        strcpy(in[i].s, tmp);
        mergesort(tmp, 0, n);
        in[i].n = ans;
        ans = 0;
    }

    sort(in, in + m, cmp);

    for(int i = 0; i < m; i++){
        printf("%s\n", in[i].s);
    }

    return 0;
}
