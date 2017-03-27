#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string n1, n2;
    int s1 = 0, s2 = 0;
    int i;
    float result = 0.0;

    while(getline(cin, n1) && getline(cin, n2)){

        for(i = 0; i < n1.length(); i++){
            if(isalpha(n1[i]))
                s1 += (n1[i] >= 'a') ? n1[i] - 'a' + 1 : n1[i] - 'A' + 1;
        }
        for(i = 0; i < n2.length(); i++){
            if(isalpha(n2[i]))
                s2 += (n2[i] >= 'a') ? n2[i] - 'a' + 1 : n2[i] - 'A' + 1;
        }
        while(s1 >= 10)
            s1 = s1 / 10 + s1 % 10;
        while(s2 >= 10)
            s2 = s2 / 10 + s2 % 10;

        result = (s1 > s2) ? (float)s2 / (float)s1 * 100 : (float)s1 / (float)s2 * 100;
        printf("%.2f %%\n", result);

        n1 = n2 = "";
        s1 = s2 = 0;
        result = 0.0;
    }

    return 0;

}
