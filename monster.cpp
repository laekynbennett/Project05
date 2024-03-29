#include "monster.hpp"

Monster::Monster(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
        Entity(builder, inventory, uid)
{
    weapon_damage = _builder.weapon_damage;

    std::cout << Name() << " the monster has entered the battle" << std::endl;
}

void Monster::WeaponAttack(Entity *target)
{
    Attack(target, this->weapon_damage, "WeaponAttack");
}

void Monster::Growl(Entity *target)  //what im adding
{
    Attack(target, GetStrength() * 0.5, "Growl");
}

void Monster::Crush(Entity *target) //what im adding
{
    Attack(target, GetStrength() * 2.0, "Crush");
}

void Monster::Chomp(Entity *target)
{
    Attack(target, GetStrength() * 2.0, "Chomp");
}

void Monster::OutputStatus() const
{
    std::cout << this->Race() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tHIDDEN INVENTORY"
                << std::endl;
}

void Monster::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "growl")  //what im adding
    {
        Growl(target);
        return;
    }
    if(spellName == "crush") //what im adding
    {
        Crush(target);
        return;
    }
    if(spellName == "chomp")
    {
        Chomp(target);
        return;
    }
    
    errorFindingAbility(spellName);
}