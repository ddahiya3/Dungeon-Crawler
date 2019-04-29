#include "ofMain.h"

#include "Projectile.h"

void Projectile::setup(bool from_p, ofPoint position_of_fire, ofPoint mouse_position, float speed_user, ofImage * bullet_image, ofPoint player_position, string type_projectile) {

	from_player = from_p;
	pos = position_of_fire;
	speed = speed_user + 3;
	img = bullet_image;
	width = img->getWidth();
	mouse_clicked_at = mouse_position;
	damage_per_hit = calculate_damage(type_projectile);

	if (from_p) {
		direction_projectile = calculate_direction(mouse_clicked_at, position_of_fire);
	} else {
		direction_projectile = calculate_direction(player_position, position_of_fire);
	}


}
void Projectile::update() {
	pos.x -= direction_projectile.x * speed; 
	pos.y -= direction_projectile.y * speed; 

}
void Projectile::draw() const {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}

ofPoint Projectile::calculate_direction(ofPoint p1, ofPoint p2) const {

	float x_new = p2.x - p1.x;
	float y_new = p2.y - p1.y;

	float normalising_number = pow(x_new,2) + pow(y_new,2);
	float normalising_factor = sqrt(normalising_number);

	ofPoint new_vect;
	new_vect.set(x_new/normalising_factor, y_new/normalising_factor);

	return new_vect;

}

float Projectile::calculate_damage(string type_projectile) {

	if (type_projectile == "base_enemy") {
		return 0.33;
	} else if (type_projectile == "base_player") {
		return 1.0;
	} else if (type_projectile == "second_form_enemy") {
		return 1.0;
	} else {
		return 0;
	}
}
