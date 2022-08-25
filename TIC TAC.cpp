#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void Board();
int winner();
int checkInput(int input);


char box[]={'0','1','2','3','4','5','6','7','8','9'};
int check[9];

int main(){
    int player=1,input,status=-1;
    Board();
   
	int d=0;
    while (status==-1)
    {
        player=(player%2==0) ? 2 : 1;
        char mark=(player==1) ? 'X' :'O';
        jump:
        printf("Please enter Number For Player %d\n",player);
        scanf("%d",&input);
	    if(input<1 || input>9){
	   		printf("invalid input");
		}	
		if(checkInput(input)==1){
			box[input]!=mark;
	       	printf("Enterd\n\n");
	       	goto jump;
		}
		else{
			box[input]=mark;
		}
		check[d]=input;
	    Board();
	    d++;
	    int result=winner();
	if(result==1){
		player=(player%2==0) ? 2 : 1;
		if(player==1){
			printf("plyer 1 [X] is the winner",player);
		}
		else{
			printf("plyer 1 [O] is the winner",player);
		}
		
		break;
	}
	else if(result==0){
		printf("Draw");
		exit(0);
	}
	
	player++;
	}
}

int checkInput(int input){
	int x=0;
	for(int i=0;i<9;i++){
	 	if(check[i]==input)
	 	x++;
	}
	if(x>0)
	return 1;
}
void Board(){
    system("cls");
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",box[1],box[2],box[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",box[4],box[5],box[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",box[7],box[8],box[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

int winner(){
	if(box[1]==box[2]&&box[2]==box[3]){
		return 1;
	}
	if(box[4]==box[5]&&box[5]==box[6]){
		return 1;
	}
	if(box[7]==box[8]&&box[8]==box[9]){
		return 1;
	}
	if(box[1]==box[4]&&box[4]==box[7]){
		return 1;
	}
	if(box[2]==box[5]&&box[5]==box[8]){
		return 1;
	}
	if(box[3]==box[6]&&box[6]==box[9]){
		return 1;
	}
	if(box[1]==box[5]&&box[5]==box[9]){
		return 1;
	}
	if(box[3]==box[5]&&box[5]==box[7]){
		return 1;
	}
	int c=0;
	for(int i=1;i<=9;i++){
		if(box[i]=='X'||box[i]=='O'){
			c++;
		}
	}
	if(c==9){
		return 0;
	}
	return -1;
}
