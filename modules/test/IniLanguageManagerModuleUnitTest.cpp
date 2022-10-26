#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <ILanguageManager.hpp>
#include <catch.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**@todo probar si esto es posible, sino va dentro del test:*/
import languageManagerModule = "../lib/IniLanguageManager";
 
TEST_CASE( "IniLanguageManager create instance", "[IniLanguageManager new]" ) 
{
    // Arrange
    ILanguageManager* lm = languageManagerModule.getInstanceAs<ILanguageManager*>();
    
    // Act
    bool isILanguageManager = ( dynamic_cast<ILanguageManager*> (lm) != nullptr );

    // Assert
    REQUIRE( isILanguageManager == true );
}

TEST_CASE( "Correct translation into default language", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = languageManagerModule.getInstanceAs<ILanguageManager*>();
 
    // Act
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into Spanish", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = languageManagerModule.getInstanceAs<ILanguageManager*>();
 
    // Act
    lm->setLanguage("esAR");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into English", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = languageManagerModule.getInstanceAs<ILanguageManager*>();
 
    // Act
    lm->setLanguage("enUS");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "Hello World!" );
}

TEST_CASE( "Correct translation into French", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = languageManagerModule.getInstanceAs<ILanguageManager*>();
 
    // Act
    lm->setLanguage("frFR");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Salut monde!" );
}