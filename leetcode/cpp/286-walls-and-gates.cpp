/*
 *
 * 8次过，题目不难，注意vector是复制不是对象
 * 多源最短路径，queue + BFS
 *
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */

#include <vector>
#include <queue>
using namespace std;

struct node{
    int x;
    int y;
    int step;
};
class Solution {
    int w, h;
    queue<node> qp;
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        h = rooms.size();
        if(h == 0) return;
        w = rooms[0].size();
        cout << w << " " << h << endl;
        for(int i = 0 ; i < h; i ++)
            for(int j = 0 ;j  < w; j ++){
                if(rooms[i][j] == 0){
                    node n = {i, j, 0};
                    qp.push(n);
                }
            }
        while(!qp.empty()){
            node tn = qp.front();
            qp.pop();
            update(tn.x + 1, tn.y, tn.step + 1, rooms);
            update(tn.x - 1, tn.y, tn.step + 1, rooms);
            update(tn.x, tn.y + 1, tn.step + 1, rooms);
            update(tn.x, tn.y - 1, tn.step + 1, rooms);
        }
    }

    void update(int x, int y, int step, vector<vector<int>>& r2){
        if(w < 5 && h < 5)
        cout << x << " " << y << " " << step << endl;
        if(x < 0 || x >= h || y < 0 || y >= w || (r2[x][y] >= -1 && r2[x][y] != INT_MAX))
            return;
        node tn = {x,y,step};
        r2[x][y] = step;
        if(w < 5 && h < 5)
        cout << x << " " << y << " " << step << endl;
        qp.push(tn);
    }
};
