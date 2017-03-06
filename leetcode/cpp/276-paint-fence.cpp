/*
 * n个围栏，每个有k种颜色，问一共多少种涂法，连续的3个篱笆不同色
 * a(n)=(k-1)*a(n-1)+(k-1)*a(n-2)
 */

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        int an = k*k, an1 = k, an2;
        while((n--) > 2){
            an2 = an1;
            an1 = an;
            an = (k-1) * (an2 + an1);
        }
        return an;
    }
};
