#!/bin/bash

## Compilo código objeto
##LangReader:
g++ -Wall -std=c++11 -c ../src/LangReader.cpp -o LangReader.o -I../include
g++ -Wall -std=c++11 -c LangReaderUnitTest.cpp -o LangReaderUnitTest.o \
-I../include -I../include/vendors/catch

##LanguageManager:
# g++ -Wall -std=c++11 -c ../src/LanguageManager.cpp -o LanguageManager.o -I../include
# g++ -Wall -std=c++11 -c LanguageManagerUnitTest.cpp -o LanguageManagerUnitTest.o \
# -I../include -I../include/vendors/catch

## Compilo el Binario
##LangReader:
g++ -Wall -std=c++11 LangReader.o LangReaderUnitTest.o -o LangReaderUnitTest.bin

##LanguageManager:
# g++ -Wall -std=c++11 LanguageManager.o LanguageManagerUnitTest.o -o LanguageManagerUnitTest.bin

## Permisos de Ejecución para el binario
##LangReader:
chmod +x ./LangReaderUnitTest.bin

# ##LanguageManager:
# chmod +x ./LanguageManagerUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

## Ejecuto el binario:
##LangReader:
./LangReaderUnitTest.bin

# ##LanguageManager:
# ./LanguageManagerUnitTest.bin