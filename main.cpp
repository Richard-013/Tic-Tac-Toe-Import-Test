#include <iostream>
#include <string>

enum difficulty{Normal = 1, Impossible = 2};

std::string gameIntro()
{
    std::string name = "";

    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?" << std::endl;

    std::getline(std::cin, name);

    std::cout << "\nWelcome " << name << std::endl;

    return name;
}

int setDifficulty()
{
    int choice = 0;

    std::cout << "There are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "1 - Normal\n2 - Impossible\n" << std::endl;

    std::cin >> choice;

    switch(choice)
    {
    case 1:
        std::cout << "\nNormal difficulty has been selected" << std::endl;
        break;
    case 2:
        std::cout << "\nImpossible difficulty has been selected" << std::endl;
        break;
    default:
        std::cout << "\nInvalid option, defaulting to Normal difficulty" << std::endl;
        choice = 2;
        break;
    }

    return choice;
}

int main()
{
    std::string playerName = gameIntro();
    int difficulty = setDifficulty();

    std::cout << "Name: " << playerName << "\nDiff: " << difficulty << std::endl;

    return 0;
}
