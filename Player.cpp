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
}

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
}

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

void Enemy::constructHP(int var) {

    srand(time(NULL));

    int multiplier = var * 5;

    setHP(rand() % (multiplier - 1 + 1));
}

int Enemy::attack(Player obj) {
    int playerHP = obj.getHP();
    int playerXP = obj.getXP();

    srand(time(NULL));

    int multiplier = playerXP * 5;

    damage = rand() % (multiplier - 1 + 1);

    std::cout << "\n > Monster attacks you for " << damage
        << "!\n";

    playerHP -= damage;

    return playerHP;
}

int Reaper::attack(Player obj) {

    bool playerAlignment = obj.getAlignment();
    int playerHP = obj.getHP();
    int playerXP = obj.getXP();

    srand(time(NULL));

    if (playerAlignment) {
        damage = playerHP / 2;
    }

    else {
        double percentage;

        percentage = (rand() % ((25 - 1 + 1) + 1) / 1000);

        double playerHealth = playerHP;

        damage = playerHealth * percentage;
    }

    std::cout << "\n > Reaper attacks you for " << damage
        << "!\n";

    playerHP -= damage;

    return playerHP;
}
