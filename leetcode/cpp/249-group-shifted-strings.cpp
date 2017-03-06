/*
 * 2次过，记得2次排序：插入re之前排序（内部vector排序），全部插入完排序vector之间按照第一个单词排序
 *
 * 将属于同一格式的字符串组合起来
 * "abc" -> "bcd" -> ... -> "xyz"
 * */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<string> > m;
    string stdForm(string str){
        string re = str;
        int ad = 'z' - str[0] + 1;
        for(int i = 0  ; i < re.length(); i ++)
            re[i] = (re[i] - 'a' + ad)% 26 + 'a';
        return re;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> re;
        int sz = strings.size();
        for(int i = 0 ; i < sz; i ++){
            string s2 = stdForm(strings[i]);
            if(m.find(s2) == m.end()){
                vector<string> vt;
                m[s2] = vt;
            }
            m[s2].push_back(strings[i]);
        }
        for(auto i = m.begin(); i != m.end(); i ++){
            sort(i->second.begin(), i->second.end());
            re.push_back(i->second);
        }
        sort(re.begin(), re.end());
        return re;
    }
};
