#ifndef MEDIUMAI_H
#define MEDIUMAI_H
#include<iostream>

class mediumAI
{
  public:
    mediumAI();
    void printBoard();
    void printAttackBoard();
    void incomingShot(std::string coords);
    std::string fireOnPlayer();
    void addShips(int numbShips);
    bool validCoordinates(std::string& coords);
    int convertCoordinate(char coord);
    bool gameOver();
    bool isShipSunk(char shipType);
  private:
    const static int m_rows = 8;
    const static int m_cols = 8;
    char gameBoard[m_rows][m_cols];
    int m_shipCount = 0;
    bool firedSpot[m_rows][m_cols];
    int prevHitSpot[2];
    int originalHitSpot[2];
    int roundsLeftToShoot;
};

#endif
