#pragma once

class EnemyType1 {
public:
	ofPoint pos;
	float width;

	float start_shoot;
	float shoot_interval;
	float speed;

	void setup(float max_enemy_shoot_interval, ofImage * enemy_image);
	void update();
	void draw() const;
	bool time_to_shoot();

	ofImage * img;
};
