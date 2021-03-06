#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "ofxBullet.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void onCollision(ofxBulletCollisionData& cdata);
	
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    
    ofEasyCam                       cam;
    ofLight                         light;
    
	ofxLeapMotion                       leap;
	vector <ofxLeapMotionSimpleHand>    simpleHands;
	vector <int>                        fingersFound;
    
    ofSoundPlayer           mySound;
    vector <ofSoundPlayer>  sounds;
    vector <ofSoundPlayer>  sounds2;
    vector <string>         tekkinPiano;
    vector <string>         animalSoshina;
    vector <string>         charactor;
    vector <string>         drum;
    vector <string>         drumSet;
    vector <string>         soshinaSet;
    vector <string>         pianoSet;
    vector <string>         animalSet;
    vector <string>         charaSet;
    vector <string>         omoroSet;
    vector <int>            toPiano;
    int                     toPlayTime;
    int                     column;
    vector <int>            toBeat;
    vector <int>            toButton;
    int                     keySet;
    int                     keySet2;
    int                     melodySet;
    vector <bool>           melody1;
    vector <bool>           melody2;
    vector <bool>           melody3;
    
    ofxBulletWorldRigid             world;
    ofxBulletBox                    ground;
    
    btBoxShape*                     boxShape;
    btSphereShape*                  sphereShape;
    vector<ofxBulletRigidBody*>     shapes;
    vector<ofxBulletRigidBody*>     handSpheres;
    vector<ofxBulletRigidBody*>     soundSpheres;
    vector<ofxBulletRigidBody*>     buttonSpheres;
    
    vector<bool>        sphereHits;
    vector<bool>        bOn;
    bool                bPlay;
    int                 tempo;
    
    int         page;
    double      pageSpace;
    double      pagePosition;
    int         toSwipe;
    
    bool    menu;
    double  menuSpace;
    bool    tutorial;
    
    ofTrueTypeFont font1;
    ofTrueTypeFont font2;
};
