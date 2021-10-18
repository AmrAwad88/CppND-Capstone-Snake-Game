#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "SDL.h"

class Environment
{
public:
    enum class Difficulty
    {
        kEasy,
        kMedium,
        kHard
    };

    // Constructor:
    Environment();
    
    // _difficulty setter and getter
    void SetDifficulty();
    Difficulty GetDifficulty();

    // _borders setter and getter
    void ReadBorders();
    std::vector<SDL_Point> GetBorders();

    bool BorderCell(int &x, int &y);

private:
    Difficulty _difficulty = Difficulty::kEasy;
    std::vector<SDL_Point> _borders{};
};

#endif