#include "gui.h"
#include "generator.h"
//------------------------------------------------------------------------------

// Thu tuc xu ly thong diep
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)	{
	switch(msg)	{
		case WM_CREATE:	{
			Create_All_Controls(hwnd, lParam);
		}
		
		case WM_COMMAND:
			switch(wParam)	{
				case ID_BUTTON_OSM:	{
					SelectFile(agrsb[0], true);
					Msg_OK(hwnd, agrsb[0].szFileName, "File Is Selected");
					
					Default_typ();
					for (int i=0; i<13; ++i)
						szCheck_TYP[i] = '0';
					break;
				}

				case ID_BUTTON_TYP:	{
					SelectFile(agrsb[1], true);
					Msg_OK(hwnd, agrsb[1].szFileName, "File Is Selected");
					break;
				}
				
				case ID_BUTTON_NET:	{
					SelectFile(agrsb[2], false);
					Add_ext(".net.xml", agrsb[2].szFileName);
					NetConverter();
					Msg_OK(hwnd, agrsb[2].szFileName, "File Is Generated");
					break;
				}
				
				case ID_BUTTON_VIN:	{
					SelectFile(agrsb[3], true);
					Msg_OK(hwnd, agrsb[3].szFileName, "File Is Selected");
					break;
				}

				case ID_BUTTON_ROU:	{
					SelectFile(agrsb[4], false);
					Add_ext(".rou.xml", agrsb[4].szFileName);

					uiVehicles = Save_Text_Value(agrsc_edit[13], 10);
					uiTrips = Save_Text_Value(agrsc_edit[14], 10);
							
				    Read_net_file(rouList);
				    Print_rou_file(rouList);
					Msg_OK(hwnd, agrsb[4].szFileName, "File Is Generated");
					break;
				}
				
				case ID_BUTTON_SUM:	{
					SelectFile(agrsb[5], false);
					Add_ext(".sumocfg", agrsb[5].szFileName);

					uiBegin = Save_Text_Value(agrsc_edit[15], 10);
					uiEnd = Save_Text_Value(agrsc_edit[16], 10);

					Print_sumocfg_file();
					Msg_OK(hwnd, agrsb[5].szFileName, "File Is Generated");
					break;
				}
				
				case ID_BUTTON_TYP_DEFAULT:	{
					Default_typ();
					Msg_OK(hwnd, "Default Values Are Set.", "Successful!");
					break;					
				}
				
				case ID_BUTTON_TYP_SET:	{
					char szId[22], szOneway[6], szAldis[9];
					char szPriority[10], szNumLanes[10], szSpeeed[10];
					
					GetWindowText(agrsc_combo[0].hControl, szId, 22);
					GetWindowText(agrsc_combo[1].hControl, szOneway, 6);
					GetWindowText(agrsc_combo[2].hControl, szAldis, 9);
					
					GetWindowText(agrsc_edit[0].hControl, szPriority, 10);
					GetWindowText(agrsc_edit[1].hControl, szNumLanes, 10);
					GetWindowText(agrsc_edit[2].hControl, szSpeeed, 10);
										
					for (int i=0; i<12; ++i)	{
						if (!strcmp(szId, etypList[i].strId.c_str()))	{
							if (!strcpy(szAldis, "allow"))
								Set_edge_att(etypList[i], szId, 
									!strcmp(szOneway, "true"), atoi(szPriority), 
									atoi(szNumLanes), atof(szSpeeed), 
									szCheck_TYP, "000000000000");
							else
								Set_edge_att(etypList[i], szId, 
									!strcmp(szOneway, "true"), atoi(szPriority), 
									atoi(szNumLanes), atof(szSpeeed), 
									"000000000000", szCheck_TYP);								
							break;
						}
					}
					
					Msg_OK(hwnd, "Values Are Set.", "Successful!");
					break;
				}
				
				case ID_BUTTON_TYP_EXPORT:	{
					SelectFile(agrsb[1], false);
					Add_ext(".typ.xml", agrsb[1].szFileName);

					Print_typ_file();

					Msg_OK(hwnd, agrsb[1].szFileName, "File Is Exported");
					break;
				}
				
				case ID_BUTTON_VIN_DEFAULT:	{
					SelectFile(agrsb[3], false);
					Add_ext(".vin", agrsb[3].szFileName);

					Default_vin();
					Save_vin_file();

					Msg_OK(hwnd, agrsb[3].szFileName, "Default Values Are Set");
					break;
				}
				
				case ID_BUTTON_VIN_ADD_MANUAL:	{
					SelectFile(agrsb[3], false);
					Add_ext(".vin", agrsb[3].szFileName);

					char szId[20], szAccel[10], szDecel[10], szLength[10];
					char szWidth[10], szMinGap[10], szMaxSpeed[10];
					char szSigma[10], szTau[10], szGuiShape[21];
					
					GetWindowText(agrsc_combo[3].hControl, szGuiShape, 21);
					GetWindowText(agrsc_edit[3].hControl, szId, 20);
					GetWindowText(agrsc_edit[4].hControl, szAccel, 10);
					GetWindowText(agrsc_edit[5].hControl, szDecel, 10);
					GetWindowText(agrsc_edit[6].hControl, szLength, 10);
					GetWindowText(agrsc_edit[7].hControl, szWidth, 10);
					GetWindowText(agrsc_edit[8].hControl, szMinGap, 10);
					GetWindowText(agrsc_edit[9].hControl, szMaxSpeed, 10);
					GetWindowText(agrsc_edit[10].hControl, szSigma, 10);
					GetWindowText(agrsc_edit[11].hControl, szTau, 10);
					
					Default_rate();
					Set_vin_att(vtypList, szId, atof(szAccel), atof(szDecel), 
						atof(szLength), atof(szWidth), atof(szMinGap), 
						atof(szMaxSpeed), atof(szSigma), atof(szTau), szGuiShape);
					Save_vin_file();
					
					Msg_OK(hwnd, agrsb[3].szFileName, "Values Are Set");
					break;
				}
				
				case ID_BUTTON_VIN_ADD_RANDOM:	{
					SelectFile(agrsb[3], false);
					Add_ext(".vin", agrsb[3].szFileName);
					
					vtypList.clear();
					Default_rate();
					Add_random_vin("Tra", 1.5, 4.0, 5.0, 1.75, 2.5, 30.0, 
						"transport");
					Add_random_vin("Bus", 2.0, 5.0, 5.8, 2.2, 2.5, 30.0, 
						"bus");
					Add_random_vin("Pas", 2.5, 6.0, 5.0, 2.0, 2.5, 40.0, 
						"passenger");
					Add_random_vin("Mot", 3.0, 6.5, 2.5, 0.5, 0.5, 40.0, 
						"motorcycle");
					Add_random_vin("Bic", 0.5, 1.0, 2.0, 0.3, 1.0, 4.0, 
						"bicycle");
					
					Save_vin_file();
										
					Msg_OK(hwnd, agrsb[3].szFileName, "Random Values Are Generated");
					break;
				}
			}
			
			for (int i=0; i<12; ++i)
				if (LOWORD(wParam) == ID_CHECK_TYP_TRANSPORT+i)	{
					HWND checkbox_handle = (HWND)lParam;
					int state = SendMessage(checkbox_handle, BM_GETCHECK, 0, 0);
		
					if (state == BST_CHECKED)
						szCheck_TYP[i] = '1';
					else
						szCheck_TYP[i] = '0';
			}
				
			break;

		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
			
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	
	return 0;
}

// Chuong trinh chinh
int WINAPI WinMain(	HINSTANCE hInstance, HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, int nCmdShow)	{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	// Dang ky lop cua so
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = "myWindowClass";
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc))	{
		Msg_Error(NULL, "Window Registration Failed.", "Error!");
		return 0;
	}

	// Tao cua so
	if (!(hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "myWindowClass", 
			"SUMO Configuration Generator", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
			CW_USEDEFAULT, 3*MIN_LENGTH, 710, NULL, NULL, hInstance, NULL))) {
		Msg_Error(NULL, "Window Creation Failed.", "Error!");
		return 0;
	}

	// Hien thi cua so
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Vong lap thong diep
	while(GetMessage(&Msg, NULL, 0, 0) > 0)	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
//------------------------------------------------------------------------------
