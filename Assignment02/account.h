#pragma once

#include "stringformat.h"
#include "in_menu.h"
#include "user.h"
#include "cart.h"
#include "book.h"

struct Account
{
	string account_ID; //Ten tai khoan
	string account_Password; //Mat khau
	string role; // ??????
	string account_ative; //Trang thai block
	string student_ID; //MSSV
};

extern string id_da_dang_nhap, pass_da_dang_nhap, mssv_da_dang_nhap;
extern string list_ID_block[NUM];
extern string ID_temp;
extern bool TK_bi_khoa;
extern int dem_list_ID_block;

void set_account_ID(string &account_ID); //Tao ten tai khoan,dung cho set_Account
void set_account_Password(string &account_Password); //Tao mat khau,dung cho set_Account
void Set_Account(Account &acc, User user); //Tao account trong he thong
void Set_User(User &someone); //Tao thong tin cua user

void khoa_tai_khoan(Account account, User user);
void mo_khoa_tai_khoan(Account account, User user);
void tim_kiem_thong_tin_user(Account account, User user);
void xoa_tai_khoan(Account account, User user);
void edit_account(Account account, User user);

/*******************DOI MAT KHAU********************/
void doi_mat_khau_user(Account &account, User user);
void doi_mat_khau_quan_ly(Account &account, User user);
void doi_mat_khau_thu_thu(Account &account, User user);

/********************CHON MENU**********************/
void chon_menu_thu_thu(Account &account, User user);
void chon_menu_quan_li(Account &account, User user);
void chon_menu_user(Account &account, User user);

/********************DANG NHAP**********************/
void menu_dang_nhap(Account account, User user);
void dang_nhap_user(Account account, User user);
void dang_nhap_thu_thu(Account account, User user);
void dang_nhap_quan_ly(Account account, User user);

/***************************************************/
void kiem_tra_qua_han();
void xem_thong_tin_user(Account account, User user);
void user_notification(Account acc);
void tra_sach(Account account, User user);
