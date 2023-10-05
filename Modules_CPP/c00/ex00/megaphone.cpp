#include <iostream>

int main(int ac, char *av[]) 
{
  int i = 0;
  if (ac < 2) 
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 1;
  }
  std::string msg;
  for (int i = 1; i < ac; i++) 
    msg += av[i];
  while (i < (int)msg.length())
  {   
    std::cout << (char)toupper(msg[i]);
    i++;
  }
  std::cout << std::endl;
  return 0;
}