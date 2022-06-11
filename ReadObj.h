#pragma once

#include"OBJMesh.h"
#include <iostream>
#include <fstream>
#include "string"
point parseVertices(vector<string> seglist);
vector<int> parseFaces(vector<string> seglist);
OBJMesh ReadObj(string str)
{
    OBJMesh Om;
    string line;
    ifstream myfile(str);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //cout << line << '\n';
            if (line != "") {
                std::stringstream test(line);
                std::string segment;
                std::vector<std::string> seglist;

                while (std::getline(test, segment, ' '))
                {
                    seglist.push_back(segment);
                }
                if (seglist[0] == "f")
                {   
                        Om.faces.push_back(parseFaces(seglist));
                }

                if (seglist[0] == "v")
                {
                    Om.points.push_back(parseVertices(seglist));
                }
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    return Om;
}

vector<int> parseFaces(vector<string> seglist)
{
    seglist.erase(seglist.begin());
    vector<int> face;

    for (string word : seglist)
    {
        std::stringstream test1(word);
        string number;

        int count = 1;
        while (std::getline(test1, number, '/') && count < 2)
        {
            if (count == 1)
            {
                face.push_back(stoi(number));
            }
            count++;
        }
    }
    return face;
}


 point parseVertices(vector<string> seglist)
{
     seglist.erase(seglist.begin());
     point pt;

     for (string word : seglist)
     {
         std::stringstream test1(word);
         if (word!="")
         pt.X.push_back(stoi(word));
     }

     return pt;
}