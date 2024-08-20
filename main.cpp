#include <iostream>
#include <random>
using namespace std;

class Character;
class Goblin;
class Dragon;

// Polymorphic due to virtual function
class Character {
public:
    virtual void Act(Character* Target) {
        cout << "Character Acting\n";
    }
    virtual void PrintDeathMessage() {
        cout << mDeathMessage;
    }
    bool GetIsAlive() const { return mAlive; }
    void SetIsAlive(const bool Alive) { mAlive = Alive; }
protected:
    bool mAlive {true};
    string mDeathMessage {"Default Death"};
};

class Player : public Character {
public:
    void Act(Character* Target) override {
        cout << "Player touched your butt\n";
    }
    void PrintDeathMessage() override {
        cout << mDeathMessage;
    }
protected:
    string mDeathMessage {"Player Death"};
};

class Dragon: public Character {
public:
    void Act(Character* Target) override {
        cout << "Dragon touched it now!\n";
    }
    void PrintDeathMessage() override {
        cout << mDeathMessage;
    }
protected:
    string mDeathMessage {"Dragon Death"};
};

void Battle(Character* A, Character* B, int action) {
    if(action == 1) {
        B->SetIsAlive(false);
        B->PrintDeathMessage();
    }
    else if(action == 2) {
        cout << "Work in progress";
    }
    else {
        B->Act(A);
    }
}

int main(int argc, char *argv[]) {
    Player player;
    Dragon dragon;
    int action;
    cout << "[1] Attack [2] Defend\n";
    cin >> action;
    Battle(&player, &dragon, action);
}
