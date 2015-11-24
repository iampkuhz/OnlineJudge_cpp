#-*-coding:utf-8-*-

# 方法2: 用一个n维数组记录每行的字符串,按照原始字符串的顺序把每个字符添加到字符串的末尾,最后合并n个字符串
# 方法2速度快很多
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s;
        r = ['' for i in range(numRows)]
        rn = 0;
        direct=1;
        for i in range(len(s)):
            r[rn] += s[i];
            rn += direct;
            if rn > numRows-1:
                rn = numRows - 2;
                direct = -1;
            elif rn < 0:
                rn = 1;
                direct = 1;
        return ''.join(r);

# 方法1: 按照先后顺序输出:先统计block的数量,然后按行输出(每行内按block顺序输出)
#class Solution(object):
#    def convert(self, s, numRows):
#        """
#        :type s: str
#        :type numRows: int
#        :rtype: str
#        """
#        if numRows == 1:
#            return s;
#        re = "";
#        blk = (len(s) + 2*numRows-1) / (2 * numRows -2);
#        for line in range(1,numRows+1):
#            for b in range(0, blk+1):
#                if b*(2*numRows-2)+ line < len(s) + 1:
#                    re = re + s[b*(2*numRows-2)+line -1];
#                if line != 1 and line != numRows and  b*(2*numRows-2)+ 2*numRows - line < len(s) + 1:
#                    re = re + s[b*(2*numRows-2)+ 2*numRows - line-1];
#        return re;
#
#s = Solution();
#print s.convert("PAYPALISHIRING",3);
#                    
#        

s=Solution();
print s.convert("PAYPALISHIRING",3);
