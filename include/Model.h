#pragma once
#include <string.h>
#include <vector>
#include <map>



class Model_ai
{
    private:
        std::vector<std::map<std::string,std::vector<std::pair<std::string, double>>>> m_Q_table;

    public:
        Model_ai(char player)
        {
            std::map< std::string,  std::vector < std::pair<std::string, double> >> Q_table_template;
            int num_of_tables = player == 'O' ? 4 : 5;
            for(int i = 0; i < num_of_tables; i++)
            {
                m_Q_table.push_back(Q_table_template);
            }
        }

        int size();

        void store_q_value(int level_num, std::string x_current_move, std::vector<std::pair<std::string,double>> o_moves_vector);

        void print_Q_table();

        std::map< std::string, std::vector < std::pair<std::string,double>>> get_q_table(int q_table);

        double get_q_value(int x_play_count, std::string x_current_move, int move);

        std::vector < std::pair<std::string,double>> get_q_vector(int x_play_count, std::string x_current_move);

        std::string get_o_play(int x_play_count, std::string x_current_move, int move);

        int get_q_vector_size(int x_play_count, std::string x_current_move);

        int find_sub_q_table(std::string x_move);
};