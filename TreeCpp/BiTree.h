#pragma once

#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#include<iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
	T value;
	BinaryTreeNode<T>* left_node;
	BinaryTreeNode<T>* right_node;

	BinaryTreeNode() :left_node(nullptr), right_node(nullptr) {};
	BinaryTreeNode(const T &e) :value(e), left_node(nullptr), right_node(nullptr){};
	BinaryTreeNode(const T &e, BinaryTreeNode* left, BinaryTreeNode* right) :
		value(e), left_node(left), right_node(right) {};
};

template< typename T>
class BinaryTree
{
public:
	BinaryTree() :m_root(nullptr) {};
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	//C++类有继承时，析构函数必须为虚函数
	//如果不是虚函数，则使用时可能存在内在泄漏的问题。
	virtual ~BinaryTree() {
		Destroy(m_root);
		m_root = nullptr;
	};

	//判断是否是空树
	bool IsEmpty() const { return m_root == nullptr ? true : false; };

	BinaryTreeNode<T>* GetRoot() const { return m_root; };

	void Add_Node(const T &value);
	//插入右孩子到当前节点下
	void InsertRightChild(BinaryTreeNode<T> *p, const T &d) const;
	//插入左孩子到当前节点下
	void InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const;

	//先序遍历整棵树
	void PreOrderTraverse() const;
	//中序遍历整棵树
	void InOrderTraverse() const;
	//后序遍历整棵树
	void PostOrderTraverse() const;
	//先序遍历整棵树（递归法）
	void PreOrderTraverseRecursion() const;
	//中序遍历整棵树（递归法）
	void InOrderTraverseRecursion() const;
	//后序遍历整棵树（递归法）
	void PostOrderTraverseRecursion() const;
	void LevelOrderTraverse() const;
protected:
	//先序遍历整棵树
	virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;
	//中序遍历整棵树
	virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;
	//后序遍历整棵树
	virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const; 
	//先序遍历整棵树（递归法）
	virtual void PreOrderTraverseRecursion(BinaryTreeNode<T> *root) const;
	//中序遍历整棵树（递归法）
	virtual void InOrderTraverseRecursion(BinaryTreeNode<T> *root) const;
	//后序遍历整棵树（递归法）
	virtual void PostOrderTraverseRecursion(BinaryTreeNode<T> *root) const; 
	//按层遍历整棵树
	virtual void LevelOrderTraverse(BinaryTreeNode<T> *root) const;

	void Destroy(BinaryTreeNode<T> *p);
private:
	BinaryTreeNode<T> *m_root;
};

/*
@brief
添加一个节点到原树中
@添加原则
小于父节点的值放在左子树，大于父节点的值放在右子树
*/
template<typename T>
void BinaryTree<T>::Add_Node(const T &value)
{
	//定义需要用到的变量
	//临时的指针
	TNode<T> *currentNode;
	//记录是否插入了新的节点
	int flag = 0;

	//将新节点插入二叉树
	if (IsEmpty())
	{
		m_root->value = value;
	}
	else
	{
		currentNode = m_root;
		//循环结束的时刻是：flag=1，即节点已被插入
		while (!flag)
		{
			if (value<currentNode->value)
			{
				if (currentNode->left_node == nullptr)
				{
					InsertLeftChild(currentNode, value);
					currentNode->left_node = newNode;
					flag = 1;
				}
				else
				{
					currentNode = currentNode->left_node;
				}
			}
			else
			{
				if (currentNode->right_node == nullptr)
				{
					currentNode->right_node = newNode;
					flag = 1;
				}
				else
				{
					currentNode = currentNode->right_node;
				}
			}
		}//end while
	}//end else
}

template<typename T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T>* p, const T & d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->right_node = p->right_node;
	p->right_node = q;
}

template<typename T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T>* p, const T & d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->left_node = p->left_node;
	p->left_node = q;
}

template<typename T>
void BinaryTree<T>::PreOrderTraverse() const
{
	PreOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::InOrderTraverse() const
{
	InOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverse() const
{
	PostOrderTraverse(m_root);
}

template<typename T>
void BinaryTree<T>::PreOrderTraverseRecursion() const
{
	PreOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::InOrderTraverseRecursion() const
{
	InOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverseRecursion() const
{
	PostOrderTraverseRecursion(m_root);
}

template<typename T>
void BinaryTree<T>::LevelOrderTraverse() const
{
	LevelOrderTraverse(m_root);
}

#pragma region 遍历

template<typename T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = curNode;
	while (!s.empty()||p!=nullptr)
	{
		while (p!=nullptr)
		{
			s.push(p);
			cout << " " << p->value << " ";
			p = p->left_node;
		}
		p = s.top();
		s.pop();
		p = p->right_node;
	}
}

template<typename T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = curNode;
	while (!s.empty() || p != nullptr)
	{
		while (p != nullptr)
		{
			s.push(p);
			p = p->left_node;
		}
		p = s.top();
		s.pop();
		cout << " " << p->value << " ";
		p = p->right_node;
	}
}

template<typename T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = curNode;
	int flag;

}

template<typename T>
void BinaryTree<T>::PreOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}
	cout << " " << curNode->value << " ";

	PreOrderTraverse(curNode->left_node);
	PreOrderTraverse(curNode->right_node);
}

template<typename T>
void BinaryTree<T>::InOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	InOrderTraverseRecursion(curNode->left_node);
	cout << " " << curNode->value << " ";
	InOrderTraverseRecursion(curNode->right_node);
}

template<typename T>
void BinaryTree<T>::PostOrderTraverseRecursion(BinaryTreeNode<T>* curNode) const
{
	if (nullptr == curNode)
	{
		return;
	}

	PostOrderTraverseRecursion(curNode->left_node);
	PostOrderTraverseRecursion(curNode->right_node);
	cout << " " << curNode->value << " ";
}

template<typename T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T>* curNode) const
{
	queue<BinaryTreeNode<T>*> q;
	if (nullptr != curNode)
	{
		q.push(curNode);
	}
	while (!q.empty())
	{
		curNode = q.front(), q.pop();
		cout << " " << curNode->value << " ";
		if (nullptr != curNode->left_node)
		{
			q.push(curNode->left_node);
		}
		if (nullptr != curNode->right_node)
		{
			q.push(curNode->right_node);
		}
	}
	cout << endl;
}

#pragma endregion

template<typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T>* p)
{
	if (nullptr != p)
	{
		Destroy(p->left_node);
		Destroy(p->right_node);
		delete p;
		p = nullptr;
	}
}
#endif // BITREE_H_INCLUDED
