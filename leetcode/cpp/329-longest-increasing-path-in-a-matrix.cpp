/*
 *Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
/*
 * 看答案改进
 */

class Solution {
    int row, col;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if(row < 1) return 0;
        col = matrix[0].size();
        if(col < 1) return 0;
        vector<vector<int> > pathL(row, vector<int>(col, 0));
        int re = 0;
        for(int i = 0 ;  i < row; i ++){
            for(int j = 0; j < col; j ++){
                re = max(re, getP(i, j, matrix, pathL));
                cout << getP(i, j, matrix, pathL) << " ";
            }cout << endl;
        }
        return re;
    }
    vector<vector<int> > dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int getP(int a, int b, vector<vector<int>>& matrix, vector<vector<int>>& pathL){
        if(pathL[a][b] > 0) return pathL[a][b];
        int re = 0;
        for(int i = 0 ; i < 4; i ++){
            int xx = a + dirs[i][0], yy = b + dirs[i][1];
            if(xx < 0 || xx >= row || yy < 0 || yy >= col) continue;
            if(matrix[xx][yy] >= matrix[a][b]) continue;
            re = max(re, getP(xx,yy,matrix, pathL));
        }
        pathL[a][b] = re + 1;
        return re + 1;
    }
};

/*
 * bfs过了，但是时间很不好
 * 不好的原因：写的冗余：好几处判断越界的地方, 2. 函数太多 3. 没必要区分开始点
 */
class Solution {
    int row, col;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if(row == 0) return 0;
        col = matrix[0].size();
        if(col == 0) return 0;
        vector<vector<int> > lev(row, vector<int>(col, -1));
        queue<pair<int, int>> vp;
        for(int i = 0 ; i < row; i ++)
            for(int j = 0; j < col; j ++)
                if(isMin(i, j, matrix)){
                    lev[i][j] = 0;
                    vp.push(make_pair(i,j));
                }
        int maxVP = 0;
        while(!vp.empty()){
            auto p = vp.front();
            vp.pop();
            PushSurd(p.first, p.second, matrix, lev, vp);
            maxVP = max(maxVP, lev[p.first][p.second]);
        }
        return maxVP + 1;
    }
    void myPush(int a, int b, int a1, int b1, vector<vector<int> >& matrix, vector<vector<int> >& lev, queue<pair<int, int>>& vp){
        if(a1 >= 0 && a1 < row && b1 >= 0 && b1 < col && matrix[a1][b1] > matrix[a][b] && lev[a1][b1] <= lev[a][b]){
            lev[a1][b1] = lev[a][b] + 1;
            vp.push(make_pair(a1,b1));
        }
    }
    void PushSurd(int a, int b, vector<vector<int> >& matrix, vector<vector<int> >& lev, queue<pair<int, int>>& vp){
        myPush(a,b,a+1,b,matrix,lev,vp);
        myPush(a,b,a-1,b,matrix,lev,vp);
        myPush(a,b,a,b+1,matrix,lev,vp);
        myPush(a,b,a,b-1,matrix,lev,vp);
    }
    bool myLess(int x1, int y1, int x2, int y2, vector<vector<int> >& matrix){
        if(x2 < 0 || x2 >= row || y2 < 0 || y2 >= col || matrix[x1][y1] <= matrix[x2][y2])
            return true;
        return false;
    }
    bool isMin(int a, int b, vector<vector<int> >& matrix){
        if(myLess(a, b, a+1, b,matrix) && myLess(a, b, a-1, b,matrix)
                && myLess(a, b, a, b+1,matrix) && myLess(a, b, a, b-1,matrix))
            return true;
        return false;
    }
};
