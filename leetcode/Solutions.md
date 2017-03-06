## 252. Meeting Rooms
> 每个meeting有开始、结束时间，问一个人能否参加所有的meeting
> struct排序!
1. algrithm.sort 对vector排序，`bool cmp(int i,int j){return i<j;}`是正序

## 266. Palindrome Permutation
> 判断一个字符串的permutation是否可以变成回文子串
> permutation:123,132,213,231,312,321

## 280 wiggle sort
> 将数组排序成锯齿型：nums[0] <= nums[1] >= nums[2] <= nums[3]....


## 293. Flip Game
> 如果出现连续的`++`，可以将其替换成`--`，给定的字符串，返回所有的修改方法（只做一步）

1. 上面的代码嫩过，下面的`runtime error`,why???就是算len的区别

```cpp
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> re;
        int len = s.length();
        for(int i = 0 ; i < len-1; i ++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = s[i+1] = '-';
                re.push_back(s);
                s[i] = s[i+1] = '+';
            }
        }
        return re;
    }
};
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> re;
        for(int i = 0 ; i < len-1; i ++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = s[i+1] = '-';
                re.push_back(s);
                s[i] = s[i+1] = '+';
            }
        }
        return re;
    }
};
```
## stack
```cpp
#include <stack>
stack<int> st;
st.size();
st.empty();
st.top();
st.pop();
st.push(12);
stack<int> st2;
st.swap(st2);
```

## map
```cpp
#include <map>
map<char, char> c2c{{'c','3'},{'a','1'}};
```
