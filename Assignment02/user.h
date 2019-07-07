#pragma once

#include "stringformat.h"
#include "xuat_thoi_gian.h"

struct User
{
	string student_ID; //MSSV
	string user_name; //Ten cua user
	string user_date_of_birth; // ngay thang nam sinh user DD//MM//YY
	string user_job; //Cong viec cua user
	string user_mail; //Dia chi email cua user
};

void set_user_student_ID(string &user_student_ID); //Tao mssv cho user
void set_user_name(string &user_name); //Tao ten cua user
void set_user_job(string &user_job);
void set_user_email(string &user_email);
void set_user_ngay_sinh(string &user_date_of_birth);
bool check_ngay_sinh(string user_date_of_birth);
