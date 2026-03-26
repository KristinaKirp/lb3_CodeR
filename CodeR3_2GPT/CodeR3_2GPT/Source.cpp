#include "Header.h"
#include <stack>
#include <iostream>

Node::Node(int InValue)
{
    Value = InValue;
    Left = nullptr;
    Right = nullptr;
}

CalcTree::CalcTree()
{
}

int CalcTree::CharToOperation(char Ch)
{
    if (Ch == '+') return -1;
    if (Ch == '-') return -2;
    if (Ch == '*') return -3;
    if (Ch == '/') return -4;
    return Ch - '0';
}

Node* CalcTree::BuildTree(const std::string& Expression)
{
    std::stack<Node*> Stack;

    for (char Ch : Expression)
    {
        if (isdigit(Ch))
        {
            Stack.push(new Node(Ch - '0'));
        }
        else
        {
            Node* Right = Stack.top();
            Stack.pop();
            Node* Left = Stack.top();
            Stack.pop();

            Node* OpNode = new Node(CharToOperation(Ch));
            OpNode->Left = Left;
            OpNode->Right = Right;

            Stack.push(OpNode);
        }
    }

    return Stack.top();
}

int CalcTree::Evaluate(Node* Root)
{
    if (!Root)
        return 0;

    if (Root->Value >= 0)
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

    return 0;
}

Node* CalcTree::RemoveAddition(Node* Root)
{
    if (!Root)
        return nullptr;

    Root->Left = RemoveAddition(Root->Left);
    Root->Right = RemoveAddition(Root->Right);

    if (Root->Value == -1)
    {
        int Result = Evaluate(Root);
        return new Node(Result);
    }

    return Root;
}

void CalcTree::PrintTree(Node* Root)
{
    if (!Root)
        return;

    std::cout << Root->Value << " ";
    PrintTree(Root->Left);
    PrintTree(Root->Right);
}