#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>

class Player {
public:
    Player();
    ~Player();
    Player(const Player &);
    Player& operator=(const Player&);

    printInfo();
    levelUp();
    getLevel();
    buff();
    heal();
    damage();
    isKnockedOut();
    addCoins();
    pay();
    getAttackStrength();

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};

#endif //EX2_PLAYER_H
