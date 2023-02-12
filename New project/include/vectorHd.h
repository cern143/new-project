#pragma once
#include "classHd.h"
#include <vector>
using namespace std;
void readHd(vector<Hopdong> &v, int mode);
void searchHd(vector<Hopdong> &v, string s, vector<int> &rank, int mode);
void changeHd(vector<Hopdong> &v, vector<int> &rank);
void deleteHd(vector<Hopdong> &v, vector<int> &rank);
unsigned int sum(vector<Hopdong> &v, struct tm start_time, struct tm end_time);
