#include <iostream>
#include <windows.h>
#include "Header.h"

int main()
{
	// Принудительно ставим кодировку консоли на 1251 (Windows Russian)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	FMorseTelegraph Telegraph;

	std::cout << "=== ТЕЛЕГРАФ ЗАПУЩЕН ===" << std::endl;
	std::cout << "(Для выхода введите '0' или 'exit')" << std::endl;

	while (true)
	{
		std::cout << "\nВведите текст: ";
		std::string UserInput = ReadUserLine();

		// Проверка на выход (цифра 0 точно сработает всегда)
		if (UserInput == "0" || UserInput == "exit" || UserInput == "выход")
		{
			std::cout << "Программа завершена." << std::endl;
			break;
		}

		std::string Result = Telegraph.TranslateToMorse(UserInput);
		std::cout << "Морзе: " << Result << std::endl;
	}

	return 0;
}