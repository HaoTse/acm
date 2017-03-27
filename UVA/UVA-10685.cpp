#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<string, string> m;

string Find(string a){
    return (m[a] == a) ? a : (m[a] = Find(m[a]));
}

void Union(string a, string b){
    m[Find(a)] = Find(b);
}

int main(){
    int c, r;
    char buf[35], buf1[35];
    map<string, int> cnt;

    while(scanf("%d %d", &c, &r)){
        if(c == 0 && r == 0)
            break;

        m.clear();
        cnt.clear();
        while(c--){
            scanf("%s", buf);
            m[buf] = buf;
        }

        while(r--){
            scanf("%s %s", buf, buf1);
            Union(buf, buf1);
        }

        int ans = 0;
        for(map<string, string>::iterator it = m.begin(); it != m.end(); it++){
            cnt[Find(it->second)]++;
        }
        for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans = (ans > it->second) ? ans : it ->second;
        }
        printf("%d\n", ans);
    }
    return 0;
}
