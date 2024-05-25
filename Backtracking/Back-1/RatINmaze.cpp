#include<bits/stdc++.h>
using namespace std;
bool isSafe(int newx, int newy,vector<vector<char>> board,vector<vector<bool>>visited ){
		int rowsize= board.size();
		int colsize= board[0].size();
	if((newx>=0 && newx<rowsize)&&(newy>=0 && newy<colsize) &&(visited[newx][newy]==false) &&(board[newx][newy]=='.')){
		return true;
	}
	else{
		return false;
	}

}
bool solve(int srcx, int srcy, int desx, int desy, vector<vector<char>> board,vector<vector<bool>>visited, string output){

	// base case:
	if((srcx==desx) && (srcy==desy)){
		cout<<"path is:"<<output<<endl;
		return true;
	}

	// DownMove:
	int newx= srcx+1;
	int newy= srcy;
	 bool Downans=false;
	if(isSafe(newx, newy,board, visited)){
		visited[newx][newy]=true;
		 Downans =solve(newx, newy,desx, desy,board, visited,output+'D' );
		visited[newx][newy]=false;
	}

	//Right Move:
	 newx= srcx;
	 newy= srcy+1;
	 bool rightAns=false;
	if(isSafe(newx, newy,board, visited)){
		visited[newx][newy]=true;
		rightAns=solve(newx, newy,desx, desy,board, visited ,output+'R');
		visited[newx][newy]=false;
	}

	// left Move:
	 newx= srcx;
	 newy= srcy-1;
	  bool leftAns=false;
	if(isSafe(newx, newy,board, visited)){
		visited[newx][newy]=true;
		leftAns =solve(newx, newy,desx, desy,board, visited ,output+'L' );
		visited[newx][newy]=false;
	}

	// Up move:
	 newx= srcx-1;
	 newy= srcy;
	  bool upAns=false;
	if(isSafe(newx, newy,board, visited)){
		visited[newx][newy]=true;
		upAns =solve(newx, newy,desx, desy,board, visited ,output+'U');
		visited[newx][newy]=false;
	}

	if(Downans || rightAns|| leftAns|| upAns){
		return true;
	}
	else{
		return false;
	}

}

int main(){
	int srcx=0;
	int srcy=0;
	
	int desx=3;
	int desy=3;

	vector<vector<char>>board(4,vector<char>(4,'.'));
	board[0][3]='*';
	board[1][1]='*';
	board[1][2]='*';
	board[3][1]='*';

	vector<vector<bool>>visited(4,vector<bool>(4,false));
	visited[0][0]=true;

	cout<<"printing the board:"<<endl;
	for (int i = 0; i < board.size(); i++)
	{
		
		for (int j = 0; j < board[i].size(); j++)
		{
			cout<<board[i][j]<<" ";
		}cout<<endl;
		
	}

	cout<<"Printing the visited Array:"<<endl;
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited[i].size(); j++)
		{
			cout<<visited[i][j]<<" ";
		}cout<<endl;
		
	}
	string s="";
	bool ans =solve(srcx, srcy, desx, desy, board, visited,s);
	cout<<"ans is:"<<ans<<endl;
	
	
	return 0;
}