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


void Gen_Q_Table::init_function(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data)
{
    std::vector<char> board = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};    
    for(int x_first_move = 0; x_first_move < 9; x_first_move+=1)
    {
        std::vector<char> temp(board);
        temp[x_first_move] = 'X';
        std::string temp_str(temp.begin(), temp.end());
        std::cout << " X first move is  " << temp_str << std::endl;
        
        find_moves(Model_Data, 0, temp);
    }
}

void Gen_Q_Table::find_moves(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data,
                        int level_num,  std::vector<char> x_current_move)
{
    std::string x_current_move_str(x_current_move.begin(), x_current_move.end());
    // std::cout << "x_current_move is " << x_current_move_str << std::endl;

    /*
        Bases Cases
        1. Full Board
        2. Winner on X moves 
    */
    if( rows(x_current_move) || columns(x_current_move) || diagonals(x_current_move))
    {
        std::cout << "X Won " << std::endl;
        printBoard(x_current_move);
        m_x_wins += 1;
        return;
    }
    else if ( tie(x_current_move))
    {
        std::cout << "Tie" << std::endl;
        printBoard(x_current_move);
        m_draws += 1;
        return;
    }
    else  
    {
        // std::vector < std::pair<std::string,double>> x_moves_vector;
        //Model_Data[level_num][str_board];// = std::vector < std::pair<std::string,double>>;


        // 1. Generate all O moves
        for(int next_available_move_for_O = 0; next_available_move_for_O < 9; next_available_move_for_O++)
        {
            if(x_current_move[next_available_move_for_O] == '_')
            {
                std::vector<char> O_next_move(x_current_move);
                O_next_move[next_available_move_for_O] = 'O';
                std::string O_next_move_str(O_next_move.begin(), O_next_move.end());
                std::cout << "O_next_move - " << O_next_move_str << std::endl;
                // Model_Data[level_num][str_board].push_back( std::make_pair( std::string(O_next_move), 0) );
                
                if( rows(O_next_move) || columns(O_next_move) || diagonals(O_next_move))
                {
                    std::cout << "O won" << std::endl;
                    printBoard(O_next_move);
                    m_o_wins+=1;
                    return;
                }
                //Find X next move;
                else
                {
                    for(int find_x_counter_move = 0; find_x_counter_move < 9; find_x_counter_move+=1)
                    {
                        if(O_next_move[find_x_counter_move] == '_')
                        {
                            std::vector<char> x_counter_move(O_next_move);
                            x_counter_move[find_x_counter_move] = 'X';
                            std::string x_counter_move_str(x_counter_move.begin(), x_counter_move.end());
                            std::cout << "x_counter_move is " << x_counter_move_str << std::endl;

                            find_moves(Model_Data, level_num+1, x_counter_move); //need to return the vector of pairs
                        }
                    }
                }
            }
        }
    }
}

void Gen_Q_Table::results()
{
    /*
        Goal
        m_x_wins - 131,184
        m_o_wins - 77,904
        m_draws  - 46,080

    */
    std::cout << "GAME RESULTS " << std::endl;
    std::cout << "TOTAL GAMES " << m_x_wins + m_o_wins + m_draws << std::endl;
    std::cout << "X WINS " << m_x_wins << std::endl;
    std::cout << "O WINS " << m_o_wins << std::endl;
    std::cout << "DRAWS " << m_draws << std::endl;
}

void Gen_Q_Table::printBoard(std::vector<char> board)
{
    std::cout << "---------" << std::endl;
    std::cout << "   " << board[0] << board[1] << board[2] << std::endl;
    std::cout << "   " << board[3] << board[4] << board[5] << std::endl;
    std::cout << "   " << board[6] << board[7] << board[8] << std::endl;
    std::cout << "---------" << std::endl;
}
