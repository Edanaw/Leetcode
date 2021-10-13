/*
 * @Author: your name
 * @Date: 2021-05-01 15:36:41
 * @LastEditTime: 2021-05-01 17:17:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\448.找到所有数组中消失的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start

/*          0 1 2 3 4 5 6 7
[value   ]  4 3 2 7 8 2 3 1
[value - 1] 3 2 1 6 7 1 2 0
                    
    0 4 -4 
    1 3 -3
    2 2 -2
    3 7 -7
    4 8  8
    5 2  2
    6 3 -3
    7 1 -1


*/
// 通过下标确定  数字是否出现过
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] > 0) {
                res.push_back(j + 1);
            }
        }

        return res;
    }
};
// @lc code=end

