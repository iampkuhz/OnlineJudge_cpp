/*
 * SimplifyPath.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	int lastE = 0;
    	vector<string> vs;
        for(int i = 0; i < path.size(); i ++)
        	if(path[i] == '/'){
        		string w = path.substr(lastE, i - lastE + 1);
            	AddWord(w, vs);
        		lastE = i + 1;
        	}
        if(lastE < path.size()){
        	string w = path.substr(lastE, path.size() - lastE);
        	AddWord(w + "/", vs);
        }
        string re = "";
        for(int i = 0 ; i < vs.size(); i ++)
        	re += vs[i];
        if(re.size() > 0 && re[re.size() - 1] == '/')
        	re = re.substr(0, re.size() - 1);
        return "/" + re;
    }
    void AddWord(string w, vector<string> & vs)
    {
    	if(w == "../"){
    		if(vs.size() > 0)
    			vs.pop_back();
    	}
		else if(w == "./"){}
		else if(w == "/"){}
		else vs.push_back(w);
    }

    void test()
    {
    	cout << simplifyPath("/home/") << endl;
    	cout << simplifyPath("/a/./b/../../c/") << endl;
    	cout << simplifyPath("//home//foo//") << endl;
    	cout << simplifyPath("/../") << endl;
    	cout << simplifyPath("/.") << endl;
    }
};



