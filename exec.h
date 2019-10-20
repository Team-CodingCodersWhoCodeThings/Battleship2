#ifndef EXEC_H
#define EXEC_H
#include <iostream>

class exec
{
  private:
  public:
    void run();
    void pvpRegular();
    void pvpSalvo();
    void pveEasy();
    void pveMedium();
    void pveHard();
    void saveHistory(int gameMode, int numShips);
    void printHistory();
    int m_numShips = 0;
};

#endif
