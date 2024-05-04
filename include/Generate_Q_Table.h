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
        int draws;
        int x_wins;
        int o_wins;
    
    public:
        void results();
        void init_function(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,int>>>> Model_Data,
                        int level_num, std::string board);
        void find_moves(std::vector< std::unordered_map< std::string,  std::vector < std::pair<std::string,int>>>> Model_Data,
                        int level_num, std::string board);
        
};