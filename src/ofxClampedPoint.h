/*
 *  ofxClampedPoint.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/6/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

// TODO: would like to use this with ofParameter in some way

#pragma once

#include "ofMain.h"

class ofxClampedPoint : public ofPoint {
public:
	
	ofxClampedPoint(const ofPoint& pnt)
		: ofPoint(pnt) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);

    }
	
	ofxClampedPoint(float _x=0.0f, float _y=0.0f, float _z=0.0f)
		: ofPoint(_x,_y,_z) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);
			
	};
	 
	~ofxClampedPoint() {}
	
	ofPoint getClamped() {
		return ofPoint(getClampedX(), getClampedY(), getClampedZ());
	}
    
	float getClampedX() {return ofClamp(x,minLimit.x,maxLimit.x);}
	float getClampedY() {return ofClamp(y,minLimit.y,maxLimit.y);}
	float getClampedZ() {return ofClamp(z,minLimit.z,maxLimit.z);}

	void setMinLimits(const ofPoint& pnt) {
        setMinX(pnt.x);
        setMinY(pnt.y);
        setMinZ(pnt.z);
    };
	void setMaxLimits(const ofPoint& pnt) {
        setMaxX(pnt.x);
        setMaxY(pnt.y);
        setMaxZ(pnt.z);
    }

	void setMinX(float x) {
        if(areSame(x,minLimit.x)) return;
        minLimit.x = x; 
        onLimitMinXChanged();
    }
    
	void setMaxX(float x) {
        if(areSame(x,maxLimit.x)) return;
        maxLimit.x = x; 
        onLimitMaxXChanged();
    }

	void setMinY(float y) {
        if(areSame(y,minLimit.y)) return;
        minLimit.y = y; 
        onLimitMinYChanged();
    }
	
    void setMaxY(float y) {
        if(areSame(y,maxLimit.y)) return;
        maxLimit.y = y; 
        onLimitMaxYChanged();
    }

	void setMinZ(float z) {
        if(areSame(z,minLimit.z)) return;
        minLimit.z = z; 
        onLimitMinZChanged();
    }
    
	void setMaxZ(float z) {
        if(areSame(z,minLimit.z)) return;
        maxLimit.z = z; 
        onLimitMaxZChanged();
    }

	void clearMaxLimits() { 
        setMaxLimits(ofPoint(FLT_MAX,FLT_MAX,FLT_MAX));
    }
	
    void clearMinLimits() { 
        setMinLimits(ofPoint(-FLT_MAX,-FLT_MAX,-FLT_MAX));
    }

    // callbacks
    void onLimitMinXChanged() {}
	void onLimitMinYChanged() {}
	void onLimitMinZChanged() {}

	void onLimitMaxXChanged() {}
	void onLimitMaxYChanged() {}
	void onLimitMaxZChanged() {}

	
protected:
	
    bool areSame(float a, float b) {
        return std::fabs(a - b) < std::numeric_limits<float>::epsilon();
    }
    
	ofPoint minLimit;
	ofPoint maxLimit;
		
		
};


