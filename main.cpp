//
// Created by Max on 06/05/2022.
//


#include "Mtmchkin.h"


int main() {
    Card cards[4];
    CardStats stats(3, 40, 10, 30, 1, 20);
    cards[0] = Card(CardType::Treasure,stats);
    cards[1] = Card(CardType::Buff,stats);
    cards[2] = Card(CardType::Battle,stats);
    cards[3] = Card(CardType::Heal,stats);
    Mtmchkin game("Daniel",cards, 4);
    while (!game.isOver()) {
        game.playNextCard();
    }

        return 0;
}