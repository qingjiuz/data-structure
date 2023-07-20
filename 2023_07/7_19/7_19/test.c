#define _CRT_SECURE_NO_WARNINGS 1

//leetcode:138. 复制带随机指针的链表
//struct Node* copyRandomList(struct Node* head) {
//    if (head == NULL)
//        return NULL;
//
//    struct Node* oldcur = head;
//
//    while (oldcur)
//    {
//        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//        struct Node* tmp = oldcur->next;
//
//        oldcur->next = newnode;
//        newnode->val = oldcur->val;
//        newnode->random = NULL;
//        newnode->next = tmp;
//        oldcur = oldcur->next->next;
//    }
//
//    struct Node* newcur = head;
//    oldcur = head;
//    while (oldcur)
//    {
//        newcur = newcur->next;
//        if (oldcur->random != NULL)
//            newcur->random = oldcur->random->next;
//        oldcur = oldcur->next->next;
//        newcur = newcur->next;
//    }
//
//    struct Node* newhead = head->next;
//    newcur = head->next;
//    oldcur = head;
//
//    while (oldcur)
//    {
//        oldcur->next = oldcur->next->next;
//        oldcur = oldcur->next;
//        if (newcur->next != NULL)
//        {
//            newcur->next = newcur->next->next;
//            newcur = newcur->next;
//        }
//    }
//    return newhead;
//}