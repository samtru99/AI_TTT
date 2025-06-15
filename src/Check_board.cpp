#include "../include/Check_board.h"
#include <iostream>

bool rows(std::vector<char> board)
{
    if( (board[0] == board[1]) && (board[1] == board[2]) && board[0] != '_')
    {
        return true;
    }
    else if( board[3] == board[4] && board[4] == board[5] && board[3] != '_')
    {
        return true;
    }
    else if(board[6] == board[7] && board[7] == board[8] && board[6] != '_')
    {
        return true;
    }
    else
    {
        return false;
    }
    // return false;
}

bool columns(std::vector<char> board)
{
    if(board[0] == board[3] && board[3] == board[6] && board[0] != '_')
    {
        return true;
    }
    else if(board[1] == board[4] && board[4] == board[7] && board[1] != '_')
    {
        return true;
    }
    else if(board[2] == board[5] && board[5] == board[8] && board[2] != '_')
    {
        return true;
    }
    else 
    {
        return false;    
    }
}

bool diagonals(std::vector<char> board)
{
    if(board[0] == board[4] && board[4] == board[8] && board[0] != '_')
    {
        return true;
    }
    else if(board[6] == board[4] && board[4] == board[2] && board[6] != '_')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool tie_game(std::vector<char> board)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == '_')
        {
            return false;
        }
    }
    return true;
}

void print_board(std::vector<char> board)
{
    std::cout << "---------" << std::endl;
    std::cout << "   " << board[0] << board[1] << board[2] << std::endl;
    std::cout << "   " << board[3] << board[4] << board[5] << std::endl;
    std::cout << "   " << board[6] << board[7] << board[8] << std::endl;
    std::cout << "---------" << std::endl;
}