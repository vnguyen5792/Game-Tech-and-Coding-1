#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Load(vector<string>& vector){
    //load from file
    ifstream file("favGames.txt");
    string line; //line of text

    //read from the file and push to the vector
    if(file.is_open()){
        while(getline(file, line)){
            vector.push_back(line);
        }
    }
    else cout << "Error reading file\n";

    file.close();
}

void Add(vector<string>& vector){
    string input;

    //ask for input then push to vector
    cout << "What game would you like to add?\n";
    getline(cin, input);

    vector.push_back(input);
}

//find given game name and mkae changes accordingly
void Edit(vector<string>& vector){
    string input;

    //ask and get input from user
    cout << "What game would you like to edit?\n";
    getline(cin, input);

    auto iter = std::find(vector.begin(), vector.end(), input);
    if (iter != vector.end())
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

//search for given game then make deletion if found
void Remove(vector<string>& vector){
    string input;
    cout << "What game would you like to delete?\n";
    getline(std::cin, input);

    auto iter = std::find(vector.begin(), vector.end(), input);
    if (iter != vector.end())
    {
        vector.erase(iter);
        std::cout << "Game removed!\n";
    }
    else
    {
        std::cout << "Game name could not be found. Try again...\n";
    }
}

void Show(const vector<string>& vector){
    //should sort list by name
    std::cout << "Here are your vector:\n";
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << i + 1 << " - " << vector[i] << "\n";
    }
}

void Quit(const vector<string>& vector){
    //offer to wipe list
    //write to file
    string input;
    cout << "Would you like to wipe games list? (yes, no)\n";
    getline(cin, input);

    ofstream file("favGames.txt", std::ios::trunc);

    //write to the empty file with updated contents
    if(input != "yes"){
        for (const auto& game : vector) {
            file << game << '\n';
        }

        cout << "Saved games to text file!\n";
    }
    else cout << "Cleared games text file!\n";

    file.close();

    cout << "Thanks for using the game tracker!\n";
}