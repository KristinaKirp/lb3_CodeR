#pragma once
#include <vector>
#include <string>

/**
 * Класс графа, построенного по матрице смежности.
 * Позволяет искать маршруты фиксированной длины (по количеству пересадок).
 */
class FGraph
{
public:
    /**
     * Загружает граф из файла.
     * Формат: n, затем n строк матрицы смежности.
     */
    bool LoadFromFile(const std::string& FileName);

    /**
     * Ищет все маршруты из K1 в K2 с L пересадками.
     * Пересадки = количество промежуточных городов.
     * Длина маршрута = L + 1 рёбер.
     */
    std::vector<std::vector<int>> FindRoutes(int K1, int K2, int L);

private:
    std::vector<std::vector<int>> Matrix;
    int N = 0;

    /**
     * Рекурсивный DFS для поиска маршрутов.
     */
    void DFS(int Current, int Target, int StepsLeft,
        std::vector<int>& Path,
        std::vector<std::vector<int>>& Result);
};
