#include <iostream>
#include <memory>
#include <vector>

#include "Player.hpp"
#include "Test.hpp"

void TestFunc(const Player &player) {
    std::cout << "Player Health from function: " << player.GetHealth() << "\n";
}

void PrintStringFunction(const std::string *Message) {
    std::cout << *Message << "\n";
}

int main() {
    Player player;
    std::vector<size_t> TestVectorOne{6, 7, 8, 9, 10};
    std::vector<size_t> TestVectorTwo;
    constexpr Player John;
    size_t total{0};
    const std::vector PlayerArray{John};
    const auto Pointer{std::make_unique<int>(50)};

    for (auto i{1}; i <= 100; ++i)
        TestVectorTwo.push_back(i);


    std::cout << "Player Health: " << player.GetHealth() << "\n";
    player.SetHealth(150);
    std::cout << "Pi Test: " << TestSpace::Pi << "\n";
    std::cout << "Updated Player Health: " << player.GetHealth() << "\n";

    for (const size_t &i: TestVectorTwo)
        total += i;
    std::cout << "TestVectorTwo Total: " << total << "\n";

    for (const size_t &i: TestVectorOne)
        total *= i;
    std::cout << "TestVectorOne Total: " << total << "\n";

    // Checking assembler for instruction count differences
    std::cout << "Size - 1, 11 Instructions: " << TestVectorOne[TestVectorOne.size() - 1]; // 11 instructions
    std::cout << "\n.back(), 6 Instructions: " << TestVectorOne.back(); // 6 instructions
    std::cout << "\nPlayer 1 Health: " << PlayerArray[0].GetHealth();
    std::cout << "\nAuto Pointer: " << *Pointer - 10;

    const int *Number{new int(100)};
    std::cout << "\nTesting new for memory allocation: " << *Number;
    delete Number;
    std::cout << "\nAfter deletion, location dereferenced: " << *Number;

    const Player Example{player};
    TestFunc(Example);
    constexpr int temp{10};
    const int *CastTest{&temp};
    const int *CastTest2{
        const_cast<int *>(CastTest)
    };
    std::cout << "\nIncremented: " << *CastTest2;
    std::cout << "\nIncremented?: " << *CastTest;

    const std::string Message{"\nHi There!"};
    PrintStringFunction(&Message);
}


