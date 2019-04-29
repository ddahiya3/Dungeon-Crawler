#pragma once

class Enemy {
public:
	ofPoint pos;
	float width;

	float start_shoot;
	float shoot_interval;
	float speed;

	float health;

	string type_of_enenmy;

	float damage_done_per_hit;

	void setup(float max_enemy_shoot_interval, ofImage * enemy_image, string enemy_type);
	void update();
	void draw() const;
	bool time_to_shoot();

	float calculate_health(string enemy);

	ofImage * img;
};
