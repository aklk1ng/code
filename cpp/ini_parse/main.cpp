#include "IniFile.h"

int main(int argc, char *argv[]) {
    IniFile ini;
    ini.load("./main.ini");
    ini.set("server", "timeout", 1000);
    ini.show();
    ini.save("./temp.ini");
    return 0;
}
