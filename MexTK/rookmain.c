#include "mex.h"
#include "rookheader.h"
#include "speciallw.c"
#include "specialhi.c"
#include "specials.c"
#include "specialn.c"

__attribute__((used))
static struct MoveLogic move_logic[] = {
	// State: 341 - JumpAerialF1
	{
		295,        // AnimationID
		0x0,        // StateFlags
		0x1,        // AttackID
		0x0,        // BitFlags
		0x800D7590, // AnimationCallback
		0x800D7614, // IASACallback
		0x80084DB0, // PhysicsCallback
		0x800D767C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 342 - SpecialN
	{
		302,        // AnimationID
		0x0,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		sn_anim, // AnimationCallback
		sn_iasa, // IASACallback
		sn_phys, // PhysicsCallback
		0x800D767C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 343 - SpecialNAir
	{
		303,        // AnimationID
		0x0,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		snair_anim, // AnimationCallback
		snair_iasa, // IASACallback
		snair_phys, // PhysicsCallback
		0x800D767C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 344 - SpecialS
	{
		317,        // AnimationID
		0x0,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		ss_anim, // AnimationCallback
		ss_iasa, // IASACallback
		ss_phys, // PhysicsCallback
		0x800D767C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 345 - SpecialAirS
	{
		318,        // AnimationID
		0x0,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		ssair_anim, // AnimationCallback
		ssair_iasa, // IASACallback
		ssair_phys, // PhysicsCallback
		0x800D767C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 365 - SpecialHiL
	{
		319,        // AnimationID
		0x340013,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x8013CB68, // AnimationCallback
		0x8013CC60, // IASACallback
		0x8013CC68, // PhysicsCallback
		0x8013CCA8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 366 - SpecialAirHiL
	{
		320,        // AnimationID
		0x340413,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x8013CBE4, // AnimationCallback
		0x8013CC64, // IASACallback
		0x8013CC88, // PhysicsCallback
		0x8013CCE4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 348 - SpecialLwL
	{
		323,        // AnimationID
		0x0,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		slw_anim, // AnimationCallback
		slw_iasa, // IASACallback
		slw_phys, // PhysicsCallback
		slw_coll, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 349 - SpecialAirLwL
	{
		324,        // AnimationID
		0x0,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		slwair_anim, // AnimationCallback
		slwair_iasa, // IASACallback
		slwair_phys, // PhysicsCallback
		slwair_coll, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 350 - JumpAerialF2
	{
		296,        // AnimationID
		0x0,        // StateFlags
		0x14,        // AttackID
		0x0,        // BitFlags
		shi1_anim, // AnimationCallback
		shi1_iasa, // IASACallback
		shi1_phys, // PhysicsCallback
		shi1_coll, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 351 - JumpAerialF3
	{
		297,        // AnimationID
		0x0,        // StateFlags
		0x14,        // AttackID
		0x0,        // BitFlags
		shi2_anim, // AnimationCallback
		shi2_iasa, // IASACallback
		shi2_phys, // PhysicsCallback
		shi2_coll, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 352 - JumpAerialF4
	{
		298,        // AnimationID
		0x0,        // StateFlags
		0x14,        // AttackID
		0x0,        // BitFlags
		shi3_anim, // AnimationCallback
		shi3_iasa, // IASACallback
		0x80084DB0, // PhysicsCallback
		shi3_coll, // CollisionCallback
		0x800761C8, // CameraCallback
	},
}; 

void OnDeath(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	Fighter_VisTableSet(fighter_gobj, 0, 0);
	Fighter_VisTableSet(fighter_gobj, 1, 0);
	RookFightVars *fighter_var = &fighterData->fighter_var;
	fighter_var->NumCrimes = 3;
	return;
}

void onlanding(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookFightVars *fighter_var = &fighterData->fighter_var;
	fighter_var->NumCrimes = 3;
	return;
}

//void onhit(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onrespawn(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onactionstatechange(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onunknown(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onframe(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onmodelrender(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//
//void onshadowrender(GOBJ *fighter_gobj)
//{
//
//	return;
//}
//