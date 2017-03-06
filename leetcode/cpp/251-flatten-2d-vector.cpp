/**
 *
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Show Hint
*/
class Vector2D {
    int i = 0;
    vector<vector<int>>::iterator i1, iEnd;

public:
    Vector2D(vector<vector<int>>& vec2d){
        i1 = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i1)[i++];
    }

    bool hasNext() {
        while(i1 != iEnd && i>=(*i1).size())
            i1 ++, i = 0;
        return i1 != iEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
