#pragma once
#include "PowerUp.h"

class Player {
public:
	ofPoint pos;

	float width, height, speed;

	int lives;

	float temp_speed, temp_damage;

	float damage_taken_per_life;

	bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;

	float damage_per_hit;

	bool invincible_mode;

	void setup(ofImage * _img_right, ofImage * _img_left);
	void update();
	void draw() const;
	void shoot();

	void calculate_movement();

	void power_up_affect(string stat, float boost, int sign);

	//bool check_can_shoot();

	vector <PowerUp> current_power_ups;

	void update_power_ups(vector <PowerUp> current_power_ups);

	void change_image(ofImage * _img_right, ofImage * _img_left);
	
	ofImage * img;

	ofImage * img_right;

	ofImage * img_left;

};

