#include "exec.h"
#include "Player.h"
#include "easyAI.h"
#include "mediumAI.h"
#include "hardAI.h"
#include <iostream>
#include <chrono>
#include <thread>

void exec::run()
{
  bool stillPlaying = true;
  while(stillPlaying)
  {
    std::cout << "\n\nWelcome to Battleship!\n\n";
    std::cout << "Please pick an option 1-5:\n";
    std::cout << "1. Play against a friend\n";
    std::cout << "2. Play against an AI opponent\n";
    std::cout << "3. Read Instructions\n";
    std::cout << "4. View the leaderboard\n";
    std::cout << "5. Quit\n";
    std::string menuInput = "";
    bool badMenuInput = true;
    while(badMenuInput)
    {
      std::cout << "Which do you choose? Option: ";
      std::cin >> menuInput;
      if(menuInput == "1" || "2" || "3" || "4" || "5")
      {
        badMenuInput = false;
      }
      else
      {
        std::cout << "Please input a number 1-5.\n";
      }
    }
    if(menuInput == "1")
    {
      std::cout << "What mode?\n1. Regular\n2. Salvo\n\n";
      menuInput = "";
      badMenuInput = true;
      while(badMenuInput)
      {
        std::cout << "Which do you choose? Option: ";
        std::cin >> menuInput;
        if(menuInput == "1" || "2")
        {
          badMenuInput = false;
        }
        else
        {
          std::cout << "Please input a number 1 or 2.\n";
        }
      }
      if(menuInput == "1")
      {
        pvpRegular();
      }
      else if(menuInput == "2")
      {
        pvpSalvo();
      }


//VIEW LEADERBOARD



    }
    else if(menuInput == "2")
    {
      std::cout << "What difficulty?\n1. Easy\n2. Medium\n3. Hard\n\n";
      menuInput = "";
      badMenuInput = true;
      while(badMenuInput)
      {
        std::cout << "Which do you choose? Option: ";
        std::cin >> menuInput;
        if(menuInput == "1" || "2" || "3")
        {
          badMenuInput = false;
        }
        else
        {
          std::cout << "Please input a number 1-3.\n";
        }
      }
      if(menuInput == "1")
      {
        pveEasy();
      }
      else if(menuInput == "2")
      {
        pveMedium();
      }
      else if(menuInput == "3")
      {
        pveHard();
      }
      // std::cout << "Press Enter to return to the menu."; //user can view leaderboard until they hit enter to return to menu.
      // std::cin >> menuInput;
      // std::cout << "\n\n\n\n";

      //LEADERBOARD



    }
    else if(menuInput == "3")
    {
      //Print instructions for regular game and salvo, mention salvo is for pvp only.
    }
    else if(menuInput == "4")
    {
      //Print leaderboard for user.
    }
    else if(menuInput == "5")
    {

      stillPlaying = false;
      std::cout << '\n';
    }
  }
  std::cout << "Thanks for playing!\n\n";
}

void exec::pvpRegular()
{
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

  Player player1(false);
  Player player2(false);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 look away, it's Player 1's turn to add ships \n\n\n====================\n\n\n";
  player1.printBoard();
  std::cout << "\nPlayer 1: ";
  player1.addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 look away, it's Player 2's turn to add ships \n\n\n====================\n\n\n";
  std::this_thread::sleep_for(interval);
  player2.printBoard();
  std::cout << "\nPlayer 2: ";
  player2.addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  bool gameOver = false;
  std::string coords;
  while (!gameOver)
  {
    std::cout << "\n====================\nPlayer 2 look away\n\n\n====================\n\n\n\n\n\n\n\n\n\n";
    std::this_thread::sleep_for(interval);
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
    player2.incomingShot(coords); //player 1 attacks player 2's game board

    if(player2.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer 1 sunk all of Player 2's battleships! Player 1 wins! \n";
      player2.printAttackBoard();
      break;
    }
    std::this_thread::sleep_for(interval);


    std::cout << "\n====================\nPlayer 1 look away\n\n\n====================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

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
    player1.incomingShot(coords); //player 2 attacks player 1's game board

    if(player1.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer 2 sunk all of Player 1's battleships! Player 2 wins! \n";
      player1.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
}

void exec::pvpSalvo()
{
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

  Player player1(true);
  Player player2(true);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 look away, it's Player 1's turn to add ships \n\n\n====================\n\n\n";
  player1.printBoard();
  std::cout << "\nPlayer 1: ";
  player1.addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 look away, it's Player 2's turn to add ships \n\n\n====================\n\n\n";
  player2.printBoard();
  std::cout << "\nPlayer 2: ";
  player2.addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  bool gameOver = false;
  std::string coords[5];
  while (!gameOver)
  {
    std::cout << "\n====================\nPlayer 2 look away\n\n\n====================\n\n\n\n\n\n\n\n";

    std::cout << "\n\nPLAYER 1'S ATTACK BOARD:\n";
    player2.printAttackBoard();
    std::cout << "\nPLAYER 1'S BOARD:\n";
    player1.printBoard();
    for (int i = 0; i < 5; i++) {
      coords[i] = "";
    }
    for(int i = 0; i < 5; i++)
    {
      while (!(player1.validCoordinates(coords[i])))
      {
        std::cout << "Player 1, choose a coordinate to fire on, " << (i + 1) << " of 5. (ex. F3)\n";
        std::cin >> coords[i];
      }
    }
    for(int i = 0; i < 5; i++)
    {
      player2.incomingShot(coords[i]); //player 1 attacks player 2's game board
    }

    if(player2.gameOver())
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
    for (int i = 0; i < 5; i++) {
      coords[i] = "";
    }
    for(int i = 0; i < 5; i++)
    {
      while (!(player2.validCoordinates(coords[i])))
      {
        std::cout << "Player 1, choose a coordinate to fire on, " << (i + 1) << " of 5. (ex. F3)\n";
        std::cin >> coords[i];
      }
    }
    for(int i = 0; i < 5; i++)
    {
      player1.incomingShot(coords[i]); //player 1 attacks player 2's game board
    }

    if(player1.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer 2 sunk all of Player 1's battleships! Player 2 wins! \n";
      player1.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
}

void exec::pveEasy()
{
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

  Player player(false);
  easyAI* AIplayer = new easyAI();
  std::cout << "\n\n\n\n";
  player.printBoard();
  std::cout << "\nPlayer: ";
  player.addShips(numberShips[0] - 48);
  AIplayer->addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n";

  bool gameOver = false;
  std::string coords;
  while (!gameOver)
  {
    std::cout << "\n\n\n";

    std::cout << "\n\nYOUR ATTACK BOARD:\n";
    AIplayer->printAttackBoard();
    std::cout << "\nYOUR BOARD:\n";
    player.printBoard();
    coords = "";
    while (!(player.validCoordinates(coords)))
    {
      std::cout << "Player, choose a coordinate to fire on. (ex. F3)\n";
      std::cin >> coords;
    }
    AIplayer->incomingShot(coords); //player 1 attacks player 2's game board

    if(AIplayer->gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer sunk all of the easy AI's ships! Player wins! \n";
      AIplayer->printAttackBoard();
      break;
    }
    std::this_thread::sleep_for(interval);

    coords = AIplayer->fireOnPlayer();
    player.incomingShot(coords); //player 2 attacks player 1's game board

    if(player.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nEasy difficulty AI sunk all of the Player's ships! Easy AI wins! \n";
      player.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
  delete AIplayer;
}

void exec::pveMedium()
{
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

  Player player(false);
  mediumAI* AIplayer = new mediumAI();
  std::cout << "\n\n\n\n";
  player.printBoard();
  std::cout << "\nPlayer: ";
  player.addShips(numberShips[0] - 48);
  AIplayer->addShips(numberShips[0] - 48);
  std::cout << "\n\n\n\n";

  bool gameOver = false;
  std::string coords;
  while (!gameOver)
  {
    std::cout << "\n\n\n";

    std::cout << "\n\nYOUR ATTACK BOARD:\n";
    AIplayer->printAttackBoard();
    std::cout << "\nYOUR BOARD:\n";
    player.printBoard();
    coords = "";
    while (!(player.validCoordinates(coords)))
    {
      std::cout << "Player, choose a coordinate to fire on. (ex. F3)\n";
      std::cin >> coords;
    }
    AIplayer->incomingShot(coords); //player 1 attacks player 2's game board

    if(AIplayer->gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer sunk all of the medium AI's ships! Player wins! \n";
      AIplayer->printAttackBoard();
      break;
    }
    std::this_thread::sleep_for(interval);

    coords = AIplayer->fireOnPlayer(player);
    player.incomingShot(coords); //player 2 attacks player 1's game board

    if(player.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nMedium difficulty AI sunk all of the Player's ships! Medium AI wins! \n";
      player.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
  delete AIplayer;
}

void exec::pveHard()
{
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

  Player player(false);
  hardAI* AIplayer = new hardAI();
  std::cout << "\n\n\n\n";
  player.printBoard();
  std::cout << "\nPlayer: ";
  player.addShips(numberShips[0] - 48);
  AIplayer->addShips(numberShips[0] - 48);
  AIplayer->getAndStoreOpponentBoard(player);
  std::cout << "\n\n\n\n";

  bool gameOver = false;
  std::string coords;
  while (!gameOver)
  {
    std::cout << "\n\n\n";

    std::cout << "\n\nYOUR ATTACK BOARD:\n";
    AIplayer->printAttackBoard();
    std::cout << "\nYOUR BOARD:\n";
    player.printBoard();
    coords = "";
    while (!(player.validCoordinates(coords)))
    {
      std::cout << "Player, choose a coordinate to fire on. (ex. F3)\n";
      std::cin >> coords;
    }
    AIplayer->incomingShot(coords); //player 1 attacks player 2's game board

    if(AIplayer->gameOver())
    {
      gameOver = true;
      std::cout << "\n\nPlayer sunk all of the hard AI's ships! Player wins! \n";
      AIplayer->printAttackBoard();
      break;
    }
    std::this_thread::sleep_for(interval);

    coords = AIplayer->fireOnPlayer();
    player.incomingShot(coords); //player 2 attacks player 1's game board

    if(player.gameOver())
    {
      gameOver = true;
      std::cout << "\n\nHard difficulty AI sunk all of the Player's ships! Hard AI wins! \n";
      player.printAttackBoard();
    }
    std::this_thread::sleep_for(interval);
  }
  delete AIplayer;
}
