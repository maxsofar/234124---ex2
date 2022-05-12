#include "Player.h"

Player::Player(std::string playerName, int maxHP, int initialForce)
    : m_name(playerName), m_level(1),  m_force(initialForce), m_maxHP(maxHP), m_HP(maxHP), m_coins(0) {
    if (initialForce <= 0) {
        m_force = 5;
    }
    if (maxHP <= 0) {
        m_HP = m_maxHP = 100;
    }
}

void Player::printInfo() {
    const char *name = m_name.c_str();
    printPlayerInfo(name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp() {
    if (m_level < MAX_LEVEL) {
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
    if (hpVal < 0) {
        return;
    }
    else if (hpVal > m_maxHP - m_HP) {
        m_HP = m_maxHP;
    } else {
        m_HP += hpVal;
    }
}

void Player::damage(int damageVal) {
    if (damageVal < 0) {
        return;
    }else if(m_HP - damageVal < 0) {
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
    if (amount <= 0) {
        return true;
    } else if (m_coins - amount < 0){
        return false;
    } else {
        m_coins -= amount;
        return true;
    }
}

int Player::getAttackStrength() {
    return m_force + m_level;
}
