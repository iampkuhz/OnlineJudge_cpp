#-*-coding:utf-8-*-
"""
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
    For example, given candidate set 2,3,6,7 and target 7,
    A solution set is:
    [7]
    [2, 2, 3]
"""

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        re=[];
        sn = sorted(candidates);
        lt = [];
        def find(i, lt, target):
            if i >= len(sn):
                return;
            if target <= 0:
                if target == 0:
                    #print lt;
                    re.append(lt[:]);
                return;
            if target >= sn[i]:
                lt.append(sn[i]);
                find(i, lt, target-sn[i]);
                lt.pop();
                find(i+1, lt, target);

        find(0,lt,target);
        return re;

s=Solution();
print s.combinationSum([2,3,6,7], 7);


