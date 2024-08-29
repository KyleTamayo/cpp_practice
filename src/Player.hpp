#pragma once

class Player{
public:
    int GetHealth() const;
    void SetHealth(int Health);
private:
    int mHealth{100};
};
