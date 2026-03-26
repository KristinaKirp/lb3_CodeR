#include <iostream>
#include <fstream>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream File("filename.txt");

    if (!File)
    {
        std::cout << "Ошибка открытия файла\n";
        return 1;
    }

    std::string Expression;
    File >> Expression;

    CalcTree Tree;

    Node* Root = Tree.BuildTree(Expression);

    std::cout << "Исходное дерево:\n";
    Tree.PrintTree(Root);

    Root = Tree.RemoveAddition(Root);

    std::cout << "\nДерево после удаления сложения:\n";
    Tree.PrintTree(Root);

    std::cout << "\nУказатель на корень дерева: " << Root << std::endl;

    return 0;
}
