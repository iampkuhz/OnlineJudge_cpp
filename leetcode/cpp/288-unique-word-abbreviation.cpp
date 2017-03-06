/*
 * 判断缩写有没有重复
 * 看答案，没理解题意，unordered_map 可以直接插入，默认初始化？：q
 *Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

class ValidWordAbbr {
    unordered_map<string, unordered_set<string> > abbs;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s: dictionary){
            string word = s;
            if(s.length() > 2)
                s = (s[0] + to_string(s.length()-2) + s[s.length()-1]);
            abbs[s].insert(word);
        }
    }

    bool isUnique(string word) {
        int sz = word.length();
        string w = word;
        if(sz > 2)
            word = word[0] + to_string(sz-2) + word[sz-1];
        return abbs.find(word) == abbs.end() || abbs[word].count(w) == abbs[word].size();
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
