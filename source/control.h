//Control.h
//Programed by Po-wei Huang. All right reserved.
//�H�����ӧ���CLASS��i��@HEADER
#ifndef CONTROL_H
#define CONTROL_H

#include <conio2.h>
#include <iostream>
#include <cstdlib> 
using namespace std ;

#define X 32  // x  �_�I���W��  ��	   30~50
#define Y  3  // y  �_�I���W�� �� 	   3 ~23


#define weight 12  //xy ���e�� �]�t���
#define length 22  //xy ������ �]�t���

enum shape { O , I , L , J , S , Z  ,T , NOT }; //�U�اΪ� 


class block;
class frame;


class block{
public:
	
	block();
	block(shape);
	
	void spin(const frame &);
	void move(int ,const frame &);
	block shadow(const frame &);

	void reset();
	
	shape getsh()           const;
	void draw_block(bool)   const;
	void erase_block(void)  const;
	void display_block(int) const;				//draw ���ݦC �H��HOLD��BLOCK
	void display_erase(int) const;				//erase ���ݦC �H��HOLD��BLOCK
	bool operator==(block)  const;					
	
	void test_draw(); // ���ե�

	friend class frame;  // frame �i�HŪ��block����T	

private:
	int pos_x;  //��m x 
	int pos_y;	 //��m y  
	int dir;	 // ��V 
	shape sh;	 // �Ϊ� 
};

class frame{
public:
	
	frame();
	static int success;							//�������
	
	void place(block);
	void replace();

	void redraw()    const;						//�d���᭫�e
	void show_value()const;						//���ե�
	
	bool isblock(int, int) const;				// x ,y ���S���F��  1 �i�H�� 0����� 
	bool linecheck(int)    const;
	void find();							    // �ˬd���S���s�u
	
	bool gameover() const;

private:
	int xy[weight][length];//1~10 1~20
	/*
		<0 �Ū�>
		������:
		O , I , L , J , S , Z  ,T
		1 , 2 , 3 , 4 , 5 , 6 , 7

	*/
};

//���Ӳ���function.h

void draw(int ,int , shape , int ,bool);  // ���� x , y , �Ϊ�  ,��V ,���A �g�bprint .h

void erase(int, int, shape, int );  // ���� x , y , �Ϊ�  ,��V , ���A �g�bprint.h

char key_t() ;// translate key to char

void printdigit();
  
shape random(); //���ͤ@��BLOCK��T

shape random(shape, shape, shape, shape, shape, shape);

void game_over();


#endif
