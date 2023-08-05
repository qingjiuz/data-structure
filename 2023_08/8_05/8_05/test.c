//newcoder:NC248 左叶子之和
//int sumOfLeftLeaves(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//
//    int sum = 0;
//    if (root->left && root->left->left == NULL && root->left->right == NULL)
//        sum = root->left->val;
//
//    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//}

//NC132 环形链表的约瑟夫问题
//typedef struct ListNode ListNode;
//
//ListNode* BuyNode(int n) {
//    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//    newnode->val = n;
//    newnode->next = NULL;
//    return newnode;
//}
//
//ListNode* CreateNode(int n) {
//    ListNode* phead, * ptail;
//    int i = 1;
//    phead = ptail = BuyNode(i++);
//
//    while (i <= n) {
//        ptail->next = BuyNode(i++);
//        ptail = ptail->next;
//    }
//
//    ptail->next = phead;
//    return phead;
//}
//
//int ysf(int n, int m) {
//    ListNode* phead = CreateNode(n);
//    ListNode* cur = phead;
//    ListNode* prev = NULL;
//
//    int i = 1;
//    while (cur->next != cur) {
//        if (i == m)
//        {
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//            i = 1;
//        }
//        else {
//            prev = cur;
//            cur = cur->next;
//            i++;
//        }
//    }
//
//    return cur->val;
//}