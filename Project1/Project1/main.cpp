#include <iostream>
#include <atlbase.h>
#include <atlwin.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "treewindow.h"
using namespace std;

typedef struct Node
{
	Node* left;
	Node* right;
	string data;
} ;

typedef struct { //����
	Node* root=NULL;
} Tree;

void NodeInfoCallback(void* context, void* node_, int hierarchy, NodeInfo* nodeInfo)
{
	auto x = (Node*)(node_);

	nodeInfo->left = x->left;           // ������ڵ�
	nodeInfo->right = x->right;         // �����ҽڵ�
	_stprintf_s(nodeInfo->Label, "%s", (x->data).c_str());    // ��Ҫ��ʾ���ı�
	nodeInfo->ColorFill = RGB(105, 255, 97);           // ���ɫ
	nodeInfo->ColorLabel = RGB(0, 0, 0);          // �ı���ɫ
	nodeInfo->ColorBorder = RGB(255,0 ,0);        // �߿���ɫ
}

void insert(Tree* tree, string value)//������
{
	Node* node = new Node;//����һ���ڵ�
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL)//�ж����ǲ��ǿ���
	{
		tree->root = node;
	}
	else {//���ǿ���
		Node* temp = tree->root;//��������ʼ
		while (temp != NULL)
		{

			if (value.compare(temp->data) < 0)//С�ھͽ������
			{
				if (temp->left == NULL)
				{
					temp->left = node;
					return;
				}
				else {//�����ж�
					temp = temp->left;
				}
			}
			else {//������Ҷ���

				if (temp->right == NULL)
				{
					temp->right = node;
					return;
				}
				else {//�����ж�
					temp = temp->right;
				}
			}
		}
	}
	return;
}

void inorder(Node* node)//�����������
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << (node->data) << " ";
		inorder(node->right);
	}
}
void display(Tree tr)
{
	TreeWindow wnd;
	wnd.DisplayBinaryTree(tr.root, NodeInfoCallback, nullptr);
	system("pause");
}


int main()
{

	Tree tree;
	//tree.root=NULL;//����һ������
	int n = 2;
	for (int i = 0; i < n; i++)//����n���������������
	{
		string temp;
		cin >> temp;
		insert(&tree, temp);
	}
	inorder(tree.root);//�������
	cout << endl;
	display(tree);
	return 0;
}