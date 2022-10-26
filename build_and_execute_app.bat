::Compilo las librerías
g++ -Wall -std=c++11 -I./include/ ./src/IniReader.cpp -o IniReader.o
g++ -shared -Wall -std=c++11 -I./include/ ./src/LanguageManagerModule.cpp -o ./lib/LanguageManagerModule.so
g++ -Wall -std=c++11 -I./include/ main.cpp -o main.o

:: Compilo el Binario
g++ -Wall -std=c++11 -ldl -I./include -I./include/vendors/cppset IniReader.o main.o -o ./app.bin 

::Borrar .o
DEL .\*.o

::Ejecuto el binario:
app.exe