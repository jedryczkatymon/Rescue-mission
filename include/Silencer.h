#pragma once
#include "Item.h"

/**
 * @class Silencer
 * @brief Przedmiot typu tłumik, który wpływa na misję.
 *
 * Tłumik pozwala komandosowi działać ciszej, zmniejszając
 * prawdopodobieństwo wykrycia przez strażników. Dziedziczy po klasie Item.
 */
class Silencer : public Item
{
public:
    /**
     * @brief Konstruktor domyślny tłumika.
     */
    Silencer();

    /**
     * @brief Nakłada efekt tłumika na misję (np. aktywuje tryb cichy).
     * @param mission Referencja do misji, której dotyczy efekt.
     */
    void applyEffect(Mission &mission) override;
};
