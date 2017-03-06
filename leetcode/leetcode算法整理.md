# 23. Merge k Sorted Lists
1. 最小堆

# 24. swap-nodes-in-pairs
1. 将链表的每两个连续的元素交换顺序，`1->2->3->4` -> `2->1->4->3`
2. 递归做

# 25. Reverse Nodes in k-Group
1. 将链表的每k个连续的元素交换顺序，`1->2->3->4->5` k=3 -> `3->2->1->4->5`

# 26. 26. Remove Duplicates from Sorted Array

# 27. Remove Element
1. 给定数据和待删除的值，将数组中的元素删除，并返回新的数组长度
2. 一遍循环即可，循环中记录当前要插入的节点的index

# 28. Implement strStr()
1. 实现自己的字串查找
2. 二重循环查找即可，KMP？

# 29. Divide Two Integers
1. 不使用乘、除、模运算，实现除法
2. 二进制移位+大小判断：1.每次找n最大的移位数shift是的m>(n<<shift),之后将m减去n<<shift，result+=1<<shift之后递归算；中间都用long来算，最后和边界值比较

# 30. Substring with Concatenation of All Words

# 31. Next Permutation
1.


# 94. Binary Tree Inorder Traversal
1. 中序遍历二叉树
2. 用一个stack保留从右上到左下的序列； 当前节点如果不为空，先递归到其最左下节点（之前节点压栈），访问该节点，并进入其右子节点继续，如果当前节点为空，则取栈中最后一个元素
