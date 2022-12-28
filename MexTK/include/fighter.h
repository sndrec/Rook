#ifndef MEX_H_FIGHTER
#define MEX_H_FIGHTER

#include "structs.h"
#include "datatypes.h"
#include "obj.h"
#include "color.h"
#include "effects.h"
#include "match.h"
#include "collision.h"

// action state flags
#define ASC_PRESERVE_FASTFALL 0x1
#define ASC_PRESERVE_GFX 0x2
#define ASC_PRESERVE_EYE 0x80
#define ASC_1000 0x1000
#define ASC_SKIP_SCRIPT 0x4000
#define ASC_PRESERVE_VISIBILITY 0x40000
#define ASC_80000 0x80000
#define ASC_400000 0x400000
#define ASC_4000000 0x4000000
#define ASC_8000000 0x8000000
#define ASC_NOANIM 0x20000000

enum FtCommonBone
{
    TopN,
    TransN,
    XRotN,
    YRotN,
    HipN,
    WaistN,
    LLegJA,
    LLegJ,
    LKneeJ,
    LFootJA,
    LFootJ,
    RLegJA,
    RLegJ,
    RKneeJ,
    RFootJA,
    RFootJ,
    WaistN2,
    BustN,
    LShoulderN,
    LShoulderJA,
    LShoulderJ,
    LArmJ,
    LHandN,
    L1stNa,
    L1stNb,
    L2ndNa,
    L2ndNb,
    L3rdNa,
    L3rdNb,
    L4thNa,
    L4thNb,
    LHaveN,
    LThumbNa,
    LThumbNb,
    NeckN,
    HeadN,
    RShoulderN,
    RShoulderJA,
    RShoulderJ,
    RArmJ,
    RHandN,
    R1stNa,
    R1stNb,
    R2ndNa,
    R2ndNb,
    R3rdNa,
    R3rdNb,
    R4thNa,
    R4thNb,
    RHaveN,
    RThumbNa,
    RThumbNb,
    ThrowN,
    Extra
};

// Fighter States *to-do, make this an enum
#define ASID_DEADDOWN 0X00
#define ASID_DEADLEFT 0X01
#define ASID_DEADRIGHT 0X02
#define ASID_DEADUP 0X03
#define ASID_DEADUPSTAR 0X04
#define ASID_DEADUPSTARICE 0X05
#define ASID_DEADUPFALL 0X06
#define ASID_DEADUPFALLHITCAMERA 0X07
#define ASID_DEADUPFALLHITCAMERAFLAT 0X08
#define ASID_DEADUPFALLICE 0X09
#define ASID_DEADUPFALLHITCAMERAICE 0X0A
#define ASID_SLEEP 0X0B
#define ASID_REBIRTH 0X0C
#define ASID_REBIRTHWAIT 0X0D
#define ASID_WAIT 0X0E
#define ASID_WALKSLOW 0X0F
#define ASID_WALKMIDDLE 0X10
#define ASID_WALKFAST 0X11
#define ASID_TURN 0X12
#define ASID_TURNRUN 0X13
#define ASID_DASH 0X14
#define ASID_RUN 0X15
#define ASID_RUNDIRECT 0X16
#define ASID_RUNBRAKE 0X17
#define ASID_KNEEBEND 0X18
#define ASID_JUMPF 0X19
#define ASID_JUMPB 0X1A
#define ASID_JUMPAERIALF 0X1B
#define ASID_JUMPAERIALB 0X1C
#define ASID_FALL 0X1D
#define ASID_FALLF 0X1E
#define ASID_FALLB 0X1F
#define ASID_FALLAERIAL 0X20
#define ASID_FALLAERIALF 0X21
#define ASID_FALLAERIALB 0X22
#define ASID_FALLSPECIAL 0X23
#define ASID_FALLSPECIALF 0X24
#define ASID_FALLSPECIALB 0X25
#define ASID_DAMAGEFALL 0X26
#define ASID_SQUAT 0X27
#define ASID_SQUATWAIT 0X28
#define ASID_SQUATRV 0X29
#define ASID_LANDING 0X2A
#define ASID_LANDINGFALLSPECIAL 0X2B
#define ASID_ATTACK11 0X2C
#define ASID_ATTACK12 0X2D
#define ASID_ATTACK13 0X2E
#define ASID_ATTACK100START 0X2F
#define ASID_ATTACK100LOOP 0X30
#define ASID_ATTACK100END 0X31
#define ASID_ATTACKDASH 0X32
#define ASID_ATTACKS3HI 0X33
#define ASID_ATTACKS3HIS 0X34
#define ASID_ATTACKS3S 0X35
#define ASID_ATTACKS3LWS 0X36
#define ASID_ATTACKS3LW 0X37
#define ASID_ATTACKHI3 0X38
#define ASID_ATTACKLW3 0X39
#define ASID_ATTACKS4HI 0X3A
#define ASID_ATTACKS4HIS 0X3B
#define ASID_ATTACKS4S 0X3C
#define ASID_ATTACKS4LWS 0X3D
#define ASID_ATTACKS4LW 0X3E
#define ASID_ATTACKHI4 0X3F
#define ASID_ATTACKLW4 0X40
#define ASID_ATTACKAIRN 0X41
#define ASID_ATTACKAIRF 0X42
#define ASID_ATTACKAIRB 0X43
#define ASID_ATTACKAIRHI 0X44
#define ASID_ATTACKAIRLW 0X45
#define ASID_LANDINGAIRN 0X46
#define ASID_LANDINGAIRF 0X47
#define ASID_LANDINGAIRB 0X48
#define ASID_LANDINGAIRHI 0X49
#define ASID_LANDINGAIRLW 0X4A
#define ASID_DAMAGEHI1 0X4B
#define ASID_DAMAGEHI2 0X4C
#define ASID_DAMAGEHI3 0X4D
#define ASID_DAMAGEN1 0X4E
#define ASID_DAMAGEN2 0X4F
#define ASID_DAMAGEN3 0X50
#define ASID_DAMAGELW1 0X51
#define ASID_DAMAGELW2 0X52
#define ASID_DAMAGELW3 0X53
#define ASID_DAMAGEAIR1 0X54
#define ASID_DAMAGEAIR2 0X55
#define ASID_DAMAGEAIR3 0X56
#define ASID_DAMAGEFLYHI 0X57
#define ASID_DAMAGEFLYN 0X58
#define ASID_DAMAGEFLYLW 0X59
#define ASID_DAMAGEFLYTOP 0X5A
#define ASID_DAMAGEFLYROLL 0X5B
#define ASID_LIGHTGET 0X5C
#define ASID_HEAVYGET 0X5D
#define ASID_LIGHTTHROWF 0X5E
#define ASID_LIGHTTHROWB 0X5F
#define ASID_LIGHTTHROWHI 0X60
#define ASID_LIGHTTHROWLW 0X61
#define ASID_LIGHTTHROWDASH 0X62
#define ASID_LIGHTTHROWDROP 0X63
#define ASID_LIGHTTHROWAIRF 0X64
#define ASID_LIGHTTHROWAIRB 0X65
#define ASID_LIGHTTHROWAIRHI 0X66
#define ASID_LIGHTTHROWAIRLW 0X67
#define ASID_HEAVYTHROWF 0X68
#define ASID_HEAVYTHROWB 0X69
#define ASID_HEAVYTHROWHI 0X6A
#define ASID_HEAVYTHROWLW 0X6B
#define ASID_LIGHTTHROWF4 0X6C
#define ASID_LIGHTTHROWB4 0X6D
#define ASID_LIGHTTHROWHI4 0X6E
#define ASID_LIGHTTHROWLW4 0X6F
#define ASID_LIGHTTHROWAIRF4 0X70
#define ASID_LIGHTTHROWAIRB4 0X71
#define ASID_LIGHTTHROWAIRHI4 0X72
#define ASID_LIGHTTHROWAIRLW4 0X73
#define ASID_HEAVYTHROWF4 0X74
#define ASID_HEAVYTHROWB4 0X75
#define ASID_HEAVYTHROWHI4 0X76
#define ASID_HEAVYTHROWLW4 0X77
#define ASID_SWORDSWING1 0X78
#define ASID_SWORDSWING3 0X79
#define ASID_SWORDSWING4 0X7A
#define ASID_SWORDSWINGDASH 0X7B
#define ASID_BATSWING1 0X7C
#define ASID_BATSWING3 0X7D
#define ASID_BATSWING4 0X7E
#define ASID_BATSWINGDASH 0X7F
#define ASID_PARASOLSWING1 0X80
#define ASID_PARASOLSWING3 0X81
#define ASID_PARASOLSWING4 0X82
#define ASID_PARASOLSWINGDASH 0X83
#define ASID_HARISENSWING1 0X84
#define ASID_HARISENSWING3 0X85
#define ASID_HARISENSWING4 0X86
#define ASID_HARISENSWINGDASH 0X87
#define ASID_STARRODSWING1 0X88
#define ASID_STARRODSWING3 0X89
#define ASID_STARRODSWING4 0X8A
#define ASID_STARRODSWINGDASH 0X8B
#define ASID_LIPSTICKSWING1 0X8C
#define ASID_LIPSTICKSWING3 0X8D
#define ASID_LIPSTICKSWING4 0X8E
#define ASID_LIPSTICKSWINGDASH 0X8F
#define ASID_ITEMPARASOLOPEN 0X90
#define ASID_ITEMPARASOLFALL 0X91
#define ASID_ITEMPARASOLFALLSPECIAL 0X92
#define ASID_ITEMPARASOLDAMAGEFALL 0X93
#define ASID_LGUNSHOOT 0X94
#define ASID_LGUNSHOOTAIR 0X95
#define ASID_LGUNSHOOTEMPTY 0X96
#define ASID_LGUNSHOOTAIREMPTY 0X97
#define ASID_FIREFLOWERSHOOT 0X98
#define ASID_FIREFLOWERSHOOTAIR 0X99
#define ASID_ITEMSCREW 0X9A
#define ASID_ITEMSCREWAIR 0X9B
#define ASID_DAMAGESCREW 0X9C
#define ASID_DAMAGESCREWAIR 0X9D
#define ASID_ITEMSCOPESTART 0X9E
#define ASID_ITEMSCOPERAPID 0X9F
#define ASID_ITEMSCOPEFIRE 0XA0
#define ASID_ITEMSCOPEEND 0XA1
#define ASID_ITEMSCOPEAIRSTART 0XA2
#define ASID_ITEMSCOPEAIRRAPID 0XA3
#define ASID_ITEMSCOPEAIRFIRE 0XA4
#define ASID_ITEMSCOPEAIREND 0XA5
#define ASID_ITEMSCOPESTARTEMPTY 0XA6
#define ASID_ITEMSCOPERAPIDEMPTY 0XA7
#define ASID_ITEMSCOPEFIREEMPTY 0XA8
#define ASID_ITEMSCOPEENDEMPTY 0XA9
#define ASID_ITEMSCOPEAIRSTARTEMPTY 0XAA
#define ASID_ITEMSCOPEAIRRAPIDEMPTY 0XAB
#define ASID_ITEMSCOPEAIRFIREEMPTY 0XAC
#define ASID_ITEMSCOPEAIRENDEMPTY 0XAD
#define ASID_LIFTWAIT 0XAE
#define ASID_LIFTWALK1 0XAF
#define ASID_LIFTWALK2 0XB0
#define ASID_LIFTTURN 0XB1
#define ASID_GUARDON 0XB2
#define ASID_GUARD 0XB3
#define ASID_GUARDOFF 0XB4
#define ASID_GUARDSETOFF 0XB5
#define ASID_GUARDREFLECT 0XB6
#define ASID_DOWNBOUNDU 0XB7
#define ASID_DOWNWAITU 0XB8
#define ASID_DOWNDAMAGEU 0XB9
#define ASID_DOWNSTANDU 0XBA
#define ASID_DOWNATTACKU 0XBB
#define ASID_DOWNFOWARDU 0XBC
#define ASID_DOWNBACKU 0XBD
#define ASID_DOWNSPOTU 0XBE
#define ASID_DOWNBOUNDD 0XBF
#define ASID_DOWNWAITD 0XC0
#define ASID_DOWNDAMAGED 0XC1
#define ASID_DOWNSTANDD 0XC2
#define ASID_DOWNATTACKD 0XC3
#define ASID_DOWNFOWARDD 0XC4
#define ASID_DOWNBACKD 0XC5
#define ASID_DOWNSPOTD 0XC6
#define ASID_PASSIVE 0XC7
#define ASID_PASSIVESTANDF 0XC8
#define ASID_PASSIVESTANDB 0XC9
#define ASID_PASSIVEWALL 0XCA
#define ASID_PASSIVEWALLJUMP 0XCB
#define ASID_PASSIVECEIL 0XCC
#define ASID_SHIELDBREAKFLY 0XCD
#define ASID_SHIELDBREAKFALL 0XCE
#define ASID_SHIELDBREAKDOWNU 0XCF
#define ASID_SHIELDBREAKDOWND 0XD0
#define ASID_SHIELDBREAKSTANDU 0XD1
#define ASID_SHIELDBREAKSTANDD 0XD2
#define ASID_FURAFURA 0XD3
#define ASID_CATCH 0XD4
#define ASID_CATCHPULL 0XD5
#define ASID_CATCHDASH 0XD6
#define ASID_CATCHDASHPULL 0XD7
#define ASID_CATCHWAIT 0XD8
#define ASID_CATCHATTACK 0XD9
#define ASID_CATCHCUT 0XDA
#define ASID_THROWF 0XDB
#define ASID_THROWB 0XDC
#define ASID_THROWHI 0XDD
#define ASID_THROWLW 0XDE
#define ASID_CAPTUREPULLEDHI 0XDF
#define ASID_CAPTUREWAITHI 0XE0
#define ASID_CAPTUREDAMAGEHI 0XE1
#define ASID_CAPTUREPULLEDLW 0XE2
#define ASID_CAPTUREWAITLW 0XE3
#define ASID_CAPTUREDAMAGELW 0XE4
#define ASID_CAPTURECUT 0XE5
#define ASID_CAPTUREJUMP 0XE6
#define ASID_CAPTURENECK 0XE7
#define ASID_CAPTUREFOOT 0XE8
#define ASID_ESCAPEF 0XE9
#define ASID_ESCAPEB 0XEA
#define ASID_ESCAPE 0XEB
#define ASID_ESCAPEAIR 0XEC
#define ASID_REBOUNDSTOP 0XED
#define ASID_REBOUND 0XEE
#define ASID_THROWNF 0XEF
#define ASID_THROWNB 0XF0
#define ASID_THROWNHI 0XF1
#define ASID_THROWNLW 0XF2
#define ASID_THROWNLWWOMEN 0XF3
#define ASID_PASS 0XF4
#define ASID_OTTOTTO 0XF5
#define ASID_OTTOTTOWAIT 0XF6
#define ASID_FLYREFLECTWALL 0XF7
#define ASID_FLYREFLECTCEIL 0XF8
#define ASID_STOPWALL 0XF9
#define ASID_STOPCEIL 0XFA
#define ASID_MISSFOOT 0XFB
#define ASID_CLIFFCATCH 0XFC
#define ASID_CLIFFWAIT 0XFD
#define ASID_CLIFFCLIMBSLOW 0XFE
#define ASID_CLIFFCLIMBQUICK 0XFF
#define ASID_CLIFFATTACKSLOW 0X100
#define ASID_CLIFFATTACKQUICK 0X101
#define ASID_CLIFFESCAPESLOW 0X102
#define ASID_CLIFFESCAPEQUICK 0X103
#define ASID_CLIFFJUMPSLOW1 0X104
#define ASID_CLIFFJUMPSLOW2 0X105
#define ASID_CLIFFJUMPQUICK1 0X106
#define ASID_CLIFFJUMPQUICK2 0X107
#define ASID_APPEALR 0X108
#define ASID_APPEALL 0X109
#define ASID_SHOULDEREDWAIT 0X10A
#define ASID_SHOULDEREDWALKSLOW 0X10B
#define ASID_SHOULDEREDWALKMIDDLE 0X10C
#define ASID_SHOULDEREDWALKFAST 0X10D
#define ASID_SHOULDEREDTURN 0X10E
#define ASID_THROWNFF 0X10F
#define ASID_THROWNFB 0X110
#define ASID_THROWNFHI 0X111
#define ASID_THROWNFLW 0X112
#define ASID_CAPTURECAPTAIN 0X113
#define ASID_CAPTUREYOSHI 0X114
#define ASID_YOSHIEGG 0X115
#define ASID_CAPTUREKOOPA 0X116
#define ASID_CAPTUREDAMAGEKOOPA 0X117
#define ASID_CAPTUREWAITKOOPA 0X118
#define ASID_THROWNKOOPAF 0X119
#define ASID_THROWNKOOPAB 0X11A
#define ASID_CAPTUREKOOPAAIR 0X11B
#define ASID_CAPTUREDAMAGEKOOPAAIR 0X11C
#define ASID_CAPTUREWAITKOOPAAIR 0X11D
#define ASID_THROWNKOOPAAIRF 0X11E
#define ASID_THROWNKOOPAAIRB 0X11F
#define ASID_CAPTUREKIRBY 0X120
#define ASID_CAPTUREWAITKIRBY 0X121
#define ASID_THROWNKIRBYSTAR 0X122
#define ASID_THROWNCOPYSTAR 0X123
#define ASID_THROWNKIRBY 0X124
#define ASID_BARRELWAIT 0X125
#define ASID_BURY 0X126
#define ASID_BURYWAIT 0X127
#define ASID_BURYJUMP 0X128
#define ASID_DAMAGESONG 0X129
#define ASID_DAMAGESONGWAIT 0X12A
#define ASID_DAMAGESONGRV 0X12B
#define ASID_DAMAGEBIND 0X12C
#define ASID_CAPTUREMEWTWO 0X12D
#define ASID_CAPTUREMEWTWOAIR 0X12E
#define ASID_THROWNMEWTWO 0X12F
#define ASID_THROWNMEWTWOAIR 0X130
#define ASID_WARPSTARJUMP 0X131
#define ASID_WARPSTARFALL 0X132
#define ASID_HAMMERWAIT 0X133
#define ASID_HAMMERWALK 0X134
#define ASID_HAMMERTURN 0X135
#define ASID_HAMMERKNEEBEND 0X136
#define ASID_HAMMERFALL 0X137
#define ASID_HAMMERJUMP 0X138
#define ASID_HAMMERLANDING 0X139
#define ASID_KINOKOGIANTSTART 0X13A
#define ASID_KINOKOGIANTSTARTAIR 0X13B
#define ASID_KINOKOGIANTEND 0X13C
#define ASID_KINOKOGIANTENDAIR 0X13D
#define ASID_KINOKOSMALLSTART 0X13E
#define ASID_KINOKOSMALLSTARTAIR 0X13F
#define ASID_KINOKOSMALLEND 0X140
#define ASID_KINOKOSMALLENDAIR 0X141
#define ASID_ENTRY 0X142
#define ASID_ENTRYSTART 0X143
#define ASID_ENTRYEND 0X144
#define ASID_DAMAGEICE 0X145
#define ASID_DAMAGEICEJUMP 0X146
#define ASID_CAPTUREMASTERHAND 0X147
#define ASID_CAPTUREDAMAGEMASTERHAND 0X148
#define ASID_CAPTUREWAITMASTERHAND 0X149
#define ASID_THROWNMASTERHAND 0X14A
#define ASID_CAPTUREKIRBYYOSHI 0X14B
#define ASID_KIRBYYOSHIEGG 0X14C
#define ASID_CAPTURELEADEAD 0X14D
#define ASID_CAPTURELIKELIKE 0X14E
#define ASID_DOWNREFLECT 0X14F
#define ASID_CAPTURECRAZYHAND 0X150
#define ASID_CAPTUREDAMAGECRAZYHAND 0X151
#define ASID_CAPTUREWAITCRAZYHAND 0X152
#define ASID_THROWNCRAZYHAND 0X153
#define ASID_BARRELCANNONWAIT 0X154
#define ASID_ACTIONABLE 1000
#define ASID_ACTIONABLEGROUND 1001
#define ASID_ACTIONABLEAIR 1002
#define ASID_DAMAGEAIR 1003
#define ASID_JUMPS 1004
#define ASID_FALLS 1005

enum Ft_AttackKind
{
    ATKKIND_0,
    ATKKIND_NONE,
    ATKKIND_JAB1,
    ATKKIND_JAB2,
    ATKKIND_JAB3,
    ATKKIND_JAB4,
    ATKKIND_DASH,
    ATKKIND_FTILT,
    ATKKIND_UTILT,
    ATKKIND_DTILT,
    ATKKIND_FSMASH,
    ATKKIND_USMASH,
    ATKKIND_DSMASH,
    ATKKIND_NAIR,
    ATKKIND_FAIR,
    ATKKIND_BAIR,
    ATKKIND_UAIR,
    ATKKIND_DAIR,
    ATKKIND_SPECIALN,
    ATKKIND_SPECIALS,
    ATKKIND_SPECIALHI,
    ATKKIND_SPECIALLW,
};

/*** Structs ***/

struct Playerblock
{
    int state;           // 0x00 = not present, 0x02 = HMN, 0x03 = CPU
    int ft_kind;         // external ID
    int type;            // (0x00 is HMN, 0x01 is CPU, 0x02 is Demo, 0x03 n/a)
    u8 isTransformed[2]; // 0xC, 1 indicates the fighter that is active
    Vec3 tagPos;         // 0x10
    Vec3 spawnPos;       // 0x1C
    Vec3 respawnPos;     // 0x28
    int x34;
    int x38;
    int x3C;
    float initialFacing; // 0x40
    u8 costume;          // 0x44
    u8 x45;              // 0x45
    u8 tint;             // 0x46
    u8 team;             // 0x47
    u8 controller;       // 0x48
    u8 cpuLv;
    u8 cpuKind;
    u8 handicap;
    float x50;
    float attack;
    float defense;
    float scale;
    u16 damage;
    u16 initialDamage;
    u16 stamina;
    int falls[2];
    int ko[6];
    int x88;
    u16 selfDestructs;
    u8 stocks;
    int coins_curr;
    int coins_total;
    int x98;
    int x9c;
    int stickSmashes[2];
    int tag;
    u8 flags2;
    u8 flags3;
    GOBJ *fighterData;
    GOBJ *fighterDataSub;
};

struct PlayerData
{
    // byte 0x0
    u8 kind;
    u8 status;
    u8 stocks;
    u8 costume;
    // 0x4
    u8 portNumberOverride;
    u8 spawnPointOverride;
    u8 facingDirection;
    u8 subcolor;
    // 0x8
    u8 handicap;
    u8 team;
    u8 nametag;
    u8 xb;
    // 0xC
    unsigned char isRumble : 1;
    unsigned char isEntry : 1;
    unsigned char unk2 : 6;
    unsigned char unk3 : 8;
    u8 cpuKind;
    u8 cpuLevel; // 0xf
    // 0x10
    u16 damageStart;
    u16 damageSpawn;
    u16 staminaStart; // 0x14
    float attack;     // 0x18
    float defense;    // 0x1C
    float scale;      // 0x20
};

struct FighterBone
{
    JOBJ *joint;
    JOBJ *joint2; // used for interpolation
    int flags;
    int flags2;
};

struct DynamicsDesc
{
    int root_bone; // bone index;
    void *params;  // dynamics params;
    int num;       // number of children bones to make dynamic
    float xc;
    float x10;
    float x14;
};

struct DynamicsHitDesc
{
    int bone; // bone index
    int x4;   // unk
    Vec3 x8;  // unk
};

struct DynamicsBehave
{
    int num; // number of dynamic bones to animate in the boneset
};

struct ftDynamics
{
    int dynamics_num;                   // number of dynamic bonesets for this fighter
    DynamicsDesc *dynamics_desc;        // boneset data array (one for each boneset)
    int dynamics_hit_num;               // (no collide bubbles), max is 11
    DynamicsHitDesc *dynamics_hit_desc; // dynamic hit data array (one for each dynamic hit)
    DynamicsBehave **dynamics_behave;   // pointer to an array of dynamics behavior pointers.
};

struct FtDynamicBoneset
{
    int apply_phys_num; // if this is 256, dyanmics are not processed
    void *unk_ptr;      // is stored @ 8000fdd4, comes from a nonstandard heap @ -0x52fc(r13)
    int bone_num;       // number of bones in this boneset
    float xc;           // stored @ 80011718, 0x8 of dynamicdesc
    float x10;          // stored @ 80011720, 0xC of dynamicdesc
    float x14;          // stored @ 80011728, 0x10 of dynamicdesc
};

struct FtDynamicRoot
{
    JOBJ *jobj;          // 0x0
    Vec4 rot;            // 0x4 quaternion
    Vec3 trans;          // 0x14
    Vec3 scale;          // 0x20
    Vec3 rot_global;     // 0x2C, copied from 0x50, 0x60, 0x70 of jobj
    float x38;           // 0x38, initialized to 1 @ 8000ff30
    float x3c;           // 0x3c, initialized to 0 @ 8000ff34
    float x40;           // 0x40, initialized to 0 @ 8000ff38
    float x44;           // 0x44, initialized to 0 @ 8000ff3c
    float x48;           // x48, initialized to 0 @ 8000ff44
    float x4c;           // x4c, THIS IS THE START OF A STRUCTURE, bunch of floats from the dynamicdesc. stored @ 80011744
    float x50;           // 0x3c
    float x54;           // 0x40
    float x58;           // 0x44
    float x5c;           // x048
    float x60;           // 0x38
    float x64;           // 0x3c
    float x68;           // 0x40
    float x6c;           // 0x44
    float x70;           // x048
    float x74;           // 0x38
    float x78;           // 0x3c
    float x7c;           // 0x40
    float x80;           // 0x44
    float x84;           // x048
    float x88;           // 0x38
    float x8c;           // 0x3c
    FtDynamicRoot *next; // 0x90
    float x94;           // 0x44
};

struct FtDynamicHit
{
    Vec3 offset;    // 0x1670, 0x0
    float size;     // 0x167C, 0xC
    JOBJ *bone;     // 0x1680, 0x10
    int x14;        // 0x1684, 0x14
    Vec3 pos;       // 0x1688, 0x18
    int bone_index; // 0x1694, 0x24
};

struct ftData
{
    char footBoneL;
    char footBoneR;
    int *charAttributes; // 0x4
    u8 *modelLookup;     // 0x8
    int animFlags;       // 0xC
    int animDynamics;    // 0x10
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    ftDynamics *dynamics; // 0x2C
    int hurtbox;
    int *center_bubble;
    int x38;
    int x3C;
    int x40;
    int coll;
    void *items;
    int *x4C;
    int x50;
    int x54;
    int *boneLookup;
};

struct ftChkDevice // 80459a68
{
    int x0;
    int x4;
    int x8;
    int xc;
    int x10;
    int x14;
    int x18;
    int x1c;
    int x20;
    GOBJ *gobj;
    int hazard_kind;
    void *check;
};

struct SubactionHeader
{
    char *symbol;
    int animOffset;
    int animSize;
    int *subactionData;
    int flags;
};

struct MoveLogic
{
    int animation_id;
    int flags;
    char move_id;
    char bitflags1;
    void *animation_callback;
    void *iasa_callback;
    void *physics_callback;
    void *collision_callback;
    void *camera_callback;
};

struct ReflectDesc
{
    int bone;
    int max_damage;
    Vec3 pos;
    float radius;
    float damage_mult;
    float velocity_mult;
    int flags;
};

struct ShieldDesc
{
    int bone;
    int max_damage;
    Vec3 pos;
    float radius;
    float damage_mult;
    float velocity_mult;
    int flags;
};

struct AbsorbDesc
{
    int bone;
    int max_damage;
    Vec3 pos;
    float radius;
    float damage_mult;
    float velocity_mult;
    int flags;
};

struct HitVictim
{
    void *victim_data; // the gobj that was hit
    int unk;           // not sure, is set to 0 when hitting them
};

struct ftHit
{
    int active;                   // 0x0
    int x4;                       // 0x4
    int dmg;                      // 0x8
    float dmg_f;                  // 0xc
    Vec3 offset;                  // 0x10
    float size;                   // 0x1c
    int angle;                    // 0x20
    int kb_growth;                // 0x24
    int wdsk;                     // 0x28
    int kb;                       // 0x2c
    int attribute;                // 0x30
    int shield_dmg;               // 0x34
    int hitsound_severity;        // 0x38. hurtbox interaction. 0 = none, 1 = grounded, 2 = aerial, 3 = both
    int hitsound_kind;            // 0x3c
    char x40;                     // 0x40
    char x41;                     // 0x41
    unsigned char x421 : 1;       // 0x42 0x80
    unsigned char x422 : 1;       // 0x42 0x40
    unsigned char x423 : 1;       // 0x42 0x20
    unsigned char x424 : 1;       // 0x42 0x10
    unsigned char no_hurt : 1;    // 0x42 0x08      ignore hurtbox
    unsigned char no_reflect : 1; // 0x42 0x04      ignore reflect?
    unsigned char x427 : 1;       // 0x42 0x02
    unsigned char x428 : 1;       // 0x42 0x01
    unsigned char x431 : 1;       // 0x43 0x80
    unsigned char x432 : 1;       // 0x43 0x40
    unsigned char hit_all : 1;    // 0x43 0x20
    unsigned char x434 : 1;       // 0x43 0x10
    unsigned char x435 : 1;       // 0x43 0x08
    unsigned char x436 : 1;       // 0x43 0x04
    unsigned char x437 : 1;       // 0x43 0x02
    unsigned char x438 : 1;       // 0x43 0x01
    u8 x44;                       // 0x44
    u8 victim_num;                // 0x45
    JOBJ *bone;                   // 0x48
    Vec3 pos;                     // 0x4c
    Vec3 pos_prev;                // 0x58
    Vec3 pos_coll;                // 0x64   position of hurt collision
    float coll_distance;          // 0x70   Distance From Collding FtHurt (Used for phantom hit collision calculation)
    HitVictim victims[24];        // 0x74
    int x134;                     // 0x134, flags of some sort
};

struct FtHurt
{
    int x0;                       // 0x0
    Vec3 hurt1_offset;            // 0x4
    Vec3 hurt2_offset;            // 0x10
    float scale;                  // 0x1c
    JOBJ *jobj;                   // 0x20
    unsigned char is_updated : 1; // 0x24, if enabled, wont update position
    unsigned char x24_2 : 1;      // 0x24 0x40
    unsigned char x24_3 : 1;      // 0x24 0x20
    unsigned char x24_4 : 1;      // 0x24 0x10
    unsigned char x24_5 : 1;      // 0x24 0x08
    unsigned char x24_6 : 1;      // 0x24 0x04
    unsigned char x24_7 : 1;      // 0x24 0x02
    unsigned char x24_8 : 1;      // 0x24 0x01
    Vec3 hurt1_pos;               // 0x28
    Vec3 hurt2_pos;               // 0x34
    int bone_index;               // 0x40
    int hurt_kind;                // 0x44. 0 = low, 1 = mid, 2 = high
    int is_grabbable;             // 0x48
};

struct FtAfterImageKey
{
    Vec3 pos;
    Vec3 rot;
} FtAfterImageKey;

struct CPU
{
    int held;       // 0x0
    s8 lstickX;     // 0x4
    s8 lstickY;     // 0x5
    s8 cstickX;     // 0x6
    s8 cstickY;     // 0x7
    int x8;         // 0x8
    int ai;         // 0xc
    int level;      // 0x10
    int x14;        // 0x14
    int x18;        // 0x18
    int x1c;        // 0x1c
    int x20;        // 0x20
    int x24;        // 0x24
    int x28;        // 0x28
    int x2c;        // 0x2c
    int x30;        // 0x30
    int x34;        // 0x34
    int x38;        // 0x38
    int x3c;        // 0x3c
    int x40;        // 0x40
    int x44;        // 0x44
    int x48;        // 0x48
    int x4c;        // 0x4c
    int x50;        // 0x50
    int x54;        // 0x54
    int x58;        // 0x58
    int x5c;        // 0x5c
    int x60;        // 0x60
    int x64;        // 0x64
    int x68;        // 0x68
    int x6c;        // 0x6c
    int x70;        // 0x70
    int x74;        // 0x74
    int x78;        // 0x78
    int x7c;        // 0x7c
    int x80;        // 0x80
    int x84;        // 0x84
    int x88;        // 0x88
    int x8c;        // 0x8c
    int x90;        // 0x90
    int x94;        // 0x94
    int x98;        // 0x98
    int x9c;        // 0x9c
    int xa0;        // 0xa0
    int xa4;        // 0xa4
    int xa8;        // 0xa8
    int xac;        // 0xac
    int xb0;        // 0xb0
    int xb4;        // 0xb4
    int xb8;        // 0xb8
    int xbc;        // 0xbc
    int xc0;        // 0xc0
    int xc4;        // 0xc4
    int xc8;        // 0xc8
    int xcc;        // 0xcc
    int xd0;        // 0xd0
    int xd4;        // 0xd4
    int xd8;        // 0xd8
    int xdc;        // 0xdc
    int xe0;        // 0xe0
    int xe4;        // 0xe4
    int xe8;        // 0xe8
    int xec;        // 0xec
    int xf0;        // 0xf0
    int xf4;        // 0xf4
    int xf8;        // 0xf8
    int xfc;        // 0xfc
    int x100;       // 0x100
    int x104;       // 0x104
    int x108;       // 0x108
    int x10c;       // 0x10c
    int x110;       // 0x110
    int x114;       // 0x114
    int x118;       // 0x118
    int x11c;       // 0x11c
    int x120;       // 0x120
    int x124;       // 0x124
    int x128;       // 0x128
    int x12c;       // 0x12c
    int x130;       // 0x130
    int x134;       // 0x134
    int x138;       // 0x138
    int x13c;       // 0x13c
    int x140;       // 0x140
    int x144;       // 0x144
    int x148;       // 0x148
    int x14c;       // 0x14c
    int x150;       // 0x150
    int x154;       // 0x154
    int x158;       // 0x158
    int x15c;       // 0x15c
    int x160;       // 0x160
    int x164;       // 0x164
    int x168;       // 0x168
    int x16c;       // 0x16c
    int x170;       // 0x170
    int x174;       // 0x174
    int x178;       // 0x178
    int x17c;       // 0x17c
    int x180;       // 0x180
    int x184;       // 0x184
    int x188;       // 0x188
    int x18c;       // 0x18c
    int x190;       // 0x190
    int x194;       // 0x194
    int x198;       // 0x198
    int x19c;       // 0x19c
    int x1a0;       // 0x1a0
    int x1a4;       // 0x1a4
    int x1a8;       // 0x1a8
    int x1ac;       // 0x1ac
    int x1b0;       // 0x1b0
    int x1b4;       // 0x1b4
    int x1b8;       // 0x1b8
    int x1bc;       // 0x1bc
    int x1c0;       // 0x1c0
    int x1c4;       // 0x1c4
    int x1c8;       // 0x1c8
    int x1cc;       // 0x1cc
    int x1d0;       // 0x1d0
    int x1d4;       // 0x1d4
    int x1d8;       // 0x1d8
    int x1dc;       // 0x1dc
    int x1e0;       // 0x1e0
    int x1e4;       // 0x1e4
    int x1e8;       // 0x1e8
    int x1ec;       // 0x1ec
    int x1f0;       // 0x1f0
    int x1f4;       // 0x1f4
    int x1f8;       // 0x1f8
    int x1fc;       // 0x1fc
    int x200;       // 0x200
    int x204;       // 0x204
    int x208;       // 0x208
    int x20c;       // 0x20c
    int x210;       // 0x210
    int x214;       // 0x214
    int x218;       // 0x218
    int x21c;       // 0x21c
    int x220;       // 0x220
    int x224;       // 0x224
    int x228;       // 0x228
    int x22c;       // 0x22c
    int x230;       // 0x230
    int x234;       // 0x234
    int x238;       // 0x238
    int x23c;       // 0x23c
    int x240;       // 0x240
    int x244;       // 0x244
    int x248;       // 0x248
    int x24c;       // 0x24c
    int x250;       // 0x250
    int x254;       // 0x254
    int x258;       // 0x258
    int x25c;       // 0x25c
    int x260;       // 0x260
    int x264;       // 0x264
    int x268;       // 0x268
    int x26c;       // 0x26c
    int x270;       // 0x270
    int x274;       // 0x274
    int x278;       // 0x278
    int x27c;       // 0x27c
    int x280;       // 0x280
    int x284;       // 0x284
    int x288;       // 0x288
    int x28c;       // 0x28c
    int x290;       // 0x290
    int x294;       // 0x294
    int x298;       // 0x298
    int x29c;       // 0x29c
    int x2a0;       // 0x2a0
    int x2a4;       // 0x2a4
    int x2a8;       // 0x2a8
    int x2ac;       // 0x2ac
    int x2b0;       // 0x2b0
    int x2b4;       // 0x2b4
    int x2b8;       // 0x2b8
    int x2bc;       // 0x2bc
    int x2c0;       // 0x2c0
    int x2c4;       // 0x2c4
    int x2c8;       // 0x2c8
    int x2cc;       // 0x2cc
    int x2d0;       // 0x2d0
    int x2d4;       // 0x2d4
    int x2d8;       // 0x2d8
    int x2dc;       // 0x2dc
    int x2e0;       // 0x2e0
    int x2e4;       // 0x2e4
    int x2e8;       // 0x2e8
    int x2ec;       // 0x2ec
    int x2f0;       // 0x2f0
    int x2f4;       // 0x2f4
    int x2f8;       // 0x2f8
    int x2fc;       // 0x2fc
    int x300;       // 0x300
    int x304;       // 0x304
    int x308;       // 0x308
    int x30c;       // 0x30c
    int x310;       // 0x310
    int x314;       // 0x314
    int x318;       // 0x318
    int x31c;       // 0x31c
    int x320;       // 0x320
    int x324;       // 0x324
    int x328;       // 0x328
    int x32c;       // 0x32c
    int x330;       // 0x330
    int x334;       // 0x334
    int x338;       // 0x338
    int x33c;       // 0x33c
    int x340;       // 0x340
    int x344;       // 0x344
    int x348;       // 0x348
    int x34c;       // 0x34c
    int x350;       // 0x350
    int x354;       // 0x354
    int x358;       // 0x358
    int x35c;       // 0x35c
    int x360;       // 0x360
    int x364;       // 0x364
    int x368;       // 0x368
    int x36c;       // 0x36c
    int x370;       // 0x370
    int x374;       // 0x374
    int x378;       // 0x378
    int x37c;       // 0x37c
    int x380;       // 0x380
    int x384;       // 0x384
    int x388;       // 0x388
    int x38c;       // 0x38c
    int x390;       // 0x390
    int x394;       // 0x394
    int x398;       // 0x398
    int x39c;       // 0x39c
    int x3a0;       // 0x3a0
    int x3a4;       // 0x3a4
    int x3a8;       // 0x3a8
    int x3ac;       // 0x3ac
    int x3b0;       // 0x3b0
    int x3b4;       // 0x3b4
    int x3b8;       // 0x3b8
    int x3bc;       // 0x3bc
    int x3c0;       // 0x3c0
    int x3c4;       // 0x3c4
    int x3c8;       // 0x3c8
    int x3cc;       // 0x3cc
    int x3d0;       // 0x3d0
    int x3d4;       // 0x3d4
    int x3d8;       // 0x3d8
    int x3dc;       // 0x3dc
    int x3e0;       // 0x3e0
    int x3e4;       // 0x3e4
    int x3e8;       // 0x3e8
    int x3ec;       // 0x3ec
    int x3f0;       // 0x3f0
    int x3f4;       // 0x3f4
    int x3f8;       // 0x3f8
    int x3fc;       // 0x3fc
    int x400;       // 0x400
    int x404;       // 0x404
    int x408;       // 0x408
    int x40c;       // 0x40c
    int x410;       // 0x410
    int x414;       // 0x414
    int x418;       // 0x418
    int x41c;       // 0x41c
    int x420;       // 0x420
    int x424;       // 0x424
    int x428;       // 0x428
    int x42c;       // 0x42c
    int x430;       // 0x430
    int x434;       // 0x434
    int x438;       // 0x438
    int x43c;       // 0x43c
    int x440;       // 0x440
    int *curr_unk;  // 0x444
    int *curr_unk2; // 0x448
    int x44c;       // 0x44c
    int x450;       // 0x450
    int x454;       // 0x454
    int x458;       // 0x458
    int x45c;       // 0x45c
    int x460;       // 0x460
    int x464;       // 0x464
    int x468;       // 0x468
    int x46c;       // 0x46c
    int x470;       // 0x470
    int x474;       // 0x474
    int x478;       // 0x478
    int x47c;       // 0x47c
    int x480;       // 0x480
    int x484;       // 0x484
    int x488;       // 0x488
    int x48c;       // 0x48c
    int x490;       // 0x490
    int x494;       // 0x494
    int x498;       // 0x498
    int x49c;       // 0x49c
    int x4a0;       // 0x4a0
    int x4a4;       // 0x4a4
    int x4a8;       // 0x4a8
    int x4ac;       // 0x4ac
    int x4b0;       // 0x4b0
    int x4b4;       // 0x4b4
    int x4b8;       // 0x4b8
    int x4bc;       // 0x4bc
    int x4c0;       // 0x4c0
    int x4c4;       // 0x4c4
    int x4c8;       // 0x4c8
    int x4cc;       // 0x4cc
    int x4d0;       // 0x4d0
    int x4d4;       // 0x4d4
    int x4d8;       // 0x4d8
    int x4dc;       // 0x4dc
    int x4e0;       // 0x4e0
    int x4e4;       // 0x4e4
    int x4e8;       // 0x4e8
    int x4ec;       // 0x4ec
    int x4f0;       // 0x4f0
    int x4f4;       // 0x4f4
    int x4f8;       // 0x4f8
    int x4fc;       // 0x4fc
    int x500;       // 0x500
    int x504;       // 0x504
    int x508;       // 0x508
    int x50c;       // 0x50c
    int x510;       // 0x510
    int x514;       // 0x514
    int x518;       // 0x518
    int x51c;       // 0x51c
    int x520;       // 0x520
    int x524;       // 0x524
    int x528;       // 0x528
    int x52c;       // 0x52c
    int x530;       // 0x530
    int x534;       // 0x534
    int x538;       // 0x538
    int x53c;       // 0x53c
    int x540;       // 0x540
    int x544;       // 0x544
    int x548;       // 0x548
    int x54c;       // 0x54c
    int x550;       // 0x550
    int x554;       // 0x554
};

struct ftCommonData
{
    float x0;                     // 0x0
    float x4;                     // 0x4
    float x8;                     // 0x8
    float xc;                     // 0xc
    float x10;                    // 0x10
    float x14;                    // 0x14
    float x18;                    // 0x18
    float x1c;                    // 0x1c
    float lstick_tilt;            // 0x20
    float x24;                    // 0x24
    float x28;                    // 0x28
    float x2c;                    // 0x2c
    float x30;                    // 0x30
    float x34;                    // 0x34
    float x38;                    // 0x38
    float x3c;                    // 0x3c
    float x40;                    // 0x40
    float x44;                    // 0x44
    float x48;                    // 0x48
    float x4c;                    // 0x4c
    float x50;                    // 0x50
    float x54;                    // 0x54
    float x58;                    // 0x58
    float x5c;                    // 0x5c
    float x60;                    // 0x60
    float x64;                    // 0x64
    float x68;                    // 0x68
    float friction_mult;          // 0x6c
    float jumpaerial_lsticky;     // 0x70
    float jumpaerial_lsticktimer; // 0x74
    float x78;                    // 0x78
    float x7c;                    // 0x7c
    float x80;                    // 0x80
    float x84;                    // 0x84
    float x88;                    // 0x88
    float x8c;                    // 0x8c
    float lstick_rebirthfall;     // 0x90
    float x94;                    // 0x94
    float x98;                    // 0x98
    float x9c;                    // 0x9c
    float xa0;                    // 0xa0
    float xa4;                    // 0xa4
    float xa8;                    // 0xa8
    float xac;                    // 0xac
    float xb0;                    // 0xb0
    float xb4;                    // 0xb4
    float xb8;                    // 0xb8
    float xbc;                    // 0xbc
    float xc0;                    // 0xc0
    float xc4;                    // 0xc4
    float xc8;                    // 0xc8
    float xcc;                    // 0xcc
    float xd0;                    // 0xd0
    float xd4;                    // 0xd4
    float xd8;                    // 0xd8
    float xdc;                    // 0xdc
    float xe0;                    // 0xe0
    float xe4;                    // 0xe4
    float xe8;                    // 0xe8
    float xec;                    // 0xec
    float xf0;                    // 0xf0
    float xf4;                    // 0xf4
    float xf8;                    // 0xf8
    float xfc;                    // 0xfc
    float kb_mult;                // 0x100
    float x104;                   // 0x104
    float x108;                   // 0x108
    float x10c;                   // 0x10c
    float x110;                   // 0x110
    float x114;                   // 0x114
    float x118;                   // 0x118
    float x11c;                   // 0x11c
    float x120;                   // 0x120
    float x124;                   // 0x124
    float x128;                   // 0x128
    float x12c;                   // 0x12c
    float x130;                   // 0x130
    float x134;                   // 0x134
    float x138;                   // 0x138
    float x13c;                   // 0x13c
    float x140;                   // 0x140
    float x144;                   // 0x144
    float x148;                   // 0x148
    float x14c;                   // 0x14c
    float x150;                   // 0x150
    float x154;                   // 0x154
    float x158;                   // 0x158
    float x15c;                   // 0x15c
    float x160;                   // 0x160
    float x164;                   // 0x164
    float x168;                   // 0x168
    float kb_maxVelX;             // 0x16c
    float x170;                   // 0x170
    float x174;                   // 0x174
    float x178;                   // 0x178
    float x17c;                   // 0x17c
    float x180;                   // 0x180
    float x184;                   // 0x184
    float x188;                   // 0x188
    float x18c;                   // 0x18c
    float x190;                   // 0x190
    float x194;                   // 0x194
    float x198;                   // 0x198
    float x19c;                   // 0x19c
    float x1a0;                   // 0x1a0
    float x1a4;                   // 0x1a4
    float tdi_maxAngle;           // 0x1a8
    float x1ac;                   // 0x1ac
    float x1b0;                   // 0x1b0
    float x1b4;                   // 0x1b4
    float x1b8;                   // 0x1b8
    float kb_bounceDecay;         // 0x1bc
    float x1c0;                   // 0x1c0
    float x1c4;                   // 0x1c4
    float x1c8;                   // 0x1c8
    float x1cc;                   // 0x1cc
    float x1d0;                   // 0x1d0
    float x1d4;                   // 0x1d4
    float x1d8;                   // 0x1d8
    float x1dc;                   // 0x1dc
    float x1e0;                   // 0x1e0
    float x1e4;                   // 0x1e4
    float x1e8;                   // 0x1e8
    float x1ec;                   // 0x1ec
    float x1f0;                   // 0x1f0
    float x1f4;                   // 0x1f4
    float x1f8;                   // 0x1f8
    float x1fc;                   // 0x1fc
    float x200;                   // 0x200
    float kb_frameDecay;          // 0x204
    float x208;                   // 0x208
    float x20c;                   // 0x20c
    float x210;                   // 0x210
    float x214;                   // 0x214
    float x218;                   // 0x218
    float x21c;                   // 0x21c
    float x220;                   // 0x220
    float x224;                   // 0x224
    float x228;                   // 0x228
    float x22c;                   // 0x22c
    float x230;                   // 0x230
    float x234;                   // 0x234
    float x238;                   // 0x238
    float x23c;                   // 0x23c
    float x240;                   // 0x240
    float x244;                   // 0x244
    float x248;                   // 0x248
    float x24c;                   // 0x24c
    float x250;                   // 0x250
    float x254;                   // 0x254
    float x258;                   // 0x258
    float x25c;                   // 0x25c
    float x260;                   // 0x260
    float x264;                   // 0x264
    float x268;                   // 0x268
    float x26c;                   // 0x26c
    float x270;                   // 0x270
    float x274;                   // 0x274
    float x278;                   // 0x278
    float x27c;                   // 0x27c
    float x280;                   // 0x280
    float x284;                   // 0x284
    float x288;                   // 0x288
    float x28c;                   // 0x28c
    float x290;                   // 0x290
    float x294;                   // 0x294
    float x298;                   // 0x298
    float x29c;                   // 0x29c
    float x2a0;                   // 0x2a0
    float x2a4;                   // 0x2a4
    float x2a8;                   // 0x2a8
    float x2ac;                   // 0x2ac
    float x2b0;                   // 0x2b0
    float x2b4;                   // 0x2b4
    float x2b8;                   // 0x2b8
    float x2bc;                   // 0x2bc
    float x2c0;                   // 0x2c0
    float x2c4;                   // 0x2c4
    float x2c8;                   // 0x2c8
    float x2cc;                   // 0x2cc
    float x2d0;                   // 0x2d0
    float x2d4;                   // 0x2d4
    float x2d8;                   // 0x2d8
    float x2dc;                   // 0x2dc
    float x2e0;                   // 0x2e0
    float x2e4;                   // 0x2e4
    float x2e8;                   // 0x2e8
    float x2ec;                   // 0x2ec
    float x2f0;                   // 0x2f0
    float x2f4;                   // 0x2f4
    float x2f8;                   // 0x2f8
    float x2fc;                   // 0x2fc
    float x300;                   // 0x300
    float x304;                   // 0x304
    float x308;                   // 0x308
    float x30c;                   // 0x30c
    float x310;                   // 0x310
    float x314;                   // 0x314
    float x318;                   // 0x318
    float x31c;                   // 0x31c
    float x320;                   // 0x320
    float x324;                   // 0x324
    float x328;                   // 0x328
    float x32c;                   // 0x32c
    float x330;                   // 0x330
    float x334;                   // 0x334
    float escapeair_vel;          // 0x338
    float escapeair_veldecaymult; // 0x33c
    float x340;                   // 0x340
    float x344;                   // 0x344
    float x348;                   // 0x348
    float x34c;                   // 0x34c
    float x350;                   // 0x350
    float x354;                   // 0x354
    float x358;                   // 0x358
    float x35c;                   // 0x35c
    float x360;                   // 0x360
    float x364;                   // 0x364
    float x368;                   // 0x368
    float x36c;                   // 0x36c
    float x370;                   // 0x370
    float x374;                   // 0x374
    float x378;                   // 0x378
    float x37c;                   // 0x37c
    float x380;                   // 0x380
    float x384;                   // 0x384
    float x388;                   // 0x388
    float x38c;                   // 0x38c
    float x390;                   // 0x390
    float x394;                   // 0x394
    float x398;                   // 0x398
    float x39c;                   // 0x39c
    float x3a0;                   // 0x3a0
    float x3a4;                   // 0x3a4
    float x3a8;                   // 0x3a8
    float x3ac;                   // 0x3ac
    float x3b0;                   // 0x3b0
    float x3b4;                   // 0x3b4
    float x3b8;                   // 0x3b8
    float x3bc;                   // 0x3bc
    float x3c0;                   // 0x3c0
    float x3c4;                   // 0x3c4
    float x3c8;                   // 0x3c8
    float x3cc;                   // 0x3cc
    float x3d0;                   // 0x3d0
    float x3d4;                   // 0x3d4
    float x3d8;                   // 0x3d8
    float x3dc;                   // 0x3dc
    float x3e0;                   // 0x3e0
    float x3e4;                   // 0x3e4
    float x3e8;                   // 0x3e8
    float x3ec;                   // 0x3ec
    float x3f0;                   // 0x3f0
    float x3f4;                   // 0x3f4
    float x3f8;                   // 0x3f8
    float x3fc;                   // 0x3fc
    float x400;                   // 0x400
    float x404;                   // 0x404
    float x408;                   // 0x408
    float x40c;                   // 0x40c
    float x410;                   // 0x410
    float x414;                   // 0x414
    float x418;                   // 0x418
    float x41c;                   // 0x41c
    float x420;                   // 0x420
    float x424;                   // 0x424
    float x428;                   // 0x428
    float x42c;                   // 0x42c
    float x430;                   // 0x430
    float x434;                   // 0x434
    float x438;                   // 0x438
    float x43c;                   // 0x43c
    float x440;                   // 0x440
    float x444;                   // 0x444
    float x448;                   // 0x448
    float x44c;                   // 0x44c
    float x450;                   // 0x450
    float zjostle_frame;          // 0x45c
    float zjostle_max;            // 0x460
    float ms_zjostle_frame;       // 0x45c
    float ms_zjostle_max;         // 0x460
    float x464;                   // 0x464
    float x468;                   // 0x468
    float x46c;                   // 0x46c
    float x470;                   // 0x470
    float x474;                   // 0x474
    float x478;                   // 0x478
    float x47c;                   // 0x47c
    float x480;                   // 0x480
    float x484;                   // 0x484
    float x488;                   // 0x488
    float x48c;                   // 0x48c
    float x490;                   // 0x490
    float x494;                   // 0x494
    float x498;                   // 0x498
    int cliff_invuln_time;        // 0x49c
    float x4a0;                   // 0x4a0
    float x4a4;                   // 0x4a4
    float x4a8;                   // 0x4a8
    float x4ac;                   // 0x4ac
    float asdi_mag;               // 0x4b0
    float x4b4;                   // 0x4b4
    float x4b8;                   // 0x4b8
    float asdi_units;             // 0x4bc
    float x4c0;                   // 0x4c0
    float x4c4;                   // 0x4c4
    float x4c8;                   // 0x4c8
    float x4cc;                   // 0x4cc
    float x4d0;                   // 0x4d0
    float x4d4;                   // 0x4d4
    float x4d8;                   // 0x4d8
    float x4dc;                   // 0x4dc
    float x4e0;                   // 0x4e0
    float x4e4;                   // 0x4e4
    float x4e8;                   // 0x4e8
    float x4ec;                   // 0x4ec
    float x4f0;                   // 0x4f0
    float x4f4;                   // 0x4f4
    float x4f8;                   // 0x4f8
    float x4fc;                   // 0x4fc
    float x500;                   // 0x500
    float x504;                   // 0x504
    float x508;                   // 0x508
    float x50c;                   // 0x50c
    float x510;                   // 0x510
    float x514;                   // 0x514
    float x518;                   // 0x518
    float x51c;                   // 0x51c
    float x520;                   // 0x520
    float x524;                   // 0x524
    float x528;                   // 0x528
    float x52c;                   // 0x52c
    float x530;                   // 0x530
    float x534;                   // 0x534
    float x538;                   // 0x538
    float x53c;                   // 0x53c
    float x540;                   // 0x540
    float x544;                   // 0x544
    float x548;                   // 0x548
    float x54c;                   // 0x54c
    float x550;                   // 0x550
    float x554;                   // 0x554
    float x558;                   // 0x558
    float x55c;                   // 0x55c
    float x560;                   // 0x560
    float x564;                   // 0x564
    float x568;                   // 0x568
    float x56c;                   // 0x56c
    float x570;                   // 0x570
    float x574;                   // 0x574
    float x578;                   // 0x578
    float x57c;                   // 0x57c
    float x580;                   // 0x580
    float x584;                   // 0x584
    float x588;                   // 0x588
    float x58c;                   // 0x58c
    float x590;                   // 0x590
    float x594;                   // 0x594
    float x598;                   // 0x598
    float x59c;                   // 0x59c
    float x5a0;                   // 0x5a0
    float x5a4;                   // 0x5a4
    float x5a8;                   // 0x5a8
    float x5ac;                   // 0x5ac
    float x5b0;                   // 0x5b0
    float x5b4;                   // 0x5b4
    float x5b8;                   // 0x5b8
    float x5bc;                   // 0x5bc
    float x5c0;                   // 0x5c0
    float x5c4;                   // 0x5c4
    float x5c8;                   // 0x5c8
    float x5cc;                   // 0x5cc
    float x5d0;                   // 0x5d0
    float x5d4;                   // 0x5d4
    float x5d8;                   // 0x5d8
    float x5dc;                   // 0x5dc
    float x5e0;                   // 0x5e0
    float x5e4;                   // 0x5e4
    float x5e8;                   // 0x5e8
    float x5ec;                   // 0x5ec
    float x5f0;                   // 0x5f0
    float x5f4;                   // 0x5f4
    float x5f8;                   // 0x5f8
    float x5fc;                   // 0x5fc
    float x600;                   // 0x600
    float x604;                   // 0x604
    float x608;                   // 0x608
    float x60c;                   // 0x60c
    float x610;                   // 0x610
    float x614;                   // 0x614
    float x618;                   // 0x618
    float x61c;                   // 0x61c
    float x620;                   // 0x620
    float x624;                   // 0x624
    float x628;                   // 0x628
    float x62c;                   // 0x62c
    float x630;                   // 0x630
    float x634;                   // 0x634
    float x638;                   // 0x638
    float x63c;                   // 0x63c
    float x640;                   // 0x640
    float x644;                   // 0x644
    float x648;                   // 0x648
    float x64c;                   // 0x64c
    float x650;                   // 0x650
    float x654;                   // 0x654
    float x658;                   // 0x658
    float x65c;                   // 0x65c
    float x660;                   // 0x660
    float x664;                   // 0x664
    float x668;                   // 0x668
    float x66c;                   // 0x66c
    float x670;                   // 0x670
    float x674;                   // 0x674
    float x678;                   // 0x678
    float x67c;                   // 0x67c
    float x680;                   // 0x680
    float x684;                   // 0x684
    float x688;                   // 0x688
    float x68c;                   // 0x68c
    float x690;                   // 0x690
    float x694;                   // 0x694
    float x698;                   // 0x698
    float x69c;                   // 0x69c
    float x6a0;                   // 0x6a0
    float x6a4;                   // 0x6a4
    float x6a8;                   // 0x6a8
    float x6ac;                   // 0x6ac
    float x6b0;                   // 0x6b0
    float x6b4;                   // 0x6b4
    float x6b8;                   // 0x6b8
    float x6bc;                   // 0x6bc
    float x6c0;                   // 0x6c0
    float x6c4;                   // 0x6c4
    float x6c8;                   // 0x6c8
    float x6cc;                   // 0x6cc
    float x6d0;                   // 0x6d0
    float x6d4;                   // 0x6d4
    float x6d8;                   // 0x6d8
    float x6dc;                   // 0x6dc
    float x6e0;                   // 0x6e0
    float x6e4;                   // 0x6e4
    float x6e8;                   // 0x6e8
    float x6ec;                   // 0x6ec
    float x6f0;                   // 0x6f0
    float x6f4;                   // 0x6f4
    float x6f8;                   // 0x6f8
    float x6fc;                   // 0x6fc
    float x700;                   // 0x700
    float x704;                   // 0x704
    float x708;                   // 0x708
    float x70c;                   // 0x70c
    float x710;                   // 0x710
    float x714;                   // 0x714
    float x718;                   // 0x718
    float x71c;                   // 0x71c
    float x720;                   // 0x720
    float x724;                   // 0x724
    float x728;                   // 0x728
    float x72c;                   // 0x72c
    float x730;                   // 0x730
    float x734;                   // 0x734
    float x738;                   // 0x738
    float x73c;                   // 0x73c
    float x740;                   // 0x740
    float x744;                   // 0x744
    float x748;                   // 0x748
    float x74c;                   // 0x74c
    float x750;                   // 0x750
    float x754;                   // 0x754
    float x758;                   // 0x758
    float x75c;                   // 0x75c
    float x760;                   // 0x760
    float x764;                   // 0x764
    float x768;                   // 0x768
    float x76c;                   // 0x76c
    float x770;                   // 0x770
    float x774;                   // 0x774
    float x778;                   // 0x778
    float x77c;                   // 0x77c
    float x780;                   // 0x780
    float x784;                   // 0x784
    float x788;                   // 0x788
    float x78c;                   // 0x78c
    float x790;                   // 0x790
    float x794;                   // 0x794
    float x798;                   // 0x798
    float x79c;                   // 0x79c
    float x7a0;                   // 0x7a0
    float x7a4;                   // 0x7a4
    float x7a8;                   // 0x7a8
    float x7ac;                   // 0x7ac
    float x7b0;                   // 0x7b0
    float x7b4;                   // 0x7b4
    float x7b8;                   // 0x7b8
    float x7bc;                   // 0x7bc
    float x7c0;                   // 0x7c0
    float x7c4;                   // 0x7c4
    float x7c8;                   // 0x7c8
    float x7cc;                   // 0x7cc
    float x7d0;                   // 0x7d0
    float x7d4;                   // 0x7d4
    float x7d8;                   // 0x7d8
    float x7dc;                   // 0x7dc
    float x7e0;                   // 0x7e0
    float x7e4;                   // 0x7e4
    float x7e8;                   // 0x7e8
    float x7ec;                   // 0x7ec
    float x7f0;                   // 0x7f0
    float x7f4;                   // 0x7f4
    float x7f8;                   // 0x7f8
    float x7fc;                   // 0x7fc
    float x800;                   // 0x800
    float x804;                   // 0x804
    float x808;                   // 0x808
    float x80c;                   // 0x80c
    float x810;                   // 0x810
};

struct FighterData
{
    GOBJ *fighter;                                             // 0x0
    int kind;                                                  // 0x4
    int spawn_num;                                             // 0x8
    char ply;                                                  // 0xC
    char xd;                                                   // 0xD
    char xe;                                                   // 0xE
    char xf;                                                   // 0xF
    int state_id;                                              // 0x10
    int anim_id;                                               // 0x14
    int state_num;                                             // 0x18
    MoveLogic *common_states;                                  // 0x1C
    MoveLogic *special_states;                                 // 0x20
    int *anim_flags;                                           // 0x24
    u16 *dynamics_data;                                        // 0x28
    float facing_direction;                                    // 0x2C
    float facing_direction_repeated;                           // 0x30
    Vec3 scale;                                                // 0x34
    int pointer_to_next_linked_list;                           // 0x40
    int pointer_to_0x40__pointer_to_prev_linked_list;          // 0x44
    int length_of_linked_list;                                 // 0x48
    int x4c;                                                   // 0x4C
    int x50;                                                   // 0x50
    int x54;                                                   // 0x54
    int x58;                                                   // 0x58
    int x5C;                                                   // 0x5C
    int x60;                                                   // 0x60
    int x64;                                                   // 0x64
    int x68;                                                   // 0x68
    int x6C;                                                   // 0x6C
    int x70;                                                   // 0x70
    struct phys                                                // 0x74
    {                                                          //
        Vec3 anim_vel;                                         // 0x74
        Vec3 self_vel;                                         // 0x80
        Vec3 kb_vel;                                           // 0x8C
        int x98;                                               // 0x98
        int x9c;                                               // 0x9C
        int xa0;                                               // 0xA0
        int xa4;                                               // 0xA4
        int xa8;                                               // 0xA8
        int xac;                                               // 0xAC
        Vec3 pos;                                              // 0xb0
        Vec3 pos_prev;                                         // 0xBC
        Vec3 pos_delta;                                        // 0xC8
        Vec3 xD4;                                              // 0xD4
        int air_state;                                         // 0xE0
        float horzitonal_velocity_queue_will_be_added_to_0xec; // 0xE4
        float vertical_velocity_queue_will_be_added_to_0xec;   // 0xE8
        Vec3 self_vel_ground;                                  // 0xEC
        int xF8;                                               // 0xF8
        int xFC;                                               // 0xFC
        int x100;                                              // 0x100
    } phys;                                                    //
    int *costume_JObjDesc;                                     // 0x104
    int *costume_archive;                                      // 0x108
    ftData *ftData;                                            // 0x10C
    struct attr                                                // 0x110
    {                                                          //
        float walk_initial_velocity;                           // 0x110
        float walk_acceleration;                               // 0x114
        float walk_maximum_velocity;                           // 0x118
        float slow_walk_max;                                   // 0x11C
        float mid_walk_point;                                  // 0x120
        float fast_walk_min;                                   // 0x124
        float ground_friction;                                 // 0x128
        float dash_initial_velocity;                           // 0x12C
        float dashrun_acceleration_a;                          // 0x130
        float dashrun_acceleration_b;                          // 0x134
        float dashrun_terminal_velocity;                       // 0x138
        float run_animation_scaling;                           // 0x13C
        float max_runbrake_frames;                             // 0x140
        float grounded_max_horizontal_velocity;                // 0x144
        float jump_startup_time;                               // 0x148
        float jump_h_initial_velocity;                         // 0x14C
        float jump_v_initial_velocity;                         // 0x150
        float ground_to_air_jump_momentum_multiplier;          // 0x154
        float jump_h_max_velocity;                             // 0x158
        float hop_v_initial_velocity;                          // 0x15C
        float air_jump_v_multiplier;                           // 0x160
        float air_jump_h_multiplier;                           // 0x164
        int max_jumps;                                         // 0x168
        float gravity;                                         // 0x16C
        float terminal_velocity;                               // 0x170
        float aerial_drift_stick_mult;                         // 0x174
        float aerial_drift_base;                               // 0x178
        float aerial_drift_max;                                // 0x17C
        float aerial_friction;                                 // 0x180
        float fastfall_velocity;                               // 0x184
        float horizontal_air_mobility_constant;                // 0x188
        int jab_2_input_window;                                // 0x18C
        int jab_3_input_window;                                // 0x190
        int frames_to_change_direction_on_standing_turn;       // 0x194
        float weight;                                          // 0x198
        float model_scaling;                                   // 0x19C
        float initial_shield_size;                             // 0x1A0
        float shield_break_initial_velocity;                   // 0x1A4
        int rapid_jab_window;                                  // 0x1A8
        int x1AC;                                              // 0x1AC
        int x1B0;                                              // 0x1B0
        int x1B4;                                              // 0x1B4
        float ledge_jump_horizontal_velocity;                  // 0x1B8
        float ledge_jump_vertical_velocity;                    // 0x1BC
        float item_throw_velocity_multiplier;                  // 0x1C0
        int x1C4;                                              // 0x1C4
        int x1C8;                                              // 0x1C8
        int x1CC;                                              // 0x1CC
        int x1D0;                                              // 0x1D0
        int x1D4;                                              // 0x1D4
        int x1D8;                                              // 0x1D8
        int x1DC;                                              // 0x1DC
        int x1E0;                                              // 0x1E0
        int x1E4;                                              // 0x1E4
        int x1E8;                                              // 0x1E8
        int x1EC;                                              // 0x1EC
        float kirby_b_star_damage;                             // 0x1F0
        float normal_landing_lag;                              // 0x1F4
        float n_air_landing_lag;                               // 0x1F8
        float f_air_landing_lag;                               // 0x1FC
        float b_air_landing_lag;                               // 0x200
        float u_air_landing_lag;                               // 0x204
        float d_air_landing_lag;                               // 0x208
        float nametag_height;                                  // 0x20C
        int x210;                                              // 0x210
        float wall_jump_horizontal_velocity;                   // 0x214
        float wall_jump_vertical_velocity;                     // 0x218
        int x21C;                                              // 0x21C
        float trophy_scale;                                    // 0x220
        int x224;                                              // 0x224
        int x228;                                              // 0x228
        int x22C;                                              // 0x22C
        int x230;                                              // 0x230
        int x234;                                              // 0x234
        int x238;                                              // 0x238
        int x23C;                                              // 0x23C
        int x240;                                              // 0x240
        int x244;                                              // 0x244
        int x248;                                              // 0x248
        int x24C;                                              // 0x24C
        int x250;                                              // 0x250
        int x254;                                              // 0x254
        int x258;                                              // 0x258
        float bubble_ratio;                                    // 0x25C
        int x260;                                              // 0x260
        int x264;                                              // 0x264
        int x268;                                              // 0x268
        int x26C;                                              // 0x26C
        float respawn_platform_scale;                          // 0x270
        int x274;                                              // 0x274
        int x278;                                              // 0x278
        int camera_zoom_target_bone;                           // 0x27C
        int x280;                                              // 0x280
        int x284;                                              // 0x284
        int x288;                                              // 0x288
        int special_jump_action___1;                           // 0x28C
        int weight_dependent_throw_speed_flags;                // 0x290
    } attr;                                                    //
    int x294;                                                  // 0x294
    int x298;                                                  // 0x298
    int x29C;                                                  // 0x29C
    int x2A0;                                                  // 0x2A0
    int x2A4;                                                  // 0x2A4
    int x2A8;                                                  // 0x2A8
    int x2AC;                                                  // 0x2AC
    int x2B0;                                                  // 0x2B0
    int x2B4;                                                  // 0x2B4
    int x2B8;                                                  // 0x2B8
    int x2BC;                                                  // 0x2BC
    int x2C0;                                                  // 0x2C0
    int x2C4;                                                  // 0x2C4
    int x2C8;                                                  // 0x2C8
    int x2CC;                                                  // 0x2CC
    int x2D0;                                                  // 0x2D0
    int *special_attributes;                                   // 0x2D4
    int *special_attributes2;                                  // 0x2D8
    int x2DC;                                                  // 0x2DC
    int x2E0;                                                  // 0x2E0
    int x2E4;                                                  // 0x2E4
    int x2E8;                                                  // 0x2E8
    int x2EC;                                                  // 0x2EC
    FtDynamicBoneset dynamics_boneset[10];                     // 0x2f0
    int dynamics_num;                                          // 0x3E0
    struct script                                              //  0x3E4
    {                                                          //
        float script_event_timer;                              // 0x3E4
        float script_frame_timer;                              // 0x3E8
        int *script_current;                                   // 0x3EC
        int script_loop_num;                                   // 0x3F0
        int *script_return;                                    // 0x3F4
    } script;                                                  //
    int unk;                                                   // 0x3F8
    int unk3FC;                                                // 0x3FC
    int pointer_to_0x460;                                      // 0x400
    int pointer_to_0x3c0;                                      // 0x404
    ColorOverlay color[3];                                     // 0x408
    int *LObj;                                                 // 0x588
    int anim_num;                                              // 0x58C
    int *anim_curr_flags_ptr;                                  // 0x590
    int anim_curr_flags;                                       // 0x594
    int *anim_requested;                                       // 0x598
    int *anim_cache_curr;                                      // 0x59C
    int *anim_cache_persist;                                   // 0x5A0
    int *anim_curr_ARAM;                                       // 0x5A4
    int *anim_persist_ARAM;                                    // 0x5A8
    int dobj_toggle_num;                                       // 0x5AC
    int x5B0;                                                  // 0x5B0
    int x5B4;                                                  // 0x5B4
    int x5B8;                                                  // 0x5B8
    int x5BC;                                                  // 0x5BC
    int x5C0;                                                  // 0x5C0
    int x5C4;                                                  // 0x5C4
    int x5C8;                                                  // 0x5C8
    int x5CC;                                                  // 0x5CC
    int x5D0;                                                  // 0x5D0
    int x5D4;                                                  // 0x5D4
    int x5D8;                                                  // 0x5D8
    int x5DC;                                                  // 0x5DC
    int x5E0;                                                  // 0x5E0
    int x5E4;                                                  // 0x5E4
    FighterBone *bones;                                        // 0x5E8
    int bone_num;                                              // 0x5EC
    int bone_arr;                                              // 0x5F0
    u16 dobj_toggle[12];                                       // 0x5f4
    Effect *gfx;                                               // 0x60C
    int x610;                                                  // 0x610
    int x614;                                                  // 0x614
    char player_controller_number;                             // 0x618
    char costume_id;                                           // 0x619
    char color_overlay_id;                                     // 0x61A
    u8 team;                                                   // 0x61B
    char x61e;                                                 // 0x61E
    char x61F;                                                 // 0x61F
    struct input                                               // input data
    {                                                          //
        float lstick_x;                                        // 0x620
        float lstick_y;                                        // 0x624
        float lstick_prev_x;                                   // 0x628
        float lstick_prev_y;                                   // 0x62C
        int x630;                                              // 0x630
        int x634;                                              // 0x634
        float cstick_x;                                        // 0x638
        float cstick_y;                                        // 0x63C
        int x640;                                              // 0x640
        int x644;                                              // 0x644
        int x648;                                              // 0x648
        int x64C;                                              // 0x64C
        float trigger;                                         // 0x650
        int x654;                                              // 0x654
        int x658;                                              // 0x658
        int held;                                              // 0x65C
        int held_prev;                                         // 0x660
        int x664;                                              // 0x664
        int down;                                              // 0x668
        int x66C;                                              // 0x66C
        char timer_lstick_tilt_x;                              // 0x670
        char timer_lstick_tilt_y;                              // 0x671
        char timer_trigger_analog;                             // 0x672
        char timer_lstick_smash_x;                             // 0x673
        char timer_lstick_smash_y;                             // 0x674
        char timer_trigger_digital;                            // 0x675
        char timer_lstick_any_x;                               // 0x676
        char timer_lstick_any_y;                               // 0x677
        char timer_trigger_any;                                // 0x678
        char x679;                                             // 0x679
        char x67A;                                             // 0x67A
        char x67B;                                             // 0x67B
        char timer_a;                                          // 0x67C
        char timer_b;                                          // 0x67D
        char timer_xy;                                         // 0x67E
        char timer_trigger_any_ignore_hitlag;                  // 0x67F
        char timer_LR;                                         // 0x680
        char timer_padup;                                      // 0x681
        char timer_paddown;                                    // 0x682
        char timer_item_release;                               // 0x683
        char since_rapid_lr;                                   // 0x684
        char timer_unk2;                                       // 0x685
        char timer_unk3;                                       // 0x686
        char timer_unk4;                                       // 0x687
        char timer_sideb;                                      // 0x688
        char timer_neutralb;                                   // 0x689
        char timer_unk5;                                       // 0x68A
        char timer_unk6;                                       // 0x68B
    } input;                                                   //
    Vec3 transN_pos;                                           // x68c
    Vec3 transN_pos_prev;                                      // 0x698
    Vec3 transN_offset;                                        // 0x6A4
    Vec3 transN_offset_prev;                                   // 0x6B0
    float input_stickangle;                                    // 0x6BC
    int x6C0;                                                  // 0x6C0
    int x6C4;                                                  // 0x6C4
    int x6C8;                                                  // 0x6C8
    int x6CC;                                                  // 0x6CC
    int x6D0;                                                  // 0x6D0
    int x6D4;                                                  // 0x6D4
    int x6D8;                                                  // 0x6D8
    int x6DC;                                                  // 0x6DC
    int x6E0;                                                  // 0x6E0
    int x6E4;                                                  // 0x6E4
    int x6E8;                                                  // 0x6E8
    int x6EC;                                                  // 0x6EC
    CollData coll_data;                                        // 0x6F0 -> 0x88C
    CameraBox *cameraBox;                                      // 0x890
    struct state
    {
        float frame; // 0x894, current frame of the animation
        int x898;    // 0x898
        float rate;  // 0x89C, current speed rate of the animation
        int x8a0;    // 0x8a0
        float blend; // 0x8a4, current interpolation value of the animation
        int x8a8;    // 0x8a8
    } state;
    JOBJ *anim_skeleton;           // 0x8ac
    int x8b0;                      // 0x8b0
    int x8b4;                      // 0x8b4
    int x8b8;                      // 0x8b8
    int x8bc;                      // 0x8bc
    int x8c0;                      // 0x8c0
    int x8c4;                      // 0x8c4
    int x8c8;                      // 0x8c8
    int x8cc;                      // 0x8cc
    int x8d0;                      // 0x8d0
    int x8d4;                      // 0x8d4
    int x8d8;                      // 0x8d8
    int x8dc;                      // 0x8dc
    int x8e0;                      // 0x8e0
    int x8e4;                      // 0x8e4
    int x8e8;                      // 0x8e8
    int x8ec;                      // 0x8ec
    int x8f0;                      // 0x8f0
    int x8f4;                      // 0x8f4
    int x8f8;                      // 0x8f8
    int x8fc;                      // 0x8fc
    int x900;                      // 0x900
    int x904;                      // 0x904
    int x908;                      // 0x908
    int x90c;                      // 0x90c
    int x910;                      // 0x910
    ftHit hitbox[4];               // 0x914
    ftHit throw_hitbox[2];         // 0xdf4
    ftHit unk_hitbox;              // 0x1064
    u8 team_unk;                   // 0x119c, friendly fire related
    u8 grabber_ply;                // 0x119D, slot ID of the person grabbing this fighter
    u8 hurt_num;                   // 0x119E, number of hurtboxes
    FtHurt hurtbox[15];            // 0x11A0
    int x1614;                     // 0x1614
    int x1618;                     // 0x1618
    int x161c;                     // 0x161c
    int x1620;                     // 0x1620
    int x1624;                     // 0x1624
    int x1628;                     // 0x1628
    int x162c;                     // 0x162c
    int x1630;                     // 0x1630
    int x1634;                     // 0x1634
    int x1638;                     // 0x1638
    int x163c;                     // 0x163c
    int x1640;                     // 0x1640
    int x1644;                     // 0x1644
    int x1648;                     // 0x1648
    int x164c;                     // 0x164c
    int x1650;                     // 0x1650
    int x1654;                     // 0x1654
    int x1658;                     // 0x1658
    int x165c;                     // 0x165c
    int x1660;                     // 0x1660
    int x1664;                     // 0x1664
    int x1668;                     // 0x1668
    int dynamics_hit_num;          // 0x166c
    FtDynamicHit dynamics_hit[11]; // 0x1670
    int x1828;                     // 0x1828
    struct dmg                     // 0x182c
    {                              //
        int behavior;              // 0x182c
        float percent;             // 0x1830
        int x1834;                 // 0x1834
        float percent_temp;        // 0x1838
        float applied;             // 0x183c
        int x1840;                 // 0x1840
        float direction;           // 0x1844
        int kb_angle;              // 0x1848
        int damaged_hurtbox;       // 0x184c
        float force_applied;       // 0x1850
        Vec3 collpos;              // 0x1854
        int dealt;                 // 0x1860
        int x1864;                 // 0x1864
        GOBJ *source;              // 0x1868
        int x186c;                 // 0x186c
        int x1870;                 // 0x1870
        int x1874;                 // 0x1874
        int x1878;                 // 0x1878
        int x187c;                 // 0x187c
        int x1880;                 // 0x1880
        int x1884;                 // 0x1884
        int x1888;                 // 0x1888
        int x188c;                 // 0x188c
        int x1890;                 // 0x1890
        int x1894;                 // 0x1894
        int x1898;                 // 0x1898
        int x189c;                 // 0x189c
        int x18a0;                 // 0x18a0
        float kb_mag;              // 0x18a4  kb magnitude
        int x18a8;                 // 0x18a8
        int time_since_hit;        // 0x18ac   in frames
        int x18b0;                 // 0x18b0
        float armor;               // 0x18b4
        int x18b8;                 // 0x18b8
        int x18bc;                 // 0x18bc
        int x18c0;                 // 0x18c0
        int source_ply;            // 0x18c4   damage source ply number
        int x18c8;                 // 0x18c8
        int x18cc;                 // 0x18cc
        int x18d0;                 // 0x18d0
        int x18d4;                 // 0x18d4
        int x18d8;                 // 0x18d8
        int x18dc;                 // 0x18dc
        int x18e0;                 // 0x18e0
        int x18e4;                 // 0x18e4
        int x18e8;                 // 0x18e8
        u16 atk_instance_hurtby;   // 0x18ec. Last Attack Instance This Player Was Hit by,
        int x18f0;                 // 0x18f0
        int x18f4;                 // 0x18f4
        u8 x18f8;                  // 0x18f8
        u8 x18f9;                  // 0x18f8
        u16 model_shift_frames;    // 0x18f8
        u8 x18fc;                  // 0x18fc
        u8 x18fd;                  // 0x18fd
        int x1900;                 // 0x1900
        int x1904;                 // 0x1904
        int x1908;                 // 0x1908
        int x190c;                 // 0x190c
        int x1910;                 // 0x1910
        int x1914;                 // 0x1914
        int x1918;                 // 0x1918
        int x191c;                 // 0x191c
        int x1920;                 // 0x1920
        int x1924;                 // 0x1924
        int x1928;                 // 0x1928
        int x192c;                 // 0x192c
        int x1930;                 // 0x1930
        int x1934;                 // 0x1934
        int x1938;                 // 0x1938
        int x193c;                 // 0x193c
        int x1940;                 // 0x1940
        int x1944;                 // 0x1944
        int x1948;                 // 0x1948
        int x194c;                 // 0x194c
        int x1950;                 // 0x1950
        int x1954;                 // 0x1954
        int x1958;                 // 0x1958
        float hitlag_frames;       // 0x195c
    } dmg;                         //
    int x1960;                     // 0x1960
    float x1964;                   // 0x1964
    struct jump                    // 0x1968
    {                              //
        char jumps_used;           // 0x1968
        char walljumps_used;       // 0x1969
    } jump;                        //
    int x196c;                     // 0x196c
    int x1970;                     // 0x1970
    GOBJ *item_held;               // 0x1974
    GOBJ *x1978;                   // 0x1978
    int x197c;                     // 0x197c
    GOBJ *item_head;               // 0x1980
    GOBJ *item_held_spec;          // 0x1984, special held item
    struct hurtstatus              // 0x1988
    {                              //
        int script;                // 0x1988
        int game;                  // 0x198c
        int ledge_intang_left;     // 0x1990
        int respawn_intang_left;   // 0x1994
    } hurtstatus;                  //
    struct shield
    {
        float health;          // 0x1998
        float lightshield_amt; // 0x199c
        int dmg_taken;         // 0x19a0, seems to be all damage taken during the frame, is reset at the end of the frame
        int dmg_taken2;        // 0x19a4, idk there so many of these
        GOBJ *dmg_source;      // 0x19a8, points to the entity that hit the shield
        float hit_direction;   // 0x19ac
        int hit_attr;          // 0x19b0, attribute of the hitbox that collided
        float x19b4;           // 0x19b4
        float x19b8;           // 0x19b8
        int dmg_taken3;        // 0x19bc, seems to be the most recent amount of damage taken
    } shield;
    struct shield_update // 0x19c0
    {
        JOBJ *bone;                   // 0x19c0
        unsigned char is_checked : 1; // 0x19d0 0x80. is checked for collision when 0
        Vec3 pos;                     // 19d4
        Vec3 offset;                  // 0x19d4
        float size_mult;              // 0x19e0
    } shield_bubble;
    struct reflect_update // 0x19e4
    {
        JOBJ *bone;                   // 0x19e4
        unsigned char is_checked : 1; // 0x19d0 0x80. is checked for collision when 0
        Vec3 pos;                     // 0x19d4
        Vec3 offset;                  // 0x19f8
        float size_mult;              // 0x1a04
    } reflect_bubble;
    struct absorb_update // 0x1a08
    {
        JOBJ *bone;                   // 0x1a08
        unsigned char is_checked : 1; // 0x1a0c 0x80. is checked for collision when 0
        Vec3 pos;                     // 0x1a10
        Vec3 offset;                  // 0x1a1c
        float size_mult;              // 0x1a28
    } absorb_bubble;
    struct reflect_hit                        // 0x1a2c
    {                                         //
        float hit_direction;                  // 0x1a2c
        int max_dmg;                          // 0x1a30
        float dmg_mult;                       // 0x1a34
        int is_break;                         // 0x1a38
    } reflect_hit;                            //
    struct absorb_hit                         // 0x1a40
    {                                         //
        int x1a3c;                            // 0x1a3c
        float hit_direction;                  // 0x1a40
        int dmg_taken;                        // 0x1a44
        int hits_taken;                       // 0x1a48
    } absorb_hit;                             //
    struct grab                               // 0x1a4c
    {                                         //
        float grab_timer;                     // 0x1a4c
        int x1a50;                            // 0x1a50
        int x1a54;                            // 0x1a54
        GOBJ *attacker;                       // 0x1a58
        GOBJ *victim;                         // 0x1a5c
        int x1a60;                            // 0x1a60
        int x1a64;                            // 0x1a64
        u16 x1a68;                            // 0x1a68
        u16 vuln;                             // 0x1a6a
        int x1a6c;                            // 0x1a6c
        int x1a70;                            // 0x1a70
        int x1a74;                            // 0x1a74
        int x1a78;                            // 0x1a78
        int x1a7c;                            // 0x1a7c
        int x1a80;                            // 0x1a80
        int x1a84;                            // 0x1a84
    } grab;                                   //
    CPU cpu;                                  // 0x1a88
    int x1fe0;                                // 0x1fe0
    int x1fe4;                                // 0x1fe4
    int x1fe8;                                // 0x1fe8
    int x1fec;                                // 0x1fec
    int x1ff0;                                // 0x1ff0
    int x1ff4;                                // 0x1ff4
    int x1ff8;                                // 0x1ff8
    int x1ffc;                                // 0x1ffc
    int x2000;                                // 0x2000
    int x2004;                                // 0x2004
    int x2008;                                // 0x2008
    int x200c;                                // 0x200c
    int x2010;                                // 0x2010
    int x2014;                                // 0x2014
    int x2018;                                // 0x2018
    int x201c;                                // 0x201c
    int x2020;                                // 0x2020
    int x2024;                                // 0x2024
    int x2028;                                // 0x2028
    int x202c;                                // 0x202c
    int x2030;                                // 0x2030
    int x2034;                                // 0x2034
    int x2038;                                // 0x2038
    int x203c;                                // 0x203c
    int x2040;                                // 0x2040
    int x2044;                                // 0x2044
    int x2048;                                // 0x2048
    int x204c;                                // 0x204c
    int x2050;                                // 0x2050
    int x2054;                                // 0x2054
    int x2058;                                // 0x2058
    int x205c;                                // 0x205c
    int x2060;                                // 0x2060
    int ledge_cooldown;                       // 0x2064
    int attack_kind;                          // 0x2068, non attacks have id 1
    int x206c;                                // 0x206c
    u8 x2070;                                 // 0x2070
    u8 x2071;                                 // 0x2071
    u8 x2072;                                 // 0x2072
    u8 x2073;                                 // 0x2073
    int x2074;                                // 0x2074
    int x2078;                                // 0x2078
    int x207c;                                // 0x207c
    int x2080;                                // 0x2080
    int x2084;                                // 0x2084
    u16 atk_instance;                         // 0x2088, Contains an ID unique to the current move instance. e.g, if two dairs are done back to back, this ID will differ to tell them apart from each other. It is stored to 0x18EC of the victim upon colliding with someone.
    int x208c;                                // 0x208c
    int x2090;                                // 0x2090
    int x2094;                                // 0x2094
    int x2098;                                // 0x2098
    int x209c;                                // 0x209c
    JOBJ *accessory;                          // 0x20a0
    int x20a4;                                // 0x20a4
    void *shadow;                             // 0x20a8, ASSERTS @ 8037f7b8, describes multiple struct members
    int x20ac;                                // 0x20ac
    struct afterimage                         //
    {                                         //
        struct FtAfterImageKey afterimage[3]; // 0x20b0
        float afterimage_bottom;              // 0x20f8
        float afterimage_top;                 // 0x20fc
        u8 afterimage_state;                  // 0x2100
        unsigned char afterimage_num : 7;     // 0x2101
    } afterimage;                             //
    int x2104;                                // 0x2104
    int x2108;                                // 0x2108
    int x210c;                                // 0x210c
    int x2110;                                // 0x2110
    struct smash                              // 0x2114
    {                                         //
        int state;                            // 0x2114 0 = none, 1 = pre-charge, 2 = charging, 3 = release
        int frame;                            // 0x2118 number of frames fighter has charged for
        float hold_frame;                     // 0x211c frame that charge begins/ends
        float dmg_mult;                       // 0x2120 damage multiplier
        float speed_mult;                     // 0x2124 speed multiplier?
        int x2128;                            // 0x2128
        int x212c;                            // 0x212c
        int is_sfx_played;                    // 0x2130 bool for smash sfx?
        u8 vibrate_frame;                     // 0x2134
        u8 x22135;                            // 0x2135
        float since_hitbox;                   // 0x2138
    } smash;                                  //
    int x213c;                                // 0x213c
    int x2140;                                // 0x2140
    int x2144;                                // 0x2144
    int x2148;                                // 0x2148
    int x214c;                                // 0x214c
    int x2150;                                // 0x2150
    int x2154;                                // 0x2154
    int x2158;                                // 0x2158
    int x215c;                                // 0x215c
    int x2160;                                // 0x2160
    int x2164;                                // 0x2164
    int x2168;                                // 0x2168
    int x216c;                                // 0x216c
    int x2170;                                // 0x2170
    int x2174;                                // 0x2174
    int x2178;                                // 0x2178
    int x217c;                                // 0x217c
    int x2180;                                // 0x2180
    int x2184;                                // 0x2184
    int x2188;                                // 0x2188
    int x218c;                                // 0x218c
    struct cb
    {
        void (*OnGrabFighter_Self)(GOBJ *fighter);   // 0x2190
        void (*x2194)(GOBJ *fighter);                // 0x2194
        void (*OnGrabFighter_Victim)(GOBJ *fighter); // 0x2198
        void (*IASA)(GOBJ *fighter);                 // 0x219C
        void (*Anim)(GOBJ *fighter);                 // 0x21A0
        void (*Phys)(GOBJ *fighter);                 // 0x21a4
        void (*Coll)(GOBJ *fighter);                 // 0x21a8
        void (*Cam)(GOBJ *fighter);                  // 0x21ac
        void (*Accessory1)(GOBJ *fighter);           // 0x21b0
        void (*Accessory2)(GOBJ *fighter);           // 0x21b4
        void (*Accessory3)(GOBJ *fighter);           // 0x21b8
        void (*Accessory4)(GOBJ *fighter);           // 0x21bc
        void (*OnGiveDamage)(GOBJ *fighter);         // 0x21c0
        void (*OnShieldHit)(GOBJ *fighter);          // 0x21c4
        void (*OnReflectHit)(GOBJ *fighter);         // 0x21c8
        void (*x21cc)(GOBJ *fighter);                // 0x21cc
        void (*EveryHitlag)(GOBJ *fighter);          // 0x21d0
        void (*EnterHitlag)(GOBJ *fighter);          // 0x21d4
        void (*ExitHitlag)(GOBJ *fighter);           // 0x21d8
        void (*OnTakeDamage)(GOBJ *fighter);         // 0x21dc
        void (*OnDeath)(GOBJ *fighter);              // 0x21e0
        void (*OnDeath2)(GOBJ *fighter);             // 0x21e4, internally Dead_Proc as evidenced by 800f5430
        void (*OnDeath3)(GOBJ *fighter);             // 0x21e8
        void (*OnActionStateChange)(GOBJ *fighter);  // 0x21ec
        void (*OnTakeDamage2)(GOBJ *fighter);        // 0x21f0
        void (*OnHurtboxDetect)(GOBJ *fighter);      // 0x21f4
        void (*OnSpin)(GOBJ *fighter);               // 0x21f8
    } cb;
    unsigned char x21fc_1 : 1;                   // 0x80 - x21fc_
    unsigned char show_center_sphere : 1;        // 0x40 - x21fc_
    unsigned char show_item_pickup : 1;          // 0x20 - x21fc_
    unsigned char show_cpu_ai : 1;               // 0x10 - x21fc_
    unsigned char show_footstool : 1;            // 0x8 - x21fc_
    unsigned char show_dynamics : 1;             // 0x4 - x21fc_
    unsigned char show_hit : 1;                  // 0x2 - x21fc_
    unsigned char show_model : 1;                // 0x1 - x21fc_
    struct ftcmd_var                             // 0x2200
    {                                            //
        int flag0;                               // 0x2200
        int flag1;                               // 0x2204
        int flag2;                               // 0x2208
        int flag3;                               // 0x220C
    } ftcmd_var;                                 //
    struct flags                                 // 0x2210
    {                                            //
        unsigned char throw_1 : 1;               // 0x80 - x2210
        unsigned char throw_2 : 1;               // 0x40 - x2210
        unsigned char throw_3 : 1;               // 0x20 - x2210
        unsigned char throw_release : 1;         // 0x10 - x2210. also used to change users direction during aerial attacks
        unsigned char throw_turn : 1;            // 0x8 - x2210
        unsigned char throw_6 : 1;               // 0x4 - x2210
        unsigned char throw_7 : 1;               // 0x2 - x2210
        unsigned char throw_8 : 1;               // 0x1 - x2210
        float throw_timerval;                    // equal to script_event_timer of the attacker
        unsigned char x2218_1 : 1;               // 0x80 - x2218
        unsigned char x2218_2 : 1;               // 0x40 - x2218
        unsigned char x2218_3 : 1;               // 0x20 - x2218
        unsigned char reflect_enable : 1;        // 0x10 - x2218
        unsigned char reflect_nochangeowner : 1; // 0x8 - x2218
        unsigned char x2218_6 : 1;               // 0x4 - x2218
        unsigned char absorb_enable : 1;         // 0x2 - x2218
        unsigned char absorb_unk : 1;            // 0x1 - x2218
        unsigned char persistent_gfx : 1;        // is shielding bool. 0x80 - 0x2219
        unsigned char immune : 1;                // 0x40 - 0x2219
        unsigned char x2219_3 : 1;               // 0x20 - 0x2219
        unsigned char hitbox_active : 1;         // 0x10 - 0x2219
        unsigned char x2219_5 : 1;               // 0x8 - 0x2219
        unsigned char freeze : 1;                // 0x4 - 0x2219
        unsigned char hitlag_unk : 1;            // 0x2 - 0x2219
        unsigned char hitlag_unk2 : 1;           // 0x1 - 0x2219
        unsigned char x221a_1 : 1;               // 0x80 - 0x221a
        unsigned char x221a_2 : 1;               // 0x40 - 0x221a
        unsigned char hitlag : 1;                // 0x20 - 0x221a
        unsigned char x221a_4 : 1;               // 0x10 - 0x221a
        unsigned char is_fastfall : 1;           // 0x8 - 0x221a
        unsigned char no_hurt_script : 1;        // 0x4 - 0x221a
        unsigned char x221a_7 : 1;               // 0x2 - 0x221a
        unsigned char gfx_persist : 1;           // 0x1 - 0x221a
        unsigned char shield_enable : 1;         // 0x80 - 0x221b
        unsigned char shield_x40 : 1;            // 0x40 - 0x221b
        unsigned char shield_x20 : 1;            // 0x20 - 0x221b
        unsigned char shield_x10 : 1;            // 0x10 - 0x221b
        unsigned char shield_x8 : 1;             //  0x8 - 0x221b
        unsigned char x221b_6 : 1;               // 0x4 - 0x221b
        unsigned char x221b_7 : 1;               // 0x2 - 0x221b
        unsigned char x221b_8 : 1;               // 0x1 - 0x221b
        unsigned char x221c_1 : 1;               // 0x80 - 0x221c
        unsigned char x221c_2 : 1;               // 0x40 - 0x221c
        unsigned char x221c_3 : 1;               // 0x20 - 0x221c
        unsigned char x221c_4 : 1;               // 0x10 - 0x221c
        unsigned char x221c_5 : 1;               // 0x8 - 0x221c
        unsigned char x221c_6 : 1;               // 0x4 - 0x221c
        unsigned char hitstun : 1;               // 0x2 - 0x221c
        unsigned char x221c_8 : 1;               // 0x1 = 0x221c
        unsigned char x221d_1 : 1;               // 0x80 - 0x221d
        unsigned char x221d_2 : 1;               // 0x40 - 0x221d
        unsigned char x221d_3 : 1;               // 0x20 - 0x221d
        unsigned char input_enable : 1;          // 0x10 - 0x221d
        unsigned char x221d_5 : 1;               // 0x8 - 0x221d
        unsigned char nudge_disable : 1;         // 0x4 - 0x221d
        unsigned char ground_ignore : 1;         // 0x2 - 0x221d
        unsigned char x221d_8 : 1;               // 0x1 - 0x221d
        unsigned char invisible : 1;             // 0x80 - 0x221e
        unsigned char x221e_2 : 1;               // 0x40 - 0x221e
        unsigned char x221e_3 : 1;               // 0x20 - 0x221e
        unsigned char item_visible : 1;          // 0x10 - 0x221e
        unsigned char x221e_5 : 1;               // 0x8 - 0x221e
        unsigned char x221e_6 : 1;               // 0x4 - 0x221e
        unsigned char x221e_7 : 1;               // 0x2 - 0x221e
        unsigned char x221e_8 : 1;               // 0x1 - 0x221e
        unsigned char is_offscreen : 1;          // 0x80 - 0x221f
        unsigned char dead : 1;                  // 0x40 - 0x221f
        unsigned char x221f_3 : 1;               // 0x20 - 0x221f
        unsigned char sleep : 1;                 // 0x10
        unsigned char ms : 1;                    // ms = master/slave. is 1 when the player is a slave
        unsigned char x221f_6 : 1;
        unsigned char x221f_7 : 1;
        unsigned char x221f_8 : 1;
        char flags_2220;                      // 0x2220
        char flags_2221;                      // 0x2221
        unsigned char x2222_1 : 1;            // 0x80 - 0x2222
        unsigned char is_multijump : 1;       // 0x40 - 0x2222
        unsigned char x2222_3 : 1;            // 0x20 - 0x2222
        unsigned char ceilko_nokb : 1;        // 0x10 - 0x2222, allow death off top without any Y KB
        unsigned char x2222_5 : 1;            // 0x08 - 0x2222
        unsigned char has_follower : 1;       // 0x04 - 0x2222, this makes the subcharacter enter sleep when the main char dies
        unsigned char x2222_7 : 1;            // 0x02 - 0x2222
        unsigned char x2222_8 : 1;            // 0x01 - 0x2222
        unsigned char x2223_1 : 1;            // 0x80 - 0x2223
        unsigned char x2223_2 : 1;            // 0x40 - 0x2223
        unsigned char x2223_3 : 1;            // 0x20 - 0x2223
        unsigned char x2223_4 : 1;            // 0x10 - 0x2223
        unsigned char x2223_5 : 1;            // 0x8 - 0x2223
        unsigned char x2223_6 : 1;            // 0x4 - 0x2223
        unsigned char x2223_7 : 1;            // 0x2 - 0x2223
        unsigned char x2223_8 : 1;            // 0x1 - 0x2223
        unsigned char x2224_1 : 1;            // 0x80 - 0x2224
        unsigned char x2224_2 : 1;            // 0x40 - 0x2224
        unsigned char stamina_dead : 1;       // 0x20 - 0x2224
        unsigned char x2224_4 : 1;            // 0x10 - 0x2224
        unsigned char x2224_5 : 1;            // 0x8 - 0x2224
        unsigned char x2224_6 : 1;            // 0x4 - 0x2224
        unsigned char x2224_7 : 1;            // 0x2 - 0x2224
        unsigned char x2224_8 : 1;            // 0x1 - 0x2224
        unsigned char x2225_1 : 1;            // 0x80 - 0x2225
        unsigned char x2225_2 : 1;            // 0x40 - 0x2225
        unsigned char has_model_addition : 1; // 0x20 - 0x2225  bool for if fighter has a model addition, like kirby copy ability and puff hat
        unsigned char x2225_4 : 1;            // 0x10 - 0x2225
        unsigned char x2225_5 : 1;            // 0x8 - 0x2225
        unsigned char x2225_6 : 1;            // 0x4 - 0x2225
        unsigned char x2225_7 : 1;            // 0x2 - 0x2225
        unsigned char x2225_8 : 1;            // 0x1 - 0x2225
        unsigned char x2226_1 : 1;            // 0x80 - 0x2226
        unsigned char x2226_2 : 1;            // 0x40 - 0x2226
        unsigned char is_thrown : 1;          // 0x20 - 0x2226, might actually be for skipping grab collision
        unsigned char x2226_4 : 1;            // 0x10 - 0x2226
        unsigned char cloak1 : 1;             // 0x8 - 0x2226
        unsigned char cloak2 : 1;             // 0x4 - 0x2226
        unsigned char x2226_7 : 1;            // 0x2 - 0x2226
        unsigned char x2226_8 : 1;            // 0x1 - 0x2226
        char flags_2227;                      // 0x2227
        char x2228_1 : 1;                     // 0x80 - 0x2228
        char x2228_2 : 1;                     // 0x40 - 0x2228
        char x2228_3 : 1;                     // 0x20 - 0x2228
        char x2228_4 : 1;                     // 0x10 - 0x2228
        char x2228_5 : 1;                     // 0x08 - 0x2228
        char x2228_6 : 1;                     // 0x04 - 0x2228
        char used_tether : 1;                 // 0x02 - 0x2228
        char x2228_8 : 1;                     // 0x01 - 0x2228
        unsigned char x2229_1 : 1;            // 0x80 - 0x2229
        unsigned char x2229_2 : 1;            // 0x40 - 0x2229
        unsigned char x2229_3 : 1;            // 0x20 - 0x2229
        unsigned char x2229_4 : 1;            // 0x10 - 0x2229
        unsigned char x2229_5 : 1;            // 0x8 - 0x2229
        unsigned char x2229_6 : 1;            // 0x4 - 0x2229
        unsigned char x2229_7 : 1;            // 0x2 - 0x2229
        unsigned char no_reaction_always : 1; // 0x1 - 0x2229
        char flags_222A;                      // 0x222A
        char flags_222B;                      // 0x222B
    } flags;                                  //
    struct fighter_var                        // 0x222c
    {                                         //
        int ft_var1;                          // 0x222c
        int ft_var2;                          // 0x2230
        int ft_var3;                          // 0x2234
        int ft_var4;                          // 0x2238
        int ft_var5;                          // 0x223c
        int ft_var6;                          // 0x2240
        int ft_var7;                          // 0x2244
        int ft_var8;                          // 0x2248
        int ft_var9;                          // 0x224c
        int ft_var10;                         // 0x2250
        int ft_var11;                         // 0x2254
        int ft_var12;                         // 0x2258
        int ft_var13;                         // 0x225c
        int ft_var14;                         // 0x2260
        int ft_var15;                         // 0x2264
        int ft_var16;                         // 0x2268
        int ft_var17;                         // 0x226c
        int ft_var18;                         // 0x2270
        int ft_var19;                         // 0x2274
        int ft_var20;                         // 0x2278
        int ft_var21;                         // 0x227c
        int ft_var22;                         // 0x2280
        int ft_var23;                         // 0x2284
        int ft_var24;                         // 0x2288
        int ft_var25;                         // 0x228c
        int ft_var26;                         // 0x2290
        int ft_var27;                         // 0x2294
        int ft_var28;                         // 0x2298
        int ft_var29;                         // 0x229c
        int ft_var30;                         // 0x22a0
        int ft_var31;                         // 0x22a4
        int ft_var32;                         // 0x22a8
        int ft_var33;                         // 0x22ac
        int ft_var34;                         // 0x22b0
        int ft_var35;                         // 0x22b4
        int ft_var36;                         // 0x22b8
        int ft_var37;                         // 0x22bc
        int ft_var38;                         // 0x22c0
        int ft_var39;                         // 0x22c4
        int ft_var40;                         // 0x22c8
        int ft_var41;                         // 0x22cc
        int ft_var42;                         // 0x22d0
        int ft_var43;                         // 0x22d4
        int ft_var44;                         // 0x22d8
        int ft_var45;                         // 0x22dc
        int ft_var46;                         // 0x22e0
        int ft_var47;                         // 0x22e4
        int ft_var48;                         // 0x22e8
        int ft_var49;                         // 0x22ec
        int ft_var50;                         // 0x22f0
        int ft_var51;                         // 0x22f4
        int ft_var52;                         // 0x22f8
    } fighter_var;
    int x22fc;           // 0x22fc
    int x2300;           // 0x2300
    int x2304;           // 0x2304
    int x2308;           // 0x2308
    int x230c;           // 0x230c
    int x2310;           // 0x2310
    int x2314;           // 0x2314
    int x2318;           // 0x2318
    int x231c;           // 0x231c
    int x2320;           // 0x2320
    int stage_internal;  // 0x2324 so stupid, used for decrementing hazard immunity
    int x2328;           // 0x2328
    int x232c;           // 0x232c
    int x2330;           // 0x2330
    int x2334;           // 0x2334
    int x2338;           // 0x2338
    int x233c;           // 0x233c
    struct state_var     // 0x2340
    {                    //
        int state_var1;  // 0x2340
        int state_var2;  // 0x2344
        int state_var3;  // 0x2348
        int state_var4;  // 0x234c
        int state_var5;  // 0x2350
        int state_var6;  // 0x2354
        int state_var7;  // 0x2358
        int state_var8;  // 0x235c
        int state_var9;  // 0x2360
        int state_var10; // 0x2364
        int state_var11; // 0x2368
        int state_var12; // 0x236c
        int state_var13; // 0x2370
        int state_var14; // 0x2374
        int state_var15; // 0x2378
        int state_var16; // 0x237c
        int state_var17; // 0x2380
        int state_var18; // 0x2384
    } state_var;         //
    int x2388;           // 0x2388
    int x238c;           // 0x238c
    int x2390;           // 0x2390
    int x2394;           // 0x2394
    int x2398;           // 0x2398
    int x239c;           // 0x239c
    int x23a0;           // 0x23a0
    int x23a4;           // 0x23a4
    int x23a8;           // 0x23a8
    int x23ac;           // 0x23ac
    int x23b0;           // 0x23b0
    int x23b4;           // 0x23b4
    int x23b8;           // 0x23b8
    int x23bc;           // 0x23bc
    int x23c0;           // 0x23c0
    int x23c4;           // 0x23c4
    int x23c8;           // 0x23c8
    int x23cc;           // 0x23cc
    int x23d0;           // 0x23d0
    int x23d4;           // 0x23d4
    int x23d8;           // 0x23d8
    int x23dc;           // 0x23dc
    int x23e0;           // 0x23e0
    int x23e4;           // 0x23e4
    int x23e8;           // 0x23e8
    struct MEX
    {
        int anim_owner;
        GOBJ *kb_abilitysource;
        u8 ucf_stick_x[3];
    } MEX;
    struct TM
    {
        s16 state_frame;  // how many frames the player has been in this state
        s16 shield_frame; // how many frames the player has been shielding
        u16 state_prev[6];
        u16 state_prev_frames[6];
        u16 last_move_hurt;        // Previous Move Instance Hit By
        u16 vuln_frames;           // how many frames the fighter has been vulnerable
        u16 can_fastfall_frames;   // how many frames the fighter has been able to fast fall
        int post_hitstun_frames;   // frames fighter has been out of hitstun
        GOBJ *fighter_hurt_shield; // pointer to the fighter who's shield this fighter hit
        void *cb_anim;             // additional animation callback
    } TM;
};

struct FtParts // is in the fighter data
{
    int num;     // 0x2240
    DOBJ **dobj; // 0x2244   array of dobjs for the ftpar
    void *x8;    // 0x2248
    void *xc;    // 0x224C
};

struct FtPartsDesc
{
    int model_num; // 0x2250
    FtPartsLookup *lookups;
};

struct FtPartsLookup
{
    FtParts *x0;
    void *x4;
    void *x8;
    void *xc;
    void *x10;
};

struct FtPartsVis // is in the fighter data
{
    int num;                           // 0x0
    u8 x4[5];                          // 0x4 array of bools?
    FtPartsVisLookup *highpoly_table;  // 0x0C
    FtPartsVisLookup *lowpoly_table;   // 0x10
    FtPartsVisLookup *metalpoly_table; // 0x14
    FtPartsVisLookup *metalmain_table; // 0x18
    FtPartsVisLookup *x1C;             // 0x1C
};

struct FtSymbolLookup
{
    FtSymbols *archives;
    u8 num;
};

struct FtSymbols
{
    JOBJ *joint;         // 0x0
    void *matanim_joint; // 0x4
    void *x8;            // 0x8
    void *xc;            // 0xc
    void *x10;           // 0x10
    ArchiveInfo *costume // 0x14
};

/** State Structs **/
struct FtCliffCatch
{
    int ledge_index;
    float fall_timer;
    int timer;
};

/** Static Variables **/

static ftCommonData **stc_ftcommon = (R13 + -0x514C);
static GXColor **stc_shieldcolors = (R13 + -0x5194);

/*** Functions ***/
void ActionStateChange(float startFrame, float animSpeed, float animBlend, GOBJ *fighter, int stateID, int flags1, int flags2);
void Fighter_UpdateBonePos(FighterData *fighter_data, int unk);
void *Animation_GetAddress(FighterData *fighter, int animID);
SubactionHeader *Fighter_GetSubactionHeader(FighterData *fighter, int animID);
float Animation_GetLength(int animAddress);
void Fighter_EnterLightThrow(GOBJ *fighter, int stateID);
void Fighter_EnterDamageFall(GOBJ *fighter);
void Fighter_EnterWait(GOBJ *fighter);
void Fighter_EnterFall(GOBJ *fighter);
void Fighter_EnterSpecialFall(GOBJ *fighter, int can_fastfall, int can_not_noimpactland, int can_not_interrupt, float aerialDriftMultipler, float landing_frames);
void Fighter_EnterLanding(GOBJ *fighter);
void Fighter_EnterSpecialLanding(GOBJ *fighter, int unk, float state_length);
void Fighter_EnterSleep(GOBJ *fighter, int ms);
void Fighter_EnterEntry(GOBJ *fighter);
void Fighter_EnterCliffWait(GOBJ *fighter);
void Fighter_EnterRebirth(GOBJ *fighter);
void Fighter_EnterRebirthWait(GOBJ *fighter);
void Fighter_UpdateRebirthPlatformPos(GOBJ *fighter);
void Fighter_MoveToCliff(GOBJ *fighter);
GOBJ *Fighter_GetGObj(int ply);
GOBJ *Fighter_GetSubcharGObj(int ply, int ms);
Playerblock *Fighter_GetPlayerblock(int ply);
void Fighter_SetSlotType(int ply, int slot);
int Fighter_GetControllerPort(int ply);
int *Fighter_GetStaleMoveTable(int ply);
void Fighter_SetPosition(int ply, int ms, Vec3 *pos);
void Fighter_ApplyIntang(GOBJ *fighter, int duration);
int Fighter_GetSlotType(int index); // returns 0x0 for HMN, 0x1 for CPU, 0x2 for Demo, 0x3 for not present
int Fighter_GetStocks(int ply);
void Fighter_SetFallNum(int index, int ms, int falls);
void Fighter_EnableECBBottomUpdate(FighterData *fighter);
void Fighter_EnterDamageState(GOBJ *fighter, int stateID, float frame);
int Fighter_BoneLookup(FighterData *fighter, int boneID);
void Fighter_GiveDamage(FighterData *fighter, float damage);
void Fighter_GiveHeal(FighterData *fighter, int heal);
void Fighter_SetHUDDamage(int player, u16 damage);
void Fighter_RunOnHitCallbacks(GOBJ *fighter);
void Fighter_SetStocks(int ply, int stocks);
int FrameTimerCheck(GOBJ *fighter);
void Fighter_EnterMiscPassState(float start_frame, GOBJ *fighter, int state, int flags);
int Fighter_CollGround_PassLedge(GOBJ *fighter);
int Fighter_CollGround_StopLedge(GOBJ *fighter); // returns is_grounded
void Fighter_CollGround_StopLedge_EnterFall(GOBJ *fighter);
int Fighter_CollAir_GrabLedgeWalljump(GOBJ *fighter, void *perFrame, void *onLand);
int Fighter_CollAir_GrabLedge(GOBJ *fighter, int grab_direction);
void Fighter_CollAir_IgnoreLedge(GOBJ *fighter, void *callback);
int Fighter_CollAir_IgnoreLedge_NoCB(GOBJ *fighter);
int Fighter_CollAir_DefineECB(GOBJ *fighter, ECBSize *ecb);
int Fighter_Coll_CheckToPass(GOBJ *fighter, int floor_type); // usually used as a callback, pass = fall through platform
int Fighter_IASACheck_CliffCatch(GOBJ *fighter);
int Fighter_IASACheck_AerialAttack(GOBJ *fighter);
int Fighter_IASACheck_JumpAerial(GOBJ *fighter);
int Fighter_IASACheck_JumpF(GOBJ *fighter);
int Fighter_IASACheck_PassConditions(GOBJ *fighter);
int Fighter_IASACheck_Turn(GOBJ *fighter);
void Fighter_PhysGround_ApplyFriction(GOBJ *fighter);
void Fighter_PhysGround_ApplyCustomFriction(FighterData *fighter, float friction);
void Fighter_PhysGround_UnkFriction(GOBJ *fighter);
void Fighter_PhysAir_ApplyGravityAndFastfall(GOBJ *);
void Fighter_PhysAir_ApplyGravity(FighterData *fighter, float gravity, float limit);
void Fighter_PhysAir_DecayXVelocity(FighterData *fighter, float unk);
void Fighter_PhysAir_LimitXVelocity(FighterData *fighter);
void Fighter_Phys_UseAnimYVelocity(GOBJ *fighter);
void Fighter_Phys_UseAnimXVelocity(GOBJ *fighter);
void Fighter_Phys_UseAnimPos(FighterData *fighter);
void Fighter_Phys_UseAnimPosAndStick(FighterData *fighter);
void Fighter_SetGrounded(FighterData *fighter);
void Fighter_SetGrounded2(FighterData *fighter);
void Fighter_SetAirborne(FighterData *fighter);
void Fighter_SetAirborneNoJumps(FighterData *fighter_data);
void Fighter_LoseGroundJump(FighterData *fighter_data);
void Fighter_KillAllVelocity(GOBJ *fighter);
void Fighter_AdvanceScript(GOBJ *fighter);
void Fighter_GFXRemoveAll(GOBJ *fighter);
void Fighter_EnableReflectUpdate(GOBJ *fighter);
void Fighter_CreateReflect(GOBJ *fighter, ReflectDesc *reflect, void *cb_OnReflectHit);
float Fighter_GetBoneRotation(FighterData *fighter, int bone);
float Fighter_RotateBone_Pitch(FighterData *fighter, int bone, float angle);
float Fighter_RotateBone_Yaw(FighterData *fighter, int bone, float angle);
float Fighter_RotateBone_Roll(FighterData *fighter, int bone, float angle);
void Fighter_PlayVoiceSFX(FighterData *fighter, int sfxID, int volume, int balance);
void Fighter_ApplyOverlay(FighterData *fighter_data, int overlay, int unk);
void Fighter_UpdateOverlay(GOBJ *fighter);
void Fighter_DisableBlend(GOBJ *fighter, int animd_id);
void Fighter_UpdateDynamics(GOBJ *fighter, u16 *dynamic_struct);
void Fighter_ZeroCPUInputs(FighterData *fighter_data);
void Fighter_CreateShieldGFX(GOBJ *fighter);
void Fighter_UpdateShieldGFX(GOBJ *fighter, float size);
int Fighter_GetShieldColorIndex(int ply);
int Fighter_GetExternalID(int ply);
int Fighter_GetCostumeID(int ply);
float Fighter_GetBaseScale(FighterData *fighter);
void Fighter_SetScale(GOBJ *fighter, float scale);
void Fighter_InitDynamics(FighterData *fighter_data);
void Fighter_ProcDynamics(GOBJ *fighter);
float Fighter_GetKnockbackAngle(FighterData *fighter_data);
void Fighter_UpdateCameraBox(GOBJ *fighter);
void Fighter_SetAllHurtboxesNotUpdated(GOBJ *fighter);
void Fighter_UpdateHurtboxes(FighterData *fighter_data);
void Fighter_UpdateIK(GOBJ *fighter);
void Fighter_ColorRemove(FighterData *fighter_data, int color_kind);
void Fighter_CPUInitialize(FighterData *fighter_data, int cpu_kind, int cpu_level, int unk);
int Fighter_GetCPUKind(int ply);
int Fighter_GetCPULevel(int ply);
char *Fighter_GetName(int external_id);
void Fighter_InitPObj();
void Fighter_InitPObj2();
void Fighter_IndexFtPartsDObjs(GOBJ *fighter, JOBJ *copy_model, FtParts *ftparts); // inits the dobj array in ftpartsmodel
void Fighter_InitFtPartsModel(FtPartsDesc *ftpartsdesc, FtPartsVis *unk, int index, FtParts *ftparts, FtParts *ftparts2);
int Fighter_CheckUnlocked(int ext_id);
void Fighter_UpdateDObjFlags(void *ftparts1, int r4, void *bone_info);
void Fighter_UpdateDObjFlags2(void *ftparts1, int r4, void *bone_info);
void Fighter_CreateDynamicsBoneset(JOBJ *joint, FtDynamicBoneset *boneset, int bone_num);
void Fighter_InitDynamicsBoneset(void *dyn_desc_params, FtDynamicBoneset *boneset);
void Fighter_UpdateOnscreenBool(GOBJ *fighter);
void Fighter_SetFacingToStickDirection(FighterData *fighter_data);
int Fighter_CheckToIgnorePlatform(GOBJ *fighter);
int Hitbox_CheckIfPreviouslyHit(void *victim_data, ftHit *hitbox);
void Hitbox_SetAsPreviouslyHit(ftHit *hitbox, int unk, void *victim_data);
int Fighter_CountPlayers();
void Fighter_InitData();
void Fighter_BreakGrabUnk(GOBJ *victim);
void Fighter_BreakGrab(GOBJ *fighter, GOBJ *victim);
void Fighter_SetCharacterFlags(GOBJ *fighter, int, int);
void Fighter_GetECBPosition(GOBJ *fighter, Vec3 *position);
void Fighter_Phys_AnimationFriction(GOBJ *fighter);
void Fighter_CollAir(GOBJ *fighter);
void Fighter_SetFacingToStickDirection(FighterData *fighter_data);
void Fighter_ClampHorizontalVelocity(FighterData *fighter_data, float max_vel);
void Fighter_ClampFallSpeed(FighterData *fighter_data, float max_vel);
void Fighter_QueueAllowXDrift(FighterData *fighter_data, float unk, float accel, float max_vel);
void Fighter_AllowXDrift(FighterData *fighter_data, float unk, float accel, float max_vel);
void Fighter_AddClampYPosition(FighterData *fighter_data, float amt, float max);
void Fighter_ClampHorizontalGroundVelocity(FighterData *, float);
void Fighter_RemoveHeldFighterItem(GOBJ *fighter);
void Fighter_DestroyAndRemoveHeldFighterItem(GOBJ *fighter);
void Fighter_Phys_ApplyVerticalAirFriction(FighterData *fighter_data);
void Fighter_VisTableGet(GOBJ *fighter, int vis_index);
void Fighter_VisTableSet(GOBJ *fighter, int vis_index, int val); // val = -1 for disable, 0 for enable
#endif
