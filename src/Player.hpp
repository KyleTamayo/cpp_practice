#pragma once

class Player {
public:
    Player() = default;

    Player(const Player &Original);

    /**
     * Retrieves the Health of the player
     * @return The value of the Players health
     */
    int GetHealth() const;

    void SetHealth(int Health);

private:
    int mHealth{100};
};


