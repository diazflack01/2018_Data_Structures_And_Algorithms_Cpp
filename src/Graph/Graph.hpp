#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <exception>

template<typename T>
class Graph
{
public:
	Graph(int numOfVertex);
	void addEdge(int v1, int v2);

	// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
	void Dfs(int v); //stack
	std::vector<T> DfsWithRet(int v);
	// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
	void Bfs(int v); //queue
	std::vector<T> BfsWithRet(int v);

private:
	void DfsUtil(const int v, bool*& visited);
	void DfsUtil(std::vector<T>& container, const int v, bool*& visited);
	const unsigned maxNumOfVertex;
	std::list<T>* adjacencyList;
};

template<typename T>
Graph<T>::Graph(int numOfVertex) : maxNumOfVertex(numOfVertex)
{
	adjacencyList = new std::list<T>[maxNumOfVertex];
}

template<typename T>
void Graph<T>::addEdge(int v1, int v2)
{
	if(0 > v1 || 0 > v2 || (int)maxNumOfVertex <= v1 || (int)maxNumOfVertex <= v2)
		throw std::out_of_range("Vertex value passed invalid");
	adjacencyList[v1].push_back(v2);
}

template<typename T>
void Graph<T>::Dfs(int v)
{
	bool* isVisited = new bool[maxNumOfVertex];

	for(auto i = 0u; i < maxNumOfVertex; ++i)
		isVisited[i] = false;

	DfsUtil(v, isVisited);
	std::cout << std::endl;
}

template<typename T>
void Graph<T>::DfsUtil(const int v, bool*& visited)
{
	visited[v] = true;

	std::cout << v << ", ";
	for(auto it = adjacencyList[v].begin(); it != adjacencyList[v].end(); ++it)
	{
		if(!visited[*it])
			DfsUtil(*it, visited);
	}
}

template<typename T>
std::vector<T> Graph<T>::DfsWithRet(int v)
{
	std::vector<T> ret;
	bool* isVisited = new bool[maxNumOfVertex];
	for(auto i = 0u; i < maxNumOfVertex; ++i)
		isVisited[i] = false;
	DfsUtil(ret, v, isVisited);
	return ret;
}

template<typename T>
void Graph<T>::DfsUtil(std::vector<T>& container, const int v, bool*& visited)
{
	visited[v] = true;
	container.push_back(v);
	for(auto it = adjacencyList[v].begin(); it != adjacencyList[v].end(); ++it)
	{
		if(!visited[*it])
		{
			DfsUtil(container, *it, visited);
		}
	}
}

template<typename T>
void Graph<T>::Bfs(int v)
{
	bool* const isVisited = new bool[maxNumOfVertex];
	for(auto i =0u; i < maxNumOfVertex; ++i)
		isVisited[i] = false;

	std::queue<std::pair<int, std::list<T>>> queue;
	queue.push(std::make_pair(v, adjacencyList[v]));

	while(!queue.empty())
	{
		auto node = queue.front();
		isVisited[node.first] = true;
		std::cout << node.first << " ";

		for(auto it = node.second.begin(); it != node.second.end(); ++it)
		{
			if(!isVisited[*it])
				queue.push(std::make_pair(*it, adjacencyList[*it]));
		}
		queue.pop();
	}
	std::cout << std::endl;
}

template<typename T>
std::vector<T> Graph<T>::BfsWithRet(int v)
{
	std::vector<T> ret;
	bool* isVisited = new bool[maxNumOfVertex];

	for(auto i = 0u; i < maxNumOfVertex; ++i)
		isVisited[i] = false;

	std::queue<std::pair<int, std::list<T>>> queue;
	queue.push(std::make_pair(v, adjacencyList[v]));

	while(!queue.empty())
	{
		auto node = queue.front();
		isVisited[node.first] = true;
		ret.push_back(node.first);

		for(auto it = node.second.begin(); it != node.second.end(); ++it)
		{
			if(!isVisited[*it])
			{
				queue.push(std::make_pair(*it, adjacencyList[*it]));
			}
		}
		queue.pop();
	}
	return ret;
}