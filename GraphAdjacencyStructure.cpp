#include "GraphAdjacencyStructure.h"
#include <Queue>
#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

bool GraphAdjacencyStructure::addEdge(int one, int two, bool oriented)
{
	if (!bvag)
	{
		if (one == two)
			return false;
		if (one > countTops || two > countTops || one < 1 || two < 1)
			return false;
		if (!oriented)
		{
			for (int i = 0; i < this->Adjacency[one - 1].size(); i++)
				if (this->Adjacency[one - 1][i] == two - 1)
					return false;
			this->Adjacency[one - 1].push_back(two - 1);
			this->Adjacency[two - 1].push_back(one - 1);
			return true;
		}
		for (int i = 0; i < this->Adjacency[one - 1].size(); i++)
			if (this->Adjacency[one - 1][i] == two - 1)
				return false;
		this->Adjacency[one - 1].push_back(two - 1);
		return true;
	}
}

bool GraphAdjacencyStructure::addEdge(int one, int two, int vag, bool oriented)
{
	this->bvag = false;
	bool check = this->addEdge(one, two, oriented);
	this->bvag = true;
	if (check)
	{
		if (oriented)
		{
			this->Vag[0].push_back(one);
			this->Vag[1].push_back(two);
			this->Vag[2].push_back(vag);
			return true;
		}
		this->Vag[0].push_back(one);
		this->Vag[1].push_back(two);
		this->Vag[2].push_back(vag);
		this->Vag[0].push_back(two);
		this->Vag[1].push_back(one);
		this->Vag[2].push_back(vag);
		return true;
	}
	return check;
}

void GraphAdjacencyStructure::print()
{
	cout << "count Tops: " << countTops << endl;
	for (int i = 0; i < countTops; i++)
	{
		cout << i + 1;
		if (Adjacency[i].size() != 0)
		{
			cout << "(";
			for (int j = 0; j < Adjacency[i].size(); j++)
			{
				cout << Adjacency[i][j]+1;
				if (bvag)
				{
					for (int k = 0; k < Vag[0].size(); k++)
					{
						if (i + 1 == Vag[0][k] && Adjacency[i][j]+1 == Vag[1][k])
						{
							cout << "{" << Vag[2][k] << "}";
							break;
						}
					}
				}
				if (j < Adjacency[i].size() - 1)
					cout << ",";
			}
			cout << ")";
		}
		cout << endl;

	}
}

void GraphAdjacencyStructure::rd(int countTops, int countEdges)
{
	int N = countTops * (countTops - 1) / 2;
	if (countEdges > N)
	{
		//err;  
		return;
	}
	srand(time(0));
	this->countTops = countTops;
	this->Adjacency.resize(countTops);
	vector<vector <int>> edg = vector<vector <int>>(2);
	for (int i = 0; i < 2; i++)
		edg[i].resize(N);
	int num = 0;
	for (int i = 0; i < countTops; i++)
	{
		for (int j = i + 1; j < countTops; j++)
		{
			edg[0][num] = i;
			edg[1][num++] = j;
		}
	}
	int r;
	bool oriented;
	int c= 0;
	for (int i = 0; i < countEdges; i++)
	{

		r = 0 + rand() % edg[0].size();
		oriented = 0 + rand() % 2;
		if (!this->bvag)
			this->addEdge(edg[0][r] + 1, edg[1][r] + 1, oriented);
		else
		{
			this->addEdge(edg[0][r] + 1, edg[1][r] + 1, 1 + rand() % 15, oriented);
			c++;
		}
		edg[0].erase(edg[0].begin() + r);
		edg[1].erase(edg[1].begin() + r);
	}
}

vector<vector<int>> GraphAdjacencyStructure::getGraphM()
{
	vector<vector<int>> GrM = vector<vector<int>>(countTops);
	for (int i = 0; i < countTops; i++)
	{
		GrM[i].resize(countTops);
	}
	for (int i = 0; i < this->Adjacency.size(); i++)
	{
		for (int j = 0; j < this->Adjacency[i].size(); j++)
		{
			GrM[i][Adjacency[i][j]] = 1;
		}
	}
	return GrM;
}

void GraphAdjacencyStructure::setGraph(vector<vector<int>> Gr)
{
	this->countTops = Gr.size();
	this->Adjacency = Gr;
	cout <<"endl" << "Complite." << endl;
}

bool GraphAdjacencyStructure::isConnected()
{
	queue<int> Queue;
	vector<int> nodes = vector<int>(this->countTops);
	vector<vector<int>> Matrix = this->getGraphM();
	Queue.push(0);
	while (!Queue.empty())
	{
		int node = Queue.front();
		Queue.pop();
		nodes[node] = 2;
		for (int j = 0; j < countTops; j++)
		{
			if (Matrix[node][j] == 1 && nodes[j] == 0)
			{
				Queue.push(j);
				nodes[j] = 1;
			}
		}
	}
	for (int i = 0; i < countTops; i++)
		if (nodes[i] != 2)
			return false;
	return true;
}

void GraphAdjacencyStructure::Depth_firstSearch()
{
	vector<vector<int>> Matrix = this->getGraphM();
	stack<int> Stack;
	vector<int> nodes = vector<int>(this->countTops);
	vector<int> buff;
	Stack.push(0);
	while (!Stack.empty())
	{ 
		int node = Stack.top();
		Stack.pop();
		if (nodes[node] == 2) continue;
		nodes[node] = 2; 
		for (int j = this->countTops - 1; j >= 0; j--)
		{
			if (Matrix[node][j] == 1 && nodes[j] != 2)
			{ 
				if (!bvag)
				{
					Stack.push(j);
				}
				else
				{
					buff.push_back(j);
				}
				nodes[j] = 1;
			}
		}
		if (bvag)
		{
			vector<int>vags;
			for (int i = 0; i < buff.size(); i++)
			{
				for (int j = 0; j < this->Vag[0].size(); j++)
				{
					if (node + 1 == Vag[0][j] && buff[i] + 1 == Vag[1][j])
					{
						vags.push_back(Vag[2][j]);
					}
				}
			}
			int s = buff.size();
			for (int i = 0; i < s; i++)
			{
				int max = 0, n = 0;
				for (int j = 0; j < buff.size(); j++)
				{
					if (max < vags[j])
					{
						max = vags[j];
						n = j;
					}
				}
				Stack.push(buff[n]);
				vags.erase(vags.begin() + n);
				buff.erase(buff.begin() + n);
			}
		}
		cout << node + 1 << endl;
	}
}

void GraphAdjacencyStructure::DijkstryAlgoritm(int a, int b)
{
	if (a == b) return;
	int big_num = 1000000;
	vector<vector<int>> locMatrix = this->getGraphM();
	for (int i = 0; i < Vag[0].size(); i++)
	{
		locMatrix[Vag[0][i] - 1][Vag[1][i] - 1] = Vag[2][i];
	}
	vector<int> pos = vector<int>(this->countTops), node = vector<int>(this->countTops);
	int min(0), index_min(0);
	for (int i = 0; i < this->countTops; ++i) {
		pos[i] = big_num;
		node[i] = 0;
	}
	pos[a - 1] = 0;
	for (int i = 0; i < this->countTops - 1; ++i) {
		min = big_num;
		for (int j = 0; j < this->countTops; ++j) {
			if (!node[j] && pos[j] < min) {
				min = pos[j];
				index_min = j;
			}
		}
		node[index_min] = true;
		for (int j = 0; j < this->countTops; ++j) {
			if (!node[j] && locMatrix[index_min][j] > 0 && pos[index_min] != big_num
				&& pos[index_min] + locMatrix[index_min][j] < pos[j]) {
				pos[j] = pos[index_min] + locMatrix[index_min][j];
			}
		}
	}
	cout << a << " -> " << b << " = " << pos[b - 1] << "\n";
	cout << endl;
}
void GraphAdjacencyStructure::DijkstryAlgoritm(int a)
{
	for (int i = 1; i <= countTops; i++)
		if (a != i)
			DijkstryAlgoritm(a, i);
}

void GraphAdjacencyStructure::DijkstryAlgoritm()
{
	for (int i = 1; i <= countTops; i++)
		DijkstryAlgoritm(i);
}

void GraphAdjacencyStructure::topologicalSortUtil(int v, bool visited[], stack<int>& Stack, vector<vector<int>> adj)
{
	visited[v] = true;
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack, adj);
	Stack.push(v);
}

void GraphAdjacencyStructure::topologicalSort()
{
	vector<vector<int>> adj = Adjacency;
	stack<int> Stack;

	bool* visited = new bool[countTops];
	for (int i = 0; i < countTops; i++)
		visited[i] = false;

	for (int i = 0; i < countTops; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack, adj);
	while (Stack.empty() == false)
	{
		cout << Stack.top() + 1 << " ";
		Stack.pop();
	}
}

vector<vector<int>> GraphAdjacencyStructure::bildSpTree()
{
	vector<vector<int>> Matrix = this->getGraphM();
	vector<vector<int>> SpTree = vector<vector<int>>(countTops);
	for (int i = 0; i < countTops; i++)
		SpTree[i].resize(countTops);
	stack<int> Stack;
	vector<int> nodes = vector<int>(this->countTops);
	vector<int> buff;
	Stack.push(0);
	while (!Stack.empty())
	{
		int node = Stack.top();
		Stack.pop();
		if (nodes[node] == 2) continue;
		nodes[node] = 2;
		for (int j = this->countTops - 1; j >= 0; j--)
		{
			if (Matrix[node][j] == 1 && nodes[j] != 2)
			{
				if (!bvag)
				{
					bool c = true;
					for (int i = 0; i < countTops; i++)
					{
						if (SpTree[j][i] == 1)
							c = false;
					}
					if (c)
					{
						SpTree[node][j] = 1;
						SpTree[j][node] = 1;
					}
					Stack.push(j);
				}
				else
				{
					buff.push_back(j);
				}
				nodes[j] = 1;
			}
		}
		if (bvag)
		{
			vector<int>vags;
			for (int i = 0; i < buff.size(); i++)
			{
				for (int j = 0; j < this->Vag[0].size(); j++)
				{
					if (node + 1 == Vag[0][j] && buff[i] + 1 == Vag[1][j])
					{
						vags.push_back(Vag[2][j]);
					}
				}
			}
			int s = buff.size();
			for (int i = 0; i < s; i++)
			{
				int max = 0, n = 0;
				for (int j = 0; j < buff.size(); j++)
				{
					if (max < vags[j])
					{
						max = vags[j];
						n = j;
					}
				}
				bool c = true;
				for (int i = 0; i < countTops; i++)
				{
					if (SpTree[buff[n]][i] == 1)
						c = false;
				}
				if (c)
				{
					SpTree[node][buff[n]] = 1;
					SpTree[buff[n]][node] = 1;
				}
				Stack.push(buff[n]);
				vags.erase(vags.begin() + n);
				buff.erase(buff.begin() + n);
			}
		}

	}
	vector<vector<int>> GrapfAS = vector<vector<int>>(countTops);
	for (int i = 0; i < GrapfAS.size(); i++)
	{
		for (int j = 0; j < countTops; j++)
		{
			if (SpTree[i][j] == 1)
			{
				GrapfAS[i].push_back(j);

			}
		}
	}
	return GrapfAS;
}
void GraphAdjacencyStructure::Kruskal()
{
	if (bvag)
	{
		int N = Vag[0].size(), M = N * 2;
		vector<Node> arr;
		vector<bool> visited(M);
		for (int i = 0; i < Vag[0].size(); i++)
		{
			arr.push_back(Node(Vag[0][i], Vag[1][i], Vag[2][i]));
		}

		sort(arr.begin(), arr.end(), compare);
		int weight = 0;
		for (int i = 0; i < N; i++)
		{
			if (!visited[arr[i].start] || !visited[arr[i].end])
			{
				weight += arr[i].length;
				visited[arr[i].start] = true;
				visited[arr[i].end] = true;
			}
		}
		cout << "Минимальный вес связующего дерева:";
		cout << weight << endl;
	}
}
