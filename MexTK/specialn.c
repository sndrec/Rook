#include "mex.h"

void specialn(GOBJ *fighter_gobj)
{
	ActionStateChange(1, 1, 0, fighter_gobj, 342, 0, 0);
	FighterData *fighterData = fighter_gobj->userdata;
	return;
}

void specialairn(GOBJ *fighter_gobj)
{
	ActionStateChange(1, 1, 0, fighter_gobj, 343, 0, 0);
	FighterData *fighterData = fighter_gobj->userdata;
	return;
}

void sn_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void sn_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void sn_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void sn_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void sn_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void snair_anim(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void snair_iasa(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void snair_phys(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void snair_coll(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}

void snair_cam(GOBJ *fighter_gobj)
{
	FighterData *fighterData = fighter_gobj->userdata;

}
