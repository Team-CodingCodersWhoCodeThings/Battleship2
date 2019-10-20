/// File Name: exec.h.
/// Assignment: EECS 448 Project 2.
/// Brief: This program is the .h file for the exec class. It begins the game.

#ifndef EXEC_H
#define EXEC_H
#include <iostream>

class exec
{
  private:
  public:

    /*!
     \pre code is launched.
     \post begins game.
     \return none.
    */

    void run();

    /*!
     \pre run function is called.
     \post beigns regular pvp game.
     \return none
    */

    void pvpRegular();

    /*!
     \pre run function is called.
     \post beigns salvo pvp game.
     \return none
    */

    void pvpSalvo();
    /*!
     \pre run function is called.
     \post beigns easy AI game.
     \return none
    */
    void pveEasy();
    /*!
     \pre run function is called.
     \post beigns medium AI game.
     \return none
    */
    void pveMedium();
    /*!
     \pre run function is called.
     \post beigns hard AI game.
     \return none
    */
    void pveHard();

    /*!
     \pre a game is played.
     \post saves winning player name, game mode, and ship count to file.
     \param gameMode what type of game was played.
     \param numShips how many ships were used
     \return none
    */

    void saveHistory(int gameMode, int numShips);

    /*!
     \pre run function is called.
     \post prints contents of History.txt.
     \return none.
    */

    void printHistory();

    /// Variable used to print ship count for history.

    int m_numShips = 0;
};

#endif
