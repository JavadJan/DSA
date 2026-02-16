/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:40:10 by codespace         #+#    #+#             */
/*   Updated: 2025/08/01 13:10:02 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vect2.hpp"

/*

Create a class vect2 representing a mathematical vector of dimension 2
containing elements of type int

==== WORKS ====

*/

// vect2
int main(void)
{
    vect2 v1; // 0,0
    vect2 v2(1, 2); // 1,2
    const vect2 v3(v2); // 1,2
    vect2 v4 = v2; // 1,2

    std::cout << "\033[1;36m [PRINT ALL VARS] \033[0m" << std::endl;
    std::cout << "v1 " << v1 << std::endl;
    std::cout << "v2 " << v2 << std::endl;
    std::cout << "v3 " << v3 << std::endl;
    std::cout << "v4 " << v4 << std::endl;

    
    std::cout << "\033[1;36m [TEST PRINT] \033[0m" << std::endl;
    std::cout << "v2 " << v2 << std::endl;
    std::cout << "v2 {" << v2[0] << ", " << v2[1] << "}" << std::endl;

    
    std::cout << "\033[1;36m [TEST INC DEC] \033[0m" << std::endl;
    std::cout << v4++ << " | print (1, 2) is (2,3)" << std::endl;
    std::cout << ++v4 << " | print (3, 4) is (3,4)" << std::endl;
    std::cout << v4-- << " | print (3, 4) is (2,3)" << std::endl;
    std::cout << --v4 << " | print (1, 2) is (1,2)" << std::endl;

    std::cout << "\033[1;36m [TEST OVERRIDES] \033[0m" << std::endl;
    v2 += v3;
    std::cout << "(v2 += v3) result: " << v2 << " (2, 4)"<< std::endl;
    v1 -= v2;
    std::cout << "(v1 -= v2) result: " << v1 << " (-2, -4)"<< std::endl;
    v2 = v3 + v3 * 2; // 3,6
    std::cout << "(v2 = v3 + v3 * 2) result: " << v2 << " (3,6)"<< std::endl;
    v2 = 3 * v2; // 9,18
    std::cout << "(v2 = 3 * v2) result: " << v2 << " (9,18)"<< std::endl;
    v2 += v2 += v3; // 20,40
    std::cout << "(v2 += v2 += v3) result: " << v2 << " (20,40)"<< std::endl;
    v1 *= 42; // -84,-168
    std::cout << "(v1 *= 42) result: " << v1 << " (-84,-168)"<< std::endl;
    v1 = v1 - v1 + v1;
    std::cout << "(v1 = v1 - v1 + v1) result: " << v1 << " (-84,-168)"<< std::endl;


    std::cout << "\033[1;36m [TEST OTHER] \033[0m" << std::endl;
    std::cout << "normal: " << v2 << " negativ: " << -v2 << std::endl;
    
    std::cout << "v1[1] = " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "(v1[1] = 12) v1[1] = " << v1[1] << std::endl;
    
    std::cout << "\033[1;36m [TEST COMPARISON] \033[0m" << std::endl;
    std::cout << "(v1 v3) " << v1 << v3 << std::endl;
    if (v1 == v3)
        std::cout << "(v1 == v3) true" << std::endl;
    else
        std::cout << "(v1 == v3) false" << std::endl;
    if (v1 != v3)
        std::cout << "(v1 != v3) true" << std::endl;
    else
        std::cout << "(v1 != v3) false" << std::endl;

    return(0);
}
