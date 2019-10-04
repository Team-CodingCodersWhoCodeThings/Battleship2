#include "Player.h"
#include <chrono>
#include <thread>

int main(int argc, const char* argv[])
{
  std::cout << "\n\nWelcome to Battleship!\n\n";
  std::string numberShips = "";
  bool badMenuInput = true;
  std::chrono::seconds interval(3);

  while(badMenuInput)
  {
    std::cout << "How many ships do you want to play with (1 - 5)? ";
    std::cin >> numberShips;
    if(numberShips[0] == '1' || '2' || '3' || '4' || '5')
    {
      badMenuInput = false;
    }
  }

  Player player1;
  Player player2;
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 look away, it's Player 1's turn to add ships \n\n\n====================\n\n\n";
  player1.printBoard();
  std::cout << "\nPlayer 1: ";
  player1.addShips(numberShips[0] - 49);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 look away, it's Player 2's turn to add ships \n\n\n====================\n\n\n";
  player2.printBoard();
  std::cout << "\nPlayer 2: ";
  player2.addShips(numberShips[0] - 49);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  bool gameOver = false;
  std::string coords;
  while (!gameOver)
  {
    std::cout << "\n====================\nPlayer 2 look away\n\n\n====================\n\n\n\n\n\n\n\n";

    std::cout << "\n\nPLAYER 1'S ATTACK BOARD:\n";
    player2.printAttackBoard();
    std::cout << "\nPLAYER 1'S BOARD:\n";
    player1.printBoard();
    coords = "";
    while (!(player1.validCoordinates(coords)))
    {
      std::cout << "Player 1, choose a coordinate to fire on. (ex. F3)\n";
      std::cin >> coords;
    }
    player2.fire(coords); //player 1 attacks player 2's game board

    if(player2.checkForWin())
    {
      gameOver = true;
      std::cout << "\n\nPlayer 1 sunk all of Player 2's battleships! Player 1 wins! \n";
      player2.printAttackBoard();
      break;
    }
    std::this_thread::sleep_for(interval);


    std::cout << "\n====================\nPlayer 1 look away\n\n\n====================\n\n\n\n\n\n\n\n";

    std::cout << "\n\nPLAYER 2'S ATTACK BOARD:\n";
    player1.printAttackBoard();
    std::cout << "\nPLAYER 2'S BOARD:\n";
    player2.printBoard();
    coords = "";
    while (!(player2.validCoordinates(coords)))
    {
      std::cout << "Player 2, choose a coordinate to fire on. (ex. F3)\n";
      std::cin >> coords;

    }
    player1.fire(coords); //player 2 attacks player 1's game board

    if(player1.checkForWin())
    {
      gameOver = true;
      std::cout << "\n\nPlayer 2 sunk all of Player 1's battleships! Player 2 wins! \n";
      player1.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
  return 0;
}
