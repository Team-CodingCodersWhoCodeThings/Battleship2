/// File Name hardAI.cpp.
/// Assignment EECS 448 Project 2.
/// Brief Implements hard AI functions.

#include "hardAI.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

hardAI::hardAI()
{
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


  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      opponentGameBoard[i][j] = '#';
    }
  }
}

hardAI::~hardAI() {
  for (int i = 0; i < 8; i++)
  {
    delete gameBoard[i];
  }
  delete gameBoard;
}

void hardAI::printBoard()
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

void hardAI::printAttackBoard()
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

void hardAI::incomingShot(std::string coords)
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
  else if(gameBoard[col][row] == 'M' || gameBoard[col][row] == 'X')
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

std::string hardAI::fireOnPlayer()
{
  /// returns a coordinate for AI to fire on.
  int row = 0;
  int col = 0;
  char rowArr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (opponentGameBoard[i][j] == 'T' ||
          opponentGameBoard[i][j] == 'S' ||
          opponentGameBoard[i][j] == 'D' ||
          opponentGameBoard[i][j] == 'B' ||
          opponentGameBoard[i][j] == 'C'
      ) {
        row = i;
        col = j;
        opponentGameBoard[i][j] = 'X';
        return std::to_string(col+1) + rowArr[row];
      }
    }
  }
  return std::to_string(col+1) + rowArr[row];
}

void hardAI::addShips(int numbShips)
{
  srand( time(NULL) );
  int direction;
  int xCoord;
  int yCoord;
  bool exit;
  bool place;
  for(int i = numbShips; i>0; i--)
  {
    exit = false;
    place=false;
    while(!exit)
    {
      xCoord = rand() % 8;
      yCoord = rand() % 8;
      /// 0-Up, 1-Right, 2-Down, 3-Left.
      direction = rand() %4;
      /// checks First Spot and going off board below.
      if(gameBoard[xCoord][yCoord]=='#')
      {
        /// Up.
          if(direction==0)
          {
            if(xCoord-i>=0)
            {
              place=true;
            }
          }
          /// Right.
          else if(direction==1)
          {
            if(yCoord+i<=7)
            {
              place=true;
            }
          }
          /// Down.
          else if(direction==2)
          {
            if(xCoord+i<=7)
            {
              place=true;
            }
          }
          /// Left.
          else
          {
            if(yCoord-i>=0)
            {
              place=true;
            }
          }
          if(place)
          {
            /// checks each position if it's water.
            for(int j=i;j>0;j--)
            {
              /// up.
              if(direction==0)
              {
                if(gameBoard[xCoord-j][yCoord]!='#')
                {
                  place=false;
                }
              }
              /// right.
              else if(direction==1)
              {
                if(gameBoard[xCoord][yCoord+j]!='#')
                {
                  place=false;
                }
              }
              /// down.
              else if(direction==2)
              {
                if(gameBoard[xCoord+j][yCoord]!='#')
                {
                  place=false;
                }
              }
              /// left.
              else
              {
                if(gameBoard[xCoord][yCoord-j]!='#')
                {
                  place=false;
                }
              }
            }
          }
          /// Places the Ships C,B,D,S,T.
          if(place)
          {
            exit=true;
            for(int j=0; j<i;j++)
            {
              if(direction==0)
              {
                if(i==5)
                {
                  gameBoard[xCoord-j][yCoord]='C';
                }
                if(i==4)
                {
                  gameBoard[xCoord-j][yCoord]='B';
                }
                if(i==3)
                {
                  gameBoard[xCoord-j][yCoord]='D';
                }
                if(i==2)
                {
                  gameBoard[xCoord-j][yCoord]='S';
                }
                if(i==1)
                {
                  gameBoard[xCoord-j][yCoord]='T';
                }
              }
              if(direction==1)
              {
                if(i==5)
                {
                  gameBoard[xCoord][yCoord+j]='C';
                }
                if(i==4)
                {
                  gameBoard[xCoord][yCoord+j]='B';
                }
                if(i==3)
                {
                  gameBoard[xCoord][yCoord+j]='D';
                }
                if(i==2)
                {
                  gameBoard[xCoord][yCoord+j]='S';
                }
                if(i==1)
                {
                  gameBoard[xCoord][yCoord+j]='T';
                }
              }
              if(direction==2)
              {
                if(i==5)
                {
                  gameBoard[xCoord+j][yCoord]='C';
                }
                if(i==4)
                {
                  gameBoard[xCoord+j][yCoord]='B';
                }
                if(i==3)
                {
                  gameBoard[xCoord+j][yCoord]='D';
                }
                if(i==2)
                {
                  gameBoard[xCoord+j][yCoord]='S';
                }
                if(i==1)
                {
                  gameBoard[xCoord+j][yCoord]='T';
                }
              }
              if(direction==3)
              {
                if(i==5)
                {
                  gameBoard[xCoord][yCoord-j]='C';
                }
                if(i==4)
                {
                  gameBoard[xCoord][yCoord-j]='B';
                }
                if(i==3)
                {
                  gameBoard[xCoord][yCoord-j]='D';
                }
                if(i==2)
                {
                  gameBoard[xCoord][yCoord-j]='S';
                }
                if(i==1)
                {
                  gameBoard[xCoord][yCoord-j]='T';
                }
              }
            }
          }
      }
    }
  }
}

bool hardAI::validCoordinates(std::string& coords)
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
  if((coords[0] == 'A' || coords[0] == 'B' || coords[0] == 'C' || coords[0] == 'D' || coords[0] == 'E' || coords[0] == 'F' || coords[0] == 'G' || coords[0] == 'H') &&
  /// Checks first is A-H, second is 1-8.
  (coords[1] == '1' || coords[1] == '2' || coords[1] == '3' || coords[1] == '4' || coords[1] == '5' || coords[1] == '6' || coords[1] == '7' || coords[1] == '8'))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int hardAI::convertCoordinate(char coord)
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

bool hardAI::gameOver()
{
  /// Iterates through map, simply setting over to false if it sees a ship marker.
  bool over = true;
  for(int x = 0; x < m_rows; x++)
  {
    for(int y = 0; y < m_cols; y++)
    {
      if((gameBoard[x][y] == 'T') || (gameBoard[x][y] == 'D') || (gameBoard[x][y] == 'S') || (gameBoard[x][y] == 'B') || (gameBoard[x][y] == 'C'))
      {
        over = false;
      }
    }
  }
  return over;
}

bool hardAI::isShipSunk(char shipType)
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


void hardAI::getAndStoreOpponentBoard(Player*& player) {
  char** playerGameBoard = player->getGameBoard();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      opponentGameBoard[i][j] = playerGameBoard[i][j];
    }
  }
}
