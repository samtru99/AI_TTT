#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include "./Model.h"
class Gen_Q_Table
{
    private:
        /*
            For debugging
        */
        int m_draws;
        int m_x_wins;
        int m_o_wins;
    
    public:
        Gen_Q_Table()
        {
            m_draws = 0;
            m_x_wins = 0;
            m_o_wins = 0;
        }
        void results();
        void init_function(Model_ai& Model_Data);
        void find_moves(Model_ai& Model_Data, int level_num,  std::vector<char> x_current_move);
        void printBoard(std:: vector<char> board);
};