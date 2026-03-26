#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Header.h"

// Цвета консоли
void SetColor(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

/**
 * Точка входа программы.
 * Обеспечивает интерфейс, загрузку файла, построение дерева и вывод результата.
 */
int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "==============================\n";
    std::cout << "     CalcTree2 — Построение дерева\n";
    std::cout << "==============================\n\n";

    std::cout << "Введите имя файла:\n> ";
    
    std::string FileName;
    std::getline(std::cin, FileName);

    std::ifstream File(FileName);
    if (!File.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл.\n";
        return 1;
    }

    std::string Expression;
    std::getline(File, Expression);

    if (Expression.empty())
    {
        std::cout << "Ошибка: файл пуст.\n";
        return 1;
    }

    try
    {
        FCalcTree Tree;

        FNode* Root = Tree.BuildTree(Expression);
        Root = Tree.RemoveAdd(Root);

        std::cout << "\nДерево успешно построено.\n";

        std::cout << "Указатель на корень: " << Root << "\n";
    }
    catch (const std::exception& Ex)
    {
        std::cout << "Ошибка: " << Ex.what() << "\n";
        return 1;
    }

    std::cout << "\nГотово!\n";

    return 0;
}
