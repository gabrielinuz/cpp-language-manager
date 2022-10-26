#include "../include/IniReader.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    IniReader* ir = new IniReader();
    ir->open("./resources/configuration.ini");
    string greet = ir->selectSection("GENERAL")->getValueOf("greet");
	string greet2 = ir->selectSection("GENERAL")->getValueOf("greet2");
	string greet3 = ir->selectSection("GENERAL")->getValueOf("greet3");
    cout << greet << endl;
    cout << greet2 << endl;
    cout << greet3 << endl;
    return 0;
}
