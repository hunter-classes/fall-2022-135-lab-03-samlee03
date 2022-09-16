// add your code
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>


/*std::ifstream fin("Current_reservoir_Levels.tsv");
if (fin.fail()) {
  std::cerr << "File cannot be opened for reading." << std::endl;
  exit(1);
 }
*/
//std::string date_;
//double eastSt, eastEl, westSt, westEl;
double get_east_storage(std::string date)
{

   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
   }
 
   std::string junk;
   getline(fin, junk);
   std::string date_;
   double eastSt, eastEl, westSt, westEl;
   while (fin >> date_ >> eastSt >> eastEl >> westSt >> westEl) {
     fin.ignore(INT_MAX, '\n');
     if (date_ == date){
       fin.close();
       return eastSt;
     }
   }
   return 0;
 }

double get_min_east() {
  double min = 10000;
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }
  std::string junk;
  getline(fin, junk);
  std::string date_;
  double eastSt, eastEl, westSt, westEl;
  while (fin >> date_ >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');
    if (eastSt < min){
      min = eastSt;
    }
  }
  return min;
}

double get_max_east() {
 double min = 0;
 std::ifstream fin("Current_Reservoir_Levels.tsv");
 if (fin.fail()){
   std::cerr << "File cannot be opened for reading." << std::endl;
   exit(1);
 }
 std::string junk;
 getline(fin, junk);
 std::string date_;
 double eastSt, eastEl, westSt, westEl;
 while (fin >> date_ >> eastSt >> eastEl >> westSt >> westEl) {
   fin.ignore(INT_MAX, '\n');
   if (eastSt > min){
     min = eastSt;
   }
 }
 
 return min;
}

std::string compare_basins(std::string date){
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk;
  getline(fin, junk);

  std::string date_;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date_ >> eastSt >> eastEl >> westSt >> westEl){
    fin.ignore(INT_MAX, '\n');
    if (date == date_){
      if(eastEl < westEl){
	return "West";
      } else if (westEl < eastEl) {
	return "East";
      } else {
	return "Equal";
      }
    }
    
  }
  return "";
}
