//***********************************************************************
// Team #14 CSCI 2380 Spring 2024 Homework # 1
// Ryan Ramirez
// First and Last Name
//
//***********************************************************************
#include "pokemon.h"
#include <iostream>
using namespace std;

// Helper function to convert Type enum to string
//I couldnt figure out another way to get the outputs to debug
string typeToStr(Pokemon::Type type) {
    switch (type) {
        case Pokemon::Normal: return "Normal";
        case Pokemon::Fighting: return "Fighting";
        case Pokemon::Flying: return "Flying";
        case Pokemon::Poison: return "Poison";
        // If i want to add cases for other types, they will be put here
        default: return "Unknown";
    }
}

Pokemon::Pokemon(string name, int ndex, Type type1)
{
    _name = name;
    _ndex = ndex;
    types[0] = type1;
    types[1] = Normal; // Default second type is Normal for single-type Pokemon
    type_count = 1;
}

Pokemon::Pokemon(string name, int ndex, Type type1, Type type2)
{
    _name = name;
    _ndex = ndex;
    types[0] = type1;
    types[1] = type2;
    type_count = 2;
}

string Pokemon::name()
{
    return _name;
}

int Pokemon::Ndex()
{
    return _ndex;
}

Pokemon::Type Pokemon::type1()
{
    return types[0];
}

bool Pokemon::is_multitype()
{
    return (type_count == 2);
}

Pokemon::Type Pokemon::type2()
{
    return (is_multitype()) ? types[1] : types[0];
}

float Pokemon::damage_multiplier(Type attack_type) {
    // Define damage multipliers based on type interactions
    float multiplier = 1.0;

    for (int i = 0; i < type_count; i++) {
        switch (types[i]) {
            case Normal:
                if (attack_type == Fighting) {
                    multiplier *= 2.0;  // Normal is weak against Fighting
                }
        
                break;

            case Fighting:
                  if (attack_type == Flying) {
                    multiplier *= 2.0;  // Fighting is resistant against Normal, Fighting and Poison
                }
                
                break;

            case Flying:
                if (attack_type == Fighting) {
                    multiplier *= 0.5;  // Flying is weak against Fighting
                }
            
                break;

            case Poison:
                if (attack_type == Poison || attack_type == Fighting) {
                    multiplier *= 0.5;  // Poison is neutral against Poison
                }
                break;
                    default:
                // For types not handled above, leave the multiplier unchanged (1.0)
                break;
        }
    }

    //cout << "Test: " << name() << ".damage_multiplier(" << typeToStr(attack_type) << ") == " << multiplier << endl; //Used this to debug and see what Multipliers i was getting to see how to adjust the damage_multipliers


    return multiplier;
}


   
