#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <iostream>

/*
 * Implements a Player class for Mtmchkin game
 *
 * The following methods are available:
 *   printInfo	       - Prints current player's parameters.
 *   levelUp		   - Increases player's level by one.
 *   getLevel          - Returns player's current level.
 *   buff	           - Adds a certain number of force points to the player.
 *   heal	           - Adds a certain number of HP to the player.
 *   damage            - Subtracts a certain number of HP from the player.
 *   isKnockedOut      - Returns player's status according to his health.
 *   addCoins          - Adds a certain number of coins to the coins owned by the player.
 *   pay               - Subtracts a certain number of coins from the coins owned by the player.
 *   getAttackStrength - Returns an attack strength of the player.
 */

class Player {
public:
    /*
     * C'tor of the player:
     *
     * @param playerName   - The name of the player.
     * @param initialForce - Initial force value of the player.
     * @param maxHP        - The maximum value of HP for the player.
     * @result
     *      An instance of Player
     */
    Player(std::string playerName, int initialForce = 5, int maxHP = 100);

    /*
     * Default D'tor, copy C'tor, assignment operator overload
     */
    ~Player() = default;
    Player(const Player&) = default;
    Player& operator=(const Player&) = default;

    /*
     * Print the following player parameters:
     *  - Name
     *  - Level
     *  - Force
     *  - HP
     *  - Coins
     *
     * @return
     *      void
     */
    void printInfo();

    /*
     * Promote the player one level
     *
     * @return
     *      void
     */
    void levelUp();

    /*
     * Get the player's current level:
     *
     * @return
     *      the current level of the player
     */
    int getLevel();

    /*
     * Increase the player's force by given number of points
     * @param buffVal the number of points to be added
     *
     * @return
     *      void
     */
    void buff(int buffVal);

    /*
     * Increase the player's HP by given number of points with the limit of maxHP
     * @param hpVal the number of points to be added
     *
     * @return
     *      void
     */
    void heal(int hpVal);

    /*
     * Decrease the player's HP by given number of points, with bottom limit 0
     * @param damageVal the number of points to be subtracted
     *
     * @return
     *      void
     */
    void damage(int damageVal);

    /*
     * Check if player is knocked out - HP is 0
     *
     * @return
     *      True if player's HP amount is 0
     *      False otherwise
     */
    bool isKnockedOut();

    /*
     * Increase the amount of player's coins by given number
     * @param amount - number of coins to be added
     *
     * @return
     *      void
     */
    void addCoins(int amount);

    /*
     * Decrease the amount of player's coins by given number
     * @param amount - number of coins to be subtracted
     *
     * @return
     *      True if the player has enough coins
     *      False otherwise
     */
    bool pay(int amount);

    /*
     * Get the attack strength of the player
     *
     * @return
     *      the sum of force points and player's level
     */
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
