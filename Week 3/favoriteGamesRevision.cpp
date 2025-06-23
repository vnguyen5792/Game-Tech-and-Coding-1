// Viet Nguyen
// T432Q948
// Week 2 Assignment

#include "favoriteGamesHeader.h"

int main()
{
    std::vector<std::string> games;
    Load(games);
    std::string input;

    std::cout << "Hello player!\n";

    while (true)
    {
        std::cout << "\nWhat would you like to do? Options are add, edit, delete, show, and quit\n";
        getline(std::cin, input);

        // if the user wants to add, get the input and pushback the vector
        if (input == "add")
        {
            Add(games);
        }

        // if the user wants to edit, search for the given name. if found, replace that value with the given value
        // if not, continue the loop
        else if (input == "edit")
        {
            Edit(games);
        }

        // if the user wants to delete, search for the given name. if found, delete at that position in the vector
        // if not, continue the loop
        else if (input == "delete")
        {
            Remove(games);
        }

        // display the list using a for loop. sort and also display a number
        else if (input == "show")
        {
            std::sort(games.begin(), games.end());
            Show(games);
        }

        // if the user wants to quit, ask for confirmation. if yes, break. if nothing else, then continue
        else if (input == "quit")
        {
            std::string input;
            cout << "Are you sure? (yes/no)\n";
            getline(cin, input);

            if (input == "yes")
            {
                Quit(games);
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
