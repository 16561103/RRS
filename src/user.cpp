#include"user.h"

//UserLoginWindow is used by user to get user access in user functions in this 
// user id and password are verified

void Userlogin::UserLoginWindow(){
      std::system("clear");
        
       
      cout<<endl;
      cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<"                             ****************USER LOGIN****************"<<endl;
      cout<<endl;
      cout<<"                                             1.USER Id :";
      cin>>USERID;
      cout<<endl;
      cout<<"                                             2.Password:";
      cin>>USERPASS;
      cout<<endl;
      //cout<<"*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&&*&*&*&*&*&*&*&*&*&";
      cout<<endl;
      ifstream fileuserid;
      ifstream fileuserpassword;
      size_t pos;
      int count=0;
      int num=0;
      std::string linepassword;
      std::string linepasswordfound;
     

      fileuserid.open("userid.txt");
     
      if(fileuserid.is_open())
      {
            while(getline(fileuserid,linepassword)){
                  
                  //THIS logic checks the position of userid in file using ++ operator program 
                  //is counting position of user id in file for camparing password position
                  count++;
                  pos=linepassword.find(USERID);
                  if(pos!=string::npos){
                        
                        num=count;
                        
                  }
            }
      }
      
      
      fileuserid.close();
      
     
      
      fileuserpassword.open("userpass.txt");
      std::string linepassword1;
      //BELOW LOGIC IS USED TO GET USER PASSWORD WHICH CAN WE COMPARE LATER
      for(int i=1;i<=num;i++)
      {
            std::getline(fileuserpassword,linepassword1);
      }  
      linepasswordfound=linepassword1;
      //password campare
      if(linepasswordfound==USERPASS){
            this->UserLoginMenu();
      }
      else{
            cout<<"                                    wrong password\n";
           UserLoginWindow();
      }
    }

//UserLoginMenu is menu of user functions

void Userlogin::UserLoginMenu()
{
      
      cout<<endl;
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
            cout<<"                        1: VIEW TRAINS"<<endl;
            cout<<"                        2: VIEW BOOKING"<<endl;
        
            cout<<"                        3: ADD BOOKING"<<endl;
            cout<<"                        4: CANCEL BOOKING"<<endl;
            
            cout<<"                        5: LOGOUT"<<endl;
            int choice;
            cin>>choice;
            switch(choice){
                  case 1:
                        this->ViewTrainsUser();
                        break;
                  case 2:
                        this->ViewBookingUser();
                        break;
                  case 3:
                        this->AddBookingUser();
                        break;
                 
                  case 4:
                  this->CancelBookingUser("booking.csv");
                        break;
                  case 5:
                  	cout<<"		********LOGOUT SUCCESSFULL*********";
                  	cout<<endl;
                  exit(0);
                        break;
                  default:
                  	cout<<"		***WRONG CHOICE: Exiting From System***";
                  	exit(0);
                  	
                  	break;      
            }
}

//NewUser Function is used to create new user and save data in userdata.txt

void Userlogin::NewUser()
{
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      fstream userdata;
      userdata.open("userdata.txt",ios::app);
      cout<<endl;
      cout<<endl;
      std::string firstname;
      std::string lastname;
      std::string cityname;
      cout<<"#############################################################################";
      cout<<endl;
      cout<<endl;
      cout<<"                                   USER FIRST NAME:";
      cin>>firstname;
      userdata<<endl;
      userdata<<firstname;
      cout<<endl;
      cout<<endl;
      cout<<"                                   USER LAST NAME:";
      cin>>lastname;
      userdata<<"    ";
      userdata<<lastname;
      cout<<endl;
      cout<<endl;
      cout<<"                                   USER CITY NAME:";
      cin>>cityname;
      userdata<<"     ";
      userdata<<cityname;
      userdata<<"    ";
      char userid[25];
      char pass[25]; 
      char confirmpass[25];
      fstream filepass;
      fstream fileid;
      filepass.open("userpass.txt",ios::app); 
      fileid.open("userid.txt",ios::app);
      cout<<"                              **************SIGN UP*************"<<endl;
      cout<<endl;
      cout<<"                                       New User Id :";
      cin>>userid;
      fileid<<userid<<"\n";
      userdata<<userid;
      cout<<endl;
    
      cout<<"                                        Password :";
           
      cin>>pass;
      cout<<endl;
      cout<<endl; 
      cout<<"                                 Confirm Password:";
      cin>>confirmpass;
      cout<<endl;
      cout<<endl;
      
     
       
       
      filepass<<confirmpass<<"\n";
      userdata<<"    ";
      userdata<<pass;
      fileid.close();
      filepass.close();
      userdata.close();
      cout<<"                                         USER HAS BEEN CREATED";
      this->UserLoginWindow();
      
     

      

}

//ViewTrainsUser function can be used by user go view trains present in system 


void Userlogin::ViewTrainsUser()
{
      std::system("clear");
      cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream trainview;
      std::string readline;
    
      trainview.open("train.csv");
      int count=0;
      string totalline;
      while(getline(trainview,totalline))
      count++;
      trainview.close();
       trainview.open("train.csv");
      int srno=1;
       for(int i=1;i<=count;i++,srno++)
      {
            std::getline(trainview,readline);
            cout<<srno;
            cout<<"     ";
            cout<<readline<<endl; 
      
      

      }
     
      
      this->UserLoginMenu();
}

//AddBookingUser is used by user to book ticket and save data in booking.txt

void Userlogin::AddBookingUser()
{
      std::system("clear");
       
        std::string name;
        
        std::string uniquechar;
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream trainview;
      std::string readline;
      //below logic is used to add booking in file
      trainview.open("train.csv");
      int count=0;
      int end=0;
      string totalline;
      while(getline(trainview,totalline))
      end++;
      trainview.close();
       trainview.open("train.csv");

       for(int i=1;i<=end;i++,count++)
      {

            std::getline(trainview,readline);
            
              

            cout<<readline<<endl; 
      }
      trainview.close();
     
      
    
         
        
            int age;
            char gender[5];
            string date;
            char destination[25],boarding[25];
             int trainno;
             int num;
  
            fstream book;
            
             fstream viewbooking;
            viewbooking.open("booking.csv");
            int totalseat=0;
            string totallines;
            while(getline(viewbooking,totallines)){
            totalseat++;
            }
            viewbooking.close();
            book.open("booking.csv",ios::app);
            //cout<<endl;
            int totalseats;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                    TOTAL SEATS :25";
            cout<<endl;
            cout<<endl;
            cout<<"                    SEATS BOOKED:";
            cout<<totalseat/2;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"            TOTAL SEATS AVAILABLE:";
            cout<<25-(totalseat/2);
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"##########################################################################################";
            cout<<endl;
            cout<<endl;
            
            cout<<"           ***************SEAT BOOKING*****************"<<endl;
            cout<<endl;

            cout<<"               PASSENGER NAME:";
            cin>>name;
            book<<endl;
            book<<name;
            
            cout<<endl;
            cout<<"               AGE :";
            cin>>age;
            book<<age<<",";
            cout<<endl;
            cout<<"               Gender :";
            cin>>gender;
            book<<gender<<",";
            cout<<endl;
            cout<<"               TRAIN NO:";
            cin>>trainno;
            book<<trainno<<",";;
           
            
            cout<<endl;

            cout<<"               BOARDING STATION:";
            cin>>boarding;
            book<<boarding<<",";;
            cout<<endl;
            cout<<"               DESTIONATION STATION:";
            cin>>destination;
            book<<destination<<",";;
            cout<<endl;
            cout<<"                DATE :";
            cin>>date;
            book<<date<<",";;
            cout<<endl;
            cout<<"               Enter aadhar no:";
            std::string aadharno;
            cin>>aadharno;

            
            
            
            
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"     #####*** please note this BOOKING ID for future reference ***#####";
            cout<<endl;
            cout<<endl;
            cout<<endl;
             cout<<"               BOOKING ID:";
            uniquechar=name+aadharno;
            cout<<uniquechar;
            book<<uniquechar<<",";;
            book.close();
            int fare;
            if(trainno==54001)
            {
                  fare=600;
            }
            else if(trainno==54002){
                  fare=700;
            }
             else if(trainno==54003){
                  fare=750;
            }
             else if(trainno==54004){
                  fare=650;
            }
             else if(trainno==54005){
                  fare=690;
            }
             else if(trainno==54006){
                  fare=550;
            }
             else if(trainno==54007){
                  fare=100;
            }
             else if(trainno==54008){
                  fare=900;
            }
             else if(trainno==54009){
                  fare=1000;
            }
            else{
                  fare=800;
            }

            cout<<endl;
            cout<<endl;

           

            cout<<"###################################################################";
            cout<<endl;
            cout<<endl;
            cout<<"         ******************TRAIN FARE****************";
            cout<<endl;
            cout<<endl;
            cout<<"                  GST         :95";
            cout<<endl;
            cout<<"                  INSURANCE   :25";
            cout<<endl;
            cout<<endl;
            cout<<"                  SUB TOTAL   :";
            cout<<fare+95+25;
            cout<<endl;
            cout<<endl;
            cout<<"                  BOOKING SUCCESSFULL";



            
          
            this->UserLoginMenu();
}

//ViewBookingUser is used by user to Vier ticket by unique id

void Userlogin::ViewBookingUser()
{
      
        std::string name;
        
        std::string uniquechar;
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<"          ****ENTER BOOKING ID:";
      cin>>uniquechar;

      ifstream readbooking;
     
      size_t pos;
      int count=0;
      int num=0;
      std::string readline;
      

      readbooking.open("booking.csv");
      
      cout<<endl;
      if(readbooking.is_open())
      {
            while(getline(readbooking,readline)){
                  count++;
                  pos=readline.find(uniquechar);
                  if(pos!=string::npos){
                        
                        num=count;
                        cout<<" ";
                        cout<<readline<<endl;
                  }
            }
      }
      this->UserLoginMenu();
      
}

//CancelBookingUser is used by user to cancel his booking using unique id

void Userlogin::CancelBookingUser(const char *bookingtxt_p)
{
      
        
        std::string uniquechar;
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      cout<<"          ****BOOKING ID:";
      cin>>uniquechar;
      ifstream readfile;
      ofstream writefile;
      size_t pos;
      int count=0;
      int num=0;
      std::string readline;
    
      readfile.open("booking.csv");
      writefile.open("booking.csv",ios::app);
      if(readfile.is_open())
      {
            while(getline(readfile,readline)){
                  count++;
                  pos=readline.find(uniquechar);
                  if(pos!=string::npos){
                        //cout<<g;
                        num=count;
                        cout<<readline<<endl;
                  }
            }
      }
       ifstream is(bookingtxt_p);
  
    
    ofstream ofs;
    ofs.open("temp.csv", ofstream::out);
  
   
    char copy;
    int line_no = 1;
    int position=num;;
    
    

    while (is.get(copy))
    {
  
        if (copy == '\n')
        line_no++;
  
    
        if (line_no != position)
            ofs << copy;
    }
  
   
    ofs.close();
  

    is.close();
  

    remove(bookingtxt_p);
  
    
    rename("temp.csv", bookingtxt_p);
    cout<<endl;
    cout<<endl;
    cout<<"                 BOOKING HAS BEEN CANCELED SUCCESSFULLY"<<endl;
    this->UserLoginMenu();
}

