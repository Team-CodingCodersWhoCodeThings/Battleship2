#ifndef HARDAI_H
#define HARDAI_H
#include<iostream>
#include "Player.h"

class hardAI
{
  public:
    hardAI();
    ~hardAI();
    void printBoard();
    void printAttackBoard();
    void incomingShot(std::string coords);
    std::string fireOnPlayer();
    void addShips(int numbShips);
    bool validCoordinates(std::string& coords);
    int convertCoordinate(char coord);
    bool gameOver();
    bool isShipSunk(char shipType);
    void getAndStoreOpponentBoard(Player& player); // get player's board and store it locally
  private:
    const static int m_rows = 8;
    const static int m_cols = 8;
    char** gameBoard;
    int m_shipCount = 0;
    char opponentGameBoard[m_rows][m_cols];
};

#endif
