#include"Elf.h"
Elf::Elf() : Creature() 
{
}
Elf::Elf(int newStrength, int newHit) : Creature(newStrength, newHit) 
{
}
int Elf::getDamage() const
{
    int damage = Creature::getDamage();
    //cout << "Elf attacks for " << damage << " points!" << '\n';
    if (rand() % 100 < 10)
    {
        damage *= 2;
        cout << "Magical attack! Damage doubled!" << '\n';
    }
    return damage;
}