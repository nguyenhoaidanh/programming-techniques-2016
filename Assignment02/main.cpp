#include "account.h"
#include "book.h"
#include "cart.h"

string id_da_dang_nhap, pass_da_dang_nhap, mssv_da_dang_nhap;
string list_ID_block[NUM];
string ID_temp;
bool TK_bi_khoa = false;
int dem_list_ID_block = 0;

int main()
{
	User user;
	Account account;

	int lua_chon_sai = 1;
	string choice;
	in_menu_start();
	do
	{
		getline(cin, choice);
		system("cls");
		menu_dang_nhap(account, user);
		if (!TK_bi_khoa)lua_chon_sai = 0;
		while (TK_bi_khoa)
		{

			string chon;
			cout << "Ban co muon dang nhap tai khoan khac khong ? (y/n) " << endl;
			while (true)
			{
				cin >> chon;
				if (chon == "y" || chon == "n") break;
				else //Neu nhap sai chon nhap lai toi khi dung
				{
					cout << "Khong xac nhan duoc lua chon, vui long nhap lai" << endl;
					continue;
				}
			} //End while nhap lua chon
			if (chon == "y") {
				system("cls"); TK_bi_khoa = false;
				menu_dang_nhap(account, user);
			}
			else {
				lua_chon_sai = 0; break;
			}
		}
	} while (lua_chon_sai);

}

