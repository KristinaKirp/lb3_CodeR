#include "Header.h"
#include <cctype>

MorseTranslator::MorseTranslator()
{
    InitializeMorseMap();
}

void MorseTranslator::InitializeMorseMap()
{
    MorseMap['А'] = ".-";
    MorseMap['Б'] = "-...";
    MorseMap['В'] = ".--";
    MorseMap['Г'] = "--.";
    MorseMap['Д'] = "-..";
    MorseMap['Е'] = ".";
    MorseMap['Ж'] = "...-";
    MorseMap['З'] = "--..";
    MorseMap['И'] = "..";
    MorseMap['Й'] = ".---";
    MorseMap['К'] = "-.-";
    MorseMap['Л'] = ".-..";
    MorseMap['М'] = "--";
    MorseMap['Н'] = "-.";
    MorseMap['О'] = "---";
    MorseMap['П'] = ".--.";
    MorseMap['Р'] = ".-.";
    MorseMap['С'] = "...";
    MorseMap['Т'] = "-";
    MorseMap['У'] = "..-";
    MorseMap['Ф'] = "..-.";
    MorseMap['Х'] = "....";
    MorseMap['Ц'] = "-.-.";
    MorseMap['Ч'] = "---.";
    MorseMap['Ш'] = "----";
    MorseMap['Щ'] = "--.-";
    MorseMap['Ъ'] = ".--.-.";
    MorseMap['Ы'] = "-.--";
    MorseMap['Ь'] = "-..-";
    MorseMap['Э'] = "..-..";
    MorseMap['Ю'] = "..--";
    MorseMap['Я'] = ".-.-";
}

bool MorseTranslator::IsValidText(const std::string& Text)
{
    for (char Ch : Text)
    {
        if (Ch == ' ')
            continue;

        char UpperChar = std::toupper((unsigned char)Ch);

        if (MorseMap.find(UpperChar) == MorseMap.end())
        {
            return false;
        }
    }

    return true;
}

std::string MorseTranslator::TranslateToMorse(const std::string& Text)
{
    std::string Result;

    if (Text.empty())
    {
        return "Ошибка: пустая строка.";
    }

    if (!IsValidText(Text))
    {
        return "Ошибка: строка содержит недопустимые символы.";
    }

    for (char Ch : Text)
    {
        if (Ch == ' ')
        {
            Result += "   ";
            continue;
        }

        char UpperChar = std::toupper((unsigned char)Ch);
        Result += MorseMap[UpperChar] + " ";
    }

    return Result;
}