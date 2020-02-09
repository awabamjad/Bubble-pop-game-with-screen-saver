#pragma once
#include "Point1D.h"
#include "Shape.h"
#include"util.h"
class Square : public Point_1D, public Shape
{
public:
	Square(int, int, int);
	void Set_x1_y1(int a, int b)
	{
		x1 = a;
		y1 = b;
	}
	void Draw_Shape(int ,int );
	void move_Shape(int,int);
	int inside_shape_mouse_check_clicked(int, int,int,int);
	bool collision_check();
	int collision_check_with_same_object(Shape *,bool);

	int get_x1();
	int get_y1();
	int get_distance_radius()
	{
		return distance_radius;
	}
	int get_x_direction()
	{
		return x_direction;
	}
	int get_y_direction()
	{
		return y_direction;
	}
	void set_x_direction(int a)
	{
		x_direction = a;
	}
	void set_y_direction(int a)
	{
		y_direction = a;
	}
	void set_timer(int a)
	{
		int x;
	}
	int get_timer()
	{
		return timer;
	}
	int get_color()
	{
		
		return color;
	}
	void set_color(int a)
	{
		int x;
	}
	void circle_square_collision(Shape *);
	void set_drag_check(bool);
	/*void Draw_Shape()
	{
	   DrawSquare(x1,y1, distance_radius,colors[color]);
	} */

};


