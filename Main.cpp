#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

class computer
{
    protected:
        string tenmay;
        string ketnoi;
    public:
        computer(){};
        computer(string tenmay, string ketnoi)
        {
            this->tenmay=tenmay;
            this->ketnoi=ketnoi;
        }

        void NhapMay()
	    {
	        cout << "\tNhap ten may ";
	        cin.ignore();
	        cin>>this->tenmay;
	        ketnoi= "connected";
	        this->ketnoi= ketnoi;
	    }

        void HienThiKetNoi()
	    {
	    	cout << "\t\t\t" << setw(15) << left << this->tenmay << "\t\t\t" << setw(15) << this->ketnoi << endl;
	    }
        string Gettenmay(){return this->tenmay;}
		void Settenmay(string tenmay){this->tenmay = tenmay;}
        string Getketnoi(){return this->ketnoi;}
		void Setketnoi(string ketnoi){this->ketnoi = ketnoi;}
	    void WriteDataToFile(ofstream &empFile)                                 //xây dựng hàm để ghi dữ liệu vừa nhập.
		{
            empFile << this->Gettenmay()  << endl;
            empFile << this->Getketnoi()  << endl;
        }
};

void HienThicomputerloiketnoi(list<computer> computers)                                              //xây dựng hàm dò tìm lỗi
{
	cout << "\t\t\t" << setw(15) << left << "tenmay";
	cout << "\t\t\t" << setw(15) << left << "ketnoi" << endl;
    list<computer>::iterator it;
    for (it = computers.begin(); it != computers.end(); ++it){
    	computer Computer = *it;
        if(Computer.Getketnoi() != "connected"){
        	Computer.HienThiKetNoi();
		}
	}
}

void WritecomputersToFile(list<computer> computers)                                                //xây dựng hàm ghi thông tin user vào file User
{
	ofstream fout;
	fout.open("computer.txt");
	list<computer>::iterator it;
    for (it = computers.begin(); it != computers.end(); ++it){
    	computer Computer = *it;
       	fout << Computer.Gettenmay() << ' ' << Computer.Getketnoi() << '\n';
	}
	fout.close();
}
void GetcomputersFromFile(list<computer> &computers)                                               //xây dựng hàm lấy dữ liệu từ file truyền vào 1 list để sử dụng
{
	computers.clear();
	ifstream fin;
    fin.open("computer.txt");
	string tenmay, ketnoi;
	while (fin >> tenmay >> ketnoi)
        {
		computer temp;
		temp.Settenmay(tenmay);
		temp.Setketnoi(ketnoi);
    	computers.insert(computers.end(), temp);
	}
}


class User                                                                                  // tạo class
{
	protected:                                                                              // khai báo thuộc tính thuộc đối tượng bảo vệ

	    string userName;
	    string passWord;
	    int trangThai; // 0 - OFF , 1 - ON

	public:                                                                         //xây dựng các hàm cơ bản thuộc lớp User

	    User()                                                                      // xây dựng hàm tạo
	    {
	        this->userName = "user123";
	        this->passWord = "user123";
	        this->trangThai = 0;
	    }

	    User(string userName, string passWord, int trangThai)                       // hàm tạo để truyền tham số
	    {
	        this->userName = userName;
	        this->passWord = passWord;
	        this->trangThai = trangThai;
	    }

	    ~User()                                                                     // hàm xóa
	    {
	        this->userName = "user123";
	    	this->passWord = "user123";
	        this->trangThai = 0;
	    }


	    void NhapThongTin()                                                         //xây dựng hàm dùng để đăng ký thông tin cho User mới, trạng thái mặc định ON
	    {
	        cout << "\tMOI BAN NHAP USERNAME CHO USER: ";
	        cin.ignore();
	        cin>>this->userName;

	        cout << "\tMOI BAN NHAP PASSWORD CHO USER: ";
	        cin.ignore();
	        cin>>this->passWord;

	        int trangThai = 0;
	        this->trangThai = trangThai;
	    }

	    void HienThiThongTin()                                                      // xây dựng hàm thông báo trạng thái của các User (không hiện pass)
	    {
	    	cout << "\t\t\t" << setw(15) << left << this->userName;
			if(this->trangThai == 1)
			{
				cout << "\t\t\t" << setw(12) << left << "ON" << endl;
			}else{
				cout << "\t\t\t" << setw(12) << left << "OFF" << endl;
			}
	    }

	    bool UserLogin(string userName, string passWord){                           //xây dựng hàm kiểm tra thông tin đăng nhập chính xác hay chưa
	    	if(this->userName == userName && this->passWord == passWord){
	    		return true;
			}
			return false;
		}

		int GetTrangThai(){                                                         //hàm gọi để sử dụng các thuộc tính thuộc vùng protected
			return this->trangThai;
		}

		string GetUserName(){
			return this->userName;
		}

		string GetPassWord(){
			return this->passWord;
		}

		void SetTrangThai(int trangThai){
			this->trangThai = trangThai;
		}

		void SetUserName(string userName){
			this->userName = userName;
		}

		void SetPassWord(string passWord){
			this->passWord = passWord;
		}

		bool TatUser(){                                                              //xây dựng hàm để tắt User đang sử dụng (nếu trạng thái =0  thì không tắt được)
			if(this->trangThai == 1){
				this->SetTrangThai(0);
				return true;
			}else
			{
				return false;
			}
		}

		bool BatUser(){                                                              //xây dựng hàm để bật User đang sử dụng (nếu trạng thái =1  thì không bật được)
			if(this->trangThai == 0){
				this->SetTrangThai(1);
				return true;
			}else{
				return false;
			}
		}
		void WriteDataToFile(std::ofstream &empFile)                                 //xây dựng hàm để ghi dữ liệu vừa nhập.
		{
            empFile << this->GetUserName()  << std::endl;
            empFile << this->GetPassWord()  << std::endl;
            empFile << this->GetTrangThai() << std::endl;
        }
};

void ChucNang()                                                                       //bảng lựa chọn quyền sử dụng(admin/user)
{
    system("cls");
	cout << "\n";
	cout << "=========================DANH SACH CHUC NANG=========================\n";
	cout << "\n";
	cout << "1.  ADMIN DANG NHAP.\n";
	cout << "2.  USER  DANG NHAP.\n";
	cout << "0.  THOAT CHUONG TRINH.\n";
	cout << "\n";
	cout << "=====================================================================\n";
	cout << "NHAP LUA CHON CUA BAN: ";
}

bool AdminLogin(string userName, string passWord)                                      //xây dựng hàm kiểm tra đăng nhập admin(tham số truyền vào userName, passWord nhập từ bàn phím)
{
	ifstream file("ADMIN.txt");                                                       //mở file admin

	string contentInLine;                                                             //biến chứa giá trị của file
	string accountAdminInFile[2];                                                     //khởi tạo mảng gồm 2 ptu, phan tu dau tien la username, phan tu 2 la password
	int i = 0;                                                                        //biến đếm số dòng

    while(file >> contentInLine)                                                      //khởi tạo vòng lặp đưa giá trị trong file vào biến
        {
    	if(i == 2){                                                                   //nếu số dòng bằng 2 thì kết thúc(dòng userName và dòng passWord)
    		break;
    	}
        accountAdminInFile[i] = contentInLine;                                        //lần lượt gán biến chứa giá trị của file vào giá trị của mảng
        i++;                                                                          //tăng biến đếm số dòng
    }
	if(userName == accountAdminInFile[0] && passWord == accountAdminInFile[1]){       //kiểm tra nếu đúng thì trả về 1 sai thì trả về 0
		return 1;
	}else{
		return 0;
	}
}

bool UserLoginInList(list<User> users, string userName, string passWord)               //zây dựng hàm kiểm tra đăng nhập user(truyển vào list được lấy từ file, userName, passWord nhập từ userLogin
{
    list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){                                 //xây dựng vòng lặp list kiểm tra từng phần tử trong list nếu trùng thì true, không trùng thì false
    	User user = *it;
        if(user.UserLogin(userName, passWord) == true){
        	return true;
		}
	}
	return false;
}
void ChucNangAdmin()                                                                  //bảng lựa chọn chức năng của admin
{
    system("cls");
	cout << "\n";
	cout << "\t=====================DANH SACH CHUC NANG ADMIN=====================\n";
	cout << "\n";
	cout << "\t1.  DANG KY USER.\n";
	cout << "\t2.  TAT USER.\n";
	cout << "\t3.  BAT USER.\n";
	cout << "\t4.  XEM DANH SACH USER ON/OFF.\n";
	cout << "\t5.  DO LOI.\n";
	cout << "\t6.  CHUYEN DU LIEU.\n";
	cout << "\t0.  DANG XUAT ADMIN.\n";
	cout << "\n";
	cout << "\t=====================================================================\n";
	cout << "\tNHAP LUA CHON CUA BAN: ";
}

void HienThiUserON(list<User> users)                                                   //xây dựng hàm hiển thị các user đang hoạt động
{
	cout << "\t\t\t" << setw(15) << left << "USERNAME";
	cout << "\t\t\t" << setw(15) << left << "TRANG THAI" << endl;
    list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
    	User user = *it;
        if(user.GetTrangThai() == 1){
        	user.HienThiThongTin();
		}
	}
}

void HienThiUserOFF(list<User> users)                                                  //xây dựng hàm hiển thị các user đang tắt
{
	cout << "\t\t\t" << setw(15) << left << "USERNAME";
	cout << "\t\t\t" << setw(15) << left << "TRANG THAI" << endl;
    list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
    	User user = *it;
        if(user.GetTrangThai() == 0){
        	user.HienThiThongTin();
		}
	}
}


void TatUserInList(list<User> &users, string userName)                                 //xây dựng hàm tắt user được nhập vào(sử dụng hàm tắt trong class)
{
    list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
    	User &user = *it;
        if(user.GetUserName() == userName)
        {
        	if(user.TatUser() == true){
        		cout << "\t\tDA TAT USER THANH CONG!";
        		return;
			}else{
				cout << "\t\tUSER DANG O TRANG THAI OFF. KHONG THE TAT!";
				return;
			}
		}
	}
	cout << "\t\tKHONG THE TIM THAY USER CO USERNAME = " << userName << "!";
}

void BatUserInList(list<User> &users, string userName)                                 //xây dựng hàm bật user được nhập vào(sử dụng hàm bật trong class)
{
	list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
    	User &user = *it;
        if(user.GetUserName() == userName){
        	if(user.BatUser() == true){
        		cout << "\t\tDA BAT USER THANH CONG!";
        		return;
			}else{
				cout << "\t\tUSER DANG O TRANG THAI ON. KHONG THE BAT!";
				return;
			}
		}
	}
	cout << "\t\tKHONG THE TIM THAY USER CO USERNAME = " << userName << " !";
}

void WriteUsersToFile(list<User> users)                                                //xây dựng hàm ghi thông tin user vào file User
{
	ofstream fout;
	fout.open("USER.txt");
	list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it){
    	User user = *it;
       	fout << user.GetUserName() << ' ' << user.GetPassWord() << ' ' << user.GetTrangThai() << '\n';
	}
	fout.close();
}

bool ChuyenDuLieu(list<User> users, string userName)                                   //xây dựng hàm gửi dữ liệu
{
	ofstream fout;
	fout.open("ChuyenDuLieu.txt");
	list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it)
        {
    	User user = *it;
    	if(user.GetUserName() == userName){
    		fout << user.GetUserName() << ' ' << user.GetPassWord() << ' ' << user.GetTrangThai() << '\n';
    		return true;
		}
	}
	fout.close();
	return false;
}

void GetUsersFromFile(list<User> &users)                                               //xây dựng hàm lấy dữ liệu từ file truyền vào 1 list để sử dụng
{
	users.clear();
	ifstream fin;
    fin.open("USER.txt");
	string userName, passWord;
	int trangThai;
	while (fin >> userName >> passWord >> trangThai)
        {
		User temp;
		temp.SetUserName(userName);
		temp.SetPassWord(passWord);
		temp.SetTrangThai(trangThai);
    	users.insert(users.end(), temp);
	}
}

void ChucNangUser()                                                                  //bảng lựa chọn chức năng của admin
{
    system("cls");
	cout << "\n";
	cout << "\t=====================DANH SACH CHUC NANG ADMIN=====================\n";
	cout << "\n";
	cout << "\t 0.DANG XUAT USER.\n";
	cout << "\n";
	cout << "\t=====================================================================\n";
	cout << "\tNHAP LUA CHON CUA BAN: ";
}


int main()
{
	list<User> users;
	GetUsersFromFile(users);                                                            // Lay tat ca user tu file User.txt va chuyen vao list
  	list<computer> computers;
  	GetcomputersFromFile(computers);
  	while (1)
        {
            ChucNang();                                                                 // hiển thị bảng chọn chức năng đăng nhập
            int n;
            cin >> n;
            cout << "\n";
            switch (n)
            {
                case 1:                                                                 // chọn đăng nhập admin
                {
                    cout << "1.  ADMIN DANG NHAP.\n";
                    string userName, passWord;
                    cout << "\tMOI BAN NHAP USERNAME: ";
                    cin>>userName;
                    cout << "\tMOI BAN NHAP PASSWORD: ";
                    cin>>passWord;
                    int resultAdminLogin = AdminLogin(userName, passWord);             //tạo biến kiểm tra đăng nhâp
                    if(resultAdminLogin == 0)
                        {
                        cout << "USERNAME HOAC PASSWORD KHONG DUNG. DANG NHAP THAT BAI!";
                        cout << "\n";
                        }
                    else{
                            bool isContinue = true;
                            while(isContinue){
                                ChucNangAdmin();
                                int adminChoose;
                                cin >> adminChoose;
                                cout << "\n";
                                switch (adminChoose)
                                {
                                    case 1:{
                                        cout << "\t1.  DANG KY USER.\n";
                                        User user;
                                        user.NhapThongTin();
                                        users.insert(users.end(), user);
                                        WriteUsersToFile(users);
                                        GetUsersFromFile(users);
                                        cout << "\tBAN DA DANG KY USER THANH CONG!";
                                        cout << "\n";
                                        break;
                                    }
                                    case 2:{
                                        cout << "\t2.  TAT USER.\n";
                                        string userNameOFF;
                                        cout << "\t\tMOI BAN NHAP USERNAME DE TAT: ";
                                        cin.ignore();
                                        cin>>userNameOFF;
                                        TatUserInList(users, userNameOFF);
                                        WriteUsersToFile(users);
                                        GetUsersFromFile(users);
                                        cout << "\n";
                                        break;
                                    }
                                    case 3:{
                                        cout << "\t3.  BAT USER.\n";
                                        string userNameON;
                                        cout << "\t\tMOI BAN NHAP USERNAME DE BAT: ";
                                        cin.ignore();
                                        cin>>userNameON;
                                        BatUserInList(users, userNameON);
                                        WriteUsersToFile(users);
                                        GetUsersFromFile(users);
                                        cout << "\n";
                                        break;
                                    }
                                    case 4:{
                                        cout << "\t4.  XEM DANH SACH USER ON/OFF.\n";
                                        cout << "\t\tDANH SACH USER DANG ON\n";
                                        HienThiUserON(users);
                                        cout << "\t\tDANH SACH USER DANG OFF\n";
                                        HienThiUserOFF(users);
                                        cout << "\n";
                                        break;
                                    }
                                    case 5:{
                                        cout << "\t5.  DO LOI.\n";
                                        cout << "\t\tDANH SACH COMPUTER BI LOI KET NOI\n";
                                        HienThicomputerloiketnoi(computers);
                                        break;
                                    }
                                    case 6:{
                                        cout << "\t6.  CHUYEN DU LIEU .\n";
                                        cout << "\t\tMOI BAN NHAP USERNAME DE CHUYEN DU LIEU: ";
                                        string userNameChuyenDuLieu;
                                        cin.ignore();
                                        cin>>userNameChuyenDuLieu;
                                        if(ChuyenDuLieu(users, userNameChuyenDuLieu) == true){
                                            cout << "\tBAN DA CHUYEN DU LIEU THANH CONG!";
                                        }else{
                                            cout << "\tKHONG TON TAI USER CO USERNAME =  " << userNameChuyenDuLieu << "!";
                                        }
                                        break;
                                    }
                                    case 0:{
                                        isContinue = false;
                                        break;
                                    }
                                    default:
                                    cout << "\t\tVUI LONG CHON CAC CHUC NANG DA CHO TRONG DANH SACH!\n";
                                    break;
                                }
                            }
                    }
                    break;
                }
                case 2:
                {
                    cout << "2.  USER  DANG NHAP.\n";
                    string userName, passWord;
                    cout << "\tMOI BAN NHAP USERNAME: ";
                    cin.ignore();
                    cin>>userName;
                    cout << "\tMOI BAN NHAP PASSWORD: ";
                    cin.ignore();
                    cin>>passWord;
                    if(UserLoginInList(users, userName, passWord) == false){
                        cout << "USERNAME HOAC PASSWORD KHONG DUNG. DANG NHAP THAT BAI!";
                    }else
                    {
                        cout << "DANG NHAP THANH CONG. ";
                        BatUserInList(users, userName);
                        WriteUsersToFile(users);
                        GetUsersFromFile(users);
                        string dangxuatUser;
                        do
                        {
                            cout<< endl << "MOI BAN SU DUNG DICH VU \n";
                            cout << "BAN CO MUON DANG XUAT Y/N \n";
                            cin >> dangxuatUser;
                            if(dangxuatUser== "y")
                            {
                                cout << "DA DANG XUAT USER";
                                TatUserInList(users, userName);
                                WriteUsersToFile(users);
                                GetUsersFromFile(users);
                            }
                        }while(dangxuatUser=="n");

                    }
                    cout << "\n";
                    break;
                }
                case 0:
                {
                    cout << "0. THOAT CHUONG TRINH.\n";
                    return 0;
                }
                default:
                    cout << "\tVUI LONG CHON CAC CHUC NANG CHO TRONG DANH SACH!\n";
                    break;
            }
        }
	system("pause");
	return 0;
}
