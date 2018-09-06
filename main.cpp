#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main () {

        const char * str = "Hello";
        cout << "str :" << str << endl;


        char * copy = new char [6];
        for (int i=0; i < 6; i++) {
                copy[i] = str[i];
        }
        cout << "copy :" << (const char *)copy << endl;

        delete[] copy;
}

