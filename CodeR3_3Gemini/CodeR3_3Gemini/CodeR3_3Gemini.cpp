#include <iostream>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	FAirlineNavigator Navigator;
	const std::string FileIn = "FileName1.txt";
	const std::string FileOut = "FileName2.txt";

	// FIX_ME: Добавлена детальная проверка загрузки
	if (!Navigator.LoadMap(FileIn))
	{
		std::cerr << "[Ошибка] Файл " << FileIn << " не найден или содержит некорректные данные!" << std::endl;
		std::cerr << "Убедитесь, что первая строка — это число n (1-15), а далее идет матрица n x n." << std::endl;
		return 1;
	}

	int K1, K2, L;
	std::cout << "Введите начальный город (1-" << 15 << "): ";
	if (!(std::cin >> K1)) return 0;

	std::cout << "Введите конечный город: ";
	if (!(std::cin >> K2)) return 0;

	std::cout << "Введите количество пересадок (L >= 0): ";
	if (!(std::cin >> L)) return 0;

	std::cout << "Выполняю поиск..." << std::endl;
	Navigator.FindRoutes(K1, K2, L);

	Navigator.SaveResults(FileOut);
	std::cout << "Результаты успешно записаны в " << FileOut << std::endl;

	return 0;
}