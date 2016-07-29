//Control.cpp
//Programed by Po-wei Huang. All right reserved.
#include "control.h"
using namespace std;

#define N_X   12   //next x 座標與起點X 差12個全形寬度
#define N_Y	   3   //next y 座標與起點Y 差3格高度
#define SPACE  4   //間隔 

#define H_X  -4    //hold x  座標與起點X 差3個全形寬度
#define H_Y   5    //hold y  座標與起點Y 差6個高度



block::block(){

	pos_x = 0;  
	pos_y = 0;
	dir   = 0;    
	sh = NOT ;	   //default NOT 沒有東西
}


block::block(shape _s){

	pos_x = 5;  //起點 (5,1)  
	pos_y = 1;
	dir = 0;    // 方向 
	sh = _s;	// 形狀
}


shape block::getsh()const{
	return this->sh;
}

void block::reset(){
	pos_x = 5; //pos reset
	pos_y = 1;
	dir = 0; // direction reset
}


// O , I , L , J , S , Z  ,T
void block::move(int info,const frame &f){ //移動資勛  0 左 1右 2下 
	int x = pos_x;
	int y = pos_y;

	switch (this->sh){
	case O:
		switch (info){ 
		case 0://左
			if (f.isblock(x - 1, y) && f.isblock(x - 1, y - 1))
				pos_x--;
			return;
		case 1:
			if (f.isblock(x + 2, y) && f.isblock(x + 2, y - 1))
				pos_x++;
			return;
		case 2:
			if (f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
				pos_y++;
			return;

		}//end switch info
	case I:
		switch (this->dir){
		case 0://直立
			switch (info){
			case 0://左
				if (y >= 2){
					if (f.isblock(x - 1, y - 2) && f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1))
						pos_x--;
					return;
				}
				else if (y >= 1){
					if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1))
						pos_x--;
					return;
				}
			case 1://右
				if (y >= 2){
					if (f.isblock(x + 1, y - 2) && f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
						pos_x++;
					return;
				}
				else if (y >= 1){
					if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
						pos_x++;
					return;
				}
			case 2://下
				if (f.isblock(x, y + 2))
					pos_y++;
				return;

			}//switch I info

		case 1://平躺
			switch (info){
			case 0:
				if (f.isblock(x - 2, y))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x +3, y))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1) && f.isblock(x + 2, y + 1))
					pos_y++;
				return;
			}//switch info

		case 2://直立
			switch (info){
			case 0://左
				if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1)&&f.isblock(x - 1, y +2))
						pos_x--;
					return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1) && f.isblock(x + 1, y + 2))
						pos_x++;
					return;
			case 2://下
				if (f.isblock(x, y + 3))
					pos_y++;
				return;

			}//switch I info

		case 3:
			switch (info){
			case 0:
				if (f.isblock(x - 3, y))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 2, y + 1)&&f.isblock(x - 1, y + 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}//switch info
		}//dir
	case L:
		switch (this->dir){
		case 0:
			switch (info){
			case 0:
				if (f.isblock(x - 2, y) && f.isblock(x, y - 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 2, y - 1) && f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}//info

		case 1:
			switch (info){
			case 0:
				if (f.isblock(x - 1, y + 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y - 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 2, y + 1))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x, y + 2) && f.isblock(x + 1, y + 2))
					pos_y++;
				return;
			}//info
		case 2:
			switch (info){
			case 0:
				if (f.isblock(x - 2, y) && f.isblock(x - 2, y - 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x , y + 1) && f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y + 2) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}//info
		case 3:
			switch (info){
			case 0:
				if (f.isblock(x - 1, y + 1) && f.isblock(x - 1, y) && f.isblock(x - 2, y - 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x -1, y ) && f.isblock(x , y + 2))
					pos_y++;
				return;
			}//info
		}//L-dir
	case J:
		switch (this->dir){
		case 0:
			switch (info){
			case 0:
				if (f.isblock(x - 2, y) && f.isblock(x-2, y - 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x , y - 1) && f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}//info

		case 1:
			switch (info){
			case 0:
				if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 2, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x, y + 2) && f.isblock(x + 1, y ))
					pos_y++;
				return;
			}//info
		case 2:
			switch (info){
			case 0:
				if (f.isblock(x - 2, y) && f.isblock(x , y + 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x +2, y ) && f.isblock(x + 2, y+1))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 2))
					pos_y++;
				return;
			}//info
		case 3:
			switch (info){
			case 0:
				if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 2, y + 1))
					pos_x--;
				return;
			case 1:
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2:
				if (f.isblock(x - 1, y+2) && f.isblock(x, y + 2))
					pos_y++;
				return;
			}//info
		}//dir
	case S:
		switch (this->dir){
		case 0:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y) && f.isblock(x - 1, y - 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 2, y - 1) && f.isblock(x + 1, y ))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y+1) && f.isblock(x , y + 1)&&f.isblock(x+1,y))
					pos_y++;
				return;
			}
		case 1:
			switch (info){
			case 0://左
				if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x , y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 2, y) && f.isblock(x +2, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x , y + 1) && f.isblock(x+1, y + 2))
					pos_y++;
				return;
			}
		case 2:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y + 1) && f.isblock(x - 1, y))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 2, y ) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y + 2) && f.isblock(x, y + 2) && f.isblock(x + 1, y+1))
					pos_y++;
				return;
			}
		case 3:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y - 1) && f.isblock(x - 2, y) && f.isblock(x  - 1 , y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x , y - 1) && f.isblock(x + 1, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y + 1) && f.isblock(x , y + 2))
					pos_y++;
				return;
			}
		}//S-dir
	case Z:
		switch (this->dir){
		case 0:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y - 1) && f.isblock(x - 1, y))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1 , y - 1) && f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}
		case 1:
			switch (info){
			case 0://左
				if (f.isblock(x, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 2, y - 1) && f.isblock(x + 2, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x , y + 2) && f.isblock(x +1, y + 1))
					pos_y++;
				return;
			}
		case 2:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y ) && f.isblock(x - 1, y+1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y ) && f.isblock(x + 2, y+1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y+1) && f.isblock(x, y + 2) && f.isblock(x + 1, y + 2))
					pos_y++;
				return;
			}
		case 3:
			switch (info){
			case 0://左
				if (f.isblock(x-1, y - 1) && f.isblock(x - 2, y) && f.isblock(x - 2, y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x , y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x-1, y + 2) && f.isblock(x , y + 1))
					pos_y++;
				return;
			}
		}//Z-dir
	case T:
		switch (this->dir){
		case 0:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y ) && f.isblock(x - 1, y-1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 2, y))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y+1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}
		case 1:
			switch (info){
			case 0://左
				if (f.isblock(x -1, y - 1) && f.isblock(x - 1, y) && f.isblock(x - 1, y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 2, y) && f.isblock(x + 1, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x, y + 2) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}
		case 2:
			switch (info){
			case 0://左
				if (f.isblock(x - 2, y) && f.isblock(x - 1, y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y+1) && f.isblock(x + 2, y ))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 2) && f.isblock(x + 1, y + 1))
					pos_y++;
				return;
			}
		case 3:
			switch (info){
			case 0://左
				if (f.isblock(x - 1, y - 1) && f.isblock(x - 2, y) && f.isblock(x - 1, y + 1))
					pos_x--;
				return;
			case 1://右
				if (f.isblock(x + 1, y - 1) && f.isblock(x + 1, y) && f.isblock(x+1, y + 1))
					pos_x++;
				return;
			case 2://下
				if (f.isblock(x - 1, y + 1) && f.isblock(x, y + 2))
					pos_y++;
				return;
			}//info
		}//T-dir
	}//shape
}

// O , I , L , J , S , Z  ,T
void block::spin(const frame &f){//NOT YET

	int x = pos_x;
	int y = pos_y;

	switch (this->sh){
	case O:
		return;                    
	case I:
		switch (dir){
		case 0:
			if (f.isblock(x - 1, y) && f.isblock(x + 1, y) && f.isblock(x + 2, y))
				dir++;
			else if (f.isblock(x - 2, y) && f.isblock(x - 1, y) && f.isblock(x + 1, y)){
				dir++;
				pos_x--;
			}
			else if (f.isblock(x - 3, y) && f.isblock(x - 2, y) && f.isblock(x - 1, y)){
				dir++;
				pos_x-=2;
			}
			else if (f.isblock(x + 1, y) && f.isblock(x + 2, y) && f.isblock(x + 3, y)){
				dir++;
				pos_x++;
			}
			return;
		case 1:
			if (f.isblock(x, y - 1) && f.isblock(x, y + 1) && f.isblock(x, y + 2))
				dir++;
			return;
		case 2:
			if (f.isblock(x - 2, y) && f.isblock(x - 1, y) && f.isblock(x + 1, y))
				dir++;
			else if (f.isblock(x - 3, y) && f.isblock(x - 2, y) && f.isblock(x - 1, y)){
				dir++;
				pos_x--;
			}
			else if (f.isblock(x - 1, y) && f.isblock(x + 1, y) && f.isblock(x + 2, y)){
				dir++;
				pos_x++;
			}
			else if (f.isblock(x + 1, y) && f.isblock(x + 2, y) && f.isblock(x + 3, y)){
				dir++;
				pos_x+=2;
			}
			return;
		case 3:
			if (f.isblock(x, y - 2) && f.isblock(x, y - 1) && f.isblock(x , y+ 1))
				dir = 0;
			return;
		}
	case L:
		switch (dir){
		case 0:
			if (f.isblock(x, y - 1) && f.isblock(x, y + 1) && f.isblock(x + 1, y + 1))
				dir++;
			else if (f.isblock(x, y - 2) && f.isblock(x, y - 1)){
				dir++;
				pos_y--;
			}
			return;
		case 1:
			if (f.isblock(x - 1, y - 1) && f.isblock(x - 1, y) && f.isblock(x + 1, y))
				dir++;
			else if (f.isblock(x + 1, y) && f.isblock(x + 2, y)){
				dir++;
				pos_x++;
			}
			return;
		case 2:
			if (f.isblock(x-1, y - 1) && f.isblock(x, y -1) && f.isblock(x , y + 1))
				dir++;
			return;
		case 3:
			if (f.isblock(x - 1, y ) && f.isblock(x + 1, y) && f.isblock(x + 1, y-1))
				dir = 0;
			else if (f.isblock(x -2, y) && f.isblock(x -1, y)){
				dir = 0;
				pos_x--;
			}
			else if (f.isblock(x - 2, y+1) && f.isblock(x - 1, y+1)){ //L 轉!
				dir = 0;
				pos_x--;
				pos_y++;
			}
			return;
		}
	case J:
		switch (dir){
		case 0:
			if (f.isblock(x, y - 1) && f.isblock(x + 1, y - 1) && f.isblock(x, y + 1))
				dir++;
			return;
		case 1:
			if (f.isblock(x-1, y ) && f.isblock(x + 1, y ) && f.isblock(x+1, y + 1))
				dir++;
			else if (f.isblock(x + 1, y) && f.isblock(x + 2, y) && f.isblock(x + 2, y + 1)){
				dir++;
				pos_x++;
			}
			return;
		case 2:
			if (f.isblock(x-1, y + 1) && f.isblock(x , y + 1) && f.isblock(x, y - 1))
				dir++;
			else if (f.isblock(x , y + 2) && f.isblock(x+1, y + 2)){ //J 轉!
				dir++;
				pos_x++;
				pos_y++;
			}
			return;
		case 3:
			if (f.isblock(x - 1, y-1) && f.isblock(x - 1, y) && f.isblock(x + 1, y ))
				dir = 0;
			else if (f.isblock(x -2, y-1) && f.isblock(x - 2, y) && f.isblock(x -1, y )){
				dir=0;
				pos_x--;
			}
			return;
		}
	case S:
		switch (dir){
		case 0:
			if (f.isblock(x + 1, y ) && f.isblock(x+1, y + 1))
				dir++;
			else if (f.isblock(x + 1, y) && f.isblock(x, y - 2)){
				dir++;
				pos_y--;
			}
			return;
		case 1:
			if (f.isblock(x - 1, y+1) && f.isblock(x , y + 1))
				dir++;
			else if (f.isblock(x , y+1) && f.isblock(x+2, y )){
				dir++;
				pos_x++;
			}
			return;
		case 2:
			if (f.isblock(x - 1, y-1) && f.isblock(x - 1, y ))
				dir++;
			return;
		case 3:
			if (f.isblock(x , y - 1) && f.isblock(x+1, y - 1))
				dir = 0;
			else if (f.isblock(x, y - 1) && f.isblock(x - 2, y)){
				dir = 0;
				pos_x--;
			}
			return;
	}
	case Z:
		switch (dir){
		case 0:
			if (f.isblock(x, y + 1) && f.isblock(x + 1, y - 1))
				dir++;
			else if (f.isblock(x+1, y - 1) && f.isblock(x +1, y-2)){
				dir++;
				pos_y--;
			}
			return;
		case 1:
			if (f.isblock(x-1, y ) && f.isblock(x + 1, y + 1))
				dir++;
			else if (f.isblock(x + 1, y + 1) && f.isblock(x + 2, y +1)){
				dir++;
				pos_x++;
			}
			return;
		case 2:
			if (f.isblock(x, y - 1) && f.isblock(x - 1, y + 1))
				dir++;
			return;
		case 3:
			if (f.isblock(x - 1, y-1) && f.isblock(x + 1, y))
				dir=0;
			else if (f.isblock(x -2, y - 1) && f.isblock(x -1, y - 1)){
				dir=0;
				pos_x--;
			}
			return;
		}
	case T:
		switch (dir){
		case 0:
			if (f.isblock(x, y + 1))
				dir++;
			else if (f.isblock(x, y - 2) && f.isblock(x + 1, y - 1)){
				dir++;
				pos_y--;
			}
			else if (f.isblock(x - 1, y + 1) && f.isblock(x - 1, y + 2) && f.isblock(x - 1, y + 3) && f.isblock(x, y + 2)){// triple T ??
				dir++;
				pos_x--;
				pos_y += 2;
			}
			return;
		case 1:
			if (f.isblock(x-1, y ))
				dir++;
			else if (f.isblock(x + 2, y) && f.isblock(x+1, y + 1)){
				dir++;
				pos_x++;
			}
			else if (f.isblock(x + 1, y + 1) && f.isblock(x + 2, y + 1)){// T 轉
				dir = 0;
				pos_x++;
				pos_y++;
			}
			return;
		case 2:
			if (f.isblock(x, y - 1))
				dir++;
			return;
		case 3:
			if (f.isblock(x + 1, y))
				dir=0;
			else if (f.isblock(x - 1, y-1) && f.isblock(x-2, y)){
				dir=0;
				pos_x--;
			}
			else if (f.isblock(x - 2, y + 1) && f.isblock(x - 1, y + 1)){ //t
				dir = 0;
				pos_x--;
				pos_y++;
			}
			return;
		}//T
	}//switch(SH)
}


//





void block::draw_block(bool t) const
{
	//轉換座標
	int x = pos_x - 1 ;
	int y = pos_y - 1 ;
	int d = dir;
	shape _s = sh;

	draw(x, y, _s, d , t); // 1 實心
}


void block::erase_block()const{

	//轉換座標
	int x = pos_x - 1;
	int y = pos_y - 1;
	int d = dir;
	shape _s = sh;

	erase(x, y, _s, d ); 
}


void block::display_block(int info)const{

	if (info == -1&&this->sh == I)//hold
		draw(H_X, H_Y, this->sh, 1 ,1);
	else if (info == -1){
		draw(H_X, H_Y, this->sh, 0 ,1);
	}
	else if (this->sh == I)
		draw(N_X, N_Y + SPACE * info, this->sh, 1 ,1);
	else
		draw(N_X, N_Y + SPACE * info, this->sh, 0 ,1);
}


void block::display_erase(int info)const{

	if (info == -1&& this->sh == I)//hold
		erase(H_X, H_Y, this->sh, 1);
	else if (info == -1){
		erase(H_X, H_Y, this->sh, 0);
	}
	else if (this->sh == I)
		erase(N_X, N_Y + SPACE * info, this->sh, 1);
	else
		erase(N_X, N_Y + SPACE * info, this->sh, 0);

}


block block::shadow(const frame & f){
	
	block temp = *this ;
	int y = 1;
	while (1){
		y = temp.pos_y;
		temp.move(2 ,f);
		if (y == temp.pos_y)
			break;
	}
	return temp;
}

bool block::operator==(block b)const{
	if (this->pos_x == b.pos_x && this->pos_y == b.pos_y&& this->sh == b.sh)
		return true;
	else
		return false;
}


void block::test_draw(){
	int x = 4;
	int y = 5;

	draw(x, y, O, 1 ,1);
	delay(500);
	erase(x, y, O, 1);

	for (int i = 0; i < 4; i++){
		draw(x, y, L, i ,1);
		delay(500);
		erase(x, y, L, i);
	}

	for (int i = 0; i < 4; i++){
		draw(x, y, S, i ,1);
		delay(500);
		erase(x, y, S, i );
	}

	for (int i = 0; i < 4; i++){
		draw(x, y, Z, i ,1);
		delay(500);
		erase(x, y, Z, i);
	}

	for (int i = 0; i < 4; i++){
		draw(x, y, I, i ,1);
		delay(500);
		erase(x, y, I, i);
	}

	for (int i = 0; i < 4; i++){
		draw(x, y, J, i ,1);
		delay(500);
		erase(x, y, J, i);
	}

	for (int i = 0; i < 4; i++){
		draw(x, y, T, i,1);
		delay(500);
		erase(x, y, T, i);
	}
}


int frame::success = 0;


frame::frame(){
	
	/*BOUNDARY CONDITION*/
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 22; j++){
			xy[i][j] = 8; // 8表示邊界
		}
	}

	for(int i = 1 ; i < 11;i++){
		for(int j = 0 ; j < 21 ;j++){
			xy[i][j] = 0 ; // 0表示空的
		}
	}
	
}




bool frame::isblock(int _x ,int _y) const { //檢查可不可以放block   0-> 可以 1-> 不行
	return (  xy[_x][_y] == 0 ) ;
}



void frame::place(block b){  
	
	int _x = b.pos_x;
	int _y = b.pos_y;
	int _d = b.dir;
	shape _s = b.sh;

	switch (_s){
		case O:
			//if (_y>=2)
			xy[_x][_y - 1] = 1;
			xy[_x][_y] = 1;
			//if (_y>=2)
			xy[_x + 1][_y - 1] = 1;
			xy[_x + 1][_y] = 1;
			break;
	
		case I:
			switch(_d){
					case 0:
						if (_y>=3)
						xy[_x][_y - 2] = 2;
						//if (_y>=2)
						xy[_x][_y - 1] = 2;
						xy[_x][_y	] = 2;
						xy[_x][_y + 1] = 2;
						return;
						
					case 1:
						for (int i = -1 ; i <3; i++)
							xy[_x+i][_y] = 2;
						return;
						
					case 2:
						//if (_y >= 2)
							xy[_x][_y - 1] = 2;
						for (int i = 0; i <3; i++)
							xy[_x][_y+i] = 2;
						return;
					
					case 3:
						for (int i = -2; i <2; i++)
							xy[_x + i][_y] = 2;
						return;

					default:
						gotoxy(1, 1);
						cout << "WARN ! PLACE  L";
						delay(1000);
						return;
				}

//ＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬＬ			
		case L:
			switch(_d){
					case 0:
						//if (_y >= 2)
							xy[_x + 1][_y - 1] = 3;
						for (int i = -1; i < 2; i++)
							xy[_x +i][_y] = 3;
						return;

					case 1:
						//if (_y >= 2)
							xy[_x][_y - 1] = 3;
						xy[_x][_y] = 3;
						for (int i = 0; i < 2; i++)
							xy[_x+i][_y+1] = 3;
						return;

					case 2:
						for (int i = -1; i < 2; i++)
							xy[_x + i][_y] = 3;
						xy[_x-1][_y+1] = 3;
						return;
					
					case 3:
						for (int i = -1; i < 1; i++)
							xy[_x + i][_y - 1] = 3;
						xy[_x][_y] = 3;
						xy[_x][_y+1] = 3;
						return;
					
					default:
						gotoxy(1,1);
						cout<<"W A R N! L" ;
						delay(1000);
						return;
			}
			
//ＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪＪ			
		case J:
			
			//一般狀況 
			switch(_d){
				case 0:
					//if (_y >= 2)
						xy[_x-1][_y-1] = 4;
					for (int i = -1; i < 2; i++)
						xy[_x + i][_y] = 4;
					return;
				case 1:
					//if (_y >= 2)
						for (int i = 0; i <= 1; i++)
							xy[_x + i][_y-1] = 4;
					xy[_x ][_y ] = 4;
					xy[_x ][_y + 1] = 4;
					return;
				case 2:
					for (int i = -1; i <= 1; i++)
						xy[_x + i][_y ] = 4;
					xy[_x + 1][_y + 1] = 4;
					return;
				case 3:
				//	if (_y >= 2)
						xy[_x][_y-1] = 4;
					xy[_x][_y] = 4;
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y+1] = 4;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N! J" ;
					delay(1000);
					return;
			}//end J
//ＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴＴ
		case T://7
			switch (_d){
				case 0:
					//if (_y >= 2)
						xy[_x][_y - 1] = 7;
					for(int i = -1; i <= 1; i++)
						xy[_x + i][_y ] = 7;
					return;
				case 1:
					//if (_y >= 2)
						xy[_x][_y - 1] = 7;
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y] = 7;
					xy[_x][_y + 1] = 7;
					return;
				case 2:
					for (int i = -1; i <= 1; i++)
						xy[_x + i][_y] = 7;
					xy[_x][_y + 1] = 7;
					return;
				case 3:
					
					//if (_y >= 2)	
						xy[_x ][_y-1] = 7; 
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y] = 7;
					xy[_x][_y + 1] = 7;
					return;
				default:
					gotoxy(1,1);
					cout<<"W A R N!  T" ;
					delay(1000);
					return;
					
			}//end T
//ＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳＳ
		case S: //5
			switch (_d){
				case 0:
					//if (_y >= 2)
					for (int i = 0; i <= 1; i++)
						xy[_x+i][_y - 1] = 5;
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y ] = 5;
					return;
				case 1:
					//if (_y >= 2)
						xy[_x ][_y-1] = 5; 
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y ] = 5;
					xy[_x+1][_y + 1] = 5;
					return;
				case 2:
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y] = 5;
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y+1] = 5;
					return;
				case 3:
					//if (_y >= 2)			
						xy[_x - 1][_y - 1] = 5; 
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y] = 5;
					xy[_x ][_y + 1] = 5;
					return;

				default:
					gotoxy(1,1);
					cout<<"W A R N!  S" ;
					return;
					
			}//end S
////ＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺＺ
		 case Z:
			switch (_d){
				case 0:
				//	if (_y >= 2)
						for (int i = -1; i <= 0; i++)
							xy[_x + i][_y-1] = 6;
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y] = 6;
					return;
				case 1:
				//	if (_y >= 2)
						xy[_x + 1][_y-1] = 6;
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y] = 6;
					xy[_x ][_y + 1] = 6;
					return;
				case 2:
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y ] = 6;
					for (int i = 0; i <= 1; i++)
						xy[_x + i][_y + 1] = 6;
					return;
				case 3:
				//	if (_y >= 2)
						xy[_x ][_y - 1] = 6;
					for (int i = -1; i <= 0; i++)
						xy[_x + i][_y ] = 6;
					xy[_x-1][_y + 1] = 6;
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


bool frame::linecheck(int num)const{ //檢查可這行可不可以消

	for (int i = 10; i >0 ; i--){ //enhace efficiency 空格多在右邊
		if (xy[i][num] == 0)
			return false;
	}
	return true;
}



void frame::find(){			// find which line should be claer and mark it.

	for (int i = 20; i > 0; i--)
	if (linecheck(i)){
		xy[1][i] = -1; //做記號
		success++;
	}
}

void frame::replace(){
	
	int index;
	for (int i = 20; i > 0; i--){
		index = 0;// initialization and reset 
		if (xy[1][i] == -1){//need to be replace
			while (xy[1][i - index] == -1){
				index++;
			}
			if ((i - index) >= 1){// 有東西可以補(方塊下墜)
				for (int idx = 1; idx < 11; idx++){
					xy[idx][i] = xy[idx][i - index];
				}
				xy[1][i - index] = -1;//mark it!
			}
			else // 全部補0 (空的)
			{
				for (int idx = 1; idx < 11; idx++)
					xy[idx][i] = 0;
			}
			
		}//end if

	}// end for
}//end fnt 



void frame::redraw()const{
	for (int j = 1; j <= 20; j++){
		for (int i = 1; i <= 10; i++){
			
			gotoxy(X + 2 * (i - 1), Y + j - 1);
			switch (xy[i][j]){
			case 0:
				cout << "  ";
				break;
			case 1:
				textcolor(YELLOW);
				cout << "■";
				break;
			case 2:
				textcolor(LIGHTCYAN);
				cout << "■";
				break;
			case 3:
				textcolor(BROWN);
				cout << "■";
				break;
			case 4:
				textcolor(LIGHTBLUE);
				cout << "■";
				break;
			case 5:
				textcolor(LIGHTGREEN);
				cout << "■";
				break;
			case 6:
				textcolor(LIGHTRED);
				cout << "■";
				break;
			case 7:
				textcolor(LIGHTMAGENTA);
				cout << "■";
				break;
			default:
				break;
			}
		}
	}
}


bool frame::gameover()const{

	for (int i = 1; i < 11; i++){
		if (xy[i][0] != 0)
			return true;
	}
	return false;
}




void frame::show_value()const{
	textcolor(WHITE);
	gotoxy(1, 2);
	for (int i = 0; i < 22; i++){
		cout << endl;
		for (int j = 0; j < 12; j++){
			cout << xy[j][i] << " ";

		}

	}

}



//OTHER FUNCTION

char key_t() // translate key to char
{
	while (1){

		if (_kbhit())
		{
			switch(_getch())
			{
				case 0x48: // UP
					return 'u';
					
				case 0x50: // DOWN
					return 'd';
					
				case 0x4D: // Right
					return 'r';
					
				case 0x4B: // Left
					return 'l';
					
				case 0x0D: //Enter
					return 'e';
					
				case 0x20://space
					return 's';

				case 0x61: //a
					return 'a';
				
				default:
					return 'n';

			}//end switch	
		}//end if


	}// end while

}

shape random(){

	

	switch (rand() % 7 + 1 ){
	case 1:
		return O;
	case 2:
		return I;
	case 3:
		return L;
	case 4:
		return J;
	case 5:
		return S;
	case 6:
		return Z;
	case 7:
		return T;
	default:
		return NOT;
	}

}

shape random(shape s1, shape s2, shape s3, shape s4, shape s5){

	shape temp(random());
	if (temp == s1 || temp == s2 || temp == s3 || temp == s4 || temp == s5){
		shape again(random());
		temp = again;
	}
	//TBC
}

