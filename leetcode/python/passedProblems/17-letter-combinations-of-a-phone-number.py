"""
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
"""

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return [];
        self.nums=[[],[],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z'],[' ']];
        re=[];
        self.Dfs(re, '', digits, 0);
        return re;
    def Dfs(self, re, tStr, digits, ind):
        if ind >= len(digits):
            re.append(tStr);
            return;
        for j in range(len(self.nums[int(digits[ind])])):
            self.Dfs(re, tStr + self.nums[int(digits[ind])][j], digits, ind+1);

s = Solution();
print s.letterCombinations("23");
print s.letterCombinations("");

        
        
