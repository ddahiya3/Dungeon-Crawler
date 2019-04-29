#pragma once

class Projectile {
public:
	ofPoint pos;
	ofPoint mouse_clicked_at;
	ofPoint position_of_player;

	ofPoint direction_projectile;

	float speed;
	float width;
	bool from_player;

	float damage_per_hit;

	string type_of_projectile;

	void setup(bool from_player, ofPoint position_of_fire ,ofPoint mouse_position, float speed, ofImage * bullet_image, ofPoint player_position, string type_projectile);
	void update();
	void draw() const;

	float calculate_damage(string type_projectile);

	ofPoint calculate_direction(ofPoint p1, ofPoint p2) const;

	ofImage * img;
};
