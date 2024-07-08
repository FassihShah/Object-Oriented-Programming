#include"Balrog.h"
Balrog::Balrog() : Demon() 
{
}
Balrog::Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) 
{
}
int Balrog::getDamage() const
{
    int damage = Demon::getDamage();
    cout << "Balrog attacks for " << damage << " points!" << '\n';
    int damage2 = Demon::getDamage();
    cout << "Balrog attacks for another " << damage2 << " points!" << '\n';
    return damage + damage2;
}