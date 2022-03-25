#include "Player.h"

void Player::setAlignment(bool newAlignment)
{
    bool boolToEnum = newAlignment;

    if (boolToEnum)
    {
        alignment = good;
    }

    else
    {
        alignment = evil;
    }
};

bool Player::changeAlignment(bool alignment)
{
    if (good)
    {
        return false;
        alignment = evil;
        XP += 2;
    }

    else
    {
        return true;
        alignment = good;
        XP += 2;
    }
};

void Player::useItem(std::string item)
{
    if (item == "Potion of Health")
    {
        if (HP > 100)
        {
            std::cout << "\nYou are already at max health.\n";
        }

        else
        {
            HP += 10;

            if (HP > 100)
            {
                HP = 100;
            }
        }
    }

    else if (item == "Magic Relic")
    {
        if (XP > 19)
        {
            std::cout << "\n You reach into your bag and pull out the relic,\n"
                << " which glows faintly in your hands. Slowly, the gates\n"
                << " creak open.\n";
        }

        else
        {
            std::cout << "\n Hopefully, you tug on the gates but find that they won't"
                << " give.\n Perhaps there is something you need in order to\n"
                << " open them.\n";
        }
    }
}

int Player::weaponDamage(Weapon weapon, int randomNumber)
{
    int playerAttack = randomNumber + equippedWeapon.attack;

    return playerAttack;
}
