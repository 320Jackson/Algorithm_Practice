#include<iostream>
using namespace std;

int* Sort(int *Start, int Left, int *End, int Right){
    int *HalfL, *HalfR;
    /*Recursive Split*/
    if(Left > 1){
        int Half = (Left / 2) + (Left % 2);
        int Other = (Left / 2);
        HalfL = Sort(&Start[0], Half, &Start[Half], Other);
    }
    else{
        HalfL = Start;
    }
    if(Right > 1){
        int Half = (Right / 2) + (Right % 2);
        int Other = (Right / 2);
        HalfR = Sort(&End[0], Half, &End[Half], Other);
    }
    else{
        HalfR = End;
    }

    /*Merge back*/
    int CountLeft = 0, CountRight = 0;
    int *RunLeft = &HalfL[0];
    int *RunRight = &HalfR[0];

    /*Constract output array*/
    int Totol = Left + Right;
    int *Output = new int[Totol];
    for(int Run = 0; Run < Totol; Run++){
        //cout << *RunLeft << " " << *RunRight;
        if(*RunLeft <= *RunRight){
            Output[Run] = *RunLeft;            
            if(CountLeft < Left - 1){
                RunLeft += 1;
                CountLeft += 1;
            }
            else{
                if(CountRight < Right - 1){
                    RunLeft = RunRight;
                    RunRight += 1;
                    CountRight += 1;
                }
                else{
                    *RunLeft = *RunRight + 1;
                }
            }
        }
        else if(*RunRight < *RunLeft){
            Output[Run] = *RunRight;
            if(CountRight < Right - 1){
                RunRight += 1;
                CountRight += 1;
            }
            else{
                if(CountLeft < Left - 1){
                    RunRight = &HalfL[Left - 1];
                }
                else{
                    *RunRight = *RunLeft + 1;
                }
            }
        }
    }
    if(HalfL != Start){
        delete HalfL;
    }
    if(HalfR != End){
        delete HalfR;
    }
    return Output;
}

int main(){
    /*Totol data number*/
    int int_n;
    cin >> int_n;

    /*Input Data*/
    int *Data = new int[int_n];
    for(int Run = 0; Run < int_n; Run++){
        cin >> Data[Run];
    }

    /*Sort*/
    int Half = (int_n / 2) + (int_n % 2);
    int Other = int_n / 2;
    int *Output = Sort(&Data[0], Half, &Data[Half], Other);
    delete Data;

    /*Output*/
    for(int Run = 0; Run < int_n; Run++){
        cout << Output[Run] << " ";
    }
    cout << "\n";
    delete Output;

    system("PAUSE");
    return 0;
}