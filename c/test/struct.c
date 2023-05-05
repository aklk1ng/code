#include <stdio.h>
struct STU // 结构体的创建
{
  char name[20];
  int age;
  double score;
};
int main() {
  struct STU s = {"李四", 18, 95.5}; // 结构体的初始化
  struct STU *pa = &s;
  printf("%s, %d, %lf\n", s.name, s.age, s.score); // 结构体变量.成员变量
  printf("%s, %d, %lf\n", (*pa).name, (*pa).age, (*pa).score);
  printf("%s, %d, %lf\n", pa->name, pa->age, pa->score);
  return 0;
}
