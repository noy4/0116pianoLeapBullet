#include "ofApp.h"

//--------------------------------------------------------------


void ofApp::setup(){
    
    ofSetFrameRate(60); //画面設定
    ofSetVerticalSync(true);
    
    page =          1;
    pageSpace =     1350;
    toSwipe =       0;
    bPlay =         false;
    toPlayTime =    0;
    tempo =         10;
    column =        0;
    keySet =        0;
    keySet2 =       0;
    melodySet =     -1;
    menu =          false;
    menuSpace =     0;
    tutorial =      false;
    
    ofTrueTypeFontSettings settings("goPr.otf", 11);
    settings.addRanges(ofAlphabet::Emoji);//絵文字
    settings.addRanges(ofAlphabet::Japanese);//日本語
    settings.addRange(ofUnicode::Latin);//アルファベット等
    font1.load(settings);
    font1.setLineHeight(30);
    
    ofTrueTypeFontSettings settings2("goPr.otf", 30);
    settings.addRanges(ofAlphabet::Emoji);//絵文字
    settings2.addRanges(ofAlphabet::Japanese);
    settings.addRange(ofUnicode::Latin);//アルファベット等
    font2.load(settings2);
    font2.setLineHeight(50);
    
    tekkinPiano = {"sounds/tekkinC.mp3", "sounds/tekkinC#.mp3", "sounds/tekkinD.mp3",
        "sounds/tekkinD#.mp3", "sounds/tekkinE.mp3", "sounds/tekkinF.mp3", "sounds/tekkinF#.mp3",
        "sounds/tekkinG.mp3", "sounds/tekkinG#.mp3", "sounds/tekkinA.mp3", "sounds/tekkinA#.mp3",
        "sounds/tekkinB.mp3", "sounds/Piano_C.mp3",    "sounds/Piano_C#.mp3",    "sounds/Piano_D.mp3",    "sounds/Piano_D#.mp3",    "sounds/Piano_E.mp3",    "sounds/Piano_F.mp3",    "sounds/Piano_F#.mp3",    "sounds/Piano_G.mp3",    "sounds/Piano_G#.mp3",    "sounds/Piano_A.mp3",    "sounds/Piano_A#.mp3",    "sounds/Piano_B.mp3"
    };
    
    animalSoshina = {
        "sounds/ashika.mp3", "sounds/hitsuji.mp3", "sounds/inoshishi.mp3", "sounds/inu.mp3", "sounds/kakkou.mp3", "sounds/karasu.mp3", "sounds/lion.mp3", "sounds/neko.mp3", "sounds/niwatori.mp3", "sounds/uribou.mp3", "sounds/yagi.mp3", "sounds/zou.mp3", "sounds/103.mp3",    "sounds/boragino-ru.mp3",    "sounds/gekidanshiki.mp3",    "sounds/hizuke.mp3",    "sounds/houji.mp3",    "sounds/hyoukin.mp3",    "sounds/kurione.mp3",    "sounds/o-rora2.mp3",    "sounds/omae.mp3",    "sounds/reibou.mp3",    "sounds/riasushiki.mp3",    "sounds/self.mp3",    "sounds/tenkousei.mp3",    "sounds/yakoubus.mp3"
    };
    
    charactor = {
        "sounds/game_healer-attack1.mp3",    "sounds/game_healer-attack2.mp3",    "sounds/game_healer-damage1.mp3",    "sounds/game_swordman-attack1.mp3",    "sounds/game_swordman-attack3.mp3",    "sounds/game_swordwoman-attack1.mp3",    "sounds/game_swordwoman-damage1.mp3",    "sounds/game_wizard-damage1.mp3",     "sounds/info-girl1_info-girl1-ashita1.mp3",    "sounds/info-girl1_info-girl1-asu1.mp3",    "sounds/info-girl1_info-girl1-dayo1.mp3",    "sounds/info-girl1_info-girl1-deshita1.mp3",    "sounds/info-girl1_info-girl1-desu1.mp3",    "sounds/info-girl1_info-girl1-excellent1.mp3",    "sounds/info-girl1_info-girl1-ganbarimasyou1.mp3",    "sounds/info-girl1_info-girl1-kinou1.mp3",    "sounds/info-girl1_info-girl1-mamonaku1.mp3",    "sounds/info-girl1_info-girl1-omedetougozaimasu1.mp3",    "sounds/info-girl1_info-girl1-oyoso1.mp3",    "sounds/info-girl1_info-girl1-tadaima1.mp3",    "sounds/info-girl1_info-girl1-yaku1.mp3",    "sounds/info-girl1_info-girl1-zyunbihaiikana1.mp3",    "sounds/line-girl1_line-girl1-gyaaa1.mp3",    "sounds/people_people-shout-oo2.mp3"
    };
    
    drum = {
        "sounds/Drum_1.mp3",    "sounds/Drum_2.mp3",    "sounds/Drum_3.mp3",    "sounds/Drum_4.mp3",    "sounds/Drum_5.mp3",    "sounds/Drum_6.mp3",    "sounds/Drum_7.mp3",    "sounds/Drum_8.mp3",    "sounds/Drum_9.mp3",    "sounds/Drum_10.mp3", "sounds/nyu1.mp3",    "sounds/nyu2.mp3",    "sounds/nyu3.mp3",    "sounds/people_people-shout-oo1.mp3",    "sounds/puyon1.mp3",    "sounds/strike1.mp3",    "sounds/touch1.mp3",    "sounds/zombie-death-throes1.mp3", "sounds/boragino-ru.mp3",    "sounds/gekidanshiki.mp3",    "sounds/hizuke.mp3",    "sounds/houji.mp3",    "sounds/hyoukin.mp3",    "sounds/kurione.mp3"
    };
    
    drumSet = {
        "sounds/Drum_8.mp3", "sounds/Drum_5.mp3", "sounds/Drum_10.mp3", "sounds/Drum_2.mp3", "sounds/Drum_3.mp3", "sounds/Drum_4.mp3"
    };
    
    soshinaSet = {
        "sounds/boragino-ru.mp3",    "sounds/gekidanshiki.mp3",    "sounds/hizuke.mp3",
        "sounds/hyoukin.mp3",    "sounds/kurione.mp3",    "sounds/o-rora2.mp3"
    };
    
    pianoSet = {
        "sounds/Piano_C.mp3", "sounds/Piano_D.mp3", "sounds/Piano_E.mp3", "sounds/Piano_G.mp3", "sounds/Piano_A.mp3", "Piano_C5.mp3"
    };
    
    animalSet = {
        "sounds/hitsuji.mp3", "sounds/inu.mp3", "sounds/karasu.mp3", "sounds/lion.mp3", "sounds/neko.mp3", "sounds/zou.mp3"
    };
    
    charaSet = {
        "sounds/game_healer-attack1.mp3", "sounds/game_swordman-attack1.mp3", "sounds/game_swordwoman-damage1.mp3", "sounds/game_wizard-damage1.mp3", "sounds/info-girl1_info-girl1-desu1.mp3", "sounds/line-girl1_line-girl1-gyaaa1.mp3"
    };
    
    omoroSet = {
        "sounds/nyu1.mp3",    "sounds/nyu2.mp3",    "sounds/nyu3.mp3",    "sounds/people_people-shout-oo1.mp3",    "sounds/puyon1.mp3", "sounds/touch1.mp3"
    };
    
    for (int i = 0; i < 6; i++) {
        ofSoundPlayer sound;
        sound.load(drumSet[i]);
        sound.setVolume(0.2);
        sound.setMultiPlay(true);
        sounds2.push_back(sound);
    }
    
    
    melody1 = {
        1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    
	leap.open(); //リープ使います宣言
    leap.setupGestures();
    
    // keep app receiving data from leap motion even when it's in the background
    leap.setReceiveBackgroundFrames(true);
    
    cam.setOrientation(ofVec3f(-20,0,0));
    
    world.setup();
    world.enableGrabbing();
    
    world.enableCollisionEvents(); //衝突検知します宣言
    ofAddListener(world.COLLISION_EVENT, this, &ofApp::onCollision); //衝突検知したとき発動する関数のセット
    
//    world.enableDebugDraw(); //輪郭というか辺
    world.setCamera(&cam);
    world.setGravity( ofVec3f(0, -9.8, 0) );
    
    ground.create( world.world, ofVec3f(0., -550, 0.), 0., 2000.f, 1.f, 2000.f );
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
    
    sphereShape = ofBtGetSphereCollisionShape(20);
    for (int i = 0; i < 120; i++) {
        handSpheres.push_back( new ofxBulletSphere() );
        ii = handSpheres.size()-1;
        ((ofxBulletSphere*)handSpheres[ii])->init(sphereShape);
        // no need to pass radius, since we already created it in the sphereShape //
        ((ofxBulletSphere*)handSpheres[ii])->create(world.world, ofVec3f(ofRandom(-100, 100), ofRandom(-490, -480), ofRandom(-200, -100)), 0.1);
        handSpheres[ii]->setActivationState( DISABLE_DEACTIVATION );
        handSpheres[ii]->add();
    }
    
    sphereShape = ofBtGetSphereCollisionShape(40);
    for (int i = 0; i < 24; i++) {
        ofSoundPlayer sound;
        sound.load(tekkinPiano[i]);
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
    int row = 0;
    for (int i = 0; i < 16; i++) {
        buttonSpheres.push_back( new ofxBulletSphere() );
        ii = buttonSpheres.size()-1;
        ((ofxBulletSphere*)buttonSpheres[ii])->init(sphereShape);
        if (i < 3) {
            ((ofxBulletSphere*)buttonSpheres[ii])->create(world.world, ofVec3f(200.0*(i - 1) + pagePosition, -400, 0), 0.1);
        } else if (i >= 3 && i < 7) {
            ((ofxBulletSphere*)buttonSpheres[ii])->create(world.world, ofVec3f(200.0*(i - 4) - 100, 300, -100), 0.1);
        } else if (i >= 7 && i < 16) {
            ((ofxBulletSphere*)buttonSpheres[ii])->create(world.world, ofVec3f(120.0*((i - 1) % 3) + 100 + pagePosition, 900 - (100*row), 0), 0.1);
            if (i % 3 == 0) row += 1;
            if (row == 1) row += 1;
        }
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
    
    if (toSwipe > 0){
        toSwipe -= 1;
    } else if (toSwipe == 0 && leap.iGestures){
        switch (leap.iGestures) {
            case 4:
                if (page < 2) {
                    page += 1;
                    toSwipe = 20;
                }
                break;
            case 3:
                if (page > 0) {
                    page -= 1;
                    toSwipe = 20;
                }
                break;
            case 10:
                //            OF_EXIT_APP(0);
                if (tempo > 7) {
                    tempo -= 1;
                    toSwipe = 20;
                }
                break;
            case 9:
                if (tempo < 16) {
                    tempo += 1;
                    toSwipe = 20;
                }
                break;
                
            default:
                break;
        }
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
    
    int row = 0;
    for (int i = 0; i < buttonSpheres.size(); i++) {
        if (i < 3) {
            diff = ofVec3f(200.0*(i - 1) + pagePosition, -400, 0) - buttonSpheres[i]->getPosition();
        } else if (i >= 3 && i < 7){
            pagePosition = -(page-1) * pageSpace;
            diff = ofVec3f(200.0*(i - 4) - 100 + pagePosition, 300, -100) - buttonSpheres[i]->getPosition();
        } else if (i >= 7 && i < 16){
            pagePosition = -(page) * pageSpace;
            diff = ofVec3f(120.0*((i - 1) % 3) + 100 + pagePosition, 900 - (100*row) - menuSpace, 0) - buttonSpheres[i]->getPosition();
            if (i % 3 == 0) row += 1;
            if (row == 1) row += 1;
        }
        
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
            if (simpleHands[i].isLeft) {
                if (simpleHands[i].handNormal.y > 0) {
                    menu = true;
                    menuSpace = 600;
                }else{
                    menu = false;
                    menuSpace = 0;
                }
            } else {
                if (simpleHands[i].handNormal.y > 0) {
                    tutorial = true;
                }else{
                    tutorial = false;
                }
            }
            
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
    
    if (bPlay) {
        if(toPlayTime == 0){
            for (int i = 0; i < 6; i++) {
                if (bOn[column + (16*i)]) {
                    sounds2[i].play();
                }
            }
            
        }
        toPlayTime += 1;
        if (toPlayTime >= tempo) {
            toPlayTime = 0;
            column += 1;
        }
        if (column == 16) {
            column = 0;
        }
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
    ofBackgroundGradient(ofColor(200,200,200), ofColor(50, 100, 100),  OF_GRADIENT_BAR);
    
    glEnable( GL_DEPTH_TEST ); //隠面消去
	cam.begin();
    
    ofSetLineWidth(1.f);
    ofSetColor(255, 0, 200);
//    world.drawDebug(); //輪郭というか辺と軸線
    
    ofEnableLighting();
    light.enable();
    
    ofSetColor(0, 100, 100, 50);
    ground.draw();
    
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
            case 3:case 4:case 5:case 6:
                if (i - 3 == keySet) {
                    ofSetColor(20, 80, 100);
                } else {
                    ofSetColor(150, 200, 150);
                }
                break;
            case 7:case 8:case 9:
                if (i - 7 == melodySet) {
                    ofSetColor(200 - (toButton[i] * 3), 200 - (toButton[i] * 3), 100 - (toButton[i] * 3));
                } else {
                    ofSetColor(200, 200, 100);
                }
                break;
            case 10:case 11:case 12:case 13:case 14:case 15:
                if (i - 10 == keySet2) {
                    ofSetColor(20, 80, 100);
                } else {
                    ofSetColor(150, 200, 150);
                }
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
            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        }
    }
    
    
    pagePosition = -(page) * pageSpace;
    ofPoint centerPos = ofPoint(0, 300, 150);
    double r = 500;
    double curve = 1.3;
    double angle = (double(column) + (toPlayTime/double(tempo)))/ 4.8;
    ofSetColor(0);
    ofSetLineWidth(20);
    ofDrawLine(centerPos.x -r*cos(angle) + pagePosition, centerPos.y, centerPos.z -r/curve*sin(angle), centerPos.x -r*cos(angle) + pagePosition, centerPos.y -600, centerPos.z -r/curve*sin(angle));
    
    light.disable();
    ofDisableLighting();
	cam.end();
    
    ofSetColor(255, 255, 255);
    
    if (tutorial) {
        switch (page) {
            case 0:
                if (menu) {
                    font2.drawString("リズム例", 900, 150);
                    font2.drawString("音変更", 900, 400);
                } else {
                    font2.drawString("円を描いてテンポ変更", 520, 100);
                    font2.drawString("始点へ", 490, 830);
                    font2.drawString("再生\n停止", 680, 800);
                    font2.drawString("リセット", 820, 830);
                }
                break;
            case 1:
                font2.drawString("スワイプでページ移動", 520, 300);
                
            default:
                break;
        }
    }
    
    string connect;
    if (leap.isConnected()) {
        connect = "○";
    } else {
        connect = "×";
    }
    
    int bpm = 3600 / (tempo * 4);
    font1.drawString("おてて演奏器\nLeap Motion 接続：　" + connect + "\nBPM： " + ofToString(bpm), 20, 30);
    
    ofSetColor(200, 200, 200, 50);
    switch (page) {
        case 0:
            ofDrawTriangle(ofGetWindowWidth() - 60, ofGetWindowHeight() - 60, ofGetWindowWidth() - 60, ofGetWindowHeight() - 30, ofGetWindowWidth() - 30, ofGetWindowHeight() - 45);
            break;
        case 1:
            ofDrawTriangle(ofGetWindowWidth() - 60, ofGetWindowHeight() - 60, ofGetWindowWidth() - 60, ofGetWindowHeight() - 30, ofGetWindowWidth() - 30, ofGetWindowHeight() - 45);
            ofDrawTriangle(60, ofGetWindowHeight() - 60, 60, ofGetWindowHeight() - 30, 30, ofGetWindowHeight() - 45);
            break;
        case 2:
            ofDrawTriangle(60, ofGetWindowHeight() - 60, 60, ofGetWindowHeight() - 30, 30, ofGetWindowHeight() - 45);
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::onCollision(ofxBulletCollisionData& cdata) {
    
    for (int i = 0; i < shapes.size(); i++) {
        if(*shapes[i] == cdata && toPiano[i] == 0) {
            sphereHits[i] = true;
                sounds[i].play();
                toPiano[i] = 20;
        }
    }
    
    for (int i = 0; i < buttonSpheres.size(); i++) {
        if(*buttonSpheres[i] == cdata && toButton[i] == 0) {
            switch (i) {
                case 0:
                    toPlayTime = 0;
                    column = 0;
                    break;
                case 1:
                    bPlay = !bPlay;
                    break;
                case 2:
                    for (int j = 0; j < soundSpheres.size(); j++) {
                        bOn[j] = false;
                    }
                    break;
                case 3:case 4:case 5: case 6:
                    if (keySet != i - 3){
                        keySet = i - 3;
                        switch (keySet) {
                            case 0:
                                sounds.clear();
                                for (int j = 0; j < 24; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(tekkinPiano[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds.push_back(sound);
                                }
                                break;
                            case 1:
                                sounds.clear();
                                for (int j = 0; j < 24; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(animalSoshina[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds.push_back(sound);
                                }
                                break;
                            case 2:
                                sounds.clear();
                                for (int j = 0; j < 24; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(charactor[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds.push_back(sound);
                                }
                                break;
                            case 3:
                                sounds.clear();
                                for (int j = 0; j < 24; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(drum[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds.push_back(sound);
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                    break;
                case 7:case 8:case 9:
                    melodySet = i - 7;
                    bOn = melody1;
                    break;
                case 10:case 11:case 12: case 13:case 14:case 15:
                    if (keySet2 != i - 10) {
                        keySet2 = i - 10;
                        switch (keySet2) {
                            case 0:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(drumSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                            case 1:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(soshinaSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                            case 2:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(pianoSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                            case 3:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(animalSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                            case 4:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(charaSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                            case 5:
                                sounds2.clear();
                                for (int j = 0; j < 6; j++) {
                                    ofSoundPlayer sound;
                                    sound.load(omoroSet[j]);
                                    sound.setVolume(0.2);
                                    sound.setMultiPlay(true);
                                    sounds2.push_back(sound);
                                }
                                break;
                                
                            default:
                                break;
                        }
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
            break;
        case OF_KEY_DOWN:
            menu = true;
            menuSpace = 600;
        case OF_KEY_UP:
            menu = false;
            menuSpace = 0;
            
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
