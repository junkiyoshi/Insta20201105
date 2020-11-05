#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 28, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofTranslate(0, -14, 0);

	int radius = 300;
	for (int y = -300; y <= 300; y += 50) {

		int start_deg = ofGetFrameNum() * ofRandom(1, 3) + y + 300;
		for (int deg = start_deg; deg < start_deg + 180; deg += 5) {

			auto location = glm::vec3(0, y, -radius);
			auto rotation_y = glm::rotate(glm::mat4(), (float)(deg * DEG_TO_RAD), glm::vec3(0, 1, 0));
			location = glm::vec4(location, 0) * rotation_y;

			ofPushMatrix();
			ofTranslate(location);
			ofRotateY(180 - deg);

			char noise_value = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, 'A', 'Z');
			this->font.drawString({ noise_value }, 0, 0);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}