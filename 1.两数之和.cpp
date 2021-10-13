/*
 * @Author: your name
 * @Date: 2021-02-09 00:05:14
 * @LastEditTime: 2021-05-01 23:36:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (50.09%)
 * Likes:    10251
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * -10^9 
 * -10^9 
 * 只会存在一个有效答案
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;


// 1. 使用unordered_map容器的hash存储去判断是否存在
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};


// 2. 采用双指针的方法 只适用于有序的数组
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int counts = nums.size();
//         int l = 0, r = counts - 1, sum;
        
//         while (l < r) {
//             sum = nums[l] + nums[r];
//             if (sum == target) break;
//             if (sum < target) {
//                 ++l;
//             } else {
//                 --r;
//             }
//         }
//         return vector<int>{l, r};
//     }
// };


/*
    key value
    2   0
    7   1
    9   2
    11  3
    

*/

// @lc code=end

