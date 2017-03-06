/*
 *Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

#include <memory.h>
#include <string>

using namespace std;
/*
 * 看答案
 */
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bs;
        for(char c:s)
            bs.flip(c);
        return bs.count() < 2;
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool cnt[300];
        memset(cnt, 0, sizeof(bool) * 300);
        for(int i = 0 ; i < s.length(); i ++)
            cnt[s[i]] = !cnt[s[i]];
        int c1 = 0;
        for(int i = 0 ; i< 300; i ++)
            if(cnt[i]){
                c1 ++;
                if(c1 > 1)
                    return false;
        }
        return true;
    }
};
