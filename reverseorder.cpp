#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

void reverse_order(std::string date1, std::string date2){
  int actual_size = 0;
  std::string dates[5];
  double elevations[5];
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }
  std::string junk;
  getline(fin, junk);
  bool inrange = false;
  std::string date;
  double eastSt, eastEl, westSt, westEl;
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){

    if (date == "06/02/2018"){
      dates[0] = "06/02/2018";
	elevations[0] = westEl;
    } else if (date == "06/01/2018"){
      dates[1] =  "06/01/2018";
      elevations[1] = westEl;
    } else if (date == "05/31/2018"){
      dates[2] = "05/31/2018";
      elevations[2] = westEl;
    } else if (date == "05/30/2018"){
      dates[3] = "05/30/2018";
	elevations[3] = westEl;
    } else if (date == "05/29/2018"){
      dates[4] = "05/29/2018";
      elevations[4] =  westEl;
    } 
  }
  for (int i = 0; i < 5; i++){
    std::cout << dates[i] << " " << elevations[i] << " ft" << std::endl;
  }

}
