#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../include/ILanguageManager.hpp"
#include "../include/IniLanguageManager.hpp"
#include <catch.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

TEST_CASE( "IniLanguageManager create instance", "[IniLanguageManager new]" ) 
{
    // Arrange
    ILanguageManager* lm;

    // Act
    lm = new IniLanguageManager();
    bool isILanguageManager = ( dynamic_cast<ILanguageManager*> (lm) != nullptr );

    // Assert
    REQUIRE( isILanguageManager == true );
}

TEST_CASE( "Correct translation into default language", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = new IniLanguageManager();
 
    // Act
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into Spanish", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = new IniLanguageManager();
 
    // Act
    lm->setLanguage("esAR");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into English", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = new IniLanguageManager();
 
    // Act
    lm->setLanguage("enUS");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "Hello World!" );
}

TEST_CASE( "Correct translation into French", "[IniLanguageManager getTranslation]" )
{
    // Arrange
    ILanguageManager* lm = new IniLanguageManager();
 
    // Act
    lm->setLanguage("frFR");
    string translation = lm.translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Salut monde!" );
}