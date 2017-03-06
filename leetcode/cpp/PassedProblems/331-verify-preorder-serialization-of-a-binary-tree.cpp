/*
 * 判断是否是正确的前序遍历序列
 * 3次过，开始写c++，有些不熟悉，题目简单
 *
 *One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
 * */
# include <string>
using namespace std;

/*
 * 看答案
 */
# include <sstream>
# include <algorithm>
class Solution {
public:
    string po;
    int pol;
    bool isValidSerialization(string preorder) {
        preorder.replace(preorder.begin(), preorder.end(), ',', ' ');
        stringstream ss(preorder);
        int treeCnt = 1;
        string node;
        while(ss >> node){
            if(treeCnt == 0) return false;
            if(node == '#')
                treeCnt --;
            else treeCnt ++;
        }
        return treeCnt == 0;

    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        replace(preorder.begin(), preorder.end(), ',', ' ');
        stringstream ss(preorder);
        int treeCnt = 1;
        string node;
        while(ss >> node){
            if(treeCnt == 0) return false;
            if(node == "#")
                treeCnt --;
            else treeCnt ++;
        }
        return (treeCnt == 0);
    }
};

class Solution {
public:
    string po;
    int pol;
    bool isValidSerialization(string preorder) {
        po = preorder;
        pol = po.length();
        return isV(0) == pol-1;

    }

    int isV(int ind){
        if(ind >= pol)
            return ind;
        if (po[ind] == '#')
            return ind;
        while(ind < pol && po[ind] != ',')
            ind ++;
        int leftInd = isV(ind+1);
        int rightInd = isV(leftInd+2);
        return rightInd;
    }

    void test(){
        cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    }
};



