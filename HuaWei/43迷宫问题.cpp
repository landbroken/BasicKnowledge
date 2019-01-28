#include"stdafx.h"

#pragma region AStar算法解

/*
1. 从起点 A 开始, 把它作为待处理的方格存入一个"开启列表",
开启列表就是一个等待检查方格 的列表.

2. 寻找起点 A 周围可以到达的方格, 将它们放入"开启列表",
并设置它们的"父方格"为 A.

3. 从"开启列表"中删除起点 A, 并将起点 A 加入"关闭列表",
"关闭列表"中存放的都是不需要再次检查的方格
从 "开启列表" 中找出相对最靠谱的方块, 什么是最靠谱? 它们
通过公式 F=G+H 来计算.

F = G + H

G 表示从起点 A 移动到网格上指定方格的移动耗费 (可沿斜方向移动).
H 表示从指定的方格移动到终点 B 的预计耗费 (H 有很多计算方法,
这里我们设定只可以 上下左右移动).
从 "开启列表" 中选择 F 值最低的方格 C (绿色起始方块 A 右边的
方块), 然后对它进行如下处 理:

4. 把它从 "开启列表" 中删除, 并放到 "关闭列表" 中.

5. 检查它所有相邻并且可以到达 (障碍物和 "关闭列表" 的方格都不
考虑) 的方格. 如果这些方格 还不在 "开启列表" 里的话, 将它们加入
"开启列表", 计算这些方格的 G, H 和 F 值各是多少, 并设置 它们的 "父方格" 为 C.

6. 如果某个相邻方格 D 已经在 "开启列表" 里了, 检查如果用新的
路径 (就是经过 C 的路径) 到 达它的话, G 值是否会更低一些, 如果
新的 G 值更低, 那就把它的 "父方格" 改为目前选中的方格 C, 然后
重新计算它的 F 值和 G 值 (H 值不需要重新计算, 因为对于每个方块,
H 值是不变的). 如果新的 G 值比较高, 就说明经过 C 再到达 D 不是
一个明智的选择, 因为它需要更远的路, 这时我们什么也不做.
*/

enum state { valid = 0, wall = 1, open = 2, close = 3,start=4,end=5 };
struct mPoint {
	int x = -1, y = -1;

	int pre_x = -1, pre_y = -1;

	double f = INT_MAX;//f=g+h
	double g = 0;//起点到这里
	double h = 0;//这里到终点
	
	state s=state::valid;
	void Update(mPoint p, double gIn, double hIn)
	{
		pre_x = p.x;
		pre_y = p.y;
		g = gIn;
		h = hIn;
		f = g + h;
	}

	//set容器自定义排序和去重
	bool operator<(const struct mPoint & right)const   //重载<运算符
	{
		if (this->x == right.x&&this->y == right.y)     //根据id去重
			return false;
		else
		{
			if (this->x != right.x)
			{
				return this->x < right.x;      //升序
			}
			else
			{
				return this->y < right.y;
			}
		}
	}
};

int startx = 0, starty = 0, endx, endy;
set<mPoint> openlist;
set<mPoint> closelist;

double GetDistance(int x, int y)
{
	return abs(endx - x) + abs(endy - y);
}

bool isValid(mPoint p, int maxX, int maxY)
{
	//墙
	if (p.s == state::wall)
		return false;
	//已经在关闭列表里，不再考虑
	else if (p.s == state::close|| p.s == state::start)
		return false;
	else
	{
		return true;
	}
}

void GetNextPoint(int cur_x, int cur_y, int i,int& next_x,int& next_y)
{
	switch (i)
	{
	case 0:
		next_x = cur_x - 1;
		next_y = cur_y;
		break;
	case 1:
		next_x = cur_x + 1;
		next_y = cur_y;
		break;
	case 2:
		next_x = cur_x;
		next_y = cur_y - 1;
		break;
	case 3:
		next_x = cur_x;
		next_y = cur_y + 1;
		break;
	default:
		break;
	}
}

void FindMinFOfPoint(mPoint &p)
{
	double min_f = INT_MAX;
	for (auto it = openlist.begin(); it != openlist.end(); it++)
	{
		if (min_f>=(*it).f)
		{
			min_f = (*it).f;
			p.x = (*it).x;
			p.y = (*it).y;
		}
	}
}

bool Insert(int cur_x, int cur_y, vector<vector<mPoint>> &imap)
{
	for (size_t i = 0; i < 4; i++)
	{
		int next_x = -1, next_y = -1;
		GetNextPoint(cur_x, cur_y,i, next_x, next_y);
		
		//越界
		if (next_x < 0 || next_y < 0 || next_x >= imap.size() || next_y >= imap[0].size())
			continue;

		if (!isValid(imap[next_x][next_y], endx, endy))
			continue;

		if (imap[next_x][next_y].s==state::end)
		{
			imap[next_x][next_y].Update(imap[cur_x][cur_y], imap[cur_x][cur_y].g + 1, 0);
			return true;
		}

		int h = GetDistance(next_x, next_y);
		int g = imap[cur_x][cur_y].g + 1;
		
		//如果周围节点在open列表中
		if (imap[next_x][next_y].s==state::open)
		{
			//计算经过的Open列表中最小f值到周围节点的G值
			if (g<imap[next_x][next_y].g)
			{
				imap[next_x][next_y].Update(imap[cur_x][cur_y], g, h);
			}
		}
		//周围节点不在Open列表中
		else
		{
			imap[next_x][next_y].Update(imap[cur_x][cur_y], g, h);
			openlist.insert(imap[next_x][next_y]);
			imap[next_x][next_y].s = state::open;
		}
	}
	return false;
}

void FindPath(vector<vector<mPoint>> &imap)
{
	imap[startx][starty].g = 0;
	imap[startx][starty].h = GetDistance(startx, starty);
	imap[startx][starty].f = imap[startx][starty].g+ imap[startx][starty].h;
	openlist.insert(imap[startx][starty]);

	while (openlist.size()>0)
	{
		mPoint p;
		FindMinFOfPoint(p);//查找Open列表中最小的f值
		openlist.erase(imap[p.x][p.y]);
		closelist.insert(imap[p.x][p.y]);//不再考虑当前节点
		if (imap[p.x][p.y].s == state::valid||
			imap[p.x][p.y].s == state::open)
		{
			imap[p.x][p.y].s = state::close;
		}

		bool isEnd=Insert(p.x, p.y, imap);
		if (isEnd)
		{
			break;
		}
	}
}

void Output(vector<vector<mPoint>> &imap)
{
	mPoint cur = imap[endx][endy];
	vector<string> a;
	while (cur.s!=state::start)
	{
		string tmp = "(";
		tmp += to_string(cur.x);
		tmp += ",";
		tmp += to_string(cur.y);
		tmp += ")";
		a.push_back(tmp);
		cur = imap[cur.pre_x][cur.pre_y];
	}
	string tmp = "(";
	tmp += to_string(cur.x);
	tmp += ",";
	tmp += to_string(cur.y);
	tmp += ")";
	a.push_back(tmp);

	for (int i = a.size()-1; i >=0 ; i--)
	{
		cout << a[i] << endl;
	}
}

int test_mi_gong_wen_ti()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<mPoint>> imap(n);
		openlist.clear();
		closelist.clear();
		//输入
		startx = 0, starty = 0, endx = n - 1, endy = m - 1;
		for (int i = 0;i<n;i++)
		{
			imap[i].resize(m);
		}
		int tmp;
		for (int i = 0;i<n;i++)
		{
			for (int j = 0;j<m;j++)
			{
				cin >> tmp;
				imap[i][j].x = i;
				imap[i][j].y = j;
				if (tmp == 1)
				{
					imap[i][j].s = state::wall;
				}
			}
		}
		imap[startx][starty].s = state::start;
		imap[endx][endy].s = state::end;
		//寻路
		FindPath(imap);
		//输出
		Output(imap);
	}
	return 0;
}

#pragma endregion

#pragma region 回溯算法解

int N, M; //分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳路径

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中

	if (i == N - 1 && j == M - 1) //判断是否到达终点
		if (path_best.empty() || path_temp.size() < path_best.size())
			path_best = path_temp;

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
		MazeTrack(i, j + 1);
	maze[i][j] = 0;         //恢复现场，设为未走
	path_temp.pop_back();
}
int test_43()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
			for (auto &j : i)
				cin >> j;
		MazeTrack(0, 0);//回溯寻找迷宫最短通路
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	}
	return 0;
}

#pragma endregion
