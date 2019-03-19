#include <iostream>


using namespace std;


int main(){
  int n;
  int a_rec = 0;
  int a_total = 0;
  int b_rec = 0;
  int b_total = 0;
  int t;
  int entry;

  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> t;
    if(t == 1){
      cin >> entry;
      a_rec += entry;
      a_total += entry;
      cin >> entry;
      a_total += entry;
    } else {
      cin >> entry;
      b_rec += entry;
      b_total += entry;
      cin >> entry;
      b_total += entry;
    }
  }

  if(((double)a_rec/(double)a_total) >= 0.5){
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }

  if(((double)b_rec/(double)b_total) >= 0.5){
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }
  
}
