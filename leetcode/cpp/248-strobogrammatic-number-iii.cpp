/*
 * 看答案
 * 1. 遍历一遍所有的s数，每一个都判断是否在区间内
 * 2. math
 *
 */

class Solution {
    vector<long> sNum = {1, 3, 5, 15, 25};
    vector<long> sNumClean = {0, 1,3,4,12};
    vector<long> contTen = {1,2,2,2,2,2,2,2,3,3,3};
    vector<int> oppo = {0,1,-1,-1,-1,-1,9,-1,8,6};
    vector<vector<char> > p = {{'1','1'},{'8','8'},{'6','9'},{'9','6'},{'0','0'}};
public:
    int strobogrammaticInRange(string low, string high) {
        int szh = high.size();
        getsNum(szh);
        if(!myLE(low, high)) return 0;
        long cnt1 = countS(high, false), cnt2 = countS(low,false) - isS(low);
        return cnt1 - cnt2;
    }
    long countS(string snum, bool leadZero){
        int szs = snum.size();
        if(szs < 1) return 1;
        long re = 0;
        for(int i = 0 ; i < re; i ++)
            re += sNumClean[i];
        if(szs == 1) return cntLE(snum[0]-'0', 1);
        else if(szs == 2) return cntLE((snum[0]-'0')*10 + snum[1]-'0', 2);
        char c = snum[0];
        int v1 = snum[0] -'0', v2 = snum[szs-1] -'0';
        if(v1 > 0){
            int mult = cntLE(v1*10, 2);
            if(!leadZero) mult --;
            re += mult * sNum[szs-2];
        }
        if(oppo[v1] >= 0) re += countS(snum.substr(1,szs-2), true);
        if(v2 < oppo[v1] && isS(snum.substr(1,szs-2))) re --;
        return re;
    }

    int cntLE(int v, int digitNr){
        if(digitNr == 1){
            return v==0? 1: (v>=8? 3:2);
        }else{
            return v<11? 0: (v<69? 1:(v<88? 2:(v<96? 3:4)));
        }
    }

    bool isS(string & str){
        int len = str.length();
        for(int i = 0 ; i < len/2 +1; i ++){
            bool iss = false;
            for(int j = 0 ; j < 5; j ++)
                if(str[i] == p[j][0] && str[len-1-i] == p[j][1]){
                    iss = true;
                    break;
                }
            if(!iss) return false;
        }
        return true;
    }

    bool myLE(string & a, string b){
        int sa = a.length(), sb = b.length();
        if(sa != sb) return sa < sb;
        for(int i = 0 ; i < sa; i ++)
            if(a[i] != b[i]) return a[i] < b[i];
        return true;
    }
    void getsNum(int num){
        num -= 5;
        int k = 3;
        while(num > 0){
            sNum.push_back(5*sNum[k++]);
            sNumClean.push_back(5*sNumClean[k]);
            num --;
        }
    }
};

class Solution {
    int cnt = 0;
    bool myLE(string a, string b){
        int sa = a.length(), sb = b.length();
        if(sa != sb) return sa < sb;
        for(int i = 0 ; i < sa; i ++)
            if(a[i] != b[i]) return a[i] < b[i];
        return true;
    }
    string l, h;
    int szl, szh;
public:
    int strobogrammaticInRange(string low, string high) {
        if(!myLE(low, high)) return 0;
        vector<vector<char> > p = {{'1','1'},{'8','8'},{'6','9'},{'9','6'},{'0','0'}};
        cnt = 0;
        l = low;
        h = high;
        szl = low.length();
        szh = high.length();
        dfs("", p);
        dfs("1", p);
        dfs("8", p);
        dfs("0", p);
        return cnt;
    }
    void dfs(string t, vector<vector<char> >&  p){
        if(t.length() > szh) return;
        if(t.length() == 1 || (t.length() > 1 && t[0] != '0'))
            if(myLE(l, t) && myLE(t, h))
                cnt ++;
        for(int i = 0 ; i < 5; i ++)
            dfs(p[i][0] + t + p[i][1], p);
    }
};

/*
 * 理解错了：
 * 计算low位到high位的strobogrammatic-number数的数量
 */

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        // 0,3,4,12,20,60,100,30,...
        int re = 0, v0 = 4, v1 = 12, i = 2;
        if(low < 2){
            if(low <= 1 && high >= 1) re += 3;
            low = 2;
        }
        while(i<=high){
            if(i >= low) re += v0;
            if(i+1 >= low && i+1 <=high) re += v1;
            v1 *= 5;
            v0 *= 5;
            i += 2;
        }
        return re;
    }
};
