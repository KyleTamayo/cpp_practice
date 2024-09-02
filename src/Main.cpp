#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Test.hpp"

int main() {
    Player player;
    std::vector<int> TestVectorOne;
    std::vector TestVectorTwo{1, 2, 3, 4, 5};

    TestVectorOne = {6, 7, 8, 9, 10};

    std::cout << player.GetHealth() << "\n";
    player.SetHealth(150);
    std::cout << TestSpace::Pi << "\n";
    std::cout << player.GetHealth() << "\n";

    for (int i = 0; i < 5; i++) {
        std::cout << TestVectorTwo[i] << "\n";
    }

    for (int i = 0; i < 5; i++) {
        std::cout << TestVectorOne[i] << "\n";
    }
}
