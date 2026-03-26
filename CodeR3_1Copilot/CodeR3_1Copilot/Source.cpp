#include "Header.h"
#include <cctype>

FMorseConverter::FMorseConverter()
{
    MorseTable =
    {
        {'À',"·–"}, {'Á',"–···"}, {'Â',"·––"}, {'Ã',"––·"},
        {'Ä',"–··"}, {'Å',"·"}, {'Æ',"···–"}, {'Ç',"––··"},
        {'È',"··"}, {'É',"·–––"}, {'Ê',"–·–"}, {'Ë',"·–··"},
        {'Ì',"––"}, {'Í',"–·"}, {'Î',"–––"}, {'Ï',"·––·"},
        {'Ğ',"·–·"}, {'Ñ',"···"}, {'Ò',"–"}, {'Ó',"··–"},
        {'Ô',"··–·"}, {'Õ',"····"}, {'Ö',"–·–·"}, {'×',"–––·"},
        {'Ø',"––––"}, {'Ù',"–––·–"}, {'Ú',"––––·"}, {'Û',"–·––"},
        {'Ü',"–··–"}, {'İ',"··–··"}, {'Ş',"··––"}, {'ß',"·–·–"}
    };
}

char FMorseConverter::ToUpper(char C) const
{
    return static_cast<char>(std::toupper(static_cast<unsigned char>(C)));
}

std::string FMorseConverter::ConvertToMorse(const std::string& Message) const
{
    std::string Result;

    for (char C : Message)
    {
        if (C == ' ')
        {
            Result += "   "; // Ğàçäåëåíèå ñëîâ
            continue;
        }

        char Upper = ToUpper(C);

        if (MorseTable.find(Upper) != MorseTable.end())
        {
            Result += MorseTable.at(Upper) + " ";
        }
        else
        {
            return "Îøèáêà: ñèìâîë '" + std::string(1, C) + "' íå ïîääåğæèâàåòñÿ.";
        }
    }

    return Result;
}
