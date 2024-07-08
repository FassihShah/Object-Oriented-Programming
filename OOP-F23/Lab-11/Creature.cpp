#include"Creature.h"
Creature::Creature()
{
    strength = 10;
    hitpoints = 10;
}
Creature::Creature(int newStrength, int newHit)
{
    strength = newStrength;
    hitpoints = newHit;
}
int Creature::getDamage() const
{
    return (rand() % strength) + 1;
}
int Creature::getStrength() const
{
    return strength;
}
int Creature::getHitpoints() const
{
    return hitpoints;
}
void Creature::setStrength(const int newStrength)
{
    strength = newStrength;
}
void Creature::setHitpoints(const int newHit)
{
    hitpoints = newHit;
}



//Creature::Creature()
//{
//    type = 0;
//    strength = 10;
//    hitpoints = 10;
//}
//
//Creature::Creature(int newType, int newStrength, int newHit):Creature()
//{
//    if (type >= 0 && type <= 3)
//        type = newType;
//    strength = newStrength;
//    hitpoints = newHit;
//}
//
//int Creature::getDamage() const 
//{
//    int damage = (rand() % strength) + 1;
//    cout << getSpecies() << " attacks for " << damage << " points!" << '\n';  
//    if ((type == 1 || type == 2) && rand() % 100 < 5)     // Demons can inflict damage of 50 with a 5% chance
//    {
//        damage += 50;
//        cout << "Demonic attack! Extra 50 damage inflicted!" << '\n';
//    }
//    if (type == 3 && rand() % 100 < 10)    // Elves inflict double magical damage with a 10% chance
//    {
//        damage *= 2;
//        cout << "Magical attack! Damage doubled!" << '\n';
//    } 
//    if (type == 2)    // Balrogs attack twice
//    {
//        int balrogDamage = (rand() % strength) + 1;
//        cout << "Balrog attacks for " << balrogDamage << " points!" << '\n';
//        damage += balrogDamage;
//    }
//    return damage;
//}
//int Creature::getStrength() const 
//{
//    return strength;
//}
//int Creature::getHitpoints() const 
//{
//    return hitpoints;
//}
//int Creature::getType() const 
//{
//    return type;
//}
//String Creature::getSpecies() const 
//{
//    switch (type) 
//    {
//    case 0:
//        return "Human";
//    case 1:
//        return "Cyberdemon";
//    case 2:
//        return "Balrog";
//    case 3:
//        return "Elf";
//    default:
//        return "unknown";
//    }
//}
//void Creature::setStrength(const int newStrength) 
//{
//    strength = newStrength;
//}
//void Creature::setHitpoints(const int newHit) 
//{
//    hitpoints = newHit;
//}
//void Creature::setType(const int newType) 
//{
//    type = newType;
//}