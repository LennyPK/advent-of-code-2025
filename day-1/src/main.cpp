#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

enum Direction
{
    LEFT,
    RIGHT
};

struct Move
{
    Direction direction;
    int times;
};

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

vector<Move> parseMoves(vector<string> data)
{
    vector<Move> moves;

    for (int i = 0; i < data.size(); i++)
    {
        string move = data[i];
        char direction = move[0];
        int times = stoi(move.substr(1));

        if (direction == 'L')
        {
            Move move;
            move.direction = LEFT;
            move.times = times;
            moves.push_back(move);
        }
        else if (direction == 'R')
        {
            Move move;
            move.direction = RIGHT;
            move.times = times;
            moves.push_back(move);
        }
    }

    return moves;
}

int getInit()
{
    int initialPos;
    cout << "What is the dial's starting position? ";
    cin >> initialPos;

    return initialPos;
}

int main()
{
    vector<string> data = readData();

    vector<Move> moves = parseMoves(data);

    int initialPos = getInit();

    int zeroCount_partOne = 0;
    int zeroCount_partTwo = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        Move move = moves[i];
        int times = move.times;
        if (move.direction == LEFT)
        {
            while (times)
            {
                initialPos--;
                times--;
                if (initialPos == -1)
                {
                    initialPos = 99;
                }
                if (initialPos == 0)
                {
                    zeroCount_partTwo++;
                }
            }
        }
        else if (move.direction == RIGHT)
        {
            while (times)
            {
                initialPos++;
                times--;
                if (initialPos == 100)
                {
                    initialPos = 0;
                }
                if (initialPos == 0)
                {
                    zeroCount_partTwo++;
                }
            }
        }
        //
        if (initialPos == 0)
        {
            zeroCount_partOne++;
        }
    }

    cout << "The dial stopped at zero " << zeroCount_partOne << " times." << endl;
    cout << "The dial passed zero " << zeroCount_partTwo << " times." << endl;

    return 0;
}