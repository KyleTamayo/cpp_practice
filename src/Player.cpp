// Created 26 August 2024
// by Kyle Tamayo
#include "Player.hpp"

#include <iostream>

Player::Player(const Player &Original) {
    std::cout << "\nPlayer Copied\n";
}

int Player::GetHealth() const {
    return mHealth;
}

void Player::SetHealth(const int Health) {
    mHealth = Health;
}
