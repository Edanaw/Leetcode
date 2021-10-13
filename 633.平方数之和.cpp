/*
 * @Author: your name
 * @Date: 2021-05-02 21:26:42
 * @LastEditTime: 2021-05-02 21:43:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit 
 * @FilePath: \project\Leetcode\633.平方数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        // 使用sqrt函数
        // for (long a = 0; a * a <= c; ++a) {
        //     double b = sqrt(c - a * a);
        //     if (b == (int)b) {
        //         return true;
        //     }
        // }        

        // 使用双指针
        long left = 0;
        long right = (int)sqrt(c);
        
        while (left <= right) {
            int sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                right--; 
            } else {
                left++;
            }
        }

        return false;
    }
};
// @lc code=end

