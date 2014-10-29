/*
 * ImplementstrStr.cpp
 *
 *  Created on: 2014年10月28日
 *      Author: hanzhe
 */
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	if(haystack == NULL || needle == NULL)
    		return NULL;
    	// KMP
    	int lenN = strlen(needle);
    	//cout << "result:" << haystack << endl;
    	if(lenN == 0)
    		return haystack;
    	if(strlen(haystack) == 0)
    		return NULL;
    	//cout << "result:" << haystack << endl;
    	int * Next = new int[lenN];
    	memset(Next, -1, sizeof(int)* lenN);
    	for(int i = 1 ; i < lenN; i ++)
    	{
    		int bef = Next[i-1];
    		while(bef >= 0)
    		{
    			if(needle[bef] == needle[i-1])
    			{
    				Next[i] = bef + 1;
    				break;
    			}
    			else bef = Next[bef];
    		}
    		if(bef < 0)
    			Next[i] = 0;
			//cout << Next[i] << " ";
    	}//cout << endl;
    	char * pt = haystack;
    	char * ptN = needle;
    	int jump = 0;
    	while(true)
    	{
    		//cout << pt << " " << ptN << endl;
    		if(*ptN == '\0')
    			return pt - lenN;
    		if(*pt == '\0')
    			return NULL;
    		if(*pt == * ptN)
    		{
    			pt ++;
    			ptN ++;
    		}
    		else{
    			if(ptN == needle)
    				pt ++;
    			else ptN = needle + Next[ptN - needle];
    		}
    	}
    }
    int GetSim(char * s1, char * s2)
    {
    	int result = 0;
    	char * p1 = s1, * p2 = s2;
    	while(*p1 != '\0' && *p2 != '\0'
    			&& *p1 == *p2)
    	{
    		result ++;
    		p1 ++;
    		p2 ++;
    	}
    	return result;
    }
    void test()
    {
    	char * h = "mississippi";
    	char * n = "issip";
    	char * result = strStr(h, n);
    	if(result == NULL)
    		cout << "NULL" << endl;
    	else cout << "OL:" << result << endl;
    }


};
