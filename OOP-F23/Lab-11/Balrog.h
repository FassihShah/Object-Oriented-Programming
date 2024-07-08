#ifndef BALROG_H
#define BALROG_H
#include"Demon.h"
class Balrog : public Demon
{
public:
    Balrog();
    Balrog(int newStrength, int newHit);
    int getDamage() const;
};
#endif