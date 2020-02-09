/*
 * Square.cpp
 *
 *  Created on: Dec 4, 2019
 *      Author: awabamjid
 */

#include "Square.h"
#include<cmath>
Square::Square(int a, int b, int r)
{
	x1 = a;
	y1 = b;
	distance_radius = rand() % 50;

	if (r > 50)
	{  
		distance_radius = r;
	}
	x_direction = 1;
	y_direction = 1;
	color = RED;
	side_bounderies_x1 = 0;
	side_bounderies_x2 = 1280 - 30;
	timer = rand() % 1000;
	if_to_move = true;
	move_according_to_mouse = false;
	drag_check = false;
	if_draw = true;

}
void Square::Draw_Shape(int x = 0, int y = 0)
{   if(if_draw)
	DrawSquare(x1, y1, distance_radius, colors[color]);
	DrawSquare(side_bounderies_x1, side_bounderies_y1, 30, colors[color]);
	DrawSquare(side_bounderies_x2, side_bounderies_y2, 30, colors[color]);
	if (timer == 1000)
	{
		int c = rand() % 4;
		if (c == 0)
		{
			color = PURPLE;
		}
		else if (c == 1)
		{
			color = WHITE;
		}
		else if (c == 2)
		{
			color = HONEYDEW;
		}
		else if (c == 3)
		{
			color = INDIGO;
		}
		else if (c == 4)
		{
			color = RED;
		}
		else if (c == 5)
		{
			color = BLUE;
		}
		else if (c == 6)
		{
			color = YELLOW;
		}
		else if (c == 7)
		{
			color = GREEN;
		}
		timer = 0;
	}
	timer++;
}
void Square::move_Shape(int o=0,int c = 0)
{
	if (!move_according_to_mouse)
	{
		if (if_to_move)
		{
			if (x_direction == 0)
			{
				x1 -= 1;
			}
			if (x_direction == 1)
			{
				x1 += 1;
			}
			if (y_direction == 0)
			{
				y1 -= 1;
			}
			if (y_direction == 1)
			{
				y1 += 1;
			}
		}
		side_bounderies_y1 = y1;
		side_bounderies_y2 = y1;
	}
	if (move_according_to_mouse)
	{
		x1 = o;
		y1 = c;
	}
	
}
bool Square::collision_check()
{
	

	if (x1 + distance_radius >= 1280-30)
	{

		x_direction = 0;
	}
	if (x1 == 30)

	{
		x_direction = 1;
	}
	if (y1 <= 0)
	{
		y_direction = 1;
	}
	if (y1 + distance_radius >= 670) 

	{
		y_direction = 0;
	}
	return 0;

}
int Square::collision_check_with_same_object(Shape *p, bool a=true)
{
	bool n = false;
	if (!drag_check && color == p->get_color())
	{
		if (!(x1 > p->get_x1() + p->get_distance_radius() || p->get_x1() > x1 + distance_radius || y1 + distance_radius < p->get_y1() + p->get_distance_radius() || p->get_y1() + p->get_distance_radius() < y1))
		{
			if (color != p->get_color() && a == true)
			{
				p->Set_x1_y1(-500, -500);
				p->set_x_direction(5);
				p->set_y_direction(5);
				return 0;
			}
			if (!(x1 > p->get_x1() + p->get_distance_radius() || p->get_x1() > x1 + distance_radius))
			{

				if (x1 > p->get_x1())
				{
					x_direction = 1;
					p->set_x_direction(0);
				}
				else
				{
					x_direction = 0;
					p->set_x_direction(1);
				}
			}
			if (!(y1 + distance_radius < p->get_y1() + p->get_distance_radius() || p->get_y1() + p->get_distance_radius() < y1))
			{
				if (y1 > p->get_y1())
				{
					y_direction = 1;
					p->set_y_direction(0);
				}
				else {
					y_direction = 0;
					p->set_y_direction(1);
				}
			}
		}
	}
	if (!drag_check && color==p->get_color())
	{
		if (!(x1 > p->get_x1() + p->get_distance_radius() || p->get_x1() > x1 + distance_radius || y1 + distance_radius < p->get_y1() + p->get_distance_radius() || p->get_y1() + p->get_distance_radius() < y1))
		{    
			if (color != p->get_color() && a == true)
			{
				p->Set_x1_y1(-500, -500);
				p->set_x_direction(5);
				p->set_y_direction(5);
				return 0;
			}
			if (!(x1 > p->get_x1() + p->get_distance_radius() || p->get_x1() > x1 + distance_radius))
			{

				if (x1 > p->get_x1())
				{
					x_direction = 1;
					p->set_x_direction(0);
				}
				else
				{
					x_direction = 0;
					p->set_x_direction(1);
				}
			}
			if (!(y1 + distance_radius < p->get_y1() + p->get_distance_radius() || p->get_y1() + p->get_distance_radius() < y1))
			{
				if (y1 > p->get_y1())
				{
					y_direction = 1;
					p->set_y_direction(0);
				}
				else {
					y_direction = 0;
					p->set_y_direction(1);
				}
			}
		}
	}

	if (drag_check &&  color == p->get_color())
	{
		
		if (!(x1 > p->get_x1() + p->get_distance_radius() || p->get_x1() > x1 + distance_radius || y1 + distance_radius < p->get_y1() + p->get_distance_radius() || p->get_y1() + p->get_distance_radius() < y1))
		{
			p->Set_x1_y1(-500, -500);
			p->set_x_direction(5);
			p->set_y_direction(5);
			
			
			
		} 
		cout << "Z" << endl;
	}
		return 0;
    
}
void Square::circle_square_collision(Shape *p)
{

	int square_x = p->get_x1() - p->get_distance_radius();
	int square_y = p->get_y1() - p->get_distance_radius();
	int d = p->get_distance_radius() + p->get_distance_radius();
	if (!(x1 > square_x + d || square_x > x1 + distance_radius || y1 + distance_radius < square_y || square_y + d < y1))
	{
		if (!(x1 > square_x + d || square_x > x1 + distance_radius))
		{
			if (x1 > square_x)
			{
				x_direction = 1;
				p->set_x_direction(0);
			}
			else
			{
				x_direction = 0;
				p->set_x_direction(1);
			}
		}
		else if (!(y1 + distance_radius < square_y || square_y + d < y1))
		{
			p->set_y_direction(1);
			y_direction = 0;
		}
	}


}
int Square::get_x1()
{
	return x1;
}
int Square::get_y1()
{
	return y1;
}
int Square::inside_shape_mouse_check_clicked(int x, int y,int game,int colorr)
{
	if (game == 0)
	{
		if (x > x1 && x<x1 + distance_radius && y>y1 && y < y1 + distance_radius)
		{
			move_according_to_mouse = true;
			if_to_move = false;
			//if_draw = false;
		}
	}
	if (game == 1)
	{

		//cout << "C" << endl;
		if (x > x1 && x<x1 + distance_radius && y>y1 && y < y1 + distance_radius)
		{
			x_direction = 9;
			y_direction = 9;
			Set_x1_y1(-500, -500);
			//cout << "AA" << endl;
			if (colorr == color)
			{
				return 1;
			}

		}

	}
	return 0;
}
void Square::set_drag_check(bool a)
{
	drag_check = a;
}

