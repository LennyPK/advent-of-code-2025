#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

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

    while (getline(inputFile, line, ','))
    {
        lines.push_back(line);
    }

    inputFile.close();

    cout << "Vector is " << lines.size() << " items long" << endl;

    return lines;
}

int main()
{
    vector<long long> invalidIds;
    vector<string> data = readData();

    for (int i = 0; i < data.size(); i++)
    {
        stringstream ss(data[i]);
        string a, b;
        getline(ss, a, '-');
        getline(ss, b, '-');

        long long startVal = stoll(a);
        long long endVal = stoll(b);

        cout << "Range: " << a << " to " << b << endl;

        for (long long n = startVal; n <= endVal; n++)
        {
            string s = to_string(n);
            int len = s.size();
            bool isValid = false;

            // Check chunk sizes from 1 to len
            for (int chunk = 1; chunk < len; chunk++)
            {
                if (len / chunk != 2 && PART_ONE)
                {
                    continue;
                }
                if (len % chunk != 0)
                {
                    // e.g. ABC ABC AB
                    continue;
                }

                bool same = true;
                string first = s.substr(0, chunk);

                for (int pos = chunk; pos < len; pos += chunk)
                {
                    if (s.substr(pos, chunk) != first)
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                {
                    isValid = true;
                    break;
                }
            }
            if (isValid)
            {
                cout << n << endl;
                invalidIds.push_back(n);
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < invalidIds.size(); i++)
    {
        sum += invalidIds[i];
    }

    cout << "The total for invalid IDs is: " << sum << endl;

    return 0;
}