#pragma once
#include <string>
#include <unordered_map>

/**
 * Класс, отвечающий за преобразование русских букв в код Морзе.
 * Хранит таблицу кодов и предоставляет метод для конвертации строки.
 */
class FMorseConverter
{
public:
    FMorseConverter();

    /**
     * Преобразует входную строку в последовательность точек и тире.
     * Возвращает строку с кодом Морзе или сообщение об ошибке.
     */
    std::string ConvertToMorse(const std::string& Message) const;

private:
    /** Таблица соответствия символов и кода Морзе */
    std::unordered_map<char, std::string> MorseTable;

    /** Приводит символ к верхнему регистру */
    char ToUpper(char C) const;
};
