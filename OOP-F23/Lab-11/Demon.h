#ifndef DEMON_H
#define DEMON_H
#include"Creature.h"
class Demon : public Creature
{
public:
    Demon();
    Demon(int newStrength, int newHit);
    int getDamage() const;
};
#endif