#include "SList.h"

//leetcode:206. 反转链表
//struct ListNode* reverseList(struct ListNode* head) {
//	if (head == NULL)
//		return NULL;
//	struct ListNode* newhead = head, * cur = head;
//	struct ListNode* next = cur->next;
//	head->next = NULL;
//
//	while (next)
//	{
//		newhead = next;
//		next = next->next;
//		newhead->next = cur;
//		cur = newhead;
//	}
//
//	return newhead;
//}

//leetcode:876. 链表的中间结点
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* fast = head->next, * low = head;
//    while (fast)
//    {
//        if (fast->next != NULL)
//        {
//            fast = fast->next->next;
//        }
//        else
//        {
//            fast = fast->next;
//        }
//        low = low->next;
//    }
//    return low;
//}

//leetcode:21. 合并两个有序链表
//SListNode* mergeTwoLists(SListNode* list1, SListNode* list2) 
//{
//    SListNode* newhead = NULL, * cur = NULL;
//
//    if (list1 == NULL)
//        return list2;
//
//    if (list2 == NULL)
//        return list1;
//
//    while (list1 && list2)
//    {
//        if (list1->date <= list2->date)
//        {
//            if (newhead == NULL)
//            {
//                newhead = list1;
//                cur = newhead;
//            }
//            else
//            {
//                cur->next = list1;
//                cur = cur->next;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (newhead == NULL)
//            {
//                newhead = list2;
//                cur = newhead;
//            }
//            else
//            {
//                cur->next = list2;
//                cur = cur->next;
//            }
//            list2 = list2->next;
//        }
//    }
//
//    if (list2 != NULL)
//        cur->next = list2;
//
//    if (list1 != NULL)
//        cur->next = list1;
//
//    return newhead;
//}

int main()
{
    SListNode* plist1 = NULL;
    SListNode* plist2 = NULL;

	//测试用例
    int arr1[] = { 2 };
    int arr2[] = { 1 };
    int sz1 = sizeof(arr1) / sizeof(int);
    int sz2 = sizeof(arr2) / sizeof(int);
    
	for (int i = 0; i < sz1; i++)
	{
		SListPushBack(&plist1, arr1[i]);
	}
    for (int i = 0; i < sz2; i++)
    {
        SListPushBack(&plist2, arr2[i]);
    }

    SListPrint(plist1);
    SListPrint(plist2);

	//测试函数
	//...

    SListDestroy(plist1);
    SListDestroy(plist2);
	return 0;
}


