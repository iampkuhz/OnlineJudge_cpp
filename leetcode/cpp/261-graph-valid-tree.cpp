/*
 *
 * 1次过！！
 * 判断一些边组成的是否是一颗树
 * 并查集：新的边的两个端点是否在一个集合上？
 */

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int sz = edges.size();
        if(sz != n-1) return false;
        vector<int> inC(n, 0);
        iota(inC.begin(), inC.end(), 0);
        for(int i = 0 ;  i < sz; i ++){
            int ac = findU(edges[i].first, inC), bc = findU(edges[i].second, inC);
            if(ac == bc) return false;
            inC[ac] = bc;
        }
        return true;

    }
    int findU(int x, vector<int> & inC){
        while(inC[x] != x)
            x = inC[x] = inC[inC[x]];
        return x;
    }
};
