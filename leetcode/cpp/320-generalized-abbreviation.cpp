/*
 *Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
 * 看答案,2次过，方法好！
 */
class Solution {
    vector<string> re;
    int len;
public:
    vector<string> generateAbbreviations(string word) {
        len = word.length();
        dfs(word, "", 0);
        return re;
    }
    void dfs(string & word, string abbr, int ind){
        if(ind >= len){
            re.push_back(abbr);
            return;
        }
        dfs(word, abbr + word[ind], ind+1);
        for(int i = ind+1; i < len; i ++)
            dfs(word, abbr + to_string(i-ind) + word[i], i+1);
        dfs(word, abbr + to_string(len-ind), len);
    }
};


/*
 * 5次过，速度超级慢
 */
class Solution {
    int len;
    string word;
public:
    vector<string> generateAbbreviations(string word) {
        len = word.length();
        vector<string> re;
        if(len == 0) {
            re.push_back("");
            return re;
        }
        this->word = word;
        vector<string> tnc = getNumCnt(0, len-1);
        vector<string> tcc = getCharCnt(0, len-1);
        tnc.insert(tnc.end(), tcc.begin(), tcc.end());
        return tnc;
    }

    vector<string> getCharCnt(int a, int b){
        vector<string> re;
        string cs(1,word[a]);
        if(a == b){
            re.push_back(cs);
            return re;
        }
            vector<string> cc = getCharCnt(a+1,b);
            for(string s1:cc)
                re.push_back(cs + s1);
            vector<string> tc  = getNumCnt(a+1,b);
            for(string s1:tc)
                re.push_back(cs + s1);
        return re;
    }

    vector<string> getNumCnt(int a, int b){
        vector<string> re;
        for(int i = a+1; i <= b; i ++){
            vector<string> tcc = getCharCnt(i, b);
            for(string s1: tcc)
                re.push_back(to_string(i-a) + s1);
        }
        re.push_back(to_string(b-a+1));
        return re;
    }

    void test(){
        //vector<string> re = generateAbbreviations("accumulation");
        vector<string> re = generateAbbreviations("accu");
        for(int i = 0; i < re.size(); i ++)
            cout << re[i] << endl;

    }
};

