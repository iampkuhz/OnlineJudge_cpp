
## log

51. `51-n-queens.py` ｎ皇后问题，不难，但是写的代码有点长

> 1. 如果用一维数组存放改行皇后所在的列号，判断皇后是否矛盾的函数代码可以大大减小

50.`50-powx-n.py` 比较简单，但是注意边界条件

49.`49-anagram.py` 简单，调用python的内置排序函数即可

> 1. 注意每组内部需要排序
> 2. python 排序指定键值`sorted(lt, key=lambda x: (x[2],x[1])`

48.`48-rotate-image.py`不难，两次过

> 1. 主要注意别搞错方向, 没有`a[x1,y1]`d的取法，应该是`a[x1][y1]` 

37.`47-permutations-ii.py` 和46一样，递增序列的要求更为宽松

46.`46-permutations.py` 本地调试了几次，一次过，方法简单，但是++--注意区分

45.`45-jump-game-ii.py` queue+剪枝过了，但是很不好看(后0.5%)

> 查看网上例子重新过了

44.`44-wildcard-matching.py` 看答案调了很多次才过，还没有完全理解意思

> 1. 直接套用python的正则表达式替换会超时，要自己写
> 2. 用二维数组存前k个字符能否被前l个模式串匹配也超时,可能会有4000×4000的二维数组
> 3. 二维数组可以压缩到[2][j]维，近似一维数组，重新用python实现：**超时**,之前cpp过的样例已经不能提交（函数入口改了）

43. `43.43-multiply-strings.py`, 大整数乘法，系统支持

42. `42.trapping-rain-water.py`, 本地调试一次，提交一次过

> 看到网上的思路后修改代码，可是比之前的还慢

41. `41.first-missing-positive.py` 看答案过的

40. `40-combination-sum-ii.py` 怎么防止`1,1,1`中第1、2,1、3被取两次？

> 我的思路：过了例子，但是没有证明，直观是对的。保留移出栈的最后一个元素，如果下一个要加入栈的元素和之前最后一次移入的元素一样，则说明重复了

38. `38-count-and-say.py` 把数字读出来，不难，看清题意

37. `37-sudoku-solver.py` dfs的时候注意几个返回位置

> 有高效解法：:

36. `36-valid-sudoku.py` 注意读题，没看清题意

> if语句写在一行的方式`if clause:continue;`
> 不能对str类型使用`s[2]='f'`进行赋值，需要新建一个str，但是leetcode上直接赋值不会报错

35. `35-search-insert-position.py` 一次过，速度快

34. `34-search-for-a-range.py` 一次过， 但是时间很慢，因为做了两次二分查找来找出左右边界

> 1. 两个函数其实可以合并
> 2. 也可以先找到一个值，再左右伸展
> 3. 下次考虑上面两种算法

33. `33-search-in-rotated-sorted-array.py` 调了很多次，还看了答案才过

> 判断分支特别碎，以后分情况考虑的时候一定要保证变量名和纸上写的一样，不然草稿就百搭了


32. `32-longest-valid-parentheses.py` 匹配过了，提交了很多次，网上有使用stack的方法，速度快

> 1. 几个边界条件需要考虑清楚

30. `30-osubstring-with-concatenation-of-all-words.py` 搜的答案

> 1. hash方法已经不能过了
> 2. hash方法的网上例子写的很简洁`[f(x) for x in xrange(len(t)) if p(x)]`

29. `29-divide-two-integers.py` 自己实现除法

> 1. python int 最小值`-(i<<31)`, int 最大值`(i<<31)-1`
> 2. python 位运算符优先级小于"+-",`1<<31-1`等于`1<31`

28. `28-implement-strstr.py` KMP 找子串

27. `27-remove-element.py` 小bug太多，提交了3次，都是语法错误`++` 和变量名写错

26. `26-remove-duplicates-from-sorted-array.py` 提交了好几次，小bug非常多

25. `25-reverse-nodes-in-k-group.py` 一个小bug，提交两次过，但是bug查了好久，增加了测试类`comMethod`把`list`转换成`ListNode`

24. `24-swap-nodes-in-pairs.py` 两次过，小bug, 画图做

22. `22-generate-parentheses.py`，一次过，本地调试一次

> python 调用函数的时候千万别忘了`self.method()`!!!

21. `21-merge-two-sorted-lists.py`, 一次过，本地没调

20. `iValid Parentheses`, 判断括号是闭合的，python代码很多bug，本地调了几次，网上提交一次过

> python 字典初始化`myDict={'a':1,'b':2}`

19. `Remove Nth Node From End of List`, 一次过

> python 没有指针，全部是对象

18. `4-sum` 和 `3-sum` 一样，一次过

15. `3-sum` 排序后二分查找超时

> python尽量别写函数，如果数组不能复用的话复制给函数的时候很花时间，思路对了，但是实现方式不好
> 数组'num'内部排序'num.sort()'

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

