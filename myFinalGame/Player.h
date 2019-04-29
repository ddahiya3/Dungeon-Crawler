#pragma once

class Player {
public:
	ofPoint pos;

	float width, height, speed;

	int lives;

	float damage_taken_per_life;

	bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;

	float damage_per_hit;

	void setup(ofImage * _img);
	void update();
	void draw() const;
	void shoot();

	void calculate_movement();

	//bool check_can_shoot();


	ofImage * img;

};

