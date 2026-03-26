#include <iostream>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Graph G;

    if (!G.LoadFromFile("FileName1.txt"))
    {
        std::cout << "Ошибка чтения файла\n";
        return 1;
    }

    int K1, K2, L;

    std::cout << "Введите начальный город: ";
    std::cin >> K1;

    std::cout << "Введите конечный город: ";
    std::cin >> K2;

    std::cout << "Введите количество пересадок: ";
    std::cin >> L;

    G.FindRoutes(K1, K2, L);
    G.SaveRoutes("FileName2.txt");

    std::cout << "Маршруты записаны в файл FileName2.txt\n";

    return 0;
}