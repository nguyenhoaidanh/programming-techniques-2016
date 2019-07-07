#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<iomanip>
#include <time.h>
#include<algorithm>
#include<vector>
#define NUM 1000
using namespace std;

void edit_string(string &str);
void display_string(const string& str);
void delete_space(string &str); //Xoa dau cach,tinh chinh van ban de xuat file
string dinh_dang_chuoi(string s);
string RE_dinh_dang_chuoi(string s);
