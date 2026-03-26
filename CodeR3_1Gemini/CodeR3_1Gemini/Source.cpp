#include "Header.h"
#include <iostream>

FMorseTelegraph::FMorseTelegraph() {}

std::string FMorseTelegraph::GetCodeForChar(unsigned char C) const
{
	// Обработка кириллицы (Windows-1251 и OEM-866)
	// А-Я (192-223 или 128-159), а-я (224-255 или 160-175/224-239)

	// Приводим строчные русские буквы к прописным вручную по кодам
	if (C >= 224 && C <= 255) C -= 32; // CP1251
	if (C >= 160 && C <= 175) C -= 32; // OEM866 (часть 1)
	if (C >= 224 && C <= 239) C -= 80; // OEM866 (часть 2)

	switch (C)
	{
	case 128: case 192: return ".-";   // А
	case 129: case 193: return "-..."; // Б
	case 130: case 194: return ".--";  // В
	case 131: case 195: return "--.";  // Г
	case 132: case 196: return "-..";  // Д
	case 133: case 197: return ".";    // Е
	case 134: case 198: return "...-"; // Ж
	case 135: case 199: return "--.."; // З
	case 136: case 200: return "..";   // И
	case 137: case 201: return ".---"; // Й
	case 138: case 202: return "-.-";  // К
	case 139: case 203: return ".-.."; // Л
	case 140: case 204: return "--";   // М
	case 141: case 205: return "-.";   // Н
	case 142: case 206: return "---";  // О
	case 143: case 207: return ".--."; // П
	case 144: case 208: return ".-.";  // Р
	case 145: case 209: return "...";  // С
	case 146: case 210: return "-";    // Т
	case 147: case 211: return "..-";  // У
	case 148: case 212: return "..-."; // Ф
	case 149: case 213: return "...."; // Х
	case 150: case 214: return "-.-."; // Ц
	case 151: case 215: return "---."; // Ч
	case 152: case 216: return "----"; // Ш
	case 153: case 217: return "--.-"; // Щ
	case 154: case 218: return ".--.-."; // Ъ
	case 155: case 219: return "-.--"; // Ы
	case 156: case 220: return "-..-"; // Ь
	case 157: case 221: return "..-.."; // Э
	case 158: case 222: return "..--"; // Ю
	case 159: case 223: return ".-.-"; // Я
	case ' ': return "   ";
	default: return "[?]";
	}
}

std::string FMorseTelegraph::TranslateToMorse(const std::string& InText) const
{
	std::string Result = "";
	for (unsigned char Symbol : InText)
	{
		Result += GetCodeForChar(Symbol) + " ";
	}
	return Result;
}

std::string ReadUserLine()
{
	std::string Input;
	while (std::getline(std::cin, Input))
	{
		if (Input.empty() || Input.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "Пустой ввод! Напишите слово: ";
			continue;
		}
		return Input;
	}
	return "";
}