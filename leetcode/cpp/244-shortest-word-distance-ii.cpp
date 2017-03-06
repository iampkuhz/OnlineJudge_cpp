/*
 * 找给定字符串数组中两个字符串的最近下标距离
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class WordDistance {
    unordered_map<string, vector<int> > w2inds;
    int sz;
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i ++){
            if(w2inds.find(words[i]) == w2inds.end()){
                vector<int> us;
                w2inds[words[i]] = us;
            }
            w2inds[words[i]].push_back(i);
        }
        sz = words.size();
    }

    int shortest(string word1, string word2) {
        vector<int> s1 = w2inds[word1], s2 = w2inds[word2];
        int re = sz, i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            int gap = abs(s1[i] - s2[j]);
            re = re < gap ? re : gap;
            if(s1[i] < s2[j]) i ++;
            else j ++;
        }
        return re;

    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
