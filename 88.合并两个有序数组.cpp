/*
 * @Author: your name
 * @Date: 2021-05-02 00:54:01
 * @LastEditTime: 2021-05-02 12:23:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\88.合并两个有序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 */

/*
    由于两个数组已经有序我们可以把指针放到两个数组的末尾
*/

// @lc code=start
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         // for (int i = 0; i != n; ++i) {
//         //     nums1[m + i] = nums2[i];
//         // }
//         // sort(nums1.begin(), nums1.end());

//         int p1 = 0, p2 = 0;
//         int sorted[m + n];
//         int cur;

//         while (p1 < m || p2 < n) {
//             if (p1 == m) cur = nums2[p2++];
//             if (p2 == n) cur = nums1[p1++];
//             if (nums1[p1] < nums2[p2]) {
//                 cur = nums1[p1++];
//             } else {
//                 cur = nums1[p2++];
//             }
//         }

//         for (int i = 0; i != m + n; ++i) {
//             nums1[i] = sorted[i];
//         }

//     }
// };

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};
// @lc code=end

