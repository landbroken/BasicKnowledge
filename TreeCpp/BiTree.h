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
template<typename T>
using SearchTreeNode = BinaryTreeNode<T>;

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

	//插入一个值
	void Insert(const T &value);
	//插入右孩子到当前节点下
	void InsertRightChild(BinaryTreeNode<T> *p, const T &d) const;
	//插入左孩子到当前节点下
	void InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const;
	BinaryTreeNode<T>* Remove(const T value, BinaryTreeNode<T>* p);

	//在二叉树中找到node->value==data
	SearchTreeNode<T>* Find(T data, BinaryTreeNode<T>* node)const;
	//在二叉树中找到最小值
	SearchTreeNode<T>* FindMin(BinaryTreeNode<T>* node)const;
	//在二叉树中找到最大值
	SearchTreeNode<T>* FindMax(BinaryTreeNode<T>* node)const;
	//在二叉树中找到最临近值(node->value<=data)
	SearchTreeNode<T>* FindFloor(T data, BinaryTreeNode<T>* node)const;

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
	//层次遍历
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

	BinaryTreeNode<T>* Destroy(BinaryTreeNode<T> *p);
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
void BinaryTree<T>::Insert(const T &value)
{
	if (nullptr==m_root)
	{
		m_root = new BinaryTreeNode<T>(value);
		return;
	}

	SearchTreeNode<T>* nearNode = FindFloor(value, m_root);
	SearchTreeNode<T>* next = nullptr;
	if (value < nearNode->value)
	{
		next = new BinaryTreeNode<T>(value);
		nearNode->left_node = next;
	}
	else if (value > nearNode->value)
	{
		next = new BinaryTreeNode<T>(value);
		nearNode->right_node = next;
	}
	else
	{
		return;//已经存在的不重复添加
	}
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

/*
@brief 删除
@说明
1、T是叶子节点。
直接释放该节点的空间，如果是根节点，则直接赋值为NULL。
2、T有一棵非空子树。
如果是根节点，则T的唯一子树成为根节点，如果非根节点，则使其父节点指针绕过
该节点指向其唯一子节点，释放空间。
3、T有两棵非空子树。
一般策略是将该节点的元素替换成它的左子树的最大元素或右子树的最小元素
（代码中采用的是后者，即用右子树的最小元素替换被删除的节点），然后再
删除被替换的元素。
*/
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Remove(const T data, BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* tmpNode;

	if (node == nullptr) 
	{
		return node;
	}
	else if (data < node->value)
	{
		node->left_node = BinaryTree<T>::Remove(data, node->left_node);
	}
	else if (data > node->value) 
	{
		node->right_node = BinaryTree<T>::Remove(data, node->right_node);
	}
	//找到该元素，开始删除
	else if (node->left_node != nullptr && node->right_node != nullptr)
	{
		//有两个子树的情况
		tmpNode = BinaryTree<T>::FindMin(node->right_node);
		node->value = tmpNode->value;
		node->right_node = BinaryTree<T>::Remove(node->value, node->right_node);
	}
	else 
	{
		//有一个或没有子树的情况
		tmpNode = node;
		//绕过被删除的节点
		if (node->left_node == nullptr)
		{
			node = node->right_node;
		}  
		else if (node->right_node == nullptr)
		{
			node = node->left_node;
		}
		delete tmpNode;
		tmpNode = nullptr;
	}

	return node;
}

template<typename T>
SearchTreeNode<T> * BinaryTree<T>::Find(T data, BinaryTreeNode<T>* node) const
{
	if (node ==nullptr)
	{
		return nullptr;
	}

	if (data== node->value)
	{
		return node;
	}
	else if(data<node->value)
	{
		return Find(data, node->left_node);//小于根节点的在左孩子里
	}
	else
	{
		return Find(data, node->right_node);//大于根节点的在右孩子里
	}
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindMin(BinaryTreeNode<T>* node) const
{
	if (node==nullptr)
	{
		return nullptr;
	}

	////递归实现
	//if (node->left_node==nullptr)
	//{
	//	return node;
	//}
	//else
	//{
	//	return FindMin(node->left_node);
	//}

	while (node->left_node!=nullptr)
	{
		node = node->left_node;
	}
	return node;
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindMax(BinaryTreeNode<T>* node) const
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->right_node != nullptr)
	{
		node = node->right_node;
	}
	return node;
}

template<typename T>
SearchTreeNode<T>* BinaryTree<T>::FindFloor(T data, BinaryTreeNode<T>* node) const
{
	if (m_root==nullptr)
	{
		return nullptr;
	}
	while (node->left_node!=nullptr|| node->right_node!=nullptr)
	{
		if(data<node->value && node->left_node!=nullptr)
		{
			node = node->left_node;
		}
		else if (data > node->value && node->right_node != nullptr)
		{
			node = node->right_node;
		}
		else 
		{
			return node;
		}
	}
	return node;
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
BinaryTreeNode<T>* BinaryTree<T>::Destroy(BinaryTreeNode<T>* p)
{
	if (nullptr != p)
	{
		p->left_node = Destroy(p->left_node);
		p->right_node = Destroy(p->right_node);
		delete p;
		p = nullptr;
	}
	return nullptr;
}

#endif // BITREE_H_INCLUDED
