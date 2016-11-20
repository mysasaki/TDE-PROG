#include "ofApp.h"
#include<iostream>

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(50);

	gameManager = new GameManager(GAME_PLAY);
	gamePlay = new GamePlay(gameManager);
	//std::cout << "Iniciei porra" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update() {
	//std::cout << "dei update porra" << std::endl;
	switch (gameManager->GetGameState())
	{
		//case GAME_MENU:
	case GAME_PLAY:
		gamePlay->Update(gameManager);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//std::cout << "dei draw porra" << std::endl;
	switch (gameManager->GetGameState())
	{
	case GAME_PLAY:
		//std::cout << "desenhei play porra" << std::endl;
		gamePlay->Draw(gameManager);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (gameManager->GetGameState())
	{
	case GAME_PLAY:
		gamePlay->KeyPressed(key);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	switch (gameManager->GetGameState())
	{
	case GAME_PLAY:
		gamePlay->MousePressed(ofGetMouseX(), ofGetMouseY(), button);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
