#include "mex.h"

void speciallw(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	RookFightVars *fighter_var = &fighterData->fighter_var;
	if (fighter_var->NumCrimes > 0)
	{
		fighter_var->NumCrimes = fighter_var->NumCrimes - 1;
	}else
	{
		return;
	}
	state_var->SpecialLwRandX = (HSD_Randf() * 6) - 3;
	state_var->SpecialLwRandY = (HSD_Randf() * 6) - 3;
	ActionStateChange(1, 1, 0, fighter_gobj, 349, 0, 0);
	return;
}

void specialairlw(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	RookFightVars *fighter_var = &fighterData->fighter_var;
	if (fighter_var->NumCrimes > 0)
	{
		fighter_var->NumCrimes = fighter_var->NumCrimes - 1;
	}else
	{
		return;
	}
	state_var->SpecialLwRandX = (HSD_Randf() * 6) - 3;
	state_var->SpecialLwRandY = (HSD_Randf() * 6) - 3;
	ActionStateChange(1, 1, 0, fighter_gobj, 349, 0, 0);
	return;
}

void slw_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slw_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slw_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slw_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slw_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slwair_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slwair_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void slwair_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	RookStateVars *state_var = &fighterData->state_var;
	if (fighterData->ftcmd_var.flag0 == 1)
	{
		fighterData->phys.self_vel.X = state_var->SpecialLwRandX;
		fighterData->phys.self_vel.Y = state_var->SpecialLwRandY;
	}
	if (fighterData->ftcmd_var.flag0 == 2)
	{
		fighterData->phys.self_vel.X = fighterData->phys.self_vel.X * 0.6;
		fighterData->phys.self_vel.Y = fighterData->phys.self_vel.Y * 0.6;
	}
	if (fighterData->ftcmd_var.flag0 == 3)
	{
		Fighter_EnterFall(fighter_gobj);
	}
}

void slwair_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;
	//if (fighterData->ftcmd_var.flag0 != 3)
	//{
	//	Fighter_CollAir_GrabLedge(fighter_gobj, 1);
	//}

	if (Fighter_CollAir_GrabLedge(fighter_gobj, 1))
	{
		if (fighterData->ftcmd_var.flag0 != 1)
		{
			Fighter_EnterSpecialLanding(fighter_gobj, 0, 15);
		}
	}
	Fighter_IASACheck_CliffCatch(fighter_gobj);
	
}

void slwair_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}
