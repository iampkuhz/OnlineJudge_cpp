"""

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
"""

# 原来的hash方法已经不能过代码了
#class Solution(object):
#    def findSubstring(self, s, words):
#        """
#        :type s: str
#        :type words: List[str]
#        :rtype: List[int]
#        """
#        word, wordNum, wordLen, = {}, len(words), len(words[0]);
#        wordSet = set(words);
#        sumHash = sum([hash(i) for i in words]);
#        h=[hash(s[i:i+wordLen]) if s[i:i+wordLen] in wordSet else 0 for i in xrange(len(s)-wordLen+1)];
#        print 'h:',h;
#        print 'sumhash:',sumHash;
#        print 'hash:',[hash(i) for i in words];
#        #return [ sum(h[i:i+wordNum*wordLen:wordLen]) for i in xrange(len(s)-wordNum*wordLen+1)];
#        return [ i for i in xrange(len(s)-wordNum*wordLen+1) if sum(h[i:i+wordNum*wordLen:wordLen])== sumHash];
    
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        word={}
        wordNum = len(words);
        wordL = len(words[0]);
        for i in words:
            if i not in word:
                word[i] = 1;
            else:
                word[i] += 1;
        re=[];
        for i in range(0, len(s)-wordL*wordNum+1):
            cur = {};j=0;
            while j < wordNum:
                Str = s[i+j*wordL:i+(j+1)*wordL];
                if Str not in word:
                    break;
                if Str not in cur:
                    cur[Str]=1;
                else:
                    cur[Str] += 1;
                if cur[Str] > word[Str]:
                    break;
                j += 1;
            if j == wordNum:
                re.append(i);
        return re;

s=Solution();
print s.findSubstring("barfoothefoobarman", ["foo","bar"]);
print s.findSubstring("bbabbbab"
,["ab","bb","bc","ac"]);
print s.findSubstring("wordgoodgoodgoodbestword"
,["word","good","best","good"]);


        
