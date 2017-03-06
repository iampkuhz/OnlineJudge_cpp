/*
 *You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/
#include <string>
using namespace std;

/*
 * 看答案,1次过
 */
class Solution {
    string str;
    int len;
public:
    bool canWin(string s) {
        len = s.length();
        str = s;
        return canWin();
    }
    bool canWin(){
        for(int i = 0 ; i < len-1; i ++){
            if(str[i] == '+' && str[i+1] == '+'){
                str[i] = str[i+1] = '-';
                bool tre = !canWin();
                str[i] = str[i+1] = '+';
                if(tre) return true;
            }
        }
        return false;
    }
};
