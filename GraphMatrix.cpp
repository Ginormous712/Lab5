#include "GraphMatrix.h"
#include <ctime>
#include <queue>
#include <iomanip>
#include <stack>
#include <algorithm>
bool GraphMatrix::addEdge(int one, int two, bool oriented)
{
	if (!bvag)
	{
		if (one == two)
			return false;
		if (one > countTops || two > countTops || one < 1 || two < 1)
			return false;
		if (this->Matrix[one - 1][two - 1] == 1 || this->Matrix[two - 1][one - 1] == 1)
			return false;
		if (!oriented)
		{
			this->Matrix[one - 1][two - 1] = 1;
			this->Matrix[two - 1][one - 1] = 1;
			return true;

		}
		this->Matrix[one - 1][two - 1] = 1;
		this->Matrix[two - 1][one - 1] = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool GraphMatrix::addEdge(int one, int two, int vag, bool oriented)
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

void GraphMatrix::print()
{
	cout << "count Tops: " << countTops << endl;
	vector<int> el;
	vector<vector<int>> pr = this->Matrix;
	if (bvag)
	{
		for (int i = 0; i < Vag[0].size(); i++)
		{
			if (pr[Vag[0][i] - 1][Vag[1][i] - 1] == 1)
				pr[Vag[0][i]-1][Vag[1][i]-1] = Vag[2][i];
		}
	}
	for (int i = 0; i < countTops; i++)
	{
		for (int j = 0; j < countTops; j++)
		{
			cout << setw(3) << pr[i][j];
		}
		cout << endl;
	}
	
}

void GraphMatrix::rd(int countTops, int countEdges)
{
	
	if (countEdges > (countTops * (countTops - 1) / 2))
	{
		cout << "error" << endl;
		return;
	}
	
	this->countTops = countTops;
	srand(time(0));
	this->Matrix.resize(countTops);
	for (int i = 0; i < countTops; i++)
		Matrix[i].resize(countTops);
	int N = countTops * (countTops - 1) / 2;
	vector<vector <int>> edg = vector<vector <int>>(2);
	for (int i = 0; i < 2; i++)
		edg[i].resize(N);
	int num = 0;
	for (int i = 0; i < countTops; i++)
	{
		for(int j = i+1;j < countTops;j++)
		{ 
			edg[0][num] = i;
			edg[1][num++] = j;
		}
	}
	int r;
	bool oriented;
	for (int i = 0; i < countEdges; i++)
	{
		
		r = 0 + rand() % edg[0].size();
		oriented = 0 + rand() % 2;
		if(!this->bvag)
			this->addEdge(edg[0][r]+1, edg[1][r]+1, oriented);
		else
			this->addEdge(edg[0][r] + 1, edg[1][r] + 1, 1 + rand() % 15, oriented);
		edg[0].erase(edg[0].begin() + r);
		edg[1].erase(edg[1].begin() + r);
	}
}

vector<vector<int>> GraphMatrix::GetGraphAS()
{
	vector<vector<int>> GrapfAS = vector<vector<int>>(this->countTops);
	for (int i = 0; i < GrapfAS.size(); i++)
	{
		for (int j = 0; j < countTops; j++)
		{
			if (Matrix[i][j] == 1)
			{
				GrapfAS[i].push_back(j);
				
			}
		}
	}
	return GrapfAS;
}

void GraphMatrix::setGr(vector<vector<int>> Gr)
{
	this->countTops = Gr.size();
	this->Matrix = Gr;
	cout << endl<<"Complite." << endl;
}

bool GraphMatrix::isConnected()
{
	queue<int> Queue;
	vector<int> nodes = vector<int>(this->countTops);
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

void GraphMatrix::Depth_firstSearch()
{
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
		for (int j = this->countTops-1; j >= 0; j--)
		{ 
			if (this->Matrix[node][j] == 1 && nodes[j] != 2)
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
					if (node +1 == Vag[0][j] && buff[i]+1 == Vag[1][j])
					{
						vags.push_back(Vag[2][j]);
					}
				}
			}
			int s = buff.size();
			for (int i = 0; i < s; i++)
			{
				int max = 0,n = 0;
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

void GraphMatrix::DijkstryAlgoritm(int a, int b)
{
	if (a == b) return;
	int big_num = 1000000;
	vector<vector<int>> locMatrix = this->Matrix;
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
	pos[a-1] = 0;
	for (int i = 0; i < this->countTops-1; ++i) {   
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
	cout << a << " -> " << b << " = " << pos[b-1] << "\n";
	cout << endl;
}

void GraphMatrix::DijkstryAlgoritm(int a)
{
	for(int i = 1;i <= countTops;i++)
		if (a != i)
			DijkstryAlgoritm(a, i);
}

void GraphMatrix::DijkstryAlgoritm()
{
	for (int i = 1; i <= countTops; i++)
			DijkstryAlgoritm(i);
}

void GraphMatrix::topologicalSortUtil(int v, bool visited[], stack<int>& Stack, vector<vector<int>> adj)
{
	visited[v] = true;
	vector<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack,adj);
	Stack.push(v);
}
void GraphMatrix::topologicalSort()
{
	vector<vector<int>> adj= this->GetGraphAS();
	stack<int> Stack;

	bool* visited = new bool[countTops];
	for (int i = 0; i < countTops; i++)
		visited[i] = false;

	for (int i = 0; i < countTops; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack, adj);
	while (Stack.empty() == false)
	{
		cout << Stack.top()+1 << " ";
		Stack.pop();
	}
}

vector<vector<int>> GraphMatrix::bildSpTree()
{
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
			if (this->Matrix[node][j] == 1 && nodes[j] != 2)
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
				nodes[j]=1;
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
	return SpTree;
}

void GraphMatrix::Kruskal()
{
	if (bvag)
	{
		int N = Vag[0].size(), M = N*2;
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
