#pragma once
#include <map>
#include <string>

class Value {
public:
  Value();
  Value(bool value);
  Value(int value);
  Value(double value);
  Value(const char *value);
  Value(const std::string &value);

  Value &operator=(bool value);
  Value &operator=(int value);
  Value &operator=(double value);
  Value &operator=(const char *value);
  Value &operator=(const std::string &value);

  operator bool();
  operator int();
  operator double();
  operator std::string();

private:
  std::string m_value;
};

typedef std::map<std::string, Value> Section;

class IniFile {
public:
  IniFile();
  bool load(const std::string &filename);
  void show();
  Value &get(const std::string &section, const std::string &key);
  void set(const std::string &section, const std::string &key,
           const Value &value);
  bool has(const std::string &section, const std::string &key);
  bool has(const std::string &section);
  bool save(const std::string &filename);
  std::string str();

  void remove(const std::string &section, const std::string &key);
  void remove(const std::string &section);
  void clear();

  Section &operator[](const std::string &section) {
    return m_sections[section];
  }

private:
  std::string m_filename;
  std::map<std::string, Section> m_sections;

  std::string trim(std::string s);
};
