#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//������˫����
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* tmp = cur->next;//�ݴ��̽ڵ�
        cur->next = pre;//��ת�������
        pre = cur;
        cur = tmp;//����ָ��ǰ��
    }
    return pre;
}


//�ݹ�
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