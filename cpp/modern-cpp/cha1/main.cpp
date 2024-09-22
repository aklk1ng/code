#include "foo.h"
#include <iostream>
#include <functional>

int main(int argc, char *argv[]) {
    [out = std::ref(std::cout << "Result from C codde: " << add(1, 2))]() {
        out.get() << ".\n";
    }();
    return 0;
}
