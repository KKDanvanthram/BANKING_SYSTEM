#include<iostream>
#include<vector>
class Bank
{
private:
    std::vector<int> accno;
    std::vector<std::string> accname;
    std::vector<double> bal;
public:
    int ano;
    std::string name;
    double b;
    void setData(int a,std::string n,double b)
    {
        accno.push_back(a);
        accname.push_back(n);
        bal.push_back(b);
    }
    void setData()
    {
        int ano;
        std::string name;
        double b;
        std::cout<<"Enter Customer Details:"<<std::endl;
        std::cout<<"Enter Account Number:";
        std::cin>>ano;
        accno.push_back(ano);
        std::cout<<"Enter Name of the account holder:";
        std::cin>>name;
        accname.push_back(name);
        std::cout<<"Enter Bank Balance:";
        std::cin>>b;
        bal.push_back(b);
    }
    void display()
    {
        int length=accno.size();
        for (int i=0;i<length;i++)
        {
            std::cout<<"--------------------"<<std::endl;
            std::cout<<i+1<<". Account Number= "<<accno[i]<<std::endl;
            std::cout<<i+1<<". Account Holder= "<<accname[i]<<std::endl;
            std::cout<<i+1<<". Account Balance= "<<bal[i]<<std::endl;
            std::cout<<"--------------------"<<std::endl;
        }
    }
    void deposit()
    {
        int a;
        double amt;
        int flag=0;
        std::cout<<"Deposit process..."<<std::endl;
        std::cout<<"Enter Account Number:";
        std::cin>>a;
        std::cout<<"Enter Amount to Be Deposited:";
        std::cin>>amt;
        for (int i=0;i<accno.size();i++){
            if (accno[i]==a){
                    bal[i]+=amt;
                    flag++;
            }
        }
        if (flag==0)
        {
            std::cout<<"Account Number Doesn't Exist!"<<std::endl;
        }
        else
        {
            std::cout<<"Your Action has been successful"<<std::endl;
        }
    }
    void check()
    {
        int a,flag=0;
        std::cout<<"Responding to your balance inquiries...."<<std::endl;
        std::cout<<"Enter Your Account Number=";
        std::cin>>a;
        for (int i=0;i<accno.size();i++)
        {
            if (accno[i]==a){
                    flag++;
                    std::cout<<"-----------------------------"<<std::endl;
                    std::cout<<"Account Number ="<<accno[i]<<std::endl;
                    std::cout<<"Account Holder ="<<accname[i]<<std::endl;
                    std::cout<<"Account Balance="<<bal[i]<<std::endl;
                    std::cout<<"-----------------------------"<<std::endl;
            }
        }
        if (flag==0){
            std::cout<<"Account Number Doesn't Exist!"<<std::endl;
        }
    }
    void withdraw()
    {
        int a,flag=0;
        double amt;
        std::cout<<"Responding to you Withdraw Request....."<<std::endl;
        std::cout<<"Enter Account Number=";
        std::cin>>a;
        std::cout<<"Enter Amount to be Withdrawn=";
        std::cin>>amt;
        for (int i=0;i<accno.size();i++)
        {
            if (accno[i]==a)
            {
                if(amt>bal[i])
                {
                    flag+=2;
                    std::cout<<"Withdraw amt is more than your balance"<<std::endl;
                    break;
                }
                else
                {
                flag+=1;
                bal[i]-=amt;
                }

            }
        }
        if (flag==0)
        {
            std::cout<<"Account Number Doesn't Exist!"<<std::endl;
        }
        else if(flag==2)
        {
            std::cout<<"Enter Valid Withdraw AMT"<<std::endl;
        }
        else
        {
            std::cout<<"Requested Action Has Been Successful!"<<std::endl;
        }
    }
};
int main()
{
    Bank b;
    std::cout<<"Welcome To KKD Bank"<<std::endl;
    int ch=0;
    while (ch!=5)
    {
        std::cout<<"Choose The Action\n1.Add Account\n2.Balance Inquiries\n3.Deposit\n4.Withdraw\n5.Exit\n";
        std::cout<<"Enter Your Choice=";
        std::cin>>ch;
        if (ch==1)
        {
            b.setData();
        }
        else if (ch==2)
        {
            b.check();
        }
        else if (ch==3)
        {
            b.deposit();
        }
        else if (ch==4)
        {
            b.withdraw();
        }
        else
        {
            break;
        }
    }
    return 0;
}
