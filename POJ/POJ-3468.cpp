#include <cstdio>
#include <cstring>

struct NODE{
    int l, r;
    NODE *left, *right;
    long long inc, sum;
};

int in[100003];
NODE node[100003 * 2];
int cnt = 0;
long long ans_sum;

void build(NODE *nd, int l, int r){
    nd -> l = l;
    nd -> r = r;
    if(l == r){
        nd -> inc = 0;
        nd -> sum = in[l];
        return;
    }

    cnt++;
    nd -> left = node + cnt;
    cnt++;
    nd -> right = node + cnt;

    int mid = (l + r) / 2;
    build(nd -> left, l, mid);
    build(nd -> right, mid + 1, r);
    nd -> sum = nd -> left -> sum + nd -> right -> sum;
}

void pushdown(NODE *nd){
    if(nd -> inc){
        nd -> left -> inc += nd -> inc;
        nd -> right -> inc += nd -> inc;
        nd -> left -> sum += (nd -> left -> r - nd -> left -> l + 1) * nd -> inc;
		nd -> right -> sum += (nd -> right -> r - nd -> right -> l + 1) * nd -> inc;
		nd -> inc = 0;
    }
}

void query(NODE *nd, int l, int r){
    if(nd -> l == l && nd -> r == r){
        ans_sum += nd -> sum;
        return;
    }

    pushdown(nd);

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

void update(NODE *nd, int l, int r, long long v){
    if(nd -> l == l && nd -> r == r){
        nd -> inc += v;
        nd -> sum += (nd -> r - nd -> l + 1) * v;
        return;
    }

    pushdown(nd);

    int mid = (nd -> l + nd -> r) / 2;
	if(r <= mid)
		update(nd -> left, l, r, v);
	else if(l > mid)
		update(nd -> right, l, r, v);
	else{
		update(nd -> left, l, mid, v);
		update(nd -> right, mid + 1, r, v);
	}

	nd -> sum = nd -> left -> sum + nd -> right -> sum;
}

int main(){
    int N, Q, a, b, c;
    char type;

    while(scanf("%d %d", &N, &Q) != EOF){
        for(int i = 1; i <= N; i++){
            scanf("%d", &in[i]);
        }
        memset(node, 0, sizeof(node));
        build(node, 1, N);

        while(Q--){
            scanf(" %c", &type);
            if(type == 'Q'){
                scanf("%d %d", &a, &b);
                ans_sum = 0;
                query(node, a, b);
                printf("%lld\n", ans_sum);
            }
            else{
                scanf("%d %d %d", &a, &b, &c);
                update(node, a, b, c);
            }
        }
    }

    return 0;
}
