#pragma once

#include "ofMain.h"

#include "../Player.h"
#include "../Projectile.h"
#include "../Enemy.h"
#include "../GameBrain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofImage player_image;
		ofImage enemy_bullet_image;
		ofImage player_bullet_image;
		ofImage enemy_image;
		ofImage life_image;
		ofImage start_screen;
		ofImage end_screen;

		ofTrueTypeFont score_font;

		ofSoundPlayer collision_sound;


		vector<Projectile> projectile_list;
		vector<Enemy> enemies;
		//vector<Life> bonuses;

		float max_enemy_shoot_interval = 1.0;

		GameBrain game_brain;

		void update_projectiles();

		void check_collisions();

		void change_current_level();

		void enemy_and_projectiles_out_of_bounds();

		void draw_lives();
		
};
