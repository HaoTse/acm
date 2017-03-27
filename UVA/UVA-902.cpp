#include <iostream> //use <cstdio> ans char array is runtime error, I don't know why
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int N;
    string buf;

    while(cin >> N){
        cin.get(); //read the empty
        getline(cin, buf);
        map<string, int> m;

        for(int i = 0; i <= buf.size() - N; i++){
            string tmp;
            tmp = buf.substr(i, N);
            if(!m[tmp]) m[tmp] = 1;
            else m[tmp]++;
        }

        int Max = 0;
        string ans;
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it -> second > Max){
                Max = it -> second;
                ans = it -> first;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
