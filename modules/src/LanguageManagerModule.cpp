#include <LanguageManagerModule.hpp>

LanguageManagerModule::LanguageManagerModule()
{
    _iniReader = new IniReader();
    _language = "default";
    _languageFilePath = "../lang/"+_language+".ini";
}

LanguageManagerModule::~LanguageManagerModule()
{
    delete _iniReader;
}

void LanguageManagerModule::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

void LanguageManagerModule::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "../lang/"+_language+".ini";
}

/**
 * @brief 
 * @todo Quitar la sección "GENERAL" del IniReader
 * @todo Basta de IniReader, hola LangReader! .lang
 * @param key 
 * @return string 
 */
string LanguageManagerModule::translate(string key) 
{
    _iniReader->open(_languageFilePath);
    return _iniReader->selectSection("GENERAL")->getValueOf(key);
}

LanguageManagerModule* getInstance() 
{
    return new LanguageManagerModule();
}
