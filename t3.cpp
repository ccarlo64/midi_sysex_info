
void Combination_t3_print_detail(struct s_t34d *pperft34d, int x, char *string_comodo)
{

char ct[7][50]={"SINGLE","LAYER","SPLIT","VEL.SW","MULTI"};


Insert_text(hDetail, "korg T3", true);
//Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Combination type %3.3d %s", (pperft34d+x)->Type, ct[(pperft34d+x)->Type]);
Insert_text(hDetail, string_comodo, true);

char nome_effetti[34][30]={"error",
"Hall","Hall","Hall","Room","Room","Live Stage","Early reflection 1","Early reflection 2","Early reflection 3","Stereo delay",
"Cross delay","Stereo chorus 1","Stereo chorus 2","Flanger","Flanger","Phase shifter 1","Phase shifter 2","Stereo tremoro 1","Stereo tremoro 2","3 band EQ",
"Over drive","Distorsion","Exciter","Symphonic Ensemble","Rotary Speaker","Delay/Hall","Delay/Room","Delay/Early Reflection","Delay/Delay","Delay/Chorus",
"Delay/Flanger","Delay/Phaser","Delay/Tremolo"};

sprintf(string_comodo," - Effect 1 Pattern n. %d (%s)", 1 + (pperft34d+x)->Effect.e_1_pattern, nome_effetti[(pperft34d+x)->Effect.e_1_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperft34d+x)->Effect.p1, x, string_comodo,1+(pperft34d+x)->Effect.e_1_pattern);

sprintf(string_comodo," - Effect 2 Pattern n. %d (%s)", 1 + (pperft34d+x)->Effect.e_2_pattern, nome_effetti[(pperft34d+x)->Effect.e_2_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperft34d+x)->Effect.p2, x, string_comodo, 1+(pperft34d+x)->Effect.e_2_pattern);
 

int i;

for(i=0;i<8;i++)
{
    Print_timbre( (pperft34d+x)->Timbre[i], i);
}


}
     

unsigned char   LoadMem_T3_50( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_t350 *pperft350)
{

bool bResult;
char nomemio[50],string_comodo[120];
unsigned char cp;

DWORD dwRead;
DWORD dwError;
unsigned char banco;

unsigned char bitti;

//SetFilePointer(hFile, 0x08, NULL, FILE_BEGIN );

unsigned char data_size[2];
int ds;
bResult=ReadFile(hFile, &data_size, sizeof(data_size), &dwRead, NULL);         
ds = data_size[0] & 0x7f | data_size[1] * 128;
sprintf(string_comodo,"%d",ds);
MessageBox(NULL, string_comodo, string_comodo,MB_OK);        


bitti=0;
bResult=ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);         
int ii,oo,x,i;

cp=0,oo=0;
//while  (dwRead>0) 
for(x=0;x<7000;x++)
{      
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        bResult=ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        (pperft350)->global[oo++]= banco;
    }
    bResult=ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);   
} 

//sprintf(string_comodo,"%d, size t350 %d %d %d %d",oo,sizeof(s_t34d),sizeof(s_t34c),sizeof(s_m14c),ds);
//MessageBox(NULL, string_comodo, string_comodo,MB_OK);        

if (MessageBox(NULL, "yes=Load Combinations   no=Load Programs", "FILE ALL DATA",MB_YESNO)==IDYES)
{
    cp=0x4d;
    struct s_t34d *cc;
    cc = &pperft350->combi[0];
    
    for(x=0;x<100;x++)
    {
        ii=0;
        i=0;
        for(i=0;i<10;i++)
        {
            if ((cc+x)->Name[i]>=0x20 && (cc+x)->Name[i]<=0x7f)
                sprintf(&nomemio[ii++],"%c", (cc+x)->Name[i]);
        }
        nomemio[ii]='\0';
        sprintf(string_comodo,"%2.2d %s",x,nomemio);
        SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
    }

}
else
{
    cp=0x4c;
    struct s_t34c *cc;
    cc = &pperft350->progra[0];
    for(x=0;x<200;x++)
    {
        ii=0;
        i=0;
        for(i=0;i<10;i++)
        {
            if ((cc+x)->Name[i]>=0x20 && (cc+x)->Name[i]<=0x7f)
                sprintf(&nomemio[ii++],"%c", (cc+x)->Name[i]);
        }
        nomemio[ii]='\0';
        sprintf(string_comodo,"%3d %s",x,nomemio);
        SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
    }
        
}
//cp = 0;
return cp;
}
