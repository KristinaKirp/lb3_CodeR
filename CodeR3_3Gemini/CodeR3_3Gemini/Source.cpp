#include "Header.h"
#include <fstream>
#include <algorithm>
#include <iostream>

FAirlineNavigator::FAirlineNavigator() : CityCount(0) {}

bool FAirlineNavigator::LoadMap(const std::string& InFileName)
{
	std::ifstream File(InFileName);

	// Проверка 1: Файл вообще существует?
	if (!File.is_open())
	{
		return false;
	}

	// Проверка 2: Удалось ли прочитать количество городов?
	if (!(File >> CityCount) || CityCount <= 0 || CityCount > 15)
	{
		return false;
	}

	AdjacencyMatrix.assign(CityCount, std::vector<int>(CityCount));

	// Проверка 3: Хватает ли чисел для заполнения матрицы n x n?
	for (int i = 0; i < CityCount; ++i)
	{
		for (int j = 0; j < CityCount; ++j)
		{
			if (!(File >> AdjacencyMatrix[i][j]))
			{
				// Если данные закончились раньше времени или там не число
				return false;
			}
		}
	}

	return true;
}

// ... (Методы DFS и FindRoutes остаются такими же, как в прошлом ответе)

void FAirlineNavigator::DFS(int CurrentCity, int TargetCity, int StepsLeft, std::vector<int>& CurrentPath)
{
	if (StepsLeft == 0)
	{
		if (CurrentCity == TargetCity)
		{
			FoundRoutes.push_back(CurrentPath);
		}
		return;
	}

	for (int NextCity = 0; NextCity < CityCount; ++NextCity)
	{
		if (AdjacencyMatrix[CurrentCity][NextCity] == 1)
		{
			CurrentPath.push_back(NextCity + 1);
			DFS(NextCity, TargetCity, StepsLeft - 1, CurrentPath);
			CurrentPath.pop_back();
		}
	}
}

void FAirlineNavigator::FindRoutes(int InK1, int InK2, int InL)
{
	FoundRoutes.clear();
	if (InK1 < 1 || InK1 > CityCount || InK2 < 1 || InK2 > CityCount) return;

	std::vector<int> CurrentPath;
	CurrentPath.push_back(InK1);
	DFS(InK1 - 1, InK2 - 1, InL + 1, CurrentPath);
	std::sort(FoundRoutes.begin(), FoundRoutes.end());
}

void FAirlineNavigator::SaveResults(const std::string& InFileName) const
{
	std::ofstream File(InFileName);
	if (!File.is_open()) return;

	if (FoundRoutes.empty())
	{
		File << -1;
	}
	else
	{
		File << FoundRoutes.size() << "\n";
		for (const auto& Route : FoundRoutes)
		{
			for (size_t i = 0; i < Route.size(); ++i)
			{
				File << Route[i] << (i == Route.size() - 1 ? "" : " ");
			}
			File << "\n";
		}
	}
}