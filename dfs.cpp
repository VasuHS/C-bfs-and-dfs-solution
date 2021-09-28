// dfs.cpp : Defines the entry point for the console application.
// Depth First Search (DFS) algorithm traverses a graph in a depthward 
// motion and uses a stack to remember to get the next vertex to start a search, 
// when a dead end occurs in any iteration.

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class DFS
{
	vector<vector<int>> v1;
	vector<bool> visitor{ false };
	stack<int> q;
public:
	DFS(int nodes)
	{
		v1.assign(nodes, vector<int>());
		visitor.assign(nodes, false);
	}
	void addedges(int fromNode, int toNode)
	{
		v1[fromNode].push_back(toNode);
	}
	void bfsFunction(int u)//bfs of a number u
	{
		q.push(u);
		visitor[u] = true;
		while (!q.empty())
		{
			int node = q.top();
			q.pop();
			cout << node << " ";

			for (auto i = v1[node].begin(); i != v1[node].end(); ++i)
			{
				if (!visitor[*i]) {
					q.push(*i);
					visitor[*i] = true;
				}
			}
		}
	}
	void printEdges()
	{
		for (auto i = 0; i < v1.size(); ++i)
		{
			for (int j = 0; j < v1[i].size(); j++)
			{
				cout << i << "-------" << v1[i][j] << endl;
			}
		}
	}
};

int main()
{
	int n, e;
	cout << "enter the nodes and edges" << endl;
	cin >> n >> e;
	DFS dfs(n);
	int a, b;
	for (int i = 0; i < e; ++i)
	{
		//cout << "enter a and b" << endl;
		cin >> a >> b;
		dfs.addedges(a, b);
	}

	dfs.printEdges();

	dfs.bfsFunction(1);
	return 0;
}



