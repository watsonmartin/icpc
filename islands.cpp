#include <iostream>

using namespace std;

int rows;
int cols;
int count;
char ** map;

bool inBounds(int x, int y){
  if(x >= rows){
    return false;
  }
  if(y >= cols){
    return false;
  }
  return true;
}

void print(){
  for(int x = 0; x < rows; x++){
    for(int y = 0; y < cols; y++){
      cout << map[x][y];
    }
    cout << endl;
  }
}

void check(int x, int y){

  map[x][y] = 'X';

  if(inBounds(x+1, y)){
    if(map[x+1][y] == 'C' || map[x+1][y] == 'L'){
      map[x+1][y] = 'X';
    }
  }
  if(inBounds(x, y+1)){
    if(map[x][y+1] == 'C' || map[x][y+1] == 'L'){
      map[x][y+1] = 'X';
    }
  }
}

int main(){
  count = 0;
  cin >> rows;
  cin >> cols;

  map = new char * [rows];
  for(int i = 0; i < rows; i++){
    map[i] = new char[cols];
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cin >> map[i][j];
    }
  }

  //  cout << "Before:" << endl;
  //  print();

  for(int x = 0; x < rows; x++){
    for(int y = 0; y < cols; y++){
      if(map[x][y] == 'L'){
	count++;
	check(x, y);
      }
      if(map[x][y] == 'X'){
	check(x, y);
      }
    }
  }
  //  cout << "\nAfter: " << endl;
  //  print();

  cout << count;
}
