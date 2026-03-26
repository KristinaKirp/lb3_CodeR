#include <iostream>
#include <string>
#include "Header.h"
#include "Windows.h"

/**
 * Точка входа программы.
 * Обеспечивает дружелюбный интерфейс, ввод пользователя и вывод результата.
 */
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "==============================\n";
    std::cout << "   Телеграф — Азбука Морзе\n";
    std::cout << "==============================\n\n";

    std::cout << "Введите сообщение (только русские буквы):\n> ";

    std::string Input;
    std::getline(std::cin, Input);

    if (Input.empty())
    {
        std::cout << "Ошибка: строка не может быть пустой.\n";
        return 1;
    }

    FMorseConverter Converter;
    std::string Morse = Converter.ConvertToMorse(Input);

    std::cout << "\nРезультат:\n" << Morse << "\n";

    std::cout << "\nСпасибо за использование телеграфа!\n";

    return 0;
}
