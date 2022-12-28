#include "mex.h"

void specialhi(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	state_var->SpecialHiFrameDirectionChanged = -20;
	state_var->SpecialHiStartDirection = 1.0;
	state_var->SpecialHiTurned = 0;
	ActionStateChange(1, 1, 0, fighter_gobj, 350, 0, 0);
	fighterData->phys.self_vel.Y = fighterData->phys.self_vel.X * 0.25;
	fighterData->phys.self_vel.X = fighterData->phys.self_vel.X * 0.25;
	return;
}

void specialairhi(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	state_var->SpecialHiFrameDirectionChanged = -20;
	state_var->SpecialHiStartDirection = 1.0;
	state_var->SpecialHiTurned = 0;
	ActionStateChange(1, 1, 0, fighter_gobj, 350, 0, 0);
	fighterData->phys.self_vel.Y = fighterData->phys.self_vel.X * 0.25;
	fighterData->phys.self_vel.X = fighterData->phys.self_vel.X * 0.25;
	return;
}

void shi1_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	float frame = fighterData->state.frame;
	RookStateVars *state_var = &fighterData->state_var;
	if (state_var->SpecialHiTurned == 0 && 
		fabs(fighterData->input.lstick_x) > 0.2 && 
		fighterData->facing_direction * fighterData->input.lstick_x < 0 &&
		frame < 9)
	{
		if (frame > 2)
		{
			state_var->SpecialHiTurned = 1;
		}
		fighterData->facing_direction *= -1;
		ActionStateChange(frame, 1, 0, fighter_gobj, 350, 0, 0);
	}
    
	if (fighterData->ftcmd_var.flag1 == 1)
	{
		ActionStateChange(1, 1, 0, fighter_gobj, 351, 0, 0);
	}
}

void shi1_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void shi1_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
}

void shi1_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	Fighter_CollAir_GrabLedge(fighter_gobj, 0);
	Fighter_IASACheck_CliffCatch(fighter_gobj);
}


//float Fighter_GetBoneRotation(FighterData *fighter, int bone);
//float Fighter_RotateBone_Pitch(FighterData *fighter, int bone, float angle);
//float Fighter_RotateBone_Yaw(FighterData *fighter, int bone, float angle);
//float Fighter_RotateBone_Roll(FighterData *fighter, int bone, float angle);

void shi2_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if (fighterData->ftcmd_var.flag1 == 2)
	{
		ActionStateChange(1, 1, 0, fighter_gobj, 352, 0, 0);
	}
	if (!(fighterData->input.held & PAD_BUTTON_B))
	{
		ActionStateChange(1, 1, 0, fighter_gobj, 352, 1, 0);
	}

}

void shi2_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void shi2_phys(GOBJ *fighter_gobj)
{	
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	float frame = fighterData->state.frame;
	float ratio = frame / 110.0;
	float maxHorizontalVel = 1.5 - (ratio * 0.5);
	float maxHorizontalDrift = 0.08 - (ratio * 0.06);
	float maxVerticalBaseVel = 0.6 - (ratio * 0.4);
	float maxVerticalAddVel = 0.5 - (ratio * 0.3);
	float stickx = fighterData->input.lstick_x;
	float sticky = fighterData->input.lstick_y;
	stickx = (((stickx * 2.0) > (-1.0)) ? (stickx * 2.0) : (-1.0));
	sticky = (((sticky * 2.0) > (-1.0)) ? (sticky * 2.0) : (-1.0));
	stickx = (((stickx * 2.0) < (1.0)) ? (stickx * 2.0) : (1.0));
	sticky = (((sticky * 2.0) < (1.0)) ? (sticky * 2.0) : (1.0));
	if (frame == 1.0)
	{
		fighterData->phys.self_vel.X = fighterData->facing_direction * maxHorizontalVel;
		state_var->SpecialHiStartDirection = fighterData->facing_direction;
	}

	if (signbit(fighterData->facing_direction) != signbit(fighterData->phys.self_vel.X))
	{
		state_var->SpecialHiFrameDirectionChanged = frame;
		fighterData->facing_direction *= -1.0;
	}

	float framesToTurn = 16.0;
	float turnRatio = ((state_var->SpecialHiFrameDirectionChanged + framesToTurn) - frame) / framesToTurn;
	turnRatio = (((turnRatio) > (0.0)) ? (turnRatio) : (0.0));
	turnRatio = (((turnRatio) < (1.0)) ? (turnRatio) : (1.0));
	float turnRatioInverted = 1.0 - turnRatio;
	if (fighterData->facing_direction == state_var->SpecialHiStartDirection)
	{
		Fighter_RotateBone_Pitch(fighterData, 2, 3.14159 * turnRatio);
	}else
	{
		Fighter_RotateBone_Pitch(fighterData, 2, 3.14159 * turnRatioInverted);
	}

	fighterData->phys.self_vel.Y = maxVerticalBaseVel + (sticky * maxVerticalAddVel);
	fighterData->phys.self_vel.X = fighterData->phys.self_vel.X + (stickx * maxHorizontalDrift);
	if (fighterData->phys.self_vel.X > maxHorizontalVel)
	{
		fighterData->phys.self_vel.X = maxHorizontalVel;
	}
	if (fighterData->phys.self_vel.X < -maxHorizontalVel)
	{
		fighterData->phys.self_vel.X = -maxHorizontalVel;
	}
	float yawOffset = (fabs(fighterData->phys.self_vel.X * 0.5) - 0.25) + (fighterData->input.lstick_y * -0.25) + 0.1;
	Fighter_RotateBone_Yaw(fighterData, 2, yawOffset);
}

void shi2_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	Fighter_CollAir_GrabLedge(fighter_gobj, 0);
	Fighter_IASACheck_CliffCatch(fighter_gobj);
}


void shi3_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if (fighterData->ftcmd_var.flag1 == 3)
	{
		Fighter_EnterSpecialFall(fighter_gobj, 1, 0, 0, 1, 20);
	}
}

void shi3_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void shi3_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void shi3_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	if (Fighter_CollAir_GrabLedge(fighter_gobj, 0))
	{
		Fighter_EnterSpecialLanding(fighter_gobj, 0, 20);
	}
	Fighter_IASACheck_CliffCatch(fighter_gobj);
}