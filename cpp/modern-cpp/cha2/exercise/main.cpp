#include <map>
#include <string>
#include <iostream>

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F foo) {
    for (auto &&[key, val] : m) {
        val = foo(key);
    }
}

template <typename... T>
auto averge(T... t) {
    return (t + ...) / sizeof...(t);
}

int main() {
    std::map<std::string, long long int> m{{"a", 1}, {"b", 2}, {"c", 3}};
    update(m, [](std::string key) { return std::hash<std::string>{}(key); });
    for (auto &&[key, value] : m) {
        std::cout << key << ":" << value << std::endl;
    }

    std::cout << averge(1, 2.0, 3) << '\n';
}
