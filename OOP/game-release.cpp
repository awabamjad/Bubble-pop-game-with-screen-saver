#include<Windows.h>
#include "util.h"
#include <iostream>
#include <vector>
#include <algorithm>
//#include<picture>
#include <ctime>
#include <string>
//#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cstring>
#include <fstream>
#include"Circle.h"
#include"Shape.h"
#include<mmsystem.h>
int checkk = 0;
int score=0;
int game_end_timer = 0;
bool choose_color = false;
bool menu_after = false;
int chosen_color_for_game = RED;
bool GAME = false;
//play
//CERT_BIOMETRIC_PICTURE_TYPE
//#include"RGBpixmap.h"
//RGBpixmap pix[6];

void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay(); 
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(800.0 / FPS, Timer, 0);
}
void a()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);
}
using namespace std;
const int width = 1280, height = 720;							//Size of the Window
bool k = false;
Shape *pointer_to_shape[20];
Shape *pointer_menu[10];
bool menu = true;
void Mouse_Motion(int, int);
float background = 0;
int speed = 0;
int Cursor_X = 0, Cursor_Y = 0;
bool box = true;
int box_x = 1280;
int box_line1 = 0;
bool mouse_clicked = false;
bool box_LINE1 = false;
Shape *menu_buttons[4];
#include "Square.h"
Shape *box_B = new Square(300, 50, 600);
//Shape *boundary[30];
//Variables for mouse Cursor
Square c(50, 50, 30);
Shape *AA = new Square(0, 50, 30);
Shape *menu_squares[20];
bool DRAG = false;
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Display()
{


	glClearColor(background, background, background, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//AA->Draw_Shape();
	if (game_end_timer == 5000)
	{
		DrawString(500, 500, "SCORE=" + to_string(score), colors[/*130*//*MISTY_ROSE*/RED]);
		DrawString(500, 550, "GAME ENDED" , colors[/*130*//*MISTY_ROSE*/RED]);
	}
	else
	{
		DrawTriangle(Cursor_X, Cursor_Y, Cursor_X + 15, Cursor_Y - 10, Cursor_X + 3, Cursor_Y - 18, colors[48]);
		/*for(int i=0; i<20; i++)
		{
	//		obj[i].Draw_Circle();
			obj[i].move_Circle();
			obj[i].collision_check();
		} */

		/*a->Draw_Shape();
		a->move_Shape();
		a->collision_check();*/
		if (box == true)
		{
			box_x -= 10;
		}
		if (box_x == 300)
		{
			box = false;


		}
		if (box_LINE1 == false)
		{
			box_line1++;

		}
		if (box_line1 == 555)
		{
			box_LINE1 = true;
			menu_after = true;
		}

		if (menu == true)
		{
			if (!menu_after)
				DrawSquare(box_x, 50, 600, colors[GREEN]);
			//pix[0].readBMPFile("p.bmp");
			if (!menu_after)
				DrawString(400, box_line1, "OOP PROJECT BY AWAB AMJAD ", colors[/*130*//*MISTY_ROSE*/RED]);
			if (555 - box_line1 <= 10)
				DrawString(400, box_line1 - 50, "LOADING GAME PLEASE WAIT......", colors[/*130*//*MISTY_ROSE*/BLACK]);


			if (menu_after)
			{
				if (!k)
				{

					PlaySound("Timer_Sound.wav", NULL, SND_ALIAS);
					k = true;

				}
				if (!choose_color)
				{
					//cout << box_B->get_x1() + 30 << " "<< box_B->get_y1() + 400 << endl;
					for (int i = 0; i < 20; i++)
					{

						menu_squares[i]->Draw_Shape();
						menu_squares[i]->collision_check();
						menu_squares[i]->move_Shape(Cursor_X, Cursor_Y);
						menu_squares[i]->collision_check_with_same_object(box_B,1);
						box_B->Draw_Shape();
						//	box_B->move_Shape();

						box_B->collision_check();

						//menu_buttons[0]->Draw_Shape();
						DrawRoundRect(box_B->get_x1() + 20, box_B->get_y1() + 390, 500, 50, colors[BLACK], 1);
						DrawString(box_B->get_x1() + 30, box_B->get_y1() + 400, "SCREEN SAVER ", colors[/*130*//*MISTY_ROSE*/RED]);
						DrawRoundRect(box_B->get_x1() + 20, box_B->get_y1() + 320, 500, 50, colors[BLACK], 1);
						DrawString(box_B->get_x1() + 30, box_B->get_y1() + 330, "CHOOSE COLOR ", colors[/*130*//*MISTY_ROSE*/RED]);
						DrawRoundRect(box_B->get_x1() + 20, box_B->get_y1() + 250, 500, 50, colors[BLACK], 1);
						DrawString(box_B->get_x1() + 30, box_B->get_y1() + 260, "SCREEN SAVER AND DRAG FUNCTION ", colors[/*130*//*MISTY_ROSE*/RED]);
						DrawRoundRect(box_B->get_x1() + 20, box_B->get_y1() + 180, 500, 50, colors[BLACK], 1);
						DrawString(box_B->get_x1() + 30, box_B->get_y1() + 190, "GAME", colors[/*130*//*MISTY_ROSE*/RED]);
						DrawTriangle(Cursor_X, Cursor_Y, Cursor_X + 15, Cursor_Y - 10, Cursor_X + 3, Cursor_Y - 18, colors[ORANGE]);
						if (mouse_clicked)
						{    //SCREEN SAVER 
							if (Cursor_X > box_B->get_x1() + 20 && Cursor_X < box_B->get_x1() + 500 && Cursor_Y > box_B->get_y1() + 390 && Cursor_Y < box_B->get_y1() + 390 + 50)
							{
								menu = false;
							}
							//choose color
							if (Cursor_X > box_B->get_x1() + 30 && Cursor_X < box_B->get_x1() + 500 && Cursor_Y > box_B->get_y1() + 320 && Cursor_Y < box_B->get_y1() + 320 + 50)
							{
								choose_color = true;
							}
							//SCREEN SAVER AND DRAG FUNCTION
							if (Cursor_X > box_B->get_x1() + 20 && Cursor_X < box_B->get_x1() + 500 && Cursor_Y > box_B->get_y1() + 250 && Cursor_Y < box_B->get_y1() + 250 + 50)
							{

								DRAG = true;
								menu = false;
							}
							//GAME
							if (Cursor_X > box_B->get_x1() + 20 && Cursor_X < box_B->get_x1() + 500 && Cursor_Y > box_B->get_y1() + 180 && Cursor_Y < box_B->get_y1() + 180 + 50)
							{
								menu = false;
								GAME = true;
								DRAG = false;
							}
						}
						mouse_clicked = false;
						for (int i = 0; i < 20; i++)
						{
							menu_squares[i]->collision_check_with_same_object(box_B, 0);
							box_B->collision_check_with_same_object(menu_squares[i], 0);
							for (int j = 0; j < 20; j++)
							{
								if (i != j)
								{
									menu_squares[i]->collision_check_with_same_object(menu_squares[j], 0);
								}

							}
						}

					}
					for (int i = 0; i < 20; i++)
					{
						menu_squares[i]->collision_check_with_same_object(box_B, 0);
						box_B->collision_check_with_same_object(menu_squares[i], 0);
						for (int j = 0; j < 20; j++)
						{
							if (i != j)
							{
								menu_squares[i]->collision_check_with_same_object(menu_squares[j], 0);
							}

						}
					}
				}
				if (choose_color)
				{
					DrawRoundRect(100, 500, 100, 50, colors[PURPLE], 1);
					DrawRoundRect(220, 500, 100, 50, colors[WHITE], 1);
					DrawRoundRect(340, 500, 100, 50, colors[HONEYDEW], 1);
					DrawRoundRect(460, 500, 100, 50, colors[INDIGO], 1);
					DrawRoundRect(580, 500, 100, 50, colors[RED], 1);
					DrawRoundRect(700, 500, 100, 50, colors[BLUE], 1);
					DrawRoundRect(820, 500, 100, 50, colors[YELLOW], 1);
					DrawRoundRect(940, 500, 100, 50, colors[GREEN], 1);
					DrawString(550, 300, "CHOOSE A COLOR", colors[/*130*//*MISTY_ROSE*/RED]);
					DrawTriangle(Cursor_X, Cursor_Y, Cursor_X + 15, Cursor_Y - 10, Cursor_X + 3, Cursor_Y - 18, colors[ORANGE]);
					if (mouse_clicked == true)
					{
						if (Cursor_X > 100 && Cursor_X < 100 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50) //for purple
						{
							choose_color = false;
							chosen_color_for_game = PURPLE;
						}
						if (Cursor_X > 220 && Cursor_X < 220 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50)// for white
						{
							choose_color = false;
							chosen_color_for_game = WHITE;
						}
						if (Cursor_X > 340 && Cursor_X < 340 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50)//for honeydew
						{
							choose_color = false;
							chosen_color_for_game = HONEYDEW;
						}
						if (Cursor_X > 460 && Cursor_X < 460 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50)//for indigo
						{
							choose_color = false;
							chosen_color_for_game = INDIGO;
						}
						if (Cursor_X > 580 && Cursor_X < 580 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50) // for red
						{
							choose_color = false;
							chosen_color_for_game = RED;
						}
						if (Cursor_X > 700 && Cursor_X < 700 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50) // for blue
						{
							choose_color = false;
							chosen_color_for_game = BLUE;
						}
						if (Cursor_X > 820 && Cursor_X < 820 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50) //for yellow
						{
							choose_color = false;
							chosen_color_for_game = YELLOW;
						}
						if (Cursor_X > 940 && Cursor_X < 940 + 100 && Cursor_Y > 500 && Cursor_Y < 500 + 50) //for green
						{
							choose_color = false;
							chosen_color_for_game = GREEN;
						}
					}
					mouse_clicked = false;



				}

			}
		}
		else
		{
			//	pix[0].draw();

			if (GAME)
				game_end_timer++;
			if (mouse_clicked && DRAG)
			{
				for (int i = 0; i < 10; i++)
				{
					pointer_to_shape[i]->set_drag_check(true);
					pointer_to_shape[i]->inside_shape_mouse_check_clicked(Cursor_X, Cursor_Y, 0, chosen_color_for_game);
					pointer_to_shape[i + 10]->set_drag_check(true);
					pointer_to_shape[i + 10]->inside_shape_mouse_check_clicked(Cursor_X, Cursor_Y, 0, chosen_color_for_game);
				}

			}

			//mouse_clicked = false;
			else if (mouse_clicked && GAME)
			{
				score += 20;
				cout << "V" << endl;
				bool oo = false;
				for (int i = 0; i < 10; i++)
				{
					if (pointer_to_shape[i]->inside_shape_mouse_check_clicked(Cursor_X, Cursor_Y, 1, chosen_color_for_game) == 1)
					{
						score++;
						cout << "L" << endl;
					}
					else
					{
						score--;
						oo = true;
					}

					if (pointer_to_shape[i + 10]->inside_shape_mouse_check_clicked(Cursor_X, Cursor_Y, 1, chosen_color_for_game) == 1)
					{
						score++;
						cout << "L" << endl;

					}
					else
					{
						score--;
						oo = true;
					}
					/*if (oo)
					{
						score -= 20;
					}*/
				}
			}
			mouse_clicked = false;
			if(GAME)
				DrawString(500, 700, "Timer=" + to_string(5000- game_end_timer), colors[/*130*//*MISTY_ROSE*/RED]);
			if (GAME)
				DrawString(50, 700, "SCORE=" + to_string(score), colors[/*130*//*MISTY_ROSE*/RED]);
			if (GAME)
				DrawRoundRect(0, 670, 1280, 20, colors[BLUE], 1);
			if (menu == false)
				DrawRoundRect(0, 670, 1280, 20, colors[BLUE], 1);
			if (menu == false && !GAME)
				DrawString(50, 690, "SCREEN SAVER", colors[/*130*//*MISTY_ROSE*/RED]);
			//PlaySound("Alan Walker - Sing Me To Sleep.wav", '10', SND_ALIAS);
			for (int i = 0; i < 10; i++)
			{
				pointer_to_shape[i]->Draw_Shape();
				pointer_to_shape[i]->move_Shape(Cursor_X, Cursor_Y);
				pointer_to_shape[i]->collision_check();
				pointer_to_shape[i]->set_timer(pointer_to_shape[i]->get_timer() + 1);
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (i == j)
						continue;
					pointer_to_shape[i]->collision_check_with_same_object(pointer_to_shape[j], 1);

				}
			}
			for (int i = 10; i < 20; i++)
			{
				for (int j = 10; j < 20; j++)
				{
					if (i != j)
					{
						pointer_to_shape[i]->collision_check_with_same_object(pointer_to_shape[j], 1);
					}


				}
			}
			for (int i = 10; i < 20; i++)
			{
				for (int j = 10; j < 20; j++)
				{


					pointer_to_shape[i]->circle_square_collision(pointer_to_shape[j - 10]);



				}
			}
			for (int i = 10; i < 20; i++)
			{
				pointer_to_shape[i]->Draw_Shape();
				pointer_to_shape[i]->move_Shape(Cursor_X, Cursor_Y);
				pointer_to_shape[i]->collision_check();
			}


		}
	}
	Sleep(5);
	glutPostRedisplay();
	glutSwapBuffers();
}




void NonPrintableKeys(int key, int x, int y)					//Function for Arrow and Special Keys
{
	if (key == GLUT_KEY_UP)
	{
		//menu = false;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		//background = GREEN;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		choose_color = true;
	}
	else if (key == GLUT_KEY_LEFT)
	{

	}
	glutPostRedisplay();
}
void Mouse(int button, int state, int x, int y)					//Function for Mouse Buttons
{
	//cout << x << " " << y << " " << state << " " << button << endl;
	//checkk = state;
	mouse_clicked = true;
	glutPostRedisplay();
}
void Cursor(int x, int y)								//Function for Mouse Pointer
{
	Cursor_X = x;
	Cursor_Y = 720 - y;

	glutPostRedisplay();
}
void PrintableKeys(unsigned char key, int x, int y)				//Function for Buttons with ASCII values
{
	if (key == KEY_ESC)								//Escape Key
	{
		//Closing HighScores.txt File
	}
	else if (key == 'W' || key == 'w')						//W key for Snake Movement (UP)
	{

	}
	else if (key == 'A' || key == 'a')						//A key for Snake Movement (LEFT)
	{

	}
	else if (key == 'S' || key == 's')						//S key for Snake Movement (DOWN)
	{

	}
	else if (key == 'D' || key == 'd')						//D key for Snake Movement (RIGHT)
	{

	}
	else if (key == 13)		//ENTER Key's ASCII, for selecting options in the Menu
	{

	}
	else if (key == 13)					//ENTER key's ASCII, for Change Level Menu
	{
		
	}
	else if (key == 13)
	{

	}
	else if (key == 8)		//ASCII for Backspace key
	{

	}
	else if (key == 32)						//ASCII key for SPACE, closing won or lost message
	{

	}
	else if (key == '+')								//Changing Contrast by + key
	{
		background += 0.01;
	}
	else if (key == '-')								//Changing Contrast by - key
	{
		background -= 0.01;
	}
	glutPostRedisplay();
}

int main(int argc, char*argv[])
{
	srand(time(NULL));
	cout<<"A"<<endl;
	
	bool random_initializer_check = true;
	int random_values_X[30];
	int random_values_Y[30];
	for (int i = 0; i < 30; i++)
	{
		random_values_X[i] = rand() % 700;
		random_values_Y[i] = rand() % 300;

	}

	for (int i = 0; i < 30; i++)
		cout << random_values_X[i] << " ";
	cout << endl;
	for (int i = 0; i < 30; i++)
		cout << random_values_Y[i] << " ";
	cout << endl;
	
	random_initializer_check = true;
	
	for (int i = 0; i < 10; i++)
		cout << random_values_X[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << random_values_Y[i] << " ";
	cout << endl;
	int temp1, temp2;
	int store;
	for (int i = 10; i < 20; i++)
	{

	}
	menu_buttons[0] = new Square(box_B->get_x1() + 5, box_B->get_y1() + 390, 51);
	
	cout << "Awab" << endl;

	//pix[0].readBMPFile("p.bmp",1);
	for (int i = 0; i < 20; i++)
	{
		temp1 = rand() % 10;
		temp2 = rand() % 10;
		store = random_values_X[temp1];
		random_values_X[temp1] = random_values_X[temp2];
		random_values_X[temp2] = store;
	}
	int d = rand() % 1000;
	int u = rand() % 1000;
	for (int i = 0; i < 10; i++)
	{
		pointer_to_shape[i] = new Circle(random_values_X[i], random_values_Y[i]);
	}
	for (int i = 0; i < 10; i++)
	{

	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == j)
				continue;
			pointer_to_shape[i]->collision_check_with_same_object(pointer_to_shape[j],1);

		}
	}
	for (int i = 10; i < 20; i++)
	{
		pointer_to_shape[i] = new Square(random_values_X[i], random_values_Y[i], 50);
	}

	for(int i=0; i<20; i++)
	menu_squares[i] = new Square(rand()%1250, rand()%690, 40);
	
	



	srand(time(NULL));
	InitRandomizer();
	a();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);						//Sets the initial position of our window
	glutInitWindowSize(width, height);					 	// Sets the size of our window (1280 X 720)
	glutCreateWindow("Awab");						//Sets the title of our game window
	SetCanvasSize(width, height);					 		//Sets the number of pixels (Same as Window Size)
	glutSpecialFunc(NonPrintableKeys);						//Special and Arrow Keys Function
	glutKeyboardFunc(PrintableKeys);						//Function for Key having ASCII values
	glutMouseFunc(Mouse);								//Function for Mouse Clicking
	glutSetCursor(GLUT_CURSOR_NONE);						//Hiding Standard OS Cursor in the Window
	glutPassiveMotionFunc(Cursor);							//Function for Mouse Cursor
	glutDisplayFunc(Display);							//Calling Display Function
	glutTimerFunc(5.0 / FPS, Timer, 0);					//Calling Auto_Movement Function after 250/FPS seconds with 0 as passing value
	glutMainLoop();									//Repeating the Glut Main Loop
	return 1;
}
