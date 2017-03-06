#!/usr/bin/env python
# encoding: utf-8

"""
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

"""

# 听jess的方法
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        if len(dungeon) == 0 or len(dungeon[0]) == 0: return 1
        r, c = len(dungeon), len(dungeon[0])
        init = [[0] * (c + 1) for j in range(r + 1)]
        for i in range(r-1, -1, -1):
            for j in range(c-1, -1, -1):
                if j == c-1: # 只和下面有关
                    need = dungeon[i][j] - init[i+1][j]
                    init[i][j] = 0 if need >= 0 else -need
                else : # 只和右面有关
                    needr = dungeon[i][j] - init[i][j+1]
                    needr = 0 if needr >= 0 else -needr
                    if i != r-1:
                        needd = dungeon[i][j] - init[i+1][j]
                        needd = 0 if needd >= 0 else -needd
                        needr = min(needd, needr)
                    init[i][j] = needr
        return init[0][0]+1




# 1. re[k]写成re[i]
# 2. [[-3],[-7]] =>8?
# 3. 调整了更新策略还是不能过，在一个复杂的样例，应该是边界没有考虑清楚
# 4. 调整的判断策略，最后一个测试样例过不了43/44
# 5. 错误：比如maxBound=(12,2),maxLeft(20,200),但是最后一个点是(-20),中间有一条路径是(15,21),答案应该是15
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        if len(dungeon) == 0 or len(dungeon[0]) == 0: return 1
        r, c = len(dungeon), len(dungeon[0])
        minBound = [[[0,0] for i in range(c+1)] for j in range(r+1)]
        maxLeft = [[[0,0] for i in range(c+1)] for j in range(r+1)]
        # init [0][0] [bound, left]
        def get(p1, p2, ind):
            return p1[:] if p1[ind] > p2[ind] or (p1[ind] == p2[ind] and p1[1-ind] > p2[1-ind]) else p2[:]

        for i in range(0, r):
            for j in range(0, c):
                #b1, l1, b2, l2
                re = [minBound[i][j-1][:], maxLeft[i][j-1][:], minBound[i-1][j][:], maxLeft[i-1][j][:]]
                for k in range(4):
                    re[k][1] += dungeon[i][j]
                    if re[k][1] <= 0:
                        re[k][0] += re[k][1] -1
                        re[k][1] = 1
                    elif i == 0 and j == 0:
                        re[k][1] += 1
                if j != 0:
                    minBound[i][j] = get(re[0], re[1], 0)
                    maxLeft[i][j] = get(re[0], re[1], 1)
                    if i > 0:
                        t = get(re[2], re[3], 0)
                        minBound[i][j] = get(minBound[i][j], t, 0)
                        s = get(re[2],re[3],1)
                        maxLeft[i][j] = get(maxLeft[i][j], s, 1)
                else:
                    minBound[i][j] = get(re[2], re[3], 0)
                    maxLeft[i][j] = get(re[2], re[3], 1)

                print i,j,minBound[i][j], maxLeft[i][j],
            print ""
        return max(1,-minBound[r-1][c-1][0])

s=Solution()
#print s.calculateMinimumHP([[-3],[-7]])
#print s.calculateMinimumHP([[3,-20,30],[-3,4,0]])
#print s.calculateMinimumHP([[1,-3,3],[0,-2,0],[-3,-3,-3]])


