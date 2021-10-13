/*
 * @Author: your name
 * @Date: 2021-05-02 12:24:47
 * @LastEditTime: 2021-05-02 21:26:15
 * @LastEditors: Please set LastEditors
//  * @Description: In User Settings Edit
 * @FilePath: \project\Leetcode\142.环形链表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

/*
    判断链表是否有环的方法：
    快慢指针： FLOYED判圈法，给定两个指针，分别命名为slow和fast，
    起始位置在链表的开头，每次fast前进两步，slow前进一步，如果
    fast可以走到尽头的话，那说明没有环路，如果fast可以无尽的走下去，
    那么说明一定有环路，且一定存在一个时刻slow和fast相遇。

    当slow和fast第一次相遇的时候，我们将fast重新移动到链表的表头
    并且让slow和fast每次都前进一步，当slow和fast再次相遇的时候
    ，相遇的节点即位环路的节点.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        do {
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};
// @lc code=end

