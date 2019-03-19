#include <iostream>
#include <vector>

using namespace std;


void remove_max(vector<int> &arr){
  int result = arr[0];
  int index = 0; 
  for(int i = 1; i < arr.size(); i++){
    if(arr[i] > result){
      result = arr[i];
      index = i;
    }
  }
  arr.erase(arr.begin()+index);
}


void remove_min(vector<int> &arr){
  int result = arr[0];
  int index = 0; 
  for(int i = 1; i < arr.size(); i++){
    if(arr[i] < result){
      result = arr[i];
      index = i;
    }
  }
  arr.erase(arr.begin()+index);
}


int main(){
  int n;
  cin >> n;
  vector<int> game;
  int entry;
  for(int i = 0; i < n; i++){
    cin >> entry;
    game.push_back(entry);
  }

  for(int i = 0; i < n-1; i++){
    if(i%2 == 0){
      remove_max(game);
    } else {
      remove_min(game);
    }
  }
  cout << game[0] << endl;
  return 0;
}

