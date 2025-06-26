#include "Mission.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "MISJA W TOKU...\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    Mission mission;

    try {
        mission.run();
    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << std::endl;
        return 1;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n=== PODSUMOWANIE MISJI ===\n\n";

    mission.logResults();
    return 0;
}
