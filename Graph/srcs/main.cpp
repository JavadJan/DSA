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
	std::vector<std::vector<int> > edges = {{0, 0, 0, 0, 0, 0, 0, 0},  // 0
											{0, 0, 1, 1, 1, 0, 0, 0}, // 1
											{0, 1, 0, 1, 0, 0, 0, 0}, // 2
											{0, 1, 1, 0, 1, 1, 0, 0}, // 3
											{0, 1, 0, 1, 0, 1, 0, 0}, // 4
											{0, 0, 0, 1, 1, 0, 1, 1},
											{0, 0, 0, 0, 0, 1, 0, 0},
											{0, 0, 0, 0, 0, 1, 0, 0},
											};
	Graph<int> g(7, edges);
	std::vector<int> res = g.bfs(1);
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " " ;
	}

	std::cout << std::endl << "dfs: ";
	
	std::vector<int> resDFS = g.dfs(4);
	for (size_t i = 0; i < resDFS.size(); i++)
	{
		std::cout << resDFS[i] << " " ;
	}
	std::cout << std::endl;
	std::cout << g << std::endl;
	return 0;
}
