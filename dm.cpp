#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node{
  int x;
  int y;
  int z;
  int pathcost;
};


void print3Darray(char *** arr, int z, int x, int y){
  for(int l = 0; l < z; l++){
    cout << endl;
    for(int r = 0; r < x; r++){
      for(int c = 0; c < y; c++){
	cout << arr[l][r][c];
      }
      cout << endl;
    }
  }
}

void getStart(char *** arr, int z, int x, int y, struct node * start){
 for(int l = 0; l < z; l++){
   for(int r = 0; r < x; r++){
      for(int c = 0; c < y; c++){
	if(arr[l][r][c] == 'S'){
	  start->z = l;
	  start->x = r;
	  start->y = c;
	  start->pathcost = 0;
	}
      }
   }
 }
}

void getMoves(char *** arr, int z, int x, int y, struct node * n, queue<struct node*> & q){
  struct node * add;
  int curX = n->x;
  int curY = n->y;
  int curZ = n->z;
  int curPath = n->pathcost + 1;
  if(((curZ + 1) < z) && (arr[curZ+1][curX][curY] != '#')){
    add = new struct node;
    add->x = curX;
    add->y = curY;
    add->z = curZ+1;
    add->pathcost = curPath;
    q.push(add);
  }
  if(((curZ - 1) > 0) && (arr[curZ-1][curX][curY] != '#')){
    add = new struct node;
    add->x = curX;
    add->y = curY;
    add->z = curZ-1;
    add->pathcost = curPath;
    q.push(add);
  }
  if(((curX + 1) < x) && (arr[curZ][curX+1][curY] != '#')){
    add = new struct node;
    add->x = curX+1;
    add->y = curY;
    add->z = curZ;
    add->pathcost = curPath;
    q.push(add);
  }
  if(((curX - 1) > 0) && (arr[curZ][curX-1][curY] != '#')){
    add = new struct node;
    add->x = curX-1;
    add->y = curY;
    add->z = curZ;
    add->pathcost = curPath;
    q.push(add);
  }
  if(((curY + 1) < y) && (arr[curZ][curX][curY+1] != '#')){
    add = new struct node;
    add->x = curX;
    add->y = curY+1;
    add->z = curZ;
    add->pathcost = curPath;
    q.push(add);
  }
  if(((curY - 1) > 0) && (arr[curZ][curX][curY-1] != '#')){
    add = new struct node;
    add->x = curX;
    add->y = curY-1;
    add->z = curZ;
    add->pathcost = curPath;
    q.push(add);
  }
}

int main(){
  //initialize main values
  int minutes;
  int x;
  int y;
  int z;
  char *** dungeon; //3D array
  //run till done
  while(true){
    cin >> z;
    cin >> x;
    cin >> y;
    if(x == 0 && y == 0 && z == 0) break; //break if done

    //allocate 3D array
    dungeon = new char **[z];
    for(int i = 0; i < x; i++){
      dungeon[i] = new char *[x];
      for(int j = 0; j < y; j++){
	dungeon[i][j] = new char[y];
      }
    }

    //fill in 3D array
    for(int level = 0; level < z; level++){
      //      getline();
      for(int row = 0; row < x; row++){
	for(int column = 0; column < y; column++){
	  cin >> dungeon[level][row][column];
	}
	//getline();
      }
    }

    //print3Darray(dungeon, z, x, y);

    struct node *  startPosition = new node;
    getStart(dungeon, z, x, y, startPosition);

    queue<struct node *> mysearch;
    
    mysearch.push(startPosition);
    while(true){
      if(mysearch.empty()){
	minutes = -1;
	break;
      }
      getMoves(dungeon, z, x, y, mysearch.front(), mysearch);
      if(dungeon[mysearch.front()->z][mysearch.front()->x][mysearch.front()->y] == 'E'){
	minutes = mysearch.front()->pathcost;
	break;
      }
      delete mysearch.front();
      mysearch.pop();
    }    

    if(minutes == -1){
      cout << "Trapped!\n";
    }
    else{
      printf("Escaped in %d minute(s).\n", minutes);
    }
    /**
    for(int l = 0; l < z; l++){
      for(int r = 0; r < x; r++){
	delete[] dungeon[l][r];
      }
      delete[] dungeon[l];
    }
    delete[] dungeon;
    **/
  }//while
  
}//main
