#include "SimpleObj.h"

int SimpleObj::get_num() { return num; }

SimpleObj::SimpleObj() {
  // 仅会初始化一次
  static int static_num = 0;
  static_num++;
  num = static_num;
}

SimpleObj::~SimpleObj() {}