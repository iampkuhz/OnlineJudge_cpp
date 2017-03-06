/*
 * 1次过
 */

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        while(n > 0){
            int t = read4(buf);
            buf += 4;
            if(t > n) t = n;
            sum += t;
            n -= 4;
            if(t < 4) break;
        }
        return sum;
    }
};
