/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int begin = 0, end = 0, size = s.size(), count = 0;
        for (; end < k; ++end) {
            char temp = s.at(end);
            switch (s.at(end)) {
                case 'a': case 'e' : case 'i' : case 'o' : case 'u' : ++count;
                default: break;
            }
        }
        int maxCount = count;
        while (end < size) {
            switch (s.at(end++)) {
                case 'a': case 'e' : case 'i' : case 'o' : case 'u' : ++count;
                default: break;
            }
            switch (s.at(begin++)) {
                case 'a': case 'e' : case 'i' : case 'o' : case 'u' : --count;
                default: break;
            }
            if (maxCount < count) { maxCount = count; }
        }
        return maxCount;
    }
};
// @lc code=end

