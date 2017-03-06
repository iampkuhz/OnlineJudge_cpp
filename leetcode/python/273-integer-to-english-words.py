#!/usr/bin/env python
# encoding: utf-8


"""
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Show Hint

"""

# 3次过，re反向添加、添加前要判断是否加空格
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0: return 'Zero'
        k = ['', ' Thousand', ' Million', ' Billion']
        tens = ['', '', 'Twenty', "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        ones = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        teen = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        t = 0
        re = []

        def addRe(tk, i):
            s = ''
            if tk >= 100: s += ones[tk/100] + ' Hundred'
            tk -= tk/100 * 100
            if tk >= 20:
                s += (' ' if len(s) > 0 else '') + tens[tk/10]
            if tk/10 != 1:
                if tk % 10 != 0:
                    s += (' ' if len(s) > 0 else '') + ones[tk%10]
            else:
                s += (' ' if len(s) > 0 else '') + teen[tk-10]
            if len(s) > 0:
                s += k[i]
                re.insert(0, s)

        while num > 0:
            tk = num % 1000
            addRe(tk, t)
            t += 1
            num = num / 1000
        return ' '.join(re)




