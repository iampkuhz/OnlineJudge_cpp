#!/usr/bin/env python
# encoding: utf-8


"""
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
"""
# 还有更快的方法是不使用 form字符串参数，每个”+192“，”-23“， ”×33“作为独立元素放在list中append、pop来公用，减少参数复制


# leetcode样例和C很像，但是快很多，怀疑是内置函数所以跑的快，将C改写成类方法
# 还是4s+
# 将nnum空串判断由 nnum == None or len(nnum) < 1 变成 not nnum，速度立刻提升: 4000ms -> 2700ms, 和是否是类方法无关！
class Solution(object):
    def addOperators(self, num, target):
        res, self.target = [], target
        for i in range(1,len(num)+1):
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], num[:i], int(num[:i]), int(num[:i]), res) # this step put first number in the string
        return res

    def dfs(self, num, temp, cur, last, res):
        if not num:
            if cur == self.target:
                res.append(temp)
            return
        for i in range(1, len(num)+1):
            val = num[:i]
            if i == 1 or (i > 1 and num[0] != "0"): # prevent "00*" as a number
                self.dfs(num[i:], temp + "+" + val, cur+int(val), int(val), res)
                self.dfs(num[i:], temp + "-" + val, cur-int(val), -int(val), res)
                self.dfs(num[i:], temp + "*" + val, cur-last+last*int(val), last*int(val), res)


# C.看网上的答案，每次计算当前公式的值和最后一个数字（为了回滚操作),4156ms
class Solution(object):
    def addOperators(self, num, target):
        re = []
        self.tar = target
        def dfs(nnum, form, val, last):
            if nnum == None or len(nnum) < 1:
                if val == self.tar: re.append(form)
                return
            nnl = len(nnum)
            for i in range(1, nnl+1):
                if ( i != 1 and nnum[0] == '0'): return
                sv = nnum[0:i]
                dfs(nnum[i:], form + '*' + sv, val - last + last * int(sv), last*int(sv))
                dfs(nnum[i:], form + '+' + sv, val + int(sv), int(sv))
                dfs(nnum[i:], form + '-' + sv, val - int(sv), -int(sv))
        for i in range(1, len(num)+1):
            if (i != 1 and num[0] == '0'): break
            sv = num[0:i]
            dfs(num[i:], sv, int(sv), int(sv))
        return re




# 超时，"1000000009" 9
class Solution(object):
    def addOperators(self, num, target):
        if len(num) < 1: return []
        def lev(op):
            return 1 if op in '+-' else 2
        def calc(opr, nums):
            op = opr.pop()
            n1, n2 = nums.pop(), nums.pop()
            nums.append(n1*n2 if op == '*' else ( n1+n2 if op == '+' else n2-n1))
        self.tar = target
        re = []
        def dfs(nnum, opr, nums, form):
            if nnum == None:
                while len(opr) > 0: calc(opr, nums)
                if nums[0] == self.tar: re.append(form)
                return
            for i in range(1, len(nnum)+1):
                v = int(nnum[0:i])
                while len(opr) > 0 and opr[-1] == '*': calc(opr, nums)
                dfs(nnum[i:], opr, nums, form + "*" + nnum[0:i])
                while len(opr) > 0 : calc(opr, nums)
                dfs(nnum[i:], opr, nums, form + "-" + nnum[0:i])
                dfs(nnum[i:], opr, nums, form + "+" + nnum[0:i])
        dfs(num, [], [], '')
        return re




# 3次超时："2147483648" -2147483648
# 4次过了，非常慢，看不到排名。。。：改了判断是否是“098”的数字、target做全局函数
# 简单看了下别人的答案，主要是传递opr,nums两个list浪费太多时间了,还有自己每次只考虑一个字符，递归次数多
class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if len(num) < 1: return []
        re = []
        def lev(op):
            return 1 if op in '+-' else 2
        def calc(opr, nums):
            op = opr.pop()
            n1, n2 = nums.pop(), nums.pop()
            nums.append(n1*n2 if op == '*' else ( n1+n2 if op == '+' else n2-n1))

        freq = [0]
        self.tar = target
        def dfs(ind, opr, nums, form):
            freq[0] += 1
            if ind >= len(num):
                while len(opr) > 0: calc(opr, nums)
                if nums[0] == self.tar: re.append(form)
                return
            if nums[-1] != 0:
                t = nums[-1] * 10 + int(num[ind])
                dfs(ind+1, opr[:], nums[0:-1] + [t], form + num[ind])

            while len(opr) > 0 and lev(opr[-1]) == 2:
                calc(opr, nums)
            dfs(ind+1, opr + ['*'], nums + [int(num[ind])], form + '*' + num[ind])

            while len(opr) > 0:
                calc(opr, nums)
            dfs(ind+1, ['+'], nums + [int(num[ind])], form + '+' + num[ind])
            dfs(ind+1, ['-'], nums + [int(num[ind])], form + '-' + num[ind])
        dfs(1, [], [int(num[0])], num[0])
        print freq[0]
        return re

s=Solution()
print s.addOperators('123',6)
print s.addOperators('232',8)
print s.addOperators('105',5)
print s.addOperators('00',0)
print s.addOperators('3456237490',9191)
print s.addOperators('2147483648',-2147483648)


