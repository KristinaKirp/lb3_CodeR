#pragma once
#include <string>
#include <unordered_map>

/*
 * Класс MorseTranslator
 * Отвечает за перевод русского текста в азбуку Морзе.
 */
class MorseTranslator
{
public:
    MorseTranslator();

    /*
     * Переводит строку текста в код Морзе.
     * @param Text - входной текст
     * @return строка с точками и тире
     */
    std::string TranslateToMorse(const std::string& Text);
    bool IsValidText(const std::string& Text);

private:
    std::unordered_map<char, std::string> MorseMap;

    /*
     * Заполняет таблицу кодов Морзе.
     */
    void InitializeMorseMap();
};