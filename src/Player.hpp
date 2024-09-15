#pragma once

class Player {
public:
    Player() = default;

    Player(const Player &Original);

    int GetHealth() const;

    void SetHealth(int Health);

private:
    int mHealth{100};
};
