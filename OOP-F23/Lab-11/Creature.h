#ifndef CREATURE_H
#define CREATURE_H
#include <cstdlib>
#include <ctime>
#include"String.h"
class Creature
{
protected:
    int strength;
    int hitpoints;
public:
    Creature();
    Creature(int newStrength, int newHit);
    int getDamage() const;
    int getStrength() const;
    int getHitpoints() const;
    void setStrength(const int newStrength);
    void setHitpoints(const int newHit);
};
//class Creature
//{
//    int strength;
//    int hitpoints;
//    int type;
//    String getSpecies() const;
//public:
//    Creature();
//    Creature(int newType, int newStrength, int newHit);
//    int getDamage() const;
//    int getStrength() const;
//    int getHitpoints() const;
//    int getType() const;
//    void setStrength(const int newStrength);
//    void setHitpoints(const int newHit);
//    void setType(const int newType);
//};
#endif