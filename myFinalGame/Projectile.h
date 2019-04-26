#pragma once

class Projectile {
public:
	ofPoint pos;
	ofPoint mouse_clicked_at;
	ofPoint start_pos;

	float speed;
	float width;
	bool from_player;


	void setup(bool from_player, ofPoint position_of_fire,ofPoint mouse_position, float speed, ofImage * bullet_image);
	void update();
	void draw() const;

	ofImage * img;
};
