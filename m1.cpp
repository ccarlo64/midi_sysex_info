
void Combination_m1_print_detail(struct s_m1 *pperfm1, int x, char *string_comodo)
{

char ct[7][50]={"SINGLE","LAYER","SPLIT","VEL.SW","MULTI"};


Insert_text(hDetail, "Korg M1 ", true);
//Insert_text(hDetail, string_comodo, true);

sprintf(string_comodo," - Combination type %3.3d %s", (pperfm1+x)->Type, ct[(pperfm1+x)->Type]);
Insert_text(hDetail, string_comodo, true);

int i;

// effect
char nome_effetti[34][30]={"error",
"Hall","Hall","Hall","Room","Room","Live Stage","Early reflection 1","Early reflection 2","Early reflection 3","Stereo delay",
"Cross delay","Stereo chorus 1","Stereo chorus 2","Flanger","Flanger","Phase shifter 1","Phase shifter 2","Stereo tremoro 1","Stereo tremoro 2","3 band EQ",
"Over drive","Distorsion","Exciter","Symphonic Ensemble","Rotary Speaker","Delay/Hall","Delay/Room","Delay/Early Reflection","Delay/Delay","Delay/Chorus",
"Delay/Flanger","Delay/Phaser","Delay/Tremolo"};

sprintf(string_comodo," - Effect 1 Pattern n. %d (%s)", 1 + (pperfm1+x)->Effect.e_1_pattern, nome_effetti[(pperfm1+x)->Effect.e_1_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperfm1+x)->Effect.p1, x, string_comodo,1+(pperfm1+x)->Effect.e_1_pattern);

sprintf(string_comodo," - Effect 2 Pattern n. %d (%s)", 1 + (pperfm1+x)->Effect.e_2_pattern, nome_effetti[(pperfm1+x)->Effect.e_2_pattern + 1]);
Insert_text(hDetail, string_comodo, true);

M1_effect_Detail( (pperfm1+x)->Effect.p2, x, string_comodo, 1+(pperfm1+x)->Effect.e_2_pattern);
         
sprintf(string_comodo," - Effect 1 Balance left/right %d/%d", (pperfm1+x)->Effect.e_1_left_ch_bal, (pperfm1+x)->Effect.e_1_right_ch_bal);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Effect 2 Balance left/right %d/%d", (pperfm1+x)->Effect.e_2_left_ch_bal, (pperfm1+x)->Effect.e_2_right_ch_bal);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Output 3 pan %d", (pperfm1+x)->Effect.output_3_pan);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Output 4 pan %d", (pperfm1+x)->Effect.output_4_pan);
Insert_text(hDetail, string_comodo, true);
sprintf(string_comodo," - Effect I/O %d", (pperfm1+x)->Effect.e_i_o);
Insert_text(hDetail, string_comodo, true);

for(i=0;i<8;i++)
{
    Print_timbre( (pperfm1+x)->Timbre[i], i);
}

}


void M1_effect_Detail(union u_parameters sss, int x, char * string_comodo,int ne)
{
    switch (ne)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    {
    sprintf(string_comodo,"    >Reverb time  %d", sss.e1_2_3_4_5_6.Reverb_time);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e1_2_3_4_5_6.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Pre delay  %d", sss.e1_2_3_4_5_6.Pre_delay);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >ER level  %d", sss.e1_2_3_4_5_6.ER_level);
    Insert_text(hDetail, string_comodo, true);             
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e1_2_3_4_5_6.EQ_high), Trasforma_f4_0c(sss.e1_2_3_4_5_6.EQ_low));
    Insert_text(hDetail, string_comodo, true);    
          
    }
    break;

    case 7:
    case 8:
    case 9:
    {
    sprintf(string_comodo,"    >ER time  %d", sss.e7_8_9.ER_time);
    Insert_text(hDetail, string_comodo, true); 
    sprintf(string_comodo,"    >Pre delay  %d", sss.e7_8_9.Pre_delay);
    Insert_text(hDetail, string_comodo, true);      
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e7_8_9.EQ_high), Trasforma_f4_0c(sss.e7_8_9.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break;

    case 10:
    case 11:
    {
    sprintf(string_comodo,"    >Delay time left  %d", 
     sss.e10_11.Delay_time_left_l + 256 * sss.e10_11.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Delay time right  %d", 
     sss.e10_11.Delay_time_right_l + 256 * sss.e10_11.Delay_time_right_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e10_11.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e10_11.EQ_high), Trasforma_f4_0c(sss.e10_11.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp %d",sss.e10_11.High_damp);
    Insert_text(hDetail, string_comodo, true);
    }
    break;
    case 12:
    case 13:
    case 14:
    case 15:                  
    {
    sprintf(string_comodo,"    >Depth  %d", sss.e12_13_14_15.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e12_13_14_15.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >MG status  %d", sss.e12_13_14_15.MG_status);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e12_13_14_15.Feedback));
    Insert_text(hDetail, string_comodo, true);    
    sprintf(string_comodo,"    >Delay time  %d", sss.e12_13_14_15.Delay_time);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e12_13_14_15.EQ_high), Trasforma_f4_0c(sss.e12_13_14_15.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break;
    case 16:
    case 17:
    {
    sprintf(string_comodo,"    >Depth  %d", sss.e16_17.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e16_17.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >MG status  %d", sss.e16_17.MG_status);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e16_17.Feedback));
    Insert_text(hDetail, string_comodo, true);    
    sprintf(string_comodo,"    >Manual  %d", sss.e16_17.Manual);
    Insert_text(hDetail, string_comodo, true);
    }
    break; 
    
    case 18:
    case 19:
    {
    sprintf(string_comodo,"    >Depth  %d", sss.e18_19.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e18_19.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >MG status  %d", sss.e18_19.MG_status);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Shape  %d", sss.e18_19.Shape);
    Insert_text(hDetail, string_comodo, true);    
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e18_19.EQ_high), Trasforma_f4_0c(sss.e18_19.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break; 
    case 20:
    {
    sprintf(string_comodo,"    >Mid fc  %d", sss.e20.Mid_fc);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Mid Gain  %s", Trasforma_f4_0c(sss.e20.Mid_Gain));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Low fc/High fc  %d/%d", 
    sss.e20.Low_fc, sss.e20.High_fc);
    Insert_text(hDetail, string_comodo, true);    
    sprintf(string_comodo,"    >Gain High/Low  %s/%s",
     Trasforma_f4_0c(sss.e20.High_gain), Trasforma_f4_0c(sss.e20.Low_gain));
    Insert_text(hDetail, string_comodo, true);
    }
    break;                 
    case 21:
    {
    sprintf(string_comodo,"    >EQ Mid fc  %d", sss.e21.EQ_Mid_fc);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >EQ Mid Gain  %s", Trasforma_f4_0c(sss.e21.EQ_Mid_Gain));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Drive  %d", sss.e21.Drive);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Level  %d", sss.e21.Level);
    Insert_text(hDetail, string_comodo, true);    
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e21.EQ_high), Trasforma_f4_0c(sss.e21.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break;     
    case 22:
    {
    sprintf(string_comodo,"    >Distorsion  %d", sss.e22.Distorsion);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Level  %d", sss.e22.Level);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >EQ low gain  %s", Trasforma_f4_0c(sss.e22.EQ_low_gain));
    Insert_text(hDetail, string_comodo, true);
    }
    break;  
    case 23:
    {
    sprintf(string_comodo,"    >Blend  %s", Trasforma_f4_0c(sss.e23.Blend));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Emphatic_point  %d", sss.e23.Emphatic_point);
    Insert_text(hDetail, string_comodo, true); 
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e23.EQ_high), Trasforma_f4_0c(sss.e23.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break;       
    case 24:
    {
    sprintf(string_comodo,"    >Deph  %d", sss.e24.Depth);
    Insert_text(hDetail, string_comodo, true); 
    sprintf(string_comodo,"    >EQ High/Low  %s/%s",
     Trasforma_f4_0c(sss.e24.EQ_high), Trasforma_f4_0c(sss.e24.EQ_low));
    Insert_text(hDetail, string_comodo, true);
    }
    break;    
    case 25:
    {
    sprintf(string_comodo,"    >Deph  %d", sss.e25.Depth);
    Insert_text(hDetail, string_comodo, true); 
    sprintf(string_comodo,"    >Speed rate  %d", sss.e25.Speed_rate);
    Insert_text(hDetail, string_comodo, true); 
    }
    break;       
    case 26:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e26.Delay_time_left_l + 256 * sss.e26.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e26.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e26.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Reverber time  %d", sss.e26.Reverber_time);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp1  %d", sss.e26.High_damp1);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Pre delay  %d", sss.e26.Pre_delay);
    Insert_text(hDetail, string_comodo, true);
    }
    break;     
    case 27:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e27.Delay_time_left_l + 256 * sss.e27.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e27.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e27.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Reverber time  %d", sss.e27.Reverber_time);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp1  %d", sss.e27.High_damp1);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Pre delay  %d", sss.e27.Pre_delay);
    Insert_text(hDetail, string_comodo, true);
    }
    break;                              
    case 28:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e28.Delay_time_left_l + 256 * sss.e28.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e28.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e28.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >ER time  %d", sss.e28.ER_time);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Pre delay  %d", sss.e28.Pre_delay);
    Insert_text(hDetail, string_comodo, true);
    }
    break;                              
    case 29:
    {
    sprintf(string_comodo,"    >Delay time left %d", 
     sss.e29.Delay_time_left_l + 256 * sss.e29.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback left  %s", Trasforma_f4_0c(sss.e29.Feedback_left));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp left  %d", sss.e29.High_damp_left);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Delay time right %d", 
     sss.e29.Delay_time_right_l + 256 * sss.e29.Delay_time_right_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback right  %s", Trasforma_f4_0c(sss.e29.Feedback_right));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp right  %d", sss.e29.High_damp_right);
    Insert_text(hDetail, string_comodo, true);
    }
    break;                              
    case 30:
    case 31:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e30_31.Delay_time_left_l + 256 * sss.e30_31.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e30_31.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e30_31.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Depth  %d", sss.e30_31.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e30_31.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >MG status  %d", sss.e30_31.MS_status);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e30_31.Feedback1));
    Insert_text(hDetail, string_comodo, true);
    }
    break;  

    case 32:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e32.Delay_time_left_l + 256 * sss.e32.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e32.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e32.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Depth  %d", sss.e32.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e32.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e32.Feedback1));
    Insert_text(hDetail, string_comodo, true);
    }
    break;   
    
    case 33:
    {
    sprintf(string_comodo,"    >Delay time %d", 
     sss.e33.Delay_time_left_l + 256 * sss.e33.Delay_time_left_h);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Feedback  %s", Trasforma_f4_0c(sss.e33.Feedback));
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >High damp  %d", sss.e33.High_damp);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Depth  %d", sss.e33.Depth);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Speed  %d", sss.e33.Speed);
    Insert_text(hDetail, string_comodo, true);
    sprintf(string_comodo,"    >Shape  %s", Trasforma_f4_0c(sss.e33.Shape));
    Insert_text(hDetail, string_comodo, true);
    }
    break;                 
    default:
    break;
    }
}

unsigned char   LoadMem_M1_4c( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m14c *pperfm14c)
{
char nomemio[50],string_comodo[120];
unsigned char cp;
DWORD dwRead;

unsigned char banco;
unsigned char bitti;

ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);         
int ii,oo,x,i;
cp=0,oo=0;
while (dwRead>0) 
{         
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        (pperfm14c+oo)->Name[cp++]= banco;
        if (cp>(sizeof(s_m14c)-1))
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
        if ((pperfm14c+x)->Name[i]>=0x20 && (pperfm14c+x)->Name[i]<=0x7f)
            sprintf(&nomemio[ii++],"%c", (pperfm14c+x)->Name[i]);
    }
    nomemio[ii]='\0';
    sprintf(string_comodo,"%2.2d %s",x,nomemio);
    SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
}

cp = 0;
return cp;
}

unsigned char   LoadMem_M1_4d( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m1 *pperfm1)
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
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        
        (pperfm1+oo)->Name[cp++]= banco;
        if (cp>(sizeof(s_m1)-1))
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
        if ((pperfm1+x)->Name[i]>=0x20 && (pperfm1+x)->Name[i]<=0x7f)
        sprintf(&nomemio[ii++],"%c", (pperfm1+x)->Name[i]);
    }
    nomemio[ii]='\0';
    sprintf(string_comodo,"%2.2d %s",x,nomemio);
    SendMessage(htext, LB_ADDSTRING, 0, (LPARAM)string_comodo);
}

cp = 0;
return cp;
}



unsigned char   LoadMem_M1_50( int NUMERO_PATCH, HANDLE hFile, HWND htext, struct s_m150 *pperfm150)
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

bitti=0;
bResult=ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);         
int ii,oo,x,i;

cp=0,oo=0;
while  (dwRead>0) 
{      
    int c7=0;
    for(c7=0;c7<7;c7++)
    {
        bResult=ReadFile(hFile, &banco, sizeof(banco), &dwRead, NULL);   
        banco = banco | ( (bitti<<(7-c7)) & 0x80);
        (pperfm150)->global[oo++]= banco;
    }
    bResult=ReadFile(hFile, &bitti, sizeof(bitti), &dwRead, NULL);   
} 

//sprintf(string_comodo,"%d, size t350 %d %d %d %d",oo,ds,sizeof(s_m1),sizeof(s_m14c),sizeof(s_m150));
//MessageBox(NULL, string_comodo, string_comodo,MB_OK);        

if (MessageBox(NULL, "yes=Load Combinations   no=Load Programs", "FILE ALL DATA",MB_YESNO)==IDYES)
{
    cp=0x4d;
    struct s_m1 *cc;
    cc = &pperfm150->combi[0];
    
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
    struct s_m14c *cc;
    cc = &pperfm150->progra[0];
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
//cp = 0;
return cp;
}





void verso_M1(struct s_header_sysex, 
  struct s_m1 *pperfm1, struct s_m3r *pperfm3r, struct s_t34d *pperft34d,  
  struct s_m14c *pperfm14c, struct s_m3r4c *pperfm3r4c, int verso, unsigned char tipo)
{
DWORD dwRead,dwWritten;
HANDLE fpw;
char filen[50];
unsigned char oldid,oldms;

oldid=header_sysex.device_id;
oldms=header_sysex.message_type;

switch (oldid)
{
    case M1:
        sprintf(filen,"M1_in_M1");
        break;
    case M3R:
        sprintf(filen,"M3R_in_M1");
        break;
    case T3:
        sprintf(filen,"T3_in_M1");
        break;
    case WAVESTATION:
        sprintf(filen,"WA_in_M1");
        break;
    default:
        sprintf(filen,"device_unknow");
        break;
}        
if (tipo==0x4d)
    strcat(filen,"_combination.syx");
if (tipo==0x4c)
    strcat(filen,"_program.syx");    
    
fpw = CreateFile(filen, GENERIC_WRITE, 0, 0,
              CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

header_sysex.device_id=verso;
header_sysex.message_type=0x4d;

if(oldid==M3R && tipo==0x4c)
{
    azzera_m14c();
    header_sysex.message_type=0x4c;
}
WriteFile(fpw, &header_sysex, sizeof(header_sysex), &dwWritten, NULL);

// riscrivi m1 file
int i;
int q=1;
unsigned char b;
unsigned char scrivi[7];
int x;
unsigned char a;
int cp;

x=0;
a=0;
cp=0;

WriteFile(fpw, &a, sizeof(a), &dwWritten, NULL);

while (x<100)
    {
    q=1;
    b=0;
    for(i=0;i<7;i++)
    {
        if(oldid==M1 && tipo==0x4d)
            a = (pperfm1+x)->Name[cp++];
        if(oldid==M3R && tipo==0x4d)
            a = (pperfm3r+x)->Name[cp++];
        if(oldid==T3 && tipo==0x4d)
            a = (pperft34d+x)->Name[cp++];
        if(oldid==WAVESTATION && tipo==0x4d)
            a = (pperft34d+x)->Name[cp++];

        if(oldid==M3R && tipo==0x4c)
            a = (pperfm14c+x)->Name[cp++];

        if ((a & 0x80)>0)
            b = b | (q<<i);
        scrivi[i] = a & 0x7f;

        if (tipo==0x4d)
        {
            if (cp>(sizeof(s_m1)-1))
            {
            cp=0;
            x++;
            } 
        }
        if (tipo==0x4c)
        {
            if (cp>(sizeof(s_m14c)-1))
            {
            cp=0;
            x++;
            } 
        }

        if (x>=100)
            break;
    }

    a = b;
    WriteFile(fpw, &a, sizeof(a), &dwWritten, NULL);


    if (x>=100)
    {
          i++;
        for(cp=0;cp<i;cp++)
        {
            a= scrivi[cp];
            WriteFile(fpw, &a, sizeof(a), &dwWritten, NULL);
        }    
    
    }
    else
    {
        for(i=0;i<7;i++)
        {
            a= scrivi[i];
            WriteFile(fpw, &a, sizeof(a), &dwWritten, NULL);
        }    
    
    }   
}

a= 0xf7;
WriteFile(fpw, &a, sizeof(a), &dwWritten, NULL);
    
CloseHandle(fpw);

}

void azzera_m14c(void)
{
int x;
for(x=0;x<100;x++)
{

//struct s_m14c ppp;

// azzera struttura m1 program //
for(i=0;i<sizeof((pperfm14c+x)->Name);i++)
    (pperfm14c+x)->Name[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator);i++)
    (pperfm14c+x)->oscillator.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->pitch_mg);i++)
    (pperfm14c+x)->pitch_mg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->cutoff_mg);i++)
    (pperfm14c+x)->cutoff_mg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->after_touch);i++)
    (pperfm14c+x)->after_touch.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->joystick);i++)
    (pperfm14c+x)->joystick.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->effect_parameter);i++)
    (pperfm14c+x)->effect_parameter.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vdf_1);i++)
    (pperfm14c+x)->oscillator_1.vdf_1.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vdf_1_eg);i++)
    (pperfm14c+x)->oscillator_1.vdf_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vda_1);i++)
    (pperfm14c+x)->oscillator_1.vda_1.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vda_1_eg);i++)
    (pperfm14c+x)->oscillator_1.vda_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.pitch_eg);i++)
    (pperfm14c+x)->oscillator_1.pitch_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.other);i++)
    (pperfm14c+x)->oscillator_1.other.a[i]=0;

for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.vdf_1);i++)
    (pperfm14c+x)->oscillator_2.vdf_1.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.vdf_1_eg);i++)
    (pperfm14c+x)->oscillator_2.vdf_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.vda_1);i++)
    (pperfm14c+x)->oscillator_2.vda_1.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.vda_1_eg);i++)
    (pperfm14c+x)->oscillator_2.vda_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.pitch_eg);i++)
    (pperfm14c+x)->oscillator_2.pitch_eg.a[i]=0;
for(i=0;i<sizeof((pperfm14c+x)->oscillator_2.other);i++)
    (pperfm14c+x)->oscillator_2.other.a[i]=0;
   

//struct s_m3r4c xxx;
/*
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator);i++)
    (pperfm3r4c+x)->oscillator.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->pitch_mg);i++)
    (pperfm3r4c+x)->pitch_mg.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->cutoff_mg);i++)
    (pperfm3r4c+x)->cutoff_mg.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->after_touch);i++)
    (pperfm3r4c+x)->after_touch.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->joystick);i++)
    (pperfm3r4c+x)->joystick.a[i]=0;

for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.vdf_1);i++)
    (pperfm3r4c+x)->oscillator_1.vdf_1.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.vdf_1_eg);i++)
    (pperfm3r4c+x)->oscillator_1.vdf_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.vda_1);i++)
    (pperfm3r4c+x)->oscillator_1.vda_1.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.vda_1_eg);i++)
    (pperfm3r4c+x)->oscillator_1.vda_1_eg.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.pitch_eg);i++)
    (pperfm3r4c+x)->oscillator_1.pitch_eg.a[i]=0;
for(i=0;i<sizeof((pperfm3r4c+x)->oscillator_1.other);i++)
    (pperfm3r4c+x)->oscillator_1.other.a[i]=0;

*/
// ---- convert


// inserisce in m1 i dati del m3r //
for(i=0;i<sizeof((pperfm14c+x)->Name);i++)
    (pperfm14c+x)->Name[i]=(pperfm3r4c+x)->Name[i];

(pperfm14c+x)->oscillator.a[0]=(pperfm3r4c+x)->oscillator.a[0];
(pperfm14c+x)->oscillator.a[1]=(pperfm3r4c+x)->oscillator.a[1];
(pperfm14c+x)->oscillator.a[2]=(pperfm3r4c+x)->oscillator.a[2];
(pperfm14c+x)->oscillator.a[3]=(pperfm3r4c+x)->oscillator.a[3];
(pperfm14c+x)->oscillator.a[9]=(pperfm3r4c+x)->oscillator.a[4];

for(i=0;i<sizeof((pperfm14c+x)->pitch_mg);i++)
    (pperfm14c+x)->pitch_mg.a[i]=(pperfm3r4c+x)->pitch_mg.a[i];

for(i=0;i<sizeof((pperfm14c+x)->cutoff_mg);i++)
    (pperfm14c+x)->cutoff_mg.a[i]=(pperfm3r4c+x)->cutoff_mg.a[i];

for(i=0;i<sizeof((pperfm14c+x)->after_touch);i++)
    (pperfm14c+x)->after_touch.a[i]=(pperfm3r4c+x)->after_touch.a[i];

for(i=0;i<sizeof((pperfm14c+x)->joystick);i++)
    (pperfm14c+x)->joystick.a[i]=(pperfm3r4c+x)->joystick.a[i];
    
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vdf_1);i++)
    (pperfm14c+x)->oscillator_1.vdf_1.a[i]=(pperfm3r4c+x)->oscillator_1.vdf_1.a[i];

for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vdf_1_eg);i++)
    (pperfm14c+x)->oscillator_1.vdf_1_eg.a[i]=(pperfm3r4c+x)->oscillator_1.vdf_1_eg.a[i];
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vda_1);i++)
    (pperfm14c+x)->oscillator_1.vda_1.a[i]=(pperfm3r4c+x)->oscillator_1.vda_1.a[i];
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.vda_1_eg);i++)
    (pperfm14c+x)->oscillator_1.vda_1_eg.a[i]=(pperfm3r4c+x)->oscillator_1.vda_1_eg.a[i];
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.pitch_eg);i++)
    (pperfm14c+x)->oscillator_1.pitch_eg.a[i]=(pperfm3r4c+x)->oscillator_1.pitch_eg.a[i];
for(i=0;i<sizeof((pperfm14c+x)->oscillator_1.other);i++)
    (pperfm14c+x)->oscillator_1.other.a[i]=(pperfm3r4c+x)->oscillator_1.other.a[i];


}
}




