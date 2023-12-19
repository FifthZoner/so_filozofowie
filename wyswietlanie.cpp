#include <iostream>
#include "wyswietlanie.hpp"

void wyswietlStan() {

    // czyszczenie konsoli
    #ifdef linux
    std::system("clear");
    #else
    std::system("CLS");
    #endif
    if (widelce[4].wUzyciu){
        std::cout << "--<\n";
    }
    else {
        std::cout << "\n";
    }
    for (unsigned short n = 0; n < filozofowie.size(); n++) {
        std::cout << filozofowie[n].imie << ": ";
        switch (filozofowie[n].stan) {
            case Filozof::watekZatrzymany:
                std::cout << "Zatrzymany\n";
                break;
            case Filozof::bezczynny:
                std::cout << "Czeka na widelce\n";
                break;
            case Filozof::mysli:
                std::cout << "Mysli\n";
                break;
            case Filozof::je:
                std::cout << "Je\n";
                break;
            default:
                break;
        }
        if (widelce[n].wUzyciu){
            std::cout << "--<\n";
        }
        else {
            std::cout << "\n";
        }
    }
}