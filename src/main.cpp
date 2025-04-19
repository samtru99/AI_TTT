#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <string>
#include <vector>

#include "../include/Generate_Q_Table.h"

// Function to print the contents of an unordered_map
void printUnorderedMap(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data) {

    for(int i = 0; i < 1; i++)
    {
        std::cout << "Q_table_"<<i<<std::endl;
        for (const auto& pair : Model_Data[i]) 
        {
            std::cout << "Key: " << pair.first << std::endl;
            std::cout << "Values:" << std::endl;
            for (const auto& innerPair : pair.second) {
                std::cout << "    First: " << innerPair.first << ", Second: " << innerPair.second << std::endl;
            }
            std::cout << std::endl;
        }
    }
}


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
    
    // if (std::string(argv[1]) == "n")
    // {
        

        std::unordered_map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_1;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_3;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_5;
        std::unordered_map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_7;
        std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string, double> >> > Model_Q_Table;
        
        Model_Q_Table.push_back(Q_table_1);        
        Model_Q_Table.push_back(Q_table_3);        
        Model_Q_Table.push_back(Q_table_5);        
        Model_Q_Table.push_back(Q_table_7);        

        Gen_Q_Table generator;
        //generator.init_function(Model_Q_Table);
        std::vector<char> board = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};    
        for(int x_first_move = 0; x_first_move < 9; x_first_move+=1)
        {
            std::vector<char> temp(board);
            temp[x_first_move] = 'X';
            std::string temp_str(temp.begin(), temp.end());
            generator.find_moves(Model_Q_Table, 0, temp);
        }
        std::cout << "map size is " << Model_Q_Table[0].size() << std::endl;
        std::cout << "printing out Q Table " << std::endl;
        generator.results();
        printUnorderedMap(Model_Q_Table);

    // }
    return 0;

}
