#include "filozof.hpp"

Filozof::Filozof(std::string imie, Widelec* prawy, Widelec* lewy) {
    this->prawy = prawy;
    this->lewy = lewy;
    this->imie = std::move(imie);
    //watek = std::thread{this->funkcjaWatku};
    stan = bezczynny;
}

Filozof::Filozof() = default;

Filozof::~Filozof() {
    if (stan != Filozof::watekZatrzymany) {
        watek.join();
    }
}

void Filozof::funkcjaWatku() {

}