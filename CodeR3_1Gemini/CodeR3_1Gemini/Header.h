#pragma once
#include <string>

class FMorseTelegraph
{
public:
	FMorseTelegraph();
	/** Основной метод перевода */
	std::string TranslateToMorse(const std::string& InText) const;

private:
	/** Вспомогательная функция для сопоставления символа и кода */
	std::string GetCodeForChar(unsigned char InChar) const;
};

/** Безопасное чтение строки с проверкой на пустоту */
std::string ReadUserLine();