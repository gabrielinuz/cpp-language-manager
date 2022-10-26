#!/bin/bash

## Compilo código objeto
g++ -Wall -std=c++11 -c ../src/IniLanguageManager.cpp -o IniLanguageManager.o -I../include

g++ -Wall -std=c++11 -c IniLanguageManagerUnitTest.cpp -o IniLanguageManagerUnitTest.o \
-I../include -I../include/vendors/catch

## Compilo el Binario
g++ -Wall -std=c++11 IniLanguageManager.o IniLanguageManagerUnitTest.o -o IniLanguageManagerUnitTest.bin

## Permisos de Ejecución para el binario
chmod +x ./IniLanguageManagerUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

## Ejecuto el binario:
./IniLanguageManagerUnitTest.bin