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

}
void Projectile::update() {
	if (from_player && pos.x != mouse_clicked_at.x && pos.y != mouse_clicked_at.y) {
		if (pos.x < mouse_clicked_at.x) {
			pos.x += speed;
		} else {
			pos.x -= speed;
		}
		if (pos.y < mouse_clicked_at.y) {
			pos.y += ((start_pos.y - mouse_clicked_at.y) / (start_pos.x - mouse_clicked_at.x))*(speed);
		} else {
			pos.y -= ((start_pos.y - mouse_clicked_at.y) / (start_pos.x - mouse_clicked_at.x))*(speed);
		}
	} else  {
		pos.y += speed;
	}
}
void Projectile::draw() const {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}
