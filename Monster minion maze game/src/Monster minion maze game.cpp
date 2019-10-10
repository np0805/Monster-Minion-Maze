//============================================================================
// Name        : Monster.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

char board[15][15] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
//			   ={'O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O','O'};
char monster='X';
char rapunzel='R';
char player, moveplayer;
char player2='H';
int temp1, temp2;
int mon1, mon2;
int a,b;
int xfart,yfart;
int usefart=3;

void maze(){
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	board[temp1][temp2]=player;

}

void moveplay(){
	board[temp1][temp2]=' ';
	if (moveplayer=='w'){
		if (temp1==0)
			cerr<<"Eror you idiot"<<endl;
		else{
			board[temp1-1][temp2]=player;
			temp1=temp1-1;
		}

	}
	else if (moveplayer=='a'){
		if (temp2==0)
			cerr<<"Eror you idiot"<<endl;
		else{
			board[temp1][temp2-1]=player;
			temp2=temp2-1;
		}
	}
	else if (moveplayer=='s'){
		if (temp1==14)
			cerr<<"Eror you idiot"<<endl;
		else{
			board[temp1+1][temp2]=player;
			temp1=temp1+1;
		}
	}
	else if (moveplayer=='d'){
		if (temp2==14)
			cerr<<"Eror you idiot"<<endl;
		else{
			board[temp1][temp2+1]=player;
			temp2=temp2+1;
		}
	}

}

void movemonster(){
	mon1= rand() % 4;
	mon2= rand() % 4;
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			if (board[i][j]==monster){
				board[i][j]=' ';
				if (mon1==0 && board[i-1][j]!=monster && i!=0){
					if (board[i-1][j]!=rapunzel)
						board[i-1][j]=monster;
				}
				if (mon1==1 && board[i][j-1]!=monster && j!=0){
					if (j-1!=0 && i!=14)
						board[i][j-1]=monster;
				}
				if (mon1==2 && board[i+1][j]!=monster && i!=14){
					if (i+1!=14 && j!=0)
						board[i+1][j]='1';
				}
				if (mon1==3 && board[i][j+1]!=monster && j!=14){
					if (board[i][j+1]!=rapunzel){
						board[i][j+1]='1';
					}
				}
			}
		}
	}
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			if (board[i][j]=='1'){
				board[i][j]=monster;
			}
		}
	}
}
void spawnmonster(){
	do{
		a = rand() % 15;
		b = rand() % 15;
	}
	while (((a==0 && b==14) || (a==14 && b==0)) && board[a][b]==player && board[a][b]==monster);
	board[a][b]=monster;
}

void fart(){
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			if (board[i][j]==player){
				yfart=i;
				xfart=j;
			}
		}
	}
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			if (board[i][j]==monster){
				if (i==yfart && j<xfart && j!=0 && board[i][j-1]!=monster){
					if (board[i][j-1]==board[14][0])
						board[i-1][j]=monster;
					else
						board[i][j-1]=monster;
				}
				if (i==yfart && j>xfart && j!=14 && board[i][j+1]!=monster){
					if (board[i][j+1]==board[0][14])
						board[i+1][j]=monster;
					else
						board[i][j+1]=monster;
				}
				if (i<yfart && j==xfart && j!=0 && board[i-1][j]!=monster){
					if (board[i-1][j]==board[0][14])
						board[i][j-1]=monster;
					else
						board[i-1][j]=monster;
				}
				if (i>yfart && j==xfart && j!=14 && board[i+1][j]!=monster){
					if (board[i+1][j]==board[14][0])
						board[i][j+1]=monster;
					else
						board[i+1][j]=monster;
				}


				if (i>yfart && j<xfart && j!=14 && board[i+1][j]!=monster){
					if (board[i+1][j]==board[14][0])
						board[i][j+1]=monster;
					else
						board[i+1][j]=monster;
				}
				if (i>yfart && j>xfart && j!=14 && board[i+1][j]!=monster)
					board[i+1][j]=monster;
				if (i<yfart && j<xfart && j!=0 && board[i-1][j]!=monster)
					board[i-1][j]=monster;
				if (i<yfart && j>xfart && j!=14 && board[i-1][j]!=monster){
					if (board[i-1][j]==board[0][14])
						board[i][j-1]=monster;
					else
						board[i-1][j]=monster;
				}
			}
		}
	}
}
int main() {
	srand (time(NULL));
	board[0][14]=rapunzel;
	bool game = false;
	do{
		cout<<"Enter your initial (except H,R,O,X) ";
		cin>>player;
		if (player=='X' || player=='O' || player=='R' || player=='H')
			cout<<"Input other than X,O,R"<<endl;
	}
	while(player =='X' || player =='O' || player =='R' || player=='H');
	temp1=14;
	temp2=0;
	board[temp1][temp2]=player;

	do{
		maze();
		cout<<"You have "<<usefart<<" farts left to use"<<endl;

		cout<<"Insert your move direction (w,a,s,d)/(f) = ";
		cin>>moveplayer;
		if (moveplayer=='w' || moveplayer=='a' || moveplayer=='s' || moveplayer=='d'){
			moveplay();
			if (board[0][14]==player){
				player=player2;
				cout<<endl<<"You have meet the princess, now hurry up and take her back to safety";
			}
		}
		else if (moveplayer=='f' && usefart>0){
			fart();
			usefart--;
		}
		else
			cout<<"Well done, you have completely wasted your turn idiot. No move will be given to you this turn whilst the monsters have moved"<<endl;
		cout<<endl;

		movemonster();
		spawnmonster();
		if (board[temp1][temp2]==monster){
			cout<<"Game over, idiot"<<endl;
			break;
		}

		if (board[14][0]=='H')
			game = true;
	}
	while (game==false);

	maze();
	if (game==true)
		cout<<"Congratulations! You have succesfully rescued Rapunzel from her tower"<<endl;

	return 0;
}
