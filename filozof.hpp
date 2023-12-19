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
};

[[noreturn]] void FunkcjaWatku(Filozof* filozof);


inline std::array <Widelec, 5> widelce;
inline std::array <Filozof, 5> filozofowie = {
        Filozof("Tales", &widelce[4], &widelce[0]),
        Filozof("Ferekydes", &widelce[0], &widelce[1]),
        Filozof("Anaksymander", &widelce[1], &widelce[2]),
        Filozof("Pitagoras", &widelce[2], &widelce[3]),
        Filozof("Ksenofanes", &widelce[3], &widelce[4])
};

#endif //SO_FILOZOFOWIE_FILOZOF_HPP
