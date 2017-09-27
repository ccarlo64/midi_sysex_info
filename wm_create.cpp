
            HFONT hfDefault,hfButton;
            hfDefault = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Courier New");
            hfButton  = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");
            
            hGroup[GRPLIST] = CreateWindowEx( 0, "BUTTON", "List", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10, 10, 185, 352,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPLIST], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            hGroup[GRPDETAIL] = CreateWindowEx( 0, "BUTTON", "Detail", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10+185+10, 202, 220, 162,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPDETAIL], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            htext = CreateWindowEx( WS_EX_CLIENTEDGE, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL | LBS_NOTIFY, 
                10+5, 10+20, 185-10, 360-25,
                hwnd, (HMENU)IDC_MAIN_TEXT, GetModuleHandle(NULL), NULL);
            SendMessage(htext, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            hdett = CreateWindowEx( WS_EX_CLIENTEDGE, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL | LBS_NOTIFY, 
                10+185+10+5, 210+12, 210, 132,
//                WIDTHLIST/2+10, 120, WIDTHLIST/2 -10, 190,
                hwnd, (HMENU)IDC_MAIN_DETT, GetModuleHandle(NULL), NULL);
            SendMessage(hdett, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            hGroup[GRPHEADER] = CreateWindowEx( 0, "BUTTON", "Header", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10+185+10, 10, 380, 70,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPHEADER], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            int y=0;
            char hHeaderString[4][20] = {"Status Byte","Manufacturer's ID","Channel Midi","Device ID"};
            for(y=0;y<2;y++)
            {
                hHeaderText[y] = CreateWindowEx(0,"EDIT",hHeaderString[y], 
                    WS_CHILD|WS_VISIBLE|ES_READONLY	, 
                    5+185+10+20, 30+y*20, 140, 20,
                    hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
                SendMessage(hHeaderText[y], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
                hHeaderEdit[y] = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", 
                    WS_CHILD|WS_VISIBLE|ES_READONLY	|ES_CENTER, 
                    50+185+10+20+100, 30+y*20, 30, 20,
                    hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
                SendMessage(hHeaderEdit[y], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

                hHeaderText[y+2] = CreateWindowEx(0,"EDIT",hHeaderString[y+2], 
                    WS_CHILD|WS_VISIBLE|ES_READONLY	, 
                    5+185+10+20+180, 30+y*20, 140, 20,
                    hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
                SendMessage(hHeaderText[y+2], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
                hHeaderEdit[y+2] = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", 
                    WS_CHILD|WS_VISIBLE|ES_READONLY	|ES_CENTER, 
                    50+185+10+20+100+180, 30+y*20, 30, 20,
                    hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
                SendMessage(hHeaderEdit[y+2], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            }
            
            hGroup[GRPMSGID] = CreateWindowEx( 0, "BUTTON", "Msg Type", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10+185+10, 90, 380, 50,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPMSGID], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            
            hHeaderMsgID = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", 
                WS_CHILD|WS_VISIBLE|ES_READONLY	|ES_CENTER, 
                5+185+10+20, 110, 30, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hHeaderMsgID, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            hHeaderMsgIDString = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", 
                WS_CHILD|WS_VISIBLE|ES_READONLY	|ES_CENTER, 
                10+185+10+5+40, 110, 320, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hHeaderMsgIDString, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));


            hGroup[GRPBANK] = CreateWindowEx( 0, "BUTTON", "Bank", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10+185+10, 150, 380, 50,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPBANK], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            hBankN = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","", 
                WS_CHILD|WS_VISIBLE|ES_READONLY	|ES_CENTER, 
                5+185+10+20, 170, 30, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hBankN, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            char hHeaderBankString[4][5] = {"RAM1","RAM2","RAM3","CARD"};
            for(y=0;y<4;y++)
            {
            hHeaderBank[y] = CreateWindowEx( 0, "BUTTON", hHeaderBankString[y], 
                WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON , 
                10+185+10+20+50+y*70, 170, 65, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hHeaderBank[y], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            }

            hFilename = CreateWindowEx(0,"EDIT","", 
                WS_CHILD|WS_VISIBLE|ES_READONLY, 
                10, 367, 572, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hFilename, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));



/*
            HFONT hfDefault;
            hfDefault = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Courier New");
// WS_EX_CLIENTEDGE
            hheader = CreateWindowEx( 0, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL, 
                0, 0, WIDTHLIST, 120,
                hwnd, (HMENU)IDC_MAIN_HEADER, GetModuleHandle(NULL), NULL);
            SendMessage(hheader, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            htext = CreateWindowEx( 0, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL | LBS_NOTIFY, 
                0, 120, WIDTHLIST/2, 190,
                hwnd, (HMENU)IDC_MAIN_TEXT, GetModuleHandle(NULL), NULL);
            SendMessage(htext, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
//            
            hdett = CreateWindowEx( 0, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL | LBS_NOTIFY, 
                WIDTHLIST/2+10, 120, WIDTHLIST/2 -10, 190,
                hwnd, (HMENU)IDC_MAIN_DETT, GetModuleHandle(NULL), NULL);
            SendMessage(hdett, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            hendfile = CreateWindowEx( 0, "LISTBOX", "", 
                WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL, 
                0, 310, WIDTHLIST/2, 40,
                hwnd, (HMENU)IDC_MAIN_ENDFILE, GetModuleHandle(NULL), NULL);
            SendMessage(hendfile, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
*/
            hButton_1 = CreateWindow("BUTTON","Load file", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
                10+185+10+200+30, 220, BUTTSIZE, 35, 
                hwnd, (HMENU) IDC_BUTTON_LOAD, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_1, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));

            hButton_4 = CreateWindow("BUTTON","Save file", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON |WS_DISABLED	, 
                10+185+10+200+BUTTSIZE+10+30, 220, BUTTSIZE, 35, 
                hwnd, (HMENU) IDC_BUTTON_SAVE, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_4, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
            
            hButton_2 = CreateWindow("BUTTON","Load Perf", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED, 
                10+185+10+200+30, 220+45, BUTTSIZE, 35, 
//                POSXBUTT, 110, BUTTSIZE, 40, 
                hwnd, (HMENU) IDC_BUTTON_LOADP, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_2, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
                            
            hButton_3 = CreateWindow("BUTTON","Save Perf", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED, 
                10+185+10+200+BUTTSIZE+10+30, 220+45, BUTTSIZE, 35, 
//                                POSXBUTT, 155, BUTTSIZE, 40, 
                hwnd, (HMENU) IDC_BUTTON_SAVEP, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_3, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
            
            hButton_5 = CreateWindow("BUTTON","Create..", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED|BS_MULTILINE, 
                10+185+10+200+30, 220+90, BUTTSIZE, 35, 
//                POSXBUTT, 200, BUTTSIZE, 40, 
                hwnd, (HMENU) IDC_BUTTON_GEN, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_5, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
            
            hbank = CreateWindowEx( 0, "COMBOBOX", "", 
                WS_CHILD | WS_VISIBLE| CBS_DROPDOWNLIST	, 
                10+185+10+200+BUTTSIZE+10+30, 220+90, BUTTSIZE, 120, 
//                POSXBUTT, 250, BUTTSIZE, 120,
                hwnd, (HMENU)IDC_BUTTON_BANK, GetModuleHandle(NULL), NULL);
            SendMessage(hbank, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM1");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM2");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM3");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"CARD");
            SendMessage(hbank, CB_SETCURSEL, 3, 0);

/*
            hheaderb = CreateWindowEx( 0, "BUTTON", "aaa", 
                WS_CHILD | WS_VISIBLE|BS_GROUPBOX, 
                POSXBUTT-10, 5, BUTTSIZE+20, 40*4+130,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hheaderb, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
/*            hheaderb1 = CreateWindowEx( WS_EX_CLIENTEDGE, "BUTTON", "bbb", 
                WS_CHILD | WS_VISIBLE|BS_AUTORADIOBUTTON, 
                WIDTHLIST/2 +30, 310, 20, 40,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hheaderb1, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
*/
//                        reinterpret_cast<LPARAM>((LPCTSTR)ComboBoxItems[0]));
//
            
/*            
            htesto1 = CreateWindow("STATIC","", WS_CHILD|WS_VISIBLE, 
            0, 0, 300, 20,
            hwnd, (HMENU)999, GetModuleHandle(NULL), NULL);
            SendMessage(htesto1, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            
            SetWindowText(htesto1, "and you are in ......");                              
*/           


