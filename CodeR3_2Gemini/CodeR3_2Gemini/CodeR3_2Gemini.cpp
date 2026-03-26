#include <iostream>
#include "Header.h"

int main()
{
	// Настройка для красоты вывода
	setlocale(LC_ALL, "Russian");

	FCalcTreeBuilder Builder;
	const std::string TargetFile = "filename.txt";

	std::cout << "Попытка чтения файла: " << TargetFile << std::endl;

	if (!Builder.LoadFromFile(TargetFile))
	{
		std::cout << "Не удалось построить дерево. Проверьте файл!" << std::endl;
		return 1;
	}

	std::cout << "Дерево построено. Убираю сложения..." << std::endl;

	Builder.RemoveAdditionOperations();

	// По заданию: вывести указатель на корень полученного дерева
	FExpressionNode* RootPtr = Builder.GetRoot();

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Указатель на корень: " << RootPtr << std::endl;

	if (RootPtr)
	{
		std::cout << "Значение в корне после преобразования: " << RootPtr->Value << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;

	return 0;
}