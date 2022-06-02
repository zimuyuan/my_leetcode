/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    // 先搜索该链表的长度
    int len = 0;
    struct ListNode returnHead;
    returnHead.next = head;
    struct ListNode* node = head;
    while (node)
    {
        len++;
        node = node->next;
    }
    node = &returnHead;
    // 将倒数 n ,换算成顺数
    n = len - n;

    // 找到要删除节点的前一个节点
    while (n > 0)
    {
        n--;
        node = node->next;
    }
    // 删除对应节点
    node->next = node->next->next;
    return returnHead.next;
}
// @lc code=end

