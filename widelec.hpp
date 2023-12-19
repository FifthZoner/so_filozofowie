#ifndef SO_FILOZOFOWIE_WIDELEC_HPP
#define SO_FILOZOFOWIE_WIDELEC_HPP

struct Filozof;

struct Widelec {
    volatile bool wUzyciu = false;
    Filozof* obecny = nullptr;

    bool podnies(Filozof* filozof);
    void odloz();
};

#endif //SO_FILOZOFOWIE_WIDELEC_HPP
