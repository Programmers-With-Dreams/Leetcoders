/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start


#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string init;
        generateRec(init, n, n, 2 * n);
        return results;
    }
    
private:  
    vector<string> results;
    void generateRec(string &result, int numLOP, int numROP, int size){
        if(!size){ results.push_back(result); return; }
        if(numROP < numLOP) { return; }
        result.push_back(')'); generateRec(result, numLOP, --numROP, --size);
        ++numROP; ++size; result.pop_back();
        if(!numLOP){ return; }
        result.push_back('('); generateRec(result, --numLOP, numROP, --size);
        ++numLOP; ++size; result.pop_back();
    }
};
// @lc code=end

