#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

#define MAXN 10003

using namespace std;

struct Poster{
    int l, r;
}post[MAXN];

struct NODE{
    int l, r;
    bool isCovered;
    NODE *left, *right;
}node[MAXN * 8];
//because use discrete and to avoid the state in ppt, so the size is MAXN * 4; and use swgment tree so the size of node is MAXN * 8

bool ans_flag = false;
vector<int> bound;
map<int, int> m;

int Nodecnt = 0;
void build(NODE *nd, int l, int r){
    nd -> l = l;
    nd -> r = r;
    nd -> isCovered = false;
    if(l == r) return;

    Nodecnt++;
    nd -> left = node + Nodecnt;
    Nodecnt++;
    nd -> right = node + Nodecnt;

    int mid = (l + r) / 2;
    build(nd -> left, l, mid);
    build(nd -> right, mid + 1, r);
}

void query(NODE *nd, int l, int r){
    if(nd -> isCovered) return;

    if(nd -> l == l && nd -> r == r){
        nd -> isCovered = true;
        ans_flag = true;
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

    if(nd -> left -> isCovered && nd -> right -> isCovered)
        nd -> isCovered = true;
}

int main(){
    int Case, n;

    scanf("%d", &Case);
    while(Case--){
        bound.clear();
        m.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &post[i].l, &post[i].r);
            bound.push_back(post[i].l);
            bound.push_back(post[i].r);
        }
        sort(bound.begin(), bound.end());
        bound.erase(unique(bound.begin(), bound.end()), bound.end()); //erase the repeated elements

        //make the input discretization
        int nInterval = 1;
        m[bound[0]] = nInterval;
        for(int i = 1; i < bound.size(); i++){
            if(bound[i] - bound[i - 1] == 1)
                nInterval += 1;
            else
                nInterval += 2;
            m[bound[i]] = nInterval;
        }

        Nodecnt = 0; //init the count of node
        build(node, 1, nInterval);

        int ans = 0;
        //iterator the input poster from back to front
        for(int i = n - 1; i >= 0; i--){
            ans_flag = false;
            query(node, m[post[i].l], m[post[i].r]);
            if(ans_flag) ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
