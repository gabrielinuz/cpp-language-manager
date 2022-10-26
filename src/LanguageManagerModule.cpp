/**
 * @file LanguageManagerModule.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <LanguageManagerModule.hpp>

LanguageManagerModule::LanguageManagerModule()
{
    _language = "default";
    _languageFilePath = "./lang/"+_language+".lang";
}

LanguageManagerModule::~LanguageManagerModule()
{
    delete _langReader;
}

void LanguageManagerModule::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

void LanguageManagerModule::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief 
 * @param key 
 * @return string 
 */
string LanguageManagerModule::translate(string key) 
{
    string result;
    _langReader = new LangReader();
    _langReader->open(_languageFilePath);
    result =_langReader->getValueOf(key);
    if(result == "")
    {
        result = "NULL TRANSLATION OF KEY: " + key + "!";
    } 
    
    return result;
}

LanguageManagerModule* getInstance() 
{
    return new LanguageManagerModule();
}
