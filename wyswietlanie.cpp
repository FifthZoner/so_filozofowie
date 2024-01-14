#include <iostream>
#include "wyswietlanie.hpp"

std::string stan(unsigned int n) {
    switch (filozofowie[n].stan) {
        case Filozof::watekZatrzymany:
            return "Zatrzymany";
        case Filozof::bezczynny:
            return "  Czeka   ";
        case Filozof::mysli:
            return "  Mysli   ";
        case Filozof::je:
            return "   Je     ";
        default:
            return "";
    }
}

std::string widelecLezacy(unsigned int n) {
    if (!widelce[n].wUzyciu) {
        return "--=";
    }
    return "   ";
}

std::string widelecPodniesiony(unsigned int n, unsigned int m) {
    if (widelce[n].wUzyciu and &filozofowie[m] == widelce[n].obecny) {
        return "--=";
    }
    return "   ";
}

void wyswietlStan() {

    // czyszczenie konsoli
    #ifdef linux
    std::system("clear");
    #else
    std::system("CLS");
    #endif

    // wyświetlanie w kole
    std::cout << "                             " << filozofowie[0].imie << "\n";

    std::cout << "                      " << widelecPodniesiony(4, 0) << "  " << stan(0) << "  " << widelecPodniesiony(0, 0);

    std::cout << "\n\n                    " << widelecLezacy(4) << "                  " << widelecLezacy(0);

    std::cout << "\n\n         " << filozofowie[4].imie << "                             " << filozofowie[1].imie << "\n";

    std::cout << "    " << widelecPodniesiony(3, 4) << "  " << stan(4) << "  " << widelecPodniesiony(4, 4) <<
    "                   " << widelecPodniesiony(0, 1) << "  " << stan(1) << "  " << widelecPodniesiony(1, 1) << "\n";

    std::cout << "\n\n\n                " << widelecLezacy(3) << "                             " << widelecLezacy(1);

    std::cout << "\n\n\n\n             " << filozofowie[3].imie << "                 " << filozofowie[2].imie << "\n";

    std::cout << "        " << widelecPodniesiony(3, 3) << "  " << stan(3) << "  " << widelecPodniesiony(2, 3) << "       " <<
    widelecPodniesiony(2, 2) << "  " << stan(2) << "  " << widelecPodniesiony(1, 2) << "\n";

    std::cout << "                             " << widelecLezacy(2) << "\n";






    //if (widelce[4].wUzyciu){
    //    std::cout << "--<\n";
    //}
    //else {
    //    std::cout << "\n";
    //}
    //for (unsigned short n = 0; n < filozofowie.size(); n++) {
    //    std::cout << filozofowie[n].imie << ": ";
    //    switch (filozofowie[n].stan) {
    //        case Filozof::watekZatrzymany:
    //            std::cout << "Zatrzymany\n";
    //            break;
    //        case Filozof::bezczynny:
    //            std::cout << "Czeka na widelce\n";
    //            break;
    //        case Filozof::mysli:
    //            std::cout << "Mysli\n";
    //            break;
    //        case Filozof::je:
    //            std::cout << "Je\n";
    //            break;
    //        default:
    //            break;
    //    }
    //    if (widelce[n].wUzyciu){
    //        std::cout << "--<\n";
    //    }
    //    else {
    //        std::cout << "\n";
    //    }
    //}
}