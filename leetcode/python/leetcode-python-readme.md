
## log

15. `3-sum` 排序后二分查找超时

>
14. `longest-common-prefix`, 网上找的直接所有的和第一个字符串匹配比二分查找更快, 可能是因为二分查找的切片代价比较大?

> for 迭代器 `for i in range(len(s))` 在外部定义的i不会改变值


11. `container-with-most-water`, 看的答案

>

10. `regular-expression-matching/`

> python里`True`,`False`要大写
> python 正则表达式`re.match(regex,str) != None`
> 二维数组记录匹配情况, 可以过 (还没找到速度快的算法)

9. `palinfrome-number`

> 字符串反向`str[::-1]`(反向切片)

8. `atoi`

> 判断字符串是否是数字`str.isdigit()`
6. `reverse-integer` 

> 必须要进行范围判断, 否则过不了. 之前网上很多的代码已经过不了了
> int32 max: 2**31-1, int32 min:-2**31


### ?: 表达式

> 不能写 `c = a> b and d or e`, 如果 d=0 则 c=e
> 可以写 `c = d if a > b else e`

5. `5-longest-palindromic-substring` , 求字符串的最长回文字串

> 1. O(n^2)算法过不了: 从长度为2的回文串开始找到所有长度的回文串,过不了"bbbbbbb..."的测试样例
> 2. 改了用二维数组存还是不行, 过不了一个很大的样例
> 3. 二维数组初始化方法
> 4. [Manacher's Algorithm: O(n) 算法](http://blog.csdn.net/hcbbt/article/details/43975453)

4. `median-of-two-sorted-arrays`

> 数组截取,函数调用
> 二分查找第k个数

3. `longest-substring-without-repeating-characters`, 看了之前的代码

> 1. 添加测试样例使用方法
> 2. dict字典查找,添加方法

2. `add-two-numbers`,

> 2. ListNode 判断 `None` 
> 3. 实例化 class, 如何调用

1. `two-sum`, 模仿网上例子写的, 很多语法错误

> 1. sort 函数写法

