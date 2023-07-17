#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//leetcode:141. 环形链表
//bool hasCycle(struct ListNode* head) {
//    if (head == NULL)
//        return false;
//    struct ListNode* low = head, * fast = head->next;
//
//    while (fast && fast->next)
//    {
//        if (low == fast)
//            return true;
//        fast = fast->next->next;
//        low = low->next;
//    }
//    return false;
//}

//leetcode:160. 相交链表 
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* TailA = headA, * TailB = headB;
//    int ADate = 0, BDate = 0;
//
//    while (TailA)
//    {
//        TailA = TailA->next;
//        ADate++;
//    }
//
//    while (TailB)
//    {
//        TailB = TailB->next;
//        BDate++;
//    }
//
//    if (ADate > BDate)
//    {
//        ADate -= BDate;
//        while (ADate--)
//            headA = headA->next;
//    }
//    else if (BDate > ADate)
//    {
//        BDate -= ADate;
//        while (BDate--)
//            headB = headB->next;
//    }
//
//    while (headA && headB)
//    {
//        if (headA == headB)
//            return headA;
//        headA = headA->next;
//        headB = headB->next;
//    }
//    return NULL;
//}

//nowcoder:OR36 链表的回文结构
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)
//        return NULL;
//    struct ListNode* newhead = head, * cur = head;
//    struct ListNode* next = cur->next;
//    head->next = NULL;
//
//
//    while (next) {
//        newhead = next;
//        next = next->next;
//        newhead->next = cur;
//        cur = newhead;
//    }
//
//
//    return newhead;
//}
//
//
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* fast = head->next, * low = head;
//    while (fast) {
//        if (fast->next != NULL) {
//            fast = fast->next->next;
//        }
//        else {
//            fast = fast->next;
//        }
//        low = low->next;
//    }
//    return low;
//}
//
//bool chkPalindrome(ListNode* pHead) {
//        ListNode* mid = middleNode(pHead);
//        ListNode* rev = reverseList(mid);
//
//
//        while (rev)
//        {
//            if (rev->val != pHead->val)
//                return false;
//            rev = rev->next;
//            pHead = pHead->next;
//        }
//
//
//        return true;
//}

int main()
{

	return 0;
}