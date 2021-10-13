/*
 * @Author: your name
 * @Date: 2021-05-16 21:02:02
 * @LastEditTime: 2021-05-16 22:26:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\769.最多能完成排序的块.cpp
 */
/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = max(arr[i], cur_max);
            // 不重复的0 - n, 当前最大值一定不会小于数组位置
            if (cur_max == i) {
                ++chunks;
            }
        }

        return chunks;
    }
};
// @lc code=end

