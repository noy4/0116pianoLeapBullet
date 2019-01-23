#include "ofApp.h"

//--------------------------------------------------------------


void ofApp::setup(){
    
    ofSetFrameRate(60); //画面設定
    ofSetVerticalSync(true);
    
    page = 1;
    pageSpace = 1350;
    toSwipe = 0;
    bPlay = false;
    
    string tekkin[] = {"sounds/tekkinC.mp3", "sounds/tekkinC#.mp3", "sounds/tekkinD.mp3",
        "sounds/tekkinD#.mp3", "sounds/tekkinE.mp3", "sounds/tekkinF.mp3", "sounds/tekkinF#.mp3",
        "sounds/tekkinG.mp3", "sounds/tekkinG#.mp3", "sounds/tekkinA.mp3", "sounds/tekkinA#.mp3",
        "sounds/tekkinB.mp3", "sounds/tekkinC2.mp3"
    };
    
	leap.open(); //リープ使います宣言
    leap.setupGestures();
    
    // keep app receiving data from leap motion even when it's in the background
    leap.setReceiveBackgroundFrames(true);
    
//    cam.setPosition(ofVec3f(50, 0, 0));
//    cam.lookAt(ofVec3f(20, 0, 0), ofVec3f(0, 1, 0));
    
    cam.setOrientation(ofVec3f(-20,0,0));
    
    world.setup();
    world.enableGrabbing();
    
    world.enableCollisionEvents(); //衝突検知します宣言
    ofAddListener(world.COLLISION_EVENT, this, &ofApp::onCollision); //衝突検知したとき発動する関数のセット
    
//    world.enableDebugDraw(); //輪郭というか辺
    world.setCamera(&cam);
    world.setGravity( ofVec3f(0, -9.8, 0) ); //重力セット
    
    sphere = new ofxBulletSphere();
    sphere->create(world.world, ofVec3f(0, 100, -100), 0.1, 5);
    sphere->add();
    
    ground.create( world.world, ofVec3f(0., -600, 0.), 0., 2000.f, 1.f, 2000.f );
    ground.setProperties(.25, .95);
    ground.add();
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    light.setPosition(0, 1000, 500);
    
    int ii = 0;
    
    pagePosition = -(page-1) * pageSpace;
    ofPoint centerPos = ofPoint(0, -150, 150);
    ofPoint sharpPos = ofPoint(0, 120, -100);
    int octCount = 0;
    ofVec3f diff;
    int key;
    float keyNum;
    double r = 500;
    double angle;
    double angleSpace = 4.2;
    double curve = 1.4;
    
    handSphere = ofBtGetSphereCollisionShape(20);
    for (int i = 0; i < 40; i++) {
        handSpheres.push_back( new ofxBulletSphere() );
        ii = handSpheres.size()-1;
        ((ofxBulletSphere*)handSpheres[ii])->init(handSphere);
        // no need to pass radius, since we already created it in the sphereShape //
        ((ofxBulletSphere*)handSpheres[ii])->create(world.world, ofVec3f(ofRandom(-100, 100), -600, ofRandom(-500, -400)), 0.1);
        handSpheres[ii]->setActivationState( DISABLE_DEACTIVATION );
        handSpheres[ii]->add();
        handHits.push_back( false );
    }
    
    sphereShape = ofBtGetSphereCollisionShape(40);
    for (int i = 0; i < 13; i++) {
        ofSoundPlayer sound;
        sound.load(tekkin[i]);
        sound.setVolume(0.2);
        sound.setMultiPlay(true);
        sounds.push_back(sound);
        toPiano.push_back(0);
        
        shapes.push_back( new ofxBulletSphere() );
        ii = shapes.size()-1;
        ((ofxBulletSphere*)shapes[ii])->init(sphereShape);
        
        key = i % 12;
        switch (key) {
            case 1:
            case 3:
                keyNum = key / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                ((ofxBulletSphere*)shapes[ii])->create(world.world, ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y + sharpPos.y, centerPos.z -r/curve*sin(angle)), 0.1);
                break;
            case 6:
            case 8:
            case 10:
                keyNum = (key+1) / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                ((ofxBulletSphere*)shapes[ii])->create(world.world, ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y + sharpPos.y, centerPos.z -r/curve*sin(angle)), 0.1);
                break;
            case 0:
            case 2:
            case 4:
                keyNum = key / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                ((ofxBulletSphere*)shapes[ii])->create(world.world, ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y, centerPos.z -r/curve*sin(angle)), 0.1);
                break;
            case 5:
            case 7:
            case 9:
            case 11:
                keyNum = (key+1) / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                ((ofxBulletSphere*)shapes[ii])->create(world.world, ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y, centerPos.z -r/curve*sin(angle)), 0.1);
                if (i % 12 == 11) octCount++;
                break;
                
            default:
                break;
        }
        
        shapes[i]->setDamping(1,.8);
        shapes[ii]->setActivationState( DISABLE_DEACTIVATION );
        shapes[ii]->add();
        sphereHits.push_back( false );
    }
    
    pagePosition = -(page) * pageSpace;
    int sixteen = 0;
    centerPos.y = 250;
    angleSpace = 4.8;
    sphereShape = ofBtGetSphereCollisionShape(30);
    for (int i = 0; i < 96; i++) {
        soundSpheres.push_back( new ofxBulletSphere() );
        ii = soundSpheres.size()-1;
        ((ofxBulletSphere*)soundSpheres[ii])->init(sphereShape);
        
        angle = (i % 16) / angleSpace;
        ((ofxBulletSphere*)soundSpheres[ii])->create(world.world, ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y - (sixteen*100), centerPos.z -r/1.3*sin(angle)), 0.1);
        if (i % 16 == 15) sixteen += 1;
        
        soundSpheres[i]->setDamping(1,.8);
        soundSpheres[ii]->setActivationState( DISABLE_DEACTIVATION );
        soundSpheres[ii]->add();
        toBeat.push_back( 0 );
        bOn.push_back(false);
    }
    
    sphereShape = ofBtGetSphereCollisionShape(40);
    for (int i = 0; i < 3; i++) {
        buttonSpheres.push_back( new ofxBulletSphere() );
        ii = buttonSpheres.size()-1;
        ((ofxBulletSphere*)buttonSpheres[ii])->init(sphereShape);
        ((ofxBulletSphere*)buttonSpheres[ii])->create(world.world, ofVec3f(200.0*(i - 1) + pagePosition, -400, 0), 0.1);
        buttonSpheres[ii]->setDamping(1, .8);
        buttonSpheres[ii]->setActivationState( DISABLE_DEACTIVATION );
        buttonSpheres[ii]->add();
        toButton.push_back( 0 );
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    world.update();
	fingersFound.clear();
    
    for (int i = 0; i < toPiano.size(); i++) {
        if (toPiano[i] > 0) toPiano[i] -= 1;
    }
    for (int i = 0; i < toButton.size(); i++) {
        if (toButton[i] > 0) toButton[i] -= 1;
    }
    for (int i = 0; i < toBeat.size(); i++) {
        if (toBeat[i] > 0) toBeat[i] -= 1;
    }
    
    if (toSwipe > 0) toSwipe -= 1;
    switch (leap.iGestures) {
        case 4:
            if (page < 2 && toSwipe == 0) {
                page += 1;
                toSwipe = 20;
            }
            break;
        case 3:
            if (page > 0 && toSwipe == 0) {
                page -= 1;
                toSwipe = 20;
            }
            
        default:
            break;
    }
    
    pagePosition = -(page-1) * pageSpace;
    ofPoint centerPos = ofPoint(0, -150, 150);
    ofPoint sharpPos = ofPoint(0, 120, -100);
    int octCount = 0;
    ofVec3f diff;
    int key;
    float keyNum;
    double r = 500;
    double angle;
    double angleSpace = 4.2;
    double curve = 1.4;
    for(int i = 0; i < shapes.size(); i++){
        key = i % 12;
        switch (key) {
            case 1:
            case 3:
                keyNum = key / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                diff = ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y + sharpPos.y, centerPos.z -r/curve*sin(angle)) - shapes[i]->getPosition();
                break;
            case 6:
            case 8:
            case 10:
                keyNum = (key+1) / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                diff = ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y + sharpPos.y, centerPos.z -r/curve*sin(angle)) - shapes[i]->getPosition();
                break;
            case 0:
            case 2:
            case 4:
                keyNum = key / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                diff = ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y, centerPos.z -r/curve*sin(angle)) - shapes[i]->getPosition();
                break;
            case 5:
            case 7:
            case 9:
            case 11:
                keyNum = (key+1) / 2.0;
                angle = (keyNum + (7*octCount))/angleSpace;
                diff = ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y, centerPos.z -r/curve*sin(angle)) - shapes[i]->getPosition();
                if (i % 12 == 11) octCount++;
                break;
                
            default:
                break;
        }
        diff *= 40;
        shapes[i]->applyCentralForce(diff);
    }
    
    pagePosition = -(page) * pageSpace;
    int sixteen = 0;
    centerPos.y = 250;
    angleSpace = 4.8;
    
    for(int i = 0; i < soundSpheres.size(); i++){
        angle = (i % 16) / angleSpace;
        diff = ofVec3f(centerPos.x -r*cos(angle) + pagePosition, centerPos.y - (sixteen*100), centerPos.z -r/1.3*sin(angle)) - soundSpheres[i]->getPosition();
        if (i % 16 == 15) sixteen += 1;
        
        diff *= 40;
        soundSpheres[i]->applyCentralForce(diff);
    }
    
    for (int i = 0; i < buttonSpheres.size(); i++) {
        diff = ofVec3f(200.0*(i - 1) + pagePosition, -400, 0) - buttonSpheres[i]->getPosition();
        diff *= 40;
        buttonSpheres[i]->applyCentralForce(diff);
    }
    
    simpleHands = leap.getSimpleHands(); //手の数取得
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
		leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < simpleHands.size(); i++){  //手の数繰り返し
            for (int f=0; f<5; f++) { //指の数繰り返し
                
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal 第三関節
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal 第二関節
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal 第一関節
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip さきっちょ
                ofPoint vel = simpleHands[i].fingers[ fingerTypes[f] ].vel;
                fingersFound.push_back(id);
                
                btVector3 velocity = btVector3(vel.x, vel.y, vel.z);
                
                btTransform tipTrans = ofGetBtTransformFromVec3f(ofVec3f(tip.x, tip.y, tip.z));
                handSpheres[f*4 + (20*i)]->getRigidBody()->setWorldTransform(tipTrans);
                handSpheres[f*4 + (20*i)]->getRigidBody()->getMotionState()->setWorldTransform(tipTrans);
                handSpheres[f*4 + (20*i)]->getRigidBody()->setLinearVelocity(velocity);
                
                btTransform dipTrans = ofGetBtTransformFromVec3f(ofVec3f(dip.x, dip.y, dip.z));
                handSpheres[f*4+1 + (20*i)]->getRigidBody()->setWorldTransform(dipTrans);
                handSpheres[f*4+1 + (20*i)]->getRigidBody()->getMotionState()->setWorldTransform(dipTrans);
                
                btTransform pipTrans = ofGetBtTransformFromVec3f(ofVec3f(pip.x, pip.y, pip.z));
                handSpheres[f*4+2 + (20*i)]->getRigidBody()->setWorldTransform(pipTrans);
                handSpheres[f*4+2 + (20*i)]->getRigidBody()->getMotionState()->setWorldTransform(pipTrans);
                
                btTransform mcpTrans = ofGetBtTransformFromVec3f(ofVec3f(mcp.x, mcp.y, mcp.z));
                handSpheres[f*4+3 + (20*i)]->getRigidBody()->setWorldTransform(mcpTrans);
                handSpheres[f*4+3 + (20*i)]->getRigidBody()->getMotionState()->setWorldTransform(mcpTrans);
            }
        }
    }
    
//    for (int i = 0; i < handHits.size(); i++){
//        for (int j = 0; j < sphereHits.size(); j++) {
//            if (sphereHits[j] == true && toPiano[j] == 0) {
//                sounds[j].play();
//                toPiano[j] = 10;
//            }
//        }
//    }
    
//    if (toPlayTime % 30 == 0 && toPlayTime%30 < sounds.size()) {
//        sounds[toPlayTime / 30].play();
//    }
//    toPlayTime += 1;
//    if (toPlayTime/30 >= sounds.size()){
//        toPlayTime = 0;
//    }
    
    for (int i = 0; i < handSpheres.size(); i++) {
        handHits[i] = false;
    }
    
    for (int i = 0; i < shapes.size(); i++) {
        sphereHits[i] = false;
    }
    
	//IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
    leap.updateGestures();
	leap.markFrameAsOld();
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(200,200,200), ofColor(100, 200, 0),  OF_GRADIENT_BAR);
	
	ofSetColor(200);
	ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    
    glEnable( GL_DEPTH_TEST ); //隠面消去
	cam.begin();
    
    ofSetLineWidth(1.f);
    ofSetColor(255, 0, 200);
//    world.drawDebug(); //輪郭というか辺と軸線
    
    ofEnableLighting();
    light.enable();
    
    ofSetColor(0, 100, 100, 50);
    ground.draw();
    
    ofSetColor(0,0,0);
    sphere->draw();
    
    for(int i = 0; i < shapes.size(); i++) {
        ofSetColor(255,100,toPiano[i]*10 + 155);
        shapes[i]->draw();
    }
    
    ofSetColor(100,255,100);
    int sixteen = 0;
    int bar = 0;
    for(int i = 0; i < soundSpheres.size(); i++) {
        
        if (!bOn[i]) {
            switch (bar % 2) {
                case 0:
                    ofSetColor(255);
                    soundSpheres[i]->draw();
                    break;
                case 1:
                    ofSetColor(200);
                    soundSpheres[i]->draw();
                    break;
                    
                default:
                    break;
            }
        } else {
            ofSetColor(255, 150, 0);
            soundSpheres[i]->draw();
        }
    
        if (i % 4 == 3) bar += 1;
        if (i % 16 == 15){
            sixteen += 1;
            bar = 0;
        }
    }
    
    ofSetColor(0,200,200);
    for(int i = 0; i < handSpheres.size(); i++) {
        handSpheres[i]->draw();
    }
    
    for(int i = 0; i < buttonSpheres.size(); i++) {
        switch (i) {
            case 0:
                ofSetColor(0, 255, toButton[i]*8);
                break;
            case 1:
                if (bPlay) {
                    ofSetColor(255, 50, 50);
                } else {
                    ofSetColor(50, 50, 255);
                }
                break;
            case 2:
                ofSetColor(200, toButton[i]*8, toButton[i]*8);
                break;
                
            default:
                break;
        }
        buttonSpheres[i]->draw();
    }
    
    int ii = 0;
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal; //normal = 法線
        
        ofSetColor(0, 0, 255);
        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20); //真ん中に青丸
        ofSetColor(255, 255, 0);
        ofDrawArrow(handPos, handPos + 100*handNormal); //真ん中から黄色法線
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 255, 0);
            ofDrawSphere(mcp.x, mcp.y, mcp.z, 24);
            ofDrawSphere(pip.x, pip.y, pip.z, 24);
            ofDrawSphere(dip.x, dip.y, dip.z, 24);
            ofDrawSphere(tip.x, tip.y, tip.z, 24);
            
            ofSetColor(255, 0, 0);
            ofSetLineWidth(20);
            ofLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
            ofLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        }
    }
    
    light.disable();
    ofDisableLighting();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::onCollision(ofxBulletCollisionData& cdata) {
//    for(int j = 0; j < handSpheres.size(); j++) {//壁との衝突は無視
//        if(*handSpheres[j] == cdata) {
//            return;
//        }
//    }
    
    for (int i = 0; i < shapes.size(); i++) {
        if(*shapes[i] == cdata && toPiano[i] == 0) {
            sphereHits[i] = true;
            //        for (int j = 0; j < sphereHits.size(); j++) {
            //            if (sphereHits[j] == true && toSound[j] == 0) {
                            sounds[i].play();
                            toPiano[i] = 10;
            //            }
            //        }
        }
    }
    
    for (int i = 0; i < handSpheres.size(); i++) {
        if(*handSpheres[i] == cdata) {
            handHits[i] = true;
        }
    }
    
    for (int i = 0; i < buttonSpheres.size(); i++) {
        if(*buttonSpheres[i] == cdata && toButton[i] == 0) {
            switch (i) {
                case 0:
                    
                    break;
                case 1:
                    bPlay = !bPlay;
                    break;
                case 2:
                    for (int j = 0; j < soundSpheres.size(); j++) {
                        bOn[j] = false;
                    }
                    break;
                    
                default:
                    break;
            }
            
            toButton[i] = 30;
        }
    }
    
    for (int i = 0; i < soundSpheres.size(); i++) {
        if(*soundSpheres[i] == cdata && toBeat[i] == 0) {
            bOn[i] = !bOn[i];
            toBeat[i] = 30;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_RIGHT:
            if (page < 2) {
                page += 1;
            }
            break;
        case OF_KEY_LEFT:
            if (page > 0) {
                page -= 1;
            }
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}
