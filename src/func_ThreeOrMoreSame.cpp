#include "rh.h"

void ThreeOrMoreSame(candy&c,int &score,int &totalscore,int &numball,int &numberoftimes)
{

    int countfalseright=0;
    int countfalseleft=0;
    bool next=true;
    int sameright=0;//�k��s��۾F�y���Ӽ�
    int sameleft=0;//����s��۾F�y���Ӽ�
    int scr[6];//same color right�N�n�������y���s�J�x�}��
    int scl[6];//same color left
    bool disappearright=false;
    bool disappearleft=false;
    for (int a=0;a<=5;a++)scr[a]=0;
    for (int a=0;a<=5;a++)scl[a]=0;



    for (int i=0;i<c.num-1;i++)
    {
    if (c.C[i].draw==true)
    {

    scr[0]=i;
    scl[0]=i;
    for(int n=1; n<MaxNum; n++)//the next ball on the right
    {
        while (next)//�P�_�U�@��draw==true���y����
        {
            if (c.C[i+n].draw==false)
            {
                i++;
                countfalseright++;
            }
            else {next=false;break;}
        }
        next=true;

        if(c.C[i-countfalseright].color==c.C[i+n].color)//�P�_�������y���C��O�_�@��
        {

            sameright++;
            scr[sameright]=i+n;
        }

        else break;
    }

    i=i-countfalseright;


    for(int n=1; n<MaxNum; n++)//the next ball on the left
    {
        while (next)//�P�_�U�@��draw=true���y����
        {
            if (c.C[i-n].draw==false)
            {
                i--;
                countfalseleft++;
            }
            else {next=false;break;}
        }
        next=true;

        if(c.C[i+countfalseleft].color==c.C[i-n].color)//�P�_�������y���C��O�_�@��
        {

            sameleft++;
            scl[sameleft]=i-n;
        }

        else break;
    }
    i=i+countfalseleft;

    if (sameright+sameleft+1>=3)//�p�G�۾F���y�h��T���~�n����
    {
        if (sameright>=1)
        {
            for (int a=0;a<=sameright-1;a++)
            {
                //�P�_�T���y�ۤ��ɤ~�n����
                if (((c.C[scr[a]].x-c.C[scr[a+1]].x)*(c.C[scr[a]].x-c.C[scr[a+1]].x)+(c.C[scr[a]].y-c.C[scr[a+1]].y)*(c.C[scr[a]].y-c.C[scr[a+1]].y))<800)
                {disappearright=true;}
                else {disappearright=false;break;}
            }
        }
        else disappearright=true;


        if (disappearright)
        {
            if (sameleft>=1)
            {
                for (int a=0;a<=sameleft-1;a++)
                {
                //�P�_�T���y�ۤ��ɤ~�n����
                if (((c.C[scl[a]].x-c.C[scl[a+1]].x)*(c.C[scl[a]].x-c.C[scl[a+1]].x)+(c.C[scl[a]].y-c.C[scl[a+1]].y)*(c.C[scl[a]].y-c.C[scl[a+1]].y))<400)
                disappearleft=true;
                else {disappearleft=false;break;}
                }
            }
            else disappearleft=true;
        }
        else disappearleft=false;



        if (disappearleft)
        {
            numball=scr[0];
            totalscore=totalscore+(sameright+sameleft+1)*(sameright+sameleft+1)*100;
            score=sameright+sameleft+1;
            for (int a=0;a<=sameright;a++)
            {c.C[scr[a]].draw=false;}
            numberoftimes=0;
            for (int a=0;a<=sameleft;a++)
            {c.C[scl[a]].draw=false;}
            numberoftimes=0;

        }


    }
    }
    countfalseright=0;
    countfalseleft=0;
    sameright=0;
    sameleft=0;
    }


}





