#include"admin.h"
// admin file
void Adminlogin::AdminLoginWindow()
{
      
       
   
       cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<"                        ****************ADMIN LOGIN****************"<<endl;
      cout<<endl;
      cout<<"                                       1.ADMIN Id :";
      cin>>ADMINID;
      cout<<endl;
      cout<<"                                       2.PASSWORD :";
      {
       

      }
      cin>>PASSWORD;
      cout<<endl;
      ifstream readpassword;
      ifstream readid;
      readpassword.open("admin.txt");
      readid.open("admin.txt");
      std::string adminpassword;
      std::string id;
      
      for(int i=1;i<=2;i++){
      std::getline(readpassword,adminpassword);//getting admin password from admin.txt
      }
      for(int i=1;i<=1;i++){
            std::getline(readid,id);
      }
         
         readpassword.close();
         
         
            if(adminpassword==PASSWORD)
            {
            this->AdminLoginMenu();
            }  
            else 
            {
             cout<<"                   Wrong Id or Password"<<endl;
             this->AdminLoginWindow();
             } 
                 
}
// AdminLoginMenu displays every functio admin can perform in menu driven program

void Adminlogin::AdminLoginMenu()
{
      std::system("clear");
            Trainclass t;
            Bookingclass b;
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;

            
            cout<<"                        1: TRAIN MENU"<<endl;
            cout<<"                        2: BOOKING MENU"<<endl;
           
            cout<<"                        3: USER INFORMATION"<<endl;
            cout<<"                        4: EXIT"<<endl;

            int choice;
            cout<<"                 CHOOSE ANYONE:  ";
            cin>>choice;
            switch(choice){
                  case 1:
                        t.TrainMenu();
                        break;
                  case 2:
                        b.BookingMenu();
                        break;
               
                  case 3:
                        UserData();
                        break; 
                  case 4:
                	exit(0);
                        break;   
                  default:
                        cout<<"wrong choice";
                        this->AdminLoginMenu();
                        break;                

            }
}




// Userdata is user to view user data from userdata.txt

void Adminlogin::UserData()
{
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      fstream viewuserdata;
      std::string read_data;
      viewuserdata.open("userdata.txt");
      //below logic is used to view user information in text file
      int end=0;
      string totalline;
      while(getline(viewuserdata,totalline))
      end++;
      viewuserdata.close();
       viewuserdata.open("userdata.txt");
       for(int i=1;i<=end;i++)
      {
            std::getline(viewuserdata,read_data);
            
            
            cout<<read_data<<endl; 
      }
      this->AdminLoginMenu();

}


           






      


      

