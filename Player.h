#pragma once

#include <iostream> // input and output
#include <time.h> // for random number generator
#include <string>

struct Weapon
{
    int attack, posX, posY;
    std::string name;
};

class Player
{
    int posX, posY, HP, turn, XP;
    Weapon equippedWeapon;

    enum Alignment : bool {
        good = true,
        evil = false
    } alignment;

public:

    Player(int positionX = 0, int positionY = 0, int health = 100, int counter = 1, int experience = 1,
        Alignment startingAlignment = good, std::string startingWeaponName = "Fists", int startingWeaponAttack = 2)
    {
        posX = positionX;
        posY = positionY;
        HP = health;
        turn = counter;
        XP = experience;
        alignment = startingAlignment;
        equippedWeapon.name = startingWeaponName;
        equippedWeapon.attack = startingWeaponAttack;
    }

    int getPosX() { return posX; }
    int getPosY() { return posY; }
    int getHP() { return HP; }
    int getTurn() { return turn; }
    int getXP() { return XP; }
    std::string getWeaponName() { return equippedWeapon.name; }
    int getWeaponAttack() { return equippedWeapon.attack; }
    Weapon getWeapon() { return equippedWeapon; }
 
    bool getAlignment() 
    { 
        bool boolAlignment;

        if (alignment == good)
        {
            boolAlignment = true;
        }
        
        else
        {
            boolAlignment = false;
        }
        
        return alignment;

        }

    bool changeAlignment(bool);
    void useItem(std::string);
    int weaponDamage(Weapon, int);

    void setAlignment(bool);

    void setHP(int newHP) { HP = newHP; }
    void setXP(int newXP) { XP = newXP; }
    void setTurn(int newTurn) { turn = newTurn; }
    void setPosX(int newPosX) { posX = newPosX; }
    void setPosY(int newPosY) { posY = newPosY; }
    void setWeapon(Weapon newWeapon) { equippedWeapon = newWeapon; }
    void setWeaponName(std::string weaponName) { equippedWeapon.name = weaponName; }


    ~Player() {};

};

/*__________---------------------_____________*
|. . . - - - END OF PLAYER CLASS - - - . . .  |
*____________________________________________*/

class Enemy {
private:
    int hp, damage;
    std::string name = "Monster";

public:

    Enemy() {};

    int getHP() { return hp; };
    int getDamage() { return damage; };
    std::string getName() { return name; };
    void setHP(int newHP) { hp = newHP; };
    void constructHP(int);

    virtual int attack(Player);

    friend class Reaper;
};

class Reaper : public Enemy {

    // Reaper has access to Enemy's private members and initializes the same
    // way. 

public:

    Reaper() {
        name = "Raging Reaper";
    }

    int attack(Player);
};

