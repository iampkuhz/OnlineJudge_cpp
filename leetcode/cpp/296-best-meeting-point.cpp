/*
 *A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

*/

#include <vector>
#include <algorithm>
using namespace std;

/*
 * 3次过，都是因为没有看清输入格式
 * 思路看了网上的答案
 */
class Solution {
public:
    int minTotalDistance(vector<vector<int> >& grid) {
        int h = grid.size(), w = grid[0].size();
        vector<int> vx;
        vector<int> vy;
        for(int i = 0  ; i < h; i++)
            for(int j = 0 ; j < w; j ++)
                if(grid[i][j] == 1){
                    vx.push_back(i);
                    vy.push_back(j);
                }
        return getMinSum(vx) + getMinSum(vy);
    }
    int getMinSum(vector<int> & vs){
        int hf = vs.size()/2;
        nth_element(vs.begin(), vs.begin()+hf, vs.end());
        int re = 0;
        for(int i = 0 ; i < vs.size(); i ++)
            re += abs(vs[i] - vs[hf]);
        return re;
    }
};
