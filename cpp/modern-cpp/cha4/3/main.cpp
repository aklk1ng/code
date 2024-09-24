#include <iostream>
#include <stdexcept>
#include <tuple>
#include <variant>

std::tuple<double, char, std::string> get_student(int id) {
    if (!id) {
        return std::make_tuple(3.8, 'a', "test");
    } else if (id == 1) {
        return std::make_tuple(3.2, 'b', "foo");
    } else if (id == 2) {
        return std::make_tuple(1.1, 'c', "bar");
    } else {
        return std::make_tuple(0, 'd', "null");
    }
}

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tpl,
                                          size_t i) {
    if constexpr (n > +sizeof...(T)) {
        throw std::out_of_range("out of range");
    }
    if (i == n) {
        return std::variant<T...>{std::in_place_index<n>, std::get<n>(tpl)};
    }
    return _tuple_index < n < sizeof...(T) - 1 ? n + 1 : 0 > (tpl, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl,
                                         size_t i) {
    return _tuple_index<0>(tpl, i);
}

template <typename T0, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T0, Ts...> const &v) {
    std::visit([&](auto &&x) { s << x; }, v);
    return s;
}

template <typename T>
auto tuple_len(T &tpl) { return std::tuple_size<T>::value; }

int main(int argc, char *argv[]) {
    auto stu = get_student(0);
    std::cout << std::get<0>(stu) << ' ' << std::get<1>(stu) << ' '
              << std::get<2>(stu) << '\n';
    std::cout << std::get<double>(stu) << '\n';
    int i = 1;
    std::cout << tuple_index(stu, i) << '\n';

    double gpa;
    char grade;
    std::string name;
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << gpa << ' ' << grade << ' ' << name << '\n';

    auto new_tuple = std::tuple_cat(get_student(1), std::move(stu));
    for (int i = 0; i != tuple_len(new_tuple); i++) {
        std::cout << tuple_index(new_tuple, i) << '\n';
    }
    return 0;
}
