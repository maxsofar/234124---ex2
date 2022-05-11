#include <iostream>
#include "Player.h"

//using namespace std;

Player::Player(std::string playerName, int maxHP, int initialForce) {
    m_name = playerName;
    m_level = 1;
    m_coins = 0;
    if (initialForce > 0) {
        m_force = initialForce;
    }
    if (maxHP > 0) {
        m_HP = m_maxHP = maxHP;
    }
}

void Player::printInfo() {
    const char *name = m_name.c_str();
    printPlayerInfo(name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp() {
    if (m_level < 10) {
        ++m_level;
    }
}

int Player::getLevel() {
    return m_level;
}

void Player::buff(int buffVal) {
    if (buffVal < 0) {
        return;
    }
    m_force += buffVal;
}

void Player::heal(int hpVal) {
    if (hpVal > m_maxHP - m_HP) {
        m_HP = m_maxHP;
    } else {
        m_HP += hpVal;
    }
}

void Player::damage(int damageVal) {
    if (m_HP - damageVal < 0) {
        m_HP = 0;
    } else {
        m_HP -= damageVal;
    }
}

bool Player::isKnockedOut() {
    if (m_HP) {
        return false;
    } else {
        return true;
    }
}

void Player::addCoins(int amount) {
    if (amount < 0) {
        return;
    }
    m_coins += amount;
}

bool Player::pay(int amount) {
    if (m_coins - amount < 0) {
        std::cout << "Not enough coins" << std::endl;
        return false;
    } else {
        m_coins -= amount;
        return true;
    }
}

int Player::getAttackStrength() {
    return m_force + m_level;
}
