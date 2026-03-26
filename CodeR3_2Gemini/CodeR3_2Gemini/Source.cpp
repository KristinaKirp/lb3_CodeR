#include "Header.h"
#include <fstream>
#include <stack>
#include <iostream>

FCalcTreeBuilder::FCalcTreeBuilder() : Root(nullptr) {}

FCalcTreeBuilder::~FCalcTreeBuilder()
{
	DeleteNode(Root);
}

void FCalcTreeBuilder::DeleteNode(FExpressionNode* Node)
{
	if (Node)
	{
		DeleteNode(Node->Left);
		DeleteNode(Node->Right);
		delete Node;
	}
}

bool FCalcTreeBuilder::LoadFromFile(const std::string& InFileName)
{
	std::ifstream File(InFileName);
	if (!File.is_open()) return false;

	std::stack<FExpressionNode*> Stack;
	std::string Token;

	// Читаем файл посимвольно или по словам
	char Char;
	while (File >> Char)
	{
		if (isdigit(Char))
		{
			Stack.push(new FExpressionNode(Char - '0'));
		}
		else
		{
			// Если это операция, достаем два операнда
			if (Stack.size() < 2) return false;

			int OpCode = 0;
			if (Char == '+') OpCode = -1;
			else if (Char == '-') OpCode = -2;
			else if (Char == '*') OpCode = -3;
			else if (Char == '/') OpCode = -4;

			FExpressionNode* NewNode = new FExpressionNode(OpCode);
			NewNode->Right = Stack.top(); Stack.pop();
			NewNode->Left = Stack.top(); Stack.pop();
			Stack.push(NewNode);
		}
	}

	if (!Stack.empty()) Root = Stack.top();
	return Root != nullptr;
}

int FCalcTreeBuilder::CalculateValue(FExpressionNode* Node)
{
	if (!Node) return 0;
	if (Node->Value >= 0) return Node->Value;

	int L = CalculateValue(Node->Left);
	int R = CalculateValue(Node->Right);

	if (Node->Value == -1) return L + R;
	if (Node->Value == -2) return L - R;
	if (Node->Value == -3) return L * R;
	if (Node->Value == -4) return (R != 0) ? L / R : 0;
	return 0;
}

FExpressionNode* FCalcTreeBuilder::Simplify(FExpressionNode* Node)
{
	if (!Node) return nullptr;

	// Идем вглубь
	Node->Left = Simplify(Node->Left);
	Node->Right = Simplify(Node->Right);

	// Если нашли сложение (-1)
	if (Node->Value == -1)
	{
		// Считаем результат этого поддерева
		int Total = CalculateValue(Node);

		// Очищаем ветки, так как узел становится числом
		DeleteNode(Node->Left);
		DeleteNode(Node->Right);

		Node->Left = nullptr;
		Node->Right = nullptr;
		Node->Value = Total;
	}
	return Node;
}

void FCalcTreeBuilder::RemoveAdditionOperations()
{
	Root = Simplify(Root);
}