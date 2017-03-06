/*
 *Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
                  */
#include <iostream>
#include <vector>
using namespace std;

/*
 * 看答案，1次过，28ms
 */
class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        int ha = A.size(), wa = B.size(), wb = B[0].size();
        vector<vector<int> > re(ha, vector<int>(wb,0));
        for(int i = 0 ; i < ha; i ++)
            for(int j = 0; j < wa; j ++)
                if(A[i][j] != 0){
                    for(int k = 0 ; k < wb; k ++)
                        if (B[j][k] != 0)
                            re[i][k] += A[i][j] * B[j][k];
                }
        return re;

    }
};


/*
 * 一次过，时间还可以,48ms
 */
class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        int ha = A.size(), wa = B.size(), wb = B[0].size();
        vector<vector<int> > re(ha, vector<int>(wb));
        bool *zeroB = new bool[wb];
        bool *zeroA = new bool[ha];
        for(int j = 0; j < wb; j ++){
            bool isz = true;
            for(int i = 0 ;  i < wa; i++)
                if(B[i][j] != 0){
                    isz = false;
                    break;
                }
            zeroB[j] = isz;
        }
        for(int i = 0 ; i < ha; i ++){
            bool isz = true;
            for(int j = 0 ; j < wa; j ++)
                if(A[i][j] != 0){
                    isz = false;
                    break;
                }
            zeroA[i] = isz;
        }
        for(int i = 0 ; i < ha; i ++)
            for(int j = 0; j < wb; j ++){
                if(zeroA[i] || zeroB[j])
                    re[i][j] = 0;
                else{
                    int sum = 0;
                    for(int k = 0; k < wa; k ++)
                        sum += A[i][k] * B[k][j];
                    re[i][j] = sum;
                }
            }
        return re;
    }
};
