#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>

class Player {
public:
    Player(std::string name, int initialForce = 5, int maxHP = 100);
    ~Player() = default;
    Player(const Player &) = default;
    Player& operator=(const Player&) = default;

    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int buffVal);
    void heal(int hpVal);
    void damage(int damageVal);
    bool isKnockedOut();
    void addCoins();
    bool pay();
    int getAttackStrength();

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};

#endif //EX2_PLAYER_H
