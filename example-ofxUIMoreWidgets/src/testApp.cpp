#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetVerticalSync(true); 
	ofEnableSmoothing(); 
	
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 320-xInit; 
	
    drawPadding = false; 
    
    gui = new ofxUICanvas(0,0,length+xInit, ofGetHeight());
	gui->addWidgetDown(new ofxUILabel("MORE WIDGETS", OFX_UI_FONT_LARGE)); 
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
	gui->addWidgetDown(new ofxUILabel("MOVING GRAPH", OFX_UI_FONT_MEDIUM));         
    int bufferSize = 256; 
    vector<float> buffer; 
    for(int i = 0; i < bufferSize; i++)
    {
        buffer.push_back(100.0*sin(TWO_PI*(i/(float)bufferSize)));
    }
    mg = (ofxUIMovingGraph *) gui->addWidgetDown(new ofxUIMovingGraph(length-xInit, 64, buffer, bufferSize, -100, 100, "MOVING GRAPH")); 
        
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
    gui->addWidgetDown(new ofxUILabel("MINIMAL SLIDER", OFX_UI_FONT_LARGE)); 
    ofxUISlider *mslider = (ofxUISlider*) gui->addWidgetDown(new ofxUIMinimalSlider(length-xInit, -100, 100, 0, "MINIMAL", OFX_UI_FONT_MEDIUM)); 
    mslider->setLabelPrecision(0);
    
    gui->addWidgetDown(new ofxUIBiLabelSlider(length-xInit, 0, 100, 50.0, "LEFT", "CALM MODE", "CRAZY MODE", OFX_UI_FONT_MEDIUM));
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
    gui->addWidgetDown(new ofxUILabel("ENHANCED 2D PADS", OFX_UI_FONT_LARGE)); 
    gui->addWidgetDown(new ofxUI2DPad(length-xInit, 128, ofPoint(-100,100), ofPoint(100,-100), ofPoint(0,0), "2D PAD RANGE"));
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2));     
    mgX = (ofxUIMovingGraph *) gui->addWidgetDown(new ofxUIMovingGraph(length-xInit, 64, buffer, bufferSize, -100, 100, "X GRAPH")); 
    mgY = (ofxUIMovingGraph *) gui->addWidgetDown(new ofxUIMovingGraph(length-xInit, 64, buffer, bufferSize, -100, 100, "Y GRAPH")); 
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2));     
    vector<string> toggles; 
    toggles.push_back("FIRST");
    toggles.push_back("SECOND");
    toggles.push_back("THIRD");
    toggles.push_back("FOURTH");
    toggles.push_back("FIFTH");    
    gui->addWidgetDown(new ofxUIDropDownList(length-xInit, "DROP DOWN LIST", toggles, OFX_UI_FONT_MEDIUM)); 
    
    
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);	
    
//    gui->loadSettings("GUI/guiSettings.xml"); 
}

//--------------------------------------------------------------
void testApp::update()
{
}

//--------------------------------------------------------------
void testApp::draw()
{    
	ofBackground(200,200,200,255); 
	
	ofPushStyle(); 
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);     
	ofPopStyle(); 
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
    cout << name << endl;
    
    if(name == "MINIMAL")
    {
        ofxUISlider *mslider = (ofxUISlider *) e.widget; 
        cout << mslider->getScaledValue() << endl; 
        mg->addPoint(mslider->getScaledValue());
    }
    else if(name == "2D PAD RANGE")
    {
        ofxUI2DPad *pad = (ofxUI2DPad *) e.widget; 
        mgX->addPoint(pad->getScaledValue().x);
        mgY->addPoint(pad->getScaledValue().y);
    }
    else if(name == "DROP DOWN LIST")
    {
        ofxUIDropDownList *ddl = (ofxUIDropDownList *) e.widget; 
        cout << ddl->isOpen() << endl; 
    }     
}
//--------------------------------------------------------------
void testApp::exit()
{
//    gui->saveSettings("GUI/guiSettings.xml"); 
    delete gui; 
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    if(gui->hasKeyboardFocus())
    {
        return; 
    }
    
    switch (key) 
    {
        case 'p':
        {
            drawPadding = !drawPadding; 
            gui->setDrawPadding(drawPadding);          
        }
            break;
            
        case 'g':
        {
            gui->toggleVisible(); 
        }
            break; 
        default:
            break;
    }
}
//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{ 
 
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
 
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
 

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}