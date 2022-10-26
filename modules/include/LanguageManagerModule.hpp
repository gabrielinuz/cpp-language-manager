#ifndef LANGUAGEMANAGERMODULE_H
#define LANGUAGEMANAGERMODULE_H
#include <iostream>
#include <ILanguageManager.hpp>
#include <IniReader.hpp>
using namespace std;

/**
 * @brief 
 * @todo Crear una interfaz de LangReader y permitir el polimorfismo en la agregación.
 * 
 */
class LanguageManagerModule: ILanguageManager
{
    public:
        LanguageManagerModule();
        ~LanguageManagerModule();
        void setLanguageFilePath(string filePath);
        void setLanguage(string language);
        string translate(string key);
    private:
        IniReader* _iniReader;
        string _languageFilePath;
        string _language;
};

extern "C" LanguageManagerModule* getInstance();
#endif