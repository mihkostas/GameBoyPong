#include <gb/gb.h>
#include <stdio.h>
#include "CharactersTiles.c"
#include "mapTiles.c"
#include "mapPong.c"





struct point{
UINT8 x;
UINT8 y;
char xs;
char ys;
};

char EndgeBounce(struct point*);
void CreateSprite(char,char,char,unsigned char*);
char Culusion(struct point*,struct point*);
char Culusion2(struct point*,struct point*);
void makePong(char,char,char,char);
void scrollBigSprite(char,char,char,char);
void playSound();


void main(){
	 char fl,s=4,s2=4;
     struct point obj[3];
 	 SPRITES_8x8;
 	 //sound registers
     NR52_REG = 0x80; //turn the sound on
  	 NR50_REG = 0x77; // sets the vol for both channels
	 NR51_REG = 0xFF; // select channel to use
   
   //ball pos and speed
       obj[0].x = 30;
       obj[0].y = 75;
       obj[0].xs = 1;
       obj[0].ys = -1;
   //player1 pos
       obj[1].x = 20;
       obj[1].y = 75;        
     
   //player2 pos
       obj[2].x = 150;
       obj[2].y = 75;     
   
       
    //player1 create sprite
       CreateSprite(0,0,3,Pong);
       makePong(obj[1].x, obj[1].y,0,3);
    
   //player2 create sprite
       CreateSprite(3,0,3,Pong);
       makePong(obj[2].x, obj[2].y,3,3);
  

	//ball create sprite
	   CreateSprite(6,3,1,ball);
	   move_sprite(6, obj[0].x, obj[0].y);
	
	//score1
       CreateSprite(7,4,10,numbers);
	   move_sprite(7, 14, 23);
	
	//score2
	   CreateSprite(8,4,10,numbers);
	   move_sprite(8, 150, 23);
   
    //map
       set_bkg_data(0,9,mapTiles);
       set_bkg_tiles(0,0,20,18,mapPong);
   
   //show Data
	   SHOW_BKG;
	   DISPLAY_ON;
	   SHOW_SPRITES;

   
while(1){


   
switch(joypad()){
   	  case 0x04U:
   	  	
   	  	  scrollBigSprite(0,3,0,-2); 	  	  
  	      obj[1].y+=-2;
   	   
   	  	  break;
   	  case 0x08U: 	  	
   	  	  scrollBigSprite(0,3,0,2);  	  		  
   	  	  obj[1].y+=2;
   	 
   	  	  break;
   }
   
    
    obj[0].x+=obj[0].xs;
    obj[0].y+=obj[0].ys;
   
   
    if((char)obj[0].y%16 == 0)obj[2].y = obj[0].y;
    
    
    makePong(obj[2].x, obj[0].y,3,3);
 
    move_sprite(6, obj[0].x,obj[0].y);

	

 
    
    fl = EndgeBounce(&obj[0]);
    
   
    if(fl == 2 && s!=13)set_sprite_tile(7,++s);
    if(s==13){s=4;s2=4;}
	if(fl == 1 && s2!=13)set_sprite_tile(8,++s2);
    if(s2==13){s2=4;s=4;}
    
    
    
	 
  
    
if(Culusion(&obj[0],&obj[1]))playSound();
if(Culusion2(&obj[0],&obj[2]))playSound();



	
delay(15);	
}
}




char EndgeBounce(struct point *OBJ){

	if((*OBJ).y < (UINT8)20){
    	(*OBJ).ys = 1;
    	return 0;
	}
	else if((*OBJ).y > (UINT8)150){
    	(*OBJ).ys = -1;
    	return 0;
	}
   
  else if((*OBJ).x < (UINT8)10){
    	(*OBJ).xs = 1;
    	return 1;
	}
   else if((*OBJ).x> (UINT8)160){
    	(*OBJ).xs = -1;
    	return 2;
	}
   else{
   	  return 0;
   	
   }
		
		
}


char Culusion(struct point *OBJ,struct point *OBJ2){


if((*OBJ).x <= (*OBJ2).x+7 && (*OBJ).x >= (*OBJ2).x){
	  if((*OBJ).y >= (*OBJ2).y && (*OBJ).y <= (*OBJ2).y+16){
    	   if((*OBJ).xs != 1){
		      (*OBJ).xs = 2;
    	       return 1;
         }
      }
}

return 0;
	
}

char Culusion2(struct point *OBJ,struct point *OBJ2){


if((*OBJ2).x <= (*OBJ).x+7 && (*OBJ2).x >= (*OBJ).x){
    if((*OBJ).y >= (*OBJ2).y && (*OBJ).y <= (*OBJ2).y+16){
	    if((*OBJ).xs != -1){
			(*OBJ).xs = -2;
    	    return 1;
	    }
    }
}


return 0;
	
}


void CreateSprite(char id,char memory,char load,unsigned char* tileMap){
	char i;
	set_sprite_data(memory,load, tileMap);
	for(i=0;i<load;i++)set_sprite_tile(id+i,memory+i);
	
	



}

void makePong(char x,char y,char stId,char n){
	char i;
	for(i=0;i<n;i++){
	
		move_sprite(stId, x, y);
		stId++;
		y+=8;
	}

	
}


void scrollBigSprite(char stId,char n,char x,char y){
	char i;
	for(i=0;i<n;i++){
		scroll_sprite(stId,x,y);
		stId++;
		
	}
	
	
	
	
}

void playSound(){
    	 NR10_REG = 0x17; // 0001 0111		 
		 NR11_REG = 0x40; // 0100 0000
		 NR12_REG = 0x72; // 0111 0010
		 NR13_REG = 0x00; // 0000 0000
		 NR14_REG = 0xC4; // 1100 0100
}




