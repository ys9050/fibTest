#include <iostream>
#include <ctime>
#include <map>

double fibBrute (int x);
double fibMemo (int x);

using namespace std;

int main () {
  
    int i;
    time_t t1, t2, t3;

    cout << "This program will calculate running time of brute and memo version of Fib. seq." << endl;
    
    cout << "enter number " << endl;

    cin >> i;
    
    t1=clock();
    double brute = fibBrute(i);
    cout << brute << endl;
    t2 = clock();

    double memo = fibMemo(i);
    cout << memo << endl;
    t3 = clock();
    
    cout << "Time it took to brute force it " << ((float)t2-(float)t1) << endl;
    cout << "Time it took to memoize it " << ((float)t3-(float)t2) << endl;

    return 0;
}


double fibBrute (int x) {
    
    double temp;

    if(x==1 || x==2) temp=1;
    else{
        temp = fibBrute(x-1) + fibBrute(x-2);
    }

    return temp;
}

double fibMemo (int x) {
  
    static map <int,double> memo;


    if(x==1 || x==2) return 1;
    else if (memo[x] > 0) return memo[x];
    else{
        
        double temp = fibMemo(x-1)+fibMemo(x-2);
        
        memo[x] = temp;
        return temp;

    }
    
}

