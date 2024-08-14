#include <iostream>
#include <utility>

class Goblin;
class Player;

class Weapon {
public:
    std::string _name{"Iron Sword"};
};

class Shield {
public:
    std::string _name{"Omega Shield"};
};

class Player {
public:
    Weapon* p_weapon{nullptr};
    Shield* p_shield{nullptr};

    Player() {
        _Name = "John";
    };
    explicit Player(std::string Name): _Name(std::move(Name)){}

    std::string GetName(){ return _Name; }
    void SetEnemy(Player* Enemy) {
        mEnemy = Enemy;
        std::cout << "\n" << this->GetName() << "\n";
        std::cout << this->p_shield->_name;
    }

    void LogEnemy() const {
        if(mEnemy)
            std::cout << "\nEnemy: " << mEnemy->GetName();
        else
            std::cout << "\nOops! No enemy!";
    }

private:
    std::string _Name;
    Player* mEnemy{nullptr};
};

void IncrememntReference(int& Number) { // Takes the reference to the integer
    Number++; // Increments Number
}
void IncrementPointer(int* Number) { // Takes a pointer to an integer
    (*Number)++; // Dereferences pointer before incrementing
}
int main() {
    int x{10};
    Player PlayerOne
    {"Tom"};
    Weapon Sword;
    Shield Shield;
    if(!PlayerOne.p_weapon)
        std::cout << "Unarmed";
    PlayerOne
    .p_weapon = &Sword;
    if(PlayerOne.p_weapon)
        std::cout << "\nNOT NOW! " << PlayerOne.p_weapon->_name << std::endl;
    if(!PlayerOne.p_shield)
        std::cout << "\nNO SHIELD!!";
    PlayerOne.p_shield = &Shield;
    if(PlayerOne.p_shield)
        std::cout << "\nNow I have one! " << PlayerOne
        .p_shield->_name << std::endl;
    std::cout << x << std::endl;
    IncrememntReference(x);  // Sends integer normally
    std::cout << x << std::endl;
    IncrementPointer(&x); // Sends reference to memory address
    std::cout << x << std::endl;

    std::cout << "Player One is: " << PlayerOne.GetName()
        << "\nA new enemy has appeared! ";
    Player Gobbo{"Gobbo"};
    PlayerOne.SetEnemy(&Gobbo);
    PlayerOne.LogEnemy();

    return 0;
}
