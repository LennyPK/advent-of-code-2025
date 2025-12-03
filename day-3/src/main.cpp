#include <iostream>
#include <fstream>
#include <vector>
// #include <string>
// #include <bits/stdc++.h>

using namespace std;

bool PART_ONE = false;

vector<string> readData()
{
    string fileName;
    cout << "Enter the input file to read from: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Failed to open file for reading.\n";
        return {};
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    inputFile.close();

    cout << "Vector is " << lines.size() << " items long" << endl;

    return lines;
}

string pickMaxSubsequence(const string &s, int N)
{
    if (N == 0)
        return "";
    if (N > s.size())
    {
        // Optional: handle invalid case
        cerr << "Cannot pick " << N << " digits from string of length " << s.size() << endl;
        return string(N, '0'); // or throw, or return partial
    }

    string result;
    int start = 0;

    for (int k = 0; k < N; ++k)
    {
        int remaining = N - k; // including current digit
        int maxSearchIndex = s.size() - remaining;

        // If we can't find enough digits left, take the best available
        if (maxSearchIndex < start)
        {
            maxSearchIndex = s.size() - 1;
        }

        char best = '0';
        int bestPos = start;

        for (int i = start; i <= maxSearchIndex && i < (int)s.size(); ++i)
        {
            if (s[i] > best)
            {
                best = s[i];
                bestPos = i;
            }
        }

        result.push_back(best);
        start = bestPos + 1;
    }

    cout << "Result: " << result << endl;

    return result;
}

int main()
{
    vector<string> data = readData();
    vector<long long> joltages;

    int NUMBER_OF_BATTERIES = 12;

    for (int bank = 0; bank < data.size(); bank++)
    {
        cout << "Joltage Bank " << bank << ": " << data[bank] << ". ";

        string currentBank = data[bank];

        // char maxJolt = '0';
        // int maxJoltPos = 0;
        string joltageString = pickMaxSubsequence(currentBank, NUMBER_OF_BATTERIES);

        // for (int batt = 0; batt < currentBank.size(); batt++)
        // {
        //     if (currentBank[batt] > maxJolt && batt != currentBank.size() - 1)
        //     {
        //         maxJolt = currentBank[batt];
        //         maxJoltPos = batt;
        //     }
        // }

        // char secondMaxJolt = '0';
        // for (int batt = maxJoltPos + 1; batt < currentBank.size(); batt++)
        // {
        //     if (currentBank[batt] > secondMaxJolt)
        //     {
        //         secondMaxJolt = currentBank[batt];
        //     }
        // }

        // joltageString.push_back(maxJolt);
        // joltageString.push_back(secondMaxJolt);

        long long joltageVal = stoi(joltageString);
        joltages.push_back(joltageVal);

        cout << "Max Joltage = " << joltageString << endl;
    }

    long long sum = 0;
    for (long long val : joltages)
    {
        sum += val;
    }

    cout << "The sum of the joltages is: " << sum;
}