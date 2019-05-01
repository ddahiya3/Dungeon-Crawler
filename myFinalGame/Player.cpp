#include "ofMain.h"

#include "Player.h"

void Player::setup(ofImage * _img_right, ofImage * _img_left) {

	lives = 3;

	speed = 5;

	img_right = _img_right;
	img_right->resize(50, 50);

	img_left = _img_left;
	img_left->resize(50, 50);

	width = height = img_right->getWidth();

	pos.x = ofGetWidth() / 2;
	pos.y = ofGetHeight() - height * 2;

	invincible_mode = true;
}

void Player::update() {
	calculate_movement();
}

void Player::draw() const {

	if (is_right_pressed) {
		img_right->draw(pos.x - width / 2, pos.y - height / 2);
	} else if (is_left_pressed) {
		img_left->draw(pos.x - width / 2, pos.y - height / 2);
	} else {
		img_right->draw(pos.x - width / 2, pos.y - height / 2);
	}

}

void Player::calculate_movement() {

	if (is_left_pressed && pos.x > 0 + width / 2) {
		pos.x -= speed;
	}
	if (is_right_pressed && pos.x < ofGetWidth() - width / 2) {
		pos.x += speed;
	}
	if (is_up_pressed && pos.y > 0 + height / 2) {
		pos.y -= speed;
	}
	if (is_down_pressed && pos.y < ofGetHeight() - height / 2) {
		pos.y += speed;
	}
}

void Player::power_up_affect(string stat, float boost, int sign) {
	
	if (stat == "health_time") {
		invincible_mode = true;
	} else if (stat == "damage") {
		damage_per_hit += sign * boost;
	} else if (stat == "speed") {
		speed += sign * boost;
	} else if (stat == "health_no_time") {
		lives += boost;
	}
}

void Player::update_power_ups(vector <PowerUp> current_power_ups) {
	for (int i = 0; i < current_power_ups.size(); i++) {
		if (current_power_ups[i].time_effect) {
			if (ofGetElapsedTimeMillis() - current_power_ups[i].start_time >= current_power_ups[i].time_of_boost) {
				if (current_power_ups[i].stat_boosted == "health_time") {
					invincible_mode = false;
					current_power_ups.erase(current_power_ups.begin() + i);
				} else {
					power_up_affect(current_power_ups[i].stat_boosted, current_power_ups[i].affect, -1);
					current_power_ups.erase(current_power_ups.begin() + i);
				}
			}
		}
	}
}

void Player::change_image(ofImage* _img_right, ofImage* _img_left) {
	
	img_right = _img_right;
	img_right->resize(50, 50);

	img_left = _img_left;
	img_left->resize(50, 50);
}
