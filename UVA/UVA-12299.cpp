#include <cstdio>
#include <cstring>
#include <cctype>

#define MAXN 100003
#define INF 0x3f3f3f3f

using namespace std;

int in[MAXN] = {0}, num[MAXN] = {0}, tmp[MAXN] = {0};
int ans;

struct NODE{
    int l, r;
    NODE *left, *right;
    int Min;
}node[MAXN * 2];

int Nodecnt = 0;
void build(NODE *nd, int l, int r){
    nd -> l = l;
    nd -> r = r;
    if(l == r){
        nd -> Min = in[l];
        return ;
    }

    Nodecnt++;
    nd -> left = node + Nodecnt;
    Nodecnt++;
    nd -> right = node + Nodecnt;

    int mid = (l + r) / 2;
    build(nd -> left, l, mid);
    build(nd -> right, mid + 1, r);

    nd -> Min = (nd -> left -> Min < nd -> right -> Min) ? nd -> left -> Min : nd -> right -> Min;
}

void query(NODE *nd, int l, int r){
    if(nd -> l == l && nd -> r == r){
        ans = (ans < nd -> Min) ? ans : nd -> Min;
        return ;
    }

    int mid = (nd -> l + nd -> r) / 2;
    if(r <= mid)
        query(nd -> left, l, r);
    else if(l > mid)
        query(nd -> right, l, r);
    else{
        query(nd -> left, l, mid);
        query(nd -> right, mid + 1, r);
    }
}

void update(NODE *nd, int x, int v){
    if(nd -> l == nd -> r){
        in[nd -> l] = nd -> Min = v;
        return ;
    }

    int mid = (nd -> l + nd -> r) / 2;
    if(x <= mid)
        update(nd -> left, x, v);
    else
        update(nd -> right, x, v);

    nd -> Min = (nd -> left -> Min < nd -> right -> Min) ? nd -> left -> Min : nd -> right -> Min;

}

int main(){
    int n, q;

    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &in[i]);
    }
    build(node, 1, n);

    getchar();
    while(q--){
        char buf[100];
        gets(buf);
        int cnt = 0;
        num[0] = 0;
        for(int i = 6; i < strlen(buf); i++){
            if(isdigit(buf[i]))
                num[cnt] = num[cnt] * 10 + buf[i] - '0';
            else
                num[++cnt] = 0;
        }

        if(buf[0] == 'q'){
            ans = INF;
            query(node, num[0], num[1]);
            printf("%d\n", ans);
        }
        else{
            for(int i = 0; i < cnt; i++){
                tmp[i] = in[num[i]];
            }
            for(int i = 0; i < cnt; i++){
                update(node, num[i], tmp[(i + 1) % cnt]);
            }
        }

    }
    return 0;
}
