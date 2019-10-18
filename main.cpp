#include "exec.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
  exec prog;
  prog.run();
  return 0;
}
