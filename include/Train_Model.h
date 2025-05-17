#include <vector>
#include <map>
#include <string.h>

class Train_Model
{
    private:
        double m_epsilon;
        double m_learning_rate;
        double m_gamma;
    
    public:
        /// @brief Simulate numerous games to train the model 
        /// @param number_of_games - number of games to performs
        /// @param Model_Data - Model Object 
        void train(int number_of_games, std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);

        /// @brief Update the Models Q values after each iteration of a game 
        /// @param episode - The games 
        /// @param reward 
        /// @param Model_Data 
        void update_q_vals(std::vector<int> episode, int reward, std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);

        /// @brief Returns the best move for 
        /// @param dict_ct - TBD
        /// @param x_current_move - Current move X is on 
        /// @param Model_Data - Model Object to extract it's next move 
        void max_value(int dict_ct, std::string x_current_move, std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);

        /// @brief Train the model. Similar to train but without the training/updating of the Model
        /// @param number_of_games - Number of games to perform 
        /// @param Model_Data - Model Object
        void test_model(int number_of_games, std::vector< std::map< std::string,  std::vector < std::pair<std::string,double>>>>& Model_Data);
};