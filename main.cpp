// add your code as appropriate 
#include <iostream>
#include <fstream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //  get_east_storage("01/01/2018");
  std::cout << "Enter date: 05/20/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl << std::endl;
  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "MAXimum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter starting date: 09/13/2018" << std::endl << "Enter ending date: 09/17/2018" << std::endl;
  std::cout << "09/13/2018 " << compare_basins("09/13/2018") << std::endl; 
  std::cout << "09/14/2018 " << compare_basins("09/14/2018") << std::endl;
  std::cout << "09/15/2018 " << compare_basins("09/15/2018") << std::endl;
  std::cout << "09/16/2018 " << compare_basins("09/16/2018") << std::endl;
  std::cout << "09/17/2018 " << compare_basins("09/17/2018") << std::endl << std::endl;
  std::cout << "Enter earlier date: 05/29/2018" << std::endl << "Enter late date: 06/02/2018" << std::endl;
  reverse_order("05/29/2018", "06/02/2018");
  
  return 0;
}
