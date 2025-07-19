#include"train.h"
#include"AddTrainClass.h"
#include<vector>
void Trainclass::ViewTrains()
{
      std::system("clear");
      cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
       ifstream viewtrain;
      std::string readline;
      viewtrain.open("train.csv");
      int count=1;
      int end=0;
      string totalline;
      while(getline(viewtrain,totalline))
      end++;
      viewtrain.close();
       viewtrain.open("train.csv");
       for(int i=1;i<=end;i++,count++)
      {

            std::getline(viewtrain,readline);
            
            cout<<count;   
            cout<<" "; 

            cout<<readline<<endl; 
      }
      viewtrain.close();
     
      
      this->TrainMenu();
}

// DeleteTrainsAdmin delete train data from train.txt
void Trainclass::DeleteTrains(const char *traintxt_p)
{
      std::system("clear");
        cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
       
        ifstream viewtrain;
      std::string readline;
      viewtrain.open("train.csv");
      int count=1;
      int end=0;
      string totalline;
      while(getline(viewtrain,totalline))
      end++;
      viewtrain.close();
       viewtrain.open("train.csv");
       for(int i=1;i<=end;i++,count++)
      {
            std::getline(viewtrain,readline);
            
            cout<<count;
            cout<<" "; 
            cout<<readline<<endl; 
      }
	viewtrain.close();
       ifstream is(traintxt_p);
  
    
    ofstream temporary;
    temporary.open("temp.csv", ofstream::out);
  
   
    char copy;
    int line_no = 1;
    int SRNO;
    cout<<"ENTER THE SR-NO OF THE TRAIN DETAIL YOU WANT TO DELETE"<<endl;
    cin>>SRNO;
    

    while (is.get(copy))//using get char c "c=null" after which it copying data of temporary to c char
    {
  
        if (copy == '\n')
        line_no++;
  
    
        if (line_no != SRNO)
            temporary << copy;
    }
  
   
    temporary.close();
  

    is.close();
  

    remove(traintxt_p);
  
    
    rename("temp.csv", traintxt_p);//renaming temp.txt to train.txt
    cout<<"                 TRAIN HAS BEEN DELEATED SUCCESSFULLY"<<endl;
    cout<<endl;
    this->ViewTrains();
}

//this function add train in train.txt

void Trainclass::AddTrains()
{
std::system("clear");
  cout<<"##############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<endl;
      ifstream viewtrain;
      std::string readline;
      viewtrain.open("train.csv");
      int count=1;
      int end=0;
      string totalline;
      while(getline(viewtrain,totalline))
      end++;
      viewtrain.close();
       viewtrain.open("train.csv");
       for(int i=1;i<=end;i++,count++)
      {

            std::getline(viewtrain,readline);

            cout<<count;
            cout<<" ";
            cout<<readline<<endl;
      }
      viewtrain.close();
      fstream addtrain;
     
      vector<AddTrainClass> *details=new vector<AddTrainClass>;
      addtrain.open("train.csv",ios::app);
      cout<<endl;
      cout<<endl;
      cout<<"#################################################################################";
      cout<<endl;
      cout<<endl;
      AddTrainClass objj;

      cout<<"                           ADD TRAIN NO:";
      //cin>>trainno;
      cin>>objj.trainNo;
   //	 addtrain<<endl;
      //addtrain<<trainno<<",";
      cout<<endl;
      cout<<"                           TRAIN NAME:";
      //cin>>trainname;
      addtrain<<"          ";
      cin>>objj.trainname;
      //addtrain<<trainname<<",";;
      cout<<endl;
      cout<<"                           FROM:";
      //cin>>from;
      cin>>objj.from;
      //addtrain<<"     ";
      //addtrain<<from<<",";;
      cout<<endl;
      cout<<"                      DEPARTURE TIME:";
      cin>>objj.starttime;
      cout<<endl;
      //addtrain<<"    ";
      //addtrain<<starttime<<",";;
      cout<<"                          DESTINATION:";
      cin>>objj.to;
      //addtrain<<"    ";
      //addtrain<<to<<",";;
      cout<<endl;
      cout<<"                         ARRIVAL TIME:";
      cin>>objj.reachtime;
      //addtrain<<"    ";
      //addtrain<<reachtime<<",";;
      details->push_back(objj);
      addtrain<<details;
      addtrain.close();
      cout<<endl;
      cout<<endl;
      cout<<"                          TRAIN HAS BEEN ADDED SUCCESSFULLY";
      cout<<endl;
      cout<<endl;
      this->TrainMenu();
}
void Trainclass::TrainMenu()
{
      
      cout<<endl;
      cout<<endl;
      cout<<"############################################################################################";
      cout<<endl;
      cout<<endl;
      cout<<"********************************************************************************************";
      cout<<endl;
      cout<<endl;
      cout<<"################################         BOOKING MENU        #########################";
      cout<<endl;
      cout<<endl;
      cout<<"                                   1.VIEW TRAINS:";
      cout<<endl;
      cout<<endl;
      cout<<"                                   2.ADD TRAIN:";
      cout<<endl;
      cout<<endl;
      cout<<"                                   3.DELETE TRAIN:";
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
             ViewTrains();

            break;
      case 2:
            AddTrains();
            break;
      case 3:
            DeleteTrains("train.csv");    
            break;
            
      case 4:
            exit(0); 
            break;             
      default:
            cout<<"                 Wrong Choice";
            cout<<endl;
            cout<<endl;
                        this->TrainMenu();
            break;
      }
}
