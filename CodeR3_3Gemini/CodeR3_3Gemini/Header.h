#pragma once

#include <vector>
#include <string>

/** * Класс для поиска авиационных маршрутов.
 * Теперь с усиленной проверкой входных данных.
 */
class FAirlineNavigator
{
public:
	FAirlineNavigator();

	/** Загружает данные. Возвращает false, если файл поврежден или пуст. */
	bool LoadMap(const std::string& InFileName);

	void FindRoutes(int InK1, int InK2, int InL);
	void SaveResults(const std::string& InFileName) const;

private:
	int CityCount;
	std::vector<std::vector<int>> AdjacencyMatrix;
	std::vector<std::vector<int>> FoundRoutes;

	void DFS(int CurrentCity, int TargetCity, int StepsLeft, std::vector<int>& CurrentPath);
};