#include <bits/stdc++.h>
using namespace std;
void ako(deque<int>& barsik, deque<int>& nursik, int bbb){
    int check = 0;
    while(!barsik.empty() && !nursik.empty() && check < 1000000){
        int barsik_element = barsik.front();
        int nursik_element = nursik.front();
        barsik.pop_front();
        nursik.pop_front();
        if(barsik_element == 0 && nursik_element==9 || barsik_element == 9 && nursik_element== 0){
                if(barsik_element == 0){
                    barsik.push_back(barsik_element);
                    barsik.push_back(nursik_element);
                    bbb++;
                    }

                else if(nursik_element==0){
                    nursik.push_back(barsik_element);
                    nursik.push_back(nursik_element);
                    bbb++;
                    }
            check++;
            }
        else{
            if(barsik_element > nursik_element){
                barsik.push_back(barsik_element);
                barsik.push_back(nursik_element);
                bbb++;
                }
            else{
    
                nursik.push_back(barsik_element);
                nursik.push_back(nursik_element);
                bbb++;
                }
            }
            check++;
        }
          
    
    
    if(barsik.empty()){
        cout<< "Nursik" << " " << bbb;
    }
    else if(nursik.empty()){
        cout<< "Boris" << " " << bbb;
    }
    else{
        cout << "blin nichya";
    }
}

int main(){
    deque<int> barsik;
    deque<int> nursik;

    int bbb = 0;
    int nnn = 0;
    
    
    for(int i=0; i<5;i++){
        int a;cin>> a;
        barsik.push_back(a);
        }




    for(int j=0; j<5;j++){
        int b; cin >> b;
        nursik.push_back(b);
        }
    ako(barsik, nursik, bbb);
}


/*
#include <iostream>
#include <deque>
#include <map>

int main() {
    std::deque<int> boris, nursik;
    std::map<int, int> card_strength = {{0, 10}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    int card;

    // Ввод карт Бориса
    std::cout << "barsik: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> card;
        boris.push_back(card);
    }

    // Ввод карт Нурсика
    std::cout << "nursik: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> card;
        nursik.push_back(card);
    }

    int rounds = 0;
    while (!boris.empty() && !nursik.empty() && rounds < 1000000) {
        int boris_card = boris.front();
        int nursik_card = nursik.front();
        boris.pop_front();
        nursik.pop_front();

        if (card_strength[boris_card] > card_strength[nursik_card]) {
            boris.push_back(boris_card);
            boris.push_back(nursik_card);
        } else {
            nursik.push_back(boris_card);
            nursik.push_back(nursik_card);
        }

        ++rounds;
    }

    if (boris.empty()) {
        std::cout << "nursik win" << std::endl;
    } else if (nursik.empty()) {
        std::cout << "borsik win" << std::endl;
    } else {
        std::cout << "draw" << std::endl;
    }

    return 0;
}
*/