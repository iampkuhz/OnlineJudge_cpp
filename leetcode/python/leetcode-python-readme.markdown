
## log

283. `283-move-zeroes.py`, 不难，一次过

113.`113-path-sum-ii.py`,输出路径和等于目标值的路径，不难，2次过，时间效率很好

112.`112-path-sum.py` 递归边界考虑不清，7次过，但是不难

111.`111-minimum-depth-of-binary-tree.py` BFS比DFS速度要快,看答案想到BFS，都是改了好多次过，None的判断出问题

> `collections.deque`比`Queue.Queue()`快

110.`110-balanced-binary-tree.py` 判断二叉树是否是平衡的，递归算，5次过，不难

109.`109-onvert-sorted-list-to-binary-search-tree.py`, 只能单向访问的链表重构成BST树，10次过，效率特别慢;网上发现快速方法,2次过

108.`108-convert-sorted-array-to-binary-search-tree.py`,两次过，简单

107.`107-binary-tree-level-order-traversal-ii.py` 按照节点深度反序输出序列，7次过，速度慢;参考网上方法，速度快，简单，2次过

106'`106-construct-binary-tree-from-inorder-and-postorder-traversal.py`,通过中序序列、后序序列重构二叉树，开始时没考虑清边界条件，2次过

105.`105-construct-binary-tree-from-preorder-and-inorder-traversal.py`,通过先序序列、中序序列重建二叉树，开始用函数递归做超内存，改用函数内小函数做+字典查找位置过了. 开始超内存是因为老是函数调用切片会增大内存，后来使用下标就好了

104.`104-maximum-depth-of-binary-tree.py` 一次过，简单

103. `103-binary-tree-zigzag-level-order-traversal.py`102的变形，简单

102. `102-binary-tree-level-order-traversal.py` 提交三次，主要是对Queue的调用不熟悉,简单

101. `101-symmetric-tree.py` 3次过，注意边界，简单

100.`100-same-tree.py` 算一次过，（函数名写错了多提交一次），简单

99.`99-recover-binary-search-tree.py`,O（n）复杂度过了，调了8次, 参考网上答案实现了O（1）空间复杂度的方法，没有提升时间

98.`98-validate-binary-search-tree.py` 一次过

97.

96.`96-unique-binary-search-trees.py`，3次过，看答案有好的解法，参考答案一次过

95.`95-unique-binary-search-trees-ii.py` 提交14次才过，各种细节没有考虑到

94.`94-binary-tree-inorder-traversal.py` 递归方法一次过，非递归方法4次过

93. `93-restore-ip-addresses.py`,两个边界没考虑清楚，提交三次,不难

92.`92-reverse-linked-list-ii.py`,一次过，不难，想好链表交换的细节

91.`91-decode-ways.py` 思路对，还是细节，字符和数字？提交5次过

90.`90-subsets-ii.py` 思路对，细节没考虑好，提交4次过

89.`89-gray-code.py` 提交两次，边界每考虑全，简单

88.`88-merge-sorted-array.py` 方法对，细节没考虑请，提交了3次

87.`87-scramble-string.py` 一个重要剪枝没考虑，一个小错误一直没发现，重做

86. `86.partition-list.py` 简单，注意细节，改了2次交过了

85.`85-maximal-rectangle.py` 有84题很好做，边界条件提交了2次

84. `84-largest-rectangle-in-histogram.py` 自己写的双向数组做的(两次过)，看答案发现更好的方法（3次过）

> stack判断是否为空 `while not stk:`
> list.pop放在句子中可能先pop，`(lt[-1]-lt.pop())===0`为倒数第1个元素减最后一个元素, `lt.pop-lt[01]`为原来的最后一个元素减去倒数第二个元素

83. `83-remove-duplicates-from-sorted-list.py` 一次过，本地没调试

82. `82-remove-duplicates-from-sorted-list-ii.py` 看答案过的，还需要再做


80.`80-remove-duplicates-from-sorted-array-ii.py` 两次过，本地无调试，注意原数组也要修改

79.`79-word-search.py` 本地调试了很多次，提交一次过，注意细节

78. `78-subsets.py` 一次过，不难

77. `77-combinations.py` 一次过，不难

76. `76-minimum-window-substring.py` 看答案过的，调试了2次，提交一次过，需要再写

> python 字典的用法

75.`75-sort-colors.py` 看了最优解法（速度上没有什么优势）

74. `74-search-a-2d-matrix.py` 一次过，效率还行，注意剪枝，O(m+n)时间复杂度

73. `73-set-matrix-zeroes.py` 将0所在行、列全部置0，o(m+n)的空间复杂度，不是空间最优

72. `72-edit-distance.py`，计算编辑距离，考虑边界情况，提交了5次才过，要重做

71. `71-simplify-path.py` 自己实现unix路径的正规化，考虑好题目给出的几个例子，本地debug一次，提交一次过，不难

68. `69-sqrtx.py` 实现整数的开方，二分查找，一次过

67. `67-add-binary.py` 调了几次才过，代码写的不好,有一行的写法

66.`66-plus-one.py` 模拟+1,一次过

65.`65-valid-number.py` 调用python内置函数

64.`64-minimum-path-sum.py`,最优路径，递归，注意边界单独算，调了3次过

63.`63-unique-paths-ii.py` 比62题多设置一个路障，动规，注意边界，一次过

62. `62-unique-paths.py` (m,n)方格的走法，动规，一次过

61. `61-rotate-list.py`，注意旋转方向，两次过，没问题

60.`60-permutation-sequence.py` 快速算每一位存的是第几大的数，一次过

59. `spiral-matrix-ii`, 54题类似，生成方形二维回行数组，比54题简单，本地调试了一下，提交一次过，注意边界

58. `58-length-of-last-word.py` python内置的split函数。自己实现的效率不好。这一题调了好多次才过，下次要重新做

57. `57-insert-interval.py` 过的方法不是最好的，先加进入排序再输出

56. `56-merge-intervals.py 

55. `55-jump-game.py` 45题的简化版本

54. `spiral-matrix`,回行数组遍历，考虑好边界情况

53. `53-maximum-subarray.py` 一次过

52. `52-n-queens-ii.py`， 两种方法，都是一次过

> 1. 普通方法：一维数组存放每行皇后的位置，
> 2. 完全递归方法：皇后位置数组，已经使用的左右斜对角行号都用list表示，作为三个参数递归，此方法快


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

