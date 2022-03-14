// Brainfucker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include  <vector>
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
    //cout << s << endl;
    ifs.close();

    vector<char>b(SIZE_BUFFER);
    int ptr = 0;
    int memo_ptr = 0;
    for (int i = 0; i < s.length(); i++) {
        //cout << s[i] << endl;
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
            if(b[ptr] == -1){
                b[ptr] = 255;
            }
        }
        else if (s[i] == '+') {
            ++b[ptr];
            if (b[ptr] == 256) {
                b[ptr] = 0;
            }
        }
        else if (s[i] == '[') {
            memo_ptr = i;
        }
        else if (s[i] == ']') {
            if(b[ptr] > 0)
                i = memo_ptr;
            
        }
        else if (s[i] == '.') {
            cout <<b[ptr];
        }
        else if (s[i] == ',') {
            cin >> b[ptr];
        }


    }

    
}

