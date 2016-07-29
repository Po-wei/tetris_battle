/*
	Name: Tetris game
	Copyright: All right reserved.
	Author: Po-wei Huang
	Date: 2015/1/24 (start)
	Description: A classic game.
*/
#include "control.h"
#include "Print.h"
using namespace std;


int main()
{
	game_ver();
	srand(time(0));  //���ܺؤl
	
	while (1){			//GREAT LOOP

		bool mode = 0; // 0 normal , 1 crazy
		bool condition = 0;
		time_t drop;
		clock_t touch; //��׸���

		game_name();
		game_mod(mode);		//select mode
		game_frame();		// display �C���D�ج[
		game_rule();
		game_ver();
		frame::success = 0;
		trans_digit(frame::success);
		countdown();

		block now(random());
		block next1(random()), next2(random()), next3(random()), next4(random());
		block hold, shadow;
		frame game; //�D�{����T
		
//		game.show_value();
		
		shadow = now.shadow(game);
		shadow.draw_block(0);
		next1.display_block(0);
		next2.display_block(1);
		next3.display_block(2);
		next4.display_block(3);
		now.draw_block(1);
		drop = time(0);
		if (mode == 0)
		timer(120, true);//�p�ɾ��}�l
		
		while (1){// �C��LOOP
			if (mode == 0)
			if (timer(120 ,false) == false){
				gotoxy(34, 12);
				textcolor(LIGHTRED);
				cout << "!!!!GAME OVER!!!!";
				cin.get();
				clrscr();
				break;
			}
						
			if (_kbhit()){//�������
				switch (key_t()){
				case 'u':
					now.erase_block();
					shadow.erase_block();
					now.spin(game);
					shadow = now.shadow(game);
					shadow.draw_block(0);
					now.draw_block(1);
					break;
				
				case 'l':
					now.erase_block();
					shadow.erase_block();
					now.move(0,game);
					shadow = now.shadow(game);
					shadow.draw_block(0);
					now.draw_block(1);
					
					break;

				case 'r':
					now.erase_block();
					shadow.erase_block();
					now.move(1,game);
					shadow = now.shadow(game);
					shadow.draw_block(0);
					now.draw_block(1);
					
					break;

				case 'd':
					now.erase_block();
					now.move(2,game);
					now.draw_block(1);
					break;

				case 'e':
					
					if (hold.getsh() == NOT){ //�٨SHOLD
						now.erase_block();
						shadow.erase_block();

						now.reset();
						hold = now; // �洫
						
						next1.display_erase(0);
						next2.display_erase(1);
						next3.display_erase(2);
						next4.display_erase(3);

						block nex(random());
						now = next1;    //����
						next1 = next2;
						next2 = next3;
						next3 = next4;
						next4 = nex;

						shadow = now.shadow(game);
						shadow.draw_block(0);
						next1.display_block(0);
						next2.display_block(1);
						next3.display_block(2);
						next4.display_block(3);
					}
					else{//�w�gHOLD
						block temp;
						shadow.erase_block();
						now.erase_block();
						now.reset();
						hold.display_erase(-1);
						temp = now;
						now = hold;
						hold = temp;
						shadow = now.shadow(game);
						shadow.draw_block(0);
					}

					hold.display_block(-1);
					now.draw_block(1);
					break;

				case 's':
					now.erase_block();
				    game.place(shadow);
				    shadow.draw_block(1);
					
					game.find();
					game.replace();
					game.redraw();
//				    game.show_value();
					
					next1.display_erase(0);
					next2.display_erase(1);
					next3.display_erase(2);
					next4.display_erase(3);

					block nex( random() ); 
					now = next1;        //����
					next1 = next2;
					next2 = next3;
					next3 = next4;
					next4 = nex;
					
					shadow = now.shadow(game); //new shadow
					shadow.draw_block(0);
					next1.display_block(0);
					next2.display_block(1);
					next3.display_block(2);
					next4.display_block(3);
					now.draw_block(1);

					trans_digit(frame::success);
					
					
			
				}//switch
			}// END KBHIT
			
			if((time(0)-drop ) == 1){ //�g�L�@��U�Y�@��
				now.erase_block();
				now.move(2, game);
				now.draw_block(1);
				drop = time(0);
			}

			if (!condition&&(shadow == now)){//�H���˴�
				condition = true;
				touch = clock();
			}
			else if (condition &&  
				    (shadow == now)&&
					(clock() - touch >= 1125 )){  //1.125���H��
					
					game.place(shadow);
					game.find();
					game.replace();
					game.redraw();
					
					next1.display_erase(0);
					next2.display_erase(1);
					next3.display_erase(2);
					next4.display_erase(3);

					block nex(random());
					now = next1;        //����
					next1 = next2;
					next2 = next3;
					next3 = next4;
					next4 = nex;

					shadow = now.shadow(game); //new shadow
					shadow.draw_block(0);
					next1.display_block(0);
					next2.display_block(1);
					next3.display_block(2);
					next4.display_block(3);
					now.draw_block(1);

					trans_digit(frame::success);
				
			}
			else if (condition && !(shadow == now)){
				condition = false;
			}
			
			
			
			if (game.gameover() == true){
				
				gotoxy(34, 12);
				textcolor(RED);
				cout << "!!!!GAME OVER!!!!";
				cin.get();
				clrscr();
				break;
			}
			
			delay(25);
			
		}//end game loop

	}//end exe loop

}
