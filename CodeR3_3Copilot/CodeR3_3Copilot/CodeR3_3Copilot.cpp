#include <iostream>
#include <windows.h>
#include <fstream>
#include "Header.h"

// Цвета консоли
void SetColor(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

/**
 * Точка входа программы.
 * Загружает граф, ищет маршруты и выводит результат в файл.
 */
int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "==============================\n";
    std::cout << "     Graf9 — Поиск маршрутов\n";
    std::cout << "==============================\n\n";

    std::cout << "Введите имя входного файла:\n> ";


    std::string FileIn;
    std::getline(std::cin, FileIn);

    FGraph Graph;
    if (!Graph.LoadFromFile(FileIn))
    {
        std::cout << "Ошибка: не удалось загрузить граф.\n";
        return 1;
    }

    int K1, K2, L;

    std::cout << "Введите город K1: ";

    std::cin >> K1;

    std::cout << "Введите город K2: ";

    std::cin >> K2;

    std::cout << "Введите количество пересадок L: ";
    std::cin >> L;

    if (K1 <= 0 || K2 <= 0 || L < 0)
    {
        std::cout << "Ошибка: некорректные входные данные.\n";
        return 1;
    }

    auto Routes = Graph.FindRoutes(K1, K2, L);

    std::cout << "Введите имя выходного файла:\n> ";

    std::string FileOut;
    std::cin >> FileOut;

    std::ofstream Out(FileOut);
    if (!Out.is_open())
    {
        std::cout << "Ошибка: не удалось открыть выходной файл.\n";
        return 1;
    }

    if (Routes.empty())
    {
        Out << -1;
        std::cout << "Маршрутов нет.\n";
    }
    else
    {
        Out << Routes.size() << "\n";
        for (auto& R : Routes)
        {
            for (int City : R)
                Out << City << " ";
            Out << "\n";
        }

        std::cout << "Маршруты успешно записаны в файл.\n";
    }

    return 0;
}
