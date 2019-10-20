/// File Name Player.h.
/// Assignment EECS 448 Project 2.
/// Brief Defines Player functions.

#ifndef Player_h
#define Player_h
#include<iostream>

class Player
{
public:

  /*!
   \pre salvo mode selected.
   \post creates board for player.
   \return none.
  */

  Player(bool salvo);

  /*!
   \pre board object is created.
   \post board object is deleted.
   \return none.
  */

  ~Player();

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
   \post converts coordinates to ints.
   \param coords Coordinate to be converted for AI use.
   \return coordinate for AI.
  */

  char find(std::string coord);

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

  /*!
   \pre Board created, boats placed.
   \post gets game board.
   \return the board.
  */

  char** getGameBoard();

  /*!
   \pre Board created, boats placed.
   \post gets ship count.
   \return how many ships used.
  */

  int getShipCount();

private:
  /// Number of rows.
  const static int m_rows = 8;

  /// Number of cols.
  const static int m_cols = 8;

  /// Pointer to board.
  char** gameBoard;

  /// How mant ships.
  int m_shipCount = 0;

  /// Mode used.
  bool salvoMode = false;

  /*!
   \pre board created and coordinates given.
   \post Returns true or false if ship length is correct.
   \param start starting coordinate.
   \param end ending coordinate.
   \param length length of the ship.
   \return true for corect length, else false.
  */

  bool checkShipLength(int length, std::string start, std::string end);

  /*!
   \pre board created and coordinates given.
   \post Returns true or false if ship position is correct.
   \param start starting coordinate.
   \param end ending coordinate.
   \return true if boat does not overlap another boat or out of bounds, else false.
  */

  bool checkShipPosition(std::string start, std::string end);

  /*!
   \pre board created and coordinates given.
   \post places ship.
   \param length length of the ship.
   \param start starting coordinate.
   \param end ending coordinate.
   \return none
  */

  void placeShip(int length, std::string start, std::string end);


};
#endif
