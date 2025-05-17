#include "../include/Train_Model.h"
#include "../include/Check_board.h"
#include <string.h>
void Train_Model::train(int number_of_games, std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data)
{
    /*
        Initialize
    */
   while(number_of_games > 0)
   {
    bool won = false;
    bool tie = false;

    int x_play_count = 0;
    std::vector<std::vector<std::string>> episode;
      
    std::vector<char> board = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};    
    std::vector<int> choices = {1,2,3,4,5,6,7,8};
    int reward = 0;
    while( won != true && tie != true)
    {
        std::vector<std::string> next_state;
        /*
            X turn
        */
        int random_move = (rand() % choices.size() + 1 );

        int position = choices[random_move];

        choices.erase(choices.begin() + random_move);

        board[position - 1] = 'X';

        //Check if X won or if it's a tie
        if( rows(board) || columns(board) || diagonals(board))
        {
            won = true;
            reward = -1;
            break;
        }
        if (tie_game(board))
        {
            tie = true;
            reward = 1;
            break;
        }

        //find the right dictionary and x
        std::string x_current_move_str(board.begin(), board.end());
        next_state.push_back(x_current_move_str);

        /*
            Pick a route: Exploit vs Explore
        */
        double random_number = ((double) rand() / (RAND_MAX)) + 1;
        
        // Explore route
        if( random_number < m_epsilon)
        {
            int number_of_options = Model_Data[x_play_count][x_current_move_str].size();
            int explore_value = (rand() % number_of_options);
            std::string o_play = Model_Data[x_play_count][x_current_move_str][explore_value].first;
        }
        //Exploit route
        else
        {
            //Set up to extract highest move
            std::vector<int> highest_q_val_list;
            int highest_q_value = Model_Data[x_play_count][x_current_move_str][0].second;
            highest_q_val_list.push_back(0);
            std::string exploit_move;
            std::string o_counter_move;
            //Extract Highest Q value(s)
            std::vector<std::pair<std::string, double>> all_possible_o_moves = Model_Data[x_play_count][x_current_move_str];
            for(int i = 1; i < all_possible_o_moves.size(); i++)
            {
                if(all_possible_o_moves[i].second > highest_q_value)
                {
                    highest_q_val_list.clear();
                    highest_q_val_list.push_back(i);
                    highest_q_value = all_possible_o_moves[i].second;
                }
                if(all_possible_o_moves[i].second == highest_q_value)
                {
                    highest_q_val_list.push_back(i);
                }
            }

            //Check if more than 1 q value
            if(highest_q_val_list.size() > 1)
            {
                int rand_exploit = (rand() % highest_q_val_list.size() + 1 );
                exploit_move = all_possible_o_moves[highest_q_val_list[rand_exploit - 1]].first;
            }
            else
            {
                exploit_move = all_possible_o_moves[highest_q_val_list[0]].first;
            }
            o_counter_move = exploit_move;

            next_state.push_back(o_counter_move);

            //Update the board - Need to delete the choice[element]
            for(int compare = 0; compare < 9; compare++)
            {
                //Found difference
                if(o_counter_move[compare] != x_current_move_str[compare])
                {
                    //Find the elemental position
                    for(int find_choice = 0; find_choice < choices.size(); find_choice++)
                    {
                        if(choices[find_choice] == compare+1)
                        {
                            choices.erase(choices.begin() + find_choice);
                        }
                    }
                }
            }

            //Check if O won
            episode.push_back(next_state);
            if( rows(board) || columns(board) || diagonals(board))
            {
                won = true;
                reward = 1;
                break;
            }
            
            x_play_count+=1;
        }


    }



   }
}