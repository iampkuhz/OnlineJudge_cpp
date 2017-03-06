/*
 * 看题意就是使用并查集
 * 不知道怎么表示4个方向，看了答案：https://leetcode.com/discuss/78856/c-union-find-solution-with-path-compression
 * 表示4个方向：看成4次：每次处理一个方向。每处理一个方向fp需要更新！
 *A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> re;
        vector<int> idx(m*n, -1);

        int sz = positions.size();
        if(sz < 1)return re;
        int cnt = 0;
        vector<pair<int, int> > dir = {{0,1},{0,-1},{-1,0},{1,0}};
        for(int i = 0 ;  i < sz; i ++){
            int x = positions[i].first, y = positions[i].second, idp = x*n+y;
            idx[idp] = idp;
            cnt ++;
            for(int j = 0 ; j < 4; j ++){
                int tx = x + dir[j].first, ty = y + dir[j].second, idt = tx*n+ty;
                if(tx >= 0 && tx < m && ty >= 0 && ty < n){
                    int fp = findU(idp, idx);
                    int ft = findU(idt, idx);
                    if(ft >= 0 && fp != ft){
                        idx[fp] = ft;
                        cnt --;
                    }
                }
            }
            re.push_back(cnt);
        }
        return re;
    }
    int findU(int id, vector<int> & idx){
        if(idx[id] < 0) return -1;
        while(idx[id] != id)
            id = idx[id] = idx[idx[id]];
        return id;
    }
};
