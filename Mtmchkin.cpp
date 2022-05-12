#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) : m_player(Player(playerName)) {
    m_gameStatus = GameStatus::MidGame;
    m_numOfCards = numOfCards;
    m_cardIndex = 0;
    m_cardStack = new Card[numOfCards];
    int cardIndex = 0;
    while(cardIndex < numOfCards) {
        m_cardStack[cardIndex] = Card(cardsArray[cardIndex]);
        ++cardIndex;
    }
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cardStack;
}

void Mtmchkin::playNextCard() {
    m_cardStack[m_cardIndex].printInfo();
    m_cardStack[m_cardIndex].applyEncounter(m_player);
    m_player.printInfo();
    ++m_cardIndex;
    if (m_cardIndex == m_numOfCards) {
        m_cardIndex = 0;
    }
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_gameStatus;
}

bool Mtmchkin::isOver() {
    if (m_player.isKnockedOut()) {
        m_gameStatus = GameStatus::Loss;
        return true;
    } else if (m_player.getLevel() == 10) {
        m_gameStatus = GameStatus::Win;
        return true;
    } else {
        return false;
    }
}