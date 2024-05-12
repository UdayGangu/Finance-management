#include<iostream>
#include<string.h> 
#include<fstream>
#include<string>
#include<iomanip>   
#include<cctype>
#include<algorithm>   
#include<vector>
#include<ctime>
#include<sstream>     
#include<cstring>
#include<limits>          
using namespace std;



struct Bills                                     //declaring Structure
{
	int RoomRent;
	int Utilites;
	int Groceries;
	int Insurance;
	int Transportation;
	int PhoneBill;
	int LoansRepayment;
	int CreditCardsRepayment;
	int Entertainment;
	int Health;
	int OtherExpenses;
	string Name;
	string Place;
	string Email;
	string PhoneNumber;
};




class Store                                     //Creating a Class "Store"
{
	public:
		int monthly_income1;
		int TotalExpenditures1;
	    int RemainingPurse1;
	    string month1;
	    string FileName1;
	    Bills bills;
	    
};
class Expenditures:public Store                // creating a child class to store that is "expenditures"
{
	public:

		void GetValues1(string fn1)                        //getting the values from user
		{
			FileName1=fn1;
			cout<<"Enter Your name:";
			getline(cin,bills.Name);
			cout<<"Enter your Town:";
			getline(cin,bills.Place);
			cout<<"Enter your Mobile number:";
			getline(cin,bills.PhoneNumber);
			cout<<"Enter your Email:";
			getline(cin,bills.Email);
			cout<<"Which month bills you want to store:";
			cin>>month1;
			cout<<"Enter your monthly income:";
			cin>>monthly_income1;
			cout<<"Enter your monthly Utilites(Electricty/Water/Gas/Internet and Cable):";
			cin>>bills.Utilites;
			cout<<"Enter your monthly Groceries:";
			cin>>bills.Groceries;
			cout<<"Enter your monthly Insurances:";
			cin>>bills.Insurance;
			cout<<"Enter your monthly Transportations(Fuel/public_transportations):";
			cin>>bills.Transportation;
			cout<<"Enter your monthly Phone bills:";
			cin>>bills.PhoneBill;
			cout<<"Enter your monthly Loan repayments:";
			cin>>bills.LoansRepayment;
			cout<<"Enter your monthly CreditCard repayments:";
			cin>>bills.CreditCardsRepayment;
			cout<<"Enter your monthly Entertainment(movies/trips/family functions):";
			cin>>bills.Entertainment;
			cout<<"Enter your monthly Health:";
			cin>>bills.Health;
			cout<<"Enter your monthly Room rent:";
			cin>>bills.RoomRent;
			cout<<"Enter your monthly Other(educations etc.,):";
			cin>>bills.OtherExpenses;
			TotalExpenditures1=bills.Utilites+bills.Groceries+bills.Insurance+bills.Transportation+bills.PhoneBill+bills.LoansRepayment+bills.CreditCardsRepayment+bills.Entertainment+bills.Health+bills.RoomRent+bills.OtherExpenses;
		    RemainingPurse1=monthly_income1-TotalExpenditures1;
		    
			WriteToFile(FileName1);			
		}
		
		void WriteToFile(string fn1)                                         //Function to storing the values in file
		{
			FileName1=fn1;
            ofstream outFile(FileName1.c_str());
            if(outFile.is_open())
			{
				outFile<<setfill('_')<<setw(103)<<"_"<<endl;
                outFile<<setfill('_')<<setw(103)<<"_"<<endl;
				outFile<<setfill(' ')<<setw(42)<<left<<"||"<<"FINANCIAL MANAGEMENT"<<setw(42)<<right<<"||"<<endl;
                outFile<<setw(44)<<left<<"||"<<setw(58)<<left<<"Monthly Bills"<<"||"<<endl;
                outFile<<"||"<<setw(102)<<right<<"||"<<endl;
                outFile<<"||"<<setw(10)<<left<<"Name:"<<setw(90)<<left<<bills.Name<<"||"<<endl;
                outFile<<"||"<<setw(10)<<left<<"Place:"<<setw(90)<<left<<bills.Place<<"||"<<endl;
                outFile<<"||"<<setw(10)<<left<<"Contact:"<<setw(90)<<left<<bills.PhoneNumber<<"||"<<endl;
                outFile<<"||"<<setw(10)<<left<<"Email:"<<setw(90)<<left<<bills.Email<<"||"<<endl;
                outFile<<"||"<<setw(10)<<left<<"Month:"<<setw(90)<<left<<month1<<"||"<<endl;
                outFile<<"||"<<setfill('_')<<setw(100)<<"_"<<"||"<<endl;
                outFile<<setfill(' ')<<"||"<<setw(35)<<right<<"Categories"<<setw(57)<<right<<"Amount"<<setw(10)<<right<<"||"<<endl;
                outFile<<"||"<<setfill('_')<<setw(100)<<"_"<<"||"<<endl;
			    outFile<<setfill(' ')<<setw(20)<<left<<"||"<<setw(63)<<left<<"Monthly income:"<<setw(19)<<left<<monthly_income1<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Utilites(Electricty/Water/Gas/Internet and Cable):"<<setw(19)<<left<<bills.Utilites<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Groceries:"<<setw(19)<<left<<bills.Groceries<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Insurances:"<<setw(19)<<left<<bills.Insurance<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Transportations(Fuel/public_transportations):"<<setw(19)<<left<<bills.Transportation<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Phone bills:"<<setw(19)<<left<<bills.PhoneBill<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Loan repayments:"<<setw(19)<<left<<bills.LoansRepayment<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Credit Card repayments:"<<setw(19)<<left<<bills.CreditCardsRepayment<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Entertainment(movies/trips/family functions):"<<setw(19)<<left<<bills.Entertainment<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Health:"<<setw(19)<<left<<bills.Health<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Room rent:"<<setw(19)<<left<<bills.RoomRent<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Other(education etc.,):"<<setw(19)<<left<<bills.OtherExpenses<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Total expenditures are:"<<setw(19)<<left<<TotalExpenditures1<<"||"<<endl;
			    outFile<<setw(20)<<left<<"||"<<setw(63)<<left<<"Remaining purse on this month is:"<<setw(19)<<left<<RemainingPurse1<<"||"<<endl;
			    outFile<<"||"<<setw(102)<<right<<"||"<<endl;
			    time_t currentTime = time(0);
                struct tm* now = localtime(&currentTime);
                char dateString[11];
                strftime(dateString, sizeof(dateString), "%Y-%m-%d", now); 
                outFile<<setw(80)<<left<<"||"<<setw(5)<<left<<"Date:"<<setw(17)<<left<<dateString<<"||"<<endl;
			    outFile<<"||"<<setw(102)<<right<<"||"<<endl;
			    outFile<<setfill('_')<<setw(103)<<"_"<<endl;
                outFile<<setfill('_')<<setw(103)<<"_"<<endl;
                outFile.close();
            }
        }
};
class BillsDisplay:public Expenditures                       //creating a child class to expenditures that is"BillsDisplay"
{
	public:
		void ReadFromFile1(string fn1)                                      //Reading values from file and Displaying the values
		{
			string fileName1=fn1;
            ifstream inFile(FileName1.c_str());
            if (inFile.is_open()) 
			{
                string line;
                while (getline(inFile, line)) 
				{
					cout<<line<<endl;
                }
                inFile.close();
            }
        }
};



class PreviousMonth                                     //creating a class "PreviousMonth"
{
	public:
		string FileName2;
};
class checkbills:public PreviousMonth                      //Reading values from file and Displaying the values  
{
	public:
		void ReadFromFile2(string fn2)                                      
		{
			FileName2=fn2;
            ifstream inFile(FileName2.c_str());
            if (inFile.is_open()) 
			{
                string line;
                while (getline(inFile, line)) 
				{
					cout<<line<<endl;
                }
                inFile.close();
            }
            else 
			{
                cout<<"..!!!Soryy Iam unable to find the file you have entered!!!.. '"<<FileName2.c_str()<<"' for reading."<<endl;
                cout<<"I think there is no file with this name."<<endl;
            }
        } 
};







class split                                          // spliting the amount for future purpose           
{
	public:
	int monthly_income3;
	int TotalExpenditures3;
	int RemainingPurse3;
	string month3;
	string FileName3;
	Bills bills;	
};
class splitExpenditures:public split                   // getting values from user
{
	public:
	void GetValues2(string fn3)
	{
		FileName3=fn3;
		cout<<"Enter Your name:";
		getline(cin,bills.Name);
		cout<<"Enter your Town:";
		getline(cin,bills.Place);
		cout<<"Enter your Mobile number:";
		getline(cin,bills.PhoneNumber);
		cout<<"Enter your Email:";
		getline(cin,bills.Email);
		cout<<"Which month bills you want to store:";
		cin>>month3;
		cout<<"Enter your monthly income:";
		cin>>monthly_income3;
		cout<<"Amount to spent on Utilites(Electricty/Water/Gas/Internet and Cable):";
		cin>>bills.Utilites;
		cout<<"Amount to spent on Groceries:";
		cin>>bills.Groceries;
		cout<<"Amount to spent on Insurances:";
		cin>>bills.Insurance;
		cout<<"Amount to spent on Transportations(Fuel/public_transportations):";
		cin>>bills.Transportation;
		cout<<"Amount to spent on Phone bills:";
		cin>>bills.PhoneBill;
		cout<<"Amount to spent on loan repayments:";
		cin>>bills.LoansRepayment;
		cout<<"Amount to spent on CreditCard repayments:";
		cin>>bills.CreditCardsRepayment;
		cout<<"Amount to spent on Entertainment(movies/trips/family functions):";
		cin>>bills.Entertainment;
		cout<<"Amount to spent on Health:";
		cin>>bills.Health;
		cout<<"Amount to spent on Room rent:";
		cin>>bills.RoomRent;
		cout<<"Amount to spent on Others(education etc.,):";
		cin>>bills.OtherExpenses;
		TotalExpenditures3=bills.Utilites+bills.Groceries+bills.Insurance+bills.Transportation+bills.PhoneBill+bills.LoansRepayment+bills.CreditCardsRepayment+bills.Entertainment+bills.Health+bills.RoomRent+bills.OtherExpenses;
		RemainingPurse3=monthly_income3-TotalExpenditures3;
		WriteToFile(FileName3);
	}
	void WriteToFile(string fn3)                                         //Function to the values in file
	{
		FileName3=fn3;
        ofstream outFile(FileName3.c_str());
        if(outFile.is_open())
		{
			outFile<<setfill('_')<<setw(103)<<"_"<<endl;
            outFile<<setfill('_')<<setw(103)<<"_"<<endl;
			outFile<<setfill(' ')<<setw(42)<<left<<"||"<<"FINANCIAL MANAGEMENT"<<setw(42)<<right<<"||"<<endl;
            outFile<<setw(41)<<left<<"||"<<setw(61)<<left<<"Upcoming month savings"<<"||"<<endl;
            outFile<<"||"<<setw(102)<<right<<"||"<<endl;
            outFile<<"||"<<setw(10)<<left<<"Name:"<<setw(90)<<left<<bills.Name<<"||"<<endl;
            outFile<<"||"<<setw(10)<<left<<"Place:"<<setw(90)<<left<<bills.Place<<"||"<<endl;
            outFile<<"||"<<setw(10)<<left<<"Contact:"<<setw(90)<<left<<bills.PhoneNumber<<"||"<<endl;
            outFile<<"||"<<setw(10)<<left<<"Email:"<<setw(90)<<left<<bills.Email<<"||"<<endl;
            outFile<<"||"<<setw(10)<<left<<"month:"<<setw(90)<<left<<month3<<"||"<<endl;
            outFile<<"||"<<setfill('_')<<setw(100)<<"_"<<"||"<<endl;
            outFile<<setfill(' ')<<"||"<<setw(35)<<right<<"Categories"<<setw(57)<<right<<"Amount You want to spent"<<setw(10)<<right<<"||"<<endl;
            outFile<<"||"<<setfill('_')<<setw(100)<<"_"<<"||"<<endl;
			outFile<<setfill(' ')<<setw(15)<<left<<"||"<<setw(63)<<left<<"Monthly income:"<<setw(24)<<left<<monthly_income3<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Utilites(Electricty/Water/Gas/Internet and Cable):"<<setw(24)<<left<<bills.Utilites<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Groceries:"<<setw(24)<<left<<bills.Groceries<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Insurances:"<<setw(24)<<left<<bills.Insurance<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Transportations(Fuel/public_transportations):"<<setw(24)<<left<<bills.Transportation<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Phone bills:"<<setw(24)<<left<<bills.PhoneBill<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Loan repayments:"<<setw(24)<<left<<bills.LoansRepayment<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Credit Card repayments:"<<setw(24)<<left<<bills.CreditCardsRepayment<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Entertainments(movies/trips/family functions):"<<setw(24)<<left<<bills.Entertainment<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Health:"<<setw(24)<<left<<bills.Health<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Room rent:"<<setw(24)<<left<<bills.RoomRent<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Other(education etc.,):"<<setw(24)<<left<<bills.OtherExpenses<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Total expenditures for next month is:"<<setw(24)<<left<<TotalExpenditures3<<"||"<<endl;
			outFile<<setw(15)<<left<<"||"<<setw(63)<<left<<"Your savings for next month is:"<<setw(24)<<left<<RemainingPurse3<<"||"<<endl;
			outFile<<"||"<<setw(102)<<right<<"||"<<endl;
			time_t currentTime = time(0);
            struct tm* now = localtime(&currentTime);
            char dateString[11];
            strftime(dateString, sizeof(dateString), "%Y-%m-%d", now); 
            outFile<<setw(80)<<left<<"||"<<setw(5)<<left<<"Date:"<<setw(17)<<left<<dateString<<"||"<<endl;
			outFile<<"||"<<setw(102)<<right<<"||"<<endl;
			outFile<<setfill('_')<<setw(103)<<"_"<<endl;
            outFile<<setfill('_')<<setw(103)<<"_"<<endl;
            outFile.close();
            }
        }
};
class splitDisplay:public splitExpenditures              //displaying the values
{
	public:
	void display(string fn3)
	{
		string FileName3=fn3;
        ifstream inFile(FileName3.c_str());
        if (inFile.is_open()) 
		{
            string line;
            while(getline(inFile, line)) 
			{
				cout<<line<<endl;
            }
            inFile.close();
        }
	}
};




int main()                                                            //main function
{
	cout<<setfill('*')<<setw(48)<<"*"<<setfill(' ')<<endl;
	cout<<"*"<<setw(47)<<right<<"*"<<endl;
	cout<<setw(3)<<left<<"*"<<setw(44)<<left<<"WELCOME TO THE FINANCE MANAGEMENT PROJECT"<<"*"<<endl;
	cout<<"*"<<setw(47)<<right<<"*"<<endl;
	cout<<setfill('*')<<setw(48)<<"*"<<endl<<endl<<endl; 
	
	
	time_t currentTime = time(0);
    struct tm* now = localtime(&currentTime);
    int hour = now->tm_hour;
    cout<<setfill('*')<<setw(48)<<"*"<<setfill(' ')<<endl;
	cout<<"*"<<setw(47)<<right<<"*"<<endl;
    if(hour >= 5 && hour < 12)
	{
		cout<<setw(17)<<left<<"*"<<setw(30)<<left<<"GOOD MORNING1"<<"*"<<endl;
    } 
	else if(hour >= 12 && hour < 17)
	{
		cout<<setw(17)<<left<<"*"<<setw(30)<<left<<"GOOD AFTERNOON!"<<"*"<<endl;
    } 
	else 
	{
		cout<<setw(17)<<left<<"*"<<setw(30)<<left<<"GOOD EVENING!"<<"*"<<endl;
    }
    cout<<"*"<<setw(47)<<right<<"*"<<endl;
    cout<<setfill('*')<<setw(48)<<"*"<<setfill(' ')<<endl<<endl<<endl;
	
	
	
	int choice;
	cout<<"Enter 1: To store this monthly bills."<<endl;
	cout<<"Enter 2: If you want to see your previous month bills."<<endl;
	cout<<"Enter 3: To split the income for upcoming months and store them."<<endl;
	cout<<"Enter 4: To Exit. \n"<<endl;
	bool isValidChoice(int choice);
    while(true) {                  
        cout<<"Enter your choice:";
        cin>>choice;
        if(cin.fail())
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid choice! Please enter a valid integer."<<endl<<endl;
        } else if(isValidChoice(choice))
		{
            break;
        }
    }
	string FileName1;
	string FileName2;
	string FileName3;
	char ch='y';
    bool isValidFileName(string fileName);

 	cout<<endl<<endl<<endl;
	if(choice==1)                                             //if you want to store your bill
	{
		while(ch=='y')                                        
		{
			while(true)
			{
				cout<<"Name your file to save as(e.g., example.txt):";
				cin.ignore();
		        getline(cin,FileName1);
		        if(isValidFileName(FileName1)){break;}
			}
            transform(FileName1.begin(),FileName1.end(),FileName1.begin(),::tolower);
		    BillsDisplay bd;
		    bd.GetValues1(FileName1);
		    for(int i=0;i<5;i++)
		    {
			    cout<<endl;
		    }
		    bd.ReadFromFile1(FileName1);
		    cout<<endl<<endl;
		    cout<<"Do you want to store another bill( yes(y)  no(n) ):";
		    cin>>ch;
		    cout<<endl<<endl<<endl;
		}
	}
	else if(choice==2)                                      //if you want to see your previous bills
	{
		while(ch=='y')
		{
		    while(true)
		    {
		    	cout<<"Enter the file name to search(e.g., example.txt):";
		    	cin.ignore();
		        getline(cin,FileName2);
		    	if(isValidFileName(FileName2)){break;}
			}
			transform(FileName2.begin(),FileName2.end(),FileName2.begin(),::tolower);
		    checkbills cb;
		    for(int i=0;i<5;i++)
		    {
			    cout<<endl;
		    }
		    cb.ReadFromFile2(FileName2);
		    cout<<endl<<endl;
		    cout<<"Do you want to see another bill( yes(y)  no(n) ):";
		    cin>>ch;
		    cout<<endl<<endl<<endl;
		}
	}
	else if(choice==3)                                      //if you want to see your previous bills
	{
		while(ch=='y')
		{
			while(true)
		    {
		    	cout<<"Name your file to save as(e.g., example.txt):";
		    	cin.ignore();
		        getline(cin,FileName3);
		    	if(isValidFileName(FileName3)){break;}
			}
			transform(FileName3.begin(),FileName3.end(),FileName3.begin(),::tolower);
		    splitDisplay sd;
		    sd.GetValues2(FileName3);
		    for(int i=0;i<5;i++)
		    {
			    cout<<endl;
		    }
		    sd.display(FileName3);
		    cout<<endl<<endl;
		    cout<<"Do you want to split for one more month( yes(y)  no(n) ):";
		    cin>>ch;
		    cout<<endl<<endl<<endl;
		}
	}
	else if(choice==4)
	{
		cout<<"Enjoy your day..!!"<<endl;
	}	
	return 0;
}



bool isValidFileName(string fileName)                                      //Check if the file name is valid
{
    if (fileName.empty())
	{
        cout<<"Error: File name cannot be empty."<<endl;
        return false;
    }

    if(fileName.length() <= 4||fileName.substr(fileName.length() - 4)!=".txt") 
	{
        cout<<"Error: Invalid file extension. Please use a '.txt' file."<<endl;
        return false;
    }
    return true;
}


bool isValidChoice(int choice)                                    //check if choice is valid or not
{
	if(choice<1||choice>4)
	{
		cout<<"Invalid choice! Please enter a valid integer."<<endl<<endl<<endl;
		return false;
	}
	return true;
}



