#pragma once
#include <vector>
#include <chrono>
#include <random>
#include "Commando.h"
#include "Guard.h"
#include "Hostage.h"

/**
 * @class Mission
 * @brief Główna klasa odpowiadająca za przebieg symulacji misji.
 *
 * Zarządza stanem misji, interakcjami między komandosami, strażnikami i zakładnikami,
 * a także obsługuje efekty specjalne (flashbang, smoke) i zapis logów z przebiegu.
 */
class Mission {
public:
    /**
     * @brief Konstruktor inicjalizujący misję i zasiewający generator losowy.
     */
    Mission();

    /**
     * @brief Rozpoczyna i przeprowadza pełną symulację misji.
     */
    void run();

    /**
     * @brief Wypisuje zapisane logi z przebiegu misji.
     */
    void logResults() const;

    /**
     * @brief Ustawia, czy komandos ma tłumik.
     * @param value true jeśli tak, false jeśli nie.
     */
    void setHasSilencer(bool value) { hasSilencer = value; }

    /**
     * @brief Sprawdza, czy komandos posiada tłumik.
     * @return true jeśli ma, false w przeciwnym razie.
     */
    bool getHasSilencer() const { return hasSilencer; }

    /**
     * @brief Dodaje wiadomość do logu misji.
     * @param message Tekst wiadomości do zapisania.
     */
    virtual void log(const std::string& message);

    /**
     * @brief Zwiększa poziom efektu flashbanga.
     */
    void applyFlashbangEffect();

    /**
     * @brief Zwiększa poziom efektu dymu.
     */
    void applySmokeEffect();

    /**
     * @brief Pobiera aktualny poziom efektu flashbanga.
     * @return Wartość efektu.
     */
    int getFlashbangEffect() const;

    /**
     * @brief Pobiera aktualny poziom efektu dymu.
     * @return Wartość efektu.
     */
    int getSmokeEffect() const;

private:
    Commando commando;                          ///< Obiekt komandosa uczestniczącego w misji.
    std::vector<Guard> guards;                  ///< Lista strażników.
    std::vector<Hostage> hostages;              ///< Lista zakładników.
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime; ///< Czas rozpoczęcia misji.
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;   ///< Czas zakończenia misji.
    std::vector<std::string> logEntries;        ///< Zebrane logi z przebiegu misji.
    bool missionSuccess = false;                ///< Flaga powodzenia misji.
    int killedGuards = 0;                       ///< Liczba wyeliminowanych strażników.
    bool hasSilencer = false;                   ///< Czy komandos posiada tłumik.
    int flashbangEffect = 0;                    ///< Siła efektu flashbanga.
    int smokeEffect = 0;                        ///< Siła efektu dymu.

    std::mt19937 rng;                           ///< Generator liczb pseudolosowych.

    /**
     * @brief Główna funkcja symulacji przebiegu misji.
     */
    void simulate();

    /**
     * @brief Symuluje spotkania ze strażnikami.
     * @param missionFailed Referencja do flagi porażki misji.
     */
    void simulateGuardEncounters(bool& missionFailed);

    /**
     * @brief Symuluje użycie przedmiotów przez komandosa.
     */
    void simulateItemUsage();

    /**
     * @brief Próbuje uratować zakładników.
     */
    void rescueHostages();

    /**
     * @brief Zapisuje logi do pliku CSV.
     */
    void logToCSV() const;
};
