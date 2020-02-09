/*
 * Circle.cpp
 *
 *  Created on: Nov 30, 2019
 *      Author: awabamjid
 */

#include "Circle.h"
#include<cstdlib>
#include<cmath>
Circle::Circle(int a, int b)
{
	//srand(time(NULL));
	x1 = a;
	y1 = b;
	speed = rand() % 4+1;
	//x1=50;
	//y1=50;
	radius = rand() % 20+10;
	int temp = rand() % 4;
	if (temp == 3)
	{
		x_direction = 1;
		y_direction = 1;
	}
	if (temp == 2)
	{
		x_direction = 1;
		y_direction = 0;
	}
	if (temp == 1)
	{
		x_direction = 0;
		y_direction = 1;
	}
	if (temp == 0)
	{
		x_direction = 0;
		y_direction = 0;
	}

	distance_radius = rand()%radius+10;
	timer = rand()%1000;
	color = 48;
	side_bounderies_x1 = 0;
	side_bounderies_x2 = 1280-30;
	if_to_move = true;
	move_according_to_mouse = false;
	drag_check = false;
}
void Circle::Draw_Shape(int x=0, int y=0)
{


	
	DrawCircle(x1, y1, radius, colors[color]);
	if (x == 0)
	{
		
	}
	DrawSquare(side_bounderies_x1, side_bounderies_y1, 30, colors[color]);
	DrawSquare(side_bounderies_x2, side_bounderies_y2, 30, colors[color]);


}

void Circle::move_Shape(int d=0,int c=0)
{
	if (if_to_move)
	{
		if (x_direction == 1)
			x1 += speed;
		if (x_direction == 0)
			x1 -= speed;
		if (y_direction == 1)
			y1 += speed;
		if (y_direction == 0)
			y1 -= speed;

		
		if (timer == 1000)
		{
			int c = rand() % 4;
			if (c == 0)
			{
				color = RED;
			}
			else if (c == 1)
			{
				color = BLUE;
			}
			else if (c == 2)
			{
				color = YELLOW;
			}
			else if (c == 3)
			{
				color = GREEN;
			}
			else if (c == 4)
			{
				color = PURPLE;
			}
			else if (c == 5)
			{
				color = WHITE;
			}
			else if (c == 6)
			{
				color = HONEYDEW;
			}
			else if (c == 7)
			{
				color = INDIGO;
			}
			timer = 0;

		}
		//cout << timer << endl;
		timer++;
		

	}
	side_bounderies_y1 = y1;
	side_bounderies_y2 = y1;
	if (move_according_to_mouse)
	{
		x1 = d;
		y1 = c;
	}
}
bool Circle::collision_check()
{
	if (y1 + radius >= 670)
	{
		y_direction = 0;
	}
	if (y1 - radius <= 0)
	{
		y_direction = 1;
	}
	if (x1 + radius >= 1280-30)
	{
		x_direction = 0;
	}
	if (x1 - radius <= 30)
	{
		x_direction = 1;
	}
	return 0;
}
int Circle::collision_check_with_same_object(Shape *a,bool aa=true)
{
	bool n = false;
	if (color != a->get_color() && !(drag_check))
	{
		if (aa)
		{
			float temp_distance;
			temp_distance = ((x1 - a->get_x1())*(x1 - a->get_x1())) + ((y1 - a->get_y1())*(y1 - a->get_y1()));
			temp_distance = sqrt(temp_distance);
			if (temp_distance <= (radius + a->get_distance_radius()))
			{
				
				if (x1 > a->get_x1())
				{
					x_direction = 1;
					a->set_x_direction(0);

				}
				else if (a->get_x1() > x1)
				{

					a->set_x_direction(1);
					x_direction = 0;
				}
				else if (y1 > a->get_y1())
				{
					y_direction = 1;
				}
				else if (y1 < a->get_y1())
				{
					y_direction = 0;
				}
			}
		}
	}
	if(drag_check && color == a->get_color() )
	{
		
		float temp_distance;
		temp_distance = ((x1 - a->get_x1())*(x1 - a->get_x1())) + ((y1 - a->get_y1())*(y1 - a->get_y1()));
		temp_distance = sqrt(temp_distance);
		if (temp_distance <= (radius + a->get_distance_radius()))
		{
			Set_x1_y1(-500, -500);
			set_x_direction(5);
			set_y_direction(5);

			//exit(1);
		}
	}
	if (drag_check && color != a->get_color())
	{
		if (aa)
		{
			float temp_distance;
			temp_distance = ((x1 - a->get_x1())*(x1 - a->get_x1())) + ((y1 - a->get_y1())*(y1 - a->get_y1()));
			temp_distance = sqrt(temp_distance);
			if (temp_distance <= (radius + a->get_distance_radius()))
			{
				if (x1 > a->get_x1())
				{
					x_direction = 1;
					a->set_x_direction(0);

				}
				else if (a->get_x1() > x1)
				{

					a->set_x_direction(1);
					x_direction = 0;
				}
				else if (y1 > a->get_y1())
				{
					y_direction = 1;
				}
				else if (y1 < a->get_y1())
				{
					y_direction = 0;
				}
			}
		}
	}
	return 0;

}
int Circle::get_x1()
{
	return x1;
}
int Circle::get_y1()
{
	return y1;
}
int Circle::get_distance_radius()
{
	return distance_radius;
}
int Circle::get_x_direction()
{
	return x_direction;
}
int Circle::get_y_direction()
{
	return y_direction;
}
void Circle::set_x_direction(int a)
{
	x_direction = a;
}
void Circle::set_y_direction(int a)
{
	y_direction = a;
}
void Circle::set_timer(int a)
{
	//timer = 1;
}
int Circle::get_timer()
{
	return  timer;
}
void Circle::set_color(int a)
{
	color = a;
}
int Circle::get_color()
{
	return color;
}
int Circle::inside_shape_mouse_check_clicked(int mouse_x, int mouse_y, int game=0, int colorr=0)
{
	if (game == 0)
	{
		if (((mouse_x - x1)*(mouse_x - x1)) + ((mouse_y - y1)*(mouse_y - y1)) <= ((distance_radius)*(distance_radius)))
		{
			if_to_move = false;
			move_according_to_mouse = true;
		}
	}
	if (game == 1 )
	{
		
		if (((mouse_x - x1)*(mouse_x - x1)) + ((mouse_y - y1)*(mouse_y - y1)) <= ((distance_radius)*(distance_radius)))
		{
			x1 = -500;
			y1 = -500;
			x_direction = 6;
			y_direction = 9;
			return 1;
		}
	}
	return 0;
	

}
void Circle::set_drag_check(bool a)
{
	drag_check = a;
}
/*Circle::~Circle() {
	// TODO Auto-generated destructor stub
} */


