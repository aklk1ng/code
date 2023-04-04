#include "speechManager.h"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <map>
#include <numeric>
#include <system_error>
#include <utility>
#include <vector>

SpeechManager::SpeechManager() {
  this->InitSpeech();
  this->createSpeaker();
  this->loadRecord();
}

void SpeechManager::show_Menu() {
  cout << "--------------------------------------" << endl;
  cout << "-------       Welcome !!!    ---------" << endl;
  cout << "----    1.begin the speech match   ---" << endl;
  cout << "----    2.check the match record   ---" << endl;
  cout << "----    3.empty the game record    ---" << endl;
  cout << "--------       0.exit        ---------" << endl;
  cout << "--------------------------------------" << endl;
}

void SpeechManager::createSpeaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (int i = 0; i < nameSeed.size(); i++) {
    string name = "";
    name += nameSeed[i];

    Speaker sp;
    sp.m_name = name;
    for (int j = 0; j < 2; j++) {
      sp.m_score[j] = 0;
    }

    this->first_round.push_back(i + 10001);
    this->m_Speaker.insert(make_pair(i + 10001, sp));
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
  cout << "------The match is over!------" << endl;

  this->InitSpeech();
  this->createSpeaker();
  this->loadRecord();
}

void SpeechManager::speechDraw() {
  cout << "The " << this->Index << " round match draws!" << endl;
  cout << "---------------------------" << endl;
  cout << "order of speeches after draw:" << endl;

  if (this->Index == 1) {
    random_shuffle(first_round.begin(), first_round.end());
    for (vector<int>::iterator it = first_round.begin(); it != first_round.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  } else {
    random_shuffle(first_victory.begin(), first_victory.end());
    for (vector<int>::iterator it = first_victory.begin(); it != first_victory.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
  cout << "---------------------------" << endl;
  system("pause");
  cout << endl;
}

void SpeechManager::speechContest() {
  cout << "------The" << this->Index << "round match starts!-------" << endl;

  multimap<double, int, greater<double>> groupScore;
  int num = 0;

  vector<int> v_Src;
  if (this->Index == 1) {
    v_Src = first_round;
  } else
    v_Src = first_victory;

  for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    deque<double> d;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f; // 600 - 1000
      /* cout << score << " "; */
      d.push_back(score);
    }
    sort(d.begin(), d.end(), greater<double>());
    d.pop_back();                                      // the min
    d.pop_front();                                     // the max
    double sum = accumulate(d.begin(), d.end(), 0.0f); // total
    double avg = sum / (double)(d.size());             // averge
    /* cout << "Speaker:" << *it << " Name:" << this->m_Speaker[*it].m_name
     * << " Averge:" << avg << endl; */

    this->m_Speaker[*it].m_score[this->Index - 1] = avg;
    groupScore.insert(make_pair(avg, *it));
    if (num % 6 == 0) {
      cout << "The " << num / 6 << " group:" << endl;
      for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
           it != groupScore.end(); it++) {
        cout << "Speaker:" << it->second << " Name:" << this->m_Speaker[it->second].m_name
             << " Score:" << this->m_Speaker[it->second].m_score[this->Index - 1] << endl;
      }
      int count = 0;
      for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
           it != groupScore.end() && count < 3; it++, count++) {
        if (this->Index == 1) {
          first_victory.push_back((*it).second);
        } else
          top_three.push_back((*it).second);
      }
      groupScore.clear();
      cout << endl;
    }
  }
  cout << "------The " << this->Index << " match is over!------" << endl;
}

void SpeechManager::showScore() {
  cout << "------The " << this->Index << " round advancement speaker------" << endl;
  vector<int> v;
  if (this->Index == 1) {
    v = first_victory;
  } else
    v = top_three;
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "Speaker:" << *it << " Name:" << this->m_Speaker[*it].m_name
         << " Score:" << this->m_Speaker[*it].m_score[this->Index - 1] << endl;
  }
  cout << endl;
}

void SpeechManager::saveRecord() {
  ofstream ofs;
  ofs.open("speech.csv", ios::out | ios::app);
  for (vector<int>::iterator it = top_three.begin(); it != top_three.end(); it++) {
    ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
  }
  ofs << endl;
  ofs.close();
  this->fileIsEmpty = false;
  cout << "------Record over!------";
}

void SpeechManager::loadRecord() {
  ifstream ifs("speech.csv", ios::in);
  if (!ifs.is_open()) {
    this->fileIsEmpty = true;
    cout << "The file isn't exist!" << endl;
    ifs.close();
    return;
  }
  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    cout << "The file is empty!" << endl;
    this->fileIsEmpty = true;
    ifs.close();
    return;
  }
  this->fileIsEmpty = false;
  ifs.putback(ch);
  string data;
  int index = 0;
  while (ifs >> data) {
    /* cout << data << endl; */
    vector<string> v;
    int pos = -1;
    int start = 0;
    while (1) {
      pos = data.find(",", start);
      if (pos == -1) {
        break;
      }
      string temp = data.substr(start, pos - start);
      v.push_back(temp);
      start = pos + 1;
    }
    this->m_Record.insert(make_pair(index, v));
    index++;
  }
  ifs.close();
}

void SpeechManager::showRecord() {
  if (this->fileIsEmpty) {
    cout << "The file isn't exist!" << endl;
  } else {
    for (int i = 0; i < this->m_Record.size(); i++) {
      cout << "The " << i + 1 << " match:" << endl
           << "Champion:" << this->m_Record[i][0] << " Score:" << this->m_Record[i][1] << endl
           << "runner up:" << this->m_Record[i][2] << " Score:" << this->m_Record[i][3] << endl
           << "runner-up:" << this->m_Record[i][4] << " Score:" << this->m_Record[i][5] << endl;
    }
  }
}

void SpeechManager::clearRecord() {
  cout << "Are you sure?" << endl;
  cout << "1.yes" << endl;
  cout << "2.no" << endl;
  int select = 0;
  cin >> select;
  if (select == 1) {
    ofstream ofs("speech.csv", ios::trunc);
    ofs.clear();
    this->InitSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "clear over!" << endl;
  }
}

void SpeechManager::exitSystem() {
  cout << "See you again!" << endl;
  exit(0);
}

SpeechManager::~SpeechManager() {}
