#ifndef Player_h
#define Player_h
#include<iostream>

class Player
{
public:
  /**
  * @pre: valid player object is created
  * @post: initializes shipDirection and shipRow
  * @param: none
  * @return: nothing
  **/
  Player();


  /**
  * @pre: valid player object is created
  * @post: prints board to the respective player
  * @param: none
  * @return: nothing
  **/
  void printBoard();

  void printAttackBoard();

  /**
  * @pre: valid player object is created
  * @post: changes locations on players attack board depending on where the player chose to attack
  * @param: row - the row where the player wants to attack
  * @param: col - the column where the player wants to attack
  * @return: nothing
  **/
  void incomingShot(std::string coords);

  /**
  * @pre: verify input from user, and make sure the input for column is upper case.
  * @post: find the location that user input
  * @param: int row of coordinate
  * @param: char column of coordinate
  * @return: char array
  **/
  char find(std::string coord);

  /**
  * @pre: valid player object is created
  * @post: sets the ships on the board and changes all valid coordinates to an 'S'
  * @param: numbShips - the number of ships the player is going to be placing on the board
  * @return: nothing
  **/
  void addShips(int numbShips);

  /**
  * @pre: valid player object is created
  * @post: checks if the coordinates passed in are all within the board and of char '#'
  * @param: shipRow - passed in row to check, shipColumn - passed in column to check, shipDirection - direction to check if valid, shipSize - size of the current ship of which to check
  * @return: true or false depending on if the corresponding coordinates are valid
  **/
  bool validCoordinates(std::string& coords);

  /**
  * @pre: valid player object is created
  * @post: lets us know the respective int for every columns char
  * @param: col - the column we want to convert to an integer
  * @return: returns a char's corresponding int
  **/
  int convertCoordinate(char coord);

  /**
  * @pre: valid player object is created
  * @post: tells us if this player won
  * @param: none
  * @return: weather or not this player won
  **/
  bool gameOver();

  bool isShipSunk(char shipType);

  char** getGameBoard();

private:
  const static int m_rows = 8;
  const static int m_cols = 8;
  char** gameBoard;
  int m_shipCount = 0;
  bool checkShipLength(int length, std::string start, std::string end);
  bool checkShipPosition(std::string start, std::string end);
  void placeShip(int length, std::string start, std::string end);


};
#endif /* Player_h */
