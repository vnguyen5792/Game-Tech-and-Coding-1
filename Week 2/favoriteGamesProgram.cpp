// Viet Nguyen
// T432Q948
// Week 2 Assignment

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::vector<std::string> games = {"Rocket League", "Minecraft"};
    std::string input;

    std::cout << "Hello player!\n";

    while (true)
    {
        std::cout << "\nWhat would you like to do? Options are add, edit, delete, show, and quit\n";
        getline(std::cin, input);

        // if the user wants to add, get the input and pushback the vector
        if (input == "add")
        {
            std::cout << "What game would you like to add?\n";
            getline(std::cin, input);
            games.push_back(input);
        }

        // if the user wants to edit, search for the given name. if found, replace that value with the given value
        // if not, continue the loop
        else if (input == "edit")
        {
            std::cout << "What game would you like to edit?\n";
            getline(std::cin, input);

            auto iter = std::find(games.begin(), games.end(), input);
            if (iter != games.end())
            {
                std::cout << "Game found! What would you like to change it to?\n";
                getline(std::cin, input);
                *iter = input;
            }
            else
            {
                std::cout << "Game name could not be found. Try again...\n";
            }
        }

        // if the user wants to delete, search for the given name. if found, delete at that position in the vector
        // if not, continue the loop
        else if (input == "delete")
        {
            std::cout << "What game would you like to delete?\n";
            getline(std::cin, input);

            auto iter = std::find(games.begin(), games.end(), input);
            if (iter != games.end())
            {
                games.erase(iter);
                std::cout << "Game removed!\n";
            }
            else
            {
                std::cout << "Game name could not be found. Try again...\n";
            }
        }

        // display the list using a for loop. sort and also display a number
        else if (input == "show")
        {
            std::sort(games.begin(), games.end());

            std::cout << "Here are your games:\n";
            for (int i = 0; i < games.size(); ++i)
            {
                std::cout << i + 1 << " - " << games[i] << "\n";
            }
        }

        // if the user wants to quit, ask for confirmation. if yes, break. if nothing else, then continue
        else if (input == "quit")
        {
            std::cout << "Are you sure? (yes/no)\n";
            getline(std::cin, input);

            if (input == "yes")
            {
                std::cout << "Thanks for using the game tracker!\n";
                break;
            }
        }

        // if they didn't type in any of the options, tell them to
        else
        {
            std::cout << "Please enter one of the options exactly: add, edit, delete, show, or quit\n";
        }
    }

    return 0;
}
