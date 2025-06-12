#pragma once
#include "Item.h"
#include "Mission.h"

/**
 * @class Flashbang
 * @brief Przedmiot typu granat hukowy używany w misji.
 *
 * Flashbang jest specjalnym przedmiotem, który wpływa na misję,
 * najprawdopodobniej tymczasowo dezorientując przeciwników lub
 * wpływając na inne mechaniki. Dziedziczy po klasie Item.
 */
class Flashbang : public Item {
public:
    /**
     * @brief Konstruktor domyślny.
     */
    Flashbang();

    /**
     * @brief Zastosowanie efektu granatu na misję.
     * @param mission Referencja do aktualnej misji.
     */
    void applyEffect(Mission& mission) override;
};
