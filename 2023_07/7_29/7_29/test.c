#include "BInaryTree.h"

int main()
{
	//Ç°Ðò±éÀúµÄ×Ö·û´®
	//"124###35###"
	//"124##5##36###"
	BTDataType a[] = "124###35###";

	int i = 0;
	BTNode* pa = BinaryTreeCreate(a, &i);
	printf("\n");
	printf("TreeSize:%d\n", BinaryTreeSize(pa));
	printf("TreeLeafSize:%d\n", BinaryTreeLeafSize(pa));
	printf("TreeLeaLevelKSize:%d\n", BinaryTreeLevelKSize(pa, 3));
	printf("TreeFind:%p\n", BinaryTreeFind(pa, '3'));

	BinaryTreePrevOrder(pa);
	printf("\n");
	BinaryTreeInOrder(pa);
	printf("\n");
	BinaryTreePostOrder(pa);
	printf("\n");

	BinaryTreeLevelOrder(pa);
	printf("\n");

	printf("TreeComplete:%d\n", BinaryTreeComplete(pa));

	BinaryTreeDestory(pa);
	pa = NULL;

	return 0;
}