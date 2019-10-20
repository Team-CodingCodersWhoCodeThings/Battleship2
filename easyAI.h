/// File Name easyAI.h.
/// Assignment EECS 448 Project 2.
/// Brief Defines easy AI functions.

#ifndef EASYAI_H
#define EASYAI_H
#include<iostream>
#include "Player.h"

class easyAI
{
  public:

    /*!
     \pre easy AI mode selected.
     \post creates board for easy AI.
     \return none.
    */

    easyAI();

    /*!
     \pre easyAI object is created.
     \post easyAI object is deleted.
     \return none.
    */

    ~easyAI();

    /*!
     \pre board created, boats placed.
     \post Prints board.
     \return none.
    */

    void printBoard();

    /*!
     \pre board created, boats placed.
     \post Prints opposite player's board.
     \return none.
    */

    void printAttackBoard();

    /*!
     \pre Board created, boats placed, coordinates given.
     \post Updates Board to show current game status, prints message if hit, sunk, or missed.
     \param coords Coordinate to be fired.
     \return none.
    */

    void incomingShot(std::string coords);

    /*!
     \pre Board created, boats placed, coordinates given.
     \post Gives coordinate for AI to fire on.
     \return coord to fire on.
    */

    std::string fireOnPlayer();

    /*!
     \pre Board created and coordinates given.
     \post Boat is placed onto the Board.
     \param numbShips how many ships to place
     \return none.
    */

    void addShips(int numbShips);

    /*!
     \pre Board created, boats placed, coordinates given.
     \post Returns if valid position.
     \param coords Coordinate to check.
     \return Return true if coordinate valid, else false.
    */

    bool validCoordinates(std::string& coords);

    /*!
     \pre Board created, boats placed, coordinates given.
     \post coordinate converted to int from char.
     \param coords Coordinate to convert.
     \return converted coord.
    */

    int convertCoordinate(char coord);

    /*!
     \pre Board created, boats placed.
     \post Checks if there are any boats left on a Board, ends game.
     \return True if there are no boats, else false.
    */

    bool gameOver();

    /*!
     \pre Board created, boats placed.
     \post Iterates through Board, simply setting isSunk to false if it sees the specified ship marker.
     \return True if ship is sunk, otherwise false.
    */

    bool isShipSunk(char shipType);
  private:
    /// Number fo rows.
    const static int m_rows = 8;

    /// Number of cols.
    const static int m_cols = 8;

    /// Pointer to board.
    char** gameBoard;

    /// Variable to check if already been fired at.
    bool firedSpot[m_rows][m_cols];
};

#endif
