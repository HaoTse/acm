#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
    string tmp;
    char buf[30];
    map<string, bool> m;

    while(scanf("%s", buf) != EOF){
        m[tmp.assign(buf)] = true;
    }

    for(map<string, bool>::iterator it = m.begin(); it != m.end(); ++it){
        if(!it->second)
            continue;
        for(int i = 0; i < it->first.size(); i++){
            string tmp1, tmp2;
            tmp1 = it->first.substr(0, i + 1);
            if(!m[tmp1])
                continue;
            tmp2 = it->first.substr(i + 1);
            if(!m[tmp2])
                continue;
            printf("%s\n", it->first.c_str());
            break;
        }
    }

    return 0;
}
