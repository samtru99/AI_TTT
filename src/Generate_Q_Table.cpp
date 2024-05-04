#include "../include/Generate_Q_Table.h"
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>


void Gen_Q_Table::init_function(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,int>>>> Model_Data,
                        int level_num, std::string board)
{
    for(int i = 0; i < 9; i++)
    {
        std::string temp = board;

        temp[i] = 'X';
        find_moves(Model_Data, level_num, temp);
    }
}

void Gen_Q_Table::find_moves(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,int>>>>,
                        int level_num, std::string board)
{
    std::cout << "board is " << board << std::endl;

    '''
        Bases Cases
        1. Full Board
        2. Winner on X moves 
    '''
}