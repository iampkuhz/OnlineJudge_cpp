
|#|name|题意|解题思路|算法考点/注意|通过次数|错误原因|
|--|--|--|--|--|--|--|
|1|two-sum|给定一个vector<int>求2个下标，他们对应的数字和为target|构造新数组pair<val,index>,排序，然后左、右2个指针夹逼找和，如果大，则左指针加，等于则返回答案，如果小，则右指针减| |1 | 无|
|2|add-two-numbers|2个LinkedList表示2个整数（逆向），求和（用list表示）。Input: (2->4->3) + (5->6->4)，Output:7->0->8|2个指针遍历2个数，新的指针创建一个空头，算和，最后如果有进位，再做一个|1.2个整数不一样长<br> 2. 有进位|4|1. 指针取元素写成了`t.next`<br> 2. 忘记加最后的进位<br> 3. `t1!=NULL && t1!= NULL`，第二个是`t2`|
|3|longest-substring-without-repeating-characters|求最长的子串长度，使得子串没有重复元素|vector<int>[256]记录每个char之前的出现次数。同时记录已当前字符为结束的的最长题意要求的子串的开始位置，一次遍历得到答案|1. vector初始为-1<br> 2. 每次记录没有重复元素的开始位置|1|无|
|**4|median-of-two-sorted-arrays|在2个排序的数组中找中位数|1. 转换成找第k个数，变成求第（sz1+sz2)/2+1和（sz1+sz2+1)/2个数的平均值<br> 2. 看第一个数的中值，第一个数组长度大于2k，递归取前半; 否则，前半有l个数字，比较其与第二数组的第（k-l）个单词的关系，（1）（k-l）大于第二个数组长度、比第二个数组的第（k-l）个数大、小 三种情况递归，直到某个数组长度为0,则结果在另一个数组里|1. 二分，一般可以不用函数，比较快（但是可能不好实现） 2. 结束条件| 3|1. if(a2 > b2) return n`2`[a1+k-1];<br> 2. m1-a1>=k的时候b1=m1`-1`|
|**5|longest-palindromic-substring|找出给定字符串的最长回文子串|方法1： bfs，(O(n^2)复杂度)找到所有长度为1和2的子串，然后不断做<br> 2. 看答案, dfs, (O(n^2)复杂度)找到一个长度为1或2的回文字串就递归找<br>||3 (方法1)<br> 1 (方法2)<br>10+ (Manacher算法)|1. int re=0, `int rei` = 0;<br> 2. 二维数组`int a[m][n]`初始化|
|6|zigzag-conversion|将字符串按锯齿从上往下、再往右上排列，再按行从上往下读出来|存k个string，遍历原字符串的每个字符，先判断应该在的行数，然后添加到该行的末尾，最后把每一行的字符串拼接起来||3|1. 错误都是变量写错了<br> 2. 速度快：str.push_back(char), str.append(str)<br> 3. vector<string> 换成 string* 速度好像没有提升|
|7|Reverse Integer|颠倒int的数字顺序|将其转换成字符串，翻转后加符号返回||6|1. 头文件：<string>`int转string： to_string(23)`<br> 2. 头文件<algorithm>`string转int：std::atoi("23")`<br> 3. 字符串翻转` std::reverse(str.begin(),str.end())`,本地有reverse函数了，一定要加`std::`,不然报错<br> 4. 头文件<limits.h>或<climits>`INT_MAX`<br> 5. 如果超int范围，返回0|
|8|String to Integer (atoi)|自己实现一个aoti函数，将字符串转换成int|考虑各种情况：1. 先导空格去掉<br> 2.遇到第一个不是开头的非数字截断（或者开头不是符号）<br> 3.越界判断...||10|1. 这题本身不重要，关键是列举特殊情况再写 2. str替换字符：<algorithm>`replace(str.begin(),str.end(), 'c','a')`|
