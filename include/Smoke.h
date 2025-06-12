#pragma once
#include "Item.h"
#include "Mission.h"

/**
 * @class SmokeGrenade
 * @brief Reprezentuje granat dymny – przedmiot wpływający na przebieg misji.
 *
 * Klasa SmokeGrenade dziedziczy po klasie Item i modeluje granat dymny,
 * który pozwala komandosowi ukryć się we mgle dymu, zwiększając szanse
 * na pozostanie niezauważonym przez wroga.
 *
 * @note Metoda applyEffect modyfikuje stan misji, aby odzwierciedlić
 * efekt zasłony dymnej na wykrywalność.
 */
class SmokeGrenade : public Item {
public:
    /**
     * @brief Konstruktor domyślny klasy SmokeGrenade.
     */
    SmokeGrenade();

    /**
     * @brief Zastosuj efekt granatu dymnego do misji.
     *
     * Metoda nadpisuje funkcję z klasy bazowej Item i zmienia
     * parametry misji, aby zwiększyć szansę na pozostanie niewykrytym.
     *
     * @param mission Referencja do obiektu Mission, który zostanie zmodyfikowany.
     */
    void applyEffect(Mission& mission) override;
};
