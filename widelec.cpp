#include <mutex>

#include "widelec.hpp"

bool Widelec::podnies(Filozof* filozof) {
    std::mutex mut;
    mut.lock();
    if (wUzyciu) {
        mut.unlock();
        return false;
    }
    wUzyciu = true;
    obecny = filozof;

    mut.unlock();

    return true;
}

void Widelec::odloz() {
    std::mutex mut;
    mut.lock();
    wUzyciu = false;
    mut.unlock();
}