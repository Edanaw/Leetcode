/*
 * @Author: your name
 * @Date: 2021-05-01 23:56:56
 * @LastEditTime: 2021-05-02 00:49:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\5.最长回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

/*


   0  1  2  3  4
0  T
1     T
2        T 
3           T
4              T
动态规划的方法：空间换时间的算法

状态转移方程： dp[i][j] = (s[i] == s[j])
and (j - i < 3 or dp[i+1][j-1])

j - 1 - (i + 1) + 1 < 2
j - i < 3

*/

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        
        int maxlen = 1;
        int begin = 0;
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (size_t i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        
        for (int j = 1; j < n; ++j)  {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxlen);
    }
};
// @lc code=end

