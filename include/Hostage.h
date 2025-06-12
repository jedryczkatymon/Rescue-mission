#pragma once

/**
 * @class Hostage
 * @brief Klasa reprezentująca zakładnika w symulacji.
 *
 * Zakładnik może zostać uratowany przez komandosa.
 * Klasa przechowuje stan uratowania i udostępnia metody
 * do jego sprawdzenia oraz zmiany.
 */
class Hostage {
public:
    /**
     * @brief Sprawdza, czy zakładnik został uratowany.
     * @return true jeśli został uratowany, false w przeciwnym razie.
     */
    bool isRescued() const;

    /**
     * @brief Oznacza zakładnika jako uratowanego.
     */
    void rescue();

private:
    bool rescued = false; ///< Flaga oznaczająca, czy zakładnik został uratowany.
};
