#pragma once

/**
 * @class Agent
 * @brief Bazowa klasa reprezentująca agenta w symulacji.
 *
 * Agent może być "żywy" lub "martwy", może wykonywać akcje
 * oraz wchodzić w interakcje z innymi obiektami. Stan agenta
 * jest kontrolowany przez flagę `alive`. Klasa zawiera też
 * wirtualną metodę do komunikacji (speak), możliwą do nadpisania.
 */
class Agent
{
public:
    /**
     * @brief Konstruktor agenta.
     * @param alive Określa, czy agent ma być żywy (domyślnie true).
     */
    Agent(bool alive = true);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Agent() = default;

    /**
     * @brief Sprawdza, czy agent żyje.
     * @return true jeśli żyje, false jeśli nie.
     */
    bool isAlive() const;

    /**
     * @brief Zabija agenta (ustawia alive = false).
     */
    void kill();

    /**
     * @brief Wirtualna metoda wypowiedzi agenta.
     * Może być nadpisana w klasach pochodnych.
     */
    virtual void doSpeak();

protected:
    bool alive; ///< Flaga określająca, czy agent jest żywy.
};
