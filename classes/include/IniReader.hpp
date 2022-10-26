/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef INIREADER_HPP
#define INIREADER_HPP

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class IniReader
{
    public:
        IniReader();
        virtual ~IniReader();
        bool open( std::string fileName);
        IniReader* selectSection( std::string section );
        std::string getValueOf( std::string key );
        void close();


    private:
        ifstream _fileInput;
        std::string  _dataSection ;
        std::string _BufferData ;

        void ReadFile();
};

#endif // INIREADER_HPP
