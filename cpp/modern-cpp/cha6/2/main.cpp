#include <iostream>
#include <regex>
// std::regex base_regex("([a-z]+\\.txt");

int main(int argc, char *argv[]) {
    std::string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
    std::regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname : fnames) {
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
    }
    return 0;
}
