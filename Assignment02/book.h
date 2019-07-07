#pragma once

#include "stringformat.h"
#include "xuat_thoi_gian.h"

struct book //Struct luu thong tin search sach,dung de ho tro ham tim sach
{
	string name;
	string author;
	string content;
	double ratio_Levenshtein; //Ho tro so trung van ban de tim sach
};

struct Account;

struct User;

void Add_Book();
void Edit_add_book(book &book_ex);
void Erase_and_edit_book();
void edit_book(book &book_ex);
void search_book(vector<book> &book_search); //Search sach
int LevenshteinDistance(const string book_name, const string input_string); //So trung van ban
void sort(vector<book> &array); //Sort mang kieu bubble
void xoa_sach();
void Search_Menu();
void check_book();