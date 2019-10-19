#ifndef MEDIUMAI_H
#define MEDIUMAI_H
#include<iostream>
#include "Player.h"

class mediumAI
{
  public:
    mediumAI();
    ~mediumAI();
    void printBoard();///prints out board.
    void printAttackBoard();///
    void incomingShot(std::string coords);
    std::string fireOnPlayer(Player*& player);
    void addShips(int numbShips);
    bool validCoordinates(std::string& coords);
    int convertCoordinate(char coord);
    bool gameOver();
    bool isShipSunk(char shipType);
  private:
    const static int m_rows = 8;
    const static int m_cols = 8;
    char** gameBoard;
    int prevHitSpot[2];
    char previousShipType;
    int originalHitSpot[2];
    int roundsLeftToShoot;
};

#endif
