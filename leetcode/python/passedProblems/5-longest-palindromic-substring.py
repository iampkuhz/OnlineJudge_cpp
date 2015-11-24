#-*-coding:utf-8-*-2:wq
# Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = '$#' + '#'.join(s) + "#_";
        p = [0] * 4210;
        mxRight = 0;
        id = 0;

        # calculate p array
        reInd = 0;
        for i in range(len(t)):
            p[i] = mxRight > i and min(p[2*id-i], mxRight-i) or 1;
            while (i-p[i] >= 0 and i+p[i] < len(t) and t[i-p[i]] == t[i+p[i]]):
                p[i] += 1;
            if(i + p[i] > mxRight):
                mxRight = i + p[i];
                id = i;
            if p[reInd] < p[i]:
                reInd = i;
#                print t[i-p[i]+1:i+p[i]];
        return s[reInd//2 - p[reInd]//2: reInd//2 + (p[reInd]-1)//2]



# 采用二维数组保存回文串, 仍然超时
#class Solution(object):
#    def longestPalindrome(self, s):
#        """
#        :type s: str
#        :rtype: str
#        """
#        fitI = 0;
#        fitSize = 1;
#        size = 1;
#        pal = [[ 0 for c in range(1000)]  for r in range(1000)]
#        for i in range(len(s)):
#            pal[i][i] = 1;
#        lastCnt = 1;
#        cntSize = [0 for c in range(1005)]
#        cntSize[0] = len(s);
#        cntSize[1] = len(s);
#        for size in range(2, len(s)):
#            if cntSize[size-2] == 0:
#                break;
#            for i in range(0, len(s)-size):
#                if(s[i] == s[i+size-1] and ( size == 2 or pal[i+1][i+size-2] == 1)):
#                    cntSize[size] += 1;
#                    pal[i][i+size-1]=1;
#                    fitI = i;
#                    fitSize = size;
##                    print size, ",", s[fitI:fitI+size];
#            if cntSize[size] == 0 and cntSize[size-1] == 0:
#                break;
#            
#
#        return s[fitI:fitI + fitSize];



# 采用字典保存回文字串,但是超时, 果然字典还是比较慢的
#class Solution(object):
#    def longestPalindrome(self, s):
#        """
#        :type s: str
#        :rtype: str
#        """
#        lenS = len(s);
#        palDict = {};
#        fitI = 0;
#        size = 1;
#        for i in range(len(s)):
#            palDict[self.encode(i,i)]=1;
#            if i > 0 and s[i] == s[i-1]:
#                palDict[self.encode(i-1,i)]=1;
#                size = 2;
#                fitI = i-1;
#        for size in range(3, len(s)):
#            cnt = 0;
#            for i in range(0, len(s)-size):
#                if(s[i] == s[i+size-1] and palDict.has_key(self.encode(i+1, i+size-2))):
#                    cnt += 1;
#                    palDict[self.encode(i,i+size-1)]=1;
#                    fitI = i;
#            if cnt == 1:
#                return s[fitI:fitI+size-1];
#            elif cnt == 0:
#                break;
#        return s[fitI:fitI+size-1];
#        
#    def encode(self, i, j):
#        return i* 1000 + j;
#        

s = Solution();
print s.longestPalindrome("abcasebcecdabcabascb");
print s.longestPalindrome("rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip");
#print s.longestPalindrome("iopsajhffgvrnyitusobwcxgwlwniqchfnssqttdrnqqcsrigjsxkzcmuoiyxzerakhmexuyeuhjfobrmkoqdljrlojjjysfdslyvckxhuleagmxnzvikfitmkfhevfesnwltekstsueefbrddxrmxokpaxsenwlgytdaexgfwtneurhxvjvpsliepgvspdchmhggybwupiqaqlhjjrildjuewkdxbcpsbjtsevkppvgilrlspejqvzpfeorjmrbdppovvpzxcytscycgwsbnmspihzldjdgilnrlmhaswqaqbecmaocesnpqaotamwofyyfsbmxidowusogmylhlhxftnrmhtnnljjhhcfvywsqimqxqobfsageysonuoagmmviozeouutsiecitrmkypwknorjjiaasxfhsftypspwhvqovmwkjuehujofiabznpipidhfxpoustquzyfurkcgmioxacleqdxgrxbldcuxzgbcazgfismcgmgtjuwchymkzoiqhzaqrtiykdkydgvuaqkllbsactntexcybbjaxlfhyvbxieelstduqzfkoceqzgncvexklahxjnvtyqcjtbfanzgpdmucjlqpiolklmjxnscjcyiybdkgitxnuvtmoypcdldrvalxcxalpwumfx");
