#include <windows.h>

//------------------------------------------------------------------------------
#define ID_BUTTON_OSM				101
#define ID_BUTTON_TYP				102
#define ID_BUTTON_NET				103
#define ID_BUTTON_VIN				104
#define ID_BUTTON_ROU				105
#define ID_BUTTON_SUM				106

#define ID_COMBO_TYP_ID				107
#define ID_COMBO_TYP_ONEWAY			108
#define ID_COMBO_TYP_ALDIS			109
#define ID_EDIT_TYP_PRIORITY		110
#define ID_EDIT_TYP_NUMLANES		111
#define ID_EDIT_TYP_SPEED			112
#define ID_BUTTON_TYP_DEFAULT		113
#define ID_BUTTON_TYP_SET			114
#define ID_BUTTON_TYP_EXPORT		115
#define ID_CHECK_TYP_TRANSPORT		116
#define ID_CHECK_TYP_BUS			117
#define ID_CHECK_TYP_PASSENGER		118
#define ID_CHECK_TYP_TAXI			119
#define ID_CHECK_TYP_VIP			120
#define ID_CHECK_TYP_MOTORCYCLE		121
#define ID_CHECK_TYP_BICYCLE		122
#define ID_CHECK_TYP_PEDESTRIAN		123
#define ID_CHECK_TYP_LIGHTRAIL		124
#define ID_CHECK_TYP_CITYRAIL		125
#define ID_CHECK_TYP_RAIL_SLOW		126
#define ID_CHECK_TYP_RAIL_FAST		127

#define ID_COMBO_VIN_GUISHAPE		128
#define ID_EDIT_VIN_ID				129
#define ID_EDIT_VIN_ACCEL			130
#define ID_EDIT_VIN_DECEL			131
#define ID_EDIT_VIN_LENGTH			132
#define ID_EDIT_VIN_WIDTH			133
#define ID_EDIT_VIN_MINGAP			134
#define ID_EDIT_VIN_MAXSPEED		135
#define ID_EDIT_VIN_SIGMA			136
#define ID_EDIT_VIN_TAU				137
#define ID_BUTTON_VIN_DEFAULT		138
#define ID_BUTTON_VIN_ADD_MANUAL	139
#define ID_BUTTON_VIN_ADD_RANDOM	140

#define ID_EDIT_ROU_VEHICLES		141
#define ID_EDIT_ROU_TRIPS			142

#define ID_EDIT_SUM_BEGIN			143
#define ID_EDIT_SUM_END				144

#define MIN_LENGTH					180
#define MIN_WIDTH					20
#define VSPACE						35
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
struct		Group_controls	{
	HWND	hButton;
	HMENU	hId;
	char*	szLabel;
};
//------------------------------------------------------------------------------
struct Group_static_button	{
	HWND	hStatic;
	HWND	hButton;
	HMENU	hId;
	char*	szStatic;
	char*	szFilter;
	char*	szLabel;
	char	szFileName[100];
};
//------------------------------------------------------------------------------
struct Group_static_control	{
	HWND	hStatic;
	HWND	hControl;
	HMENU	hId;
	char*	szStatic;
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
char		szCheck_TYP[13]		=	"000000000000";
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
char*	aszItems_TYP_id[31]		=	{
	"highway.motorway",		"highway.motorway_link",	"highway.trunk", 
	"highway.trunk_link",	"highway.primary",			"highway.primary_link", 
	"highway.second", 		"highway.second_link", 		"highway.tertiary", 
	"highway.tertiary_link","highway.unclassified", 	"highway.residential", 
	"highway.road", 		"highway.living_street", 	"highway.pedestrian", 
	"highway.service", 		"highway.bus_guideway", 	"highway.track", 
	"highway.path", 		"highway.cycleway", 		"highway.footway", 
	"highway.bridleway", 	"highway.steps", 			"highway.rail", 
	"highway.tram", 		"highway.light_rail", 		"highway.subway", 
	"highway.preserved", 	"highway.narrow_gauge", 	"highway.monorail", 
	"highway.funicular"
};
//------------------------------------------------------------------------------
char* 	aszItems_TYP_oneway[2]		=	{
	"true",					"false"
};
//------------------------------------------------------------------------------
char*	aszItems_TYP_aldis[2]		=	{
	"allow",				"disallow"
};
//------------------------------------------------------------------------------
char*	aszItems_VIN_guiShape[23]	=	{
	"pedestrian",			"bicycle",					"motorcycle",
	"passenger", 			"passenger/sedan",			"passenger/hatchback", 
	"passenger/wagon",		"passenger/van",			"delivery", 
	"transport", 			"transport/semitrailer", 	"transport/trailer", 
	"bus", 					"bus/city", 				"bus/flexible", 
	"bus/overland", 		"rail", 					"rail/light", 
	"rail/city", 			"rail/slow", 				"rail/fast", 
	"rail/cargo", 			"evehicle" 
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Group_controls agrcCheck_TYP[12]		=	{
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_TRANSPORT, 		"transport"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_BUS, 			"bus"			},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_PASSENGER, 		"passenger"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_TAXI, 			"taxi"			},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_VIP, 			"vip"			},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_MOTORCYCLE, 	"motorcycle"	},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_BICYCLE, 		"bicycle"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_PEDESTRIAN, 	"pedestrian"	},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_LIGHTRAIL, 		"lightrail"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_CITYRAIL, 		"cityrail"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_RAIL_SLOW, 		"rail_slow"		},
	{	(HWND)0, 	(HMENU)ID_CHECK_TYP_RAIL_FAST, 		"rail_fast"		},
};
//------------------------------------------------------------------------------
Group_controls agrcButton_TYP[3]	=	{
	{	(HWND)0, 	(HMENU)ID_BUTTON_TYP_DEFAULT, 		"Use Default"	}, 
	{	(HWND)0,	(HMENU)ID_BUTTON_TYP_SET, 			"Set"			}, 
	{	(HWND)0, 	(HMENU)ID_BUTTON_TYP_EXPORT, 		"Export"		}
};
//------------------------------------------------------------------------------
Group_controls agrcButton_VIN[3] = {
	{	(HWND)0,	(HMENU)ID_BUTTON_VIN_DEFAULT, 		"Use Default"	}, 
	{	(HWND)0, 	(HMENU)ID_BUTTON_VIN_ADD_MANUAL,	"Add Manual"	}, 
	{	(HWND)0, 	(HMENU)ID_BUTTON_VIN_ADD_RANDOM,	"Random 100"	}
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Group_static_button agrsb[]		=	{
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_OSM,	"OpenStreetMap File",
 			"OpenStreetMap Files *.osm)\0",				"Import",		""	}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_TYP,	"Edge Type XML File",
 			"Edge Type XML Files (*.typ.xml)\0",		"Import",		""	}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_NET,	"SUMO Net XML File", 
			"SUMO Net XML Files (*.net.xml)\0",			"NETCONVERT",	""	},
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_VIN,	"Vehicles Information File", 
			"Vehicles Information Files (*.vin)\0",		"Import",		""	},
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_ROU,	"Routes XML File", 
			"Routes XML Files (*.rou.xml)\0",			"Export",		""	},
	{(HWND)0,	(HWND)0,	(HMENU)ID_BUTTON_SUM,	"SUMO Configuration File", 		
			"SUMO Configuration Files (*.sumocfg)\0",	"Export",		""	}
};
//------------------------------------------------------------------------------
Group_static_control agrsc_combo[]		=	{
	{(HWND)0,	(HWND)0,	(HMENU)ID_COMBO_TYP_ID,			"id"			  }, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_COMBO_TYP_ONEWAY,		"oneway"		  }, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_COMBO_TYP_ALDIS,		"allow / disallow"}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_COMBO_VIN_GUISHAPE,	"guiShape", 	  }
};
//------------------------------------------------------------------------------
Group_static_control agrsc_edit[]		=	{
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_TYP_PRIORITY,	"priority"		}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_TYP_NUMLANES,	"numLanes"		}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_TYP_SPEED,		"speed"			}, 
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_ID,			"id"			},
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_ACCEL,		"accel"			},
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_DECEL,		"decel"			},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_LENGTH,		"length"		},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_WIDTH,		"width"			},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_MINGAP,		"minGap"		},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_MAXSPEED,	"maxSpeed"		},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_SIGMA,		"sigma"			},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_VIN_TAU,			"tau"			},
	{(HWND)0,	(HWND)0,	(HMENU)0,						"guiShape"		},
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_ROU_VEHICLES,	"Number of vehicles"},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_ROU_TRIPS,		"Number of trips"	},	
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_SUM_BEGIN,		"Begin"			},
	{(HWND)0,	(HWND)0,	(HMENU)ID_EDIT_SUM_END,			"End"			}	
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Thong bao loi
inline void Msg_Error(HWND hwnd, char *info, char *title);
// Thong bao thanh cong
inline void Msg_OK(HWND hwnd, char *info, char *title);
// Chon file de mo hoac luu
void SelectFile(Group_static_button &grsb, bool opsv);
// Them phan mo rong cho ten file neu thieu
void Add_ext(char *ext, char *filename);
// Luu text trong control duoi dang so
int Save_Text_Value(Group_static_control grsc, unsigned length);
//------------------------------------------------------------------------------
// Tao Static Text
HWND Create_Static(HWND hwnd, RECT rect, const char *label);
// Tao Button
HWND Create_Button(HWND hwnd, RECT rect, HMENU id, const char* label);
// Tao List Combobox
HWND Create_List_Combo(HWND hwnd, RECT rect, HMENU id, const HINSTANCE hInst);
// Tao EditBox
HWND Create_EditBox(HWND hwnd, RECT rect, HMENU id);
// Tao CheckBox
HWND Create_CheckBox(HWND hwnd, RECT rect, HMENU id, const char *label);
// Tao Static text chua title va Button tuong ung
void Create_Static_Button(HWND hwnd, int min_wids, int vspaces, int wids, 
		Group_static_button &grsb);
// Tao Static Text va Combo
void Create_Static_Combo(HWND hwnd, int min_wids, int vspaces, float lens, 
		int wids, LPARAM lParam, Group_static_control &grsc, char *items[]);
// Tao Static Text va Edit Text
void Create_Static_Edit(HWND hwnd, int min_wids, int vspaces, float left, 
		float lens, Group_static_control &grsc);
// Tao 3 nut
void Create_3_Buttons(HWND hwnd, int min_wids, int vspaces, int wids, 
		Group_controls agrc[]);
// Tao nhieu Checkbox
void Create_Multi_Checkboxs(HWND hwnd, int min_wids, int vspaces, 
		Group_controls grc[]);
//------------------------------------------------------------------------------
// Tao va hien thi tat ca cac control
void Create_All_Controls(HWND hwnd, LPARAM lParam);
// Thu tuc xu ly thong diep
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
// Chuong trinh chinh
int WINAPI WinMain(	HINSTANCE hInstance, HINSTANCE hPrevInstance, 
		LPSTR lpCmdLine, int nCmdShow);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Thong bao loi
inline void Msg_Error(HWND hwnd, char *info, char *title)	{
	MessageBox(hwnd, info, title, MB_OK | MB_ICONERROR);
}

// Thong bao thanh cong
inline void Msg_OK(HWND hwnd, char *info, char *title)	{
	MessageBox(hwnd, info, title, MB_OK);
}

// Chon file de mo hoac luu
void SelectFile(Group_static_button &grsb, bool opsv)	{
	OPENFILENAME osfn;

	ZeroMemory( &osfn , sizeof(osfn));

	osfn.lStructSize = sizeof(osfn);
	osfn.lpstrFilter = grsb.szFilter;
	osfn.lpstrFile = grsb.szFileName;
	osfn.nMaxFile = 512;
	osfn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES | 
				 OFN_EXPLORER | OFN_HIDEREADONLY;

	if (opsv)
		GetOpenFileName(&osfn);
	else
		GetSaveFileName(&osfn);
}

// Them phan mo rong cho ten file neu thieu
void Add_ext(char *ext, char *filename)	{
	int i, len = strlen(filename), ext_len = strlen(ext);
					
	for (i=ext_len; i>=1; --i)
		if (filename[len-i] != ext[ext_len-i])	{
			for (int j=0; j<=ext_len; ++j)
				filename[len+j] = ext[j];
		}
}

// Luu text trong control duoi dang so
int Save_Text_Value(Group_static_control grsc, unsigned length) 	{
	char *szText = new char[length];
	
	GetWindowText(grsc.hControl, szText, length);
	return atoi(szText);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tao Static Text
HWND Create_Static(HWND hwnd, RECT rect, const char *label)	{
	return CreateWindowEx(WS_EX_CLIENTEDGE, "STATIC", label, 
		WS_CHILD | WS_VISIBLE, rect.left, rect.top, rect.right, rect.bottom, 
		hwnd, NULL, GetModuleHandle(NULL), NULL);
}

// Tao Button
HWND Create_Button(HWND hwnd, RECT rect, HMENU id, const char* label)	{
	return CreateWindowEx(NULL, "Button", label, WS_VISIBLE | WS_CHILDWINDOW, 
		rect.left, rect.top, rect.right, rect.bottom, hwnd, id, 
		GetModuleHandle(NULL), NULL);
}

// Tao List Combobox
HWND Create_List_Combo(HWND hwnd, RECT rect, HMENU id, const HINSTANCE hInst) {
	return CreateWindowEx(0, "Combobox", "",
		CBS_DROPDOWNLIST | WS_CHILD | WS_VISIBLE, rect.left, rect.top, 
		rect.right, rect.bottom, hwnd, id, hInst, NULL);
}

// Tao EditBox
HWND Create_EditBox(HWND hwnd, RECT rect, HMENU id) {
	return CreateWindowEx(NULL, "Edit", "", 
		WS_VISIBLE | WS_CHILDWINDOW | ES_MULTILINE, rect.left, rect.top, 
		rect.right, rect.bottom, hwnd, id, GetModuleHandle(NULL), NULL);
}

// Tao CheckBox
HWND Create_CheckBox(HWND hwnd, RECT rect, HMENU id, const char *label)	{
	return CreateWindowEx(NULL, "Button", label, 
		BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, rect.left, rect.top, 
		rect.right, rect.bottom, hwnd, id, GetModuleHandle(NULL), NULL);
}

// Tao Static text chua title va Button tuong ung
void Create_Static_Button(HWND hwnd, int min_wids, int vspaces, int wids, 
		Group_static_button &grsb) {
	RECT rect = {
		0, 					MIN_WIDTH * min_wids + VSPACE * vspaces, 
		MIN_LENGTH * 2,		MIN_WIDTH
	};
	
	if (!(grsb.hStatic = Create_Static(hwnd, rect, grsb.szStatic)))
		Msg_Error(hwnd, "Static Text Creation Failed.", "Error!");

	rect.left	= MIN_LENGTH * 2;
	rect.right	= MIN_LENGTH;
	rect.bottom	= MIN_WIDTH  * wids;
	
	if (!(grsb.hButton = Create_Button(hwnd, rect, grsb.hId, grsb.szLabel)))
		Msg_Error(hwnd, "Button Creation Failed.", "Error!");
}

// Tao Static Text va Combo
void Create_Static_Combo(HWND hwnd, int min_wids, int vspaces, float lens, 
		int wids, LPARAM lParam, Group_static_control &grsc, char *items[])	{
	RECT rect = {
		0, 					MIN_WIDTH * min_wids + VSPACE * vspaces, 
		MIN_LENGTH * lens,	MIN_WIDTH
	};
	
	if (!(grsc.hStatic = Create_Static(hwnd, rect, grsc.szStatic)))
		Msg_Error(hwnd, "Static Text Creation Failed.", "Error!");

	rect.top	+= MIN_WIDTH;
	rect.bottom	+= MIN_WIDTH * wids;

	if (!(grsc.hControl = Create_List_Combo(hwnd, rect, grsc.hId, 
			((CREATESTRUCT*)lParam)->hInstance)))
		Msg_Error(hwnd, "List Combobox Creation Failed.", "Error!");
		
	for (int i=0; i<wids; ++i)
		SendMessage(grsc.hControl, CB_ADDSTRING, 0, (LPARAM)items[i]);
}

// Tao Static Text va Edit Text
void Create_Static_Edit(HWND hwnd, int min_wids, int vspaces, float left, 
		float lens, Group_static_control &grsc)	{
	RECT rect = {
		MIN_LENGTH * left,	MIN_WIDTH * min_wids + VSPACE * vspaces, 
		MIN_LENGTH * lens,	MIN_WIDTH
	};

	if (!(grsc.hStatic = Create_Static(hwnd, rect, grsc.szStatic)))
		Msg_Error(hwnd, "Static Text Creation Failed.", "Error!");

	rect.top	+= MIN_WIDTH;

	if (!(grsc.hControl = Create_EditBox(hwnd, rect, grsc.hId)))
		Msg_Error(hwnd, "EditBox Creation Failed.", "Error!");	
}

// Tao 3 nut
void Create_3_Buttons(HWND hwnd, int min_wids, int vspaces, int wids, 
		Group_controls agrc[])	{
	RECT rect = {
		MIN_LENGTH * 2,	0, 
		MIN_LENGTH,		MIN_WIDTH * wids
	};

	for (int i=0; i<3; ++i)	{
		rect.top = MIN_WIDTH * (min_wids + i*wids) + VSPACE * vspaces;
		
		if (!(agrc[i].hButton = Create_Button(hwnd, rect, agrc[i].hId, 
				agrc[i].szLabel)))
			Msg_Error(hwnd, "Button Creation Failed.", "Error!");
	}
}

// Tao nhieu Checkbox
void Create_Multi_Checkboxs(HWND hwnd, int min_wids, int vspaces, 
		Group_controls grc[])	{
	RECT rect = {
		0,				0, 
		MIN_LENGTH / 2,	MIN_WIDTH
	};
	
	for (int i=0; i<12; ++i)	{
		rect.left = MIN_LENGTH * (i%4)/2;
		rect.top  = MIN_WIDTH * (min_wids + i/4) + VSPACE * vspaces;
		
		if (!(grc[i].hButton = Create_CheckBox(hwnd, rect, grc[i].hId, 
				grc[i].szLabel)))
			Msg_Error(hwnd, "CheckBox Creation Failed.", "Error!");
	}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Tao va hien thi tat ca cac control
void Create_All_Controls(HWND hwnd, LPARAM lParam)	{
	//--------------------Tieu de + Button dau tien---------------------
	Create_Static_Button(hwnd, 0, 0, 1, agrsb[0]);
	Create_Static_Button(hwnd, 1, 1, 1, agrsb[1]);
	Create_Static_Button(hwnd, 11, 2, 1, agrsb[2]);
	Create_Static_Button(hwnd, 12, 3, 1, agrsb[3]);
	Create_Static_Button(hwnd, 19, 4, 3, agrsb[4]);
	Create_Static_Button(hwnd, 22, 5, 3, agrsb[5]);
		
	//-----------------------Static + Bombobox--------------------------
	Create_Static_Combo(hwnd, 2, 1, 2, 31, lParam, agrsc_combo[0], 
		aszItems_TYP_id);
	Create_Static_Combo(hwnd, 4, 1, 0.5, 2, lParam, agrsc_combo[1], 
		aszItems_TYP_oneway);
	Create_Static_Combo(hwnd, 6, 1, 2, 2, lParam, agrsc_combo[2], 
		aszItems_TYP_aldis);
	Create_Static_Combo(hwnd, 13, 3, 1, 23, lParam, agrsc_combo[3], 
		aszItems_VIN_guiShape);
					
	//-------------------------Static + EditBox-------------------------
	Create_Static_Edit(hwnd, 4, 1, 0.5, 0.5, agrsc_edit[0]);
	Create_Static_Edit(hwnd, 4, 1, 1, 0.5, agrsc_edit[1]);
	Create_Static_Edit(hwnd, 4, 1, 1.5, 0.5, agrsc_edit[2]);
	Create_Static_Edit(hwnd, 13, 3, 1, 1, agrsc_edit[3]);
	Create_Static_Edit(hwnd, 15, 3, 0, 0.5, agrsc_edit[4]);
	Create_Static_Edit(hwnd, 15, 3, 0.5, 0.5, agrsc_edit[5]);
	Create_Static_Edit(hwnd, 15, 3, 1, 0.5, agrsc_edit[6]);
	Create_Static_Edit(hwnd, 15, 3, 1.5, 0.5, agrsc_edit[7]);
	Create_Static_Edit(hwnd, 17, 3, 0, 0.5, agrsc_edit[8]);
	Create_Static_Edit(hwnd, 17, 3, 0.5, 0.5, agrsc_edit[9]);
	Create_Static_Edit(hwnd, 17, 3, 1, 0.5, agrsc_edit[10]);
	Create_Static_Edit(hwnd, 17, 3, 1.5, 0.5, agrsc_edit[11]);
	Create_Static_Edit(hwnd, 20, 4, 0, 1, agrsc_edit[13]);
	Create_Static_Edit(hwnd, 20, 4, 1, 1, agrsc_edit[14]);
	Create_Static_Edit(hwnd, 23, 5, 0, 1, agrsc_edit[15]);
	Create_Static_Edit(hwnd, 23, 5, 1, 1, agrsc_edit[16]);
	
	//-------------------------12 Checkbox------------------------------
	Create_Multi_Checkboxs(hwnd, 8, 1, agrcCheck_TYP);

	//----------------------------3 Button------------------------------
	Create_3_Buttons(hwnd, 2, 1, 3, agrcButton_TYP);							
	Create_3_Buttons(hwnd, 13, 3, 2, agrcButton_VIN);
}
//------------------------------------------------------------------------------
