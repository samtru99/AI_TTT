#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <tuple>

class Model_transfer
{
    private:
    std::string Q_table_1;
    std::string Q_table_3;
    std::string Q_table_5;
    std::string Q_table_7;

    public:
        /// @brief Transfer all data from Model Data into textfiles
        /// @param Model_Data - which contains all the Q tables
        void save_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);
        /// @brief Load a model from text files 
        /// @param Model_Data - where to store the data that represents the Q table
        void load_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);

};