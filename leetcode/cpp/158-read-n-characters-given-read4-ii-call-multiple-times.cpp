/**
 * 看答案，之前的思路错了，
 * 题目的意思i是：连续读一些内容，放到buf内，比如读‘1234’，先读n=1,buf内容为`1`,在读n=2,buf内容为`23`
 *The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

*/


// Forward declaration of the read4 API.

/*
 */
int read4(char *buf);

class Solution {
public:
    int i4 = 0, n4 = 0;
    char buf4[4];
    int read(char *buf, int n) {
        int i = 0;
        while(i < n){
            if(i4 >= n4){
                i4 = 0;
                n4 = read4(buf4);
                if(n4 == 0) break;
            }
            buf[i++] = buf4[i4++];
        }
        return i;
    }
};

/*
 *
 *
 * 错误答案
 */
class Solution {
    unordered_map<char *, int> b2n;// 记录之前访问的最大值
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0, left = n;
        if(b2n.find(buf) != b2n.end()){
            int maxt = b2n[buf];
            if(maxt >= n) return n;
            sum = maxt;
            n -= maxt;
            buf += maxt;
        }
        while(n > 0){
            int tr = read4(buf);
            if(tr >= n || tr < 4){
                sum += tr > n ? n : tr;
                buf += tr > n ? n : tr;
                break;
            }
            sum += 4;
            buf += 4;
            n -= 4;
        }
        b2n[buf-sum] = sum;
        return sum;
    }
};
