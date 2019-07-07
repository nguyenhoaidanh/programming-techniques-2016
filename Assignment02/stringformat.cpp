#include "stringformat.h"

void edit_string(string &str)
{
	system("cls");
	cout << str;

	char ch;
	ch = _getch();
	while (ch != 13) //Nhan enter de ket thuc
	{
		if (ch == 8) //Khi nhan nut backspace
		{
			if (str.length() > 0) //Neu length > 0 thi moi xoa
			{
				cout << '\b'; //Xoa ki tu trong console
				cout << ' '; //Thay the ki tu do bang space
				cout << '\b'; //Xoa space vua moi them vao
				str.erase(str.length() - 1, 1); //Xoa ki tu luu trong string
			}
		}
		else
		{
			str.push_back(ch); // Them char vao string password
			cout << ch; //Hien thi dau *
		}
		ch = _getch();
	} //End while
	delete_space(str);
}
void display_string(const string& str)
{
	unsigned int cnt = 0;
	for (size_t i = 1; i <= str.size(); i++)
	{
		cout << str[i-1];
		++cnt;
		if (cnt >= 100 && str[i-1] == 32)
		{
			
				cout << endl;
				cnt = 0;
		}
	}
	cout << endl;
}
void delete_space(string &str)
{
	if (str.length() > 0)
	{
		unsigned short cnt = 0; //Bien dem khoang trang
		for (size_t i = 0; i < str.length(); i++) //Chay het chuoi
		{
			if (str[i] == 32) //Gap khoang trang tang bien dem len 1
				++cnt;
			else //Neu gap ki tu thuong thi khoi tao lai bien dem
				cnt = 0;

			if (cnt > 1)
			{
				str.erase(i, 1); //Xoa khoang trang
				--i; //Tra lai vi string da thay doi vi tri va length
			}
		}
		//Xoa khoang trang dau va cuoi
		if (str[str.length() - 1] == 32)
			str.erase(str.length() - 1, 1);
		if (str[0] == 32)
			str.erase(0, 1);
	}
}
string dinh_dang_chuoi(string s)
{
	int a = s.find(" ");
	while (a != -1)
	{
		s.replace(a, 1, "_");
		a = s.find(" ");
	}
	return s;
}
string RE_dinh_dang_chuoi(string s)
{
	int a = s.find("_");
	while (a != -1)
	{
		s.replace(a, 1, " ");
		a = s.find("_");
	}
	return s;
}
