#include "Header.h"
#include <fstream>
#include <algorithm>

bool Graph::LoadFromFile(const std::string& FileName)
{
    std::ifstream File(FileName);

    if (!File.is_open())
        return false;

    File >> N;

    if (N <= 0 || N > 15)
        return false;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            File >> Matrix[i][j];

    return true;
}

void Graph::DFS(int Current, int End, int StepsLeft)
{
    CurrentPath.push_back(Current);

    if (StepsLeft == 0)
    {
        if (Current == End)
            Routes.push_back(CurrentPath);

        CurrentPath.pop_back();
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (Matrix[Current - 1][i] == 1)
        {
            DFS(i + 1, End, StepsLeft - 1);
        }
    }

    CurrentPath.pop_back();
}

void Graph::FindRoutes(int Start, int End, int Transfers)
{
    Routes.clear();
    CurrentPath.clear();

    int Steps = Transfers + 1;
    DFS(Start, End, Steps);

    std::sort(Routes.begin(), Routes.end());
}

void Graph::SaveRoutes(const std::string& FileName)
{
    std::ofstream File(FileName);

    if (Routes.empty())
    {
        File << -1;
        return;
    }

    File << Routes.size() << "\n";

    for (auto& Route : Routes)
    {
        for (int City : Route)
            File << City << " ";

        File << "\n";
    }
}