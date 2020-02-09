#pragma once
#include "Point1D.h"
#include"Shape.h"
#include"util.h"
#include<iostream>
using namespace std;
class Circle : public Point_1D, public Shape
{
	int radius;

public:
	Circle(int, int);
	void Set_x1_y1(int x, int y)
	{
		x1 = x;
		y1 = y;

	}
	void Draw_Shape(int ,int);
	void move_Shape(int,int);
	bool collision_check();
	int collision_check_with_same_object(Shape *,bool);
	int get_x1();
	int get_y1();
	int get_distance_radius();
	int get_x_direction();
	int get_y_direction();
	void set_x_direction(int);
	void set_y_direction(int);
	void set_timer(int);
	int get_timer();
	int get_color();
	void set_color(int);
	int inside_shape_mouse_check_clicked(int, int,int,int);
	void set_drag_check(bool);
	//virtual ~Circle();
};


