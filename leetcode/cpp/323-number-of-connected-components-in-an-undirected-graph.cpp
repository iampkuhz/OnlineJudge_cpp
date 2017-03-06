/*
 *Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * 并查集！！看答案,4次过。看别人的答案就容易抄变量，结果编译错误
 */
#include <numeric>

class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        vector<int> comp(n);
        iota(comp.begin(), comp.end(), 0);
        int re = n;
        for(int i = 0  ; i < edges.size(); i ++){
            int t = edges[i].first, w = edges[i].second;
            while(comp[t] != t) t = comp[t] = comp[comp[t]];
            while(comp[w] != w) w = comp[w] = comp[comp[w]];
            re -= (t != w);
            if(t != w) comp[w] = t;
        }
        return re;
    }
};

/*
 * 1次过，(感觉不可思议，应该会有一点错误的吧？）
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        unordered_map<int,unordered_set<int> > nbs;
        unordered_set<int> ids;
        for(int i = 0 ; i < n; i++){
            ids.insert(i);
            unordered_set<int> us;
            nbs[i] = us;
        }
        for(pair<int, int> p:edges){
            nbs[p.first].insert(p.second);
            nbs[p.second].insert(p.first);
        }
        int c = 0;
        while(!ids.empty()){
            c ++;
            int id = *ids.begin();
            ids.erase(id);
            // 删除相关边
            vector<int> cn;
            cn.push_back(id);
            while(cn.size() > 0){
                int id = cn.back();
                cn.pop_back();
                unordered_set<int> us = nbs[id];
                for(auto it = us.begin(); it != us.end(); it ++)
                    if(ids.find(*it)!= ids.end() ){
                        ids.erase(*it);
                        cn.push_back(*it);
                    }
            }
        }
        return c;



    }
};
