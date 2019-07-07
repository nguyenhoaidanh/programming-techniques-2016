#include "user.h"

void set_user_student_ID(string &user_student_ID)
{
	//Xoa het bo nho dem de nhap string
	user_student_ID.clear();
	//Nhap ma so sinh vien
	bool exit_set_studen_id = false; //Trang thai cua viec nhap mssv,neu nhap dung thi se thanh true va thoat vong lap
	while (exit_set_studen_id == false)
	{
		getline(cin, user_student_ID); //Nhap mssv cua someone

									   //Kiem tra mssv hop le
		if (user_student_ID.length() != 7) //Kiem tra do dai mssv cua someone
		{
			cout << "MSSV can co 7 chu so, vui long nhap lai" << endl;
			continue;
		}
		else
		{
			exit_set_studen_id = true; //Cho bien kiem soat tam thoi la true,xong tiep tuc kiem tra,neu khong false thi thoat while
									   //Kiem tra tung ki tu cua someone co phai la so khong
			for (size_t i = 0; i < 7; ++i)
			{
				if (!isdigit(user_student_ID[i])) //Dung ham isdigit(str[i]) de check
				{
					cout << "MSSV phai la cac chu so, vui long nhap lai" << endl;
					exit_set_studen_id = false; //Tra bien kiem soat ve false de nhap lai mssv
					break;
				}
			} //End for check ki tu
		} //End else	
	} //End while nhap mssv
}
void set_user_name(string &user_name) // ??????????????
{
	while (true)
	{
		getline(cin, user_name);
		if (user_name.length() >= 5) //?????????? Co nen kiem tra truong hop ten khong co cac chu so ???????????
			break;
		else
			cout << "Ten qua ngan, vui long nhap lai" << endl;
	}
	delete_space(user_name); //Xoa cac dau cach du trong ten
}
void set_user_job(string &user_job) // ??????????
{
	getline(cin, user_job);
}
void set_user_email(string &user_email)
{
	cout << "Nhap email cua ban: ";
	getline(cin, user_email);
	int a_cong_find = user_email.find("@");
	int space_find = user_email.find(" ");
	while (a_cong_find == -1 || space_find != -1)
	{
		cout << "Nhap lai email cua ban, email phai co ki tu '@' va khong duoc chua khoang trang: ";
		getline(cin, user_email);
		a_cong_find = user_email.find("@");
		a_cong_find = user_email.find(" ");
	}
}
void set_user_ngay_sinh(string &user_date_of_birth)
{
	cout << "Nhap ngay sinh cua ban (dd/mm/yyyy): ";
	getline(cin, user_date_of_birth);
	while (!check_ngay_sinh(user_date_of_birth))
	{
		cout << "Nhap sai. Xin moi nhap lai!!!" << endl;
		getline(cin, user_date_of_birth);
	}
}
bool check_ngay_sinh(string user_date_of_birth)
{
	bool dinh_dang_ngay_sinh;
	if (user_date_of_birth[2] != '/' || user_date_of_birth[5] != '/' || user_date_of_birth.length() != 10)
	{
		dinh_dang_ngay_sinh = false;
	}
	else
	{
		stringstream temp(user_date_of_birth);
		char temp1, temp2;
		int dd, mm, yyyy;
		temp >> dd >> temp1 >> mm >> temp2 >> yyyy;
		int ngay = ngay_trong_thang(mm, yyyy);
		if (dd <= 0 || dd > ngay || mm <= 0 || mm > 12 || yyyy <= 0)
			dinh_dang_ngay_sinh = false;
		else dinh_dang_ngay_sinh = true;

	}
	return dinh_dang_ngay_sinh;
}
