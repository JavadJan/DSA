# ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>

template <typename T>
class Graph {
	private:
		std::vector<std::vector<T> > G;
		int v;
	public:
		Graph(int v, std::vector<std::vector<T> > &edges);
		~Graph();
		Graph(const Graph& b);
		Graph& operator=(const Graph& b);


		int getV();
		const std::vector<std::vector<T> >& getG()const;

};



template <typename T>
std::ostream& operator<<(std::ostream& o, const Graph<T>& a)
{
    const std::vector<std::vector<T> >& g = a.getG();

    for (size_t i = 0; i < g.size(); i++) {
        o << i << ": ";

        for (size_t j = 0; j < g[i].size(); j++) {
            o << g[i][j] << " ";
        }

        o << "\n";
    }

    return o;
}


#include "./Graph.tpp"
#endif