#ifndef SO_FILOZOFOWIE_FILOZOF_HPP
#define SO_FILOZOFOWIE_FILOZOF_HPP

#include <string>
#include <thread>
#include <cstdint>
#include <array>

#include "widelec.hpp"

struct Filozof {
    std::string imie;
    std::thread watek;
    enum {
        watekZatrzymany, bezczynny, mysli, je
    };
    uint8_t stan = watekZatrzymany;
    Widelec* prawy = nullptr;
    Widelec* lewy = nullptr;
    Filozof(std::string imie, Widelec* prawy, Widelec* lewy);
    Filozof();
    ~Filozof();

    void funkcjaWatku();
};

inline std::array <Filozof, 5> filozofowie;

#endif //SO_FILOZOFOWIE_FILOZOF_HPP
