/*
 * @Author: your name
 * @Date: 2021-05-04 20:15:38
 * @LastEditTime: 2021-05-07 00:46:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\695.岛屿的最大面积.cpp
 */
/*
    深度优先搜索(DFS): 可以用来检测环路: 记录每个遍历过的节点的父节点，若一个节点
    被再次遍历且父亲节点不同的话，说明又环路。拓扑排序也可以用来检测是否有环路，如最后
    存在出度部位0的点，则说明有环。

    有时候需要对已经搜索过的节点进行标记，以防止在遍历的时候重复搜索某个节点，这种做法叫做
    状态记录或记忆化。

    深度有限搜索分为： 主函数和辅助函数

    主函数：用于遍历所有的搜索位置，判断是否可以开始搜索，如果可以即在辅助函数进行搜索，辅助函数
    负责深度优先搜索的递归调用。当然，我们也可以使用stack实现深度优先搜索，但是因为stack和递归调用的
    的原理先沟通，递归相对实现方便
    

*/
// #include <vector>
// #include <stack>

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         vector<int> direction{-1, 0, 1, 0, -1};
//         // row
//         int m = grid.size();
//         // col
//         int n = m ? grid[0].size() : 0;
//         int local_area;
//         int area = 0;
//         int x, y;

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j]) {
//                     local_area = 1;
//                     grid[i][j] = 0;
//                     stack<pair<int, int>> island;
//                     island.push({i, j});
                    
//                     while (!island.empty()) {
//                         auto [r, c] =  island.top();
//                         island.pop();
//                         for (int k = 0; k < 4; ++k) {
//                             x = r + direction[k];
//                             y = c + direction[k + 1];
//                             if (x >= 0 && x < m && y >= 0 && y < n
//                                 && grid[x][y] == 1) {
//                                 grid[x][y] = 0;
//                                 ++local_area;
//                                 island.push({x, y});
//                             }
//                         }
//                     }
//                     area = max(area, local_area);
//                 }
//             }
//         }
//         return area;
//     }
// };

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() ||
            cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index < 4; ++index) {
            int next_i = cur_i + di[index];
            int next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};