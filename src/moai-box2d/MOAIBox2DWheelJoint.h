// Copyright (c) 2010-2017 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIBOX2DWHEELJOINT_H
#define	MOAIBOX2DWHEELJOINT_H

#include <moai-box2d/MOAIBox2DJoint.h>

//================================================================//
// MOAIBox2DWheelJoint
//================================================================//
/**	@lua MOAIBox2DWheelJoint
	@text Box2D wheel joint.
 */
class MOAIBox2DWheelJoint :
public MOAIBox2DJoint {
private:
	
	//----------------------------------------------------------------//
	static int		_getJointTranslation	( lua_State* L );
	static int		_getJointSpeed			( lua_State* L );
	static int		_isMotorEnabled			( lua_State* L );	
	static int		_getMotorSpeed			( lua_State* L );
	static int		_getSpringDampingRatio	( lua_State* L );	
	static int		_getMaxMotorTorque		( lua_State* L );
	static int		_getMotorTorque			( lua_State* L );	
	static int		_getSpringFrequencyHz	( lua_State* L );
	static int		_setMotor				( lua_State* L );
	static int		_setMotorSpeed			( lua_State* L );
	static int		_setMotorEnabled		( lua_State* L );
	static int		_setMaxMotorTorque		( lua_State* L );	
	static int		_setSpringDampingRatio	( lua_State* L );
	static int		_setSpringFrequencyHz	( lua_State* L );

	//----------------------------------------------------------------//
	void			MOAILuaObject_RegisterLuaClass		( MOAIComposer& composer, MOAILuaState& state );
	void			MOAILuaObject_RegisterLuaFuncs		( MOAIComposer& composer, MOAILuaState& state );
	
public:
	
	DECL_LUA_FACTORY ( MOAIBox2DWheelJoint )

	//----------------------------------------------------------------//
					MOAIBox2DWheelJoint		();
					~MOAIBox2DWheelJoint	();
};

#endif
