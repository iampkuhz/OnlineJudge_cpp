/*
 * 插入一些数，问是否存在2个数和为v？
 * 网上用unordered_multiset最快
 */


/*
 * 看了网上答案，关键在add操作一定要快
 */
class TwoSum {
    vector<int> v;
    unordered_map<int, int> vs;
    bool st = true;
public:

    // Add the number to an internal data structure.
	void add(int number) {
        v.push_back(number);
        vs[number] ++;
        st = false;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
        for(int i = v.size()-1; i >= 0; i --)
            if(vs.find(value-v[i]) != vs.end()){
                if(value != 2*v[i] || vs[value-v[i]] > 1)
                    return true;
            }
        return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
/*
 * O(1)插入 + O（nlogn+n)查找超时, 有样例是好几万个数，把2个数的和插入hashset估计内存不够
 * 100 find + 20000 add
 */
class TwoSum {
    vector<int> v;
    bool st = true;
public:

    // Add the number to an internal data structure.
	void add(int number) {
        v.push_back(number);
        st = false;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
        if(!st){
            sort(v.begin(), v.end());
            st = true;
        }
        int l = 0, r = v.size()-1;
        while(l < r){
            int sum = v[l] + v[r];
            if(sum == value) return true;
            else if(sum > value) r --;
            else l ++;
        }
        return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
