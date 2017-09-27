

void Combination_m3r_print_detail(struct s_m3r *pperfm3r, int x, char *string_comodo)
{

char ct[7][50]={"SINGLE","LAYER","SPLIT","VEL.SW","MULTI"};


Insert_text(hDetail, "Korg M3R ", true);
//Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Combination type %3.3d %s", (pperfm3r+x)->Type, ct[(pperfm3r+x)->Type]);
Insert_text(hDetail, string_comodo, true);

int i;

// effect
char nome_effetti[34][30]={"error",
"Hall","Hall","Hall","Room","Room","Live Stage","Early reflection 1","Early reflection 2","Early reflection 3","Stereo delay",
"Cross delay","Stereo chorus 1","Stereo chorus 2","Flanger","Flanger","Phase shifter 1","Phase shifter 2","Stereo tremoro 1","Stereo tremoro 2","3 band EQ",
"Over drive","Distorsion","Exciter","Symphonic Ensemble","Rotary Speaker","Delay/Hall","Delay/Room","Delay/Early Reflection","Delay/Delay","Delay/Chorus",
"Delay/Flanger","Delay/Phaser","Delay/Tremolo"};

sprintf(string_comodo," - Effect 1 Pattern n. %d (%s)", 1 + (pperfm3r+x)->Effect.e_1_pattern, nome_effetti[(pperfm3r+x)->Effect.e_1_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperfm3r+x)->Effect.p1, x, string_comodo,1+(pperfm3r+x)->Effect.e_1_pattern);

sprintf(string_comodo," - Effect 2 Pattern n. %d (%s)", 1 + (pperfm3r+x)->Effect.e_2_pattern, nome_effetti[(pperfm3r+x)->Effect.e_2_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperfm3r+x)->Effect.p2, x, string_comodo, 1+(pperfm3r+x)->Effect.e_2_pattern);
         
sprintf(string_comodo," - Effect 1 Balance left/right %d/%d", (pperfm3r+x)->Effect.e_1_left_ch_bal, (pperfm3r+x)->Effect.e_1_right_ch_bal);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Effect 2 Balance left/right %d/%d", (pperfm3r+x)->Effect.e_2_left_ch_bal, (pperfm3r+x)->Effect.e_2_right_ch_bal);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Output 3 pan %d", (pperfm3r+x)->Effect.output_3_pan);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Output 4 pan %d", (pperfm3r+x)->Effect.output_4_pan);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Effect I/O %d", (pperfm3r+x)->Effect.e_i_o);
Insert_text(hDetail, string_comodo, true);

for(i=0;i<8;i++)
{
    Print_timbre( (pperfm3r+x)->Timbre[i], i);
}

}




unsigned char   LoadMem_M3R_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m3r4c *pperfm3r4c)
{
char nomemio[50],string_comodo[120];
unsigned char cp;

DWORD dwRead;

unsigned char banco;

unsigned char bitti;

bitti=0;
ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);         
int ii,oo,x,i;
cp=0,oo=0;
while  (dwRead>0) 
{
//        for(ii=0;ii<1800/bla;ii++)
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        (pperfm3r4c+oo)->Name[cp++]= banco;
        if (cp>74)
        {
            cp=0;
            oo++;
        } 

    }
    ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);   
} 
for(x=0;x<100;x++)
{
    ii=0;
    i=0;
    for(i=0;i<10;i++)
    {
        if ((pperfm3r4c+x)->Name[i]>=0x20 && (pperfm3r4c+x)->Name[i]<=0x7f)
        sprintf(&nomemio[ii++],"%c", (pperfm3r4c+x)->Name[i]);
    }
    nomemio[ii]='\0';
    sprintf(string_comodo,"%2.2d %s",x,nomemio);
    SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
}

cp = 0;
return cp;
}

unsigned char   LoadMem_M3R_4d( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m3r *pperfm3r)
{
char nomemio[50],string_comodo[120];
unsigned char cp;

DWORD dwRead;

unsigned char banco;

unsigned char bitti;

bitti=0;
ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);         
int ii,oo,x,i;
cp=0,oo=0;
while (dwRead>0) 
{
//for(ii=0;ii<1800/bla;ii++)   
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        
        (pperfm3r+oo)->Name[cp++]= banco;
        if (cp>(sizeof(s_m3r)-1))//125
        {
            cp=0;
            oo++;
        }
    }
ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);   
} 
for(x=0;x<100;x++)
{
    ii=0;
    i=0;
    for(i=0;i<10;i++)
    {
        if ((pperfm3r+x)->Name[i]>=0x20 && (pperfm3r+x)->Name[i]<=0x7f)
        sprintf(&nomemio[ii++],"%c", (pperfm3r+x)->Name[i]);
    }
    nomemio[ii]='\0';
    sprintf(string_comodo,"%2.2d %s",x,nomemio);
    SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
}

cp = 0;
return cp;
}


