#include <vector>
#include <map>
#include <string.h>
#include "./Model.h"

class Train_Model
{
    private:
        double m_epsilon;
        double m_learning_rate;
        double m_gamma;
        int m_reward;    
    public:

        Train_Model(double espilon, double learn_rate, double gamma)
        {
            m_epsilon = espilon;
            m_learning_rate = learn_rate;
            m_gamma = gamma;
        }

        /// @brief Simulate numerous games to train the model 
        /// @param number_of_games - number of games to performs
        /// @param Model_Data - Model Object 
        void train(int number_of_games, Model_ai& Model_Data);

        /// @brief Update the Models Q values after each iteration of a game 
        /// @param episode - The games 
        /// @param reward 
        /// @param Model_Data 
        void update_q_vals(std::vector<int> episode, int reward, Model_ai& Model_Data);

        /// @brief Returns the best move for 
        /// @param dict_ct - TBD
        /// @param x_current_move - Current move X is on 
        /// @param Model_Data - Model Object to extract it's next move 
        void max_value(int dict_ct, Model_ai& Model_Data);

        /// @brief Train the model. Similar to train but without the training/updating of the Model
        /// @param number_of_games - Number of games to perform 
        /// @param Model_Data - Model Object
        void test_model(int number_of_games, Model_ai& Model_Data);

        /// @brief Teach the model by rewarding the paths it took
        /// @param Model_data - Model Object
        /// @param episode - Game history
        void update_q_vals(Model_ai& Model_data, std::vector<std::vector<std::string>> episode);
};