// Brainfucker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include  <vector>
#include <deque >
using namespace std;

#define SIZE_BUFFER 1024


int main()
{
    string s;
    string bf;// Contain final code

    ifstream ifs("bfr.b", ifstream::in);

    while (ifs.good()) {

        s += ifs.get();
    }
   
    ifs.close();

    deque<int> d, pd;
    vector<int>b(SIZE_BUFFER);
    int ptr = 0;
    int memo_ptr = 0;
    for (int i = 0; i < s.length(); i++) {
       
        if (s[i] == '>') {
            if (ptr < SIZE_BUFFER)
                ++ptr;
            
        }
        else if (s[i] == '<') {
            if(ptr > 0)
                --ptr;
        }
        else if (s[i] == '-') {
            --b[ptr];
            
        }
        else if (s[i] == '+') {
            ++b[ptr];
            
        }
        else if (s[i] == '[') {
            if (b[ptr] == 0) {
                
                for (int j = i+1; j < s.length(); j++) {
                    if (s[j] == '[') {
                        pd.push_front(j);
                    }
                    else if (s[j] == ']') {
                        if (pd.empty()) {
                            i = j;
                            break;
                        }
                        pd.pop_front();
                    }
                                      
                }
            }
            else {
               
                d.push_front(i);
                
            }
          
            
        }
        else if (s[i] == ']') {
            if (b[ptr] > 0) {
                i = d.front();
              
            }
            else {
                d.pop_front();
               
            }
            
        }
        else if (s[i] == '.') {
            cout << (unsigned char)b[ptr];
        }
        else if (s[i] == ',') {
           
            char buff[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
            cin.getline(buff, 10);
            bool num = true;
            for (int j = 0; j < 10 && buff[j] != 0; ++j) {
                if(! (buff[j] >= '0' && buff[j] <= '9')) {
                    num = false;
                    break;
                }
                
                
            }

            if (num) {
                int  n = 0;
                for (int j = 0; j < 10 && buff[j] != 0; ++j) {
                    n += buff[j] - '0';
                    n *= 10;
                    
                }
                b[ptr] = n;
            }
            else {
                b[ptr] = (int)buff[0];
            }

        }
        else if (s[i] == 't') {
            for (int j = 0; j < 10; j++) {
                cout << (int)b[j] << " - ";
            }cout << endl;
            cout << ptr << endl;
        }
        

    }

    
}

