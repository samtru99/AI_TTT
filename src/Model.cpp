#include "../include/Model.h"
#include <iostream>
int Model_ai::size()
{
    return m_Q_table.size();
}

void Model_ai::store_q_value(int level_num, std::string x_current_move, std::vector<std::pair<std::string,double>> o_moves_vector)
{
    m_Q_table[level_num][x_current_move] = o_moves_vector;
}

void Model_ai::print_Q_table()
{
    for(int i = 0; i < 1; i++)
    {
        std::cout << "Q_table_"<<i<<std::endl;
        int key_size = 0;
        int value_size = 0;
        for (const auto& pair : m_Q_table[i]) 
        {
            key_size+=1;
            std::cout << "Key: " << pair.first << std::endl;
            std::cout << "Values:" << std::endl;
            for (const auto& innerPair : pair.second) {
                std::cout << "    First: " << innerPair.first << ", Second: " << innerPair.second << std::endl;
                value_size+=1;
            }
            std::cout << std::endl;
        }
        std::cout << "Key Size: " << key_size << std::endl;
        std::cout << "Value Size: " << value_size << std::endl;

    }
}

std::map< std::string, std::vector < std::pair<std::string,double>>> Model_ai::get_q_table(int q_table)
{
    return m_Q_table[q_table];
}

double Model_ai::get_q_value(int x_play_count, std::string x_current_move, int move)
{
    return m_Q_table[x_play_count][x_current_move][move].second;
}

std::string Model_ai::get_o_play(int x_play_count, std::string x_current_move, int move)
{
    return m_Q_table[x_play_count][x_current_move][move].first;
}

int Model_ai::get_q_vector_size(int x_play_count, std::string x_current_move)
{
    return m_Q_table[x_play_count][x_current_move].size();
}

std::vector < std::pair<std::string,double>> Model_ai::get_q_vector(int x_play_count, std::string x_current_move)
{
    return m_Q_table[x_play_count][x_current_move];
}