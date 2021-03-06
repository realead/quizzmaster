#pragma once


#include <random>


#include "RollGenerator.h"


namespace RandomDice{

    //returns 6 values which can be interpreted as red,yellow,green, blue, first white, second white
    DiceRoll random_roll();
    ShortDiceRoll random_short_roll();
}


class DiceRoller{
private:
  std::mt19937 gen; 
  std::uniform_int_distribution<int>  distr;           
public:
  DiceRoller(size_t seed);
  DiceRoll roll();
  ShortDiceRoll short_roll();
};



//rollers
class GlobalRollGenerator : public RollGenerator{
    size_t left;
    double prob;
public:
    GlobalRollGenerator(size_t sampling_number);
    virtual bool has_next() const;
    virtual RollPair get_next();
};


class GlobalShortRollGenerator : public ShortRollGenerator{
    size_t left;
    double prob;
public:
    GlobalShortRollGenerator(size_t sampling_number);
    virtual bool has_next() const;
    virtual ShortRollPair get_next();
};





























