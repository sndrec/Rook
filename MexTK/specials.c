#include "mex.h"

void SideBHit(GOBJ *fighter_gobj)
{
	ActionStateChange(1, 1, 0, fighter_gobj, 344, 0, 0);
}

void specials(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	state_var->SpecialSStartedTurned = 0;
	//if (fighterData->state_id == 19)
	//{
	//	fighterData->facing_direction *= -1;
	//	state_var->SpecialSStartedTurned = 1;
	//}
	ActionStateChange(1, 1, 0, fighter_gobj, 345, 0, 0);
	fighterData->cb.OnGiveDamage = SideBHit;
	state_var->SpecialSStartedGrounded = 1;
	state_var->SpecialSGrabFlip = 0;
	return;
}

void specialairs(GOBJ *fighter_gobj)
{
	ActionStateChange(1, 1, 0, fighter_gobj, 345, 0, 0);
	FighterData *fighterData = fighter_gobj->userdata;
	fighterData->cb.OnGiveDamage = SideBHit;
	RookStateVars *state_var = &fighterData->state_var;
	state_var->SpecialSStartedTurned = 0;
	state_var->SpecialSStartedGrounded = 0;
	state_var->SpecialSGrabFlip = 0;
	return;
}

void ss_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	float frame = fighterData->state.frame;
	if (frame == 10 && state_var->SpecialSGrabFlip == 0)
	{
		fighterData->facing_direction *= -1;
	}
}

void ss_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if (fighterData->ftcmd_var.flag0 == 2)
	{
		Fighter_IASACheck_CliffCatch(fighter_gobj);
		Fighter_IASACheck_AerialAttack(fighter_gobj);
		Fighter_IASACheck_JumpAerial(fighter_gobj);
	}
	if (fighterData->ftcmd_var.flag0 == 3)
	{
		Fighter_EnterFall(fighter_gobj);
	}
}

void ss_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	Fighter_Phys_UseAnimYVelocity(fighter_gobj);
	Fighter_Phys_UseAnimXVelocity(fighter_gobj);
	if (fighterData->ftcmd_var.flag0 == 2)
	{
		Fighter_PhysAir_ApplyGravity(fighterData, 1, 1);
		Fighter_AllowXDrift(fighterData, 0, 0.6, 1.5);
	}
}

void ss_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if ((Fighter_CollAir_GrabLedge(fighter_gobj, 0)) && (fighterData->ftcmd_var.flag0) == 3)
	{
		Fighter_EnterLanding(fighter_gobj);
	}
}

void ss_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
}

void ssair_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	//if (state_var->SpecialSStartedTurned == 1)
	//{
	//	Fighter_RotateBone_Pitch(fighterData, 2, 3.14159);
	//}
}

void ssair_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if (fighterData->ftcmd_var.flag0 == 1)
	{
		Fighter_IASACheck_CliffCatch(fighter_gobj);
	}
	if (fighterData->ftcmd_var.flag0 == 3)
	{
		Fighter_EnterSpecialFall(fighter_gobj, 1, 0, 0, 1, 12);
	}
}

void ssair_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	Fighter_Phys_UseAnimYVelocity(fighter_gobj);
	Fighter_Phys_UseAnimXVelocity(fighter_gobj);
	RookStateVars *state_var = &fighterData->state_var;
	float frame = fighterData->state.frame;
	if (state_var->SpecialSStartedGrounded == 1 && frame < 11)
	{
		fighterData->phys.self_vel.Y = 0.5;
	}
	if (fighterData->ftcmd_var.flag0 == 2)
	{
		Fighter_AllowXDrift(fighterData, 0, 0.6, 1.5);
	}

}

void ssair_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if ((Fighter_CollAir_GrabLedge(fighter_gobj, 0)) && (fighterData->ftcmd_var.flag0) == 2)
	{
		Fighter_EnterSpecialLanding(fighter_gobj, 0, 20);
	}
}

void ssair_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
}
