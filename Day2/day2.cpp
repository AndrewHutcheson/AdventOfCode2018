#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("input.txt");
    string currentLine;    

    //part 1
    int totalDoubleCharacters = 0;
    int totalTripleCharacters = 0;
    map <char, int> alphabet;
    
    while (getline(myfile, currentLine))
    {
        alphabet.clear();
        for (int i = 0; i < currentLine.size(); i++)
        {
            if(alphabet.find(currentLine[i]) == alphabet.end())
                alphabet[currentLine[i]] = 1;
            else
                alphabet[currentLine[i]]++;
            //cout << currentLine[i] << ":" << alphabet[currentLine[i]] << endl;
        }
        //cout<<endl;
        for (const auto& [key, value] : alphabet)
        {
            if(value == 2)
            {
                totalDoubleCharacters++;
                break;
            }
        }
        for (const auto& [key, value] : alphabet)
        {
            if(value == 3)
            {
                totalTripleCharacters++;
                break;
            }
        }
    }

    cout << "part 1 " << totalDoubleCharacters * totalTripleCharacters << endl;

    map <int,string> lines;
    map <int,string> linesCopy;
    int counter = 0;
    int matchOffCounter = 0;

    myfile.clear();
    myfile.seekg(0);
    while (getline(myfile, currentLine))
    {
        lines[counter] = currentLine;
        counter++;
    }
    
    linesCopy = lines;

    for (const auto& [index, line] : lines)
    {
        for (const auto& [index2, line2] : linesCopy)
        {
            if(index != index2)
            {
                matchOffCounter = 0;
                for(int i = 0; i < line.size(); i++)
                {
                    if(line[i] != line2[i]) //they lines are known to be same size
                        matchOffCounter++;
                }
                if(matchOffCounter == 1)
                {
                    cout << "part 2 is " << line << " and "<< line2 << endl;
                }
            }
        }
    }
}