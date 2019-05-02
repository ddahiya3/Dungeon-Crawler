#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "ofApp.h"
#include "Player.h"
#include "ofImage.h"

TEST_CASE("Collision Logic Test") {

	ofPoint img1;
	img1.set(10, 10, 0);
	float img1_width = 10;

	ofPoint img2;
	img2.set(10, 10, 0);
	float img2_width = 10;

	REQUIRE(ofDist(img1.x, img1.y, img2.x, img2.y) < (img1_width + img2_width) / 2);

}

