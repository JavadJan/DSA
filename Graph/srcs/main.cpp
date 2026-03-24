#include "../includes/Graph.hpp"

int main()
{
	//std::vector<std::vector<int> > v (10, std::vector<int>(5, 0));
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	for (size_t j = 0; j < v[i].size(); j++)
	//	{
	//		/* code */
	//		std::cout << v[i][j] << " " ;
	//	}
		
	//	std::cout << std::endl;
	//}
	std::vector<std::vector<int> > edges = {{0, 1},{0, 2},{1, 2}};
	Graph g(3, edges);
	std::cout << g << std::endl;
	return 0;
}
