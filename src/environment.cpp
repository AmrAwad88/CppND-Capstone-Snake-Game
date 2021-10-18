#include "environment.h"

Environment::Environment()
{
    SetDifficulty();
    ReadBorders();
}

void Environment::SetDifficulty()
{
    std::cout << "Please select the game play difficulty: \n'e' for easy\n'm' for medium\n'h' for hard\nKeyboard input: ";
    std::string s;
    std::cin >> s;
    if (s == "e")
    {
        _difficulty = Difficulty::kEasy;
        std::cout << "Selected game play is \"easy\"\n";
    }
    else if (s == "m")
    {
        _difficulty = Difficulty::kMedium;
        std::cout << "Selected game play is \"medium\"\n";
    }
    else if (s == "h")
    {
        _difficulty = Difficulty::kHard;
        std::cout << "Selected game play is \"hard\"\n";
    }
    else // recursive call: repeat the method in case of wrong user input
    {
        std::cout << "Wrong user entry, try again!\n";
        SetDifficulty();
    }
}

Environment::Difficulty Environment::GetDifficulty() { return _difficulty; }

void Environment::ReadBorders()
{
    // Select the map (borders) based on the selected game difficulty
    std::string sFileName{};
    if (_difficulty == Difficulty::kEasy)
    {
        sFileName = "easy.txt";
    }
    else if (_difficulty == Difficulty::kMedium)
    {
        sFileName = "medium.txt";
    }
    else if (_difficulty == Difficulty::kHard)
    {
        sFileName = "hard.txt";
    }
    std::cout << "Selected map is: " << sFileName << " \n";

    // Construct the borders arreay based on the parsed files
    SDL_Point dummy;
    int rowIndex{-1};
    int columnIndex{-1};

    std::ifstream myFile;
    myFile.open("../levels/" + sFileName);
    if (myFile)
    {
        std::cout << "File stream created successfully! \n";
        std::string line;
        while (getline(myFile, line))
        {
            rowIndex++;
            std::istringstream myString(line);
            int n;
            char c;
            while (myString >> n >> c && c == ',')
            {
                columnIndex++;
                if (n == 1)
                {
                    dummy.x = columnIndex;
                    dummy.y = rowIndex;
                    _borders.push_back(dummy);
                }
            }
            columnIndex = -1;
        }
    }
    else
        std::cout << "File stream NOT created successfully! \n";

    std::cout << "Number of border points = " << _borders.size() << "\n";
}

std::vector<SDL_Point> Environment::GetBorders() { return _borders; }

bool Environment::BorderCell(int &x, int &y)
{
    for (auto const &item : _borders)
    {
        if (x == item.x && y == item.y)
        {
            return true;
        }
    }
    return false;
}