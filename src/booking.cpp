#include"booking.h"
// AddBookingAdmin in this fuction admin can book seat and save it in booking.txt

void Bookingclass::AddBooking()
{
    
     std::string name;
     std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream viewtrain;
      std::string trainline;
      viewtrain.open("train.csv");
      int count=0;
      int end=0;
      string totalline;
      while(getline(viewtrain,totalline))
      end++;
      viewtrain.close();
       viewtrain.open("train.csv");
       for(int i=1;i<=end;i++,count++)
      {

            std::getline(viewtrain,trainline);
            
                

            cout<<trainline<<endl; 
      }
      viewtrain.close();
     
      
    
           // char ame[25];
            int age;
            char gender[5];
            string date;
            char destination[25],boarding[25];
             int trainno;
             int fare;
  
            fstream booking;
            fstream viewbooking;
            viewbooking.open("booking.csv");
            int totalseat=0;
            string totallines;
            while(getline(viewbooking,totallines)){
            totalseat++;
            }
            viewbooking.close();
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
            booking.open("booking.csv",ios::app);
            
            
            cout<<"           ***************SEAT BOOKING*****************"<<endl;
            cout<<endl;
            cout<<endl;

            cout<<"               PASSENGER NAME:";
            cin>>name;
            booking<<endl;
            booking<<name<<",";;
            
            cout<<endl;
            cout<<"               AGE :";
            cin>>age;
            booking<<age<<",";;
            cout<<endl;
            cout<<"               Gender :";
            cin>>gender;
            booking<<gender<<",";;
            cout<<endl;
            cout<<"               TRAIN NO:";
            cin>>trainno;
            booking<<trainno<<",";;
           
            
            cout<<endl;
            cout<<"               BOARDING STATION:";
            cin>>boarding;
            booking<<boarding<<",";;
            cout<<endl;
            cout<<"               DESTIONATION STATION:";
            cin>>destination;
            booking<<destination<<",";;
            cout<<endl;
            cout<<"                DATE :";
            cin>>date;
            booking<<date<<",";;
            cout<<endl;
            cout<<"ENTER LAST FOUR DIGITS OF AADHAR NUMBER:";
            std::string aadharno;
            
            cin>>aadharno;

            
            
            
            
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"             #####*** please note this BOOKING ID"; 
            cout<<"                  for future reference ***#####";
            cout<<endl;
            cout<<endl;
            cout<<endl;
             cout<<"               BOOKING ID:";
            BOOKINGID=name+aadharno;
            cout<<BOOKINGID;
            booking<<BOOKINGID<<",";
            
            
          

             
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
            booking.close();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                 SEAT HAS BEEN CONFIRMED";
            cout<<endl;
           
            
            this->ViewBooking();

}

// DeleteBookingAdmin can be used by admin to cancel booking and save data in booking.txt

void Bookingclass::DeleteBooking( const char *bookingtxt_p)
{
   
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream viewbooking;
      std::string readline;
      viewbooking.open("booking.csv");
      int count=1;
      int end=0;
      string totalline;
      while(getline(viewbooking,totalline))
      end++;
      viewbooking.close();
       viewbooking.open("booking.csv");
       for(int i=1;i<=end;i++,count++)
      {
            std::getline(viewbooking,readline);
            
            cout<<count;
            cout<<"  ";
            cout<<readline<<endl; 
      }
      viewbooking.close();
      ifstream is(bookingtxt_p);
  
    
    ofstream compare;
    compare.open("temp.txt", ofstream::out);
  
   
    char copy;
    int line_no = 1;
    int num;
    cout<<"ENTER THE SR-NO OF THE BOOKING YOU WANT TO DELETE "<<endl;
    cin>>num;
    

    while (is.get(copy))
    {
  
        if (copy == '\n')
        line_no++;
  
    
        if (line_no != num)
            compare << copy;
    }
  
   
    compare.close();
  

    is.close();
  

    remove(bookingtxt_p);
  
    
    rename("temp.txt", bookingtxt_p);
    cout<<"                                Reservation has been Cancelled"<<endl;
    this->ViewBooking();
}

//ViewBookingAdmin can be used by admin to view booked seats in booking.txt

void Bookingclass::ViewBooking()
{
          


   // std::system("clear");
    cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream viewbooking;
      std::string readline;
      viewbooking.open("booking.csv");
      int end=0;
      string totalline;
      while(getline(viewbooking,totalline))
      end++;
      viewbooking.close();
       viewbooking.open("booking.csv");
       int srno=1;
           
       for(int i=1;i<=end;i++,srno++)
      {
            std::getline(viewbooking,readline);
            cout<<srno;
            cout<<"     ";
            cout<<readline<<endl; 
      }
      this->BookingMenu();

}
void Bookingclass::BookingMenu()
{
      
      cout<<endl;
      cout<<endl;
      cout<<"############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<"********************************************************************************************";
      cout<<endl;
      cout<<endl;
      cout<<"################################         BOOKING MENU        ###############################";
      cout<<endl;
      cout<<endl;
      cout<<"                                   1.VIEW BOOKING:";
      cout<<endl;
      cout<<endl;
      cout<<"                                   2.ADD BOOKING:";
      cout<<endl;
      cout<<endl;
      cout<<"                                   3.Cancel Booking:";
      cout<<endl;
      cout<<endl;
      
      cout<<"                                   4.EXIT";
      cout<<endl;
      cout<<endl;
      cout<<"############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<"********************************************************************************************";
      cout<<endl;
      cout<<endl;
      int num;
      cout<<"                       CHOOSE ANY ONE:";
      cin>>num;
      
      switch (num)
      {
      case 1:
            ViewBooking();

            break;
      case 2:
            AddBooking();
            break;
      case 3:
            DeleteBooking("booking.csv");    
            break;
      case 4:
            exit(0); 
            break;             
      default:
            cout<<"                 Wrong Choice";
            cout<<endl;
            cout<<endl;
                        //this->BookingMenuAdmin();
            break;
      }
}






