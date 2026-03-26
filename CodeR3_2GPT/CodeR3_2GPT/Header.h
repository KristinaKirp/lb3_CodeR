#pragma once
#include <string>

/*
 * Структура узла дерева выражения
 */
struct Node
{
    int Value;
    Node* Left;
    Node* Right;

    Node(int InValue);
};

/*
 * Класс для работы с деревом выражения
 */
class CalcTree
{
public:
    CalcTree();

    /*
     * Строит дерево из обратной польской записи
     */
    Node* BuildTree(const std::string& Expression);

    /*
     * Преобразует дерево (убирает операции сложения)
     */
    Node* RemoveAddition(Node* Root);

    /*
     * Вычисляет значение поддерева
     */
    int Evaluate(Node* Root);

    /*
     * Печатает дерево (прямой обход)
     */
    void PrintTree(Node* Root);

private:
    int CharToOperation(char Ch);
};
