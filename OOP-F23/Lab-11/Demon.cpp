#include"Demon.h"
Demon::Demon() : Creature() 
{
}
Demon::Demon(int newStrength, int newHit) : Creature(newStrength, newHit) 
{
}
int Demon::getDamage() const
{
    int damage = Creature::getDamage();
    //cout << "Demon attacks for " << damage << " points!" << '\n';
    if (rand() % 100 < 5)
    {
        damage += 50;
        cout << "Demonic attack! Extra 50 damage inflicted!" << '\n';
    }
    return damage;
}