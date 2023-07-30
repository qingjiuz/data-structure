#define _CRT_SECURE_NO_WARNINGS 1

//leetcode:144. 二叉树的前序遍历
//int TreeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void preorder(struct TreeNode* root, int* a, int* i)
//{
//    if (root == NULL)
//        return;
//
//    a[*i] = root->val;
//    (*i)++;
//    preorder(root->left, a, i);
//    preorder(root->right, a, i);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* a = (int*)malloc(*returnSize * sizeof(int));
//
//    int i = 0;
//    preorder(root, a, &i);
//
//    return a;
//}


//leetcode:101. 对称二叉树
//bool TreeCom(struct TreeNode* left, struct TreeNode* right)
//{
//    if (left == NULL && right == NULL)
//        return true;
//
//    if (left == NULL || right == NULL)
//        return false;
//
//    if (left->val != right->val)
//        return false;
//
//    return TreeCom(left->left, right->right) && TreeCom(left->right, right->left);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    return TreeCom(root->left, root->right);
//}

//leetcode:572. 另一棵树的子树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p != NULL && q != NULL)
//    {
//        if (p->val != q->val)
//            return false;
//
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    }
//    else
//        return false;
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//
//    if (root->val == subRoot->val)
//    {
//        if (isSameTree(root, subRoot))
//            return true;
//    }
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}

//nowcoder:KY11 二叉树遍历
//struct TreeNode {
//    struct TreeNode* left;
//    struct TreeNode* right;
//    int val;
//};
//
//struct TreeNode* CreateTree(char* a, int* pi) {
//    if (a[*pi] == '#') {
//        (*pi)++;
//        return NULL;
//    }
//
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->val = a[(*pi)++];
//    root->left = CreateTree(a, pi);
//    root->right = CreateTree(a, pi);
//
//    return root;
//}
//
//void BinaryTreeInOrder(struct TreeNode* root)
//{
//    if (root == NULL)
//        return;
//
//    BinaryTreeInOrder(root->left);
//    printf("%c ", root->val);
//    BinaryTreeInOrder(root->right);
//}
//
//
//int main() {
//    char a[100];
//    scanf("%s", a);
//
//    int i = 0;
//    struct TreeNode* root = CreateTree(a, &i);
//
//    BinaryTreeInOrder(root);
//
//    return 0;
//}
