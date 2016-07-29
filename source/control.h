//Control.h
//Programed by Po-wei Huang. All right reserved.
//以後應該把單個CLASS放進單一HEADER
#ifndef CONTROL_H
#define CONTROL_H

#include <conio2.h>
#include <iostream>
#include <cstdlib> 
using namespace std ;

#define X 32  // x  起點左上角  →	   30~50
#define Y  3  // y  起點左上角 ↓ 	   3 ~23


#define weight 12  //xy 的寬度 包含邊界
#define length 22  //xy 的高度 包含邊界

enum shape { O , I , L , J , S , Z  ,T , NOT }; //各種形狀 


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
	void display_block(int) const;				//draw 等待列 以及HOLD的BLOCK
	void display_erase(int) const;				//erase 等待列 以及HOLD的BLOCK
	bool operator==(block)  const;					
	
	void test_draw(); // 測試用

	friend class frame;  // frame 可以讀取block的資訊	

private:
	int pos_x;  //位置 x 
	int pos_y;	 //位置 y  
	int dir;	 // 方向 
	shape sh;	 // 形狀 
};

class frame{
public:
	
	frame();
	static int success;							//消的行數
	
	void place(block);
	void replace();

	void redraw()    const;						//削掉後重畫
	void show_value()const;						//測試用
	
	bool isblock(int, int) const;				// x ,y 有沒有東西  1 可以放 0不能放 
	bool linecheck(int)    const;
	void find();							    // 檢查有沒有連線
	
	bool gameover() const;

private:
	int xy[weight][length];//1~10 1~20
	/*
		<0 空的>
		對應表:
		O , I , L , J , S , Z  ,T
		1 , 2 , 3 , 4 , 5 , 6 , 7

	*/
};

//應該移到function.h

void draw(int ,int , shape , int ,bool);  // 中心 x , y , 形狀  ,方向 ,型態 寫在print .h

void erase(int, int, shape, int );  // 中心 x , y , 形狀  ,方向 , 型態 寫在print.h

char key_t() ;// translate key to char

void printdigit();
  
shape random(); //產生一個BLOCK資訊

shape random(shape, shape, shape, shape, shape, shape);

void game_over();


#endif
