#include <bits/stdc++.h>
using namespace std;

int main(){
    bool aza = true;
    deque<string> ako;
    vector<string> ero;
    while(aza){
        string era;cin>> era;
    
        
        if(era == "exit"){
            ero.push_back("goodbye");
            aza = false;
        }


        if(era== "add_front"){
            string sama;cin >> sama;
            ako.push_front(sama);
            ero.push_back("ok");
            
        }


        if(era== "add_back"){
            string sama;cin >> sama;
            ako.push_back(sama);
            ero.push_back("ok");
        }


        if(era == "erase_front"){
            if(!ako.empty()){
                ero.push_back(ako.front());
                ako.pop_front();
            }
            else{
                ero.push_back("error");
            }
        }


        if(era == "erase_back"){
            if(!ako.empty()){
                ero.push_back(ako.back());
                ako.pop_back();
            }
            else{
                ero.push_back("error");
            }
        }


        if(era == "clear"){
            while(!ako.empty()){
                ako.pop_back();
            }
            ero.push_back("ok");
        }


        if(era == "front"){
            if(!ako.empty()){
                ero.push_back(ako.front());
            }
            else{
                ero.push_back("error");
            }
        }


        if(era == "back"){
            if(!ako.empty()){
                ero.push_back(ako.back());
            }
            else{
                ero.push_back("error");
            }
        }
    }
    for(int i=0;i<ero.size();i++){
        cout << ero[i] << endl;
    }
}


