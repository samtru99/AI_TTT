#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>

#include "../include/Generate_Q_Table.h"
int main(int argc, char* argv[])
{
    float epsilon = .7;
    float learning_rate = .4;
    float gamma = .9;
    int num_of_games = 100000;

    if (argc == 2 && std::string(argv[1]) == "h")
    {
        std::cout << "this is the help info " << std::endl;
    }
    
    if (std::string(argv[1]) == "n")
    {
        char board[9] = {'_','_','_',
                        '_','_','_',
                        '_','_','_'};

        
        std::unordered_map< std::string,  std::vector < std::pair<std::string, int> >> Q_table_1;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, int> >> Q_table_3;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, int> >> Q_table_5;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, int> >> Q_table_7;
        std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string, int> >> > Model_Q_Table;
        
        Gen_Q_Table generator;

        generator.init_function(Model_Q_Table, 0,board);
    }
    return 0;

}