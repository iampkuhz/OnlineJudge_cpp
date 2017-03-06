/*
 *This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 * 1次过，简单
 */
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        bool dup = (word1 == word2) ? true: false;
        int sz = words.size();
        if(sz == 0) return 0;
        int p1 = -1, p2 = -1, minLen = sz;
        for(int i = 0 ; i < sz; i ++){
            if(words[i] == word1){
                if(dup){
                    p2 = p1;
                    p1 = i;
                }
                else p1 = i;
            }
            else if(words[i] == word2) p2 = i;
            else continue;
            if(p1 >= 0 && p2 >= 0 && abs(p1-p2) < minLen)
                minLen = abs(p1-p2);
        }
        return minLen;

    }
};
