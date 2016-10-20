/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* appearance */
static const char *fonts[] = {
	"xft:terminus:pixelsize=14"
};
static const char dmenufont[]       = "-*-terminus-medium-*-*-*-14-*-*-*-*-*-*-1";
/*static const char normbordercolor[] = "#252D43";
static const char normbgcolor[]     = "#192033";
static const char normfgcolor[]     = "#D3D7CF";
static const char selbordercolor[]  = "#06989A";
static const char selbgcolor[]      = "#252D43";
static const char selfgcolor[]      = "#D3D7CF";*/
/*static const char normbordercolor[] = "#073642";
static const char normbgcolor[]     = "#073642";
static const char normfgcolor[]     = "#b58900";
static const char selbordercolor[]  = "#CB4B16";
static const char selbgcolor[]      = "#002B36";
static const char selfgcolor[]      = "#cb4b16";*/
static const char normbordercolor[] = "#928374";
static const char normbgcolor[]     = "#1d2021";
static const char normfgcolor[]     = "#928374";
static const char selbordercolor[]  = "#d65d0e";
static const char selbgcolor[]      = "#282828";
static const char selfgcolor[]      = "#d65d0e";
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int gappx              = 15;

#define NUMCOLORS 2
static const char colors[NUMCOLORS][MAXCOLORS][8] = {
  /*  POKEMIX
  { "#252D43", "#D3D7CF", "#192033"},
  { "#06989A", "#D3D7CF", "#252D43"},
  */
  /*  SOLARIZED */
  /*{ "#073642", "#EEE8D5", "#073642" },
  { "#CB4B16", "#EEE8D5", "#002B36"},*/
  { "#928374", "#ebdbb2", "#1d2021" },
  { "#d65d0e", "#ebdbb2", "#282828" },
};
/* tagging */
/* static const char *tags[] = { "", "", "", "", "", "6", "7", "8", "9" };*/

static const char *tags[] = { "☯", "☰", "☱", "☲", "☳", "☴", "☵", "☶", "☷" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "google-chrome",  NULL,       NULL,       1,       0,           -1 },
	{ "vlc",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Vlc",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Steam",  NULL,       NULL,       1 << 5,       1,           -1 },
	{ "csgo_linux",  NULL,       NULL,       1 << 5,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "🜖",      tile },    /* first entry is default */
	{ "🝆",      NULL },    /* no layout function means floating behavior */
	{ "☉",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, "-x", "400", "-y", "372", "-w", "566", NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *chrome[]  = { "google-chrome", NULL };
static const char *gmrun[]  = { "gmrun", NULL };
static const char *locker[]  = { "lock", NULL };
static const char *screener[]  = { "screener", NULL };
static const char *mpd_curr[]  = { "notif", "mpd_current", NULL };
static const char *volUp[]  = { "amixer", "sset", "Master", "5%+", NULL };
static const char *volDown[]  = { "amixer", "sset", "Master", "5%-", NULL };
static const char *next[]  = { "mpc", "next", NULL };
static const char *prev[]  = { "mpc", "prev", NULL };
static const char *mute[]  = { "amixer", "set", "Master", "toggle", NULL };
static const char *play[]  = { "mpc", "toggle", NULL };
static const char *lightUp[]  = { "xbacklight", "-inc", "5",  NULL };
static const char *lightDown[]  = { "xbacklight", "-dec", "5",  NULL };
static const char *suspend[]  = { "systemctl", "suspend", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = chrome } },
	{ MODKEY|ShiftMask,             XK_r, spawn,          {.v = gmrun } },
	{ MODKEY|ShiftMask,             XK_l, spawn,          {.v = locker } },
	{ MODKEY|ShiftMask,             XK_p, spawn,          {.v = suspend } },
	{ MODKEY,                       XK_p, spawn,          {.v = mpd_curr } },
  { 0,                            XK_Print,    spawn,        { .v = screener } },
  { 0,                            XF86XK_AudioPrev,    spawn,        { .v = prev } },
  { 0,                            XF86XK_AudioPlay,    spawn,        { .v = play } },
  { 0,                            XF86XK_AudioNext,    spawn,        { .v = next } },
  { 0,                            XF86XK_AudioMute,    spawn,        { .v = mute } },
  { 0,                            XF86XK_AudioLowerVolume,spawn,        { .v = volDown } },
  { 0,                            XF86XK_AudioRaiseVolume,spawn,        { .v = volUp } },
  { 0,                            XF86XK_MonBrightnessUp,spawn,        { .v = lightUp } },
  { 0,                            XF86XK_MonBrightnessDown,spawn,        { .v = lightDown } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

