#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  int entry;
  int last;
  int total = 1;
  vector<int> step_counts;
  
  cin >> n;
  cin >> entry;

  for(int i = 0; i < n-1; i++){
    last = entry;
    cin >> entry;
    if(entry == 1){
      total++;
      step_counts.push_back(last);
    }
  }
  step_counts.push_back(entry);


  //print results
  cout << total << endl;
  for(int i = 0; i < step_counts.size(); i++){
    cout << step_counts[i] << " ";
  }
  cout << endl;
  
}
