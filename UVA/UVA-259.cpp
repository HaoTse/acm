#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int llink[10], rlink[10];
bool used[10];
vector<int> node[10];

bool DFS(int now){
    for(int nxt : node[now]){
        if(!used[nxt]){
            used[nxt] = true;
            if(rlink[nxt] == -1 || DFS(rlink[nxt])){
                rlink[nxt] = now;
                llink[now] = nxt;
                return true;
            }
        }
    }
    return false;
}

int bipartite(int L){
    int ret = 0;
    memset(llink, -1, sizeof(llink));
    memset(rlink, -1, sizeof(rlink));

    for(int i = 0; i < L; i++){
        memset(used, false, sizeof(used));
        if(DFS(i)) ret++;
    }
    return ret;
}

int main(){

    string in;
    char app[10];
    int num = 0;
    bool over = false;

    while(1){
        getline(cin, in);

        if(in != ""){
            string buf = in.substr(3);

            for(int i = 0; i < in[1] - '0'; i++){
                if(num >= 10){
                    over = true;
                    break;
                }
                app[num] = in[0];

                for(char c : buf){
                    if(c == ';') break;
                    node[num].push_back(c - '0');
                }
                num++;
            }
        }
        else{
            if(over)
                puts("!");
            else if(bipartite(num) == num){
                for(int i : rlink){
                    if(i == -1)
                        printf("_");
                    else
                        printf("%c", app[i]);
                }
                printf("\n");
            }
            else
                puts("!");

            if(cin.eof()) break;

            num = 0;
            over = false;
            for(int i = 0; i < 10; i++)
                node[i].clear();
        }
    }

    return 0;
}