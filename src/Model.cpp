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

double Model_ai::get_q_value(int x_play_count, std::string x_current_move, std::string o_move)
{
    for(const auto& pair : m_Q_table[x_play_count][x_current_move])
    {
        if(pair.first == o_move)
        {
            return pair.second;
        }
    }
}

std::string Model_ai::get_o_play(int x_play_count, std::string x_current_move, int move)
{
    std::string result;
    try {
        result = m_Q_table[x_play_count][x_current_move][move].first;
    }
    catch(const std::exception& e){
        result = "Error";
    }
    return result;
}

int Model_ai::get_q_vector_size(int x_play_count, std::string x_current_move)
{
    return m_Q_table[x_play_count][x_current_move].size();
}

std::vector < std::pair<std::string,double>> Model_ai::get_q_vector(int x_play_count, std::string x_current_move)
{
    return m_Q_table[x_play_count][x_current_move];
}

double Model_ai::find_next_max_q_value(int sub_q_table, std::string x_move)
{
    double max_value = 0;
    for(auto& pair : m_Q_table[sub_q_table][x_move])
    {
        if(pair.second > max_value)
        {
           max_value = pair.second;
        }
    }
    return max_value;
}

void Model_ai::update_q_value(int sub_q_table, std::string x_move, std::string o_move, double q_value)
{
    std::cout << "Updating q value function" << std::endl;
    auto temp = get_q_vector(sub_q_table, o_move);


    for(int pair = 0; pair < get_q_vector_size(sub_q_table,x_move); pair++)
    {
        auto p = m_Q_table[sub_q_table][x_move][pair];
        std::cout << "pair.first - " << p.first << std::endl;
        if(p.first == o_move)
        {
            std::cout << "Updating " << o_move << " to be " << q_value << std::endl;
            m_Q_table[sub_q_table][x_move][pair].second = p.second;
            return;
        }
    }

    // for(auto& pair : m_Q_table[sub_q_table][x_move])
    // {
    //     std::cout << "pair.first - " << pair.first << std::endl;
    //     if(pair.first == o_move)
    //     {
    //         std::cout << "Updating " << o_move << " to be " << q_value << std::endl;
    //         pair.second = q_value;
            
    //         return;
    //     }
    // }
}