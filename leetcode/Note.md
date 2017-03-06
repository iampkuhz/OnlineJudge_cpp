
# 算法

1. 找到字符串的所有回文子串的复杂度？
2. leetcode.238不会做
3. python最小堆的使用
4. 线段树：leetcode.307
5. python 判断list是否为空：速度比较
6. c++ 找偏序集的优先队列？（排课表）


# C++ 语法
> algorithm 默认最大堆，增加排序函数即可

## unordered_map

## priority_queue

## 最小堆
```cpp
struct greater1{
  bool operator()(const long& a,const long& b) const{
    return a>b;
  }
};
int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end(), greater1());
  std::cout << "initial min heap   : " << v.front();//30

  std::pop_heap (v.begin(),v.end(), greater1()); v.pop_back();
  std::cout << "min heap after pop : " << v.front();//20

  v.push_back(99); std::push_heap (v.begin(),v.end(), greater());
  std::cout << "min heap after push: " << v.front(); // 99

  std::sort_heap (v.begin(),v.end(), greater());//5 10 15 20 99

  ```
## 字符串语法：

```cpp
#include <string>
string str("qeewqwdwq");
string str2(str, 4,3); //str2="qwd"
str.substr(2,5) : //[2,5]
str.substr(2); // [2,end]
```

3. 字符串替换

```cpp
str.replace(8,10,"just a");
str.replace(str.begin(),str.end()-3,str3);

#include <algorithm>
replace(str.begin(),str.end(), 'x', 'y') // x 替换成y
```

## vector

```cpp
#include<vector>
vector<string> vs;
vs.push_back("12321");
// sort 排序
#include <algorithm>
bool myCmp(int i, int j){ return i < j;} // 正序
sort(vs.begin(),vs.end(), myCmp);
sort(vs.begin(),vs.end());
```

## queue
```cpp
#include <queue>
queue<int> qi;
qi.empty();
qi.size();
qi.front();
qi.pop();
qi.back();
qi.push();
```

## bitset

```cpp
bitset<256> bs // 32 bit, all zero
bs.flip(2); //第二位取反
bs.count() // 置1的二进制位数
bs.set(2); //第二位置1
bs.reset(2); //第二位置0
(bs1 & bs2).count(); //相同的置1位的个数
```
﻿
## stringstream

```cpp
#include <sstream>
stringstream ss("9,3,4,#,#,1,#,#,2,#,6,#,#");
string value;
while(ss >> value){cout << value << endl;}
```

## cmpare

## <algorithm>
```cpp
# swap
vector<int> vi
swap(vi[1],vi[3]);
```

## pair
```cpp
vector<pair<int, int>> vps;
#include <utility>
vps.push_back(make_pair(1,3));
```

## 类型转换
```cpp
string a(1,'c');//char to string
string s = std::to_string(42); // int to string
```
