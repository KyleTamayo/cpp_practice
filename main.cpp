#include <iostream>
#include <random>

class Character;
class Goblin;
class Dragon;

class Character {
public:
    virtual void Act(Character* Target) {
        std::cout << "Character Acting\n";
    }
    virtual void PrintDeathMessage() {
        std::cout << mDeathMessage;
    }
    bool GetIsAlive() const { return mAlive; }
    void SetIsAlive(const bool Alive) { mAlive = Alive; }
protected:
    bool mAlive {true};
    std::string mDeathMessage {"Default Death"};
};

class Goblin : public Character {
public:
    void Act(Character* Target) override {
        std::cout << "Goblin touched your butt\n";
    }
    void PrintDeathMessage() override {
        std::cout << mDeathMessage;
    }
protected:
    std::string mDeathMessage {"Goblin Death"};
};

class Dragon: public Character {
public:
    void Act(Character* Target) override {
        std::cout << "Dragon touched it now!\n";
    }
    void PrintDeathMessage() override {
        std::cout << mDeathMessage;
    }
protected:
    std::string mDeathMessage {"Dragon Death"};
};

void Battle(Character* A, Character* B) {
    int count {0};
    while (A->GetIsAlive() && B->GetIsAlive()) {
        A->Act(B);
        B->Act(A);
        ++count;
        if (count == 5) {
            B->SetIsAlive(false);
        }
        if (A->GetIsAlive() == false)
            A->PrintDeathMessage();
        else if (B->GetIsAlive() == false)
            B->PrintDeathMessage();

    }
}

int main(int argc, char *argv[]) {
    Goblin goblin;
    Dragon dragon;
    Battle(&goblin, &dragon);
}
