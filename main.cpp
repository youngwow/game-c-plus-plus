#include "Tools/Game.h"
//#include "Rules/Rules.h"
#include <windows.h>



int main(){
    SetConsoleOutputCP(CP_UTF8);
    Game<Rules<1>, Rules_second<30>> modelGame; // 6 врагов
    modelGame.StartGame();

    return 0;
}
