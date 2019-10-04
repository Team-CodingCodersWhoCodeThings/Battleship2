#include "Player.h"
#include<iostream>
#include<string>
Player::Player()
{
  shipDirection = "";
  //shipPosition = "";
  shipRow = 0;
  for(int x = 0; x < m_rows; x++)
  {
    for(int y = 0; y < m_cols; y++)
    {
      gameBoard[x][y] = '#'; //BLANK BOARD SPACE
    }
  }
}

void Player::printBoard()
{
  std::cout << "  A B C D E F G H"; //COLUMN LABELS

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
  std::cout << "  A B C D E F G H"; //COLUMN LABELS

  for(int x = 0; x < m_rows; x++)
  {
    std::cout << "\n" << (x + 1) << " ";

    for(int y = 0; y < m_cols; y++)
    {
      if(gameBoard[x][y] != ('#' || 'M' || 'X'))
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

char Player::find(std::string coord) //will return the value of the board at the specified location.
{
  //Might keep for AI data access, might remove if uneccessary.
}

void Player::fire(std::string coords)
{
  int col = convertCoordinate(coords[0]);//Convert Coordinates to array indeces.
  int row = convertCoordinate(coords[1]);
  if(gameBoard[col][row] == '#')//Check if hits empty water, a miss.
  {
    std::cout << "You missed.\n";
    gameBoard[col][row] = 'M';//Mark the miss on the map.
  }
  else if(gameBoard[col][row] == ('M' || 'X'))
  {
    std::string newCoords = "";
    std::cout << "You already fired here. Try another position.\n";
    std::cin >> newCoords;
    while(!validCoordinates(newCoords))
    {
      std::cout << "Please input valid coordinates.\n";
      std::cin >> newCoords;
    }
    fire(newCoords);
  }
  else
  {
    //go through process for ship hit
  }
}



bool Player::checkForWin()//Signals the end of the game, implementation  will depend on ship implementation
{
  if(m_shipCount == 0)//Simply checks if no ships are left.
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Player::addShips(int numShips)
{
  m_shipCount = numShips;//ship number variable may prove unneccessary, might remove if uneccessary
  //places all ships per user inputs, needs implementation.
}

bool Player::validCoordinates(std::string& coords)
{
  if(coords.length() != 2)
  {
    return false;
  }
  if(coords[0] == 'a' || coords[0] == 'b' || coords[0] == 'c' || coords[0] == 'd' || coords[0] == 'e' || coords[0] == 'f' || coords[0] == 'g' || coords[0] == 'h')
  {
    coords[0] = toupper(coords[0]);
  }
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
}
