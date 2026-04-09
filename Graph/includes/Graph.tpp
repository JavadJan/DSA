#include "./Graph.hpp"

template <typename T>
Graph<T>::Graph(int v, std::vector<std::vector<T> > &edges):V(v), G(edges)
{
}
template <typename T>
Graph<T>::~Graph(){}

template <typename T>
Graph<T>::Graph(const Graph& b): V(b.v), G(b.G)
{	
}

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph& other)
{
	if( this != &other)
	{
		this->G = other.G;
		this->V = other.v;
	}
}

template<typename T>
int Graph<T>::getV()
{
	return this->V;
}

template<typename T>
const std::vector<std::vector<T> >& Graph<T>::getG() const
{
	return this->G;
}

/* BFS AND DFS */
template <typename T>
std::vector<int> Graph<T>::bfs(int start)
{
	std::queue<int> q;

	std::vector<bool> visited(this->V, false);
	std::vector<int> res;

	int i = start;

	visited[i] = true;

	q.push(i);

	while(!q.empty())
	{
		int cur = q.front();
		res.push_back(cur);
		q.pop();
		for (int neighbor = 0; neighbor < this->V; ++neighbor) {
			if (this->G[cur][neighbor] != 0 && !visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
	return res;
}
template <typename T>
void Graph<T>::RDFS(int start, std::vector<bool>& visited, std::vector<int>& res)
{
	visited[start] = true;
	res.push_back(start);
	for(int j = 1; j <= this->V; j++)
	{
		if (this->G[start][j] != 0 && !visited[j])
			RDFS(j, visited, res);
	}
}

template <typename T>
std::vector<int> Graph<T>::dfs(int start)
{
	std::vector<bool> visited(this->V, false);
	std::vector<int> res;
	RDFS(start, visited, res);
	return res;
}