// This is a problemd that I've uploaded to HackerRank and can be found at:
// https://www.hackerrank.com/contests/packet-processing-context/challenges/packet-processing/problem

#include <iostream>
#include <stdio.h> // stdin
#include <cstdlib> // getenv
#include <string>

using namespace std;

class P {
public:
    int ti;
    int li;
};

int N;
P ps[1000];

void read(){
    cin >> N;
    
    P p;
    for(int i = 0; i < N; i++){
        cin >> p.ti >> p.li;
        ps[i] = p;
    }
}

bool cpu_1(){
    int i = 1, ni = 0, cpu = 0;
    
    for(i = 1; i <= 5000; i++){
        while(ps[ni].ti == i){
            cpu += ps[ni].li;
            
            if(cpu > 10){
                return false;
            } else if(ni < N){
                ni++;
            } else {
                return true;
            }
        }
        
        if(cpu > 0){
            cpu--;
        }
    }
    
    return true;
}

bool cpu_2(int i = 1, int ni = 0, int cpu1 = 0, int cpu2 = 0){
    if(ni == 0){
        if(cpu_2(1, ni+1, cpu1 + ps[ni].li, 0) ||
           cpu_2(1, ni+1, 0, cpu2 + ps[ni].li)){
            return true;
        }else{
            return false;
        }
    } else{
        for(int j = i; j <= 5000; j++){
            while(ps[ni].ti == j){
                if(cpu1 > 10 || cpu2 > 10){
                    return false;
                }
                
                if(ni < N){
                    if (cpu_2(j, ni+1, cpu1 + ps[ni].li, cpu2) ||
                        cpu_2(j, ni+1, cpu1, cpu2 + ps[ni].li)){
                        return true;
                    }else{
                        return false;
                    }
                } else {
                    return true;
                }
            }
            
            if(cpu1 > 0) cpu1--;
            if(cpu2 > 0) cpu2--; 
        }
        
        return true;
    }
}

void solve()
{
    // My solution goes here
    read();
    
    int result = -1;
    if(cpu_1()){
        result = 1;
    } else if(cpu_2()){
        result = 2;
    }
    cout << result;
}

int main()
{

    if (getenv("IS_DEBUG"))
    {
        string fullFileName(__FILE__);
        string fileNameWithoutExtension = fullFileName.substr(0, fullFileName.rfind('.'));
        string inputFileName = fileNameWithoutExtension.append(".input");

        freopen(inputFileName.c_str(), "r", stdin);
    }

    int start = clock();
    solve();
    int end = clock();

    // Workaround for issue
    // https://github.com/Microsoft/vscode-cpptools/issues/466
    if (getenv("IS_DEBUG"))
    {
        cout << endl
             << "[Finished in " << end - start << " ms]" << endl;
    }

    return 0;
}