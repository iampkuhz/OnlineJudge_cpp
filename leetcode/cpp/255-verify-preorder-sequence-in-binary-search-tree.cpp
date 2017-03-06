/*
 * 10次过，看答案，需要重做
 * 检查是否是二叉搜索树的前序遍历
 */

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int sz = preorder.size();
        if(sz <= 1) return true;
        stack<int> st;
        st.push(preorder[0]);
        int ind = 1;
        while(ind < sz && preorder[ind] < preorder[ind-1])
            st.push(preorder[ind++]);
        int curRoot = (1<<31);
        while(ind < sz){
            int v = preorder[ind++];
            if(st.empty() || v < st.top()){
                if(v < curRoot) return false;
            }
            else{
                while((!st.empty()) && st.top() < v){
                    curRoot = st.top();
                    st.pop();
                }
            }
            st.push(v);
        }
        return true;
    }
};
/*
 * 方法不对：
 * 记录最右的序列，如果出现连续小于序列中的2个点，则说明不对
 */
