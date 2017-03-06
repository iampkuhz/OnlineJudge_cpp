/*
 * 给定一些单词的排序后vector，找出其中字符的偏序关系
 *
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

 */

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char> > c2next;
        unordered_map<char, int> c2precnt;
        // 1. insert
        int sz = words.size();
        for(int i = 0 ; i < sz; i ++){
            for(char c:words[i]){
                if(c2precnt.find(c) == c2precnt.end())
                    c2precnt[c] = 0;
                if(c2next.find(c) == c2next.end()){
                    unordered_set<char> us;
                    c2next[c] = us;
                }
            }
            if(i > 0){
                for(int j = 0 ; j < min(words[i].length(), words[i-1].length()); j ++)
                    if(words[i][j] != words[i-1][j] && c2next[words[i-1][j]].find(words[i][j]) == c2next[words[i-1][j]].end()){
                        c2next[words[i-1][j]].insert(words[i][j]);
                        c2precnt[words[i][j]] ++;
                        break;
                    }
            }
        }
        queue<char> qc;
        string re;
        // for(auto p : c2precnt)
        //     cout << p.first <<" "<<p.second << endl;
        for(auto p : c2precnt)
            if(p.second == 0){
                qc.push(p.first);
            }
        while(!qc.empty()){
            char c = qc.front();
            c2precnt.erase(c);
            qc.pop();
            re += c;
            for(auto c2 : c2next[c]){
                c2precnt[c2] --;
                if(c2precnt[c2] == 0)
                    qc.push(c2);
            }
        }
        // for(auto p : c2precnt)
        //     cout << p.first <<" "<<p.second << endl;
        if(!c2precnt.empty())
            return "";
        return re;
    }
};
