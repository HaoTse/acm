#include <cstdio>

using namespace std;

int main(){
    int h, m;
    float h_a, m_a;

    while(scanf("%d:%d", &h, &m)){

        if(h == 0 && m == 0)
            break;

        h_a = 30 * h + 0.5 * m;
        m_a = 6 * m;

        if(h_a > m_a)
            printf("%.3f\n", (h_a - m_a < 180) ? h_a - m_a : 360 - h_a + m_a);
        else
            printf("%.3f\n", (m_a - h_a < 180) ? m_a - h_a : 360 - m_a + h_a);
    }

    return 0;
}
