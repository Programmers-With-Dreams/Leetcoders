/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int begin = 0, end = people.size() - 1, count = 0;
        while (begin <= end){
            if (people.at(end) + people.at(begin) <= limit){ ++begin; } 
            --end; ++count;
        }
        return count;
    }
};
// @lc code=end