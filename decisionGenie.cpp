#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<windows.h>

using namespace std;

int main(){
    srand(time(0));
    char again='y';

    cout<<"================================\n";
    cout<<"         Welcome to\n";
    cout<<"        DecisionGenie\n";
    cout<<"================================\n";
    cout << "[INFO] Sometimes a little nudge is all we need to get started.\n";
    cout<<"[TIP] It's not about you can't decide it's about not overthinking every time.\n";
    Sleep(5000);

    while(again=='y'|| again=='Y'){
        int n;
        cout<<"\nEnter the number of choices : ";
        cin>>n;
        cin.ignore();

        vector<string> options;
        vector<int> weights;
        
        for(int i=1;i<=n;i++){
            int weight;
            string option;

            cout<<"Enter option "<<i<<": ";
            getline(cin,option);
            
            cout<<"Enter weight to this option (1=least, higher = more likely): ";
            cin>>weight;
            if(weight>100){
                cout<<"[INFO] Weight capped at 100 for balance,\n";
                weight=100;
            }
            else if(weight<1){
                cout<<"[INFO] Weight too low. Setting to 1 by default.\n";
                weight=1;
            }
            cin.ignore();
            
            options.push_back(option);
            weights.push_back(weight);
        }

        vector<string> weightedList;
        for(int i=0;i<n;i++){
            for(int j=0;j<weights[i];j++){
                weightedList.push_back(options[i]);
            }
        }

        cout<<"\n[Genie] Summoning your decision";
        for(int i=0;i<3;i++){
            cout<<".";
            cout.flush();
            Sleep(800);
            // if cross platform std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }


        vector<string> phrases{
            "\n[Genie] Hmm... tricky one!",
            "\n[Genie] Rolling my invisible dice...",
            "\n[Genie] Reading your mental chaos",
            "\n[Genie] Consulting the stars..."
            
        };
        
        int phraseIndex = rand()% phrases.size();
        cout<<phrases[phraseIndex]<<"\n";
        Sleep(2000);

        if(weightedList.empty()){
            cout<<"\nNo valid option provided.\n";
        }else{
            int choice=rand()%weightedList.size();
            cout<<"You should: "<<weightedList[choice]<<"\n";

        }
       
        cout<<"\nDo you want to make another decision? (y/n): ";
        cin>>again;
        cin.ignore();
    }

    cout<<"\nThanks for using DecisionGenie! Stay decisive !\n";

    return 0;
}
