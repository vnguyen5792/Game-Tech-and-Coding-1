/*welcome the player
set up the game
    int health = 10, attack, block, turns = 0
    seed the random number generator
start the loop
    add 1 to turns
    start the encounter
        randomly generate numbers for attack (range = 0-4) and block (range = 0-4)
        if block is greater or equal to attack, successful block
        otherwise, subtract attack value from health.
        ask the player if they would like to keep adventuring. if they don't, break out of the loop.
keep looping while health is greater than zero and fewer than 4 turns have happened

if health is greater than 0, congratulate player
otherwise, tell the player they're dead. */

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // seed the random number generator with time
    srand(time(NULL));

    bool extraNumbers = false;
    std::string userInput;

    std::cout << "Welcome to the game, Player! Your journey starts now!\n";
    std::cout << "Would you like to see all the numbers? (y/n)\n";

    // this will display more numbers as the user plays the game
    std::cin >> userInput;
    if (userInput == "y")
        extraNumbers = true;

    // declare and initialize variables
    int playerHealth = 10;
    int playerAttack = 0, playerBlock = 0;
    int rounds = 0;
    int maxRounds = rand() % 2 + 4; // this will generate a random number from 4 to 6

    int enemyHealth = 10;
    int enemyAttack = 0, enemyBlock = 0;

    int enemiesDefeated = 0;
    bool firstEncounter = true;

    // loop while statement
    while (rounds <= maxRounds && playerHealth > 0)
    {
        if (firstEncounter)
        {
            std::cout << "\nYou encounter an enemy!\n\n";
            firstEncounter = false;
        }

        if (playerHealth < 4)
            std::cout << "You should probably go see a doctor...\n\n";

        // generate attack and blocks
        playerAttack = rand() % 4;
        playerBlock = rand() % 4;
        enemyAttack = rand() % 2;
        enemyBlock = rand() % 2;

        // display extra numbers upon request
        if (extraNumbers)
        {
            std::cout << "Your Health (before applied attack) -> " << playerHealth << std::endl;
            std::cout << "Your Attack -> " << playerAttack << std::endl;
            std::cout << "Your Block -> " << playerBlock << std::endl;
            std::cout << "Enemy Health (before applied attack) -> " << enemyHealth << std::endl;
            std::cout << "Enemy Attack -> " << enemyAttack << std::endl;
            std::cout << "Enemy Block -> " << enemyBlock << std::endl;
        }

        // apply logic for attacks and blocks
        if ((playerBlock - enemyAttack) < 0)
            playerHealth -= enemyAttack;
        else
            std::cout << "You successfully blocked the opposing attack!\n";

        if ((enemyBlock - playerAttack) < 0)
            enemyHealth -= playerAttack;
        else
            std::cout << "The enemy was able to block your attack!\n";

        std::cout << "Your health -> " << playerHealth << std::endl;
        std::cout << "Enemy health -> " << enemyHealth << std::endl
                  << std::endl;

        // if the enemy hasn't been defeated yet, continue to the next round
        if (enemyHealth > 0)
        {
            std::cout << "Press any enter to continue to the next turn...\n\n";
            std::getc(stdin);
        }

        // check to see if the user wants to continue the adventure
        // if they do, reset variables
        else
        {
            enemiesDefeated++;
            std::cout << "You have successfully defeated the enemy! Do you wish to continue? (y/n)\n";
            std::cin >> userInput;

            if (userInput != "y")
                break;
            else
            {
                enemyHealth = 10;
                firstEncounter = true;
                rounds++;
            }
        }
    }

    if (playerHealth <= 0)
        std::cout << "You have died!\n";
    else
        std::cout << "Congratulations on completing your journey!\n";

    std::cout << "Number of enemies defeated: " << enemiesDefeated << std::endl;
    std::cout << "Your adventure ends! Thanks for playing!\n";

    return 0;
}