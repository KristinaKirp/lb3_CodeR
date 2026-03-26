#pragma once
#include <vector>
#include <string>

/*
 * Класс Graph
 * Работает с графом авиамаршрутов
 */
class Graph
{
public:
    /*
     * Читает граф из файла
     */
    bool LoadFromFile(const std::string& FileName);

    /*
     * Ищет все маршруты с L пересадками
     */
    void FindRoutes(int Start, int End, int Transfers);

    /*
     * Записывает маршруты в файл
     */
    void SaveRoutes(const std::string& FileName);

private:
    int N;
    int Matrix[15][15];

    std::vector<std::vector<int>> Routes;
    std::vector<int> CurrentPath;

    /*
     * DFS поиск маршрутов
     */
    void DFS(int Current, int End, int StepsLeft);
};