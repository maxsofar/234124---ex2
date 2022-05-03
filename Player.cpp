#include "Player.h"

using namespace std;

Player::Player(string name, int initialForce, int maxHP) {
    m_name = name;
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

    return 0;
}
