/*
 * @Author: your name
 * @Date: 2021-04-27 23:26:56
 * @LastEditTime: 2021-04-28 00:47:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, start = -1;
        vector<int> cmp(256, -1);
        
        for (int i = 0; i != s.length(); ++i) {
            if (cmp[s[i]] > start) {
                /*
                    重复字符不进行计数操作
                */
                start = cmp[s[i]];
            }
            cmp[s[i]] = i;
            maxlen = max(maxlen, i - start);
        }

        return maxlen;
    }
};
// @lc code=end

