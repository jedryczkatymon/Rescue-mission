#pragma once

#include <memory>
#include <vector>
#include "Item.h"
#include "Agent.h"

/**
 * @class Commando
 * @brief Klasa reprezentująca komandosa, dziedzicząca po Agencie.
 *
 * Komandos może przechowywać przedmioty (inventory) i wchodzić w interakcje
 * z otoczeniem poprzez nadpisaną metodę doSpeak(). Klasa zarządza pamięcią
 * za pomocą wskaźników smart (`unique_ptr`).
 */
class Commando : public Agent
{
public:
    /**
     * @brief Domyślny destruktor wirtualny.
     */
    virtual ~Commando() = default;

    /**
     * @brief Dodaje przedmiot do ekwipunku.
     * @param item Wskaźnik do przedmiotu (przekazany przez unique_ptr).
     */
    void addItem(std::unique_ptr<Item> item);

    /**
     * @brief Zwraca stałą referencję do ekwipunku komandosa.
     * @return Stała referencja do wektora unikalnych wskaźników Item.
     */
    const std::vector<std::unique_ptr<Item>> &getItems() const;

    /**
     * @brief Zwraca referencję do ekwipunku komandosa (modyfikowalną).
     * @return Referencja do wektora unikalnych wskaźników Item.
     */
    std::vector<std::unique_ptr<Item>> &getItems();

    /**
     * @brief Nadpisana metoda wypowiedzi komandosa.
     */
    void doSpeak() override;

private:
    std::vector<std::unique_ptr<Item>> inventory; ///< Ekwipunek komandosa.
};
