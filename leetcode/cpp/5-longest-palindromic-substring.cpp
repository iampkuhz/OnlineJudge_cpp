/*
 * 求一个字符串的最长回文子串
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string re = "$";
        int sz = s.length();
        for(char c:s)
            re += c + "#";
        vector<int> p(sz,0);
        int mx = -1, id = -1;
        for(int i = 1; i < re.length(); i ++){
            p[i] = mx > i ? min(p[2*id-i], mx-i):1;
            while(re[i-p[i]-1]==re[i+p[i]+1]) p[i]++;
            if(pi[i]+i > mx){
                mx = p[i] + i;
                id = i;
            }
        }
        int mxi = 0, mxl = p[0];
        for(int i = 1; i < re.length(); i ++)
            if(p[i] > mxl){
                mxl = p[i];
                mxi = i;
            }
        return s.substr((mxi-p[i])/2, p[i]);
    }
};

/*
 * 递推式方法,速度慢
 * P[i,j] = 1 if i+1>=j && s[i]==s[j]
 *          1 if s[i] == s[j] && P[i+1][j-1]
 *          0 else
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length();
        int re = 1, rei = 0;
        int P[sz][sz];
        memset(P, 0, sz*sz*sizeof(int));
        for(int i = 0 ; i < sz; i ++){
            for(int j = 0; j <= i; j ++){
                P[j][i] = (s[i] == s[j] && (j+1>=i||P[j+1][i-1])) ? 1: 0;
                if(P[j][i] && i-j+1>re){
                    re = i-j+1;
                    rei = j;
                }
            }
        }
        return s.substr(rei,re);
    }
};


/*
 * dfs,找到一个长度为1或2的就进入查找，最后返回结果
 */
class Solution {
    int re = 0, rei = -1;
    int sz;
    string ss;
public:
    string longestPalindrome(string s) {
        sz = s.length();
        ss = s;
        for(int i = 0 ; i < sz; i ++){
            dfs(i,1);
            if(i> 0 && s[i] == s[i-1])
                dfs(i-1,2);
        }
        return s.substr(rei, re);
    }
    void dfs(int i, int k){
        if(i > 0 && i+k < sz && ss[i-1] == ss[i+k])
            dfs(i-1,k+2);
        else if(k > re){
            re = k;
            rei = i;
        }
    }



/*
 * bfs
 */
class Solution {
public:
    string longestPalindrome(string s) {
        queue<pair<int,int> > qp;
        int sz = s.length();
        for(int i = 0 ; i < sz; i ++){
            qp.push(make_pair(i,1));
            if(i > 0 && s[i] == s[i-1])
                qp.push(make_pair(i-1,2));
        }
        int re = 0, rei = -1;
        while(!qp.empty()){
            auto p = qp.front();
            qp.pop();
            int i = p.first, k = p.second;
            if(k > re){
                re = k;
                rei = i;
            }
            if(i > 0 && i+k-1 < sz-1 && s[i-1] == s[i+k])
                qp.push(make_pair(i-1,k+2));
        }
        return s.substr(rei,re);
    }
};
