#include "ofMain.h"

#include "Projectile.h"

void Projectile::setup(bool from_p, ofPoint position_of_fire, ofPoint mouse_position, float speed_user, ofImage * bullet_image) {
	from_player = from_p;
	pos = position_of_fire;
	speed = speed_user + 3;
	img = bullet_image;
	width = img->getWidth();
	mouse_clicked_at = mouse_position;
	start_pos = position_of_fire;
	direction_projectile = calculate_direction(mouse_clicked_at, start_pos);


}
void Projectile::update() {
	if (from_player && pos.x != mouse_clicked_at.x && pos.y != mouse_clicked_at.y) {
		pos.x -= direction_projectile.x * speed; //* ofGetElapsedTimeMillis();
		pos.y -= direction_projectile.y * speed; //* ofGetElapsedTimeMillis();
	}
}
void Projectile::draw() const {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}

ofPoint Projectile::calculate_direction(ofPoint p1, ofPoint p2) {

	float x_new = p2.x - p1.x;
	float y_new = p2.y - p1.y;

	float normalising_number = pow(x_new,2) + pow(y_new,2);
	float normalising_factor = sqrt(normalising_number);

	ofPoint new_vect;
	new_vect.set(x_new/normalising_factor, y_new/normalising_factor);

	return new_vect;


}
