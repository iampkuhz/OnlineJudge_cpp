/*
 * 看答案，3次过，非常精妙！
 * encode vector<string> to string
 * codec.decode(codec.encode(strs));
 */

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string re;
        for(int i = 0  ; i < strs.size(); i ++)
            re += to_string(strs[i].size()) + "#" + strs[i];
        return re;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> re;
        int pos = 0;
        while(s.length()> 0){
            pos = s.find_first_of("#");
            int tsz = stoi(s.substr(0, pos+1));
            re.push_back(s.substr(pos+1,tsz));
            s = s.substr(pos+1+tsz);
        }
        return re;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
