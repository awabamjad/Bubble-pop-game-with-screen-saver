#pragma once
class Shape {
protected:
	int x_direction;
	int y_direction;
	int distance_radius;
	int timer;
	int color;
	int speed;
	int side_bounderies_x1;
	int side_bounderies_y1;
	int side_bounderies_x2;
	int side_bounderies_y2;
	int side_boundry_length;
	Shape *pointer_inside_shape;
	bool if_to_move;
	bool move_according_to_mouse;
	bool drag_check;
	bool if_draw;
public:
	Shape();
	/*virtual   ~Shape(); */
	virtual void Set_x1_y1(int, int) = 0;
	virtual void Draw_Shape(int x=0 ,int y=0) = 0;
	virtual void move_Shape(int o=0, int c=0) = 0;
	virtual bool collision_check() = 0;
	virtual int collision_check_with_same_object(Shape *,bool) = 0;
	virtual int get_x1() = 0;
	virtual int get_y1() = 0;
	virtual int get_distance_radius() = 0;
	virtual int get_x_direction() = 0;
	virtual int get_y_direction() = 0;
	virtual void set_x_direction(int) = 0;
	virtual void set_y_direction(int) = 0;
	virtual int get_timer() = 0;
	virtual void set_timer(int) = 0;
	virtual void set_color(int) = 0;
	virtual int get_color() = 0;
	virtual int inside_shape_mouse_check_clicked(int, int,int,int) = 0;
	virtual void set_drag_check(bool)=0;
	virtual void circle_square_collision(Shape *)
	{
		int x;
	}
	//virtual void Set_x2_y2(int,int);
	//virtual void Set_x3_y3(int,int);


};

