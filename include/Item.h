#pragma once
#include <string>

class Mission;

/**
 * @class Item
 * @brief Abstrakcyjna klasa bazowa dla przedmiotów w symulacji.
 *
 * Każdy przedmiot posiada nazwę, może być użyty tylko raz i wywiera
 * efekt na misję poprzez metodę applyEffect(). Stan użycia jest
 * przechowywany i dostępny do modyfikacji.
 */
class Item
{
public:
    /**
     * @brief Konstruktor przedmiotu.
     * @param name Nazwa przedmiotu.
     */
    Item(const std::string &name);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Item() = default;

    /**
     * @brief Zwraca nazwę przedmiotu.
     * @return Referencja do nazwy.
     */
    const std::string &getName() const;

    /**
     * @brief Sprawdza, czy przedmiot został użyty.
     * @return true jeśli użyty, false w przeciwnym razie.
     */
    bool isUsed() const;

    /**
     * @brief Oznacza przedmiot jako użyty.
     */
    void use();

    /**
     * @brief Wirtualna metoda stosowania efektu przedmiotu na misję.
     * @param mission Referencja do misji, na którą działa przedmiot.
     */
    virtual void applyEffect(Mission &mission) = 0;

    /**
     * @brief Ustawia stan użycia przedmiotu.
     * @param value true, jeśli przedmiot został użyty.
     */
    void setUsed(bool value);

protected:
    std::string name; ///< Nazwa przedmiotu.
    bool used = false; ///< Flaga oznaczająca, czy przedmiot został użyty.
};
