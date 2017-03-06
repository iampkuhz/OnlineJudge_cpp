/*
 *Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Show Hint
Show Tags
Hide Similar Problems
*/
/*
 * 其实本来是对的，但是leetcode 计算`if((pc++)>1) return re`特别慢，所以改成`pc++;if(pc>1) return re`,这样原来的就可以过！！！！
 *
 * 提交了很多次（～20），很多小bug，最后超时！！
 */

/*
 * 看答案的，调用系统的`next_perutation(str.begin(),str.end())`
 */

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> palindromes;
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        int odd = 0; char mid; string half;
        for (auto p : counts) {
            if (p.second & 1) {
                odd++, mid = p.first;
                if (odd > 1) return palindromes;
            }
            half += string(p.second / 2, p.first);
        }
        palindromes = permutations(half);
        for (string& p : palindromes) {
            string t(p);
            reverse(t.begin(), t.end());
            if (odd) t = mid + t;
            p += t;
        }
        return palindromes;
    }
private:
    vector<string> permutations(string& s) {
        vector<string> perms;
        string t(s);
        do {
            perms.push_back(s);
            next_permutation(s.begin(), s.end());
        } while (s != t);
        return perms;
    }
};
/*
 * 原来的自己写的
 */
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> re;
        int sz = s.length();
        if(sz == 0) return re;
        // 1.check
        map<char, int> ccnt;
        for(char c:s)
            ccnt[c] ++;
        int pc = 0;
        char unic = ' ';
        vector<char> vc;
        for(auto i=ccnt.begin(); i != ccnt.end(); i ++){
            if(i->second %2 == 1){
                pc ++;
                if(pc > 1) return re;
                unic = i->first;
            }
            for(int j = 0 ; j < i->second/2; j ++)
                vc.push_back(i->first);
        }
        sort(vc.begin(), vc.end());
        string ps(vc.begin(), vc.end());
        cout << ps << endl;
        string tps = ps;
        while(true){
            string nps_rev = ps;
            reverse(nps_rev.begin(), nps_rev.end());
            if(pc == 1)
                nps_rev = ps + unic + nps_rev;
            else nps_rev = ps + nps_rev;
            // cout << ps << " " << nps_rev <<endl;
            re.push_back(nps_rev);
            ps = getN(ps);
            if(ps == "") break;
        }
        return re;
    }
    string getN(string ps){
        string re = ps;
        int sz = ps.length();
        int i = sz-2;
        while(i >= 0 && ps[i] >= ps[i+1]) i --;
        if(i < 0)
            return "";
        int j = i + 1;
        while(j+1 < sz && ps[j+1] > ps[i]) j ++;
        re[i] = ps[j];
        ps[j] = ps[i];
        for(int k = i + 1; k < sz; k ++)
            re[k] = ps[sz + i - k];
        return re;
    }
};
