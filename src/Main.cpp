#include <iostream>
#include "Player.hpp"

int main(){
    Player player;

    std::cout << player.GetHealth();
    player.SetHealth(150);
    std::cout << player.GetHealth();
}
