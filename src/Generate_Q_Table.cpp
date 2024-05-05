#include "../include/Generate_Q_Table.h"
#include "../include/Check_board.h"
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <tuple>


void Gen_Q_Table::init_function(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>> Model_Data)
{
    char board[9] = {'_','_','_',
                    '_','_','_',
                    '_','_','_'};
    for(int i = 0; i < 9; i++)
    {
        char temp[9];
        std::copy(std::begin(board), std::end(board), std::begin(temp));

        temp[i] = 'X';
        find_moves(Model_Data, 0, temp);
    }
}

void Gen_Q_Table::find_moves(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>> Model_Data,
                        int level_num, char board[9])
{
    std::cout << "board is " << board << std::endl;

    /*
        Bases Cases
        1. Full Board
        2. Winner on X moves 
    */

    if( rows(board) || tie(board))
    {
        if( rows(board))
        {
            x_wins += 1;
        }
        else
        {
            draws += 1;
        }
    }
    std::vector < std::pair<std::string,double>> x_moves_vector;
    std::string str_board(board);
    Model_Data[level_num][str_board] = x_moves_vector;
    
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == '_')
        {
            char O_next_move[9];
            for (int i = 0; i < 9; ++i) 
            {
                O_next_move[i] = board[i];
            }
            Model_Data[level_num][str_board].push_back( std::make_pair( std::string(O_next_move), 0) );
        }
    }
   
}