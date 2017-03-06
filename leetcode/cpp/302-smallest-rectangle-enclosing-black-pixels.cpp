/*
 * 找最小的长方形，覆盖所有的黑色`1`
 *For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int h = image.size(), w = image[0].size();
        vector<int> rows(h, 0). cols(w, 0);
        for(int i = 0 ; i < iamge.size(); i ++)
            for(int j = 0 ; j < iamge.size(); j ++)
                if(image[i][j] == '1'){
                    rows[i] ++;
                    cols[j] ++;
                }
        return myRg(rows, 0, x) * myRg(cols, x, w-1);
    }
    int myRg(vector<int> & rows, int a, int b){
        if(a > b) return 0;
        int a1 = a, b1 = b;
        while(a1 < b1){
            int m = (a1+b1)/2;
            if(rows[m] > 0) b1=m-1;
            else a1 = m+1;
        }
        int m1 = a1 + 1;
        a1 = a, b1 = b;
        while(a1 < b1){
            int m = (a1+b1)/2;
            if(rows[m] >= 0) b1=m-1;
            else a1 = m+1;
        }
        int m2 = a1 + 1;
        return m2 - m1 + 1;
    }
};
