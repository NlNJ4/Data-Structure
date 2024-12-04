#include <bits/stdc++.h>
using namespace std;

#define ALL(a) a.begin(), a.end()

vector<int> sp(map<pair<int, int>, int> fare, int n, int max_fare)
{
    max_fare *= 2;
    max_fare++;
    vector<int> tmp(n, max_fare);
    vector<vector<int>> table(n, tmp);

    for (auto f : fare)
    {
        table[f.first.first][f.first.second] = fare[f.first];
    }
    for (int i = 0; i < n; i++)
    {
        table[i][i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (table[0][j] > table[0][k] + table[k][j])
            {
                table[0][j] = table[0][k] + table[k][j];
            }
        }
    }

    vector<int> output(n);
    for (int i = 0; i < n; i++)
    {
        if (table[0][i] < max_fare)
            output[i] = table[0][i];
        else
            output[i] = -1;
    }

    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<int, int> ci, co;
    for (int i = 0; i < n; i++)
    {
        cin >> ci[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> co[i];
    }

    int max_fare = 0;
    map<pair<int, int>, int> fare; // contain pair of (from,to) and total cost
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int aco = co[a]; // aco = cost out from a
        int bci = ci[b]; // bci = cost in to b
        int cio = aco + bci;

        fare[make_pair(a, b)] = cio;
        max_fare += cio;
    }

    vector<int> output = sp(fare, n, max_fare);

    for (auto o : output)
    {
        cout << o << " ";
    }
}