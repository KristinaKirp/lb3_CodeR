#include "Header.h"
#include <stack>
#include <cctype>
#include <stdexcept>

int FCalcTree::GetOpCode(char Op)
{
    switch (Op)
    {
    case '+': return -1;
    case '-': return -2;
    case '*': return -3;
    case '/': return -4;
    }
    return 0;
}

bool FCalcTree::IsOperator(char C)
{
    return (C == '+' || C == '-' || C == '*' || C == '/');
}

FNode* FCalcTree::BuildTree(const std::string& Expression)
{
    std::stack<FNode*> Stack;

    for (char C : Expression)
    {
        if (C == ' ')
            continue;

        if (std::isdigit(C))
        {
            Stack.push(new FNode(C - '0'));
        }
        else if (IsOperator(C))
        {
            if (Stack.size() < 2)
                throw std::runtime_error("Ошибка: недостаточно операндов.");

            FNode* Right = Stack.top(); Stack.pop();
            FNode* Left = Stack.top(); Stack.pop();

            FNode* OpNode = new FNode(GetOpCode(C));
            OpNode->Left = Left;
            OpNode->Right = Right;

            Stack.push(OpNode);
        }
        else
        {
            throw std::runtime_error("Ошибка: недопустимый символ.");
        }
    }

    if (Stack.size() != 1)
        throw std::runtime_error("Ошибка: выражение некорректно.");

    return Stack.top();
}

int FCalcTree::Evaluate(FNode* Root)
{
    if (!Root->Left && !Root->Right)
        return Root->Value;

    int L = Evaluate(Root->Left);
    int R = Evaluate(Root->Right);

    switch (Root->Value)
    {
    case -1: return L + R;
    case -2: return L - R;
    case -3: return L * R;
    case -4: return L / R;
    }

    throw std::runtime_error("Ошибка: неизвестная операция.");
}

FNode* FCalcTree::RemoveAdd(FNode* Root)
{
    if (!Root)
        return nullptr;

    Root->Left = RemoveAdd(Root->Left);
    Root->Right = RemoveAdd(Root->Right);

    if (Root->Value == -1) // сложение
    {
        int Val = Evaluate(Root);
        return new FNode(Val);
    }

    return Root;
}
