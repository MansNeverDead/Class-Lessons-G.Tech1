#include "ClassDiving/Game/Game.h"
#include <iostream>



int main() {
    Game& s1 = Game::getInstance();
    cout << "Adress: " << &s1 << endl;
    s1.GameLoop();

    return 0;
}

// "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\Llvm\x64\bin\clang.exe" -g ClassDiving.cpp ClassDiving\Game\Game.cpp ClassDiving\Map\Map.cpp ClassDiving\Utilities\Vector2.cpp ClassDiving\Utilities\Buffer.cpp -o ClassDiving.exe