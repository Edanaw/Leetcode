/*
 * @Author: your name
 * @Date: 2021-05-02 19:48:33
 * @LastEditTime: 2021-05-02 21:25:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\76.最小覆盖子串.cpp
 */
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

/*
    TODO: 思考滑动窗口方法确定区间子字符串
*/

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);

        // 统计T中的字符的情况
        for (int i = 0; i < t.size(); ++i) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        // 移动滑动窗口，不断更新统计数据
        int cnt = 0;
        int l = 0;
        int min_l = 0;
        int min_size = s.size() + 1;

        for (int r = 0; r < s.size(); ++r) {
            if (flag[s[r]]) {
                if (--chars[s[r]] >= 0) {
                    ++cnt;
                }
                // 若滑动窗口已经包含T中全部的字符
                // 尝试将l右移，在不影响结果的情况下获得最短字符串
                while (cnt == t.size()) {
                    if (r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }

                    if (flag[s[l]] && ++chars[s[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
    
};


// @lc code=end

