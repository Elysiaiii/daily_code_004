#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//迭代（双链表）
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* tmp = cur->next;//暂存后继节点
        cur->next = pre;//反转两个结点
        pre = cur;
        cur = tmp;//两个指针前进
    }
    return pre;
}


//递归
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* nhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nhead;
}