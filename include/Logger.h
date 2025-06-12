#pragma once
#include <string>

/**
 * @class Logger
 * @brief Klasa pomocnicza do zapisu danych w formacie CSV.
 *
 * Udostępnia statyczną metodę do zapisu tekstowych danych
 * do pliku CSV o podanej nazwie.
 */
class Logger {
public:
    /**
     * @brief Zapisuje dane do pliku CSV.
     * @param filename Nazwa pliku, do którego mają zostać zapisane dane.
     * @param data Dane w formacie tekstowym (np. już sformatowany wiersz CSV).
     * @return true jeśli zapis się powiódł, false w przeciwnym razie.
     */
    static bool writeCSV(const std::string& filename, const std::string& data);
};
