#include "../include/Model_transfer.h"
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>


void Model_transfer::save_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data)
{
    std::cout << "Saving Model...." << std::endl;
    std::ofstream model_file;
    //Iterate through each Q-Table
    for(int q_table = 0; q_table < Model_Data.size() ; q_table++)
    {
        std::string q_file = m_Q_table_lists[q_table];
        std::cout << "Opening " << q_file << std::endl;
        model_file.open(q_file);
        if(!model_file)
        {
            std::cout << "Failed to open " << m_Q_table_lists[q_table] << std::endl;
            return;
        }
        
        //Iterate through keys
        for (const auto& pair: Model_Data[q_table])
        {
            // Write Key
            model_file << pair.first;
            model_file << ":";

            //Iterate through [move, q_value] vector
            int first_iteration = 0;
            for(const auto& q_pair: pair.second)
            {
                if(first_iteration != 0)
                {
                    model_file << " ";
                }
                model_file << q_pair.first;
                model_file << " ";
                model_file << q_pair.second;
                
                if(q_pair != pair.second.back())
                {
                    model_file << " | ";
                }
            }
            model_file << "\n";
        }
        model_file.close();
    }
    std::cout << "Model saved..." << std::endl;
}

void Model_transfer::load_model(std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data)
{
    //Iterate through each Q File
    std::cout << "Loading Model...." << std::endl;
    for(int q_file_counter = 0; q_file_counter < 1 ; q_file_counter++) //m_Q_table_lists.size() 
    {
        // Set up the Model
        std::vector < std::pair<std::string,double>> temp_vector;


        std::string q_file = m_Q_table_lists[q_file_counter];
        std::cout << "Opening " << q_file << std::endl;
        std::ifstream model_file(q_file);
        std::string Q_data;
        while(getline(model_file, Q_data))
        {
            //std::cout << Q_data << std::endl;
            std::string list_delimiter = ":";
            std::string q_pair_delimiter = "|";
            
            std::string key = Q_data.substr(0, Q_data.find(list_delimiter));
            temp_vector.clear();
            //std::cout << "\n Key : " << key << std::endl;

            std::string values = Q_data.substr(10);
            int tester = values.find(q_pair_delimiter);
            std::vector <std::pair<std::string, double>> list_q_pairs;

            int position_start = 0;
            int position_end = 0;
            std::string token;
            //std::cout << "Splitting " << std::endl;
            
            int counter = 0;
            counter = values.find(q_pair_delimiter);
            while( (counter = values.find(q_pair_delimiter)) != std::string::npos)
            {

                //Extract Q Pair
                std::string new_pair = values.substr(0, counter);
                //std::cout << "\tvalue = " << new_pair << std::endl;
                values = values.substr(counter + 2);
                //Store Q Pair
                std::string o_move = new_pair.substr(0,9);
                double q_value = stod(new_pair.substr(9));
                temp_vector.push_back(std::make_pair(o_move,q_value));

                //Check if extracting last value
                if((counter = values.find(q_pair_delimiter)) == std::string::npos)
                {
                    new_pair = values;
                    //std::cout << "\tvalue = " << new_pair << std::endl;
                    //Store Q Pair
                    std::string o_move = new_pair.substr(0,9);
                    double q_value = stod(new_pair.substr(9));
                    temp_vector.push_back(std::make_pair(o_move,q_value));
                }

            }
            Model_Data[q_file_counter][key] = temp_vector;
        }


    }
}