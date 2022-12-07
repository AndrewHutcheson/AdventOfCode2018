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
    map <string, int> grid;
    int xpos;
    int ypos;
    int width;
    int height;
    string location;
    int claimCounter = 0;

    while (getline(myfile, currentLine))
    {
        xpos = stoi(currentLine.substr(currentLine.find('@')+1,currentLine.find(',')));
        ypos = stoi(currentLine.substr(currentLine.find(',')+1,currentLine.find(':')));
        //cout<<xpos<<" "<<ypos<<endl;
        width = stoi(currentLine.substr(currentLine.find(':')+1,currentLine.find('x')));
        height = stoi(currentLine.substr(currentLine.find('x')+1));
        //cout<<width<<" "<<height<<endl;

        for(int x=xpos; x < xpos+width; x++)
        {
            for(int y=ypos; y < ypos+height; y++)
            {
                location = to_string(x) + " " + to_string(y);
                //cout << location << endl;

                if((grid.find(location) == grid.end()))
                    grid[location] = 1;
                else
                    grid[location] = grid[location] + 1;
            }
        }
    }

    for (const auto& [key, value] : grid)
    {
        if(value > 1)
        {
            //cout << key << " " << value << endl;
            claimCounter++;
        }
    }
    cout << "part 1" << claimCounter << endl;
}