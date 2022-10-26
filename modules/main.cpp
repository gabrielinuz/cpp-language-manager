#include <iostream>
#include <ILanguageManager.hpp>
#include <ModuleLoader.hpp>

using namespace std;
import lmModule = "./lib/LanguageManagerModule";

int main()
{
    ILanguageManager* lm = lmModule.getInstanceAs<ILanguageManager*>();
    // lm->setLanguageFilePath("./lang/esAR.ini");
    lm->setLanguage("esAR");
    cout << lm->translate("HELLO_WORLD") << endl;
    
    delete lm;
    return EXIT_SUCCESS;
}