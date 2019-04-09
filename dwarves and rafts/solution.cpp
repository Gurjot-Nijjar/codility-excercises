// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;



// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;




int solution(int N, string &S, string &T) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int>> boat;
    vector<int> bar;
    boat.resize(N);
    bar.resize(4);
    char letter;
    int integer_;
    int letter_ = 0;
    stringstream barrels(S);
    stringstream dwarves(T);
    int d_init_counter = 0;
    for(int i = 0; i < N; ++i)
    {
        boat[i].resize(N);
    }
    
    
    while(!barrels.eof())
    {
        string tmp;
        barrels >> tmp;
        std::string::size_type sz;
        if(tmp.size() == 2)
        {
            integer_ = tmp[0] - '0' - 1;
            letter_ = tmp[1] - 'A';
            boat[integer_][letter_] = 2;
        }
        
        else if (tmp.size() == 3)
        {
            letter_ = tmp[2] - 'A';
            integer_ = std::stoi(tmp,&sz);
            boat[integer_][letter_] = 2;
        }
    }
    
    while(!dwarves.eof())
    {
        string tmp;
        dwarves >> tmp;
        std::string::size_type sz;
        if(tmp.size() == 2)
        {
            integer_ = tmp[0] - '0' - 1;
            letter_ = tmp[1] - 'A';
            boat[integer_][letter_] = 1;
           
        }
        
        else if (tmp.size() == 3)
        {
            letter_ = tmp[2] - 'A';
            integer_ = std::stoi(tmp,&sz);
            boat[integer_][letter_] = 1;
        }
    }
    for (int i = 0; i < boat.size() ; i++) 
    { 
        for (int j = 0; j < boat[i].size(); j++) 
        {
            if(boat[i][j] == 1)
            {
                d_init_counter++;
            }
        }
    }
    /*
     for (int i = 0; i < boat.size() ; i++) 
    { 
        for (int j = 0; j < boat[i].size(); j++) 
        {
            cout << boat[i][j] << " ";
        }
            cout << endl; 
    }
    */
    for(int q = 0; q < 4; q++)
    {
        bar[q] = 0;
    }
    
    for (int i = 0; i < N/2; i++)
    {
        for (int j = 0; j < N/2; j++)
        {
            if (boat[i][j] == 2)
            {
                bar[0]++;
            }
        }
    }
    
    for (int i = 0; i < N/2; i++)
    {
        for (int j = N/2 ; j < N; j++)
        {
            if (boat[i][j] == 2)
            {
                bar[1]++;
            }
        }
    }
    
    for (int i = N/2; i < N; i++)
    {
        for (int j = 0; j < N/2; j++)
        {
            if (boat[i][j] == 2)
            {
                bar[2]++;
            }
        }
    }
    
    for (int i = N/2; i < N; i++)
    {
        for (int j = N/2; j < N; j++)
        {
            if (boat[i][j] == 2)
            {
                bar[3]++;
            }
        }
    }
    int temp_value = 0;
    int check_value = 0;
    
    for(int u = 0; u < bar.size(); u++)
    {
        if(bar[u] > temp_value)
        {
            temp_value = bar[u];
            check_value = u;
        }
    }
    

    int counter = 0;
    
    
    if (check_value == 0)
    {
        for (int i = 0; i < N/2; i++)
        {
            for (int j = 0; j < N/2; j++)
            {
                if (boat[i][j] != 2)
                {
                    if(boat[i][j] == 1)
                    {
                        counter++;
                    }
                    
                    else if(boat[i][j] == 0)
                    {
                        boat[i][j] = 1;
                        counter++;
                    }
                }
            }
        }
    }
    
    else if (check_value == 1)
    {
        for (int i = 0; i < N/2; i++)
        {
            for (int j = N/2 ; j < N; j++)
            {
                if (boat[i][j] != 2)
                {
                    if(boat[i][j] == 1)
                    {
                        counter++;
                    }
                    
                    else if(boat[i][j] == 0)
                    {
                        boat[i][j] = 1;
                        counter++;

                    }
                }
            }
        }
    }
    
    else if (check_value == 2)
    {
        for (int i = N/2; i < N; i++)
        {
            for (int j = 0; j < N/2; j++)
            {
                if (boat[i][j] != 2)
                {
                    if(boat[i][j] == 1)
                    {
                        counter++;
                    }
                    
                    else if(boat[i][j] == 0)
                    {
                        boat[i][j] = 1;
                        counter++;
                    }
                }
            }
        }
    }
    
    else if (check_value == 3)
    {
        for (int i = N/2; i < N; i++)
        {
            for (int j = N/2; j < N; j++)
            {
                if (boat[i][j] != 2)
                {
                    if(boat[i][j] == 1)
                    {
                        counter++;
                    }
                    
                    else if(boat[i][j] == 0)
                    {
                        boat[i][j] = 1;
                        counter++;
                    }
                }
            }
        }
    }
    

    
       
    temp_value = counter;
       
    for (int i = 0; i < N/2; i++)
    {
        for (int j = 0; j < N/2; j++)
        {
            if (boat[i][j] != 2)
            {
                if (boat[i][j] == 1)
                {
                    temp_value--;
                }
                
                else if(boat[i][j] == 0 && temp_value != 0)
                {
                    boat[i][j] = 1;
                    temp_value--;
                }
            }
        }
    }
    
    temp_value = counter;

    for (int i = 0; i < N/2; i++)
    {
        for (int j = N/2 ; j < N; j++)
        {
            if (boat[i][j] != 2)
            {
                if (boat[i][j] == 1)
                {
                    temp_value--;
                }
                
                else if(boat[i][j] == 0 && temp_value != 0)
                {
                    boat[i][j] = 1;
                    temp_value--;
                }
            }
        }
    }
    
    temp_value = counter;

    for (int i = N/2; i < N; i++)
    {
        for (int j = 0; j < N/2; j++)
        {
            if (boat[i][j] != 2)
            {
                if (boat[i][j] == 1)
                {
                    temp_value--;
                }
                
                else if(boat[i][j] == 0 && temp_value != 0)
                {
                    boat[i][j] = 1;
                    temp_value--;
                }
            }
        }
    }
    
    temp_value = counter;

 
    for (int i = N/2; i < N; i++)
    {
        for (int j = N/2; j < N; j++)
        {
            if (boat[i][j] != 2)
            {
                if (boat[i][j] == 1)
                {
                    temp_value--;
                }
                
                else if(boat[i][j] == 0 && temp_value != 0)
                {
                    boat[i][j] = 1;
                    temp_value--;
                }
            }
        }
    }
    
    int d_counter = 0;
    
    
    for (int i = 0; i < boat.size() ; i++) 
    { 
        for (int j = 0; j < boat[i].size(); j++) 
        {
            if(boat[i][j] == 1)
            {
                d_counter++;
            }
        }
    }
    
    int answer = d_counter - d_init_counter;
    
    return answer;
}

