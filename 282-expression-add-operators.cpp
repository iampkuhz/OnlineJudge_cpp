/*
 * 282-expression-add-operators.cpp
 * Given a string that contains only digits 0-9 and a target value,
 * return all possibilities to add binary operators (not unary) +, -,
 * or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
 *  Created on: Nov 26, 2015
 *      Author: hanzhe
 */
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:

    vector<string> addOperators(string num, int target) {
    	vector<string> re;
    	if(num.size() < 1)
    		return re;
    	string op(1, num[0]);
    	calcu(re, num.substr(1, num.size()-1), op, target, num[0]-'0', num[0]-'0');
    }

    void calcu(vector<string> & re, string num, string op, int target, int tRe, int lastInt){
    	if(num.size() == 0){
    		if(target == tRe)
    			re.push_back(op);
    		return;
    	}
    	for(int i = 1 ; i < num.length(); i ++){
    		string nNum = num.substr(0, i);
    	}
    }


//    第二种方法， 效率没有明显提升， 不能传stack参数，太慢
//	int t;
//    vector<string> addOperators(string num, int target) {
//    	vector<string> re;
//    	if(num.length() < 1)
//    		return re;
//    	t = target;
//    	string tStr(1,num[0]);
//    	stack<int> nbs;
//    	stack<char> sym;
//    	getAll2(re, num, tStr, 1, nbs, sym, num[0]-'0');
//    	return re;
//    }
//    void getAll2(vector<string> &re, string &num, string tStr, int numInd,
//    		stack<int> nbs, stack<char> sym, int nb){
//    	if(numInd == num.length()){
//    		int tt = 0;
//    		if(sym.size()>0 && sym.top() == '*'){
//    			nb *= nbs.top();
//    			nbs.pop();
//    			sym.pop();
//    		}
//    		while(sym.size()>0){
//    			nb = sym.top() == '-' ? -nb : nb;
//    			tt += nb;
//    			sym.pop();
//    			nb = nbs.top();
//    			nbs.pop();
//    		}
//    		tt += nb;
//    		if(tt == t)
//    			re.push_back(tStr);
//    		return;
//    	}
//    	if(!(num[numInd-1] == '0' && num[numInd] >= '0' && num[numInd] <= '9'))
//    		getAll2(re, num, tStr + num[numInd], numInd+1, nbs, sym, nb * 10 + num[numInd] - '0');
//    	if(numInd > 0){
//    		if(sym.size()>0 && sym.top() == '*'){
//    			nb = nbs.top() * nb;
//    			nbs.pop();
//    			sym.pop();
//    		}
//    		nbs.push(nb);
//    		nb = num[numInd] - '0';
//    		sym.push('*');
//        	getAll2(re, num, tStr + "*" + num[numInd], numInd+1, nbs, sym, nb);
//        	sym.pop();
//
//        	while(sym.size() > 0){
//        		int top = nbs.top();
//        		nbs.pop();
//        		int top2 = nbs.top();
//        		nbs.pop();
//        		char op = sym.top();
//        		sym.pop();
//        		switch(op){
//        		case '-':
//        			top = top2 - top;
//        			break;
//        		case '+' :
//        			top = top2 + top;
//        			break;
//        		case '*' :
//        			top = top2 * top;
//        		}
//        		nbs.push(top);
//        	}
//    		sym.push('+');
//        	getAll2(re, num, tStr + "+" + num[numInd], numInd+1, nbs, sym, nb);
//    		sym.pop();
//    		sym.push('-');
//        	getAll2(re, num, tStr + "-" + num[numInd], numInd+1, nbs, sym, nb);
//    		sym.pop();
//    	}
//    }


// 第一种方法：先求出所有可能情况，再算排列， 超时 O（4^n）复杂度
//    vector<string> addOperators(string num, int target) {
//        // 1. 生成所有的代码
//    	vector<string> expr;
//    	string e(1, num[0]);
//    	getAll(expr, num, e, 1);
////    	cout << "expSize:" << expr.size() << endl;
//    	// 2. 对每个公式计算结果
//    	vector<string> re;
//
//    	for(int i = 0; i < expr.size(); i ++)
//    		if(getExpRe(expr[i]) == target)
//    			re.push_back(expr[i]);
//    	return re;
//    }
//    int getExpRe(string & exp){
//    	int re = 0;
//    	stack<char> sym;
//    	stack<int> nbs;
//    	int nb = 0;
//    	for(int i = 0 ; i < exp.size(); i ++){
//    		if(exp[i] == '-' || exp[i] == '+' || exp[i] == '*'){
//    			if(sym.size() > 0 && sym.top() == '*'){
//    				nb = nb * nbs.top();
//    				nbs.pop();
//    				sym.pop();
//    			}
//    			nbs.push(nb);
//    			sym.push(exp[i]);
//    			nb = 0;
//    		}
//    		else{
//    			nb = nb * 10 + exp[i] - '0';
//    		}
//    	}
//    	if(sym.size()>0 && sym.top() == '*'){
//    		nb = nbs.top() * nb;
//    		sym.pop();
//    		nbs.pop();
//    	}
//    	while(sym.size() > 0){
//    		nb = sym.top() == '-' ? -nb : nb;
//    		re += nb;
//    		nb = nbs.top();
//    		nbs.pop();
//    		sym.pop();
//    	}
//    	re += nb;
////    	cout << exp << " " << re << endl;
//    	return re;
//    }
//
//    void getAll(vector<string> &re, string &num, string tStr, int numInd){
//    	if(numInd == num.length()){
//    		re.push_back(tStr);
//    		return;
//    	}
//    	if(!(num[numInd-1] == '0' && num[numInd] >= '0' && num[numInd] <= '9'))
//    		getAll(re, num, tStr + num[numInd], numInd+1);
//    	if(numInd > 0){
//        	getAll(re, num, tStr + "+" + num[numInd], numInd+1);
//        	getAll(re, num, tStr + "-" + num[numInd], numInd+1);
//        	getAll(re, num, tStr + "*" + num[numInd], numInd+1);
//    	}
//    }

    void test(){
    	Solution * s= new Solution();
    	vector<string> re = s->addOperators("123", 6);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    	re = s->addOperators("232", 8);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    	re = s->addOperators("105", 5);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    	re = s->addOperators("00", 0);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    	re = s->addOperators("3456237490", 9191);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    	re = s->addOperators("999999999", 81);
    	cout << "[";
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << ", ";
    	cout << "]" << endl;

    }
};


