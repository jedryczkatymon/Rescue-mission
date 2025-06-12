#pragma once
#include "Agent.h"

/**
 * @class Guard
 * @brief Klasa reprezentująca strażnika w symulacji.
 *
 * Strażnik posiada szansę wykrycia komandosa, którą można modyfikować.
 * Dziedziczy po klasie Agent i nadpisuje metodę doSpeak().
 */
class Guard : public Agent
{
public:
    /**
     * @brief Konstruktor strażnika.
     * @param detectionChance Podstawowa szansa na wykrycie komandosa (0.0–1.0).
     */
    Guard(float detectionChance);

    /**
     * @brief Próba wykrycia komandosa z uwzględnieniem modyfikatora.
     * @param modifier Modyfikator wpływający na skuteczność wykrycia (domyślnie 1.0).
     * @return true jeśli wykryto, false w przeciwnym razie.
     */
    bool detectCommando(float modifier = 1.0f);

    /**
     * @brief Nadpisana metoda wypowiedzi strażnika.
     */
    void doSpeak() override;

private:
    float detectionChance; ///< Bazowa szansa wykrycia komandosa.
};
