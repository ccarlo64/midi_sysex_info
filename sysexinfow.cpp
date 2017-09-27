//#define _WIN32_IE 0x300

#include <windows.h>
//#include <commctrl.h>
#include <stdio.h>
//#define MAX_PATH_1 1024

#define NAME_SIZE           32
#define NAME_SIZE_WAVE      16
#define NUMERO_WAVE         32
#define POSXBUTT            480 //445 //650
#define BUTTSIZE            70
#define WIDTHLIST           430 //

#define WAVESTATION 0x28
#define M1 0x19
#define T3 0x26
#define M3R 0x24

#include "struct.h"

#include "m1.h"
#include "wavestation.h"
#include "m3r.h"
#include "t3.h"

#define IDC_MAIN_TEXT 9001
#define IDC_MAIN_HEADER 9002
#define IDC_BUTTON_LOAD 9003
#define IDC_MAIN_ENDFILE 9004
#define IDC_BUTTON_LOADP 9005
#define IDC_BUTTON_SAVEP 9006
#define IDC_BUTTON_SAVE 9007
#define IDC_MAIN_DETT 9008
#define IDC_BUTTON_GEN 9009
#define IDC_BUTTON_BANK 9010
#define IDC_MAIN_DETAIL 9011
#define ID_BANK 9012
#define ID_BANK1 9013
#define IDC_BUTTON_EXP 9020        
#define IDC_TYPE_EXP 9021

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
char *patch_decode(char *sbank, int pnum);
unsigned char    Nibble_Decode( unsigned char byte_h, unsigned char byte_l );
char *bank_decode( unsigned char bd );
char *bank_header_decode( unsigned char bd );
//char *message_id_decode( unsigned char m_id);
char *message_id_decode( unsigned char m_id, unsigned char d_id);
char *manuf_id_decode( unsigned char m_id);
char *device_id_decode( unsigned char m_id);
BOOL SaveFile(LPSTR pszText, LPSTR nomefile );
char *choicefile( bool a,HWND hwnd );
void generazione(char *n, int dove);

void Insert_text(HWND htext, char *testo, bool acapo);
char *Trasforma_f4_0c(unsigned char valore);

void Performance_print_detail(struct s_performance1 *pperf, int x, char *string_comodo);
void Patch_print_detail(struct s_patch1 *ppatch1, int x, char *string_comodo);
void Combination_m1_print_detail(struct s_m1 *pperfm1, int x, char *string_comodo);
void Combination_t3_print_detail(struct s_t34d *pperft34d, int x, char *string_comodo);
void M1_effect_Detail( union u_parameters sss, int x, char * string_comodo,int ne);
void Print_timbre(struct s_timbre s, int i);
void Combination_m3r_print_detail(struct s_m3r *pperf3r, int x, char *string_comodo);

unsigned char   LoadMem_Wavestation_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_patch1 *ppatch1);

unsigned char   LoadMem_Wavestation_4d( int NUMERO_PERFORMANCE, HANDLE hFile, HWND htext, struct s_performance1 *pperf1);
//unsigned char   LoadMem_T3_50( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_t34d *pperft34d);
unsigned char   LoadMem_M1_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m14c *pperfm14c);
unsigned char   LoadMem_M1_4d( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m1 *pperfm1);
unsigned char   LoadMem_M1_50( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m150 *pperfm150);

unsigned char   LoadMem_T3_50( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_t350 *pperft350);

unsigned char   LoadMem_Wavestation_54( int nn, HANDLE hFile, HWND htext, struct s_ws_block ws_block);
unsigned char   LoadMem_M3R_4d( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m3r *pperfm3r);
unsigned char   LoadMem_M3R_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m3r4c *pperfm3r4c);

void azzera_m14c(void);
void verso_M1(struct s_header_sysex, 
struct s_m1 *pperfm1, struct s_m3r *pperfm3r, struct s_t34d *pperft34d, 
struct s_m14c *pperfm14c, struct s_m3r4c *pperfm3r4c, int verso, unsigned char tipo);



char GLOBALFILENAME[MAX_PATH];
bool DD=false;
HWND htext;
HWND hdett;
HWND hheader;
HWND hendfile;
HWND hButton_1,hButton_2,hButton_3,hButton_4, hButton_5;
HWND hbank;
HWND hheaderb;
HWND hheaderb1;
HWND hexport;
HWND hTypeExport;

#define GRPLIST 0
#define GRPHEADER 1
#define GRPDETAIL 2
#define GRPBANK 3
#define GRPMSGID 4
HWND hBankN;
HWND hGroup[6];
HWND hHeaderText[4];
HWND hHeaderEdit[4];
HWND hHeaderBank[4];
HWND hHeaderMsgID,hHeaderMsgIDString;
HWND hDetail;
HWND hFilename;

unsigned char NUMERO_PERFORMANCE = 50;
int DIM_PERFORMANCE = 0xb5;
unsigned char NUMERO_PATCH = 35;
int DIM_PATCH = 0x1aa;
unsigned char banco;
int x,ii;
long i;
char nomemio[30];
unsigned char cp;
struct s_performance1 *pperf1;
struct s_performance *pperf;
struct s_patch *ppatch;
struct s_patch1 *ppatch1;
struct s_m1 *pperfm1;
struct s_m14c *pperfm14c;
struct s_t34d *pperft34d;
struct s_m3r *pperfm3r;
struct s_m3r4c *pperfm3r4c;
struct s_m150 *pperfm150;
struct s_t350 *pperft350;

long tot_byte;
HINSTANCE hThisInstance1;
const char g_szClassName[] = "Skeleton";
/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

#include "wavestation.cpp"
#include "m1.cpp"
#include "m3r.cpp"
#include "t3.cpp"


union 
{
    struct s_t34d;
    struct s_m3r;
    struct s_m1;
} u_uguale;




int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{

    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
hThisInstance1=hThisInstance;
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           WS_EX_ACCEPTFILES,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Sysex Info ver 1.1(a) for Wavestation and others - by myself@64",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           600,//544,                 /* The programs width */
//            740,
           420+80+80,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

/*
INITCOMMONCONTROLSEX InitCtrlEx;
InitCtrlEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
InitCtrlEx.dwICC  = ICC_BAR_CLASSES;
InitCommonControlsEx(&InitCtrlEx);
*/
                tot_byte = sizeof(s_performance1)*100;
                pperf1 = (struct s_performance1 *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = DIM_PERFORMANCE*2*NUMERO_PERFORMANCE;
                pperf = (struct s_performance *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = DIM_PATCH*2*NUMERO_PATCH;
                ppatch = (struct s_patch *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = sizeof(s_patch1)*35;
                ppatch1 = (struct s_patch1 *)GlobalAlloc(GPTR, tot_byte + 1);

                tot_byte = sizeof(s_m1)*100;
                pperfm1 = (struct s_m1 *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = sizeof(s_m14c)*100;
                pperfm14c = (struct s_m14c *)GlobalAlloc(GPTR, tot_byte + 1);
                
                tot_byte = sizeof(s_t34d)*100;
                pperft34d = (struct s_t34d *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = sizeof(s_t350);
                pperft350 = (struct s_t350 *)GlobalAlloc(GPTR, tot_byte + 1);
                
                tot_byte = sizeof(s_m3r)*100;
                pperfm3r = (struct s_m3r *)GlobalAlloc(GPTR, tot_byte + 1);
                tot_byte = sizeof(s_m3r4c)*100;
                pperfm3r4c = (struct s_m3r4c *)GlobalAlloc(GPTR, tot_byte + 1);

                tot_byte = sizeof(s_m150);
                pperfm150 = (struct s_m150 *)GlobalAlloc(GPTR, tot_byte + 1);


char fla[30];
//sprintf(fla,"bis %d   old %d",sizeof(s_m14c),sizeof(s_m14cbis));
//sprintf(fla,"bis %d   old %d",sizeof(s_m3r4cbis),sizeof(s_m3r4c));


//MessageBox(NULL, fla,fla,MB_OK);
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
      case WM_CREATE:
            {

            HFONT hfDefault,hfButton;
            hfDefault = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Courier New");
            hfButton  = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Arial");

            hGroup[GRPLIST] = CreateWindowEx( 0, "BUTTON", "List", 
                WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 
                10, 10, 185, 352,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hGroup[GRPLIST], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            hGroup[GRPDETAIL] = CreateWindowEx( 0, "BUTTON", "Detail brief", 
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

            hDetail = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "",
ES_AUTOHSCROLL |ES_AUTOVSCROLL |ES_MULTILINE |ES_LEFT |WS_CHILD |WS_BORDER |WS_VSCROLL |WS_HSCROLL |WS_TABSTOP |WS_VISIBLE,            
//                ES_MULTILINE | ES_LEFT |WS_CHILD | WS_VISIBLE| WS_HSCROLL | WS_VSCROLL | LBS_NOTIFY, 
                10, 210+12+165, 572, 80+80,
                hwnd, (HMENU)IDC_MAIN_DETAIL, GetModuleHandle(NULL), NULL);
            SendMessage(hDetail, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));



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
            int idc;
            for(y=0;y<4;y++)
            {
            idc=ID_BANK+y;
            hHeaderBank[y] = CreateWindowEx( 0, "BUTTON", hHeaderBankString[y], 
                WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON , 
                10+185+10+20+50+y*70, 170, 65, 20,
                hwnd, (HMENU)idc, GetModuleHandle(NULL), NULL);
            SendMessage(hHeaderBank[y], WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
            }

            hFilename = CreateWindowEx(0,"EDIT","", 
                WS_CHILD|WS_VISIBLE|ES_READONLY, 
                10, 367, 572, 20,
                hwnd, (HMENU)8888, GetModuleHandle(NULL), NULL);
            SendMessage(hFilename, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
int pos1,pos2,alt,posy,sepa;
alt=30;
sepa=5;
posy=220;
pos1=10+185+10+200+30;
pos2=10+185+10+200+BUTTSIZE+10+30;
            hButton_1 = CreateWindow("BUTTON","Load file", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
                pos1, posy, BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_LOAD, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_1, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));

            hButton_4 = CreateWindow("BUTTON","Save file", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON |WS_DISABLED	, 
                pos2, posy, BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_SAVE, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_4, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
            
            hButton_2 = CreateWindow("BUTTON","Load Perf", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED, 
                pos1, posy+alt+sepa, BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_LOADP, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_2, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
                            
            hButton_3 = CreateWindow("BUTTON","Save Perf", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED, 
                pos2, posy+alt+sepa, BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_SAVEP, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_3, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));
            
            hButton_5 = CreateWindow("BUTTON","Create for", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED|BS_MULTILINE, 
                pos1, posy+2*(alt+sepa), BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_GEN, GetModuleHandle(NULL), NULL);           
            SendMessage(hButton_5, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));

            hexport = CreateWindow("BUTTON","Export to", 
                WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED|BS_MULTILINE, 
                pos1, 220+3*(alt+sepa), BUTTSIZE, alt, 
                hwnd, (HMENU) IDC_BUTTON_EXP, GetModuleHandle(NULL), NULL);           
            SendMessage(hexport, WM_SETFONT, (WPARAM)hfButton, MAKELPARAM(TRUE, 0));

            hTypeExport = CreateWindowEx( 0, "COMBOBOX", "", 
                WS_CHILD | WS_VISIBLE| CBS_DROPDOWNLIST	, 
                pos2, posy+3*(alt+sepa), BUTTSIZE, 120, 
                hwnd, (HMENU)IDC_TYPE_EXP, GetModuleHandle(NULL), NULL);
            SendMessage(hTypeExport, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

//            SendMessage(hTypeExport, CB_ADDSTRING, 0, (LPARAM)"Wav*");
            SendMessage(hTypeExport, CB_ADDSTRING, 0, (LPARAM)"M1");
//            SendMessage(hTypeExport, CB_ADDSTRING, 0, (LPARAM)"M3R*");
//            SendMessage(hTypeExport, CB_ADDSTRING, 0, (LPARAM)"T3*");
            SendMessage(hTypeExport, CB_SETCURSEL, 0, 0);        
            
            hbank = CreateWindowEx( 0, "COMBOBOX", "", 
                WS_CHILD | WS_VISIBLE| CBS_DROPDOWNLIST	, 
                pos2, posy+2*(alt+sepa), BUTTSIZE, 120, 
                hwnd, (HMENU)IDC_BUTTON_BANK, GetModuleHandle(NULL), NULL);
            SendMessage(hbank, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));

            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM1");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM2");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"RAM3");
            SendMessage(hbank, CB_ADDSTRING, 0, (LPARAM)"CARD");
            SendMessage(hbank, CB_SETCURSEL, 3, 0);
        }
      break;
      
      
      case WM_COMMAND:
         switch(LOWORD(wParam))
         {
            case ID_BANK:
            case ID_BANK+1:
            case ID_BANK+2:
            case ID_BANK+3:
            {   
                int y;
                char stringa[3];
                for(y=0;y<4;y++)
                {
                    if (SendMessage(hHeaderBank[y], BM_GETCHECK, (WPARAM)0, (LPARAM)0)==BST_CHECKED)
                    {
                        sprintf(stringa,"%2.2d",y);
                        SendMessage( hBankN, WM_SETTEXT, 0 , (LPARAM)stringa);                         
                        break;
                    }
                
                }
            }
            break;
            
            case IDC_BUTTON_GEN:
            {
            int iIndex = SendMessage (hbank, CB_GETCURSEL, 0, 0);                
            generazione(GLOBALFILENAME, iIndex);
            }
            break;

            case IDC_BUTTON_LOADP:
            {
            if (header_sysex.message_type == 0x4d)
            {                
                int iIndex = SendMessage (htext, LB_GETCURSEL, 0, 0);
                char chBuffer[33],nomefile[33]; 
                char np[3];
        
                if (iIndex != LB_ERR)  
                {
                    char string_comodo[255];
                    nomefile[0]=0;
                    SendMessage(htext, LB_GETTEXT,(WPARAM)iIndex, (LPARAM)chBuffer);
                    strncpy(np,chBuffer,2);
                    np[2]=0;
                    chBuffer[2]='_';
                    for(i=0;i<strlen(chBuffer);i++)
                        if (chBuffer[i]!=0x20)
                            strncat(nomefile,&chBuffer[i],1);
        
                    char szFileName[MAX_PATH];
                    
                    strcpy(szFileName,choicefile( true, hwnd ));

                    if (szFileName!=NULL)
                    {
                    strcpy(nomefile,szFileName);
        
                    HANDLE hFile;
                    BOOL bSuccess = FALSE;
        
                    sprintf(string_comodo,"%s.syx",nomefile);
                    tot_byte=DIM_PERFORMANCE*2;
        
                    hFile = CreateFile(nomefile, GENERIC_READ, FILE_SHARE_READ, NULL,
                       OPEN_EXISTING, 0, 0);
                    if(hFile != INVALID_HANDLE_VALUE)
                    {
                    DWORD dwFileSize;
                    dwFileSize = GetFileSize(hFile, NULL);
                    if(dwFileSize != 0xFFFFFFFF)
                    {
                    DWORD dwRead;
                    ReadFile(hFile, &header_sysex, sizeof(header_sysex), &dwRead, NULL);

                    if (header_sysex.message_type==0x49) //sigle perf
                    {
                    ReadFile(hFile, &cp, sizeof(cp), &dwRead, NULL); //bank
                    ReadFile(hFile, &cp, sizeof(cp), &dwRead, NULL); // nperf
//                    ReadFile(hFile, &performance, sizeof(performance), &dwRead, NULL); // nperf
                    unsigned char due[2];

                    for(i=0;i<DIM_PERFORMANCE;i++)
                    {
                      ReadFile(hFile, &due, sizeof(due), &dwRead, NULL); 
                      (pperf1+iIndex)->Perf_Name[i] = Nibble_Decode(due[1],due[0]); 
                    }       

                    SendMessage(htext, LB_RESETCONTENT, 0, 0);
                    SendMessage(hendfile, LB_RESETCONTENT, 0, 0);                
                    SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');        
                    
                    tot_byte = DIM_PERFORMANCE*NUMERO_PERFORMANCE;
        
                    for(x=0;x<NUMERO_PERFORMANCE;x++)
                    {
                        ii=0;
                        for(i=0;i<16;i++)
                        {
                            sprintf(&nomemio[ii++],"%c", (pperf1+x)->Perf_Name[i]);
                        }
                        nomemio[ii]='\0';
                        sprintf(string_comodo,"%2.2d %s",x,nomemio);
                        SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
                        
                    }
                  
                    }//49
                    header_sysex.message_type = 0x4d;
                    CloseHandle(hFile);
                    MessageBox(hwnd, nomefile, "File loaded",MB_OK);       
                    }//sizefile
                    }//handle inva
                    }//filename
                }


            }
            }
            break;
            
            
            case IDC_BUTTON_EXP:
                {

            int iIndex = SendMessage (hTypeExport, CB_GETCURSEL, 0, 0);                
//sprintf(string_comodo,"scelta %2.2d",iIndex);
//MessageBox(NULL,string_comodo,string_comodo,MB_OK);
switch (iIndex) // verso
    {
    case 0: // M1
        {
// controllo provenienza
        switch (header_sysex.device_id)
            {
            case M3R:
            {
                if (header_sysex.message_type!=0x50)
                {
                    verso_M1(header_sysex, pperfm1,pperfm3r,pperft34d, pperfm14c,pperfm3r4c,M1,header_sysex.message_type);
                    MessageBox(NULL,"M3R === > M1 file created","INFO",MB_OK);
                }
                else
//                    verso_M1(header_sysex, pperfm1,pperfm3r,pperft34d, pperfm14c,pperfm3r4c,M1,cp);
                    MessageBox(NULL,"M3R === > M1 (type 50 not implemented)","INFO",MB_OK);
            }
            break;
            case M1:
            {
//                verso_M1((struct s_m1 *)pperfm1, M1);
                MessageBox(NULL,"M1 === > M1 (not implemented)","INFO",MB_OK);
            }
            break;
            case T3:
            {
//                verso_M1(header_sysex, pperfm1,pperfm3r, &pperft350->combi[0], M1);
                MessageBox(NULL,"T3 === > M1 (not implemented)","INFO",MB_OK);
            }
            break;
            case WAVESTATION:
            {
//                verso_M1((struct s_m1 *)pperf1);
                MessageBox(NULL,"WAVESTATION === > M1 (not implemented)","INFO",MB_OK);
            }
            break;
            
            
            default:
                break;
            }


        }
        break;
    case 1: // WAVESTATION
        {
        }
        break;
    case 2: // M3R
        {
        }
        break;
    case 3: // T3
        {
        }
        break;
    
    default:
        {
        }
        break;
    
       }       







                }
                break;
                
            case IDC_BUTTON_SAVEP:
            {
            if (header_sysex.message_type == 0x4d)
            {                
            int iIndex = SendMessage (htext, LB_GETCURSEL, 0, 0);
            char chBuffer[33],nomefile[33]; 
            char np[3];
            if (iIndex != LB_ERR)  
            {
                char string_comodo[255];
                nomefile[0]=0;
                SendMessage(htext, LB_GETTEXT,(WPARAM)iIndex, (LPARAM)chBuffer);
                strncpy(np,chBuffer,2);
                np[2]=0;
                chBuffer[2]='_';
                for(i=0;i<strlen(chBuffer);i++)
                    if (chBuffer[i]!=0x20 && chBuffer[i]!='*')
                        strncat(nomefile,&chBuffer[i],1);

                HANDLE hFile;
                BOOL bSuccess = FALSE;

                sprintf(string_comodo,"%s.syx",nomefile);
                tot_byte=DIM_PERFORMANCE*2;

                hFile = CreateFile(string_comodo, GENERIC_WRITE, 0, 0,
                  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

                DWORD dwWritten;
                header_sysex.message_type = 0x49;
                WriteFile(hFile, &header_sysex, sizeof(header_sysex), &dwWritten, NULL);
                header_sysex.message_type = 0x4d;
                
                WriteFile(hFile, &banco, sizeof(banco), &dwWritten, NULL);      
                cp = atoi(np);
                WriteFile(hFile, &cp, sizeof(cp), &dwWritten, NULL);                     

                x = cp;
                cp = 0;
                unsigned char uno;
                unsigned char due[2];
                for(i=0;i<DIM_PERFORMANCE;i++)
                {
                    uno = (pperf1+x)->Perf_Name[i];
                    due[1] = (uno>>4) & 0x0f;
                    due[0] = uno & 0x0f;
                    WriteFile(hFile, &due, sizeof(due), &dwWritten, NULL);
                    cp = cp + due[1] + due[0];
                }

                finefile.check = cp & 0x7f;  
                finefile.fine = 0xf7;
                WriteFile(hFile, &finefile, sizeof(finefile), &dwWritten, NULL);      

                CloseHandle(hFile);
                MessageBox(hwnd, nomefile, "File saved",MB_OK);                                
                } //indx
            }
            }
            break;

            case IDC_BUTTON_SAVE:
            {
            if (header_sysex.message_type == 0x4d)
            {
            char szFileName[MAX_PATH];
            strcpy(szFileName,choicefile( false, hwnd ));
//            MessageBox(NULL, szFileName, "Info",MB_OK);
            if (szFileName!=NULL)
            {
                HANDLE hFile;
                BOOL bSuccess = FALSE;
//                tot_byte=DIM_PERFORMANCE*NUMERO_PERFORMANCE;
            
                hFile = CreateFile(szFileName, GENERIC_WRITE, 0, 0,
                  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
            
                DWORD dwWritten;
                header_sysex.message_type = 0x4d;
                WriteFile(hFile, &header_sysex, sizeof(header_sysex), &dwWritten, NULL);
            //    banco =  
                char stringa[3];   
                SendMessage(hBankN, WM_GETTEXT,(WPARAM)3, (LPARAM)stringa);  
                banco=atoi(stringa);
                WriteFile(hFile, &banco, sizeof(banco), &dwWritten, NULL);      
                //trasformare
                cp=0;
                unsigned char uno;
                unsigned char due[2];
                for(x=0;x<NUMERO_PERFORMANCE;x++)
                {
                    for(i=0;i<DIM_PERFORMANCE;i++)
                    {
                        uno = (pperf1+x)->Perf_Name[i];
                        due[1] = (uno>>4) & 0x0f;
                        due[0] = uno & 0x0f;
                        WriteFile(hFile, &due, sizeof(due), &dwWritten, NULL);
                        cp = cp + due[1] + due[0];
                    }
                }
                finefile.check = cp & 0x7f;  
                finefile.fine = 0xf7;
                WriteFile(hFile, &finefile, sizeof(finefile), &dwWritten, NULL);      
            
                CloseHandle(hFile);
            }
            }
            } //endcase
            break;
            case IDC_BUTTON_LOAD:
            {


                SendMessage(hheader, LB_RESETCONTENT, 0, 0);
                SendMessage(htext, LB_RESETCONTENT, 0, 0);
                SendMessage(hdett, LB_RESETCONTENT, 0, 0);
                SendMessage(hendfile, LB_RESETCONTENT, 0, 0);                
                SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');

                char szFileName[MAX_PATH];

                if (!DD)
                {
                    strcpy(szFileName,choicefile( true, hwnd ));
                }
                    else
                {
                    strcpy(szFileName,GLOBALFILENAME);
                }
                DD = false;
                strcpy(GLOBALFILENAME,szFileName);


                SendMessage(hFilename, WM_SETTEXT, 0, (LPARAM)GLOBALFILENAME);

        
                if (szFileName!=NULL)
                {
            
                HANDLE hFile;
//                BOOL bSuccess = FALSE;
                hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
                   OPEN_EXISTING, 0, 0);
                if(hFile != INVALID_HANDLE_VALUE)
                {
                DWORD dwFileSize;
                dwFileSize = GetFileSize(hFile, NULL);
                if(dwFileSize != 0xFFFFFFFF)
                {
                DWORD dwRead;
                ReadFile(hFile, &header_sysex, sizeof(header_sysex), &dwRead, NULL);

                char string_comodo[255];

/*
                sprintf(string_comodo,"Status byte       [ %2.2x ]", header_sysex.status_byte); 
                SendMessage(hheader, LB_ADDSTRING, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"Manufacturer's ID [ %2.2x ]", header_sysex.korg_id);
                SendMessage(hheader, LB_ADDSTRING, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"Channel number    [ %2.2x ]", header_sysex.channel_number);
                SendMessage(hheader, LB_ADDSTRING, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"Device Id         [ %2.2x ]", header_sysex.device_id);
                SendMessage(hheader, LB_ADDSTRING, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"Msg Type [ %2.2x ] %s", header_sysex.message_type, message_id_decode(header_sysex.message_type)); 
                SendMessage(hheader, LB_ADDSTRING, 0, (LPARAM)string_comodo);
*/         
                sprintf(string_comodo,"%2.2x", header_sysex.status_byte); 
                SendMessage(hHeaderEdit[0], WM_SETTEXT, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"%2.2x", header_sysex.korg_id);
                SendMessage(hHeaderEdit[1], WM_SETTEXT, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"%2.2x", header_sysex.channel_number);
                SendMessage(hHeaderEdit[2], WM_SETTEXT, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"%2.2x", header_sysex.device_id);
                SendMessage(hHeaderEdit[3], WM_SETTEXT, 0, (LPARAM)string_comodo);

                sprintf(string_comodo,"%2.2x", header_sysex.message_type); 
                SendMessage(hHeaderMsgID, WM_SETTEXT, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,"%s", message_id_decode(header_sysex.message_type, header_sysex.device_id)); 
                SendMessage(hHeaderMsgIDString, WM_SETTEXT, 0, (LPARAM)string_comodo);

/*
                sprintf(string_comodo,"%2.2x %s\n%2.2x %s\n", header_sysex.korg_id, 
                manuf_id_decode(header_sysex.korg_id), 
                header_sysex.device_id, 
                device_id_decode(header_sysex.device_id)); 
*/
                sprintf(string_comodo,">%s", manuf_id_decode(header_sysex.korg_id));
                SendMessage(hHeaderText[1], WM_SETTEXT, 0, (LPARAM)string_comodo);
                sprintf(string_comodo,">%s", device_id_decode(header_sysex.device_id));
                SendMessage(hHeaderText[3], WM_SETTEXT, 0, (LPARAM)string_comodo);


//                MessageBox(hwnd, string_comodo, "Info",MB_OK);    

//
                // ------------------------------------------------------
                // ------------------------------------------------------
                // spostato
                EnableWindow(hButton_2, false);                
                EnableWindow(hButton_3, false);                
                EnableWindow(hButton_4, false);                
                EnableWindow(hButton_5, false);                

                EnableWindow(hexport, false);                
                
                ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);         

                sprintf(string_comodo,"%2.2x", banco, bank_header_decode(banco));
                SendMessage(hBankN, WM_SETTEXT, 0, (LPARAM)string_comodo);
                for(x=0;x<4;x++)
                    SendMessage(hHeaderBank[x], BM_SETCHECK, BST_UNCHECKED,0);                
                SendMessage(hHeaderBank[banco], BM_SETCHECK, BST_CHECKED,0);  
                // ------------------------------------------------------
                // ------------------------------------------------------
                // ------------------------------------------------------

switch( header_sysex.device_id )
{
case WAVESTATION:
{
if  ((header_sysex.message_type & 0x7f ) == 0x4d)
{
    EnableWindow(hButton_2, true);                
    EnableWindow(hButton_3, true);                
    EnableWindow(hButton_4, true);                
    EnableWindow(hButton_5, true);                
}
if (( (header_sysex.message_type & 0x7f ) == 0x4d || 
    (header_sysex.message_type & 0x7f ) == 0x49 ))
{
    if ((header_sysex.message_type & 0x7f ) == 0x49)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);         
        sprintf(string_comodo,"Perf number    [ %2.2d ]", banco);
        NUMERO_PERFORMANCE = 1;
    }
    else
    {
        NUMERO_PERFORMANCE = 50;
    }
    cp = LoadMem_Wavestation_4d(  NUMERO_PERFORMANCE, hFile, htext,  pperf1);                
} // endif 4d

if (( (header_sysex.message_type & 0x7f ) == 0x4c || 
     (header_sysex.message_type & 0x7f ) == 0x40 )) 
{
    if ((header_sysex.message_type & 0x7f ) == 0x40)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);         
        sprintf(string_comodo,"Patch number   [ %2.2d ]", banco);
        NUMERO_PATCH = 1;
    }
    else
    {
        NUMERO_PATCH = 35;
    }
    cp =  LoadMem_Wavestation_4c( NUMERO_PATCH, hFile, htext,  ppatch1);
    
} // endif 4c
  
if ( (header_sysex.message_type & 0x7f ) == 0x54 )
{
    cp=LoadMem_Wavestation_54( 0, hFile, htext, ws_block);
} // endif 54  
  
}
break;



case M3R:
{
EnableWindow(hexport, true);      
if ( (header_sysex.message_type & 0x7f ) == 0x4d )
   cp = LoadMem_M3R_4d( 0, hFile, htext, pperfm3r);
if ( (header_sysex.message_type & 0x7f ) == 0x4c )
   cp = LoadMem_M3R_4c( 0, hFile, htext, pperfm3r4c);
}
break;    

case M1:
{
if ( (header_sysex.message_type & 0x7f ) == 0x4d )
   cp = LoadMem_M1_4d( 0, hFile, htext, pperfm1);
if ((header_sysex.message_type & 0x7f ) == 0x4c)
   cp = LoadMem_M1_4c( 0, hFile, htext, pperfm14c);
if ((header_sysex.message_type & 0x7f ) == 0x50)
   cp = LoadMem_M1_50( 0, hFile, htext, pperfm150);   
}
break;

case T3:
{
if ( (header_sysex.message_type & 0x7f ) == 0x50 )
//   cp = LoadMem_T3_50( 0, hFile, htext, pperft34d);
   cp = LoadMem_T3_50( 0, hFile, htext, pperft350);

}
break;

default:
break;
} 

                ReadFile(hFile, &finefile, sizeof(finefile), &dwRead, NULL);                         

                cp = cp & 0x7f;
                
                SendMessage(hFilename, WM_GETTEXT, MAX_PATH, (LPARAM)string_comodo);

//MessageBox(NULL, string_comodo, "Info",MB_OK);        
//                char t[25];
//                sprintf(t," CHECK=%2.2x/%2.2x",finefile.check, cp);
//                strcat(string_comodo,t);
//                SendMessage(hendfile, LB_ADDSTRING, 0, (LPARAM)string_comodo);
//                sprintf(t," EOX=%2.2x",finefile.fine);
//                SendMessage(hendfile, LB_ADDSTRING, 0, (LPARAM)string_comodo);
//                strcat(string_comodo,t);
                SendMessage(hFilename, WM_SETTEXT, 0, (LPARAM)string_comodo);
                
                CloseHandle(hFile);
                }
                
            }
                }
            }
                break;
//**********************        
			case IDC_MAIN_TEXT:
            {
                char string_comodo[255];
                switch (HIWORD(wParam)) 
                { 
                case LBN_SELCHANGE: 
                {

                int iIndex = SendMessage (htext, LB_GETCURSEL, 0, 0);


                if (header_sysex.device_id==M1)
                {
                if ( (header_sysex.message_type & 0x7f ) == 0x4d )
                {
                SendMessage(hdett, LB_RESETCONTENT, 0, 0);               
                SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');        
                if (iIndex != LB_ERR)  
                {
                x = iIndex;
                sprintf(string_comodo,"***");           
                Combination_m1_print_detail(pperfm1, x, string_comodo);
                
                } // index
                } // 4d
                if ( (header_sysex.message_type & 0x7f ) == 0x50 )
                {
                SendMessage(hdett, LB_RESETCONTENT, 0, 0);               
                SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');        
                if (iIndex != LB_ERR)  
                {
                x = iIndex;
                sprintf(string_comodo,"***");       
                if (cp==0x4d)    
                   Combination_m1_print_detail(&pperfm150->combi[0], x, string_comodo);
                
                } // index
                } // 4d

                } // M1
    
                if (header_sysex.device_id==M3R)
                {
                if ( (header_sysex.message_type & 0x7f ) == 0x4d )
                {
                SendMessage(hdett, LB_RESETCONTENT, 0, 0);               
                SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');        
                if (iIndex != LB_ERR)  
                {
                x = iIndex;
                sprintf(string_comodo,"***");           
                Combination_m3r_print_detail(pperfm3r, x, string_comodo);
                
                } // index
                } // 4d
                } // M3R


                if (header_sysex.device_id==T3)
                {
                    if ( (header_sysex.message_type & 0x7f ) == 0x4d )
                    {
                        SendMessage(hdett, LB_RESETCONTENT, 0, 0);       
                        SendMessage( hDetail, WM_SETTEXT, 0 , (LPARAM)"");
                        if (iIndex != LB_ERR)  
                        {
                            x = iIndex;
                            sprintf(string_comodo,"***");           
                            Combination_t3_print_detail(pperft34d, x, string_comodo);
                        } // index
                    } // 4d
                    if ( (header_sysex.message_type & 0x7f ) == 0x50 )
                    {
                        SendMessage(hdett, LB_RESETCONTENT, 0, 0);       
                        SendMessage( hDetail, WM_SETTEXT, 0 , (LPARAM)"");
                        if (iIndex != LB_ERR)  
                        {
                            x = iIndex;
                            sprintf(string_comodo,"***");            
                            if (cp==0x4d)     
                                Combination_t3_print_detail(&pperft350->combi[0], x, string_comodo);
                        } // index
                    } // 4d
                
                } // T3  
    
                if (header_sysex.device_id==WAVESTATION)
                {
                    
                if ( (header_sysex.message_type & 0x7f ) == 0x4c )
                {
                SendMessage(hdett, LB_RESETCONTENT, 0, 0);               
                SendMessage( hDetail, WM_SETTEXT, 0 , (int)'\0');        
                if (iIndex != LB_ERR)  
                {
                x = iIndex;
                unsigned char oscill;
                long wave_num;
                oscill = 1;
                oscill = oscill << ((ppatch1+x)->Number_Of_Waves);

char waveabcd[4][25];
waveabcd[0][0]='\0';
waveabcd[1][0]='\0';
waveabcd[2][0]='\0';
waveabcd[3][0]='\0';
            wave_num = (ppatch1+x)->waveA.Wave_Num[0] + (ppatch1+x)->waveA.Wave_Num[1];
            sprintf(string_comodo,"WAVE A %s/%d", 
            bank_decode((ppatch1+x)->waveA.Wave_Bank), wave_num);
            SendMessage(hdett, LB_ADDSTRING, 0, (LPARAM)string_comodo);                
strcpy(waveabcd[0],string_comodo);

            wave_num = (ppatch1+x)->waveB.Wave_Num[0] + (ppatch1+x)->waveB.Wave_Num[1];
            if (oscill==4) {
            sprintf(string_comodo,"WAVE B %s/%d", 
            bank_decode((ppatch1+x)->waveB.Wave_Bank), wave_num);
                SendMessage(hdett, LB_ADDSTRING, 0, (LPARAM)string_comodo);                
strcpy(waveabcd[1],string_comodo);

            }
            wave_num = (ppatch1+x)->waveC.Wave_Num[0] + (ppatch1+x)->waveC.Wave_Num[1];
            if ((oscill==2) || (oscill==4)){
            sprintf(string_comodo,"WAVE C %s/%d", 
            bank_decode((ppatch1+x)->waveC.Wave_Bank), wave_num);
                SendMessage(hdett, LB_ADDSTRING, 0, (LPARAM)string_comodo);                
strcpy(waveabcd[2],string_comodo);
                    
            }
            wave_num = (ppatch1+x)->waveD.Wave_Num[0] + (ppatch1+x)->waveD.Wave_Num[1];
            if (oscill==4) {
            sprintf(string_comodo,"WAVE D %s/%d", 
            bank_decode((ppatch1+x)->waveD.Wave_Bank), wave_num);
                SendMessage(hdett, LB_ADDSTRING, 0, (LPARAM)string_comodo);                
strcpy(waveabcd[3],string_comodo);

            }
            
    Insert_text(hDetail, waveabcd[0], true);
    Insert_text(hDetail, waveabcd[1], true);
    Insert_text(hDetail, waveabcd[2], true);
    Insert_text(hDetail, waveabcd[3], true);

//Patch_print_detail(ppatch1, x, string_comodo);
                }
                }



                if ( (header_sysex.message_type & 0x7f ) == 0x4d )
                {


                SendMessage(hdett, LB_RESETCONTENT, 0, 0);               
//                SendMessage(hDetail, LB_RESETCONTENT, 0, 0);               
                  SendMessage( hDetail, WM_SETTEXT, 0 , (LPARAM)"");
//MessageBox(NULL,"uno","due",MB_OK);
                if (iIndex != LB_ERR)  
                {
                x = iIndex;
                unsigned char cc, acc;
                char patch_n[8][4];
                char patch_b[8][7];
                unsigned char pm;
                
                for(i=0;i<8;i++)
                {
                    acc = (pperf1+x)->pp[i].Patch_Num;
                    if (acc != 0xff)
                    {
                        sprintf(patch_n[i],"%2.2d",acc);
                        cc = (pperf1+x)->pp[i].Part_Mode;
                        pm = (cc >> 6) & 0x03;
                        cc = (pperf1+x)->pp[i].Bank_Num;
                        sprintf(patch_b[i],"%s",bank_decode( pm*4 + cc ));    
                    }
                    else
                    {
                        patch_b[i][0] = '\0';
                        patch_n[i][0] = '\0';
                    }
                    sprintf(string_comodo,"%s %s %s",patch_n[i],patch_b[i],
                    patch_decode(patch_b[i], acc));
                    SendMessage(hdett, LB_ADDSTRING, 0, (LPARAM)string_comodo);


                    if (acc != 0xff)
                    {

                        Performance_print_detail(pperf1, x, string_comodo);
                    }

// 
                                
                }  // for i
                } // lberr
                
                } //4d 
//                    int combo = SendMessage(hcombo, CB_GETCURSEL, 0, 0);
//                    sprintf(string_comodo,"%d", combo);  
//MessageBox(NULL, string_comodo, "Info",MB_OK);  


                } // wavestation      
                
                } // LBN_SELCHANGE
                break;
                default:
                   break;
                }     
            }
       
//---------------------------

            default:
                break;
        }

        break;
case WM_DROPFILES:
    {
        
        TCHAR FN[MAX_PATH] = {0};  
HDROP hDrop;
hDrop=  (HDROP)wParam;
DragQueryFile(hDrop, 0, FN, MAX_PATH);  
  
DragFinish(hDrop);  
                    MessageBox(hwnd, FN, "DRAG",MB_OK);
DD = true;                    
                strcpy(GLOBALFILENAME,FN);
PostMessage(hwnd, WM_COMMAND,IDC_BUTTON_LOAD, 0);                                   
    }
    break;
       
        case WM_DESTROY:
            GlobalFree(pperf);                
            GlobalFree(ppatch);

            GlobalFree(pperfm1);
            GlobalFree(pperfm14c);
            GlobalFree(pperft34d);
            GlobalFree(pperfm3r);            
            
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


unsigned char    Nibble_Decode( unsigned char byte_h, unsigned char byte_l )
{
    static unsigned char carattere;
    carattere = 16*(byte_h & 0x0f) + (byte_l & 0x0f);    
    return carattere;
}   

char *bank_decode( unsigned char bd )
{
    static char be[12][6]={"RAM1","RAM2","ROM11","CARD","ROM4","ROM5","RAM3","ROM6","ROM7","ROM8","ROM9","ROM10"};
    return be[bd];
}

char *bank_header_decode( unsigned char bd )
{
    static char be[4][6]={"RAM1","RAM2","RAM3","CARD"};
    return be[bd];
}

char *message_id_decode( unsigned char m_id, unsigned char d_id)
{
static char message_string[38][50] = { "Parameter Change Message",
                              "Parameter Change Message Expanded",
                              "Parameter Change Message SR Expanded ",
                              "Single Patch Dump",
                              "Single Performance Dump",
                              "All Patch Dump (within bank)",
                              "All Performance Dump (within bank)",
                              "All Data Dump", // (system, patch, performance, wave sequence,multisets, performance map, scales)",
                              "System Setup Dump",
                              "All Wave Sequence Dump",
                              "Micro Tune Scales Dump",
                              "System Setup Dump Expanded",
                              "Multi Mode Setup Dump",
                              "Performance Map Dump ",
                              "Multi Mode Setup Dump Expanded",
                              "Performance Map Dump Expanded",
                              "Performance Map Dump SR Expanded",
                              "System Setup Dump SR Expanded",
                              "Multi Mode Setup Dump SR Expanded",
                              "Data Load Completed",
                              "Data Load Error",
                              "Patch Write Command",
                              "Performance Write Command",
                              "Write Complete Message",
                              "Write Error Message",
                              "Multi Mode Setup Select",
                              "Multi Mode Setup Select SR Expanded",
                              "Multi Mode Setup Dump Request",
                              "Performance Map Dump Request",
                              "Micro Tune Scales Dump Request",
                              "Wave Sequence Data Dump Request",
                              "System Setup Dump Request",
                              "All Data Dump Request",
                              "Single Patch Dump Request",
                              "Single Performance Dump Request",
                              "All Patch Dump Request",
                              "All Performance Dump Request",
                              "UNKNOW" };
unsigned char message_code[] = { 0x41,0x42,0x43,0x40,0x49,0x4C,0x4D,0x50,0x51,0x54
                                ,0x5A,0x5C,0x55,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x23
                                ,0x24,0x11,0x1A,0x21,0x22,0x5B,0x63,0x06,0x07,0x08
                                ,0x0C,0x0E,0x0F,0x10,0x19,0x1C,0x1D,0x00 };
static char message_string_m1[38][50] = { "Parameter Change",
                              "Mode Data",
                              "?",
                              "Program Parameter Dump",
                              "Combination Parameter Dump",
                              "All Program Parameter Dump",
                              "All Combination Parameter Dump",
                              "All Data (Glb, Cmb, Prg, Seq) Dump", 
                              "Global Data Dump",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "?",
                              "UNKNOW" };
    int i; 
    m_id = m_id &0x7f;
    for (i=0;i<37;i++)
    {
        if ( ( m_id ) == message_code[i] )
            break;
    }
    switch (d_id)
    {
      case WAVESTATION:
      {
       return message_string[i];
       }
       break;
       case M1:
      {
       return message_string_m1[i];
       }
            {}
            break;
            default:
                          {
       return message_string[i];
       }
       break;
       }            
}
BOOL SaveFile(LPSTR pszText, LPSTR nomefile )
{
   HANDLE hFile;
   BOOL bSuccess = FALSE;

   hFile = CreateFile(nomefile, GENERIC_WRITE, 0, 0,
      CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
   if(hFile != INVALID_HANDLE_VALUE)
   {
      DWORD dwTextLength;
      dwTextLength = 4096;
      if(dwTextLength > 0)// No need to bother if there's no text.
      {
       
         if(pszText != NULL)
         {
            
               DWORD dwWritten;
               if(WriteFile(hFile, pszText, dwTextLength, &dwWritten, NULL))
                  bSuccess = TRUE;
         }
      }
      CloseHandle(hFile);
   }
   return bSuccess;
}


char *choicefile( bool a, HWND hwnd )
{
    static char szFileName[MAX_PATH];
    
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    szFileName[0] = 0;
    
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Sysex Files (*.syx)\0*.syx\0All Files (*.*)\0*.*\0\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrDefExt = "syx";
//    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    if(!a)
    {
        ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY |
         OFN_OVERWRITEPROMPT;
        GetSaveFileName(&ofn);
    }
    else
    {
        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
        GetOpenFileName(&ofn);
    }    
    return szFileName;
}



char *patch_decode(char *sbank, int pnum)
{
    int i;
    char nomemio[17];
    char string_comodo[255];   
    char filen[MAX_PATH];
    string_comodo[0] = 0;

    sprintf(filen,"%s.syx", sbank);
    HANDLE hFile;

    if (sbank[0]!=0)
    {
       
    hFile = CreateFile(filen, GENERIC_READ, FILE_SHARE_READ, NULL,
               OPEN_EXISTING, 0, 0);
    if(hFile != INVALID_HANDLE_VALUE)
    {

    SetFilePointer(hFile, 6 + pnum*0x1aa*2, NULL, FILE_BEGIN );
    DWORD dwRead;
    ReadFile(hFile, &patch, sizeof(patch), &dwRead, NULL);            

    int ii=0;
    for(i=0;i<NAME_SIZE;i=i+2)
    {
        sprintf(&nomemio[ii++],"%c", Nibble_Decode( patch.Patch_Name[i+1], patch.Patch_Name[i] ));
    }
    nomemio[ii]='\0';
    sprintf(string_comodo,"%s",nomemio);
 
    CloseHandle(hFile);

    } // hfile 
    }
    return string_comodo;
}
void generazione(char *n, int dove)
{

    unsigned char NUMERO_PERFORMANCE;
    unsigned char NUMERO_PATCH;
    char pins[12][35];
    bool piena=false;
        unsigned char carattere;
    int contaperf=0;
    int pok[50];
    int y=0;
    for(x=0;x<50;x++)
        pok[x]=-1;



    for(i=0;i<12;i++)
      for(x=0;x<35;x++)
        pins[i][x]=-1;

// prepara il log
    char stringa[200];
    SendMessage( hDetail, WM_SETTEXT, 0 , (LPARAM)"");
    Insert_text(hDetail, "Start...", true);


    DWORD dwRead,dwWritten;
    HANDLE fpw,fpwp,fp_patch;
    char filen[50];
    HANDLE fp;
    sprintf(filen,"%s",n);
    fp = CreateFile(filen, GENERIC_READ, FILE_SHARE_READ, NULL,
                   OPEN_EXISTING, 0, 0);

// log
    Insert_text(hDetail, "open file ..... ", false);
    Insert_text(hDetail, filen, true);

    ReadFile(fp, &header_sysex, sizeof(header_sysex), &dwRead, NULL);

    sprintf(filen,"PERFCARD.syx");
    fpw = CreateFile(filen, GENERIC_WRITE, 0, 0,
                  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
// log
    Insert_text(hDetail, "create file ..... ", false);
    Insert_text(hDetail, filen, true);


    sprintf(filen,"CARD.syx");
    fpwp = CreateFile(filen, GENERIC_WRITE, 0, 0,
                  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
// log
    Insert_text(hDetail, "create file ..... ", false);
    Insert_text(hDetail, filen, true);

    char progp;
    ReadFile(fp, &parameter_bank_number, sizeof(parameter_bank_number), &dwRead, NULL);    

    if ( (header_sysex.message_type & 0x7f ) == 0x4d )
    {
    progp=0;
    WriteFile(fpw, &header_sysex, sizeof(header_sysex), &dwWritten, NULL);

// log
    Insert_text(hDetail, "write header 4d (performance) ", true);

    header_sysex.message_type = 0x4c;
    WriteFile(fpwp, &header_sysex, sizeof(header_sysex), &dwWritten, NULL);

// log
    Insert_text(hDetail, "write header 4c (patch) ..... ", true);
    
// -------------- change to CARD into header
    unsigned char pb = 0x03;
    pb = dove; //////////////////////////////////////////////
    WriteFile(fpw, &pb, sizeof(pb), &dwWritten, NULL);
    WriteFile(fpwp, &pb, sizeof(pb), &dwWritten, NULL);    

// log
    Insert_text(hDetail, "change bank reference ..... ", true);

    if (dove==2)
        dove=6;

    unsigned char cp1;
    cp1 = 0;
    cp = 0;


    NUMERO_PERFORMANCE = 50;

    for(x=0;x<NUMERO_PERFORMANCE;x++)
    {
        ReadFile(fp, &performance, sizeof(performance), &dwRead, NULL);    

// log
        Insert_text(hDetail, " ", true);    
        sprintf(stringa,"%2.2d ",x);
        Insert_text(hDetail, stringa, false);        
        for(i=0;i<32;i=i+2)
        {
            sprintf(stringa,"%c", Nibble_Decode( performance.Perf_Name[i+1], performance.Perf_Name[i] ));
            Insert_text(hDetail, stringa, false); 
        }


        for(i=0;i<8;i++)
        {
            int pnum;
            pnum = Nibble_Decode(performance.pp[i].Patch_Num[1],performance.pp[i].Patch_Num[0]);
            if (pnum != 0xff)
            {
            int bb;
            carattere = Nibble_Decode(performance.pp[i].Part_Mode[1],performance.pp[i].Part_Mode[0]);
            bb = (carattere >> 6) & 0x03;  
            carattere = Nibble_Decode(performance.pp[i].Bank_Num[1],performance.pp[i].Bank_Num[0]);                      
            sprintf(filen,"%s.syx", bank_decode( bb*4 + carattere ));
            int banco;
            banco = bb*4 + carattere;
            
            fp_patch = CreateFile(filen, GENERIC_READ, FILE_SHARE_READ, NULL,
                   OPEN_EXISTING, 0, 0);
            if (fp_patch==NULL)
            {
                printf("\nfile %s not found...",filen);
                exit(1);
            }
// log
            Insert_text(hDetail, " ", true);
            Insert_text(hDetail, "open file ", false);             
            Insert_text(hDetail, filen, true);             
            
                        
            int xx;
            NUMERO_PATCH = 35;
            
            SetFilePointer(fp_patch, 6 + pnum*0x1aa*2, NULL, FILE_BEGIN );

            ReadFile(fp_patch, &patch, sizeof(patch), &dwRead, NULL);    

// log
int y;
sprintf(stringa," Extract patch ---> %d --->", pnum);
Insert_text(hDetail, stringa, false); 
for(y=0;y<NAME_SIZE;y=y+2)
{
    sprintf(stringa,"%c", Nibble_Decode( patch.Patch_Name[y+1], patch.Patch_Name[y] ));
    Insert_text(hDetail, stringa, false); 
}
if (pins[banco][pnum]<0)
{
    sprintf(stringa," = new patch "); 
}
else
{
    sprintf(stringa," = already existing n. %d", pins[banco][pnum]); 
}
Insert_text(hDetail, stringa, true); 

            if (pins[banco][pnum]<0)
            {

                if (!piena)
                {
                    pins[banco][pnum] = progp;
                    carattere = progp & 0x0f;
                    performance.pp[i].Patch_Num[0]=carattere;
                    carattere = (progp >> 4 )& 0x0f;
                    performance.pp[i].Patch_Num[1]=carattere;
                }
                else
                {
                    performance.pp[i].Patch_Num[0]=0x0f;
                    performance.pp[i].Patch_Num[1]=0x0f;
                }                    


                performance.pp[i].Bank_Num[0] = dove; ///////////////0x03;
                performance.pp[i].Part_Mode[1] = performance.pp[i].Part_Mode[1] & 0x03;
                if ( progp < 35 ) 
                {
                    WriteFile(fpwp, &patch, sizeof(patch), &dwWritten, NULL);                        
                    for(y=0;y<sizeof(patch);y++)
                        cp1 = cp1 + (unsigned char)patch.Patch_Name[y];
                }

                if (progp==34)
                    piena=true;
        
                progp++;
            }
            else
            {
                carattere = pins[banco][pnum] & 0x0f;
                performance.pp[i].Patch_Num[0]=carattere;
                carattere = (pins[banco][pnum] >> 4 )& 0x0f;
                performance.pp[i].Patch_Num[1]=carattere;
                performance.pp[i].Bank_Num[0] = dove; ////////////0x03;
                performance.pp[i].Part_Mode[1] = performance.pp[i].Part_Mode[1] & 0x03;
                        

            }
    
           CloseHandle(fp_patch);
                
        } // end if 0xff
// -------------------------------- calcolo check
        
    } // end for performance 
        WriteFile(fpw, &performance, sizeof(performance), &dwWritten, NULL);

        if (!piena)
        {
            contaperf++;
            pok[x]=1;
        }

        
        for(i=0;i<sizeof(performance);i++)
            cp = cp + (unsigned char)performance.Perf_Name[i];
    } // endfor 50
    
        if (!piena)
        {
            int hh,y;
            unsigned char pvuota[sizeof(patch)];
            for(y=0;y<sizeof(patch);y++)
                pvuota[y]=0;
            for(hh=progp;hh<35;hh++)
            {
                if ( progp < 35 ) 
                    WriteFile(fpwp, &pvuota, sizeof(pvuota), &dwWritten, NULL);                    
            }    
        }
    cp = cp & 0x7f;
    WriteFile(fpw, &cp, sizeof(cp), &dwWritten, NULL);                    
  
    cp1 = cp1 & 0x7f;
    WriteFile(fpwp, &cp1, sizeof(cp1), &dwWritten, NULL);                    
    cp = 0xf7;
    WriteFile(fpw, &cp, sizeof(cp), &dwWritten, NULL);                    
    WriteFile(fpwp, &cp, sizeof(cp), &dwWritten, NULL);                    

    CloseHandle(fpw);
    CloseHandle(fpwp);    
    
    } // ---------------- end 4D ---------------
    CloseHandle(fp);
    
// log
Insert_text(hDetail, " ", true);     
sprintf(stringa," files generated ");
Insert_text(hDetail, stringa, true);     
header_sysex.message_type = 0x4d;        

}



char *manuf_id_decode( unsigned char m_id)
{
static char message_string[22][50] = { "Kawai"
                                    ,"Roland"
                                    ,"Korg"
                                    ,"Yamaha"
                                    ,"Casio"
                                    ,"Moridaira"
                                    ,"Kamiya"
                                    ,"Akai"
                                    ,"Japan Victor"
                                    ,"Meisosha"
                                    ,"Hoshino Gakki"
                                    ,"Fujitsu Electric"
                                    ,"Sony"
                                    ,"Nishin Onpa"
                                    ,"TEAC"
                                    ,"Matsushita Electric"
                                    ,"Fostex"
                                    ,"Zoom"
                                    ,"Midori Electronics"
                                    ,"Matsushita Communication Industrial"
                                    ,"Suzuki Musical Instrument Mfg."
                                    ,"UNKNOW" };
unsigned char message_code[] = {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,
                                0x4A,0x4B,0x4C,0x4D,0x4E,0x50,0x51,0x52,0x53,0x54,
                                0x55,0x00 };
    int i; 
    m_id = m_id &0x7f;
    for (i=0;i<21;i++)
    {
        if ( ( m_id ) == message_code[i] )
            break;
    }
    return message_string[i];
}



char *device_id_decode( unsigned char m_id)
{
static char message_string[5][50] = { "T3"
                                    ,"M1"
                                    ,"Wavestation"
                                    ,"M3R"
                                    ,"UNKNOW" };
unsigned char message_code[] = {0x26,0x19,0x28,0x24
                                ,0x00 };
    int i; 
    m_id = m_id &0x7f;
    for (i=0;i<4;i++)
    {
        if ( ( m_id ) == message_code[i] )
            break;
    }
    return message_string[i];
}

    

void Insert_text(HWND htext, char *testo, bool acapo)
{
    char bn[65000];
    char string_comodo[3];
    bn[0]='\0';
    SendMessage( htext, WM_GETTEXT, 65000 , (LPARAM)bn);     
//MessageBox(NULL,bn,bn,MB_OK);
    strcat(bn,testo);
    if (acapo)
    {
        sprintf(string_comodo,"%c%c",0x0d,0x0a);
        strcat(bn,string_comodo);
    }
    SendMessage( htext, WM_SETTEXT, 0 , (LPARAM)bn); 
//    MessageBox(NULL,blocconote,    blocconote,MB_OK);    
}




char *Trasforma_f4_0c(unsigned char valore)
{
    static char stringa[5];
    unsigned char valoreori;
    valoreori = valore;
    if ((valore & 0x80)>0)
    {
        valore = valore^255 ;
        valore++;
    }
    sprintf(stringa,"%c%d", ( (valoreori & 0x80 > 0 )? '-' : '+' ), valore);    
    return stringa;   
}


void Print_timbre(struct s_timbre s, int i)
{
char string_comodo[200];
string_comodo[0]='\0';
char pn[256][4];
int a,y;

sprintf(string_comodo," TIMBRE [ %d ]",i+1);
Insert_text(hDetail, string_comodo, true);

pn[0][0]='O';
pn[0][1]='F';
pn[0][2]='F';
pn[0][3]='\0';
y=0;
for(i=0;i<0xC9;i++){
    y++;
    if (i<0x64)
    {
        pn[y][0]='I';
    }
    else 
    {
        pn[y][0]='C';    
    }
    a = i/10;
    if (a>9)
        a=a-10;
    pn[y][1]='0'+a;
    a = i - (i/10)*10;
    pn[y][2]='0'+ a;

    pn[y][3]='\0';

}


sprintf(string_comodo," - Program n. %d [%s]", s.Program_n, pn[s.Program_n]);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Output Level n. %d", s.OutputLevel);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Key Traspose n. %s", Trasforma_f4_0c(s.KeyTraspose));
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Detune n. %s", Trasforma_f4_0c(s.Detune));
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Key Window Top/Bottom n. %d/%d", s.KeyWindowTop, s.KeyWindowBottom);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Vel Window Top/Bottom n. %d/%d", s.VelWindowTop, s.VelWindowBottom);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Control filter  [%2.2x] ", s.ControlFilter);
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo,"  [%s] Program Change",
  ((((s.ControlFilter) & 0x01)>0)? "X" : " ") );
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo,"  [%s] Damper",
  ((((s.ControlFilter) & 0x02)>0)? "X" : " ") );
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo,"  [%s] After Touch",
  ((((s.ControlFilter) & 0x04)>0)? "X" : " ") );
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo,"  [%s] Control Change",
  ((((s.ControlFilter) & 0x08)>0)? "X" : " ") );
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo,"  [%s] Midi Out X=1",
  ((((s.ControlFilter) & 0x10)>0)? "X" : " ") );
Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Timbre %s",
  ((((s.TimbreOnOff) & 0x10)>0)? "ON" : "OFF") );
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Midi channel %d", (s.TimbreOnOff & 0x0f) + 1);
Insert_text(hDetail, string_comodo, true);


sprintf(string_comodo,"");
Insert_text(hDetail, string_comodo, true);


}


