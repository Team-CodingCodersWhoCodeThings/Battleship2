#ifndef EASYAI_H
#define EASYAI_H
#include<iostream>

class easyAI
{
  public:
    easyAI();
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
};

#endif
