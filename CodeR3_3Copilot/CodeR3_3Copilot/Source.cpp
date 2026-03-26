#include "Header.h"
#include <fstream>
#include <algorithm>

bool FGraph::LoadFromFile(const std::string& FileName)
{
    std::ifstream File(FileName);
    if (!File.is_open())
        return false;

    File >> N;
    if (N <= 0 || N > 15)
        return false;

    Matrix.assign(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            File >> Matrix[i][j];

    return true;
}

void FGraph::DFS(int Current, int Target, int StepsLeft,
    std::vector<int>& Path,
    std::vector<std::vector<int>>& Result)
{
    if (StepsLeft == 0)
    {
        if (Current == Target)
            Result.push_back(Path);
        return;
    }

    for (int Next = 0; Next < N; Next++)
    {
        if (Matrix[Current][Next] == 1)
        {
            Path.push_back(Next + 1);
            DFS(Next, Target, StepsLeft - 1, Path, Result);
            Path.pop_back();
        }
    }
}

std::vector<std::vector<int>> FGraph::FindRoutes(int K1, int K2, int L)
{
    std::vector<std::vector<int>> Result;
    std::vector<int> Path;

    Path.push_back(K1);

    DFS(K1 - 1, K2 - 1, L + 1, Path, Result);

    std::sort(Result.begin(), Result.end());

    return Result;
}
