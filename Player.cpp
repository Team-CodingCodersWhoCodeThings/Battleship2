/// File Name player.cpp.
/// Assignment EECS 448 Project 2.
/// Brief Implements player functions.

#include "Player.h"
#include<iostream>
#include<string>

Player::Player(bool salvo)
{
  salvoMode = salvo;
  gameBoard = new char *[8];
  for (int i = 0; i < 8; i++)
  {
    gameBoard[i] = new char[8];
  }
  /// Creating the 2D array.
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      gameBoard[i][j] = '#';
    }
  }
}

Player::~Player() {
  for (int i = 0; i < 8; i++)
  {
    delete gameBoard[i];
  }
  delete gameBoard;
}

void Player::printBoard()
{
  /// COLUMN LABELS.
  std::cout << "  A B C D E F G H";

  for(int x = 0; x < m_rows; x++)
  {
    std::cout << "\n" << (x + 1) << " ";

    for(int y = 0; y < m_cols; y++)
    {
      std::cout << gameBoard[x][y] << " ";
    }
  }
  std::cout << "\n";
}

void Player::printAttackBoard()
{
  /// COLUMN LABELS.
  std::cout << "  A B C D E F G H";

  for(int x = 0; x < m_rows; x++)
  {
    std::cout << "\n" << (x + 1) << " ";

    for(int y = 0; y < m_cols; y++)
    {
      if((gameBoard[x][y] == 'T') || (gameBoard[x][y] == 'D') || (gameBoard[x][y] == 'S') || (gameBoard[x][y] == 'B') || (gameBoard[x][y] == 'C'))
      {
        std::cout << "# ";
      }
      else
      {
        std::cout << gameBoard[x][y] << " ";
      }
    }
  }
  std::cout << "\n";
}

/// Will return the value of the board at the specified location, mostly for AI use.
char Player::find(std::string coord)
{
  int row = convertCoordinate(coord[0]);
  int col = convertCoordinate(coord[1]);
  return gameBoard[col][row];
}

void Player::incomingShot(std::string coords)
{
  /// Convert Coordinates to array indeces.
  int row = convertCoordinate(coords[0]);
  int col = convertCoordinate(coords[1]);
  /// Check if hits empty water, a miss.
  if(gameBoard[col][row] == '#')
  {
    std::cout << "You missed.\n";
    /// Mark the miss on the map.
    gameBoard[col][row] = 'M';
  }
  else if(gameBoard[col][row] == 'M'  || gameBoard[col][row] == 'X')
  {
    if(salvoMode == false)
    {
      std::string newCoords = "";
      std::cout << "You already fired here. Try another position.\n";
      std::cin >> newCoords;
      while(!validCoordinates(newCoords))
      {
        std::cout << "Please input valid coordinates.\n";
        std::cin >> newCoords;
      }
      incomingShot(newCoords);
    }
    else
    {
      std::cout << "You missed.\n";
    }
  }
  else
  {
    char shipType = gameBoard[col][row];
    gameBoard[col][row] = 'X';
    std::cout << "\n\nHit!\n\n";
    if(isShipSunk(shipType))
    {
      if(shipType == 'T')
      {
        std::cout << "You sunk my Tugboat!\n\n";
      }
      else if(shipType == 'S')
      {
        std::cout << "You sunk my Submarine!\n\n";
      }
      else if(shipType == 'D')
      {
        std::cout << "You sunk my Destroyer!\n\n";
      }
      else if(shipType == 'B')
      {
        std::cout << "You sunk my BattleShip!\n\n";
      }
      else
      {
        std::cout << "You sunk my Carrier!\n\n";
      }
    }
  }
}


/// Signals the end of the game, checks for remaining ship markers.
bool Player::gameOver()
{
  /// Iterates through map, simply setting over to false if it sees a ship marker.
  bool over = true;
  for(int x = 0; x < m_rows; x++)
  {
    for(int y = 0; y < m_cols; y++)
    {
      if(gameBoard[x][y] == 'T' || gameBoard[x][y] == 'B' || gameBoard[x][y] == 'S' || gameBoard[x][y] == 'C' || gameBoard[x][y] == 'D')
      {
        over = false;
      }
    }
  }
  return over;
}

bool Player::isShipSunk(char shipType)
{
  /// Iterates through map, simply setting isSunk to false if it sees the specified ship marker.
  bool isSunk = true;
  for(int x = 0; x < m_rows; x++)
  {
    for(int y = 0; y < m_cols; y++)
    {
      if(gameBoard[x][y] == shipType)
      {
        isSunk = false;
      }
    }
  }
  return isSunk;
}

/// Places ships based on user input.
void Player::addShips(int numShips)
{
  m_shipCount = numShips;
  bool placing = true;
  std::string start = "";
  std::string end = "";
  /// Places ships going largest to smallest.
  for(int i = m_shipCount; i > 0; i--)
  {
    while(placing)
    {
      /// repeatedly ask for start point until valid position is given.
      while(!validCoordinates(start))
      {
        std::cout << "Input a valid starting coordinate for ship length " << i << ", column(A-H) and row(1-8). (ex. F5)\n";
        std::getline (std::cin,start);
      }
      if(i == 1)
      {
        end = start;
      }
      /// repeatedly ask for end point until valid position is given.
      while(!validCoordinates(end))
      {
        std::cout << "Input a valid ending coordinate for ship length " << i << ", column(A-H) and row(1-8). (ex. F5)\n";
        std::getline (std::cin,end);
      }
      /// Check that both ship is right length and not overlapping before placing.
      if(checkShipLength(i, start, end) && checkShipPosition(start, end))
      {
        placeShip(i, start, end);
        placing = false;
        std::cout << "\n\n\n\n";
        start = "";
        end = "";
      }
      /// If ship doesn't fit those two conditions, restart process.
      else
      {
        start = "";
        end = "";
        if(checkShipLength(i, start, end))
        {
          std::cout << "Your ship overlaps one of your others, try again.\n\n\n\n";
        }
        else if(checkShipPosition(start, end))
        {
          std::cout << "Your ship is either diagonal or the wrong length, try again.\n\n\n\n";
        }
        else
        {
          std::cout << "Ship position is not Valid, try again.\n\n\n\n";
        }
      }
    }
    /// Resets looping variable if another ship is to be placed.
    placing = true;
  }
}

/// Returns if coordinate is on map, and uppercases first coordinate if necessary.
bool Player::validCoordinates(std::string& coords)
{
  /// Checks coordinate set is exactly a column and row with length.
  if(coords.length() != 2)
  {
    return false;
  }
  /// Uppercases first coordinate if necessary.
  if(coords[0] == 'a' || coords[0] == 'b' || coords[0] == 'c' || coords[0] == 'd' || coords[0] == 'e' || coords[0] == 'f' || coords[0] == 'g' || coords[0] == 'h')
  {
    coords[0] = toupper(coords[0]);
  }
  /// Checks first is A-H, second is 1-8.
  if((coords[0] == 'A' || coords[0] == 'B' || coords[0] == 'C' || coords[0] == 'D' || coords[0] == 'E' || coords[0] == 'F' || coords[0] == 'G' || coords[0] == 'H') &&
  (coords[1] == '1' || coords[1] == '2' || coords[1] == '3' || coords[1] == '4' || coords[1] == '5' || coords[1] == '6' || coords[1] == '7' || coords[1] == '8'))
  {
    return true;
  }
  else
  {
    return false;
  }
}

/// Converts coordinates in char to int array coordinates using ASCII value.
int Player::convertCoordinate(char coord)
{
  if(coord == 'A' || coord == 'B' || coord == 'C' || coord == 'D' || coord == 'E' || coord == 'F' || coord == 'G' || coord == 'H')
  {
    return(coord - 65);
  }
  if(coord == '1' || coord == '2' || coord == '3' || coord == '4' || coord == '5' || coord == '6' || coord == '7' || coord == '8')
  {
    return(coord - 49);
  }
  return 0;
}

/// Function checking that start and endpoints are in a straight line and right distance apart.
bool Player::checkShipLength(int length, std::string start, std::string end)
{
  if((start[0] != end[0]) && (start[1] != end[1]))/// Checks first if not diagonal.
  {
    return false;
  }
  /// If columns are same, checks distance of row coordinates.
  else if(start[0] == end[0])
  {
    if((end[1]-start[1]==(length-1))||(start[1]-end[1]==(length-1)))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  /// If rows are same, checks distance of column coordinates.
  else if(start[1] == end[1])
  {
    if((end[0]-start[0]==(length-1))||(start[0]-end[0]==(length-1)))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

/// Checks that there are no ships in a specified line.
bool Player::checkShipPosition(std::string start, std::string end)
{
  int startRow = convertCoordinate(start[0]);
  int startCol = convertCoordinate(start[1]);
  int endRow = convertCoordinate(end[0]);
  int endCol = convertCoordinate(end[1]);
  bool canPlace = true;
  /// If the column coordinates are the same, iterate over row and change canPlace to false if it sees a ship marker.
  if(startCol == endCol)
  {
    if(startRow > endRow)
    {
      for(int i = endRow; i <= startRow; i++)
      {
        if(gameBoard[startCol][i] != '#')
        {
          canPlace = false;
        }
      }
    }
    else if(startRow < endRow)
    {
      for(int i = startRow; i <= endRow; i++)
      {
        if(gameBoard[startCol][i] != '#')
        {
          canPlace = false;
        }
      }
    }
    else
    {
      if(gameBoard[startCol][startRow] != '#')
      {
        canPlace = false;
      }
    }
  }
  else
  {
    if(startCol > endCol)
    {
      for(int i = startCol; i <= endCol; i++)
      {
        if(gameBoard[i][startRow] != '#')
        {
          canPlace = false;
        }
      }
    }
    else if(startCol < endCol)
    {
      for(int i = startCol; i <= endCol; i++)
      {
        if(gameBoard[i][startRow] != '#')
        {
          canPlace = false;
        }
      }
    }
  }
  return canPlace;
}

/// Actually places the ship on the board.
void Player::placeShip(int length, std::string start, std::string end)
{
  int startRow = convertCoordinate(start[0]);
  int startCol = convertCoordinate(start[1]);
  int endRow = convertCoordinate(end[0]);
  int endCol = convertCoordinate(end[1]);
  char ships[5] = {'T','S','D','B','C'};
  /// Uses ship marker for ship of that length.
  char curShip = ships[length - 1];
  /// If the column coordinates are the same, iterate over row and place ship markers.
  if(startCol == endCol)
  {
    if(startRow > endRow)
    {
      for(int i = 0; i < length; i++)
      {
        gameBoard[startCol][i + endRow] = curShip;
      }
    }
    else if(startRow < endRow)
    {
      for(int i = 0; i < length; i++)
      {
        gameBoard[startCol][i + startRow] = curShip;
      }
    }
    else
    {
      gameBoard[startCol][startRow] = curShip;
    }
  }
  else
  {
    if(startCol > endCol)
    {
      for(int i = 0; i < length; i++)
      {
        gameBoard[i + endCol][startRow] = curShip;
      }
    }
    else if(startCol < endCol)
    {
      for(int i = 0; i < length; i++)
      {
        gameBoard[i + startCol][startRow] = curShip;
      }
    }
  }
}

char** Player::getGameBoard() {
  return gameBoard;
}

int Player::getShipCount()
{
  return (m_shipCount);
}
