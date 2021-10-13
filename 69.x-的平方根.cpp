/*
 * @Author: your name
 * @Date: 2021-05-17 23:27:16
 * @LastEditTime: 2021-05-17 23:41:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Ed
 * @FilePath: \project\Leetcode\69.x-的平方根.cpp
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return x;
        int l = 1, r = x, mid, sqrt;
        while (l <= r) {
            mid = 1 + (r - 1) / 2;
            sqrt =  x / mid;
            if (sqrt == mid) {
                return mid;
            } else if (mid > sqrt) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

    }
};
// @lc code=end

