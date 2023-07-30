#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//ͨ��ǰ����������鹹��������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

//����������
void BinaryTreeDestory(BTNode* root);

//�������ڵ����
int BinaryTreeSize(BTNode* root);

//������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//������ǰ�����
void BinaryTreePrevOrder(BTNode* root);

//�������������
void BinaryTreeInOrder(BTNode* root);

//�������������
void BinaryTreePostOrder(BTNode* root);

//�������
void BinaryTreeLevelOrder(BTNode* root);

//�ж϶������Ƿ���ȫ������
bool BinaryTreeComplete(BTNode* root);
