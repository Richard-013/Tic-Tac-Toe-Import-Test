#include <iostream>
#include <string>

using namespace std;

std::string gameIntro()
{
    std::string name = "";

    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?" << std::endl;

    std::getline(std::cin, name);

    std::cout << "\nWelcome " << name << std::endl;

    return name;
}


int main()
{
    std::string playerName = gameIntro();


    return 0;
}
