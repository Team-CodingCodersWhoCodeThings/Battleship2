#ifndef HARDAI_H
#define HARDAI_H
#include<iostream>

class hardAI
{
  public:
    hardAI();
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
    char gameBoard[m_cols][m_rows];
    int m_shipCount = 0;
};

#endif
