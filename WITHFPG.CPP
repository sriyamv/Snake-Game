#include <graphics.h>
//#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <bios.h>
#include <dos.h>
#include <time.h>

int strt_x = 19;
int strt_y = 15;
int end_x = 613;
int end_y = 459;

void first_page();
void start_game();
void move();
void menu();
void instructions();
int game_over();
void score_update(int);
void delete_food();

/* To store the co-ordinates of play_area and their value */
struct point
{
	int co_ordx,co_ordy;
	int value;
};

/* Display Project Authors' Names */
void credits()
{
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	setbkcolor(LIGHTGRAY);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(4);
	settextstyle(TRIPLEX_FONT, 0, 3);
	outtextxy(getmaxx()/2,100, "COMPUTER SCIENCE PROJECT");
	setcolor(BLUE);
	settextstyle(DEFAULT_FONT,0, 5);
	outtextxy(getmaxx()/2,200, "PROJECT SNAKE ");
	setcolor(MAGENTA);
	settextstyle(GOTHIC_FONT,0,5);
	outtextxy(312, 350, "BY: ");
	setcolor(GREEN);
	settextstyle(TRIPLEX_FONT, 0, 2);
	outtextxy(320, 400 , "Anusha.S and Sriya.M.V");
	getch();
	closegraph();
}
/* Displays Game Name */
void first_page()
{
	int x,y,i;

	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	cleardevice();
	x = getmaxx()/2;
	y = getmaxy()/2;
	setbkcolor(rand());
	setcolor(LIGHTRED);
	settextstyle(TRIPLEX_FONT,0,7);
	outtextxy(10,30,"SNAKE");
	setcolor(YELLOW);
	settextstyle(SMALL_FONT,0,5);
	outtextxy(425,400, "Press any key to begin");
	while(!kbhit())
	{
		setcolor(rand());
		for(int i = 0; i < 30; i++)
			circle(x,y,i);
		setcolor(rand());
		for(int j = 30; j < 70; j++)
			circle(x,y,j);
		setcolor(rand());
		for(int k=70;j<110;j++)
			circle(x,y,k);
		setcolor(rand());
		for(int l = 110; l < 150; l++)
			circle(x,y,l);
		delay(200);
	}
	closegraph();
	getch();
	menu();
}
/* Provides options to the user */
void menu()
{
	int value = 0;
	int x, y;
	int startcoordx = 14, startcoordy = 10;

	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	int midx = getmaxx() / 2;

	setcolor(12);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(4, HORIZ_DIR, 8);
	outtextxy(midx, 100, "MENU");

	setfillstyle(SOLID_FILL,YELLOW);
	bar(440,200,200,240);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(315,215,"New Game");

	setfillstyle(SOLID_FILL,BLACK);
	bar(440,270,200,310);
	setcolor(RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(323,283,"Instructions");

	setfillstyle(SOLID_FILL,BLACK);
	bar(440,340,200,380);
	setcolor(GREEN);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(320,360,"Exit ");

	x = 12 , y = 6;
	for(int i = 0; i <= 35 ; i++)
	{
			setcolor(YELLOW);
			ellipse(startcoordx, startcoordy, 0, 360, x, y);
			setfillstyle(SOLID_FILL, RED);
			fillellipse(startcoordx, startcoordy, x, y);
			startcoordx += 17;
			delay(18);
	}
	x = 6, y = 12;
	for(int j = 0; j <= 26 ; j++)
	{
			setcolor(GREEN);
			ellipse(startcoordx, startcoordy, 0, 360, x, y);
			setfillstyle(SOLID_FILL, BLUE);
			fillellipse(startcoordx, startcoordy, x, y);
			startcoordy += 17;
			delay(18);
	}
	x = 12, y = 6;
	for(int k = 0; k <= 35 ; k++)
	{
			setcolor(RED);
			ellipse(startcoordx, startcoordy, 0, 360, x, y);
			setfillstyle(SOLID_FILL, YELLOW);
			fillellipse(startcoordx, startcoordy, x, y);
			startcoordx -= 17;
			delay(18);
	}
	x = 6, y = 12;
	for(int l = 0; l <= 26 ; l++)
	{
			setcolor(BLUE);
			ellipse(startcoordx, startcoordy, 0, 360, x, y);
			setfillstyle(SOLID_FILL, GREEN);
			fillellipse(startcoordx, startcoordy, x, y);
			startcoordy -= 17;
			delay(18);
	}
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(325,400,"PRESS ENTER WHEN OPTION IS HIGHLIGHTED ");

	do
	{
		int start1 = 200;
		int start2 = 240;
		if(kbhit())
		{
			value = 1;
			break;
		}
		setfillstyle(SOLID_FILL,BLACK);
		bar(440,200,200,240);
		setcolor(BLUE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(315,215,"New Game");

		setfillstyle(SOLID_FILL,YELLOW);
		bar(440,start1 + 70,200,start2 + 70);
		setcolor(RED);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(323,283,"Instructions");
		delay(800);
		if(kbhit())
		{
			value = 2;
			break;
		}
		setfillstyle(SOLID_FILL,BLACK);
		bar(440,start1 + 70,200,start2 + 70);
		setcolor(RED);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(323,283,"Instructions");

		setfillstyle(SOLID_FILL,YELLOW);
		bar(440,start1 + 140,200,start2 + 140);
		setcolor(GREEN);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(320,360,"Exit");
		delay(800);
		if(kbhit())
		{
			value = 3;
			break;
		}
		setfillstyle(SOLID_FILL,BLACK);
		bar(440,start1 + 140,200,start2 + 140);
		setcolor(GREEN);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(320,360,"Exit");

		setfillstyle(SOLID_FILL,YELLOW);
		bar(440,start1,200,start2);
		setcolor(BLUE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
		outtextxy(315,215,"New Game");
		delay(800);

	}while(!value);
	closegraph();

	switch(value)
	{
		case 1 :
		{
			start_game();
			break;
		}
		case 2 :
		{
			instructions();
			break;
		}
		case 3 :
		{
			exit(0);
		}
	}
}
/* A class to store attributes of snake object */
class snake
{
	public :
	int pos_snake[100][2];
	int no_of_units;
	int cur_dirn;    // 1 - right, 2 - left, 3 - up, 4 - down
	snake();
	void snake_create(point p[100][75]);
	~snake()
	{
	}

};
	/* Constructor of snake to initialise snake units and direction */
	snake::snake()
	{
		no_of_units = 5;
		cur_dirn = 2;
	}
	/* Function to initialise snake positions */
	void snake::snake_create(point p[100][75])
	{
	      for(int i = 4; i >= 0; i--)
	      {
			pos_snake[i][0] =  p[strt_x + i][strt_y].co_ordx;
			pos_snake[i][1] =  p[strt_x + i][strt_y].co_ordy;
	      }
	}
/* Class to score attributes of scores */
class score
{
	public :
	int score_update;
	score()
	{
		score_update = 0;
	}
	~score()
	{
	}
};
/* Class to store attributes of food */
class food
{
	public :
	int food_co_ordx, food_co_ordy;
	int fx,fy;
	food()
	{
		food_co_ordx = 0;
		food_co_ordy = 0;
		fx = 0;
		fy = 0;
	}
	~food()
	{
	}
};
/* Class to initialise a playing arena and the objects to be present in it.
   Initialises food, snake and score. Snake moves within this arena */
class play_area
{
	public :
	int dly;
	point p[100][75];
	snake s;
	food f;
	score scr;
	int x1,y1,x2,y2; //Co-ordinates of head and tail of snake respectively
	play_area();
	void init_snake();
	int chng_dirn();
	int move_one_step_right();
	int move_one_step_left();
	int move_one_step_up();
	int move_one_step_down();
	void draw_unit();
	void delete_unit();
	void move();
	int test();
	void create_food();
	void delete_food();
	void foodhit();
	~play_area()
	{
	}
};
	/* Constructor to initialise playarea */
	play_area::play_area()
	{
		int x = 0,y;
		for(int i = 0; i < 100; i++)
		{
			y = 0;
		    for(int j = 0; j < 75; j++)
		    {
				p[i][j].value = 0;
				p[i][j].co_ordx = strt_x + x;
				p[i][j].co_ordy = strt_y + y;
				y += 6;
		    }
		    x += 6;
		}
		int ax = 6 , by = 3;
		int startcoordx = 3, startcoordy = 3;
		for(i = 0; i <= 62 ; i++)
		{
			setcolor(BLUE);
			ellipse(startcoordx, startcoordy, 0, 360, ax, by);
			setfillstyle(SOLID_FILL, GREEN);
			fillellipse(startcoordx, startcoordy, ax, by);
			startcoordx += 10;
			if( startcoordx == 715 )
				break;

		}
		ax = 3, by = 6;
		for(int j = 0; j <= 46 ; j++)
		{
			setcolor(BLUE);
			ellipse(startcoordx, startcoordy, 0, 360, ax, by);
			setfillstyle(SOLID_FILL, GREEN);
			fillellipse(startcoordx, startcoordy, ax, by);
			startcoordy += 10;
			if( startcoordy == 470 )
				break;
		}
		ax = 6, by = 3;
		for(int k = 0; k <= 62 ; k++)
		{
			setcolor(BLUE);
			ellipse(startcoordx, startcoordy, 0, 360, ax, by);
			setfillstyle(SOLID_FILL, GREEN);
			fillellipse(startcoordx, startcoordy, ax, by);
			startcoordx -= 10;
			if( startcoordx == 715)
				break;
		}
		ax = 3, by = 6;
		for(int l = 0; l <= 46 ; l++)
		{
			setcolor(BLUE);
			ellipse(startcoordx, startcoordy, 0, 360, ax, by);
			setfillstyle(SOLID_FILL, GREEN);
			fillellipse(startcoordx, startcoordy, ax, by);
			startcoordy -= 10;
			if( startcoordy == 470 )
				break;
		}
		dly = 150;

		s.snake_create(p);
	}
	/* Creates the snake using graphics */
	void play_area::init_snake()
	{
		time_t tm;
		srand(time(&tm));
		x1 = (s.pos_snake[0][0] - strt_x)/6;
		y1 = (s.pos_snake[0][1] - strt_y)/6;
		x2 = (s.pos_snake[s.no_of_units - 1][0] - strt_x)/6;
		y2 = (s.pos_snake[s.no_of_units - 1][1] - strt_y)/6;
		for(int i = s.no_of_units - 1; i >= 0; i--)
		{
			setcolor(5);
			circle(s.pos_snake[i][0],s.pos_snake[i][1],3);
			setfillstyle(SOLID_FILL,YELLOW);
			floodfill(s.pos_snake[i][0],s.pos_snake[i][1],MAGENTA);
			p[strt_x + i][strt_y].value = 1;
		}
	}
	/* Stores the current direction change when a key is hit */
	int play_area::chng_dirn()
	{
		long int a;
		a = bioskey(0);
		if(a == 283)
		{
			return 3;
		}
		if(a == 19200 && s.cur_dirn != 1 && s.cur_dirn != 2)
		{
			s.cur_dirn = 2;
			return 1;
		}
		if(a == 18432 && s.cur_dirn != 3 && s.cur_dirn != 4)
		{
			s.cur_dirn = 3;
			return 1;
		}
		if(a == 20480 && s.cur_dirn != 4 && s.cur_dirn != 3)
		{
			s.cur_dirn = 4;
			return 1;
		}
		if(a == 19712 && s.cur_dirn != 2 && s.cur_dirn != 1)
		{
			s.cur_dirn = 1;
			return 1;
		}
		else
		    return 0;
	}
	/* Draws unit of snake */
	void play_area::draw_unit()
	{
		s.pos_snake[0][0] = p[x1][y1].co_ordx;
		s.pos_snake[0][1] = p[x1][y1].co_ordy;
		setcolor(5);
		circle(s.pos_snake[0][0],s.pos_snake[0][1],3);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(s.pos_snake[0][0],s.pos_snake[0][1],MAGENTA);
		p[x1][y1].value = 1;
	}
	/* Deletes unit of snake */
	void play_area::delete_unit()
	{
		setcolor(BLACK);
		circle(s.pos_snake[s.no_of_units - 1][0],s.pos_snake[s.no_of_units - 1][1],3);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(s.pos_snake[s.no_of_units - 1][0],s.pos_snake[s.no_of_units - 1][1],BLACK);
		p[x2][y2].value = 0;
		for(int i = s.no_of_units - 1; i >= 1; i--)
		{
			s.pos_snake[i][0] = s.pos_snake[i - 1][0];
			s.pos_snake[i][1] = s.pos_snake[i - 1][1];
		}
	}
	/* To move the snake by one unit right */
	int play_area::move_one_step_right()
	{
			for(int i = 1; i <  s.no_of_units; i++)
			{
				if( s.pos_snake[0][0] == s.pos_snake[i][0] && s.pos_snake[0][1] == s.pos_snake[i][1])
				{
					return 1;
				}
			}
		delay(dly);
		delete_unit();
		x2++;
		x1++;
		draw_unit();
		if(s.pos_snake[s.no_of_units - 1][0] == f.food_co_ordx && s.pos_snake[s.no_of_units - 1][1] == f.food_co_ordy)
			return 2;
		else
			return 0;
	}
	/* To move the snake by one unit left */
	int play_area::move_one_step_left()
	{
			for(int i = 1; i <  s.no_of_units; i++)
			{
				if( s.pos_snake[0][0] == s.pos_snake[i][0] && s.pos_snake[0][1] == s.pos_snake[i][1])
				{
					return 1;
				}
			}
		delay(dly);
		delete_unit();
		x2--;
		x1--;
		draw_unit();
		if(s.pos_snake[s.no_of_units - 1][0] == f.food_co_ordx && s.pos_snake[s.no_of_units - 1][1] == f.food_co_ordy)
			return 2;
		else
			return 0;
	}
	/* To move the snake by one unit up */
	int play_area::move_one_step_up()
	{
			for(int i = 1; i <  s.no_of_units; i++)
			{
				if( s.pos_snake[0][0] == s.pos_snake[i][0] && s.pos_snake[0][1] == s.pos_snake[i][1])
				{
					return 1;
				}
			}
		delay(dly);
		delete_unit();
		y2--;
		y1--;
		draw_unit();
		if(s.pos_snake[s.no_of_units - 1][0] == f.food_co_ordx && s.pos_snake[s.no_of_units - 1][1] == f.food_co_ordy)
			return 2;
		else
			return 0;
	 }
	 /* To move the snake by one unit down */
	 int play_area::move_one_step_down()
	 {
			for(int i = 1; i <  s.no_of_units; i++)
			{
				if( s.pos_snake[0][0] == s.pos_snake[i][0] && s.pos_snake[0][1] == s.pos_snake[i][1])
				{
					return 1;
				}
			}
		delay(dly);
		delete_unit();
		y2++;
		y1++;
		draw_unit();
		if(s.pos_snake[s.no_of_units - 1][0] == f.food_co_ordx && s.pos_snake[s.no_of_units - 1][1] == f.food_co_ordy)
			return 2;
		else
			return 0;
	 }
	 /* To initialise movement of snake */
	 void play_area::move()
	 {
		int game = 0;
		int l;
		do
		{
			if(kbhit())
			{
				int r = chng_dirn();
				if(r == 3)
				{
					closegraph();
					//menu();
					l = r;
				}
			}
			if(s.cur_dirn != 2 && s.cur_dirn != 3)
			{
				x1 = x1 % 100;
				y1 = y1 % 75;
				x2 = x2 % 100;
				y2 = y2 % 75;
			}
			if(s.cur_dirn == 1)
			{
				int object = move_one_step_right();
				if(object == 1)
				{
					game = game_over();
					//closegraph();
				}
				if(object == 2)
					foodhit();
			}
			if(s.cur_dirn == 2)
			{
				if(x1 == 0)
				{
					x1 = 100;
					x2 = 100 - s.no_of_units;
				}
				int object = move_one_step_left();
				if(object == 1)
				{
					game = game_over();
					//closegraph();
				}
				if(object == 2)
					foodhit();
			}
			if(s.cur_dirn == 3)
			{
				if(y1 == 0)
				{
					y1 = 75;
					y2 = 75 - s.no_of_units;
				}
				int object = move_one_step_up();
				if(object == 1)
				{
					game = game_over();
				}
				if(object == 2)
					foodhit();
			}
			if(s.cur_dirn == 4)
			{
				int object = move_one_step_down();
				if(object == 1)
				{
					game = game_over();
				}
				if(object == 2)
					foodhit();
			}
			if(l == 3)
			{
				menu();
				game = 1;
			}
		}while(!game);
		score_update(scr.score_update);
	}
	/* To check if food co-ordinate coincides with snake co-ordinate */
	int play_area::test()
	{
		for(int i = 0; i < 5; i++)
		{
			if(f.food_co_ordx == s.pos_snake[i][0] && f.food_co_ordy == s.pos_snake[i][1])
				return 1;
		}
		if(f.food_co_ordx < 19 || f.food_co_ordx > 613)
			return 1;

		else if(f.food_co_ordy < 15 || f.food_co_ordy > 459)
			return 1;
		else
			return 0;
	}
	/* To create a food unit */
	void play_area::create_food()
	{
		do
		{
			f.food_co_ordx = (rand() % 100) * 6 + strt_x;
			f.fx = (f.food_co_ordx - strt_x)/6;
			f.food_co_ordy = (rand() % 100) * 6 + strt_y;
			f.fy = (f.food_co_ordx - strt_y)/6;
			p[f.fx][f.fy].value = 2;
		}while(test());
		setcolor(7);
		setfillstyle(1,random(15)+1);
		fillellipse(f.food_co_ordx,f.food_co_ordy,3,3);
	}
	/* To delete a food unit */
	void play_area::delete_food()
	{
		setcolor(BLACK);
		setfillstyle(1,BLACK);
		fillellipse(f.food_co_ordx,f.food_co_ordy,3,3);
		p[f.fx][f.fy].value = 0;
		create_food();
	}
	/* To check if snake has encountered a food unit */
	void play_area::foodhit()
	{
			if(dly > 50)
				dly -= 20;
			else if(dly > 20)
				dly -= 5;
			s.no_of_units += 2;
			scr.score_update += 100;
			delete_food();
			move();
	}
/* To display instructions on how to play the game */
void instructions()
{

	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	cleardevice();
	delay(200);
	getch();
	setbkcolor(BLUE);
	setcolor(GREEN);
	outtextxy(100,100,"HOW TO PLAY THE GAME ? ");
	setcolor(YELLOW);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	delay(300);
	outtextxy(100,120,"Use the arrow keys to navigate the snake as you please. ");
	delay(300);
	outtextxy(100,140,"The snake moves out of the screen and comes in like a marquee");
	delay(300);
	outtextxy(100,160,"on reaching the end of screen.");
	delay(300);
	outtextxy(100,180,"The game ends if the snake bites itself. ");
	delay(300);
	outtextxy(100,200,"Read instructions carefully. ");
	delay(300);
	outtextxy(100,280,"Enjoy the game ! ");
	delay(300);
	outtextxy(100,320,"PRESS ENTER TO START THE GAME ");
	delay(300);
	outtextxy(100,340,"PRESS 'M' TO GO BACK TO MAIN MENU ");
	long int a = getch();
	closegraph();
	if(a == 13)
	  start_game();
	else
	  menu();
}
/* To initialis the game by creating playarea object */
void start_game()
{
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	cleardevice();
	play_area p;
	p.create_food();
	p.init_snake();
	p.move();
}
/* To display when game ends */
int game_over()
{
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	cleardevice();
	setcolor(LIGHTRED);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
	outtextxy(getmaxx()/2,getmaxy()/2,"Game Over");
	delay(1000);
	closegraph();
	return 1;
}
/* To update score when a food is encountered */
void score_update(int score)
{
	int gdriver = DETECT, gmode, errorcode;

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	cleardevice();
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	outtextxy(getmaxx()/2 - 35,getmaxy()/2,"SCORE :    ");
	char string[25];
	itoa(score,string,10);
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	outtextxy(getmaxx()/2,getmaxy()/2,string);
	delay(1000);
	getch();
	closegraph();
	exit(0);
}
/* To execute the program */
int main(void)
{
	credits();
	first_page();
	getch();
	return 0;
}

