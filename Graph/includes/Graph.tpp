#include "./Graph.hpp"

template <typename T>
Graph<T>::Graph(int v, std::vector<std::vector<T> > &edges):v(v), G(edges)
{
}
template <typename T>
Graph<T>::~Graph(){}

template <typename T>
Graph<T>::Graph(const Graph& b): v(b.v), G(b.G)
{	
}

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph& other)
{
	if( this != &other)
	{
		this->G = other.G;
		this->v = other.v;
	}
}

template<typename T>
int Graph<T>::getV()
{
	return this->v;
}

template<typename T>
const std::vector<std::vector<T> >& Graph<T>::getG() const
{
	return this->G;
}