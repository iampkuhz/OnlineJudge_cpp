/*
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int sz = words.size();
        int re = sz+1;
        for(auto ele = words.begin(); ele!= words.end(); ele++){
            if((*ele).compare(word1) == 0) pos1 = ele - words.begin();
            else if((*ele).compare(word2) == 0) pos2 = ele - words.begin();
            else continue;
            if(pos1 >= 0 && pos2 >= 0 && abs(pos1 - pos2) < re)
                re = abs(pos1 - pos2);
        }
        return re;
    }
};
