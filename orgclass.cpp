//  class to contain and manage data of organization operations
#include <iostream>

using namespace std;

class Organization 
{
    protected: 
        std::string orgid,name,location,parent,type;
        ///std::string orgid,location;

    public:      
       virtual int Organization_attribs()
            { 
                orgid = "ORG001";
                name = "ZUBACORP";
                location = "ASIA";
                type = "HEAD";
                parent = "NIL";

                return 0;
            }
};

class Account_details : public Organization{
    protected:

        std::string userid, account_type, account_no,transaction_history,branch;
        double balance,equity;
    public:
        int user_details() {
            userid = "USR001";
            account_no = "ACC001";
            account_type = "normal";
            transaction_history = "available";
            branch = orgid;
            balance = 50000.00;
            equity = 78000.00;
            return 0;
        }
};

class profile : public Organization, public Account_details 
{
       private: 
       string userid1,username,firstname,lastname,email,phone,address,bran;

       public: 
       int profile_details() {

           userid1 = userid;
           username = "Mike";
           firstname = "Mike";
           lastname = "jack";
           email = "me@github.com";
           phone = "9876443210";
           bran  = branch;
           
           return 0;
       }

       int display() {
           cout<<username<<userid1<<branch<<endl;
       }


};

int main()
{
    profile p1;
    Account_details a1;
    a1.Organization_attribs();
      p1.user_details();
    p1.profile_details();
  
    p1.display();


return 0;
}