#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
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
        void results();
        void init_function(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);
        void find_moves(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data,
                        int level_num,  std::vector<char> x_current_move);
        
};