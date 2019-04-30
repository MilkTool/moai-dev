// Copyright (c) 2010-2017 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-sim/MOAIDrawShapeImmediate.h>
#include <moai-sim/MOAIViewport.h>
#include <moai-sim/MOAIQuadBrush.h>

#define DEFAULT_ELLIPSE_STEPS 64

//================================================================//
// MOAIDrawShapeImmediate
//================================================================//

//----------------------------------------------------------------//
MOAIDrawShapeImmediate::MOAIDrawShapeImmediate () {
}

//----------------------------------------------------------------//
MOAIDrawShapeImmediate::~MOAIDrawShapeImmediate () {
}

//================================================================//
// ::implementation::
//================================================================//

//----------------------------------------------------------------//
void MOAIDrawShapeImmediate::MOAIAbstractDrawShape_DrawLine ( float x0, float y0, float z0, float x1, float y1, float z1 ) {
	
	MOAIGfxMgrGL& gfxMgr = MOAIGfxMgrGL::Get ();

	gfxMgr.BeginPrim ( ZGL_PRIM_LINES, 2 );
	
		gfxMgr.WriteVtx ( x0, y0, z0 );
		gfxMgr.WritePenColor4b ();
		
		gfxMgr.WriteVtx ( x1, y1, z1 );
		gfxMgr.WritePenColor4b ();
	
	gfxMgr.EndPrim ();
}

//----------------------------------------------------------------//
void MOAIDrawShapeImmediate::MOAIAbstractDrawShape_DrawPoint ( float x, float y, float z ) {

	MOAIGfxMgrGL& gfxMgr = MOAIGfxMgrGL::Get ();
	UNUSED(z);
	gfxMgr.BeginPrim ( ZGL_PRIM_POINTS, 1 );
		gfxMgr.WriteVtx ( x, y, 0.0f );
		gfxMgr.WritePenColor4b ();
	gfxMgr.EndPrim ();
}

//----------------------------------------------------------------//
void MOAIDrawShapeImmediate::MOAIAbstractDrawShape_DrawTriangleFill ( const ZLVec3D& v0, const ZLVec3D& v1, const ZLVec3D& v2 ) {

	MOAIGfxMgrGL& gfxMgr = MOAIGfxMgrGL::Get ();

	gfxMgr.BeginPrim ( ZGL_PRIM_TRIANGLES, 3 );
	
		gfxMgr.WriteVtx ( v0.mX, v0.mY, v0.mZ );
		gfxMgr.WritePenColor4b ();
	
		gfxMgr.WriteVtx ( v1.mX, v1.mY, v1.mZ );
		gfxMgr.WritePenColor4b ();
	
		gfxMgr.WriteVtx ( v2.mX, v2.mY, v2.mZ );
		gfxMgr.WritePenColor4b ();

	gfxMgr.EndPrim ();
}

//----------------------------------------------------------------//
void MOAIDrawShapeImmediate::MOAIAbstractDrawShape_SetPenColor ( u32 color ) {

	MOAIGfxMgrGL::Get ().SetPenColor ( color );
}

//----------------------------------------------------------------//
void MOAIDrawShapeImmediate::MOAIAbstractDrawShape_SetPenWidth ( float width ) {

	MOAIGfxMgrGL::Get ().SetPenWidth ( width );
}
