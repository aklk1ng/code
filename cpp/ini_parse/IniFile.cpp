#include "IniFile.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Value::Value() {}

Value::Value(bool value) { *this = value; }

Value::Value(int value) { *this = value; }

Value::Value(double value) { *this = value; }

Value::Value(const char *value) { *this = value; }

Value::Value(const std::string &value) { *this = value; }

Value &Value::operator=(bool value) {
    m_value = value ? "true" : "false";
    return *this;
}

Value &Value::operator=(int value) {

    std::stringstream ss;
    ss << value;
    m_value = ss.str();
    return *this;
}

Value &Value::operator=(double value) {
    std::stringstream ss;
    ss << value;
    m_value = ss.str();
    return *this;
}

Value &Value::operator=(const char *value) {
    m_value = value;
    return *this;
}

Value &Value::operator=(const std::string &value) {
    m_value = value;
    return *this;
}

Value::operator bool() { return m_value == "true"; }

Value::operator int() { return std::atoi(m_value.c_str()); }

Value::operator double() { return std::atof(m_value.c_str()); }

Value::operator std::string() { return m_value; }

IniFile::IniFile() {}

bool IniFile::load(const std::string &filename) {
    std::ifstream fin(filename);
    if (fin.fail()) {
        return false;
    }

    std::string line;
    std::string section;
    while (std::getline(fin, line)) {
        line = trim(line);
        if (line == "") {
            continue;
        } else if (line[0] == '[') {
            int pos = line.find_first_of(']');
            section = line.substr(1, pos - 1);
            section = trim(section);
            m_sections[section] = Section();
        } else {
            int pos = line.find_first_of('=');
            std::string key = line.substr(0, pos);
            key = trim(key);
            std::string value = line.substr(pos + 1, line.length() - pos);
            value = trim(value);
            m_sections[section][key] = value;
        }
    }
    fin.close();
    return true;
}

std::string IniFile::str() {
    std::stringstream ss;
    for (auto it = m_sections.begin(); it != m_sections.end(); it++) {
        ss << '[' << it->first << ']' << std::endl;
        for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
            ss << iter->first << " = " << std::string(iter->second)
               << std::endl;
        }
        ss << std::endl;
    }
    return ss.str();
}

void IniFile::show() { std::cout << str(); }

std::string IniFile::trim(std::string s) {
    if (s.empty())
        return s;
    s.erase(0, s.find_first_not_of(" \n\r"));
    s.erase(s.find_last_not_of(" \n\r") + 1);
    return s;
}

Value &IniFile::get(const std::string &section, const std::string &key) {
    return m_sections[section][key];
}

void IniFile::set(const std::string &section, const std::string &key,
                  const Value &value) {
    m_sections[section][key] = value;
}

bool IniFile::has(const std::string &section, const std::string &key) {
    std::map<std::string, Section>::const_iterator it =
        m_sections.find(section);
    if (it != m_sections.end()) {
        return it->second.find(key) != it->second.end();
    }
    return false;
}

bool IniFile::has(const std::string &section) {
    return (m_sections.find(section) != m_sections.end());
}

bool IniFile::save(const std::string &filename) {
    std::ofstream fout(filename);
    if (fout.fail()) {
        return false;
    }
    fout << str();
    fout.close();
    return true;
}

void IniFile::remove(const std::string &section, const std::string &key) {
    std::map<std::string, Section>::iterator it = m_sections.find(section);
    if (it != m_sections.end()) {
        it->second.erase(key);
    }
}

void IniFile::remove(const std::string &section) { m_sections.erase(section); }

void IniFile::clear() { m_sections.clear(); }
