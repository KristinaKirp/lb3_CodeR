#include <iostream>
#include "Header.h"
#include "Windows.h"

int main()
{
    setlocale(LC_ALL, "rus"); //локализаторы добавиоа сама
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    MorseTranslator Translator;
    std::string InputText;

    while (true)
    {
        std::cout << "\nВведите сообщение на русском (0 - выход): ";
        std::getline(std::cin, InputText);

        if (InputText == "0")
        {
            std::cout << "Выход из программы.\n";
            break;
        }

        if (InputText.empty())
        {
            std::cout << "Ошибка: вы ввели пустую строку.\n";
            continue;
        }

        if (!Translator.IsValidText(InputText))
        {
            std::cout << "Ошибка: допустимы только русские буквы и пробел.\n";
            continue;
        }

        std::string MorseCode = Translator.TranslateToMorse(InputText);

        std::cout << "Код Морзе:\n";
        std::cout << MorseCode << std::endl;
    }

    return 0;
}