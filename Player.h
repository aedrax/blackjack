//
// Created by chrisnoper on 6/12/22.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H
#include <string>
#include <vector>
#include "Card.h"

enum class actions {
    hit,
    stand,
    double_down,
    split,
};

class Player {

public:
    Player(std::string  name, double starting_bankroll, bool is_dealer = false);
    void add_card(const Card& card);
    virtual double get_bet(double minimum);
    std::string get_name();
    double get_current_bet();
    bool can_increase_bet(double amount);
    void increase_bet(double amount);
    void player_win(double amount);
    void player_lose();
    void player_bust();
    void player_push();
    bool is_busted();

    virtual void reset_player();
    std::string hand_to_str();

    virtual std::vector<Card> get_hand() const;
    virtual actions get_action(const Player& dealer);
    virtual ~Player() = default;


protected:
    void double_down();

    std::string name;
    double starting_bankroll;
    double current_bankroll;
    std::vector<Card> hand;
    bool is_dealer = false;
    double current_bet = 0;
    bool busted = false;
};


#endif //BLACKJACK_PLAYER_H