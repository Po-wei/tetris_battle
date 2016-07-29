//Print.h
//Programed by Po-wei Huang. All right reserved.

#ifndef PRINT_H
#define PRINT_H

#include "control.h"
#include <ctime>
using namespace std;

#define Digit_X   5  //�j�r���_�lX��
#define Digit_Y  13	 //�j�r���_�lY��
#define D_space   8  //�j�r�����Z��


bool timer(int dur , bool state) //�ɶ�����
{
	static time_t start;
	if (state == true)
		start = time(0);
	time_t t;
	time_t diff = time(0) - start;
	t = dur - diff ;
	if ( t >= 0){
		textcolor(BROWN);
		gotoxy(34, 1);
		cout << "Time    "; cout << t / 60 << " : "; (t % 60 >= 10) ? cout << t % 60 : cout <<  "0" <<  t % 60;
		return true;
	}
	return false;
}

void game_ver(){
	gotoxy(1, 1);
	textcolor(LIGHTGREEN);
	cout << "VERSION 1.03";

}

void game_name() //�b�C���}�l�e �L�X���D
{
	const int x = 6; //orgin_x
	const int y = 4; //orgin_y
	const int space = 12;// �r�����Z

	textcolor(9);
	gotoxy(x, y);     cout << "����������";
	gotoxy(x, y + 1); cout << "    ��    ";
	gotoxy(x, y + 2); cout << "    ��    ";
	gotoxy(x, y + 3); cout << "    ��    ";
	gotoxy(x, y + 4); cout << "    ��    ";

	textcolor(10);
	gotoxy(x + space, y);     cout << "����������";
	gotoxy(x + space, y + 1); cout << "��        ";
	gotoxy(x + space, y + 2); cout << "����������";
	gotoxy(x + space, y + 3); cout << "��        ";
	gotoxy(x + space, y + 4); cout << "����������";

	textcolor(11);
	gotoxy(x + 2 * space, y);     cout << "����������";
	gotoxy(x + 2 * space, y + 1); cout << "    ��    ";
	gotoxy(x + 2 * space, y + 2); cout << "    ��    ";
	gotoxy(x + 2 * space, y + 3); cout << "    ��    ";
	gotoxy(x + 2 * space, y + 4); cout << "    ��    ";

	textcolor(4);
	gotoxy(x + 3 * space, y);     cout << "����������";
	gotoxy(x + 3 * space, y + 1); cout << "��      ��";
	gotoxy(x + 3 * space, y + 2); cout << "����������";
	gotoxy(x + 3 * space, y + 3); cout << "��    ��  ";
	gotoxy(x + 3 * space, y + 4); cout << "��      ��";
	
	textcolor(14);
	gotoxy(x + 4 * space, y);     cout << "  ������  ";
	gotoxy(x + 4 * space, y + 1); cout << "    ��    ";
	gotoxy(x + 4 * space, y + 2); cout << "    ��    ";
	gotoxy(x + 4 * space, y + 3); cout << "    ��    ";
	gotoxy(x + 4 * space, y + 4); cout << "  ������  " ;

	textcolor(7);
	gotoxy(x + 5 * space, y);     cout << "����������";
	gotoxy(x + 5 * space, y + 1); cout << "��        ";
	gotoxy(x + 5 * space, y + 2); cout << "����������";
	gotoxy(x + 5 * space, y + 3); cout << "        ��";
	gotoxy(x + 5 * space, y + 4); cout << "����������";

	cout << endl;
	textcolor(15);


}


void game_mod(bool &mode)   //���ɶ� �n�令return 3 mode 
{
	const int x = 33;
	const int y = 15;
	
	
	gotoxy(x, y);
	textcolor(YELLOW);
	cout << "�� NORMAL MODE";

	gotoxy(x, y + 3);
	textcolor(WHITE);
	cout << "   CRAZY  MODE";

	while (1){

		bool game_start = 0;

		if (_kbhit()){

			switch (key_t())
			{
			case 'u':
				if (mode == 0)
					mode = 1;
				else
					mode = 0;
				break;

			case 'd':
				if (mode == 0)
					mode = 1;
				else
					mode = 0;
				break;

			case 'e':
				clrscr();
				game_start = 1;
				break;

			default:
				break;
			}//end switch

			if (game_start) // �C���}�l!
				break;
			else if (mode == 0){
				gotoxy(x, y);
				textcolor(YELLOW);
				cout << "�� NORMAL MODE";

				gotoxy(x, y + 3);
				textcolor(WHITE);
				cout << "   CRAZY  MODE";
			}
			else{
				gotoxy(x, y);
				textcolor(WHITE);
				cout << "   NORMAL MODE";

				gotoxy(x, y + 3);
				textcolor(YELLOW);
				cout << "�� CRAZY  MODE";
			}
		}
	}//end while

	
}


void game_frame()
{
	cout << endl; textcolor(LIGHTGRAY);
	cout << "                             ����������������������������������              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                   ������������                    ������������              " << endl;
	cout << "                   ��        ��                    ��        ��              " << endl;
	cout << "                   ������������                    ��        ��              " << endl;
	cout << "                   ��        ��                    ��        ��              " << endl;
	cout << "                   ��        ��                    ������������              " << endl;
	cout << "                   ��        ��                    ��        ��              " << endl;
	cout << "                   ������������                    ��        ��              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ������������              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ������������              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ��        ��              " << endl;
	cout << "                             ��                    ������������              " << endl;
	cout << "                             ��                    ��                        " << endl;
	cout << "                             ��                    ��                        " << endl;
	cout << "                             ������������������������                        " << endl;
	 
	gotoxy(X-10, 5);
	textcolor(YELLOW); cout << "�֢ݢڢ�";
	gotoxy(X+22, 3);
	textcolor(YELLOW); cout << "�ܢӢ��";

	textcolor(WHITE); // color reset
	

	


}



void game_rule(){

	textcolor(YELLOW);
	gotoxy(1, 5);
	cout << "HOLD : ENTER" << endl;
	cout << "���� :   �� " << endl;
	cout << "���� : ������" << endl;
	cout << "�������� : SPACE";

}

// block.draw_block ��@
void draw(int x , int y , shape _s ,int  d , bool type){ // enum shape { O , L , J , I , S , Z  ,T}; 
														 //type : 0 �Ť� , 1 ���
	switch(_s){	
/*�ݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢݢ�*/		
		case O:
			textcolor(YELLOW);
			if( y==0){	//�Ĥ@���X�{ 
				gotoxy(X + 2 * x, Y + y );	type==1 ? cout << "����" : cout << "����" ;
				break ;	//���X O 																
			}

			//�@�몬�p 
			gotoxy(X + 2 * x, Y + y - 1);	type == 1 ? cout << "����" : cout << "����";
			gotoxy(X + 2 * x, Y + y);		type == 1 ? cout << "����" : cout << "����";
			break;


/*��*/		
		case I:
			textcolor(LIGHTCYAN);
			if( y==0){	//�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2 * x, Y + y);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+1);		type == 1 ? cout << "��" : cout << "��";
						return; // �ܦh��break !
						
					case 1:
						gotoxy(X + 2 * x - 2, Y + y);		type == 1 ? cout << "��������" : cout << "��������";
						return;
						
					case 2:
						gotoxy(X + 2 * x, Y + y);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+1);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+2);		type == 1 ? cout << "��" : cout << "��";
						return ;
					
					case 3:
						gotoxy(X + 2 * x - 4, Y + y);	type == 1 ? cout << "��������" : cout << "��������";
						return;	
				}//end switch
			}//end if

			//�@�몬�p 
			switch(d){
					case 0:

					if (y>=2) //�u���@��
					   {gotoxy(X + 2 * x, Y + y-2);	    type == 1 ? cout << "��" : cout << "��";}
						gotoxy(X + 2 * x, Y + y-1);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+1);		type == 1 ? cout << "��" : cout << "��";
						return;
						
					case 1:
						gotoxy(X + 2 * x - 2, Y + y);		type == 1 ? cout << "��������" : cout << "��������";
						return;
						
					case 2:
						gotoxy(X + 2 * x, Y + y-1);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+1);		type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y+2);		type == 1 ? cout << "��" : cout << "��";
						return ;
					
					case 3:
						gotoxy(X + 2 * x - 4, Y + y);	type == 1 ? cout << "��������" : cout << "��������";
						return;	

					default:
						gotoxy(1, 1);
						cout << "WARN ! I";
						delay(1000);
						return;
				}


/*�ڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢ�*/			
		case L:

			textcolor(BROWN);
			if( y==0){ //�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2 * x - 2, Y + y); type == 1 ? cout << "������" : cout << "������"; 
						return;
					case 1:
						gotoxy(X + 2 * x, Y + y);    type == 1 ? cout << "��" :   cout << "��";
						gotoxy(X + 2*x  , Y + y+1);  type == 1 ? cout << "����" : cout << "����";
						return;
					case 2:
						gotoxy(X + 2 * x - 2, Y + y);     type == 1 ? cout << "������" : cout << "������";
						gotoxy(X + 2 * x - 2, Y + y + 1); type == 1 ? cout << "��" :     cout << "��";
						return;
					case 3:
						gotoxy(X + 2 * x, Y + y);	 type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2*x  , Y + y+1);	 type == 1 ? cout << "��" : cout << "��";
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N! L" ;
						return;
				}
				
			}
			
			//�@�몬�p 
			switch(d){
					case 0:
						gotoxy(X + 2 * x + 2, Y + y - 1); type == 1 ?  cout << "��" :	  cout << "��";
						gotoxy(X + 2 * x - 2, Y + y);  type == 1 ? cout << "������" : cout << "������";
						return;
					case 1:
						gotoxy(X + 2*x  , Y + y-1);  type == 1 ?  cout << "��" :	  cout << "��";
						gotoxy(X + 2*x  , Y + y);    type == 1 ?  cout << "��" :	  cout << "��";
						gotoxy(X + 2 * x, Y + y + 1); type == 1 ? cout << "����" :    cout << "����";
						return;
					case 2:
						gotoxy(X + 2 * x - 2, Y + y);     type == 1 ? cout << "������" : cout << "������";
						gotoxy(X + 2 * x - 2, Y + y + 1); type == 1 ? cout << "��" :     cout << "��";
						return;
					case 3:
						gotoxy(X + 2 * x - 2, Y + y - 1);	  type == 1 ? cout << "����" : cout << "����";
						gotoxy(X + 2 * x, Y + y);	            type == 1 ? cout << "��" :   cout << "��";
						gotoxy(X + 2 * x, Y + y + 1);           type == 1 ? cout << "��" :   cout << "��";
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N! L" ;
						delay(1000);
						return;
			}
			
/*�آآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآ�*/			
		case J:
			
			textcolor(LIGHTBLUE);
			if( y==0){ //�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2 * x - 2, Y + y); type == 1 ? cout << "������" : cout << "������";
						return;
					case 1:
						gotoxy(X + 2 * x, Y + y);      type == 1 ? cout << "��" : cout << "��";
						gotoxy(X + 2 * x, Y + y + 1);  type == 1 ? cout << "��" : cout << "��";
						return;
					case 2:
						gotoxy(X + 2 * x - 2, Y + y);     type == 1 ? cout << "������" : cout << "������";
						gotoxy(X + 2 * x + 2, Y + y + 1);     type == 1 ? cout << "��" :     cout << "��";
						return;
					case 3:
						gotoxy(X + 2 * x, Y + y);	           type == 1 ? cout << "��" :   cout << "��";
						gotoxy(X + 2 * x - 2, Y + y + 1);	 type == 1 ? cout << "����" : cout << "����";
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N! J" ;
						delay(1000);
						return;
				}
				
			}
			
			//�@�몬�p 
			switch(d){
				case 0:
					gotoxy(X + 2 * x - 2, Y + y - 1); type == 1 ? cout << "��" :     cout << "��";
					gotoxy(X + 2 * x - 2, Y + y);     type == 1 ? cout << "������" : cout << "������";
					return;
				case 1:
					gotoxy(X + 2 * x, Y + y - 1);  type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y);      type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x, Y + y + 1);  type == 1 ? cout << "��" :   cout << "��";
					return;
				case 2:
					gotoxy(X + 2 * x - 2, Y + y);    type == 1 ? cout << "������" : cout << "������";
					gotoxy(X + 2 * x + 2, Y + y + 1);    type == 1 ? cout << "��" :     cout << "��";
					return;
				case 3:
					gotoxy(X + 2*x  , Y + y-1);	           type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x, Y + y);	           type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x - 2, Y + y + 1);	 type == 1 ? cout << "����" : cout << "����";
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N! J" ;
					delay(1000);
					return;
			}//end J
/*������������������������������������������������*/
		case T:
			textcolor(LIGHTMAGENTA);
			switch (d){//���Ӽg�k
				case 0:
					gotoxy(X + 2*x   , Y + y-1);
					if (y >= 1)					     type == 1 ? cout << "��" :     cout << "��";
					gotoxy(X + 2 * x - 2, Y + y);  type == 1 ? cout << "������" : cout << "������";
					return;
				case 1:
					gotoxy(X + 2*x  , Y + y-1);  
					if (y >= 1)				      type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x, Y + y);     type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y + 1); type == 1 ? cout << "��" :   cout << "��";
					return;
				case 2:
					gotoxy(X + 2 * x - 2, Y + y);    type == 1 ? cout << "������" : cout << "������";
					gotoxy(X + 2 * x, Y + y + 1);      type == 1 ? cout << "��" :     cout << "��";
					return;
				case 3:
					gotoxy(X + 2*x   , Y + y-1);	
					if (y >= 1)						      type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x - 2, Y + y);	    type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y + 1);	      type == 1 ? cout << "��" :   cout << "��";
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!  T" ;
					delay(1000);
					return;
					
			}//end T
/*������������������������������������������������������*/
		case S:
			textcolor(LIGHTGREEN);
			switch (d){
				case 0:
					gotoxy(X + 2*x  , Y + y-1);
					if (y >= 1)                     type == 1 ? cout << "����" : cout << "����"; //���Ӽg�k
					gotoxy(X + 2 * x - 2, Y + y); type == 1 ? cout << "����" : cout << "����";
					return;
				case 1:
					gotoxy(X + 2*x  , Y + y-1);  
					if (y >= 1)					     type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x, Y + y);        type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x + 2, Y + y + 1);  type == 1 ? cout << "��" :   cout << "��";
					return;
				case 2:
					gotoxy(X + 2 * x, Y + y);            type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x - 2, Y + y + 1);  type == 1 ? cout << "����" : cout << "����";
					return;
				case 3:
					gotoxy(X + 2*x -2, Y + y-1);	
					if (y >= 1)						  type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x - 2, Y + y);	  type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y + 1);	    type == 1 ? cout << "��" :   cout << "��";
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!  S" ;
					return;
					
			}//end S
/*�������������������������������������������*///
		 case Z:
			textcolor(LIGHTRED);
			switch (d){
				case 0:
					gotoxy(X + 2*x -2 , Y + y-1);
					if (y >= 1)                     type == 1 ? cout << "����" : cout << "����"; //���Ӽg�k
					gotoxy(X + 2 * x, Y + y);         type == 1 ? cout << "����" : cout << "����";
					return;
				case 1:
					gotoxy(X + 2*x+2  , Y + y-1);  
					if (y >= 1)				         type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x, Y + y);      type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y + 1);  type == 1 ? cout << "��" :   cout << "��";
					return;
				case 2:
					gotoxy(X + 2 * x - 2, Y + y);  type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x, Y + y + 1);    type == 1 ? cout << "����" : cout << "����";
					return;
				case 3:
					gotoxy(X + 2*x   , Y + y-1);	
					if (y >= 1)						    type == 1 ? cout << "��" :   cout << "��";
					gotoxy(X + 2 * x - 2, Y + y);	  type == 1 ? cout << "����" : cout << "����";
					gotoxy(X + 2 * x - 2, Y + y + 1); type == 1 ? cout << "��" :   cout << "��";
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!  Z" ;
					delay(1000);
					return;
					
			}//end S

		 case NOT:
			 gotoxy(1, 1);
			 cout << "NO HOLD";
			 delay(1000);
			 break;

		 default:
			 gotoxy(1, 1);
			 cout << "W A R N!";
			 delay(1000);
			 return;


	}//end switch(_s)
}


// block.erase_block ��@
void erase(int x, int y, shape _s, int d){
	
	switch(_s){								 	
		case O:
			if( y==0){	//�Ĥ@���X�{ 
				gotoxy(X + 2 * x, Y + y );	cout << "    " ;
				break ;	//���X O 																
			}

			//�@�몬�p 
			gotoxy(X + 2 * x, Y + y-1);		cout << "    " ;
			gotoxy(X + 2 * x, Y + y );		cout << "    " ;	
			break;


/*�עעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעעע�*/		
		case I:
			if( y==0){	//�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2 * x, Y + y);		cout << "  " ;
						gotoxy(X + 2 * x, Y + y+1);		cout << "  " ;
						return;
						
					case 1:
						gotoxy(X + 2 * x-2, Y + y);		cout << "        " ;
						return;
						
					case 2:
						gotoxy(X + 2 * x, Y + y);		cout << "  " ;
						gotoxy(X + 2 * x, Y + y+1);		cout << "  " ;
						gotoxy(X + 2 * x, Y + y+2);		cout << "  " ;
						return ;
					
					case 3:
						gotoxy(X + 2 * x -4, Y + y);	cout << "  �@�@�@" ;
						return;	
				}//end switch
			}//end if

			//�@�몬�p 
			switch(d){
					case 0:

					if (y>=2) //�u���@��
					   {gotoxy(X + 2 * x, Y + y-2);	    cout << "�@";}
						gotoxy(X + 2 * x, Y + y-1);		cout << "�@" ;
						gotoxy(X + 2 * x, Y + y);		cout << "�@" ;
						gotoxy(X + 2 * x, Y + y+1);		cout << "�@" ;
						return;
						
					case 1:
						gotoxy(X + 2 * x-2, Y + y);		cout << "�@�@�@�@" ;
						return;
						
					case 2:
						gotoxy(X + 2 * x, Y + y-1);		cout << "�@" ;
						gotoxy(X + 2 * x, Y + y);		cout << "�@" ;
						gotoxy(X + 2 * x, Y + y+1);		cout << "�@" ;
						gotoxy(X + 2 * x, Y + y+2);		cout << "�@" ;
						return ;
					
					case 3:
						gotoxy(X + 2 * x -4, Y + y);	cout << "�@�@�@�@" ;
						return;	
				}


/*�ڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢڢ�*/			
		case L:

			if( y==0){ //�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2*x -2 , Y + y);cout << "�@�@�@" ;
						return;
					case 1:
						gotoxy(X + 2*x  , Y + y);    cout << "�@" ;
						gotoxy(X + 2*x  , Y + y+1);  cout << "�@�@" ;
						return;
					case 2:
						gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
						gotoxy(X + 2*x -2 , Y + y+1);cout << "�@" ;
						return;
					case 3:
						gotoxy(X + 2*x  , Y + y);	 cout << "�@" ;
						gotoxy(X + 2*x  , Y + y+1);	 cout << "�@" ;
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N!" ;
						return;
				}
				
			}
			
			//�@�몬�p 
			switch(d){
					case 0:
						gotoxy(X + 2*x +2 , Y + y-1);    cout << "�@" ;
						gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
						return;
					case 1:
						gotoxy(X + 2*x  , Y + y-1);  cout << "�@" ;
						gotoxy(X + 2*x  , Y + y);    cout << "�@" ;
						gotoxy(X + 2*x  , Y + y+1);  cout << "�@�@" ;
						return;
					case 2:
						gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
						gotoxy(X + 2*x -2 , Y + y+1);cout << "�@" ;
						return;
					case 3:
						gotoxy(X + 2*x-2, Y + y-1);	  cout<< "�@�@" ;
						gotoxy(X + 2*x  , Y + y);	    cout<< "�@" ;
						gotoxy(X + 2*x  , Y + y+1);     cout<< "�@" ;
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N!" ;
						return;
			}
			
/*�آآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآآ�*/			
		case J:
			
			
			if( y==0){ //�Ĥ@���X�{ 
				switch(d){
					case 0:
						gotoxy(X + 2*x -2 , Y + y);cout << "�@�@�@" ;
						return;
					case 1:
						gotoxy(X + 2*x  , Y + y);    cout << "�@" ;
						gotoxy(X + 2*x  , Y + y+1);  cout << "�@" ;
						return;
					case 2:
						gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
						gotoxy(X + 2*x +2 , Y + y+1);    cout << "�@" ;
						return;
					case 3:
						gotoxy(X + 2*x   , Y + y);	       cout << "�@" ;
						gotoxy(X + 2*x -2  , Y + y+1);	 cout << "�@�@" ;
						return;
					default:
						gotoxy(1,1);
						cout<<"W A R N!" ;
						return;
				}
				
			}
			
			//�@�몬�p 
			switch(d){
				case 0:
					gotoxy(X + 2*x -2 , Y + y-1);cout << "�@" ;
					gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
					return;
				case 1:
					gotoxy(X + 2*x  , Y + y-1);  cout << "�@�@" ;
					gotoxy(X + 2*x  , Y + y);    cout << "�@" ;
					gotoxy(X + 2*x  , Y + y+1);  cout << "�@" ;
					return;
				case 2:
					gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@�@" ;
					gotoxy(X + 2*x +2 , Y + y+1);    cout << "�@" ;
					return;
				case 3:
					gotoxy(X + 2*x  , Y + y-1);	       cout << "�@" ;
					gotoxy(X + 2*x  , Y + y);	       cout << "�@" ;
					gotoxy(X + 2*x -2  , Y + y+1);	 cout << "�@�@" ;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!" ;
					return;
			}//end J
			
/*�������������������������������������������*/
		case T:
			
			switch (d){//���Ӽg�k
				case 0:

					gotoxy(X + 2*x   , Y + y-1);
					if(y>=1)					   cout << "�@" ; 
					gotoxy(X + 2*x -2, Y + y);   cout << "�@�@�@" ;
					return;
				case 1:
					gotoxy(X + 2*x  , Y + y-1);  
					if (y >= 1)				     cout << "�@";
					gotoxy(X + 2*x  , Y + y);    cout << "�@�@" ;
					gotoxy(X + 2*x  , Y + y+1);  cout << "�@" ;
					return;
				case 2:
					gotoxy(X + 2*x -2, Y + y);    cout << "�@�@�@" ;
					gotoxy(X + 2*x   , Y + y+1);  cout <<   "�@" ;
					return;
				case 3:
					gotoxy(X + 2*x   , Y + y-1);	
					if (y >= 1)						   cout << "�@";
					gotoxy(X + 2*x -2, Y + y);	     cout << "�@�@" ;
					gotoxy(X + 2*x   , Y + y+1);	   cout << "�@" ;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!" ;
					return;
					
			}//end T
/*������������������������������������������*/
		case S:
			textcolor(LIGHTGREEN);
			switch (d){
				case 0:
					gotoxy(X + 2*x  , Y + y-1);
					if(y>=1)                     cout <<   "�@�@" ; //���Ӽg�k
					gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@" ;
					return;
				case 1:
					gotoxy(X + 2*x  , Y + y-1);  
					if (y >= 1)					    cout << "�@";
					gotoxy(X + 2*x   , Y + y);      cout << "�@�@" ;
					gotoxy(X + 2*x+2 , Y + y+1);    cout <<   "�@" ;
					return;
				case 2:
					gotoxy(X + 2*x    , Y + y);      cout << "�@�@" ;
					gotoxy(X + 2*x -2 , Y + y+1);  cout << "�@�@" ;
					return;
				case 3:
					gotoxy(X + 2*x -2, Y + y-1);	
					if (y >= 1)						 cout << "�@";
					gotoxy(X + 2*x -2, Y + y  );	 cout << "�@�@" ;
					gotoxy(X + 2*x   , Y + y+1);	 cout <<   "�@" ;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!" ;
					return;
					
			}//end S
/*��������������������������������������������*/
		 case Z:
			switch (d){
				case 0:
					gotoxy(X + 2*x -2 , Y + y-1);
					if(y>=1)                     cout << "�@�@" ; //���Ӽg�k
					gotoxy(X + 2*x  , Y + y);      cout << "�@�@" ;
					return;
				case 1:
					gotoxy(X + 2*x+2  , Y + y-1);  
					if (y >= 1)				     cout <<   "�@";
					gotoxy(X + 2*x  , Y + y);    cout << "�@�@" ;
					gotoxy(X + 2*x  , Y + y+1);  cout << "�@" ;
					return;
				case 2:
					gotoxy(X + 2*x -2 , Y + y);  cout << "�@�@" ;
					gotoxy(X + 2*x  , Y + y+1);  cout <<   "�@�@" ;
					return;
				case 3:
					gotoxy(X + 2*x     , Y + y-1);	
					if (y >= 1)						 cout <<   "�@";
					gotoxy(X + 2*x -2  , Y + y);	 cout << "�@�@" ;
					gotoxy(X + 2*x -2  , Y + y+1);	 cout << "�@" ;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!" ;
					return;
					
			}//end S
			
	}//end switch(_s)
}

void printdigit(int x, int y, int num){
	switch (num){
	case 0:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);		cout << "��  ��";
		gotoxy(x, y + 2);		cout << "��  ��";
		gotoxy(x, y + 3);		cout << "��  ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 1:
		gotoxy(x, y);			cout << "    ��";
		gotoxy(x, y + 1);	    cout << "    ��";
		gotoxy(x, y + 2);		cout << "    ��";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "    ��";
		break;
	case 2:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "    ��";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "��    ";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 3:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "    ��";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 4:
		gotoxy(x, y);			cout << "��  ��";
		gotoxy(x, y + 1);	    cout << "��  ��";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "    ��";
		break;
	case 5:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "��    ";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 6:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "��	   ";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "��  ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 7:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "��  ��";
		gotoxy(x, y + 2);		cout << "    ��";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "    ��";
		break;
	case 8:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "��  ��";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "��  ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case 9:
		gotoxy(x, y);			cout << "������";
		gotoxy(x, y + 1);	    cout << "��  ��";
		gotoxy(x, y + 2);		cout << "������";
		gotoxy(x, y + 3);		cout << "    ��";
		gotoxy(x, y + 4);		cout << "������";
		break;
	case -1:
		gotoxy(x, y);			cout << "      ";
		gotoxy(x, y + 1);	    cout << "      ";
		gotoxy(x, y + 2);		cout << "      ";
		gotoxy(x, y + 3);		cout << "      ";
		gotoxy(x, y + 4);		cout << "      ";
		break;
		
	}
}


void trans_digit(int value){

	int o = value % 10;
	int t = (value / 10) % 10;
	int h = (value / 100) % 10;
	
	textcolor(LIGHTCYAN);
	printdigit(Digit_X, Digit_Y, h);
	printdigit(Digit_X + D_space, Digit_Y, t);
	printdigit(Digit_X + 2 * D_space, Digit_Y, o);
}

void game_block(int info){

	// �ѰO�n���ƻ�F
}

void countdown(){
	
	textcolor(LIGHTBLUE);
	for (int i = 3; i > 0; i--){
		printdigit(39, 10, i);
		delay(800);
		printdigit(39, 10, -1);
		delay(200);
	}
	printdigit(39, 10, -1); // clear 
}



#endif
