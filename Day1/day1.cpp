#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("input.txt");
    string currentLine;    
    vector <double> usedFrequencies;


    //part 1
    double sum = 0.0;

    while (getline(myfile, currentLine))
    {
        sum += stod(currentLine);
    }
    cout << "part 1 " << sum << endl;

    //part 2
    sum = 0.0;
    usedFrequencies.push_back(sum);

    while (true)
    {
        while (getline(myfile, currentLine))
        {
            sum += stod(currentLine);
            //if (count(usedFrequencies.begin(), usedFrequencies.end(), sum))
            if (find(usedFrequencies.begin(), usedFrequencies.end(), sum) != usedFrequencies.end())
            {
                cout << "part 2 " << sum << endl;
                return 0;
            }
            usedFrequencies.push_back(sum);
        }
        myfile.clear();
        myfile.seekg(0);
    }
}