// qt_shared_deque_2.cpp
#include <iostream>
#include <cassert>
#include <limits>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;

  buffer.create(100);

  while (true) 
  {
    int value;
    std::cout << "$>";
    if (!(std::cin >> value)) 
    {
      if (std::cin.eof())
      {
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Not an integer, try again" << std::endl;
      continue;
    }

    if (buffer.enqueue(value))
    {
      std::cout << "Enqueued: " << value << std::endl;
    }
    else
    {
      std::cout << "Queue is full, could not enqueue: " << value << std::endl;
    }
  }

  return 0;
}
