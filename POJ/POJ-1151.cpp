#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

#define MAXN 103

using namespace std;

struct NODE{
    int l, r;
    NODE *left, *right;
    double len;
    int covers;
}node[MAXN * 4];

struct Line{
    double x, y1, y2;
    bool isLeft;
};

vector<Line> line;
vector<double> yList;
map<double, int> m;

int Nodecnt = 0;
void build(NODE *nd, int l, int r){
    nd -> l = l;
    nd -> r = r;
    nd -> len = 0;
    nd -> covers = 0;

    if(l == r) return ;

    Nodecnt++;
    nd -> left = node + Nodecnt;
    Nodecnt++;
    nd -> right = node + Nodecnt;

    int mid = (l + r) / 2;
    build(nd -> left, l, mid);
    build(nd -> right, mid + 1, r);
}

void enter(NODE *nd, int l, int r){
    if(nd -> l == l && nd -> r == r){
        nd -> len = yList[r] - yList[l - 1]; //because yLisr[0] = nInterval[1]; r + 1 is initial r, r + 1 - 1 = r; l -> l - 1
        nd -> covers++;
        return ;
    }

    int mid = (nd -> l + nd -> r) / 2;
    if(r <= mid)
        enter(nd -> left, l, r);
    else if(l > mid)
        enter(nd -> right, l, r);
    else{
        enter(nd -> left, l, mid);
        enter(nd -> right, mid + 1, r);
    }

    if(nd -> covers == 0)
        nd -> len = nd -> left -> len + nd -> right -> len;
}

void leave(NODE *nd, int l, int r){
    if(nd -> l == l && nd -> r == r){
        nd -> covers--;
        if(nd -> covers == 0)
            nd -> len = (l == r) ? 0 : nd -> left -> len + nd -> right -> len;
        return ;
    }

    int mid = (nd -> l + nd -> r) / 2;
    if(r <= mid)
        leave(nd -> left, l, r);
    else if(l > mid)
        leave(nd -> right, l, r);
    else{
        leave(nd -> left, l, mid);
        leave(nd -> right, mid + 1, r);
    }

    if(nd -> covers == 0)
        nd -> len = nd -> left -> len + nd -> right -> len;
}

bool cmp(Line a, Line b){
    return a.x < b.x;
}

int main(){
    int n, Case = 1;
    double x1, x2, y1, y2;

    while(scanf("%d", &n)){
        if(n == 0) break;

        line.clear();
        yList.clear();
        m.clear();
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            yList.push_back(y1);
            yList.push_back(y2);
            Line tmp;
            tmp.x = x1;
            tmp.y1 = y1;
            tmp.y2 = y2;
            tmp.isLeft = true;
            line.push_back(tmp);
            tmp.x = x2;
            tmp.isLeft = false;
            line.push_back(tmp);
        }

        //discrete
        sort(yList.begin(), yList.end());
        yList.erase(unique(yList.begin(), yList.end()), yList.end());
        Nodecnt = 0;
        build(node, 1, yList.size() - 1);
        int nInterval = 1;
        for(int i = 0; i < yList.size(); i++){
            m[yList[i]] = nInterval++;
        }

        sort(line.begin(), line.end(), cmp);
        double ans = 0.0;
        for(int i = 0; i < line.size() - 1; i++){
            int l = m[line[i].y1];
            int r = m[line[i].y2];
            if(line[i].isLeft) enter(node, l, r - 1); //need r - 1; for example, nInterval of l and r is 1 and 2, but the interval in segement tree of them is 1
            else leave(node, l, r - 1);

            ans += node[0].len * (line[i + 1].x - line[i].x);
        }

        printf("Test case #%d\n", Case++);
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}
