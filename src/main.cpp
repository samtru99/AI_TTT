#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <tuple>
#include <string>
#include <vector>

#include "../include/Generate_Q_Table.h"
#include "../include/Model_transfer.h"
#include "../include/Train_Model.h"

// Function to print the contents of an unordered_map
// void printUnorderedMap(Model_ai& Model_Data) 
// {
//     for(int i = 0; i < 1; i++)
//     {
//         std::cout << "Q_table_"<<i<<std::endl;
//         int key_size = 0;
//         int value_size = 0;
//         for (const auto& pair : Model_Data[i]) 
//         {
//             key_size+=1;
//             std::cout << "Key: " << pair.first << std::endl;
//             std::cout << "Values:" << std::endl;
//             for (const auto& innerPair : pair.second) {
//                 std::cout << "    First: " << innerPair.first << ", Second: " << innerPair.second << std::endl;
//                 value_size+=1;
//             }
//             std::cout << std::endl;
//         }
//         std::cout << "Key Size: " << key_size << std::endl;
//         std::cout << "Value Size: " << value_size << std::endl;

//     }
// }


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
        
        // std::map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_template;
        // std::vector< std::map< std::string,  std::vector < std::pair<std::string, double> >> > Model_Q_Table;
        
        // Model_Q_Table.push_back(Q_table_template);        
        // Model_Q_Table.push_back(Q_table_template);        
        // Model_Q_Table.push_back(Q_table_template);        
        // Model_Q_Table.push_back(Q_table_template); 
        Model_ai ai('O');  

        //Gen_Q_Table generator;
        //generator.init_function(ai);
       
        std::cout << "map size is " << ai.size() << std::endl;
        //std::cout << "printing out Q Table " << std::endl;
        //generator.results();
        //printUnorderedMap(Model_Q_Table);
        //ai.print_Q_table();
        Model_transfer transfer;
        //transfer.save_model(ai);
        transfer.load_model(ai);
        //ai.print_Q_table();
        //printUnorderedMap(Model_Q_Table);
        std::cout << "Training Model " << std::endl;
        Train_Model train(.5, 1,1);
        train.train(1, ai); 
        std::cout << "saving model" << std::endl;
        transfer.save_model(ai);


    // }
    return 0;

}
