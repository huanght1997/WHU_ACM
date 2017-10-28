// 其本质是求一个图中两点间的最短距离
// 图的两种表示方法中，一个是邻接矩阵，针对这个点最多有200,000的图显然会爆内存
// 故使用邻接链表来表示图
// 直接BFS就行，用遍历深度即可表示结果
// 另外，STL是个好东西
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> *graph;// graph是一个数组，数组的下标用于标记点，数组元素表示该点的后继节点的集合
int shortest(int u, int v, int n);
int main()
{
	int n, m;
	cin >> n >> m;
	graph = new vector<int>[n];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << shortest(u, v, n) << endl;
	}
	delete[] graph;
	return 0;
}

// 实际上就是图的广度遍历，u为起始节点，v为终止节点，n为节点个数
int shortest(int u, int v, int n)
{
	if (u == v)
		return 0;
	bool *visited;
	queue<pair<int,int>> q;
	pair<int,int> curr;	// first为节点编号，second为深度
	visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;	// 已访问节点数组初始化
	visited[u] = true;
	q.push(make_pair(u, 0));	// 确定初始顶点编号
	// 开始广度优先遍历
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		// 讲道理我用C++11的一个最主要原因就是auto关键字
		for (auto it = graph[curr.first].begin(); it != graph[curr.first].end(); it++)
		{
			if (*it == v)
				// 碰到立刻返回遍历深度-1（结果是中间节点的个数），也就是该节点上一层节点也就是curr的深度
				return curr.second;
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(make_pair(*it, curr.second + 1));
			}
		}
	}
	// 广度优先遍历不到？
	return -1;
}