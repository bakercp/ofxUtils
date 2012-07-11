/*
 *  Enabler.h
 *  utils
 *
 *  Created by Christopher P. Baker on 3/6/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

class ofxEnablerInterface {
	
public:
	
	ofxEnablerInterface() { setEnabled(true); }
	ofxEnablerInterface(bool _enabled) { setEnabled(_enabled); }
	virtual ~ofxEnablerInterface() {};
	
	bool isEnabled() {
		return enabled;
	}
	
    void enable() {
        setEnabled(true);
    }

    void disable() {
        setEnabled(false);
    }

    
    void toggleEnabled() {
        enabled = !enabled;
        // call the events if needed
        if(enabled) {
            onEnabled();
        } else {
            onDisabled();
        }
    }
    
	void setEnabled(bool _enabled) { 
		if(_enabled != enabled) {
			enabled = _enabled;
			// call the events if needed
			if(enabled) {
				onEnabled();
			} else {
				onDisabled();
			}
		}
	}
	
	// subclasses can get these messages
	virtual void onEnabled(){};
	virtual void onDisabled(){};

private:
	// not protected, so changes only via getters/setters.
	bool enabled;
	
};


