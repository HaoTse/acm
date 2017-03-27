#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;

struct NODE{
    int l, r;
    int Min, Max;
    NODE *left, *right;
};

NODE node[50003 * 2];
int in[50003] = {0};
int cnt = 0, ans_max, ans_min;

void build(NODE *nd, int l, int r){
    nd -> l = l;
    nd -> r = r;
    if(l == r){
        nd -> Max = nd -> Min = in[l];
        return;
    }

    cnt++;
    nd -> left = node + cnt;
    cnt++;
    nd -> right = node + cnt;

    int mid = (l + r) / 2;
    build(nd -> left, l, mid);
    build(nd -> right, mid + 1, r);
    nd -> Max = (nd -> left -> Max > nd -> right -> Max) ? nd -> left -> Max : nd -> right -> Max;
    nd -> Min = (nd -> left -> Min < nd -> right -> Min) ? nd -> left -> Min : nd -> right -> Min;
}

void query(NODE *nd, int l, int r){
    if(nd -> l == l && nd -> r == r){
        ans_max = (ans_max > nd -> Max) ? ans_max : nd -> Max;
        ans_min = (ans_min < nd -> Min) ? ans_min : nd -> Min;
        return;
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

int main(){
    int N, Q, a, b;

    memset(node, 0, sizeof(node));
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &in[i]);
    }
    build(node, 1, N);

    while(Q--){
        scanf("%d %d", &a, &b);
        ans_max = 0, ans_min = INF;
		query(node, a, b);
		printf("%d\n", ans_max - ans_min);
    }

    return 0;
}
