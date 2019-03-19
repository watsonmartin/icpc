#include <iostream>
#include <vector>
#include <string>


using namespace std;


//return true if name s exists earlier in vector arr
bool backsearch(vector<string> arr, string s){
  int i = arr.size() - 2;
  while(i >= 0){
    if(arr[i].compare(s) == 0){
      return true;
    }
    i--;
  }
  return false;
}

int main(){

  //create variables
  int n;
  vector<string> diary;
  string input;

  //get count
  cin >> n;



  for(int i = 0; i < n; i++){
    cin >> input;
    diary.push_back(input);
    if(backsearch(diary, input)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  
}
