#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string cur;

    while(getline(cin, cur)){
        if(cur == "ENDOFINPUT")
            break;

        if(cur == "START")
            continue;
        if(cur == "END"){
            printf("\n");
            continue;
        }

        for(int i = 0; i < cur.length(); i++){
            if(isupper(cur[i]))
                cur[i] = (cur[i] <= 'E') ? cur[i] + 21 : cur[i] - 5;
        }
        printf("%s", cur.c_str());
    }

    return 0;
}
