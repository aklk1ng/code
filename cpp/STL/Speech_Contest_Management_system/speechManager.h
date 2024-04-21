#pragma once
#include "speaker.h"
#include <algorithm>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

class SpeechManager {
public:
  SpeechManager();
  void show_Menu();
  void exitSystem();
  ~SpeechManager();
  void InitSpeech();
  void createSpeaker();
  void startSpeech();
  void speechDraw();
  void speechContest();
  void showScore();
  void saveRecord();
  void loadRecord();
  void showRecord();
  void clearRecord();

  std::vector<int> first_round;
  std::vector<int> first_victory;
  std::vector<int> top_three;
  std::map<int, Speaker> m_Speaker;
  std::map<int, std::vector<std::string>> m_Record;
  int Index;
  bool fileIsEmpty;
};
