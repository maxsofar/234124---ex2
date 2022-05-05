#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string playerName, int initialForce, int maxHP) {
    m_name = playerName;
    m_level = 1;
    m_coins = 0;
    m_force = initialForce;
    m_HP = m_maxHP = maxHP;
}

void Player::printInfo() {
    cout << "Player Details:" << endl;
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Force: " << m_force << endl;
    cout << "HP: " << m_HP << endl;
    cout << "Coins: " << m_coins << endl;
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
    //coins?
    m_force += buffVal;
}

void Player::heal(int hpVal) {
    //coins?
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
    m_coins += amount;
}

bool Player::pay(int amount) {
    if (m_coins - amount < 0) {
        cout << "Not enough coins" << endl;
        return false;
    } else {
        m_coins -= amount;
        return true;
    }
}

int Player::getAttackStrength() {
    return m_force + m_level;
}
//--------------------for testing------------------------//

void playerStatus(Player& player) {
    if (player.isKnockedOut()) {
        cout << "The player is knocked out\n" << endl;
    } else {
        cout << "The player is fine\n" << endl;
    }
}

void damageCheck(Player& player, int damageVal) {
    player.damage(damageVal);
    cout << "The player received " << damageVal << " damage\n" << endl;
}

void coinsCheck(Player& player, int coinsToAdd, int coinsToPay) {
    player.addCoins(coinsToAdd);
    cout << "The player received " << coinsToAdd << " coins\n";
    player.pay(coinsToPay);
    cout << "The player payed " << coinsToPay << " coins\n" << endl;
}

int main() {
    Player player1("Max", 10, 20);
    player1.printInfo();
    cout << "\n";

    player1.levelUp();
    cout << "Player's level is: " << player1.getLevel() << "\n" << endl;

    player1.buff(2);
    player1.printInfo();
    cout << "\n";

    playerStatus(player1);
    damageCheck(player1, 20);
    playerStatus(player1);

    player1.heal(3);
    player1.printInfo();
    cout << "\n";

    coinsCheck(player1, 5, 2);
    player1.printInfo();
    cout << "\n";

    cout << "The player's attack strength is: " << player1.getAttackStrength() << endl;

    return 0;
}
