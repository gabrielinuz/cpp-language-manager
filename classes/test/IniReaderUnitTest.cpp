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

    // Assert
    /**@todo refactorizar IniReader para que soporte espacios*/
    REQUIRE( greet == "¡Hola_Ñoños!" );
}