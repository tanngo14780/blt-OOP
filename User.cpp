#include <bits/stdc++.h>

using namespace std;
 
class User
{
	protected:
		
	    string userName;
	    string passWord;
	    int trangThai; // 0 - OFF , 1 - ON
	 
	public:
		
	    User()
	    {
	        this->userName = "user123";
	        this->passWord = "user123";
	        this->trangThai = 0;
	    }
	    
	    User(string userName, string passWord, int trangThai)
	    {
	        this->userName = userName;
	        this->passWord = passWord;
	        this->trangThai = trangThai;
	    }
	    
	    ~User()
	    {
	        this->userName = "user123";
	    	this->passWord = "user123";
	        this->trangThai = 0;
	    }

		//User dang ky moi, luc dang ky mac dinh cho user co trang thai ON
	    void NhapThongTin()
	    {
	        cout << "\tMOI BAN NHAP USERNAME CHO USER: ";
	        fflush(stdin);
	        getline(cin, this->userName);
	        
	        cout << "\tMOI BAN NHAP PASSWORD CHO USER: ";
	        fflush(stdin);
	        getline(cin, this->passWord);
	        
	        int trangThai = 1;
	        this->trangThai = trangThai;
	    }
	 
	    void HienThiThongTin()
	    {
	    	cout << "\t\t\t" << setw(15) << left << this->userName;
			if(this->trangThai == 1)
			{
				cout << "\t\t\t" << setw(12) << left << "ON" << endl;
			}else{
				cout << "\t\t\t" << setw(12) << left << "OFF" << endl;
			}
	    }
	    
	    bool UserLogin(string userName, string passWord){
	    	if(this->userName == userName && this->passWord == passWord){
	    		return true;
			}
			return false;
		}
		
		int GetTrangThai(){
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
		
		bool TatUser(){
			if(this->trangThai == 1){
				this->SetTrangThai(0);
				return true;
			}else // Trang thai dang bang 0 thi khong the tat 
			{
				return false;
			}
		}
		
		bool BatUser(){
			if(this->trangThai == 0){
				this->SetTrangThai(1);
				return true;
			}else{
				return false;
			}	
		}
		void WriteDataToFile(std::ofstream &empFile);
};

void User::WriteDataToFile(std::ofstream &empFile)
{
    empFile << this->GetUserName()  << std::endl;
    empFile << this->GetPassWord()  << std::endl;
    empFile << this->GetTrangThai() << std::endl;
}
