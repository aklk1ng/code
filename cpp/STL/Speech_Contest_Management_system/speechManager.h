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
using namespace std;

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

  vector<int> first_round;
  vector<int> first_victory;
  vector<int> top_three;
  map<int, Speaker> m_Speaker;
  map<int, vector<string>> m_Record;
  int Index;
  bool fileIsEmpty;
};
