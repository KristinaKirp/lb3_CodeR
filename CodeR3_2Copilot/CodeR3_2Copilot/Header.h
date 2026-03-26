#pragma once
#include <string>

/**
 * Структура узла дерева выражения.
 * Хранит значение (число или код операции) и указатели на потомков.
 */
struct FNode
{
    int Value;
    FNode* Left;
    FNode* Right;

    FNode(int InValue)
        : Value(InValue), Left(nullptr), Right(nullptr)
    {
    }
};

/**
 * Класс для построения и преобразования дерева арифметического выражения.
 */
class FCalcTree
{
public:
    /**
     * Строит дерево из строки в обратной польской записи.
     */
    FNode* BuildTree(const std::string& Expression);

    /**
     * Удаляет операции сложения, заменяя поддеревья их вычисленным значением.
     */
    FNode* RemoveAdd(FNode* Root);

    /**
     * Вычисляет значение поддерева.
     */
    int Evaluate(FNode* Root);

private:
    /**
     * Преобразует символ операции в код.
     */
    int GetOpCode(char Op);

    /**
     * Проверяет, является ли символ операцией.
     */
    bool IsOperator(char C);
};

