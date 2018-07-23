#pragma once
#ifndef _MATRIX_UDG_H_
#define _MATRIX_UDG_H_

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

class MatrixUDG {
private:
	char mVexs[MAX];    // 顶点集合
	int mVexNum;             // 顶点数
	int mEdgNum;             // 边数
	int mMatrix[MAX][MAX];   // 邻接矩阵

public:
	// 创建图(自己输入数据)
	MatrixUDG();
	// 创建图(用已提供的矩阵)
	MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
	~MatrixUDG();

	// 深度优先搜索遍历图
	void DFS();
	// 广度优先搜索（类似于树的层次遍历）
	void BFS();
	// 打印矩阵队列图
	void print();

private:
	// 读取一个输入字符
	char readChar();
	// 返回ch在mMatrix矩阵中的位置
	int getPosition(char ch);
	// 返回顶点v的第一个邻接顶点的索引，失败则返回-1
	int firstVertex(int v);
	// 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
	int nextVertex(int v, int w);
	// 深度优先搜索遍历图的递归实现
	void DFS(int i, int *visited);

};

int matrix_udg_main();

#endif // !_MATRIX_UDG_H_
