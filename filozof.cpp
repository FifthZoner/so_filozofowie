#include <random>
#include <chrono>

#include "filozof.hpp"

Filozof::Filozof(std::string imie, Widelec* prawy, Widelec* lewy) {
    this->prawy = prawy;
    this->lewy = lewy;
    this->imie = std::move(imie);
    watek = std::thread(FunkcjaWatku, this);
    stan = bezczynny;
}

Filozof::Filozof() = default;

Filozof::~Filozof() {
    if (stan != Filozof::watekZatrzymany) {
        watek.join();
    }
}

[[noreturn]] void FunkcjaWatku(Filozof* filozof) {
    filozof->stan = Filozof::bezczynny;

    std::random_device losowe;
    std::default_random_engine generator{losowe()};
    std::uniform_int_distribution<int> czasMyslenia{2000, 5000};
    std::uniform_int_distribution<int> czasJedzenia{3000, 7000};
    std::uniform_int_distribution<int> czasPomiedzy{500, 2000}; // pomiedzy probami podniesienia widelca

    auto czekaj = [&generator](std::uniform_int_distribution<int>& zakres) {
        std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1, 1000>>(zakres(generator)));
    };

    while (true) {
        filozof->stan = Filozof::mysli;
        czekaj(czasMyslenia);
        filozof->stan = Filozof::bezczynny;
        for (unsigned short n = 0; n < 5; n++) {
            if (filozof->lewy->podnies(filozof)){
                for (n = 0; n < 5; n++) {
                    if (filozof->prawy->podnies(filozof)){
                        filozof->stan = Filozof::je;
                        czekaj(czasJedzenia);
                        filozof->prawy->odloz();
                        break;
                    }
                    czekaj(czasPomiedzy);
                }
                filozof->lewy->odloz();
                break;
            }
            else if (filozof->prawy->podnies(filozof)){
                for (n = 0; n < 5; n++) {
                    if (filozof->lewy->podnies(filozof)){
                        filozof->stan = Filozof::je;
                        czekaj(czasJedzenia);
                        filozof->lewy->odloz();
                        break;
                    }
                    czekaj(czasPomiedzy);
                }
                filozof->prawy->odloz();
                break;
            }
            czekaj(czasPomiedzy);
        }
    }
}