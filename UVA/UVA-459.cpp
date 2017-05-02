#include <cstdio>
#include <cstring>

using namespace std;

int p[30];
bool visited[30];

void init(int n){
    for(int i = 0; i <= n; i++){
        p[i] = i;
        visited[i] = false;
    }
}

int Find(int x){
    return (p[x] == x) ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y) {
    p[Find(x)] = Find(y);
}

int main(){
    int Case;
    int size;
    char buf[10];

    scanf("%d", &Case);
    int tmp = Case;
    while(tmp--){
        scanf("%s", buf);
        size = buf[0] - 'A';
        init(size);
        getchar();

        while(gets(buf) && strcmp(buf, "")){
            int x = buf[0] - 'A', y;
            y = buf[1] - 'A';
            Union(x, y);
        }

        int ans = 0;
        for(int i = 0; i <= size; i++){
            if(!visited[Find(i)]){
                ans++;
            }
            visited[Find(i)] = true;
        }

        if(tmp != Case - 1) puts("");
        printf("%d\n", ans);
    }

    return 0;
}
