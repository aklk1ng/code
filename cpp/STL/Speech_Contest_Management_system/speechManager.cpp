#include "speechManager.h"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <map>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

SpeechManager::SpeechManager() {
  this->InitSpeech();
  this->createSpeaker();
  this->loadRecord();
}

void SpeechManager::show_Menu() {
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "-------       Welcome !!!    ---------" << std::endl;
  std::cout << "----    1.begin the speech match   ---" << std::endl;
  std::cout << "----    2.check the match record   ---" << std::endl;
  std::cout << "----    3.empty the game record    ---" << std::endl;
  std::cout << "--------       0.exit        ---------" << std::endl;
  std::cout << "--------------------------------------" << std::endl;
}

void SpeechManager::createSpeaker() {
  std::string nameSeed = "ABCDEFGHIJKL";
  for (int i = 0; i < nameSeed.size(); i++) {
    std::string name = "";
    name += nameSeed[i];

    Speaker sp;
    sp.m_name = name;
    for (int j = 0; j < 2; j++) {
      sp.m_score[j] = 0;
    }

    this->first_round.push_back(i + 10001);
    this->m_Speaker.insert(std::make_pair(i + 10001, sp));
  }
}

void SpeechManager::InitSpeech() {
  this->first_round.clear();
  this->first_victory.clear();
  this->top_three.clear();
  this->m_Speaker.clear();

  this->Index = 1;
  this->m_Record.clear();
}

void SpeechManager::startSpeech() {
  this->speechDraw();
  this->speechContest();
  this->showScore();
  this->Index++;
  this->speechDraw();
  this->speechContest();
  this->showScore();
  this->saveRecord();
  std::cout << "------The match is over!------" << std::endl;

  this->InitSpeech();
  this->createSpeaker();
  this->loadRecord();
}

void SpeechManager::speechDraw() {
  std::cout << "The " << this->Index << " round match draws!" << std::endl;
  std::cout << "---------------------------" << std::endl;
  std::cout << "order of speeches after draw:" << std::endl;

  std::random_device rd;
  std::mt19937 gen(rd());
  if (this->Index == 1) {
    shuffle(first_round.begin(), first_round.end(), gen);
    for (auto it : first_round) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
  } else {
    shuffle(first_victory.begin(), first_victory.end(), gen);
    for (auto it : first_victory) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "---------------------------" << std::endl;
  system("pause");
  std::cout << std::endl;
}

void SpeechManager::speechContest() {
  std::cout << "------The" << this->Index << "round match starts!-------"
            << std::endl;

  std::multimap<double, int, std::greater<double>> groupScore;
  int num = 0;

  std::vector<int> v_Src;
  if (this->Index == 1) {
    v_Src = first_round;
  } else
    v_Src = first_victory;

  for (auto it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    std::deque<double> d;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f; // 600 - 1000
      /* cout << score << " "; */
      d.push_back(score);
    }
    sort(d.begin(), d.end(), std::greater<double>());
    d.pop_back();                                      // the min
    d.pop_front();                                     // the max
    double sum = accumulate(d.begin(), d.end(), 0.0f); // total
    double avg = sum / (double)(d.size());             // averge

    this->m_Speaker[*it].m_score[this->Index - 1] = avg;
    groupScore.insert(std::make_pair(avg, *it));
    if (num % 6 == 0) {
      std::cout << "The " << num / 6 << " group:" << std::endl;
      for (auto it : groupScore) {
        std::cout << "Speaker:" << it.second
                  << " Name:" << this->m_Speaker[it.second].m_name << " Score:"
                  << this->m_Speaker[it.second].m_score[this->Index - 1]
                  << std::endl;
      }
      int count = 0;
      for (auto it : groupScore) {
        if (this->Index == 1) {
          first_victory.push_back(it.second);
        } else
          top_three.push_back(it.second);
      }
      groupScore.clear();
      std::cout << std::endl;
    }
  }
  std::cout << "------The " << this->Index << " match is over!------"
            << std::endl;
}

void SpeechManager::showScore() {
  std::cout << "------The " << this->Index << " round advancement speaker------"
            << std::endl;
  std::vector<int> v;
  if (this->Index == 1) {
    v = first_victory;
  } else
    v = top_three;
  for (auto it : v) {
    std::cout << "Speaker:" << it << " Name:" << this->m_Speaker[it].m_name
              << " Score:" << this->m_Speaker[it].m_score[this->Index - 1]
              << std::endl;
  }
  std::cout << std::endl;
}

void SpeechManager::saveRecord() {
  std::ofstream ofs;
  ofs.open("speech.csv", std::ios::out | std::ios::app);
  for (auto it : top_three) {
    ofs << it << "," << this->m_Speaker[it].m_score[1] << ",";
  }
  ofs << std::endl;
  ofs.close();
  this->fileIsEmpty = false;
  std::cout << "------Record over!------";
}

void SpeechManager::loadRecord() {
  std::ifstream ifs("speech.csv", std::ios::in);
  if (!ifs.is_open()) {
    this->fileIsEmpty = true;
    std::cout << "The file isn't exist!" << std::endl;
    ifs.close();
    return;
  }
  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    std::cout << "The file is empty!" << std::endl;
    this->fileIsEmpty = true;
    ifs.close();
    return;
  }
  this->fileIsEmpty = false;
  ifs.putback(ch);
  std::string data;
  int index = 0;
  while (ifs >> data) {
    /* cout << data << endl; */
    std::vector<std::string> v;
    int pos = -1;
    int start = 0;
    while (1) {
      pos = data.find(",", start);
      if (pos == -1) {
        break;
      }
      std::string temp = data.substr(start, pos - start);
      v.push_back(temp);
      start = pos + 1;
    }
    this->m_Record.insert(std::make_pair(index, v));
    index++;
  }
  ifs.close();
}

void SpeechManager::showRecord() {
  if (this->fileIsEmpty) {
    std::cout << "The file isn't exist!" << std::endl;
  } else {
    for (int i = 0; i < this->m_Record.size(); i++) {
      std::cout << "The " << i + 1 << " match:" << std::endl
                << "Champion:" << this->m_Record[i][0]
                << " Score:" << this->m_Record[i][1] << std::endl
                << "runner up:" << this->m_Record[i][2]
                << " Score:" << this->m_Record[i][3] << std::endl
                << "runner-up:" << this->m_Record[i][4]
                << " Score:" << this->m_Record[i][5] << std::endl;
    }
  }
}

void SpeechManager::clearRecord() {
  std::cout << "Are you sure?" << std::endl;
  std::cout << "1.yes" << std::endl;
  std::cout << "2.no" << std::endl;
  int select = 0;
  std::cin >> select;
  if (select == 1) {
    std::ofstream ofs("speech.csv", std::ios::trunc);
    ofs.clear();
    this->InitSpeech();
    this->createSpeaker();
    this->loadRecord();
    std::cout << "clear over!" << std::endl;
  }
}

void SpeechManager::exitSystem() {
  std::cout << "See you again!" << std::endl;
  exit(0);
}

SpeechManager::~SpeechManager() {}
