#pragma once

#include <string>

/** * ”зел бинарного дерева выражени€.
 * ѕо условию: 0-9 Ч числа, -1 Ч (+), -2 Ч (-), -3 Ч (*), -4 Ч (/).
 */
struct FExpressionNode
{
	int Value;
	FExpressionNode* Left;
	FExpressionNode* Right;

	FExpressionNode(int InValue)
		: Value(InValue), Left(nullptr), Right(nullptr) {
	}
};

class FCalcTreeBuilder
{
public:
	FCalcTreeBuilder();
	~FCalcTreeBuilder();

	/** —оздает дерево из файла filename.txt */
	bool LoadFromFile(const std::string& InFileName);

	/** ”бирает все операции сложени€, замен€€ их результатом */
	void RemoveAdditionOperations();

	/** ѕечать дерева (дл€ проверки, можно удалить) */
	void PrintTree(FExpressionNode* Node, int Level = 0);

	FExpressionNode* GetRoot() const { return Root; }

private:
	FExpressionNode* Root;

	/** –екурсивные помощники */
	void DeleteNode(FExpressionNode* Node);
	int CalculateValue(FExpressionNode* Node);
	FExpressionNode* Simplify(FExpressionNode* Node);
};