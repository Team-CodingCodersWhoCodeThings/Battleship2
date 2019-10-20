/// File Name mediumAI.h.
/// Assignment EECS 448 Project 2.
/// Brief Defines medium AI functions.

#ifndef MEDIUMAI_H
#define MEDIUMAI_H
#include<iostream>
#include "Player.h"

class mediumAI
{
  public:

    /*!
     \pre hard AI mode selected.
     \post creates board for hard AI.
     \return none.
    */

    mediumAI();

    /*!
     \pre hardAI object is created.
     \post hardAI object is deleted.
     \return none.
    */

    ~mediumAI();

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
     \return none.
    */

    std::string fireOnPlayer(Player*& player);

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
    /// Number of rows.
    const static int m_rows = 8;

    /// Number of cols.
    const static int m_cols = 8;

    /// Pointer to board.
    char** gameBoard;

    /// Variable for shooting surrounding coord.
    int prevHitSpot[2];

    /// Variable for tracking ships.
    char previousShipType;

    /// Variable for shooting surrounding coord.
    int originalHitSpot[2];

    /// Variable for how many shots are left.
    int roundsLeftToShoot;
};

#endif
