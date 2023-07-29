#include "BInaryTree.h"

//通过前序遍历的数组构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	assert(*pi >= 0);

	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* ptr = (BTNode*)malloc(sizeof(BTNode));
	if (ptr == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	ptr->val = a[*pi];
	printf("%c ", a[*pi]);
	(*pi)++;
	if (a[*pi])
	{
		ptr->left = BinaryTreeCreate(a, pi);
		ptr->right = BinaryTreeCreate(a, pi);
	}

	return ptr;
}

//二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);

	free(*root);
	*root = NULL;
}

//二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;
	
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) 
			+ BinaryTreeLevelKSize(root->right, k - 1);
}

//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;

	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;

	return NULL;
}

//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

//二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreeInOrder(root->right);
}

//二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->val);
}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		//释放队列的头
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);

		//带入根的左右子树
		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
}

//判断二叉树是否完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	int flag = 1;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else if (root->left == NULL && root->right != NULL)
		return 0;

	if (flag && root->left)
		flag = BinaryTreeComplete(root->left);

	if (flag && root->right)
		flag = BinaryTreeComplete(root->right);

	return flag;
}
