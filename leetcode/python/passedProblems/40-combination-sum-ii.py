#-*-coding:utf-8-*-
"""
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
    For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
    A solution set is: 
    [1, 7] 
    [1, 2, 5] 
    [2, 6] 
    [1, 1, 6] 
"""
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nc=sorted(candidates);
        #print nc;
        ls,re=[],[];
        lastPop = [-1];
        def dfs(i, ls, target):
            if i >= len(nc) or target <= 0:
                if target == 0 and i <= len(nc):
                    re.append(ls[:]);
                return;
            #print lastPop[0],i, ls, target
            if target >= nc[i] and nc[i] != lastPop[0]:
                ls.append(nc[i]);
                dfs(i+1, ls, target-nc[i]);
                lastPop[0] = ls[-1];
                ls.pop();
            dfs(i+1, ls, target);
        dfs(0,ls,target);
        return re;
                


s=Solution();
#print s.combinationSum2([10,1,2,7,6,1,5],8);
print s.combinationSum2([1],1);
