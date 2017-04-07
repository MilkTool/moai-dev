// Copyright (c) 2010-2017 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef ZLVEC3D_H
#define	ZLVEC3D_H

#include <zl-util/ZLVec2D.h>

//================================================================//
// ZLMetaVec3D
//================================================================//
template < typename TYPE >
class ZLMetaVec3DStruct {
public:

	TYPE	mX;
	TYPE	mY;
	TYPE	mZ;

	//----------------------------------------------------------------//
	bool operator == ( const ZLMetaVec3DStruct < TYPE >& rhs ) const {
		return (( this->mX == rhs.mX ) && ( this->mY == rhs.mY ) && ( this->mZ == rhs.mZ ));
	}
	
	//----------------------------------------------------------------//
	bool operator != ( const ZLMetaVec3DStruct < TYPE >& rhs ) const {
		return (( this->mX != rhs.mX ) || ( this->mY != rhs.mY ) || ( this->mZ != rhs.mZ ));
	}

	//----------------------------------------------------------------//
	ZLMetaVec3DStruct < TYPE > operator + ( const ZLMetaVec3DStruct < TYPE >& v ) const {
		ZLMetaVec3DStruct < TYPE > result;
		result.mX = this->mX + v.mX;
		result.mY = this->mY + v.mY;
		result.mZ = this->mZ + v.mZ;
		return result;
	}

	//----------------------------------------------------------------//
	ZLMetaVec3DStruct < TYPE > operator - ( const ZLMetaVec3DStruct < TYPE >& v ) const {
		ZLMetaVec3DStruct < TYPE > result;
		result.mX = this->mX - v.mX;
		result.mY = this->mY - v.mY;
		result.mZ = this->mZ - v.mZ;
		return result;
	}

	//----------------------------------------------------------------//
	// V = V + vec
	void Add ( const ZLMetaVec3DStruct < TYPE >& vec ) {
		mX = mX + vec.mX;
		mY = mY + vec.mY;
		mZ = mZ + vec.mZ;
	}

	//----------------------------------------------------------------//
	// V += vec * scale
	void Add ( const ZLMetaVec3DStruct < TYPE >& vec, TYPE scale ) {
		mX = mX + ( vec.mX * scale );
		mY = mY + ( vec.mY * scale );
		mZ = mZ + ( vec.mZ * scale );
	}

	//----------------------------------------------------------------//
	// Clamps in positive and negative
	void Clamp ( const ZLMetaVec3DStruct < TYPE >& clamp ) {
		if ( mX > clamp.mX ) mX = clamp.mX;
		else if ( mX < -clamp.mX ) mX = -clamp.mX;
		if ( mY > clamp.mY ) mY = clamp.mY;
		else if ( mY < -clamp.mY ) mY = -clamp.mY;
		if ( mZ > clamp.mZ ) mZ = clamp.mZ;
		else if ( mZ < -clamp.mZ ) mZ = -clamp.mZ;
	}

	//----------------------------------------------------------------//
	bool Compare ( const ZLMetaVec3DStruct < TYPE >& point ) {
	
		if (( mX != point.mX ) || ( mY != point.mY ) || ( mZ != point.mZ )) return false;
		
		return true;
	}

	//----------------------------------------------------------------//
	// Is V within res of vec?
	bool Compare ( const ZLMetaVec3DStruct < TYPE >& vec, TYPE res ) const {

		if ((( mX < ( vec.mX - res )) || ( mX > ( vec.mX + res ))) ||
			(( mY < ( vec.mY - res )) || ( mY > ( vec.mY + res ))) ||
			(( mZ < ( vec.mZ - res )) || ( mZ > ( vec.mZ + res )))) return false;

		return true;
	}

	//----------------------------------------------------------------//
	// V = V x vec
	void Cross ( const ZLMetaVec3DStruct < TYPE >& vec ) {
		float tx;
		float ty;

		tx	= ( mY * vec.mZ ) - ( mZ * vec.mY );
		ty	= ( mZ * vec.mX ) - ( mX * vec.mZ );
		mZ	= ( mX * vec.mY ) - ( mY * vec.mX );
		mY = ty;
		mX = tx;
	}
	
	//----------------------------------------------------------------//
	// V = v0 x v1
	static ZLMetaVec3DStruct < TYPE > Cross ( const ZLMetaVec3DStruct < TYPE >& v0, const ZLMetaVec3DStruct < TYPE >& v1 ) {
		
		ZLMetaVec3DStruct < TYPE > vec;
		
		vec.mX	= ( v0.mY * v1.mZ ) - ( v0.mZ * v1.mY );
		vec.mY	= ( v0.mZ * v1.mX ) - ( v0.mX * v1.mZ );
		vec.mZ	= ( v0.mX * v1.mY ) - ( v0.mY * v1.mX );
		
		return vec;
	}
	
	//----------------------------------------------------------------//
	// V = v0 x v1
	static ZLMetaVec3DStruct < TYPE > CrossNorm ( const ZLMetaVec3DStruct < TYPE >& v0, const ZLMetaVec3DStruct < TYPE >& v1 ) {
	
		ZLMetaVec3DStruct < TYPE > v = Cross ( v0, v1 );
		v.Norm ();
		
		return v;
	}

	//----------------------------------------------------------------//
	// |V| -= damp
	void Dampen ( const ZLMetaVec3DStruct < TYPE >& damp ) {
		if ( mX > ( TYPE )0 ) {
			mX -= damp.mX;
			if ( mX < ( TYPE )0 ) mX = ( TYPE )0;
		}
		else if ( mX < ( TYPE )0 ) {
			mX += damp.mX;
			if ( mX > ( TYPE )0 ) mX = ( TYPE )0;
		}

		if ( mY > ( TYPE )0 ) {
			mY -= damp.mY;
			if ( mY < ( TYPE )0 ) mY = ( TYPE )0;
		}
		else if ( mY < ( TYPE )0 ) {
			mY += damp.mY;
			if ( mY > ( TYPE )0 ) mY = ( TYPE )0;
		}

		if ( mZ > ( TYPE )0 ) {
			mZ -= damp.mZ;
			if ( mZ < ( TYPE )0 ) mZ = ( TYPE )0;
		}
		else if ( mZ < ( TYPE )0 ) {
			mZ += damp.mZ;
			if ( mZ > ( TYPE )0 ) mZ = ( TYPE )0;
		}
	}

	//----------------------------------------------------------------//
	float Dist ( const ZLMetaVec3DStruct < TYPE >& vec ) {

		TYPE x = this->mX - vec.mX;
		TYPE y = this->mY - vec.mY;
		TYPE z = this->mZ - vec.mZ;

		return sqrtf (( x * x ) + ( y * y ) + ( z * z ));
	}

    //----------------------------------------------------------------//
	float DistSqrd ( const ZLMetaVec3DStruct < TYPE >& vec ) const {

		TYPE x = this->mX - vec.mX;
		TYPE y = this->mY - vec.mY;
		TYPE z = this->mZ - vec.mZ;

		return  (( x * x ) + ( y * y ) + ( z * z ));
	}

	//----------------------------------------------------------------//
	// V . vec
	float Dot ( const ZLMetaVec3DStruct < TYPE >& vec ) const {
		return ( mX * vec.mX ) + ( mY * vec.mY ) + ( mZ * vec.mZ );
	}

	//----------------------------------------------------------------//
	TYPE GetComponent ( int idx ) const {

		switch ( idx ) {
			case 0:		return this->mX;
			case 1:		return this->mY;
			case 2:		return this->mZ;
			default:	return 0;
		}
	}

	//----------------------------------------------------------------//
	void Init ( TYPE x, TYPE y, TYPE z ) {
		mX = x;
		mY = y;
		mZ = z;
	}

	//----------------------------------------------------------------//
	template < typename PARAM_TYPE >
	void Init ( const ZLMetaVec2D < PARAM_TYPE >& point ) {
		mX = ( TYPE )point.mX;
		mY = ( TYPE )point.mY;
		mZ = 0;
	}

	//----------------------------------------------------------------//
	template < typename PARAM_TYPE >
	void Init ( const ZLMetaVec3DStruct < PARAM_TYPE >& vec ) {
		mX = ( TYPE )vec.mX;
		mY = ( TYPE )vec.mY;
		mZ = ( TYPE )vec.mZ;
	}

	//----------------------------------------------------------------//
	// V = 1 / V
	void Inverse () {
		mX = 1 / mX;
		mY = 1 / mY;
		mZ = 1 / mZ;
	}

	//----------------------------------------------------------------//
	// |V|
	float Length () {
		return sqrtf (( mX * mX ) + ( mY * mY ) + ( mZ * mZ ));
	}
	
	//----------------------------------------------------------------//
	// |V| * |V|
	float LengthSqrd () {
		return (( mX * mX ) + ( mY * mY ) + ( mZ * mZ ));
	}

	//----------------------------------------------------------------//
	void Lerp ( const ZLMetaVec3DStruct& vec, TYPE time ) {

		this->mX = this->mX + (( vec.mX - this->mX ) * time );
		this->mY = this->mY + (( vec.mY - this->mY ) * time );
		this->mZ = this->mZ + (( vec.mZ - this->mZ ) * time );
	}

	//----------------------------------------------------------------//
	// V *= vec
	void Multiply ( const ZLMetaVec3DStruct < TYPE >& vec ) {
		mX = mX * vec.mX;
		mY = mY * vec.mY;
		mZ = mZ * vec.mZ;
	}

	//----------------------------------------------------------------//
	TYPE Norm () {

		TYPE length;
		
		length = this->Length ();

		this->mX = this->mX / length;
		this->mY = this->mY / length;
		this->mZ = this->mZ / length;

		return length;
	}

	//----------------------------------------------------------------//
	TYPE NormSafe () {

		TYPE length;
		
		length = this->Length ();

		if ( length != 0 ) {
			this->mX = this->mX / length;
			this->mY = this->mY / length;
			this->mZ = this->mZ / length;
		}

		return length;
	}

	//----------------------------------------------------------------//
	// V += vec * d
	void Offset ( const ZLMetaVec3DStruct < TYPE >& vec, TYPE d ) {
		mX += vec.mX * d;
		mY += vec.mY * d;
		mZ += vec.mZ * d;
	}

	//----------------------------------------------------------------//
	void Project ( ZLMetaVec3DStruct < TYPE >& norm ) {

		TYPE dot;
		
		dot = this->Dot ( norm );

		this->mX -= norm.mX * dot;
		this->mY -= norm.mY * dot;
		this->mZ -= norm.mZ * dot;
	}

	//----------------------------------------------------------------//
	void Project ( ZLMetaVec3DStruct < TYPE >& norm, ZLMetaVec3DStruct < TYPE >& axis ) {

		TYPE project = norm.Dot ( axis ) / Dot ( norm );

		this->mX -= axis.mX * project;
		this->mY -= axis.mY * project;
		this->mZ -= axis.mZ * project;
	}

	//----------------------------------------------------------------//
	void Quantize ( TYPE decimalPlace ) {

		TYPE reciprocal = 1 / decimalPlace;
		
		this->mX = (( s32 )this->mX * reciprocal ) * decimalPlace;
		this->mY = (( s32 )this->mY * reciprocal ) * decimalPlace;
		this->mZ = (( s32 )this->mZ * reciprocal ) * decimalPlace;
	}

	//----------------------------------------------------------------//
	// angle between vectors in radians
	float Radians ( const ZLMetaVec3DStruct < TYPE >& v ) const {
		
		float dot = this->Dot ( v );
		
		if ( dot <= -1.0f ) return ( float )PI;
		if ( dot >= 1.0f ) return 0.0f;
		
		return ACos ( dot );
	}

	//----------------------------------------------------------------//
	void Reflect ( ZLMetaVec3DStruct < TYPE >& norm ) {
		TYPE dot;
		
		dot = 2.0f * this->Dot ( norm );

		this->mX -= norm.mX * dot;
		this->mY -= norm.mY * dot;
		this->mZ -= norm.mZ * dot;
	}

	//----------------------------------------------------------------//
	void Res ( TYPE res ) {

		this->mX = ((( s32 )( this->mX / res )) * res );
		this->mY = ((( s32 )( this->mY / res )) * res );
		this->mZ = ((( s32 )( this->mZ / res )) * res );
	}

	//----------------------------------------------------------------//
	// V = -V
	void Reverse () {
		mX = -mX;
		mY = -mY;
		mZ = -mZ;
	}

	//----------------------------------------------------------------//
	// Rotates about the Z axis (implicit by the orthogonal normals provided)
	void RotateInBasis	( ZLMetaVec3DStruct < TYPE >& xAxis, ZLMetaVec3DStruct < TYPE >& yAxis, TYPE theta ) {

		// Do the trig for the angle
		TYPE sinTheta = Sin ( theta );
		TYPE cosTheta = Cos ( theta );

		// Yank out the vector components in terms of the local axes
		TYPE x = Dot ( xAxis );
		TYPE y = Dot ( yAxis );

		// Move the vector back to the origin ( do it this way to preserve the z component )
		this->mX -= ( x * xAxis.mX ) - ( y * yAxis.mX );
		this->mY -= ( x * xAxis.mY ) - ( y * yAxis.mY );
		this->mZ -= ( x * xAxis.mZ ) - ( y * yAxis.mZ );

		// Figure the new components
		TYPE xP = ( x * cosTheta ) - ( y * sinTheta );
		TYPE yP = ( y * cosTheta ) + ( x * sinTheta );

		// Move the vector to its new rotated position
		this->mX += ( xP * xAxis.mX ) + ( yP * yAxis.mX );
		this->mY += ( xP * xAxis.mY ) + ( yP * yAxis.mY );
		this->mZ += ( xP * xAxis.mZ ) + ( yP * yAxis.mZ );
	}

	//----------------------------------------------------------------//
	// V *= scale
	void Scale ( TYPE scale ) {
		mX *= scale;
		mY *= scale;
		mZ *= scale;
	}

	//----------------------------------------------------------------//
	void Scale ( TYPE x, TYPE y, TYPE z ) {
		mX *= x;
		mY *= y;
		mZ *= z;
	}

	//----------------------------------------------------------------//
	void SetComp ( const u8 idx, const TYPE val ) {

		switch ( idx ) {
		
			case 0:
				this->mX = val;
			break;
			
			case 1:
				this->mY = val;
			break;
			
			default:
				this->mZ = val;
		}
	}

	//----------------------------------------------------------------//
	TYPE SetLength ( TYPE length ) {

		TYPE scale;
		scale = this->Length () / length;

		this->mX = this->mX / scale;
		this->mY = this->mY / scale;
		this->mZ = this->mZ / scale;

		return length;
	}

	//----------------------------------------------------------------//
	// V = V - vec
	void Sub ( const ZLMetaVec3DStruct < TYPE >& vec ) {
		mX -= vec.mX;
		mY -= vec.mY;
		mZ -= vec.mZ;
	}

	//----------------------------------------------------------------//
	// V -= vec * scale
	void Sub ( const ZLMetaVec3DStruct < TYPE >& vec, TYPE scale ) {
		mX = mX - ( vec.mX * scale );
		mY = mY - ( vec.mY * scale );
		mZ = mZ - ( vec.mZ * scale );
	}
	
	//----------------------------------------------------------------//
	ZLMetaVec2D < TYPE > Vec2D () const {
	
		return ZLMetaVec2D < TYPE >( this->mX, this->mY );
	}
};

//================================================================//
// ZLMetaVec3D
//================================================================//
template < typename TYPE >
class ZLMetaVec3D :
	public ZLMetaVec3DStruct < TYPE > {
public:

	static const ZLMetaVec3D < TYPE >	X_AXIS;
	static const ZLMetaVec3D < TYPE >	Y_AXIS;
	static const ZLMetaVec3D < TYPE >	Z_AXIS;

	static const ZLMetaVec3D < TYPE >	ORIGIN;		// all 0's
	static const ZLMetaVec3D < TYPE >	AXIS;		// all 1's

	//----------------------------------------------------------------//
	operator ZLMetaVec3DStruct < TYPE > () {
	
		return *( ZLMetaVec3DStruct < TYPE >* )this;
	}

	//----------------------------------------------------------------//
	ZLMetaVec3D () {
	}

	//----------------------------------------------------------------//
	ZLMetaVec3D ( const ZLMetaVec3DStruct < TYPE >& vec ) {
	
		*( ZLMetaVec3DStruct < TYPE >* )this = vec;
	}

	//----------------------------------------------------------------//
	ZLMetaVec3D ( TYPE x, TYPE y, TYPE z ) {
		
		this->mX = x;
		this->mY = y;
		this->mZ = z;
	}
};

template < typename TYPE > const ZLMetaVec3D < TYPE > ZLMetaVec3D < TYPE >::X_AXIS	= ZLMetaVec3D < TYPE >( 1, 0, 0 );
template < typename TYPE > const ZLMetaVec3D < TYPE > ZLMetaVec3D < TYPE >::Y_AXIS	= ZLMetaVec3D < TYPE >( 0, 1, 0 );
template < typename TYPE > const ZLMetaVec3D < TYPE > ZLMetaVec3D < TYPE >::Z_AXIS	= ZLMetaVec3D < TYPE >( 0, 0, 1 );

template < typename TYPE > const ZLMetaVec3D < TYPE > ZLMetaVec3D < TYPE >::ORIGIN	= ZLMetaVec3D < TYPE >( 0, 0, 0 );
template < typename TYPE > const ZLMetaVec3D < TYPE > ZLMetaVec3D < TYPE >::AXIS	= ZLMetaVec3D < TYPE >( 1, 1, 1 );

typedef ZLMetaVec3DStruct < int > ZLIntVec3DStruct;
typedef ZLMetaVec3DStruct < float > ZLVec3DStruct;
typedef ZLMetaVec3DStruct < double > ZLVec3D64Struct;

typedef ZLMetaVec3D < int > ZLIntVec3D;
typedef ZLMetaVec3D < float > ZLVec3D;
typedef ZLMetaVec3D < double > ZLVec3D64;

#endif
