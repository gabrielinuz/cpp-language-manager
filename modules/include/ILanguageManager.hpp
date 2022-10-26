#ifndef I_LANGUAGE_MANAGER_HPP
#define I_LANGUAGE_MANAGER_HPP

#include <iostream>
#include <string>
using namespace std;

class ILanguageManager
{
    public:
        // virtual void setLanguageFilePath(string filePath) = 0;
        virtual void setLanguage(string language) = 0;
        virtual string translate(string key) = 0;
};

#endif // I_LANGUAGE_MANAGER_HPP