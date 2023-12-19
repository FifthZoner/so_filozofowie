#include <chrono>

#include "filozof.hpp"
#include "wyswietlanie.hpp"

int main() {

    while (true) {
        wyswietlStan();
        std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1, 10>>(1));
    }

    return 0;
}
