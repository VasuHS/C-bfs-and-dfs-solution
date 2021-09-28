// bfs.cpp : Defines the entry point for the console application.
// BFS is level wise search or tree travesal in any type of tree
// in BFS use queue to push and pop the elelemts 
// data structures used : vector and queue.

#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class BFS
{
	vector<vector<int>> v1;
	vector<bool> visitor{false};
	queue<int> q;
public:
	BFS(int nodes)
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
			int node = q.front();
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
	BFS bfs(n);
	int a, b;
	for (int i = 0; i < e; ++i)
	{
		//cout << "enter a and b" << endl;
		cin >> a >> b;
		bfs.addedges(a, b);
	}

	bfs.printEdges();

	bfs.bfsFunction(0);
    return 0;
}
