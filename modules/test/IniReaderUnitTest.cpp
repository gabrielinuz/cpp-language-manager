#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../include/vendors/catch/catch.hpp"
#include "../include/IniReader.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**@test ${1:IniReader create instance
 *
 */
TEST_CASE( "Correct getValueOf of INI file", "[IniReader getValueOf]" ) 
{
    // Arrange
    /**@todo refactorizar IniReader para que soporte espacios*/
    IniReader* ir = new IniReader();

    // Act
   	ir->open("./resources/configuration.ini");
	string greet = ir->selectSection("GENERAL")->getValueOf("greet");
	string greet2 = ir->selectSection("GENERAL")->getValueOf("greet2");
	string greet3 = ir->selectSection("GENERAL")->getValueOf("greet3");

    // Assert
    /**@todo refactorizar IniReader para que soporte espacios*/
    REQUIRE( greet == "¡Hola Ñoños!" );
    REQUIRE( greet2 == "¡Hola Mundo Cruel?" );
    REQUIRE( greet3 == "¡Hola Amigos &&&&" );
}