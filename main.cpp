#include<bits/stdc++.h>
using namespace std ;

void FCFS(vector<int>&seq,int HP)//HP --> head position
{
    int sum = 0 ;
    sum+=abs(HP-seq[0]) ;
    cout<<"\n--------------------------------------------------------------------\n" ;
    cout<<"Head"<<"        "<<"From"<<"          "<<"To"<<"       "<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;

    for(int i=1;i<seq.size();i++)
    {
        sum+=abs(seq[i]-seq[i-1]) ;
        //cout<<"("<<seq[i-1]<<" , "<<seq[i]<<" )"<<endl;
        cout<<seq[i-1]<<"          "<<seq[i-1]<<"           "<<seq[i]<<"       "<<endl ;
    }
    cout<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
    cout<<"The Seek time is : "<<sum<<"\tUsing the FCFS method"<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
}

void SSTF(vector<int>&seq,int HP)
{
    int N = seq.size() ;
    seq.push_back(HP) ;
    sort(seq.begin(),seq.end()) ;
    int sum = 0 ;
    vector<int>::iterator it ;
    int SecHead ;

    //map<int,int>diff ;
    int temp ;

    cout<<"\n--------------------------------------------------------------------\n" ;
    cout<<"Head"<<"        "<<"From"<<"          "<<"To"<<"       "<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
    while(seq.size()!=1)
    {
        it = lower_bound(seq.begin(),seq.end(),HP) ;

        temp = it-seq.begin() ;


        if( (seq[temp]-seq[temp-1]) < (seq[temp+1]-seq[temp]) )
            SecHead = seq[temp-1] ;
        else
            SecHead = seq[temp+1] ;
        
        if( SecHead == 0 )
        {
            SecHead = seq[temp+1] ;
        }   
        cout<<HP<<"          "<<HP<<"           "<<SecHead<<"       "<<endl ;
        sum+=abs(HP-SecHead) ;
        seq.erase(it) ;
        HP = SecHead ;
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------------\n" ;
    cout<<"The Seek time is : "<<sum<<"\tUsing the SSTF method"<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
}

void SCAN(vector<int>&seq,int HP)
{
    int sum = 0 ;
    int N = seq.size() ;
    int SecHead ;
    int track,prt ;
    cout<<"Enter the number of tracks\n";
    cin>>track ;
    cout<<endl<<endl ;
    seq.push_back(track-1) ;
    seq.push_back(0) ;
    sort(seq.begin(),seq.end()) ;
    cout<<"Enter the priority for direction :\n\t\t\t1: Smaller first\n\t\t\t2: Larger First\n" ;
    cin>>prt ;
    cout<<endl<<endl;

    cout<<"\n--------------------------------------------------------------------\n" ;
    cout<<"Head"<<"        "<<"From"<<"          "<<"To"<<"       "<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;

    if( prt == 1 )
    {
        vector<int>::iterator it ;
        it = lower_bound(seq.begin(),seq.end(),HP) ;
        SecHead = it-seq.begin() ;

        for(int i=SecHead-1;i>=0;i--)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[i]<<"       "<<endl ; 

            sum+=abs(HP-seq[i]) ;
            HP = seq[i] ;

        }
        //seq[SecHead] = 0 ;
        HP = 0 ;
        for(int k=SecHead+1;k<=N;k++)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[k]<<"       "<<endl ; 

            sum+=abs(HP-seq[k]) ;
            HP = seq[k] ;
        }


    }
    else if( prt == 2 )
    {
        vector<int>::iterator it ;
        it = lower_bound(seq.begin(),seq.end(),HP) ;
        SecHead = it-seq.begin() ;


        for(int k=SecHead;k<=N+1;k++)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[k]<<"       "<<endl ; 

            sum+=abs(HP-seq[k]) ;
            HP = seq[k] ;
        }

        for(int i=SecHead-1;i>0;i--)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[i]<<"       "<<endl ; 

            sum+=abs(HP-seq[i]) ;
            HP = seq[i] ;

        }
    }
    else
    {
        cout<<"Please enter the correct option\n" ;
        return ;
    }

    cout<<endl;
    cout<<"--------------------------------------------------------------------\n" ;
    cout<<"The Seek time is : "<<sum<<"\tUsing the SCAN method"<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
}
void C_SCAN(vector<int>&seq,int HP)
{
        int sum = 0 ;
    int N = seq.size() ;
    int SecHead ;
    int track,prt ;
    cout<<"Enter the number of tracks\n";
    cin>>track ;
    cout<<endl<<endl ;
    seq.push_back(track-1) ;
    seq.push_back(0) ;
    sort(seq.begin(),seq.end()) ;
    cout<<"Enter the priority for direction :\n\t\t\t1: Smaller first\n\t\t\t2: Larger First\n" ;
    cin>>prt ;
    cout<<endl<<endl;

    cout<<"\n--------------------------------------------------------------------\n" ;
    cout<<"Head"<<"        "<<"From"<<"          "<<"To"<<"       "<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;

    if( prt == 1 )
    {
        vector<int>::iterator it ;
        it = lower_bound(seq.begin(),seq.end(),HP) ;
        SecHead = it-seq.begin() ;

        for(int i=SecHead-1;i>=0;i--)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[i]<<"       "<<endl ; 

            sum+=abs(HP-seq[i]) ;
            HP = seq[i] ;

        }
        HP = seq[0] ;
        for(int k=N+1;k>=SecHead;k--)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[k]<<"       "<<endl ; 

            sum+=abs(HP-seq[k]) ;
            HP = seq[k] ;
        }


    }
    else if( prt == 2 )
    {
        vector<int>::iterator it ;
        it = lower_bound(seq.begin(),seq.end(),HP) ;
        SecHead = it-seq.begin() ;


        for(int k=SecHead;k<=N+1;k++)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[k]<<"       "<<endl ; 

            sum+=abs(HP-seq[k]) ;
            HP = seq[k] ;
        }
        cout<<HP<<"          "<<HP<<"           "<<"0"<<"       "<<endl ; 
        sum+=abs(HP) ;
        HP = seq[0] ;
        for(int i=1;i<SecHead;i++)
        {
            cout<<HP<<"          "<<HP<<"           "<<seq[i]<<"       "<<endl ; 

            sum+=abs(HP-seq[i]) ;
            HP = seq[i] ;

        }
    }
    else
    {
        cout<<"Please enter the correct option\n" ;
        return ;
    }

    cout<<endl;
    cout<<"--------------------------------------------------------------------\n" ;
    cout<<"The Seek time is : "<<sum<<"\tUsing the SCAN method"<<endl ;
    cout<<"--------------------------------------------------------------------\n" ;
}
int main()
{
    vector<int>seq = {82,170,43,140,24,16,190};
    int HP ;

    cout<<"Enter the HEAD POSITION \n" ;
    cin>>HP ;


    int choise = 1 ;
    cout<<"\n\nEnter the choise \n\n";
    cout<<"1    :   FCFS\n";
    cout<<"2    :   SSTF\n";
    cout<<"3    :   SCAN\n";
    cout<<"4    :   C_SCAN\n";
    cout<<"5    :   End Program \n\n\n";
    cin>>choise ;
    
    while( choise != 5 )
    {
        switch (choise)
        {
        case 1:
            FCFS(seq,HP) ;
            break;
        case 2:
            SSTF(seq,HP) ;
            break ;
        case 3:
            SCAN(seq,HP);
            break;
        case 4:
            C_SCAN(seq,HP);
        case 5 :
            break ;
        default:
            break;
        }
        cout<<"\n\n\nEnter the choise \n\n";
            cout<<"1    :   FCFS\n";
            cout<<"2    :   SSTF\n";
            cout<<"3    :   SCAN\n";
            cout<<"4    :   C_SCAN\n";
            cout<<"5    :   End Program \n\n\n";
            cin>>choise ;

    }

    return 0 ;
}
