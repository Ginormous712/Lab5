#pragma once
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class GraphAdjacencyStructure
{
	struct Node
	{
		int start;
		int end;
		int length;
		Node(int s, int e, int l)
		{
			start = s;
			end = e;
			length = l;
		}
	};
	vector<vector<int>> Adjacency;
	vector<vector<int>> Vag;
	bool bvag;
	int countTops;
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack, vector<vector<int>> adj);
	static bool compare(Node a, Node b)
	{
		return a.length < b.length;
	}
public:
	GraphAdjacencyStructure(int countTops, bool bvag) :
		countTops(countTops), bvag(bvag)
	{
		Adjacency.resize(countTops);
		for (int i = 0; i < Adjacency.size(); i++)
			Adjacency[i].resize(0);
		if (bvag)
			Vag.resize(3);
	}
	bool addEdge(int, int, bool);
	bool addEdge(int, int, int, bool);
	void print();
	void rd(int countTops, int countEdges);
	vector<vector<int>>getGraphM();
	void setGraph(vector<vector<int>>);
	//task 5
	bool isConnected();
	//task 11
	void Depth_firstSearch();
	//task 15
	void DijkstryAlgoritm(int a, int b);
	void DijkstryAlgoritm(int a);
	void DijkstryAlgoritm();
	//task 17
	void topologicalSort();
	//task 19
	vector<vector<int>> bildSpTree();
	//task 21
	void Kruskal();
};

