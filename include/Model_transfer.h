#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <tuple>

class Model_transfer
{
    private:
    std::string m_Q_table_1 = "Q_table_1.txt";
    std::string m_Q_table_3 = "Q_table_3.txt";
    std::string m_Q_table_5 = "Q_table_5.txt";
    std::string m_Q_table_7 = "Q_table_7.txt";
    std::vector<std::string> m_Q_table_lists; //= {m_Q_table_1, m_Q_table_3, m_Q_table_5, m_Q_table_7};

    public:
        Model_transfer()
        {
            m_Q_table_lists.push_back(m_Q_table_1);
            m_Q_table_lists.push_back(m_Q_table_3);
            m_Q_table_lists.push_back(m_Q_table_5);
            m_Q_table_lists.push_back(m_Q_table_7);
        }
        /// @brief Transfer all data from Model Data into textfiles
        /// @param Model_Data - which contains all the Q tables
        void save_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);
        /// @brief Load a model from text files 
        /// @param Model_Data - where to store the data that represents the Q table
        void load_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);

};