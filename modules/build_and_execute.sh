#!/bin/bash
##Compilo las librerías
g++ -shared -Wall -std=c++11 -I./include/ ./src/IniReader.cpp -o IniReader.o
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/LanguageManagerModule.cpp -o ./lib/LanguageManagerModule.so
g++ -shared -Wall -std=c++11 -I./include/ main.cpp -o main.o

## Compilo el Binario
g++ -Wall -std=c++11 -ldl -I./include -I./include/vendors/cppset IniReader.o main.o -o ./app.bin 

## Borro código objeto
rm *.o;

## Permisos de Ejecución para el binario
chmod +x ./app.bin

## Ejecuto el binario:
./app.bin