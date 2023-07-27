#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* ptr = (BTNode*)malloc(sizeof(BTNode));
	if (ptr == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ptr->val = x;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

BTNode* CreatBinaryTree()
{
	
	BTNode* Node1 = BuyNode(1);
	BTNode* Node2 = BuyNode(2);
	BTNode* Node3 = BuyNode(3);
	BTNode* Node4 = BuyNode(4);
	BTNode* Node5 = BuyNode(5);
	BTNode* Node6 = BuyNode(6);
	BTNode* Node7 = BuyNode(7);
	BTNode* Node8 = BuyNode(8);
	BTNode* Node9 = BuyNode(9);
	BTNode* Node10 = BuyNode(10);

	Node1->left = Node2;
	Node2->left = Node3;

	Node1->right = Node4;
	
	Node3->left = Node7;
	Node7->left = Node8;
	Node7->right = Node9;

	Node4->left = Node5;
	Node4->right = Node6;

	Node2->right = Node10;

	return Node1;
}

//前序遍历-- 根->左子树->右子树
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

//中序遍历-- 左子树->根->右子树
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

//后序遍历-- 左子树->右子树->根
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

//计算节点数量
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return TreeSize(root->left) + TreeSize(root->right) + 1;
}

//计算树的高度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int left = TreeHeight(root->left);
	int right = TreeHeight(root->right);
	
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

//计算第k层的节点数
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;
	
	int left = TreeKLevel(root->left, k-1);
	int right = TreeKLevel(root->right, k-1);

	return left + right;
}


void BTTest()
{
	BTNode* root = CreatBinaryTree();

	//前序遍历-- 根->左子树->右子树
	PreOrder(root);
	printf("\n");

	//中序遍历-- 左子树->根->右子树
	InOrder(root);
	printf("\n");

	//后序遍历-- 左子树->右子树->根
	PostOrder(root);
	printf("\n");

	//层序遍历
	//LevelOrder(root);

	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeKLevel:%d\n", TreeKLevel(root, 3));
}

int main()
{
	BTTest();

	return 0;
}