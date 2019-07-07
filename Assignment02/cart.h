#pragma once

#include "stringformat.h"
#include "in_menu.h"
#include "xuat_thoi_gian.h"
#include "book.h"

void Cart_Main_Menu(string account_ID); //Menu chinh cua gio hang
void Exit_Cart_Main_Menu(string account_ID, vector<book> &book_borrow, bool &exit_main_menu);
void Read_Data(string account_ID, vector<book> &book_borrow);
void Save_Data(string account_ID, vector<book> &book_borrow); //Save lai du lieu khi thoat menu chinh
void Cart_Search_Menu(vector<book> &book_search, vector<book> &book_borrow); //Menu tim sach
void Cart_Manage_Menu(vector<book> &book_borrow, vector<book> &book_search, string account_ID); //Menu gio hang
void erase_cart(vector<book> &book_borrow, bool &exit_cart_manage_menu, bool &exit_edit_cart); //Xoa sach trong gio hang
void print_book_in_cart(vector<book> book_borrow); //Xuat sach trong gio hang ra man hinh
void confirm_cart(vector<book> &book_borrow, string account_ID); //Ham xac nhan gio hang,hoan tat muon sach
