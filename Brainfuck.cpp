// Brainfuck.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
using namespace std;

const string a = "++++++++++[>+++++++++<-]>+++++++.";//97
const string A = "++++++++++[>++++++<-]>+++++."; //65

 
int main()
{
    string s;
    string bf;// Contain final code

    ifstream ifs("bf.b", ifstream::in);
   // char c = ifs.get();

    while (ifs.good()) {
       
        s += ifs.get();
    }
    cout << s << endl;
    ifs.close();
                  
    
    int lc = 0;
    for (int i = 0; i < s.length()-1; i++) {
        int c = s[i];
        //string z = "+[><-]>."; +zero

        int d = c - lc;
       
        if (d > 0) {
            if (d == 0) {
                if (i == 0) {
                    bf += ".";
                    continue;
                }
            }
            else if (d <= 20) {
                bf += ">";
                for (int j = 0; j < d; j++) {
                    bf += "+";
                }
                bf += ".";
            }
            else {
                bf += "++++++++++[>";
                int dd = d / 10;
                int r = d - (dd * 10);
                for (int j = 0; j < dd; j++) {
                    bf += "+";

                }
                bf += "<-]>";

                for (int j = 0; j < r; j++) {
                    bf += "+";
                }
                bf += ".";

            }

         

        }
        else if (d < 0){
            if (d >= -20) {
                bf += ">";
                for (int j = 0; j < abs(d); j++) {
                    bf += "-";
                }
                bf += ".";
            }
            else {
                bf += "++++++++++[>";
                int dd = abs(d / 10);
                int r = abs(d) - (dd * 10);
                for (int j = 0; j < dd; j++) {
                    bf += "-";

                }
                bf += "<-]>";

                for (int j = 0; j < r; j++) {
                    bf += "-";
                }
                bf += ".";

            }

            
        }
        else {

            bf += ">.";


        }


        bf += "<";

        lc = s[i];


    }
    

    cout << bf << endl;
    
}
