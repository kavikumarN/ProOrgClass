#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

struct login_data {
      string userid;
      string password;
      string email;
} ld[100];

struct account_data {
      string userid;
      string accountid;
      string username;
      string equity;
      string balance;
} ad[100];

struct profile_data {
      string userid;
      string accountid;
      string username;
      string firstname;
      string lastname;
      string email;
      string accounttype;
      string address;
      string country;
      string phone;
} pd[100];

struct organization_data {
      string orgid;
      string name;
      string location;
      string parent;
      string type;
} od[100];

int db_query()
{
   std::string sql_login,sql_profile,sql_account,sql_organization;

   try
   {
      connection C("dbname = organization user = postgres password = postgres hostaddr = 127.0.0.1 port = 5432");

      sql_login = "SELECT * from login";

      nontransaction N(C);

      result R = (N.exec(sql_login));
      int i =0;
      for (result::const_iterator c = R.begin(); c != R.end(); ++c)
      {  
         ld[i].userid=to_string(c[0]);
         ld[i].password =to_string(c[1]);
         ld[i].email =to_string(c[3]);
        // cout << c[0] << c[1] << c[2] << endl;

      }

      sql_organization = "SELECT * from organization";

     // nontransaction N(C);

        R = (N.exec(sql_organization));
      
      for (result::const_iterator c = R.begin(); c != R.end(); ++c)
      {  
         od[i].orgid=to_string(c[0]);
         od[i].name =to_string(c[1]);
         od[i].location =to_string(c[3]);
         od[i].parent =to_string(c[4]);
         od[i].type =to_string(c[5]);
        // cout << c[0] << c[1] << c[2] << c[3]<<c[4] <<c[5]<< endl;
      }


      sql_profile = "SELECT * from profile";

     // nontransaction N(C);

      R = (N.exec(sql_profile));

      for (result::const_iterator c = R.begin(); c != R.end(); ++c)
      {  
         pd[i].userid=to_string(c[0]);
         pd[i].accountid =to_string(c[1]);
         pd[i].username =to_string(c[3]);
         pd[i].firstname =to_string(c[4]);
         pd[i].lastname =to_string(c[5]);
         pd[i].email =to_string(c[6]);
         pd[i].accounttype =to_string(c[7]);
         pd[i].address =to_string(c[7]);
         pd[i].country =to_string(c[6]);
         pd[i].phone =to_string(c[8]);

        // cout << c[0] << c[1] << c[2] << c[3]<<c[4] <<c[5]<<c[6]<<c[7]<<c[8]<< endl;
      }

         sql_account = "SELECT * from account";

      //nontransaction N(C);

      R = (N.exec(sql_account));

      for (result::const_iterator c = R.begin(); c != R.end(); ++c)
      {  
         ad[i].userid=to_string(c[0]);
         ad[i].accountid =to_string(c[1]);
         ad[i].username =to_string(c[3]);
         ad[i].equity =to_string(c[4]);
         ad[i].balance =to_string(c[5]);

        // cout << c[0] << c[1] << c[2] << c[3]<<c[4] <<c[5]<< endl;
      }

      C.disconnect();
   }
   catch (const std::exception &e)
   {
      cerr << "ERROR in opening :" << e.what() << std::endl;
      return 1;
   }
}

int main(int argc, char *argv[])
{
   db_query();

   cout<<ld[0].email;
   return 0;
}