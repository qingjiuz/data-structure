#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//100. 相同的树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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

//226. 翻转二叉树
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if ((root == NULL) || (root->left == NULL && root->right == NULL))
//        return root;
//
//    struct TreeNode* ptr = root->left;
//    root->left = root->right;
//    root->right = ptr;
//
//    invertTree(root->left);
//    invertTree(root->right);
//
//    return root;
//}

//104. 二叉树的最大深度
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//
//    if (left > right)
//        return left + 1;
//    else
//        return right + 1;
//}

//965. 单值二叉树
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->left->val != root->val)
//        return false;
//
//    if (root->right && root->right->val != root->val)
//        return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}

int main()
{
	//bool a = false;
	//bool b = false;
	//
	//printf("%d", a && b);

	return 0;
}