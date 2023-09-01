#include <graphics.h>
#include <stdio.h>

class MainMenu
{
public:
    int s1 = 6, s2 = 6, s3 = 6;
    int x1 = 0, x2 = 0, x3 = 0;
    int y1 = 0, y2 = 0, y3 = 0;
    int PilihanMenu = 0;
    int close = 1;
    int level = 0;

    void SetMenu()
    {
        setfillstyle(1,GREEN);
        bar(0*close,0*close,1920*close,1080*close);
        settextstyle(10, 0, 9);
        outtextxy(450*close, 250*close, "Terobos Laju Cepat");
        settextstyle(10, 0, s1);
        outtextxy(885*close+x1, 500*close+y1, "Mulai");
        settextstyle(10, 0, s2);
        outtextxy(838*close+x2, 600*close+y2, "Petunjuk");
        settextstyle(10, 0, s3);
        outtextxy(865*close+x3, 700*close+y3, "Keluar");
    }

    void SetPetunjuk()
    {
        rectangle(80,380,630,650);
        settextstyle(10, 0, 3);
        outtextxy(100, 400, "Petunjuk Permainan :");
        settextstyle(10, 0, 3);
        outtextxy(100, 450, "- Panah Kanan : Gerak Mobil Ke Kanan");
        settextstyle(10, 0, 3);
        outtextxy(100, 500, "- Panah Kiri : Gerak Mobil Ke Kiri");
        settextstyle(10, 0, 3);
        outtextxy(100, 550, "- Klik Mouse Kiri : Tembak Peluru");
        settextstyle(10, 0, 3);
        outtextxy(100, 600, "- Escape : Pause Game");
        settextstyle(10, 0, 3);
        outtextxy(130, 800, "Klik Escape untuk Kembali Ke Menu");
    }

    void PilihMenu()
    {
        if(GetAsyncKeyState(VK_DOWN) & (0x8000) != 0)
        {
            if(PilihanMenu < 3)
            {
                PilihanMenu = PilihanMenu + 1;
            }
        }

        if(GetAsyncKeyState(VK_UP) & (0x8000) != 0)
        {
            if(PilihanMenu > 1)
            {
                PilihanMenu = PilihanMenu - 1;
            }
        }
        if(PilihanMenu==1)
        {
            s1 = 8; s2 = 6; s3 = 6;
            x1 = -35; x2 = 0; x3 = 0;
            y1 = -12; y2 = 0; y3 = 0;
        }
        if(PilihanMenu==2)
        {
            s1 = 6; s2 = 8; s3 = 6;
            x1 = 0; x2 = -59; x3 = 0;
            y1 = 0; y2 = -12; y3 = 0;
        }
        if(PilihanMenu==3)
        {
            s1 = 6; s2 = 6; s3 = 8;
            x1 = 0; x2 = 0; x3 = -42;
            y1 = 0; y2 = 0; y3 = -12;
        }
    }

    void SetPilihanMenu()
    {
        if(PilihanMenu == 1)
        {
            if(GetAsyncKeyState(VK_RETURN) & (0x8000) != 0)
            {
                close = -5;
                level = 1;
            }
        }

        if(PilihanMenu == 2)
        {
            if(GetAsyncKeyState(VK_RETURN) & (0x8000) != 0)
            {
                close = -5;
                level = -1;
            }
        }

        if(PilihanMenu == 3)
        {
            if(GetAsyncKeyState(VK_RETURN))
            {
                closegraph();
            }
        }
    }
};

class Loading
{
public:
    int Start=0;
    int blink=0;
    char level[9999];
    void Set(int setlevel, int tx)
    {
        settextstyle(10, 0, 6);
        sprintf(level, "level %d", setlevel);
        outtextxy(855-tx, 400, level);
        settextstyle(10, 0, 4);
        outtextxy(848, 500+blink, "Harap Tunggu");
        rectangle(750,570,1170,600);
    }

    void LoadingBar(int x)
    {
        x=x+1;
        setfillstyle(1,11);
        bar(750,570,750+x,600);
    }

    void LoadingCar(float LBy1)
    {
        setfillstyle(1,11);
        bar(750,570,750+LBy1,600);
    }
};

class Score
{
public:
    void Set()
    {
        setfillstyle(1,GREEN);
        bar(0,0,1920,1080);
        settextstyle(10, 0, 8);
        outtextxy(720, 120, "Papan Score");
        rectangle(360,250,1560,950);
    }
    void SetScore(int level, int sy, int score, int jarak, int total)
    {
        char nilailevel[5];
        char nilaiscore[9999];
        char nilaijarak[9999];
        char nilaitotal[9999];

        settextstyle(10, 0, 5);
        sprintf(nilailevel, "Level %d :", level);
        outtextxy(500, 300+sy, nilailevel);
        sprintf(nilaiscore, "+Poin = %d", score);
        outtextxy(750, 300+sy, nilaiscore);
        sprintf(nilaijarak, "+Menang = %d", jarak);
        outtextxy(750, 350+sy, nilaijarak);
        sprintf(nilaitotal, "Score = %d", total);
        outtextxy(1100, 300+sy, nilaitotal);
    }

    void TotalScore(int total)
    {
        char totalscore[99999];

        setfillstyle(1,15);
        bar(1050,815,1450,825);
        bar(1425,770,1430,800);
        bar(1412.5,782.5,1442.5,787.5);
        settextstyle(10, 0, 5);
        sprintf(totalscore, "Score = %d", total);
        outtextxy(1100, 850, totalscore);
    }
};

class PauseMenu
{
public:

    int s1 = 6, s2 = 6, s3 = 6, s4 = 6;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
    int PilihanPause = 0;
    int PilihanYakin = 0;
    int yakin=0;
    int pause=0;
    int menu=1;

    void setPause()
    {
        if(GetAsyncKeyState(VK_ESCAPE)& 0x8000)
        {
            pause=1;
        }
        if(GetAsyncKeyState(VK_DELETE))
        {
            pause=0;
        }
    }

    void Draw()
    {
        settextstyle(10, 0, 9);
        outtextxy(605, 250, "Game Berhenti");
        settextstyle(10, 0, s1);
        outtextxy(820+x1, 500+y1, "Lanjutkan");
        settextstyle(10, 0, s2);
        outtextxy(735+x2, 600+y2, "Kembali ke Menu");
    }

    void PilihPause()
    {
        if(GetAsyncKeyState(VK_DOWN))
        {
            PilihanPause = 2;
            s1 = 6; s2 = 8;
            x1 = 0; x2 = -115;
            y1 = 0; y2 = -12;
        }

        if(GetAsyncKeyState(VK_UP))
        {
            PilihanPause = 1;
            s1 = 8; s2 = 6;
            x1 = -65; x2 = 0;
            y1 = -12; y2 = 0;
        }
    }

    void SetPilihanPause()
    {
        if(PilihanPause == 1)
        {
            if(GetAsyncKeyState(VK_RETURN))
            {
                pause=0;
                PilihanPause=0;
            }
        }
        if(PilihanPause == 2)
        {
            if(GetAsyncKeyState(VK_RETURN))
            {
                pause=2;
                PilihanPause=0;
            }
        }
    }

    void DrawYakin()
    {
        settextstyle(10, 0, 7);
        outtextxy(450, 300, "Anda Yakin Kembali ke Menu ?");
        settextstyle(10, 0, 3);
        outtextxy(730, 400, "Semua poin game akan disetel ulang!");
        settextstyle(10, 0, s3);
        outtextxy(780+x3, 530+y3, "Ya");
        settextstyle(10, 0, s4);
        outtextxy(980+x4, 530+y4, "Tidak");
    }

    void PilihYakin()
    {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            PilihanYakin = 2;
            s3 = 6; s4 = 8;
            x3 = 0; x4 = -40;
            y3 = 0; y4 = -12;
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            PilihanYakin = 1;
            s3 = 8; s4 = 6;
            x3 = -20; x4 = 0;
            y3 = -12; y4 = 0;
        }
    }

    void SetPilihanYakin()
    {
        if(PilihanYakin == 1)
        {
            if(GetAsyncKeyState(VK_RETURN))
            {
                pause=3;
                //s3=9;
                PilihanYakin=0;
            }
        }
        if(PilihanYakin == 2)
        {
            if(GetAsyncKeyState(VK_RETURN))
            {
                pause=1;
                //closegraph();
                PilihanYakin=0;
            }
        }
    }

};

class CGarisLine
{
public:
    float px;
    float py;
    float ay;


    void Set(float X,float Y,float dy)
    {
        px=X;
        py=Y;
    }
    void Gerak(int v)
    {
        py=py+v;
        if (py>1120)
        {
            py =-80;
        }
    }
    void Draw()
    {
        setfillstyle(1,15);
        bar(-7.5+(int)px,-40+(int)py,7.5+(int)px,40+(int)py);
    }
};

class SetJalan : public CGarisLine
{
public:
    CGarisLine gi1,gi2,gi3,gi4,gi5,gi6,gi7,gi8,gi9,gi10;
    CGarisLine ga1,ga2,ga3,ga4,ga5,ga6,ga7,ga8,ga9,ga10;
    void setpos()
    {
        gi1.Set(870,-40,1);gi2.Set(870,80,1);
        gi3.Set(870,200,1);gi4.Set(870,320,1);
        gi5.Set(870,440,1);gi6.Set(870,560,1);
        gi7.Set(870,680,1);gi8.Set(870,800,1);
        gi9.Set(870,920,1);gi10.Set(870,1040,1);

        ga1.Set(1050,-40,1);ga2.Set(1050,80,1);
        ga3.Set(1050,200,1);ga4.Set(1050,320,1);
        ga5.Set(1050,440,1);ga6.Set(1050,560,1);
        ga7.Set(1050,680,1);ga8.Set(1050,800,1);
        ga9.Set(1050,920,1);ga10.Set(1050,1040,1);
    }

    void drawjalan(int v)
    {
            setfillstyle(1,8);
            bar(690,0,1230,1080);

            gi1.Draw();gi2.Draw();gi3.Draw();gi4.Draw();gi5.Draw();
            gi6.Draw();gi7.Draw();gi8.Draw();gi9.Draw();gi10.Draw();
            gi1.Gerak(v);gi2.Gerak(v);gi3.Gerak(v);gi4.Gerak(v);gi5.Gerak(v);
            gi6.Gerak(v);gi7.Gerak(v);gi8.Gerak(v);gi9.Gerak(v);gi10.Gerak(v);

            ga1.Draw();ga2.Draw();ga3.Draw();ga4.Draw();ga5.Draw();
            ga6.Draw();ga7.Draw();ga8.Draw();ga9.Draw();ga10.Draw();
            ga1.Gerak(v);ga2.Gerak(v);ga3.Gerak(v);ga4.Gerak(v);ga5.Gerak(v);
            ga6.Gerak(v);ga7.Gerak(v);ga8.Gerak(v);ga9.Gerak(v);ga10.Gerak(v);
    }
};

class Mobil
{
public:
    int MMx = 960;
    int MMy = 900;
    int MLx1, MLx2, MLx3;
    int MLy1, MLy2, MLy3;
    int Px1, Px2, Px3;
    int Py1, Py2, Py3;
    float s = 0;
    int setNyawa = 3;
    int poinNambah = 0;
    int Ketembak1 = 0; int Ketembak2 = 0; int Ketembak3 = 0;
    int Ketembak4 = 0; int Ketembak5 = 0; int Ketembak6 = 0;
    int Ketabrak = 0;
    int countmm=0;
    int countspmm=0;
    int sy=0;

    void Init()
    {
        MLx1=780; MLx2=960; MLx3=1140;
        Px1=780; Px2=960; Px3=1140;
    }

    void HitBox()
    {
        if (  MMx > 685 && MMx < 880)
        {
            if (MLy1 > 760 && MLy1 < 1015)
            {
               MLy1 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
        if (  MMx > 860 && MMx < 1057)
        {
            if (MLy2 > 760 && MLy2 < 1015)
            {
               MLy2 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
        if (  MMx > 1040 && MMx < 1235)
        {
            if (MLy3 > 760 && MLy3 < 1015)
            {
               MLy3 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
        if (  MMx > 710 && MMx < 848)
        {
            if (Py1 > 815 && Py1 < 960)
            {
               Py1 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
        if (  MMx > 890 && MMx < 1028)
        {
            if (Py2 > 815 && Py2 < 960)
            {
               Py2 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
        if (  MMx > 1070 && MMx < 1198)
        {
            if (Py3 > 815 && Py3 < 960)
            {
               Py3 = 1200;
               setNyawa = setNyawa - 1;
               Ketabrak = 1;
            }
        }
    }

    void ResetMobil()
    {
        s = 0;
        MMx = 960; MMy = 900;
        MLy1 = -100; MLy2 = -100; MLy3 = -100;
        Py1 = -100; Py2 = -100; Py3 = -100;
    }

    void MMMove()
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            if(MMx>735)
            {
                MMx-=5;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if(MMx<1175)
            {
                MMx+=5;
            }
        }
    }

    void RespawnKetabrak()
    {
        int countspm=0;
        countspmm=countspmm+1;
        s=0;
        if(countspmm==10)
        {
            s=2.5;
            Ketabrak=Ketabrak+1;
            countspmm=0;
        }

    }
};

class Penghalang1 : public Mobil
{
public:
    void Draw()
    {
        setfillstyle(1,9);
        bar(-20*s+Px1,-20*s+Py1,20*s+Px1,20*s+Py1);
        setfillstyle(1,4);
        circle(0*s+Px1,0*s+Py1,15*s);
        floodfill(0*s+Px1,0*s+Py1,15);
        setfillstyle(1,15);
        bar(-10*s+Px1,-2.5*s+Py1,10*s+Px1,2.5*s+Py1);
    }

    void Set(int setx, int sety, float sets)
    {
        Px1=setx;
        Py1=sety;
        s=sets;
    }

    void Move1()
    {
        if(Py1 < 3100)
        {
            Py1 += 5;
        }
    }

    void resetPy1()
    {
        Py1 = 1500;
        if(Py1 > 1400)
        {
            return;
        }
    }
};

class Penghalang2 : public Mobil
{
public:
    void Draw()
    {
        setfillstyle(1,9);
        bar(-20*s+Px2,-20*s+Py2,20*s+Px2,20*s+Py2);
        setfillstyle(1,4);
        circle(0*s+Px2,0*s+Py2,15*s);
        floodfill(0*s+Px2,0*s+Py2,15);
        setfillstyle(1,15);
        bar(-10*s+Px2,-2.5*s+Py2,10*s+Px2,2.5*s+Py2);
    }

    void Set(int setx, int sety, float sets)
    {
        Px2=setx;
        Py2=sety;
        s=sets;
    }

    void Move2()
    {
        Py2 += 5;
        if(Py2 > 1100)
        {
            return;
        }
    }

    void resetPy2()
    {
        Py2 = 1500;
        if(Py2 > 1400)
        {
            return;
        }
    }
};

class Penghalang3 : public Mobil
{
public:
    void Draw()
    {
        setfillstyle(1,9);
        bar(-20*s+Px3,-20*s+Py3,20*s+Px3,20*s+Py3);
        setfillstyle(1,4);
        circle(0*s+Px3,0*s+Py3,15*s);
        floodfill(0*s+Px3,0*s+Py3,15);
        setfillstyle(1,15);
        bar(-10*s+Px3,-2.5*s+Py3,10*s+Px3,2.5*s+Py3);
    }

    void Set(int setx, int sety, float sets)
    {
        Px3=setx;
        Py3=sety;
        s=sets;
    }

    void Move3()
    {
        Py3 += 5;
        if(Py3 > 1100)
        {
            return;
        }
    }

    void resetPy3()
    {
        Py3 = 1500;
        if(Py3 > 1400)
        {
            return;
        }
    }
};

class MainMobil : public Mobil
{
public:
    void Draw()
    {
        setfillstyle(1,14);
        bar(-12.5*s+MMx,-30*s+MMy,17.5*s+MMx,30*s+MMy);
        setfillstyle(1,7);
        bar(-9*s+MMx,-12.3*s+MMy,14.3*s+MMx,0*s+MMy);
        setfillstyle(1,7);
        bar(-9*s+MMx,19.9*s+MMy,14.3*s+MMx,25.9*s+MMy);
        setfillstyle(1,0);
        bar(-17.5*s+MMx,-20*s+MMy,-12.5*s+MMx,-5*s+MMy);
        bar(17.5*s+MMx,-20*s+MMy,22.5*s+MMx,-5*s+MMy);
        bar(-17.5*s+MMx,10*s+MMy,-12.5*s+MMx,25*s+MMy);
        bar(17.5*s+MMx,10*s+MMy,22.5*s+MMx,25*s+MMy);
    }

    void DrawMiring()
    {
        setfillstyle(1,14);
        bar(-27.5*s+MMx,-15*s+MMy,32.5*s+MMx,15*s+MMy);
        setfillstyle(1,7);
        bar(2.5*s+MMx,-11.5*s+MMy,14.8*s+MMx,11.44*s+MMy);
        setfillstyle(1,7);
        bar(-23.4*s+MMx,-11.5*s+MMy,-16.8*s+MMx,11.44*s+MMy);
        setfillstyle(1,0);
        bar(7.5*s+MMx,-20*s+MMy,22.5*s+MMx,-15*s+MMy);
        bar(7.5*s+MMx,15*s+MMy,22.5*s+MMx,20*s+MMy);
        bar(-22.5*s+MMx,-20*s+MMy,-7.5*s+MMx,-15*s+MMy);
        bar(-22.5*s+MMx,15*s+MMy,-7.5*s+MMx,20*s+MMy);
    }
};

class MobilLawan1 : public Mobil
{
public:
    void Draw()
    {
        //s=2.5;
        setfillstyle(1,5);
        bar(-12.5*s+MLx1,-30*s+MLy1,17.5*s+MLx1,30*s+MLy1);
        setfillstyle(1,7);
        bar(-9*s+MLx1,12.3*s+MLy1,14.3*s+MLx1,0*s+MLy1);
        setfillstyle(1,7);
        bar(-9*s+MLx1,-19.9*s+MLy1,14.3*s+MLx1,-25.9*s+MLy1);
        setfillstyle(1,0);
        bar(-17.5*s+MLx1,-25*s+MLy1,-12.5*s+MLx1,-10*s+MLy1);
        bar(17.5*s+MLx1,-25*s+MLy1,22.5*s+MLx1,-10*s+MLy1);
        bar(-17.5*s+MLx1,5*s+MLy1,-12.5*s+MLx1,20*s+MLy1);
        bar(17.5*s+MLx1,5*s+MLy1,22.5*s+MLx1,20*s+MLy1);
    }

    void Set(int setx, int sety, float sets)
    {
        MLx1=setx;
        MLy1=sety;
        s=sets;
    }

    void Move1()
    {
        if(MLy1<1300)
        {
            MLy1 += 5;
        }
    }

    void resetMLy1()
    {
        MLy1 = 1500;
    }
};

class MobilLawan2 : public Mobil
{
public:
    void Draw()
    {
        //s=2.5;
        setfillstyle(1,5);
        bar(-12.5*s+MLx2,-30*s+MLy2,17.5*s+MLx2,30*s+MLy2);
        setfillstyle(1,7);
        bar(-9*s+MLx2,12.3*s+MLy2,14.3*s+MLx2,0*s+MLy2);
        setfillstyle(1,7);
        bar(-9*s+MLx2,-19.9*s+MLy2,14.3*s+MLx2,-25.9*s+MLy2);
        setfillstyle(1,0);
        bar(-17.5*s+MLx2,-25*s+MLy2,-12.5*s+MLx2,-10*s+MLy2);
        bar(17.5*s+MLx2,-25*s+MLy2,22.5*s+MLx2,-10*s+MLy2);
        bar(-17.5*s+MLx2,5*s+MLy2,-12.5*s+MLx2,20*s+MLy2);
        bar(17.5*s+MLx2,5*s+MLy2,22.5*s+MLx2,20*s+MLy2);
    }

    void Set(int setx, int sety, float sets)
    {
        MLx2=setx;
        MLy2=sety;
        s=sets;
    }

    void Move2()
    {
        MLy2 += 5;
        if(MLy2 > 1100)
        {
            return;
        }
    }

    void resetMLy2()
    {
        MLy2 = 1500;
        if(MLy2 > 1400)
        {
            return;
        }
    }
};

class MobilLawan3 : public Mobil
{
public:
    void Draw()
    {
        setfillstyle(1,5);
        bar(-12.5*s+MLx3,-30*s+MLy3,17.5*s+MLx3,30*s+MLy3);
        setfillstyle(1,7);
        bar(-9*s+MLx3,12.3*s+MLy3,14.3*s+MLx3,0*s+MLy3);
        setfillstyle(1,7);
        bar(-9*s+MLx3,-19.9*s+MLy3,14.3*s+MLx3,-25.9*s+MLy3);
        setfillstyle(1,0);
        bar(-17.5*s+MLx3,-25*s+MLy3,-12.5*s+MLx3,-10*s+MLy3);
        bar(17.5*s+MLx3,-25*s+MLy3,22.5*s+MLx3,-10*s+MLy3);
        bar(-17.5*s+MLx3,5*s+MLy3,-12.5*s+MLx3,20*s+MLy3);
        bar(17.5*s+MLx3,5*s+MLy3,22.5*s+MLx3,20*s+MLy3);
    }

    void Set(int setx, int sety, float sets)
    {
        MLx3=setx;
        MLy3=sety;
        s=sets;
    }

    void Move3()
    {
        MLy3 += 5;
        if(MLy3 > 1100)
        {
            return;
        }
    }

    void resetMLy3()
    {
        MLy3 = 1500;
        if(MLy3 > 1400)
        {
            return;
        }
    }
};

class CTembak : public Mobil
{
public:

    float PosX;
    float PosY;
    float PeluruX[100], PeluruY[100], FP[100];

    void Init()
    {
        PosX = 0;
        PosY = 0;
        for (int i=0; i<100; i++)
        {
            PeluruX[i]=0;
            PeluruY[i]=0;
            FP[i]=0;
        }
    }
    void Tembak()
    {
        //if (GetAsyncKeyState(VK_SPACE))
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            for (int i=0; i<100; i++)
            {
                if (FP[i]==0)
                {
                    FP[i]=1;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;

                    return;
                }
            }
        }
    }

    void PeluruKeAtas()
    {
        for (int i=0;i<100;i++)
        {
            if (FP[i]==1)
            {
                PeluruY[i]=PeluruY[i]-10;
                setfillstyle(1,4);
                circle(PeluruX[i],PeluruY[i],10);
                floodfill(PeluruX[i],PeluruY[i],15);
                if (PeluruY[i]<0)
                {
                    FP[i]=0;
                }
            }
        }
    }

    void SetPosPeluru(float x, float y)
    {
        PosX=x;
        PosY=y;
    }

    void HitBoxPeluru(float MLy11, float MLy2, float MLy3, float Py1, float Py2, float Py3)
    {
        for (int i=0;i<100;i++)
        {
            if (  PeluruX[i] > 730 && PeluruX[i] < 840)
            {
                if (PeluruY[i] < MLy11+50 && PeluruY[i] > MLy11-50)
                {
                    Ketembak1=1;
                    poinNambah = poinNambah + 1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
            if (  PeluruX[i] > 915 && PeluruX[i] < 1020)
            {
                if (PeluruY[i] < MLy2+50 && PeluruY[i] > MLy2-50)
                {
                    Ketembak2=1;
                    poinNambah = poinNambah + 1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
            if (  PeluruX[i] > 1094 && PeluruX[i] < 1200)
            {
                if (PeluruY[i] < MLy3+50 && PeluruY[i] > MLy3-50)
                {
                    Ketembak3=1;
                    poinNambah = poinNambah + 1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
            if (  PeluruX[i] > 750 && PeluruX[i] < 808)
            {
                if (PeluruY[i] < Py1+50 && PeluruY[i] > Py1-50)
                {
                    Ketembak4=1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
            if (  PeluruX[i] > 930 && PeluruX[i] < 988)
            {
                if (PeluruY[i] < Py2+50 && PeluruY[i] > Py2-50)
                {
                    Ketembak5=1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
            if (  PeluruX[i] > 1110 && PeluruX[i] < 1158)
            {
                if (PeluruY[i] < Py3+50 && PeluruY[i] > Py3-50)
                {
                    Ketembak6=1;
                    FP[i]=0;
                    PeluruX[i]=PosX;
                    PeluruY[i]=PosY;
                }
            }
        }
    }
};

class Jarak
{
public:
    int maks=0; char nilaimaks[9999];
    int jarak=0; char poinjarak[9999];
    int setnilai=0; char nilaisetnilai[9999];
    float y; int nilai;

    void Set(int maks)
    {
        rectangle(1800,190,1850,890);
        settextstyle(3, 0, 4);
        outtextxy(1777, 100, "Target");
        outtextxy(1786, 900, "Jarak");
        sprintf(nilaimaks, "%d", maks);
        outtextxy(1788, 142, nilaimaks);
    }

    void PoinJarak(float nilai)
    {

        if(nilai>=0)
        {
            jarak=jarak+nilai;
        }
        sprintf(poinjarak, "%d", jarak);
        if(jarak<100)
        {
            settextstyle(3, 0, 4);
            outtextxy(1805, 935, poinjarak);
        }
        else if(jarak>99 && jarak<1000)
        {
            settextstyle(3, 0, 4);
            outtextxy(1796, 935, poinjarak);
        }
        else if (jarak>999)
        {
            settextstyle(3, 0, 4);
            outtextxy(1789, 935, poinjarak);
        }
    }

    void SetPoin(int setnilai)
    {
        sprintf(nilaisetnilai, "%d", setnilai);
        if(setnilai<100)
        {
            settextstyle(3, 0, 4);
            outtextxy(1805, 935, nilaisetnilai);
        }
        else if(setnilai>99 && setnilai<1000)
        {
            settextstyle(3, 0, 4);
            outtextxy(1796, 935, nilaisetnilai);
        }
        else if (setnilai>999)
        {
            settextstyle(3, 0, 4);
            outtextxy(1789, 935, nilaisetnilai);
        }
    }

    void BarJarak(float y)
    {
        setfillstyle(1,6);
        bar(1800,890-y,1850,890);
    }

    void ResetJarak()
    {
        jarak = 0;
    }
};

class Poin : public Mobil
{
public:
    char nilaipoin[9999];

    void Set(int poin)
    {
        settextstyle(3, 0, 7);
        outtextxy(50, 30, "Poin :");
        sprintf(nilaipoin, "%d", poin);
        outtextxy(50, 100, nilaipoin);
    }
};

class Nyawa : public Mobil
{
public:
    char nilainyawa[3];

    void Set(int nyawa)
    {
        settextstyle(3, 0, 6);
        outtextxy(50, 910, "Nyawa :");
        sprintf(nilainyawa, "%d", nyawa);
        outtextxy(270, 912, nilainyawa);
    }

};

main()
{
    int getch();

    int cekNyawa=3;
    float CekPoin=0;
    float Poin1=0; float Poin2=0; float Poin3=0; float Poin4=0; float Poin5=0;
    float yj=0;
    int page = 0;
    int sy=0; int cy=0;
    float LB=0; float LBc=0;
    int randJalan1=-1; int randJalan2=-1; int randJalan3=-1;

    int countML1 = 0; int countML2 = 0; int countML3 = 0;
    int countP1 = 0; int countP2 = 0; int countP3 = 0;
    int countrand1=0; int countrand2=0; int countrand3=0;
    int countspmm = 0;
    int countlb = 0;
    int countb = 0;
    int countsc = 0;

    int s1 = 6, s2 = 6;
    int x1 = 0, x2 = 0;
    int y1 = 0, y2 = 0;
    int PilihanMenu = 0;
    int close = 1;
    int Start=0;

    DWORD layarx = GetSystemMetrics(SM_CXSCREEN);
    DWORD layary = GetSystemMetrics(SM_CYSCREEN);

    MainMenu Menu;
    Loading Loading1;
    Score PapanScore;
    PauseMenu Pause;

    Mobil setMobil;
    MainMobil Player;
    MainMobil StartPlayer;
    MainMobil LoadingMM;
    MobilLawan1 Lawan1a, Lawan1b, Lawan1c;
    MobilLawan2 Lawan2a, Lawan2b, Lawan2c;
    MobilLawan3 Lawan3a, Lawan3b, Lawan3c;
    Penghalang1 Halang1a, Halang1b, Halang1c;
    Penghalang2 Halang2a, Halang2b, Halang2c;
    Penghalang3 Halang3a, Halang3b, Halang3c;

    CTembak pelor;
    pelor.Init();

    SetJalan Jalan;
    Jalan.setpos();
    Jarak SetJarak;
    Nyawa SetNyawa;
    Poin SetPoin;

    setMobil.Init();
    Lawan1a.Set(780,1200,2.5); Lawan1b.Set(780,1200,2.5); Lawan1c.Set(780,1200,2.5);
    Lawan2a.Set(960,1200,2.5); Lawan2b.Set(960,1200,2.5); Lawan2c.Set(960,1200,2.5);
    Lawan3a.Set(1140,1200,2.5); Lawan3b.Set(1140,1200,2.5); Lawan3c.Set(1140,1200,2.5);
    Halang1a.Set(780,1200,1.6); Halang1b.Set(780,1200,1.6); Halang1c.Set(780,1200,1.6);
    Halang2a.Set(960,1200,1.6); Halang2b.Set(960,1200,1.6); Halang2c.Set(960,1200,1.6);
    Halang3a.Set(1140,1200,1.6); Halang3b.Set(1140,1200,1.6); Halang3c.Set(1140,1200,1.6);

    initwindow(layarx,layary, "");

    while(1)
    {
        setactivepage(page);
        setvisualpage(1 - page);

        cleardevice();

        setbkcolor(GREEN);

        if(Menu.level == -1)
        {
            Jalan.drawjalan(0);
            SetJarak.Set(9999); SetJarak.SetPoin(9999); SetJarak.BarJarak(300);
            SetNyawa.Set(3);
            SetPoin.Set(9999);
            Menu.SetPetunjuk();
            pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas(); pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan1a.MLy1, Lawan1a.MLy1, Halang3a.Py3, Halang3a.Py3, Halang3a.Py3);
            Player.Draw(); Player.MMMove(); Player.s=2.5;
            Lawan1a.Draw(); Lawan1a.MMMove(); Lawan1a.MLy1=100;
            Halang3a.Draw(); Halang3a.MMMove(); Halang3a.Py3=100;
            Player.HitBox(); Lawan1a.HitBox(); Halang3a.HitBox();
            if(pelor.Ketembak1==1)
            {
                countspmm += 1;
                Lawan1a.MLy1=-100;
                if(countspmm==40)
                {
                    Lawan1a.MLy1=100;
                    countspmm = 0;
                    pelor.Ketembak1 = 0;
                }
            }
            if(GetAsyncKeyState(VK_ESCAPE) & (0x8000) != 0)
            {
                Player.ResetMobil(); Lawan1a.resetMLy1(); Halang3a.resetPy3();
                Menu.level = 0; Menu.close = 1;
            }
        }

        if(Menu.level == 0)
        {
            Menu.SetMenu();
            Menu.PilihMenu();
            Menu.SetPilihanMenu();
        }

        if(Menu.level == 1)
        {
            if(Start==0)
            {
                Loading1.Set(1,0);
                if(Loading1.blink==0){countb=countb+1; if(countb==30){Loading1.blink=800;countb=0;}}
                if(Loading1.blink==800){countb=countb+1; if(countb==30){Loading1.blink=0; countb=0;}}

                Loading1.LoadingCar(LB);
                LoadingMM.DrawMiring(); LoadingMM.MMx=670+LBc; LoadingMM.MMy=585; LoadingMM.s=1.6;
                if(LBc<570){LBc=LBc+4; if(LBc>100&&LBc<521){if(LB<420){LB=LB+4;}}}
                if(LBc>569){LBc=569; countlb=countlb+1; if(countlb==50){Start=1;}}
            }
            if(Start==1)
            {
                LoadingMM.s=0;
                Jalan.drawjalan(5);
                SetJarak.Set(2000); SetJarak.SetPoin(0);
                SetPoin.Set(0); SetPoin.Set(CekPoin);
                SetNyawa.Set(cekNyawa);
                pelor.Ketembak1 = 0; pelor.Ketembak2 = 0; pelor.Ketembak3 = 0; pelor.Ketembak4 = 0; pelor.Ketembak5 = 0; pelor.Ketembak6 = 0;

                StartPlayer.Draw(); StartPlayer.MMx=960;  StartPlayer.s = 2.5;
                StartPlayer.MMy = 1200-sy; sy = sy + 3;
                if(StartPlayer.MMy<900)
                {
                    if(Pause.pause==0)
                    {
                        Pause.setPause();
                        StartPlayer.s=0; StartPlayer.MMy=900;
                        SetJarak.PoinJarak(1); SetJarak.BarJarak(yj); yj=yj+0.352;
                        if(yj>=701)
                        {
                            yj=701;
                            SetJarak.SetPoin(2000);
                            randJalan1=-2; randJalan2=-2; randJalan3=-2;
                            countrand1=0; countrand2=0; countrand3=0;
                            if(Halang2a.Py2>1100)
                            {
                                StartPlayer.Draw(); StartPlayer.s = 2.5; StartPlayer.MMx=Player.MMx;
                                StartPlayer.MMy = 900-cy; cy = cy + 3;
                                Player.s = 0;
                                if(StartPlayer.MMy<-50)
                                {
                                    Poin1=CekPoin;
                                    PapanScore.Set();
                                    PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                                    if(countsc<300)
                                    {
                                        countsc=countsc+1;
                                        if(countsc==299)
                                        {
                                            countsc=0; countlb=0;
                                            CekPoin=0; SetJarak.ResetJarak();
                                            Menu.level = 2;
                                            yj=0; Jalan.py = 0;
                                            LB=0; LBc=0;
                                            sy=0; cy=0;
                                            Player.ResetMobil(); StartPlayer.ResetMobil();
                                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                            Start=0;
                                        }
                                    }
                                }
                            }
                        }

                        pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas();
                        pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan2a.MLy2, Lawan3a.MLy3, Halang1a.Py1, Halang2a.Py2, Halang3a.Py3);
                        pelor.HitBoxPeluru(Lawan1b.MLy1, Lawan2b.MLy2, Lawan3b.MLy3, Halang1b.Py1, Halang2b.Py2, Halang3b.Py3);
                        pelor.HitBoxPeluru(Lawan1c.MLy1, Lawan2c.MLy2, Lawan3c.MLy3, Halang1c.Py1, Halang2c.Py2, Halang3c.Py3);

                        Player.Draw(); Player.MMMove();
                        Lawan1a.MMMove(); Lawan1b.MMMove(); Lawan1a.Move1(); Lawan1b.Move1();
                        Lawan2a.MMMove(); Lawan2b.MMMove(); Lawan2a.Move2(); Lawan2b.Move2();
                        Lawan3a.MMMove(); Lawan3b.MMMove(); Lawan3a.Move3(); Lawan3b.Move3();
                        Halang1a.MMMove(); Halang1b.MMMove(); Halang1a.Move1(); Halang1b.Move1();
                        Halang2a.MMMove(); Halang2b.MMMove(); Halang2a.Move2(); Halang2b.Move2();
                        Halang3a.MMMove(); Halang3b.MMMove(); Halang3a.Move3(); Halang3b.Move3();

                        if(Lawan1a.MLy1<1200){Lawan1a.Draw();} if(Halang1a.Py1<1200){Halang1a.Draw();}
                        if(Lawan2a.MLy2<1200){Lawan2a.Draw();} if(Halang2a.Py2<1200){Halang2a.Draw();}
                        if(Lawan3a.MLy3<1200){Lawan3a.Draw();} if(Halang3a.Py3<1200){Halang3a.Draw();}
                        if(Lawan1b.MLy1<1200){Lawan1b.Draw();} if(Halang1b.Py1<1200){Halang1b.Draw();}
                        if(Lawan2b.MLy2<1200){Lawan2b.Draw();} if(Halang2b.Py2<1200){Halang2b.Draw();}
                        if(Lawan3b.MLy3<1200){Lawan3b.Draw();} if(Halang3b.Py3<1200){Halang3b.Draw();}

                        Player.HitBox();
                        Lawan1a.HitBox(); Lawan1b.HitBox();
                        Lawan2a.HitBox(); Lawan2b.HitBox();
                        Lawan3a.HitBox(); Lawan3b.HitBox();
                        Halang1a.HitBox(); Halang1b.HitBox();
                        Halang2a.HitBox(); Halang2b.HitBox();
                        Halang3a.HitBox(); Halang3b.HitBox();

                        countrand1+=1;
                        if(randJalan1==-1){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;}}
                        if(countrand1==110){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1b.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1b.Py1=-100;}}
                        if(countrand1==220){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1c.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1c.Py1=-100;}}
                        if(countrand1==330){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;countrand1=0;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;countrand1=0;}if(randJalan1>=21){countrand1=0;}}
                        countrand2+=1;
                        if(randJalan2==-1){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;}}
                        if(countrand2==110){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2b.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2b.Py2=-100;}}
                        if(countrand2==220){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2c.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2c.Py2=-100;}}
                        if(countrand2==330){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;countrand2=0;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;countrand2=0;}if(randJalan2>=21){countrand2=0;}}
                        countrand3+=1;
                        if(randJalan3==-1){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;}}
                        if(countrand3==110){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3b.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3b.Py3=-100;}}
                        if(countrand3==220){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3c.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3c.Py3=-100;}}
                        if(countrand3==330){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;countrand3=0;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;countrand3=0;}if(randJalan3>=21){countrand3=0;}}

                        if(Lawan1a.setNyawa==3)
                        {
                            cekNyawa=3;
                        }
                        if(Lawan1a.setNyawa==2 || Lawan2a.setNyawa==2 || Lawan3a.setNyawa==2 || Halang1a.setNyawa==2 || Halang2a.setNyawa==2 || Halang3a.setNyawa==2 ||
                            Lawan1b.setNyawa==2 || Lawan2b.setNyawa==2 || Lawan3b.setNyawa==2 || Halang1b.setNyawa==2 || Halang2b.setNyawa==2 || Halang3b.setNyawa==2 ||
                            Lawan1c.setNyawa==2 || Lawan2c.setNyawa==2 || Lawan3c.setNyawa==2 || Halang1c.setNyawa==2 || Halang2c.setNyawa==2 || Halang3c.setNyawa==2 )
                        {
                            cekNyawa=2;
                            if(Lawan1a.setNyawa>2 || Lawan2a.setNyawa>2 || Lawan3a.setNyawa>2 || Halang1a.setNyawa>2 || Halang2a.setNyawa>2 || Halang3a.setNyawa>2 ||
                                Lawan1b.setNyawa>2 || Lawan2b.setNyawa>2 || Lawan3b.setNyawa>2 || Halang1b.setNyawa>2 || Halang2b.setNyawa>2 || Halang3b.setNyawa>2 ||
                                Lawan1c.setNyawa>2 || Lawan2c.setNyawa>2 || Lawan3c.setNyawa>2 || Halang1c.setNyawa>2 || Halang2c.setNyawa>2 || Halang3c.setNyawa>2 )
                            {
                                Lawan1a.setNyawa=2; Lawan2a.setNyawa=2; Lawan3a.setNyawa=2; Halang1a.setNyawa=2; Halang2a.setNyawa=2; Halang3a.setNyawa=2;
                                Lawan1b.setNyawa=2; Lawan2b.setNyawa=2; Lawan3b.setNyawa=2; Halang1b.setNyawa=2; Halang2b.setNyawa=2; Halang3b.setNyawa=2;
                                Lawan1c.setNyawa=2; Lawan2c.setNyawa=2; Lawan3c.setNyawa=2; Halang1c.setNyawa=2; Halang2c.setNyawa=2; Halang3c.setNyawa=2;
                            }
                        }
                        if(Lawan1a.setNyawa==1 || Lawan2a.setNyawa==1 || Lawan3a.setNyawa==1 || Halang1a.setNyawa==1 || Halang2a.setNyawa==1 || Halang3a.setNyawa==1 ||
                            Lawan1b.setNyawa==1 || Lawan2b.setNyawa==1 || Lawan3b.setNyawa==1 || Halang1b.setNyawa==1 || Halang2b.setNyawa==1 || Halang3b.setNyawa==1 ||
                            Lawan1c.setNyawa==1 || Lawan2c.setNyawa==1 || Lawan3c.setNyawa==1 || Halang1c.setNyawa==1 || Halang2c.setNyawa==1 || Halang3c.setNyawa==1 )
                        {
                            cekNyawa=1;
                            if(Lawan1a.setNyawa>1 || Lawan2a.setNyawa>1 || Lawan3a.setNyawa>1 || Halang1a.setNyawa>1 || Halang2a.setNyawa>1 || Halang3a.setNyawa>1 ||
                                Lawan1b.setNyawa>1 || Lawan2b.setNyawa>1 || Lawan3b.setNyawa>1 || Halang1b.setNyawa>1 || Halang2b.setNyawa>1 || Halang3b.setNyawa>1 ||
                                Lawan1c.setNyawa>1 || Lawan2c.setNyawa>1 || Lawan3c.setNyawa>1 || Halang1c.setNyawa>1 || Halang2c.setNyawa>1 || Halang3c.setNyawa>1 )
                            {
                                Lawan1a.setNyawa=1; Lawan2a.setNyawa=1; Lawan3a.setNyawa=1; Halang1a.setNyawa=1; Halang2a.setNyawa=1; Halang3a.setNyawa=1;
                                Lawan1b.setNyawa=1; Lawan2b.setNyawa=1; Lawan3b.setNyawa=1; Halang1b.setNyawa=1; Halang2b.setNyawa=1; Halang3b.setNyawa=1;
                                Lawan1c.setNyawa=1; Lawan2c.setNyawa=1; Lawan3c.setNyawa=1; Halang1c.setNyawa=1; Halang2c.setNyawa=1; Halang3c.setNyawa=1;
                            }
                        }
                        if(Lawan1a.setNyawa==0 || Lawan2a.setNyawa==0 || Lawan3a.setNyawa==0 || Halang1a.setNyawa==0 || Halang2a.setNyawa==0 || Halang3a.setNyawa==0 ||
                            Lawan1b.setNyawa==0 || Lawan2b.setNyawa==0 || Lawan3b.setNyawa==0 || Halang1b.setNyawa==0 || Halang2b.setNyawa==0 || Halang3b.setNyawa==0 ||
                            Lawan1c.setNyawa==0 || Lawan2c.setNyawa==0 || Lawan3c.setNyawa==0 || Halang1c.setNyawa==0 || Halang2c.setNyawa==0 || Halang3c.setNyawa==0 )
                        {
                            cekNyawa=0;
                            if(Lawan1a.setNyawa>0 || Lawan2a.setNyawa>0 || Lawan3a.setNyawa>0 || Halang1a.setNyawa>0 || Halang2a.setNyawa>0 || Halang3a.setNyawa>0 ||
                                Lawan1b.setNyawa>0 || Lawan2b.setNyawa>0 || Lawan3b.setNyawa>0 || Halang1b.setNyawa>0 || Halang2b.setNyawa>0 || Halang3b.setNyawa>0 ||
                                Lawan1c.setNyawa>0 || Lawan2c.setNyawa>0 || Lawan3c.setNyawa>0 || Halang1c.setNyawa>0 || Halang2c.setNyawa>0 || Halang3c.setNyawa>0 )
                            {
                                Lawan1a.setNyawa=0; Lawan2a.setNyawa=0; Lawan3a.setNyawa=0; Halang1a.setNyawa=0; Halang2a.setNyawa=0; Halang3a.setNyawa=0;
                                Lawan1b.setNyawa=0; Lawan2b.setNyawa=0; Lawan3b.setNyawa=0; Halang1b.setNyawa=0; Halang2b.setNyawa=0; Halang3b.setNyawa=0;
                                Lawan1c.setNyawa=0; Lawan2c.setNyawa=0; Lawan3c.setNyawa=0; Halang1c.setNyawa=0; Halang2c.setNyawa=0; Halang3c.setNyawa=0;
                            }
                        }
                        if(Lawan1a.setNyawa==-1 || Lawan2a.setNyawa==-1 || Lawan3a.setNyawa==-1 || Halang1a.setNyawa==-1 || Halang2a.setNyawa==-1 || Halang3a.setNyawa==-1 ||
                            Lawan1b.setNyawa==-1 || Lawan2b.setNyawa==-1 || Lawan3b.setNyawa==-1 || Halang1b.setNyawa==-1 || Halang2b.setNyawa==-1 || Halang3b.setNyawa==-1 ||
                            Lawan1c.setNyawa==-1 || Lawan2c.setNyawa==-1 || Lawan3c.setNyawa==-1 || Halang1c.setNyawa==-1 || Halang2c.setNyawa==-1 || Halang3c.setNyawa==-1 )
                        {
                            Poin1=CekPoin;
                            PapanScore.Set();
                            PapanScore.SetScore(1,0,Poin1,0,Poin1+0);
                            PapanScore.SetScore(2,100,Poin2,0,Poin2+0);
                            PapanScore.SetScore(3,200,Poin3,0,Poin3+0);
                            PapanScore.SetScore(4,300,Poin4,0,Poin4+0);
                            PapanScore.SetScore(5,400,Poin5,0,Poin5+0);
                            PapanScore.TotalScore(Poin1+0+Poin2+0+Poin3+0+Poin4+0+Poin5+0);
                            settextstyle(10, 0, 3);
                            outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                            if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                            {
                                countsc=0; countlb=0;
                                CekPoin=0; SetJarak.ResetJarak();
                                Menu.close = 1; Menu.level = 0;
                                yj=0; Jalan.py = 0;
                                LB=0; LBc=0;
                                sy=0; cy=0;
                                Player.ResetMobil(); StartPlayer.ResetMobil();
                                Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                Start=0;

                                if(Lawan1a.setNyawa<0 || Lawan2a.setNyawa<0 || Lawan3a.setNyawa<0 || Halang1a.setNyawa<0 || Halang2a.setNyawa<0 || Halang3a.setNyawa<0 ||
                                    Lawan1b.setNyawa<0 || Lawan2b.setNyawa<0 || Lawan3b.setNyawa<0 || Halang1b.setNyawa<0 || Halang2b.setNyawa<0 || Halang3b.setNyawa<0 ||
                                    Lawan1c.setNyawa<0 || Lawan2c.setNyawa<0 || Lawan3c.setNyawa<0 || Halang1c.setNyawa<0 || Halang2c.setNyawa<0 || Halang3c.setNyawa<0 )
                                {
                                    cekNyawa=3;
                                    Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                    Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                    Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                }
                            }
                        }

                        if(pelor.Ketembak1==1)
                        {
                            if(Lawan1a.MLy1<900){ if(Lawan1b.MLy1>Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1b.MLy1<Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1b.MLy1<900){ if(Lawan1c.MLy1>Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1c.MLy1<Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1c.MLy1<900){ if(Lawan1a.MLy1>Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan3a.MLy1<Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; }}
                        }
                        else if(pelor.Ketembak2==1)
                        {
                            if(Lawan2a.MLy2<900){ if(Lawan2b.MLy2>Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2b.MLy2<Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2b.MLy2<900){ if(Lawan2c.MLy2>Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2c.MLy2<Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2c.MLy2<900){ if(Lawan2a.MLy2>Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2a.MLy2<Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; }}
                        }
                        else if(pelor.Ketembak3==1)
                        {
                            if(Lawan3a.MLy3<900){ if(Lawan3b.MLy3>Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3b.MLy3<Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3b.MLy3<900){ if(Lawan3c.MLy3>Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3c.MLy3<Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3c.MLy3<900){ if(Lawan3a.MLy3>Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3a.MLy3<Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; }}
                        }
                        else if(pelor.Ketembak4==1)
                        {
                            pelor.Ketembak4=0;
                        }
                        else if(pelor.Ketembak5==1)
                        {
                            pelor.Ketembak5=0;
                        }
                        else if(pelor.Ketembak6==1)
                        {
                            pelor.Ketembak6=0;
                        }

                        if(pelor.poinNambah==1)
                        {
                            CekPoin = CekPoin + 15;
                            pelor.poinNambah=pelor.poinNambah-1;
                        }

                        if(setMobil.Ketabrak==0){ Player.s=2.5; }
                        if(Lawan1a.Ketabrak>0 && Lawan1a.Ketabrak<4){ Lawan1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1b.Ketabrak>0 && Lawan1b.Ketabrak<4){ Lawan1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1c.Ketabrak>0 && Lawan1c.Ketabrak<4){ Lawan1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2a.Ketabrak>0 && Lawan2a.Ketabrak<4){ Lawan2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2b.Ketabrak>0 && Lawan2b.Ketabrak<4){ Lawan2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2c.Ketabrak>0 && Lawan2c.Ketabrak<4){ Lawan2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3a.Ketabrak>0 && Lawan3a.Ketabrak<4){ Lawan3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3b.Ketabrak>0 && Lawan3b.Ketabrak<4){ Lawan3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3c.Ketabrak>0 && Lawan3c.Ketabrak<4){ Lawan3c.RespawnKetabrak(); Player.RespawnKetabrak(); }

                        if(Halang1a.Ketabrak>0 && Halang1a.Ketabrak<4){ Halang1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1b.Ketabrak>0 && Halang1b.Ketabrak<4){ Halang1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1c.Ketabrak>0 && Halang1c.Ketabrak<4){ Halang1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2a.Ketabrak>0 && Halang2a.Ketabrak<4){ Halang2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2b.Ketabrak>0 && Halang2b.Ketabrak<4){ Halang2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2c.Ketabrak>0 && Halang2c.Ketabrak<4){ Halang2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3a.Ketabrak>0 && Halang3a.Ketabrak<4){ Halang3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3b.Ketabrak>0 && Halang3b.Ketabrak<4){ Halang3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3c.Ketabrak>0 && Halang3c.Ketabrak<4){ Halang3c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                    }

                    if(Pause.pause==1)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.setPause(); Pause.Draw(); Pause.PilihPause(); Pause.SetPilihanPause();
                    }

                    if(Pause.pause==2)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.DrawYakin(); Pause.PilihYakin(); Pause.SetPilihanYakin();
                        if(Pause.pause==3)
                        {
                            countsc=0; countlb=0;
                            CekPoin=0; SetJarak.ResetJarak();
                            Menu.close = 1; Menu.level = 0;
                            Pause.pause=0; Pause.PilihanPause=0;
                            yj=0; Jalan.py = 0;
                            LB=0; LBc=0;
                            sy=0; cy=0;
                            Player.ResetMobil(); StartPlayer.ResetMobil();
                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                            Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                            Start=0;

                            if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                            {
                                cekNyawa=3;
                                Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                            }
                        }
                    }
                }
            }
        }

if(Menu.level == 2)
        {
            if(Start==0)
            {
                Loading1.Set(2,0);
                if(Loading1.blink==0){countb=countb+1; if(countb==30){Loading1.blink=800;countb=0;}}
                if(Loading1.blink==800){countb=countb+1; if(countb==30){Loading1.blink=0; countb=0;}}

                Loading1.LoadingCar(LB);
                LoadingMM.DrawMiring(); LoadingMM.MMx=670+LBc; LoadingMM.MMy=585; LoadingMM.s=1.6;
                if(LBc<570){LBc=LBc+4; if(LBc>100&&LBc<521){if(LB<420){LB=LB+4;}}}
                if(LBc>569){LBc=569; countlb=countlb+1; if(countlb==50){Start=1;}}
            }
            if(Start==1)
            {
                LoadingMM.s=0;
                Jalan.drawjalan(5);
                SetJarak.Set(3000); SetJarak.SetPoin(0);
                SetPoin.Set(0); SetPoin.Set(CekPoin);
                SetNyawa.Set(cekNyawa);

                StartPlayer.Draw(); StartPlayer.MMx=960;  StartPlayer.s = 2.5;
                StartPlayer.MMy = 1200-sy; sy = sy + 3;
                if(StartPlayer.MMy<900)
                {
                    if(Pause.pause==0)
                    {
                        Pause.setPause();
                        StartPlayer.s=0; StartPlayer.MMy=900;
                        SetJarak.PoinJarak(1); SetJarak.BarJarak(yj); yj=yj+0.235;
                        if(yj>=701)
                        {
                            yj=701;
                            SetJarak.SetPoin(3000);
                            randJalan1=-2; randJalan2=-2; randJalan3=-2;
                            countrand1=0; countrand2=0; countrand3=0;
                            if(Lawan1a.MLy1>1100)
                            {
                                StartPlayer.Draw(); StartPlayer.s = 2.5; StartPlayer.MMx=Player.MMx;
                                StartPlayer.MMy = 900-cy; cy = cy + 3;
                                Player.s = 0;
                                if(StartPlayer.MMy<-50)
                                {
                                    Poin2=CekPoin;
                                    PapanScore.Set();
                                    PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                                    PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                                    if(countsc<300)
                                    {
                                        countsc=countsc+1;
                                        if(countsc==299)
                                        {
                                            countsc=0; countlb=0;
                                            CekPoin=0; SetJarak.ResetJarak();
                                            Menu.level = 3;
                                            yj=0; Jalan.py = 0;
                                            LB=0; LBc=0;
                                            sy=0; cy=0;
                                            Player.ResetMobil(); StartPlayer.ResetMobil();
                                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                            Start=0;
                                        }
                                    }
                                }
                            }
                        }

                        pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas();
                        pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan2a.MLy2, Lawan3a.MLy3, Halang1a.Py1, Halang2a.Py2, Halang3a.Py3);
                        pelor.HitBoxPeluru(Lawan1b.MLy1, Lawan2b.MLy2, Lawan3b.MLy3, Halang1b.Py1, Halang2b.Py2, Halang3b.Py3);
                        pelor.HitBoxPeluru(Lawan1c.MLy1, Lawan2c.MLy2, Lawan3c.MLy3, Halang1c.Py1, Halang2c.Py2, Halang3c.Py3);

                        Player.Draw(); Player.MMMove();
                        Lawan1a.MMMove(); Lawan1b.MMMove(); Lawan1a.Move1(); Lawan1b.Move1();
                        Lawan2a.MMMove(); Lawan2b.MMMove(); Lawan2a.Move2(); Lawan2b.Move2();
                        Lawan3a.MMMove(); Lawan3b.MMMove(); Lawan3a.Move3(); Lawan3b.Move3();
                        Halang1a.MMMove(); Halang1b.MMMove(); Halang1a.Move1(); Halang1b.Move1();
                        Halang2a.MMMove(); Halang2b.MMMove(); Halang2a.Move2(); Halang2b.Move2();
                        Halang3a.MMMove(); Halang3b.MMMove(); Halang3a.Move3(); Halang3b.Move3();

                        if(Lawan1a.MLy1<1200){Lawan1a.Draw();} if(Halang1a.Py1<1200){Halang1a.Draw();}
                        if(Lawan2a.MLy2<1200){Lawan2a.Draw();} if(Halang2a.Py2<1200){Halang2a.Draw();}
                        if(Lawan3a.MLy3<1200){Lawan3a.Draw();} if(Halang3a.Py3<1200){Halang3a.Draw();}
                        if(Lawan1b.MLy1<1200){Lawan1b.Draw();} if(Halang1b.Py1<1200){Halang1b.Draw();}
                        if(Lawan2b.MLy2<1200){Lawan2b.Draw();} if(Halang2b.Py2<1200){Halang2b.Draw();}
                        if(Lawan3b.MLy3<1200){Lawan3b.Draw();} if(Halang3b.Py3<1200){Halang3b.Draw();}

                        Player.HitBox();
                        Lawan1a.HitBox(); Lawan1b.HitBox();
                        Lawan2a.HitBox(); Lawan2b.HitBox();
                        Lawan3a.HitBox(); Lawan3b.HitBox();
                        Halang1a.HitBox(); Halang1b.HitBox();
                        Halang2a.HitBox(); Halang2b.HitBox();
                        Halang3a.HitBox(); Halang3b.HitBox();

                        countrand1+=1;
                        if(randJalan1==-1){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;}}
                        if(countrand1==110){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1b.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1b.Py1=-100;}}
                        if(countrand1==220){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1c.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1c.Py1=-100;}}
                        if(countrand1==330){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;countrand1=0;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;countrand1=0;}if(randJalan1>=20){countrand1=0;}}
                        countrand2+=1;
                        if(randJalan2==-1){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;}}
                        if(countrand2==110){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2b.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2b.Py2=-100;}}
                        if(countrand2==220){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2c.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2c.Py2=-100;}}
                        if(countrand2==330){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;countrand2=0;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;countrand2=0;}if(randJalan2>=20){countrand2=0;}}
                        countrand3+=1;
                        if(randJalan3==-1){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;}}
                        if(countrand3==110){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3b.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3b.Py3=-100;}}
                        if(countrand3==220){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3c.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3c.Py3=-100;}}
                        if(countrand3==330){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;countrand3=0;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;countrand3=0;}if(randJalan3>=20){countrand3=0;}}

                        if(Lawan1a.setNyawa==3)
                        {
                            cekNyawa=3;
                        }
                        if(Lawan1a.setNyawa==2 || Lawan2a.setNyawa==2 || Lawan3a.setNyawa==2 || Halang1a.setNyawa==2 || Halang2a.setNyawa==2 || Halang3a.setNyawa==2 ||
                            Lawan1b.setNyawa==2 || Lawan2b.setNyawa==2 || Lawan3b.setNyawa==2 || Halang1b.setNyawa==2 || Halang2b.setNyawa==2 || Halang3b.setNyawa==2 ||
                            Lawan1c.setNyawa==2 || Lawan2c.setNyawa==2 || Lawan3c.setNyawa==2 || Halang1c.setNyawa==2 || Halang2c.setNyawa==2 || Halang3c.setNyawa==2 )
                        {
                            cekNyawa=2;
                            if(Lawan1a.setNyawa>2 || Lawan2a.setNyawa>2 || Lawan3a.setNyawa>2 || Halang1a.setNyawa>2 || Halang2a.setNyawa>2 || Halang3a.setNyawa>2 ||
                                Lawan1b.setNyawa>2 || Lawan2b.setNyawa>2 || Lawan3b.setNyawa>2 || Halang1b.setNyawa>2 || Halang2b.setNyawa>2 || Halang3b.setNyawa>2 ||
                                Lawan1c.setNyawa>2 || Lawan2c.setNyawa>2 || Lawan3c.setNyawa>2 || Halang1c.setNyawa>2 || Halang2c.setNyawa>2 || Halang3c.setNyawa>2 )
                            {
                                Lawan1a.setNyawa=2; Lawan2a.setNyawa=2; Lawan3a.setNyawa=2; Halang1a.setNyawa=2; Halang2a.setNyawa=2; Halang3a.setNyawa=2;
                                Lawan1b.setNyawa=2; Lawan2b.setNyawa=2; Lawan3b.setNyawa=2; Halang1b.setNyawa=2; Halang2b.setNyawa=2; Halang3b.setNyawa=2;
                                Lawan1c.setNyawa=2; Lawan2c.setNyawa=2; Lawan3c.setNyawa=2; Halang1c.setNyawa=2; Halang2c.setNyawa=2; Halang3c.setNyawa=2;
                            }
                        }
                        if(Lawan1a.setNyawa==1 || Lawan2a.setNyawa==1 || Lawan3a.setNyawa==1 || Halang1a.setNyawa==1 || Halang2a.setNyawa==1 || Halang3a.setNyawa==1 ||
                            Lawan1b.setNyawa==1 || Lawan2b.setNyawa==1 || Lawan3b.setNyawa==1 || Halang1b.setNyawa==1 || Halang2b.setNyawa==1 || Halang3b.setNyawa==1 ||
                            Lawan1c.setNyawa==1 || Lawan2c.setNyawa==1 || Lawan3c.setNyawa==1 || Halang1c.setNyawa==1 || Halang2c.setNyawa==1 || Halang3c.setNyawa==1 )
                        {
                            cekNyawa=1;
                            if(Lawan1a.setNyawa>1 || Lawan2a.setNyawa>1 || Lawan3a.setNyawa>1 || Halang1a.setNyawa>1 || Halang2a.setNyawa>1 || Halang3a.setNyawa>1 ||
                                Lawan1b.setNyawa>1 || Lawan2b.setNyawa>1 || Lawan3b.setNyawa>1 || Halang1b.setNyawa>1 || Halang2b.setNyawa>1 || Halang3b.setNyawa>1 ||
                                Lawan1c.setNyawa>1 || Lawan2c.setNyawa>1 || Lawan3c.setNyawa>1 || Halang1c.setNyawa>1 || Halang2c.setNyawa>1 || Halang3c.setNyawa>1 )
                            {
                                Lawan1a.setNyawa=1; Lawan2a.setNyawa=1; Lawan3a.setNyawa=1; Halang1a.setNyawa=1; Halang2a.setNyawa=1; Halang3a.setNyawa=1;
                                Lawan1b.setNyawa=1; Lawan2b.setNyawa=1; Lawan3b.setNyawa=1; Halang1b.setNyawa=1; Halang2b.setNyawa=1; Halang3b.setNyawa=1;
                                Lawan1c.setNyawa=1; Lawan2c.setNyawa=1; Lawan3c.setNyawa=1; Halang1c.setNyawa=1; Halang2c.setNyawa=1; Halang3c.setNyawa=1;
                            }
                        }
                        if(Lawan1a.setNyawa==0 || Lawan2a.setNyawa==0 || Lawan3a.setNyawa==0 || Halang1a.setNyawa==0 || Halang2a.setNyawa==0 || Halang3a.setNyawa==0 ||
                            Lawan1b.setNyawa==0 || Lawan2b.setNyawa==0 || Lawan3b.setNyawa==0 || Halang1b.setNyawa==0 || Halang2b.setNyawa==0 || Halang3b.setNyawa==0 ||
                            Lawan1c.setNyawa==0 || Lawan2c.setNyawa==0 || Lawan3c.setNyawa==0 || Halang1c.setNyawa==0 || Halang2c.setNyawa==0 || Halang3c.setNyawa==0 )
                        {
                            cekNyawa=0;
                            if(Lawan1a.setNyawa>0 || Lawan2a.setNyawa>0 || Lawan3a.setNyawa>0 || Halang1a.setNyawa>0 || Halang2a.setNyawa>0 || Halang3a.setNyawa>0 ||
                                Lawan1b.setNyawa>0 || Lawan2b.setNyawa>0 || Lawan3b.setNyawa>0 || Halang1b.setNyawa>0 || Halang2b.setNyawa>0 || Halang3b.setNyawa>0 ||
                                Lawan1c.setNyawa>0 || Lawan2c.setNyawa>0 || Lawan3c.setNyawa>0 || Halang1c.setNyawa>0 || Halang2c.setNyawa>0 || Halang3c.setNyawa>0 )
                            {
                                Lawan1a.setNyawa=0; Lawan2a.setNyawa=0; Lawan3a.setNyawa=0; Halang1a.setNyawa=0; Halang2a.setNyawa=0; Halang3a.setNyawa=0;
                                Lawan1b.setNyawa=0; Lawan2b.setNyawa=0; Lawan3b.setNyawa=0; Halang1b.setNyawa=0; Halang2b.setNyawa=0; Halang3b.setNyawa=0;
                                Lawan1c.setNyawa=0; Lawan2c.setNyawa=0; Lawan3c.setNyawa=0; Halang1c.setNyawa=0; Halang2c.setNyawa=0; Halang3c.setNyawa=0;
                            }
                        }
                        if(Lawan1a.setNyawa==-1 || Lawan2a.setNyawa==-1 || Lawan3a.setNyawa==-1 || Halang1a.setNyawa==-1 || Halang2a.setNyawa==-1 || Halang3a.setNyawa==-1 ||
                            Lawan1b.setNyawa==-1 || Lawan2b.setNyawa==-1 || Lawan3b.setNyawa==-1 || Halang1b.setNyawa==-1 || Halang2b.setNyawa==-1 || Halang3b.setNyawa==-1 ||
                            Lawan1c.setNyawa==-1 || Lawan2c.setNyawa==-1 || Lawan3c.setNyawa==-1 || Halang1c.setNyawa==-1 || Halang2c.setNyawa==-1 || Halang3c.setNyawa==-1 )
                        {
                            Poin2=CekPoin;
                            PapanScore.Set();
                            PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                            PapanScore.SetScore(2,100,Poin2,0,Poin2+0);
                            PapanScore.SetScore(3,200,Poin3,0,Poin3+0);
                            PapanScore.SetScore(4,300,Poin4,0,Poin4+0);
                            PapanScore.SetScore(5,400,Poin5,0,Poin5+0);
                            PapanScore.TotalScore(Poin1+200+Poin2+0+Poin3+0+Poin4+0+Poin5+0);
                            settextstyle(10, 0, 3);
                            outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                            if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                            {
                                countsc=0; countlb=0;
                                CekPoin=0; SetJarak.ResetJarak();
                                Menu.close = 1; Menu.level = 0;
                                yj=0; Jalan.py = 0;
                                LB=0; LBc=0;
                                sy=0; cy=0;
                                Player.ResetMobil(); StartPlayer.ResetMobil();
                                Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                Start=0;

                                if(Lawan1a.setNyawa<0 || Lawan2a.setNyawa<0 || Lawan3a.setNyawa<0 || Halang1a.setNyawa<0 || Halang2a.setNyawa<0 || Halang3a.setNyawa<0 ||
                                    Lawan1b.setNyawa<0 || Lawan2b.setNyawa<0 || Lawan3b.setNyawa<0 || Halang1b.setNyawa<0 || Halang2b.setNyawa<0 || Halang3b.setNyawa<0 ||
                                    Lawan1c.setNyawa<0 || Lawan2c.setNyawa<0 || Lawan3c.setNyawa<0 || Halang1c.setNyawa<0 || Halang2c.setNyawa<0 || Halang3c.setNyawa<0 )
                                {
                                    cekNyawa=3;
                                    Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                    Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                    Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                }
                            }
                        }

                        if(pelor.Ketembak1==1)
                        {
                            if(Lawan1a.MLy1<900){ if(Lawan1b.MLy1>Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1b.MLy1<Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1b.MLy1<900){ if(Lawan1c.MLy1>Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1c.MLy1<Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1c.MLy1<900){ if(Lawan1a.MLy1>Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan3a.MLy1<Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; }}
                        }
                        else if(pelor.Ketembak2==1)
                        {
                            if(Lawan2a.MLy2<900){ if(Lawan2b.MLy2>Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2b.MLy2<Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2b.MLy2<900){ if(Lawan2c.MLy2>Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2c.MLy2<Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2c.MLy2<900){ if(Lawan2a.MLy2>Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2a.MLy2<Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; }}
                        }
                        else if(pelor.Ketembak3==1)
                        {
                            if(Lawan3a.MLy3<900){ if(Lawan3b.MLy3>Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3b.MLy3<Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3b.MLy3<900){ if(Lawan3c.MLy3>Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3c.MLy3<Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3c.MLy3<900){ if(Lawan3a.MLy3>Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3a.MLy3<Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; }}
                        }
                        else if(pelor.Ketembak4==1)
                        {
                            pelor.Ketembak4=0;
                        }
                        else if(pelor.Ketembak5==1)
                        {
                            pelor.Ketembak5=0;
                        }
                        else if(pelor.Ketembak6==1)
                        {
                            pelor.Ketembak6=0;
                        }

                        if(pelor.poinNambah==1)
                        {
                            CekPoin = CekPoin + 15;
                            pelor.poinNambah=pelor.poinNambah-1;
                        }

                        if(setMobil.Ketabrak==0){ Player.s=2.5; }
                        if(Lawan1a.Ketabrak>0 && Lawan1a.Ketabrak<4){ Lawan1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1b.Ketabrak>0 && Lawan1b.Ketabrak<4){ Lawan1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1c.Ketabrak>0 && Lawan1c.Ketabrak<4){ Lawan1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2a.Ketabrak>0 && Lawan2a.Ketabrak<4){ Lawan2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2b.Ketabrak>0 && Lawan2b.Ketabrak<4){ Lawan2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2c.Ketabrak>0 && Lawan2c.Ketabrak<4){ Lawan2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3a.Ketabrak>0 && Lawan3a.Ketabrak<4){ Lawan3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3b.Ketabrak>0 && Lawan3b.Ketabrak<4){ Lawan3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3c.Ketabrak>0 && Lawan3c.Ketabrak<4){ Lawan3c.RespawnKetabrak(); Player.RespawnKetabrak(); }

                        if(Halang1a.Ketabrak>0 && Halang1a.Ketabrak<4){ Halang1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1b.Ketabrak>0 && Halang1b.Ketabrak<4){ Halang1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1c.Ketabrak>0 && Halang1c.Ketabrak<4){ Halang1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2a.Ketabrak>0 && Halang2a.Ketabrak<4){ Halang2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2b.Ketabrak>0 && Halang2b.Ketabrak<4){ Halang2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2c.Ketabrak>0 && Halang2c.Ketabrak<4){ Halang2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3a.Ketabrak>0 && Halang3a.Ketabrak<4){ Halang3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3b.Ketabrak>0 && Halang3b.Ketabrak<4){ Halang3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3c.Ketabrak>0 && Halang3c.Ketabrak<4){ Halang3c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                    }

                    if(Pause.pause==1)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.setPause(); Pause.Draw(); Pause.PilihPause(); Pause.SetPilihanPause();
                    }

                    if(Pause.pause==2)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.DrawYakin(); Pause.PilihYakin(); Pause.SetPilihanYakin();
                        if(Pause.pause==3)
                        {
                            countsc=0; countlb=0;
                            CekPoin=0; SetJarak.ResetJarak();
                            Menu.close = 1; Menu.level = 0;
                            Pause.pause=0; Pause.PilihanPause=0;
                            yj=0; Jalan.py = 0;
                            LB=0; LBc=0;
                            sy=0; cy=0;
                            Player.ResetMobil(); StartPlayer.ResetMobil();
                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                            Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                            Start=0;

                            if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                            {
                                cekNyawa=3;
                                Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                            }
                        }
                    }
                }
            }
        }


if(Menu.level == 3)
        {
            if(Start==0)
            {
                Loading1.Set(3,0);
                if(Loading1.blink==0){countb=countb+1; if(countb==30){Loading1.blink=800;countb=0;}}
                if(Loading1.blink==800){countb=countb+1; if(countb==30){Loading1.blink=0; countb=0;}}

                Loading1.LoadingCar(LB);
                LoadingMM.DrawMiring(); LoadingMM.MMx=670+LBc; LoadingMM.MMy=585; LoadingMM.s=1.6;
                if(LBc<570){LBc=LBc+4; if(LBc>100&&LBc<521){if(LB<420){LB=LB+4;}}}
                if(LBc>569){LBc=569; countlb=countlb+1; if(countlb==50){Start=1;}}
            }
            if(Start==1)
            {
                LoadingMM.s=0;
                Jalan.drawjalan(5);
                SetJarak.Set(4000); SetJarak.SetPoin(0);
                SetPoin.Set(0); SetPoin.Set(CekPoin);
                SetNyawa.Set(cekNyawa);

                StartPlayer.Draw(); StartPlayer.MMx=960;  StartPlayer.s = 2.5;
                StartPlayer.MMy = 1200-sy; sy = sy + 3;
                if(StartPlayer.MMy<900)
                {
                    if(Pause.pause==0)
                    {
                        Pause.setPause();
                        StartPlayer.s=0; StartPlayer.MMy=900;
                        SetJarak.PoinJarak(1); SetJarak.BarJarak(yj); yj=yj+0.177;
                        if(yj>=701)
                        {
                            yj=701;
                            SetJarak.SetPoin(4000);
                            randJalan1=-2; randJalan2=-2; randJalan3=-2;
                            countrand1=0; countrand2=0; countrand3=0;
                            if(Lawan1a.MLy1>1100)
                            {
                                StartPlayer.Draw(); StartPlayer.s = 2.5; StartPlayer.MMx=Player.MMx;
                                StartPlayer.MMy = 900-cy; cy = cy + 3;
                                Player.s = 0;
                                if(StartPlayer.MMy<-50)
                                {
                                    Poin3=CekPoin;
                                    PapanScore.Set();
                                    PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                                    PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                                    PapanScore.SetScore(3,200,Poin3,400,Poin3+400);
                                    if(countsc<300)
                                    {
                                        countsc=countsc+1;
                                        if(countsc==299)
                                        {
                                            countsc=0; countlb=0;
                                            CekPoin=0; SetJarak.ResetJarak();
                                            Menu.level = 4;
                                            yj=0; Jalan.py = 0;
                                            LB=0; LBc=0;
                                            sy=0; cy=0;
                                            Player.ResetMobil(); StartPlayer.ResetMobil();
                                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                            Start=0;
                                        }
                                    }
                                }
                            }
                        }

                        pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas();
                        pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan2a.MLy2, Lawan3a.MLy3, Halang1a.Py1, Halang2a.Py2, Halang3a.Py3);
                        pelor.HitBoxPeluru(Lawan1b.MLy1, Lawan2b.MLy2, Lawan3b.MLy3, Halang1b.Py1, Halang2b.Py2, Halang3b.Py3);
                        pelor.HitBoxPeluru(Lawan1c.MLy1, Lawan2c.MLy2, Lawan3c.MLy3, Halang1c.Py1, Halang2c.Py2, Halang3c.Py3);

                        Player.Draw(); Player.MMMove();
                        Lawan1a.MMMove(); Lawan1b.MMMove(); Lawan1a.Move1(); Lawan1b.Move1();
                        Lawan2a.MMMove(); Lawan2b.MMMove(); Lawan2a.Move2(); Lawan2b.Move2();
                        Lawan3a.MMMove(); Lawan3b.MMMove(); Lawan3a.Move3(); Lawan3b.Move3();
                        Halang1a.MMMove(); Halang1b.MMMove(); Halang1a.Move1(); Halang1b.Move1();
                        Halang2a.MMMove(); Halang2b.MMMove(); Halang2a.Move2(); Halang2b.Move2();
                        Halang3a.MMMove(); Halang3b.MMMove(); Halang3a.Move3(); Halang3b.Move3();

                        if(Lawan1a.MLy1<1200){Lawan1a.Draw();} if(Halang1a.Py1<1200){Halang1a.Draw();}
                        if(Lawan2a.MLy2<1200){Lawan2a.Draw();} if(Halang2a.Py2<1200){Halang2a.Draw();}
                        if(Lawan3a.MLy3<1200){Lawan3a.Draw();} if(Halang3a.Py3<1200){Halang3a.Draw();}
                        if(Lawan1b.MLy1<1200){Lawan1b.Draw();} if(Halang1b.Py1<1200){Halang1b.Draw();}
                        if(Lawan2b.MLy2<1200){Lawan2b.Draw();} if(Halang2b.Py2<1200){Halang2b.Draw();}
                        if(Lawan3b.MLy3<1200){Lawan3b.Draw();} if(Halang3b.Py3<1200){Halang3b.Draw();}

                        Player.HitBox();
                        Lawan1a.HitBox(); Lawan1b.HitBox();
                        Lawan2a.HitBox(); Lawan2b.HitBox();
                        Lawan3a.HitBox(); Lawan3b.HitBox();
                        Halang1a.HitBox(); Halang1b.HitBox();
                        Halang2a.HitBox(); Halang2b.HitBox();
                        Halang3a.HitBox(); Halang3b.HitBox();

                        countrand1+=1;
                        if(randJalan1==-1){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;}}
                        if(countrand1==110){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1b.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1b.Py1=-100;}}
                        if(countrand1==220){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1c.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1c.Py1=-100;}}
                        if(countrand1==330){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;countrand1=0;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;countrand1=0;}if(randJalan1>=21){countrand1=0;}}
                        countrand2+=1;
                        if(randJalan2==-1){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;}}
                        if(countrand2==110){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2b.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2b.Py2=-100;}}
                        if(countrand2==220){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2c.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2c.Py2=-100;}}
                        if(countrand2==330){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;countrand2=0;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;countrand2=0;}if(randJalan2>=21){countrand2=0;}}
                        countrand3+=1;
                        if(randJalan3==-1){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;}}
                        if(countrand3==110){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3b.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3b.Py3=-100;}}
                        if(countrand3==220){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3c.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3c.Py3=-100;}}
                        if(countrand3==330){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;countrand3=0;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;countrand3=0;}if(randJalan3>=21){countrand3=0;}}

                        if(Lawan1a.setNyawa==3)
                        {
                            cekNyawa=3;
                        }
                        if(Lawan1a.setNyawa==2 || Lawan2a.setNyawa==2 || Lawan3a.setNyawa==2 || Halang1a.setNyawa==2 || Halang2a.setNyawa==2 || Halang3a.setNyawa==2 ||
                            Lawan1b.setNyawa==2 || Lawan2b.setNyawa==2 || Lawan3b.setNyawa==2 || Halang1b.setNyawa==2 || Halang2b.setNyawa==2 || Halang3b.setNyawa==2 ||
                            Lawan1c.setNyawa==2 || Lawan2c.setNyawa==2 || Lawan3c.setNyawa==2 || Halang1c.setNyawa==2 || Halang2c.setNyawa==2 || Halang3c.setNyawa==2 )
                        {
                            cekNyawa=2;
                            if(Lawan1a.setNyawa>2 || Lawan2a.setNyawa>2 || Lawan3a.setNyawa>2 || Halang1a.setNyawa>2 || Halang2a.setNyawa>2 || Halang3a.setNyawa>2 ||
                                Lawan1b.setNyawa>2 || Lawan2b.setNyawa>2 || Lawan3b.setNyawa>2 || Halang1b.setNyawa>2 || Halang2b.setNyawa>2 || Halang3b.setNyawa>2 ||
                                Lawan1c.setNyawa>2 || Lawan2c.setNyawa>2 || Lawan3c.setNyawa>2 || Halang1c.setNyawa>2 || Halang2c.setNyawa>2 || Halang3c.setNyawa>2 )
                            {
                                Lawan1a.setNyawa=2; Lawan2a.setNyawa=2; Lawan3a.setNyawa=2; Halang1a.setNyawa=2; Halang2a.setNyawa=2; Halang3a.setNyawa=2;
                                Lawan1b.setNyawa=2; Lawan2b.setNyawa=2; Lawan3b.setNyawa=2; Halang1b.setNyawa=2; Halang2b.setNyawa=2; Halang3b.setNyawa=2;
                                Lawan1c.setNyawa=2; Lawan2c.setNyawa=2; Lawan3c.setNyawa=2; Halang1c.setNyawa=2; Halang2c.setNyawa=2; Halang3c.setNyawa=2;
                            }
                        }
                        if(Lawan1a.setNyawa==1 || Lawan2a.setNyawa==1 || Lawan3a.setNyawa==1 || Halang1a.setNyawa==1 || Halang2a.setNyawa==1 || Halang3a.setNyawa==1 ||
                            Lawan1b.setNyawa==1 || Lawan2b.setNyawa==1 || Lawan3b.setNyawa==1 || Halang1b.setNyawa==1 || Halang2b.setNyawa==1 || Halang3b.setNyawa==1 ||
                            Lawan1c.setNyawa==1 || Lawan2c.setNyawa==1 || Lawan3c.setNyawa==1 || Halang1c.setNyawa==1 || Halang2c.setNyawa==1 || Halang3c.setNyawa==1 )
                        {
                            cekNyawa=1;
                            if(Lawan1a.setNyawa>1 || Lawan2a.setNyawa>1 || Lawan3a.setNyawa>1 || Halang1a.setNyawa>1 || Halang2a.setNyawa>1 || Halang3a.setNyawa>1 ||
                                Lawan1b.setNyawa>1 || Lawan2b.setNyawa>1 || Lawan3b.setNyawa>1 || Halang1b.setNyawa>1 || Halang2b.setNyawa>1 || Halang3b.setNyawa>1 ||
                                Lawan1c.setNyawa>1 || Lawan2c.setNyawa>1 || Lawan3c.setNyawa>1 || Halang1c.setNyawa>1 || Halang2c.setNyawa>1 || Halang3c.setNyawa>1 )
                            {
                                Lawan1a.setNyawa=1; Lawan2a.setNyawa=1; Lawan3a.setNyawa=1; Halang1a.setNyawa=1; Halang2a.setNyawa=1; Halang3a.setNyawa=1;
                                Lawan1b.setNyawa=1; Lawan2b.setNyawa=1; Lawan3b.setNyawa=1; Halang1b.setNyawa=1; Halang2b.setNyawa=1; Halang3b.setNyawa=1;
                                Lawan1c.setNyawa=1; Lawan2c.setNyawa=1; Lawan3c.setNyawa=1; Halang1c.setNyawa=1; Halang2c.setNyawa=1; Halang3c.setNyawa=1;
                            }
                        }
                        if(Lawan1a.setNyawa==0 || Lawan2a.setNyawa==0 || Lawan3a.setNyawa==0 || Halang1a.setNyawa==0 || Halang2a.setNyawa==0 || Halang3a.setNyawa==0 ||
                            Lawan1b.setNyawa==0 || Lawan2b.setNyawa==0 || Lawan3b.setNyawa==0 || Halang1b.setNyawa==0 || Halang2b.setNyawa==0 || Halang3b.setNyawa==0 ||
                            Lawan1c.setNyawa==0 || Lawan2c.setNyawa==0 || Lawan3c.setNyawa==0 || Halang1c.setNyawa==0 || Halang2c.setNyawa==0 || Halang3c.setNyawa==0 )
                        {
                            cekNyawa=0;
                            if(Lawan1a.setNyawa>0 || Lawan2a.setNyawa>0 || Lawan3a.setNyawa>0 || Halang1a.setNyawa>0 || Halang2a.setNyawa>0 || Halang3a.setNyawa>0 ||
                                Lawan1b.setNyawa>0 || Lawan2b.setNyawa>0 || Lawan3b.setNyawa>0 || Halang1b.setNyawa>0 || Halang2b.setNyawa>0 || Halang3b.setNyawa>0 ||
                                Lawan1c.setNyawa>0 || Lawan2c.setNyawa>0 || Lawan3c.setNyawa>0 || Halang1c.setNyawa>0 || Halang2c.setNyawa>0 || Halang3c.setNyawa>0 )
                            {
                                Lawan1a.setNyawa=0; Lawan2a.setNyawa=0; Lawan3a.setNyawa=0; Halang1a.setNyawa=0; Halang2a.setNyawa=0; Halang3a.setNyawa=0;
                                Lawan1b.setNyawa=0; Lawan2b.setNyawa=0; Lawan3b.setNyawa=0; Halang1b.setNyawa=0; Halang2b.setNyawa=0; Halang3b.setNyawa=0;
                                Lawan1c.setNyawa=0; Lawan2c.setNyawa=0; Lawan3c.setNyawa=0; Halang1c.setNyawa=0; Halang2c.setNyawa=0; Halang3c.setNyawa=0;
                            }
                        }
                        if(Lawan1a.setNyawa==-1 || Lawan2a.setNyawa==-1 || Lawan3a.setNyawa==-1 || Halang1a.setNyawa==-1 || Halang2a.setNyawa==-1 || Halang3a.setNyawa==-1 ||
                            Lawan1b.setNyawa==-1 || Lawan2b.setNyawa==-1 || Lawan3b.setNyawa==-1 || Halang1b.setNyawa==-1 || Halang2b.setNyawa==-1 || Halang3b.setNyawa==-1 ||
                            Lawan1c.setNyawa==-1 || Lawan2c.setNyawa==-1 || Lawan3c.setNyawa==-1 || Halang1c.setNyawa==-1 || Halang2c.setNyawa==-1 || Halang3c.setNyawa==-1 )
                        {
                            Poin3=CekPoin;
                            PapanScore.Set();
                            PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                            PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                            PapanScore.SetScore(3,200,Poin3,0,Poin3+0);
                            PapanScore.SetScore(4,300,Poin4,0,Poin4+0);
                            PapanScore.SetScore(5,400,Poin5,0,Poin5+0);
                            PapanScore.TotalScore(Poin1+200+Poin2+300+Poin3+0+Poin4+0+Poin5+0);
                            settextstyle(10, 0, 3);
                            outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                            if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                            {
                                countsc=0; countlb=0;
                                CekPoin=0; SetJarak.ResetJarak();
                                Menu.close = 1; Menu.level = 0;
                                yj=0; Jalan.py = 0;
                                LB=0; LBc=0;
                                sy=0; cy=0;
                                Player.ResetMobil(); StartPlayer.ResetMobil();
                                Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                Start=0;

                                if(Lawan1a.setNyawa<0 || Lawan2a.setNyawa<0 || Lawan3a.setNyawa<0 || Halang1a.setNyawa<0 || Halang2a.setNyawa<0 || Halang3a.setNyawa<0 ||
                                    Lawan1b.setNyawa<0 || Lawan2b.setNyawa<0 || Lawan3b.setNyawa<0 || Halang1b.setNyawa<0 || Halang2b.setNyawa<0 || Halang3b.setNyawa<0 ||
                                    Lawan1c.setNyawa<0 || Lawan2c.setNyawa<0 || Lawan3c.setNyawa<0 || Halang1c.setNyawa<0 || Halang2c.setNyawa<0 || Halang3c.setNyawa<0 )
                                {
                                    cekNyawa=3;
                                    Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                    Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                    Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                }
                            }
                        }

                        if(pelor.Ketembak1==1)
                        {
                            if(Lawan1a.MLy1<900){ if(Lawan1b.MLy1>Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1b.MLy1<Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1b.MLy1<900){ if(Lawan1c.MLy1>Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1c.MLy1<Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1c.MLy1<900){ if(Lawan1a.MLy1>Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan3a.MLy1<Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; }}
                        }
                        else if(pelor.Ketembak2==1)
                        {
                            if(Lawan2a.MLy2<900){ if(Lawan2b.MLy2>Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2b.MLy2<Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2b.MLy2<900){ if(Lawan2c.MLy2>Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2c.MLy2<Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2c.MLy2<900){ if(Lawan2a.MLy2>Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2a.MLy2<Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; }}
                        }
                        else if(pelor.Ketembak3==1)
                        {
                            if(Lawan3a.MLy3<900){ if(Lawan3b.MLy3>Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3b.MLy3<Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3b.MLy3<900){ if(Lawan3c.MLy3>Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3c.MLy3<Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3c.MLy3<900){ if(Lawan3a.MLy3>Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3a.MLy3<Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; }}
                        }
                        else if(pelor.Ketembak4==1)
                        {
                            pelor.Ketembak4=0;
                        }
                        else if(pelor.Ketembak5==1)
                        {
                            pelor.Ketembak5=0;
                        }
                        else if(pelor.Ketembak6==1)
                        {
                            pelor.Ketembak6=0;
                        }

                        if(pelor.poinNambah==1)
                        {
                            CekPoin = CekPoin + 15;
                            pelor.poinNambah=pelor.poinNambah-1;
                        }

                        if(setMobil.Ketabrak==0){ Player.s=2.5; }
                        if(Lawan1a.Ketabrak>0 && Lawan1a.Ketabrak<4){ Lawan1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1b.Ketabrak>0 && Lawan1b.Ketabrak<4){ Lawan1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1c.Ketabrak>0 && Lawan1c.Ketabrak<4){ Lawan1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2a.Ketabrak>0 && Lawan2a.Ketabrak<4){ Lawan2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2b.Ketabrak>0 && Lawan2b.Ketabrak<4){ Lawan2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2c.Ketabrak>0 && Lawan2c.Ketabrak<4){ Lawan2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3a.Ketabrak>0 && Lawan3a.Ketabrak<4){ Lawan3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3b.Ketabrak>0 && Lawan3b.Ketabrak<4){ Lawan3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3c.Ketabrak>0 && Lawan3c.Ketabrak<4){ Lawan3c.RespawnKetabrak(); Player.RespawnKetabrak(); }

                        if(Halang1a.Ketabrak>0 && Halang1a.Ketabrak<4){ Halang1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1b.Ketabrak>0 && Halang1b.Ketabrak<4){ Halang1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1c.Ketabrak>0 && Halang1c.Ketabrak<4){ Halang1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2a.Ketabrak>0 && Halang2a.Ketabrak<4){ Halang2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2b.Ketabrak>0 && Halang2b.Ketabrak<4){ Halang2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2c.Ketabrak>0 && Halang2c.Ketabrak<4){ Halang2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3a.Ketabrak>0 && Halang3a.Ketabrak<4){ Halang3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3b.Ketabrak>0 && Halang3b.Ketabrak<4){ Halang3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3c.Ketabrak>0 && Halang3c.Ketabrak<4){ Halang3c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                    }

                    if(Pause.pause==1)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.setPause(); Pause.Draw(); Pause.PilihPause(); Pause.SetPilihanPause();
                    }

                    if(Pause.pause==2)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.DrawYakin(); Pause.PilihYakin(); Pause.SetPilihanYakin();
                        if(Pause.pause==3)
                        {
                            countsc=0; countlb=0;
                            CekPoin=0; SetJarak.ResetJarak();
                            Menu.close = 1; Menu.level = 0;
                            Pause.pause=0; Pause.PilihanPause=0;
                            yj=0; Jalan.py = 0;
                            LB=0; LBc=0;
                            sy=0; cy=0;
                            Player.ResetMobil(); StartPlayer.ResetMobil();
                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                            Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                            Start=0;

                            if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                            {
                                cekNyawa=3;
                                Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                            }
                        }
                    }
                }
            }
        }

if(Menu.level == 4)
        {
            if(Start==0)
            {
                Loading1.Set(4,0);
                if(Loading1.blink==0){countb=countb+1; if(countb==30){Loading1.blink=800;countb=0;}}
                if(Loading1.blink==800){countb=countb+1; if(countb==30){Loading1.blink=0; countb=0;}}

                Loading1.LoadingCar(LB);
                LoadingMM.DrawMiring(); LoadingMM.MMx=670+LBc; LoadingMM.MMy=585; LoadingMM.s=1.6;
                if(LBc<570){LBc=LBc+4; if(LBc>100&&LBc<521){if(LB<420){LB=LB+4;}}}
                if(LBc>569){LBc=569; countlb=countlb+1; if(countlb==50){Start=1;}}
            }
            if(Start==1)
            {
                LoadingMM.s=0;
                Jalan.drawjalan(5);
                SetJarak.Set(5000); SetJarak.SetPoin(0);
                SetPoin.Set(0); SetPoin.Set(CekPoin);
                SetNyawa.Set(cekNyawa);

                StartPlayer.Draw(); StartPlayer.MMx=960;  StartPlayer.s = 2.5;
                StartPlayer.MMy = 1200-sy; sy = sy + 3;
                if(StartPlayer.MMy<900)
                {
                    if(Pause.pause==0)
                    {
                        Pause.setPause();
                        StartPlayer.s=0; StartPlayer.MMy=900;
                        SetJarak.PoinJarak(1); SetJarak.BarJarak(yj); yj=yj+0.1413;
                        if(yj>=701)
                        {
                            yj=701;
                            SetJarak.SetPoin(5000);
                            randJalan1=-2; randJalan2=-2; randJalan3=-2;
                            countrand1=0; countrand2=0; countrand3=0;
                            if(Lawan1a.MLy1>1100)
                            {
                                StartPlayer.Draw(); StartPlayer.s = 2.5; StartPlayer.MMx=Player.MMx;
                                StartPlayer.MMy = 900-cy; cy = cy + 3;
                                Player.s = 0;
                                if(StartPlayer.MMy<-50)
                                {
                                    Poin4=CekPoin;
                                    PapanScore.Set();
                                    PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                                    PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                                    PapanScore.SetScore(3,200,Poin3,400,Poin3+400);
                                    PapanScore.SetScore(4,300,Poin4,500,Poin4+500);
                                    if(countsc<300)
                                    {
                                        countsc=countsc+1;
                                        if(countsc==299)
                                        {
                                            countsc=0; countlb=0;
                                            CekPoin=0; SetJarak.ResetJarak();
                                            Menu.level = 5;
                                            yj=0; Jalan.py = 0;
                                            LB=0; LBc=0;
                                            sy=0; cy=0;
                                            Player.ResetMobil(); StartPlayer.ResetMobil();
                                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                            Start=0;
                                        }
                                    }
                                }
                            }
                        }

                        pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas();
                        pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan2a.MLy2, Lawan3a.MLy3, Halang1a.Py1, Halang2a.Py2, Halang3a.Py3);
                        pelor.HitBoxPeluru(Lawan1b.MLy1, Lawan2b.MLy2, Lawan3b.MLy3, Halang1b.Py1, Halang2b.Py2, Halang3b.Py3);
                        pelor.HitBoxPeluru(Lawan1c.MLy1, Lawan2c.MLy2, Lawan3c.MLy3, Halang1c.Py1, Halang2c.Py2, Halang3c.Py3);

                        Player.Draw(); Player.MMMove();
                        Lawan1a.MMMove(); Lawan1b.MMMove(); Lawan1a.Move1(); Lawan1b.Move1();
                        Lawan2a.MMMove(); Lawan2b.MMMove(); Lawan2a.Move2(); Lawan2b.Move2();
                        Lawan3a.MMMove(); Lawan3b.MMMove(); Lawan3a.Move3(); Lawan3b.Move3();
                        Halang1a.MMMove(); Halang1b.MMMove(); Halang1a.Move1(); Halang1b.Move1();
                        Halang2a.MMMove(); Halang2b.MMMove(); Halang2a.Move2(); Halang2b.Move2();
                        Halang3a.MMMove(); Halang3b.MMMove(); Halang3a.Move3(); Halang3b.Move3();

                        if(Lawan1a.MLy1<1200){Lawan1a.Draw();} if(Halang1a.Py1<1200){Halang1a.Draw();}
                        if(Lawan2a.MLy2<1200){Lawan2a.Draw();} if(Halang2a.Py2<1200){Halang2a.Draw();}
                        if(Lawan3a.MLy3<1200){Lawan3a.Draw();} if(Halang3a.Py3<1200){Halang3a.Draw();}
                        if(Lawan1b.MLy1<1200){Lawan1b.Draw();} if(Halang1b.Py1<1200){Halang1b.Draw();}
                        if(Lawan2b.MLy2<1200){Lawan2b.Draw();} if(Halang2b.Py2<1200){Halang2b.Draw();}
                        if(Lawan3b.MLy3<1200){Lawan3b.Draw();} if(Halang3b.Py3<1200){Halang3b.Draw();}

                        Player.HitBox();
                        Lawan1a.HitBox(); Lawan1b.HitBox();
                        Lawan2a.HitBox(); Lawan2b.HitBox();
                        Lawan3a.HitBox(); Lawan3b.HitBox();
                        Halang1a.HitBox(); Halang1b.HitBox();
                        Halang2a.HitBox(); Halang2b.HitBox();
                        Halang3a.HitBox(); Halang3b.HitBox();

                        countrand1+=1;
                        if(randJalan1==-1){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;}}
                        if(countrand1==110){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1b.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1b.Py1=-100;}}
                        if(countrand1==220){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1c.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1c.Py1=-100;}}
                        if(countrand1==330){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;countrand1=0;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;countrand1=0;}if(randJalan1>=21){countrand1=0;}}
                        countrand2+=1;
                        if(randJalan2==-1){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;}}
                        if(countrand2==110){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2b.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2b.Py2=-100;}}
                        if(countrand2==220){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2c.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2c.Py2=-100;}}
                        if(countrand2==330){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;countrand2=0;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;countrand2=0;}if(randJalan2>=21){countrand2=0;}}
                        countrand3+=1;
                        if(randJalan3==-1){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;}}
                        if(countrand3==110){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3b.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3b.Py3=-100;}}
                        if(countrand3==220){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3c.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3c.Py3=-100;}}
                        if(countrand3==330){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;countrand3=0;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;countrand3=0;}if(randJalan3>=21){countrand3=0;}}

                        if(Lawan1a.setNyawa==3)
                        {
                            cekNyawa=3;
                        }
                        if(Lawan1a.setNyawa==2 || Lawan2a.setNyawa==2 || Lawan3a.setNyawa==2 || Halang1a.setNyawa==2 || Halang2a.setNyawa==2 || Halang3a.setNyawa==2 ||
                            Lawan1b.setNyawa==2 || Lawan2b.setNyawa==2 || Lawan3b.setNyawa==2 || Halang1b.setNyawa==2 || Halang2b.setNyawa==2 || Halang3b.setNyawa==2 ||
                            Lawan1c.setNyawa==2 || Lawan2c.setNyawa==2 || Lawan3c.setNyawa==2 || Halang1c.setNyawa==2 || Halang2c.setNyawa==2 || Halang3c.setNyawa==2 )
                        {
                            cekNyawa=2;
                            if(Lawan1a.setNyawa>2 || Lawan2a.setNyawa>2 || Lawan3a.setNyawa>2 || Halang1a.setNyawa>2 || Halang2a.setNyawa>2 || Halang3a.setNyawa>2 ||
                                Lawan1b.setNyawa>2 || Lawan2b.setNyawa>2 || Lawan3b.setNyawa>2 || Halang1b.setNyawa>2 || Halang2b.setNyawa>2 || Halang3b.setNyawa>2 ||
                                Lawan1c.setNyawa>2 || Lawan2c.setNyawa>2 || Lawan3c.setNyawa>2 || Halang1c.setNyawa>2 || Halang2c.setNyawa>2 || Halang3c.setNyawa>2 )
                            {
                                Lawan1a.setNyawa=2; Lawan2a.setNyawa=2; Lawan3a.setNyawa=2; Halang1a.setNyawa=2; Halang2a.setNyawa=2; Halang3a.setNyawa=2;
                                Lawan1b.setNyawa=2; Lawan2b.setNyawa=2; Lawan3b.setNyawa=2; Halang1b.setNyawa=2; Halang2b.setNyawa=2; Halang3b.setNyawa=2;
                                Lawan1c.setNyawa=2; Lawan2c.setNyawa=2; Lawan3c.setNyawa=2; Halang1c.setNyawa=2; Halang2c.setNyawa=2; Halang3c.setNyawa=2;
                            }
                        }
                        if(Lawan1a.setNyawa==1 || Lawan2a.setNyawa==1 || Lawan3a.setNyawa==1 || Halang1a.setNyawa==1 || Halang2a.setNyawa==1 || Halang3a.setNyawa==1 ||
                            Lawan1b.setNyawa==1 || Lawan2b.setNyawa==1 || Lawan3b.setNyawa==1 || Halang1b.setNyawa==1 || Halang2b.setNyawa==1 || Halang3b.setNyawa==1 ||
                            Lawan1c.setNyawa==1 || Lawan2c.setNyawa==1 || Lawan3c.setNyawa==1 || Halang1c.setNyawa==1 || Halang2c.setNyawa==1 || Halang3c.setNyawa==1 )
                        {
                            cekNyawa=1;
                            if(Lawan1a.setNyawa>1 || Lawan2a.setNyawa>1 || Lawan3a.setNyawa>1 || Halang1a.setNyawa>1 || Halang2a.setNyawa>1 || Halang3a.setNyawa>1 ||
                                Lawan1b.setNyawa>1 || Lawan2b.setNyawa>1 || Lawan3b.setNyawa>1 || Halang1b.setNyawa>1 || Halang2b.setNyawa>1 || Halang3b.setNyawa>1 ||
                                Lawan1c.setNyawa>1 || Lawan2c.setNyawa>1 || Lawan3c.setNyawa>1 || Halang1c.setNyawa>1 || Halang2c.setNyawa>1 || Halang3c.setNyawa>1 )
                            {
                                Lawan1a.setNyawa=1; Lawan2a.setNyawa=1; Lawan3a.setNyawa=1; Halang1a.setNyawa=1; Halang2a.setNyawa=1; Halang3a.setNyawa=1;
                                Lawan1b.setNyawa=1; Lawan2b.setNyawa=1; Lawan3b.setNyawa=1; Halang1b.setNyawa=1; Halang2b.setNyawa=1; Halang3b.setNyawa=1;
                                Lawan1c.setNyawa=1; Lawan2c.setNyawa=1; Lawan3c.setNyawa=1; Halang1c.setNyawa=1; Halang2c.setNyawa=1; Halang3c.setNyawa=1;
                            }
                        }
                        if(Lawan1a.setNyawa==0 || Lawan2a.setNyawa==0 || Lawan3a.setNyawa==0 || Halang1a.setNyawa==0 || Halang2a.setNyawa==0 || Halang3a.setNyawa==0 ||
                            Lawan1b.setNyawa==0 || Lawan2b.setNyawa==0 || Lawan3b.setNyawa==0 || Halang1b.setNyawa==0 || Halang2b.setNyawa==0 || Halang3b.setNyawa==0 ||
                            Lawan1c.setNyawa==0 || Lawan2c.setNyawa==0 || Lawan3c.setNyawa==0 || Halang1c.setNyawa==0 || Halang2c.setNyawa==0 || Halang3c.setNyawa==0 )
                        {
                            cekNyawa=0;
                            if(Lawan1a.setNyawa>0 || Lawan2a.setNyawa>0 || Lawan3a.setNyawa>0 || Halang1a.setNyawa>0 || Halang2a.setNyawa>0 || Halang3a.setNyawa>0 ||
                                Lawan1b.setNyawa>0 || Lawan2b.setNyawa>0 || Lawan3b.setNyawa>0 || Halang1b.setNyawa>0 || Halang2b.setNyawa>0 || Halang3b.setNyawa>0 ||
                                Lawan1c.setNyawa>0 || Lawan2c.setNyawa>0 || Lawan3c.setNyawa>0 || Halang1c.setNyawa>0 || Halang2c.setNyawa>0 || Halang3c.setNyawa>0 )
                            {
                                Lawan1a.setNyawa=0; Lawan2a.setNyawa=0; Lawan3a.setNyawa=0; Halang1a.setNyawa=0; Halang2a.setNyawa=0; Halang3a.setNyawa=0;
                                Lawan1b.setNyawa=0; Lawan2b.setNyawa=0; Lawan3b.setNyawa=0; Halang1b.setNyawa=0; Halang2b.setNyawa=0; Halang3b.setNyawa=0;
                                Lawan1c.setNyawa=0; Lawan2c.setNyawa=0; Lawan3c.setNyawa=0; Halang1c.setNyawa=0; Halang2c.setNyawa=0; Halang3c.setNyawa=0;
                            }
                        }
                        if(Lawan1a.setNyawa==-1 || Lawan2a.setNyawa==-1 || Lawan3a.setNyawa==-1 || Halang1a.setNyawa==-1 || Halang2a.setNyawa==-1 || Halang3a.setNyawa==-1 ||
                            Lawan1b.setNyawa==-1 || Lawan2b.setNyawa==-1 || Lawan3b.setNyawa==-1 || Halang1b.setNyawa==-1 || Halang2b.setNyawa==-1 || Halang3b.setNyawa==-1 ||
                            Lawan1c.setNyawa==-1 || Lawan2c.setNyawa==-1 || Lawan3c.setNyawa==-1 || Halang1c.setNyawa==-1 || Halang2c.setNyawa==-1 || Halang3c.setNyawa==-1 )
                        {
                            Poin4=CekPoin;
                            PapanScore.Set();
                            PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                            PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                            PapanScore.SetScore(3,200,Poin3,400,Poin3+400);
                            PapanScore.SetScore(4,300,Poin4,0,Poin4+0);
                            PapanScore.SetScore(5,400,Poin5,0,Poin5+0);
                            PapanScore.TotalScore(Poin1+200+Poin2+300+Poin3+400+Poin4+0+Poin5+0);
                            settextstyle(10, 0, 3);
                            outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                            if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                            {
                                countsc=0; countlb=0;
                                CekPoin=0; SetJarak.ResetJarak();
                                Menu.close = 1; Menu.level = 0;
                                yj=0; Jalan.py = 0;
                                LB=0; LBc=0;
                                sy=0; cy=0;
                                Player.ResetMobil(); StartPlayer.ResetMobil();
                                Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                Start=0;

                                if(Lawan1a.setNyawa<0 || Lawan2a.setNyawa<0 || Lawan3a.setNyawa<0 || Halang1a.setNyawa<0 || Halang2a.setNyawa<0 || Halang3a.setNyawa<0 ||
                                    Lawan1b.setNyawa<0 || Lawan2b.setNyawa<0 || Lawan3b.setNyawa<0 || Halang1b.setNyawa<0 || Halang2b.setNyawa<0 || Halang3b.setNyawa<0 ||
                                    Lawan1c.setNyawa<0 || Lawan2c.setNyawa<0 || Lawan3c.setNyawa<0 || Halang1c.setNyawa<0 || Halang2c.setNyawa<0 || Halang3c.setNyawa<0 )
                                {
                                    cekNyawa=3;
                                    Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                    Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                    Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                }
                            }
                        }

                        if(pelor.Ketembak1==1)
                        {
                            if(Lawan1a.MLy1<900){ if(Lawan1b.MLy1>Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1b.MLy1<Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1b.MLy1<900){ if(Lawan1c.MLy1>Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1c.MLy1<Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1c.MLy1<900){ if(Lawan1a.MLy1>Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan3a.MLy1<Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; }}
                        }
                        else if(pelor.Ketembak2==1)
                        {
                            if(Lawan2a.MLy2<900){ if(Lawan2b.MLy2>Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2b.MLy2<Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2b.MLy2<900){ if(Lawan2c.MLy2>Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2c.MLy2<Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2c.MLy2<900){ if(Lawan2a.MLy2>Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2a.MLy2<Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; }}
                        }
                        else if(pelor.Ketembak3==1)
                        {
                            if(Lawan3a.MLy3<900){ if(Lawan3b.MLy3>Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3b.MLy3<Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3b.MLy3<900){ if(Lawan3c.MLy3>Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3c.MLy3<Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3c.MLy3<900){ if(Lawan3a.MLy3>Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3a.MLy3<Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; }}
                        }
                        else if(pelor.Ketembak4==1)
                        {
                            pelor.Ketembak4=0;
                        }
                        else if(pelor.Ketembak5==1)
                        {
                            pelor.Ketembak5=0;
                        }
                        else if(pelor.Ketembak6==1)
                        {
                            pelor.Ketembak6=0;
                        }

                        if(pelor.poinNambah==1)
                        {
                            CekPoin = CekPoin + 15;
                            pelor.poinNambah=pelor.poinNambah-1;
                        }

                        if(setMobil.Ketabrak==0){ Player.s=2.5; }
                        if(Lawan1a.Ketabrak>0 && Lawan1a.Ketabrak<4){ Lawan1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1b.Ketabrak>0 && Lawan1b.Ketabrak<4){ Lawan1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1c.Ketabrak>0 && Lawan1c.Ketabrak<4){ Lawan1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2a.Ketabrak>0 && Lawan2a.Ketabrak<4){ Lawan2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2b.Ketabrak>0 && Lawan2b.Ketabrak<4){ Lawan2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2c.Ketabrak>0 && Lawan2c.Ketabrak<4){ Lawan2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3a.Ketabrak>0 && Lawan3a.Ketabrak<4){ Lawan3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3b.Ketabrak>0 && Lawan3b.Ketabrak<4){ Lawan3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3c.Ketabrak>0 && Lawan3c.Ketabrak<4){ Lawan3c.RespawnKetabrak(); Player.RespawnKetabrak(); }

                        if(Halang1a.Ketabrak>0 && Halang1a.Ketabrak<4){ Halang1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1b.Ketabrak>0 && Halang1b.Ketabrak<4){ Halang1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1c.Ketabrak>0 && Halang1c.Ketabrak<4){ Halang1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2a.Ketabrak>0 && Halang2a.Ketabrak<4){ Halang2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2b.Ketabrak>0 && Halang2b.Ketabrak<4){ Halang2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2c.Ketabrak>0 && Halang2c.Ketabrak<4){ Halang2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3a.Ketabrak>0 && Halang3a.Ketabrak<4){ Halang3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3b.Ketabrak>0 && Halang3b.Ketabrak<4){ Halang3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3c.Ketabrak>0 && Halang3c.Ketabrak<4){ Halang3c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                    }

                    if(Pause.pause==1)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.setPause(); Pause.Draw(); Pause.PilihPause(); Pause.SetPilihanPause();
                    }

                    if(Pause.pause==2)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.DrawYakin(); Pause.PilihYakin(); Pause.SetPilihanYakin();
                        if(Pause.pause==3)
                        {
                            countsc=0; countlb=0;
                            CekPoin=0; SetJarak.ResetJarak();
                            Menu.close = 1; Menu.level = 0;
                            Pause.pause=0; Pause.PilihanPause=0;
                            yj=0; Jalan.py = 0;
                            LB=0; LBc=0;
                            sy=0; cy=0;
                            Player.ResetMobil(); StartPlayer.ResetMobil();
                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                            Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                            Start=0;
                            if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                            {
                                cekNyawa=3;
                                Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                            }
                        }
                    }
                }
            }
        }

if(Menu.level == 5)
        {
            if(Start==0)
            {
                Loading1.Set(5,0);
                if(Loading1.blink==0){countb=countb+1; if(countb==30){Loading1.blink=800;countb=0;}}
                if(Loading1.blink==800){countb=countb+1; if(countb==30){Loading1.blink=0; countb=0;}}

                Loading1.LoadingCar(LB);
                LoadingMM.DrawMiring(); LoadingMM.MMx=670+LBc; LoadingMM.MMy=585; LoadingMM.s=1.6;
                if(LBc<570){LBc=LBc+4; if(LBc>100&&LBc<521){if(LB<420){LB=LB+4;}}}
                if(LBc>569){LBc=569; countlb=countlb+1; if(countlb==50){Start=1;}}
            }
            if(Start==1)
            {
                LoadingMM.s=0;
                Jalan.drawjalan(5);
                SetJarak.Set(6000); SetJarak.SetPoin(0);
                SetPoin.Set(0); SetPoin.Set(CekPoin);
                SetNyawa.Set(cekNyawa);

                StartPlayer.Draw(); StartPlayer.MMx=960;  StartPlayer.s = 2.5;
                StartPlayer.MMy = 1200-sy; sy = sy + 3;
                if(StartPlayer.MMy<900)
                {
                    if(Pause.pause==0)
                    {
                        Pause.setPause();
                        StartPlayer.s=0; StartPlayer.MMy=900;
                        SetJarak.PoinJarak(1); SetJarak.BarJarak(yj); yj=yj+0.118;
                        if(yj>=701)
                        {
                            yj=701;
                            SetJarak.SetPoin(6000);
                            randJalan1=-2; randJalan2=-2; randJalan3=-2;
                            countrand1=0; countrand2=0; countrand3=0;
                            if(Lawan1a.MLy1>1100)
                            {
                                StartPlayer.Draw(); StartPlayer.s = 2.5; StartPlayer.MMx=Player.MMx;
                                StartPlayer.MMy = 900-cy; cy = cy + 3;
                                Player.s = 0;
                                if(StartPlayer.MMy<-50)
                                {
                                    Poin5=CekPoin;
                                    PapanScore.Set();
                                    PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                                    PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                                    PapanScore.SetScore(3,200,Poin3,400,Poin3+400);
                                    PapanScore.SetScore(4,300,Poin4,500,Poin4+500);
                                    PapanScore.SetScore(5,400,Poin5,600,Poin5+600);
                                    PapanScore.TotalScore(Poin1+200+Poin2+300+Poin3+400+Poin4+500+Poin5+600);
                                    settextstyle(10, 0, 3);
                                    outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                                    if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                                    {
                                        countsc=0; countlb=0;
                                        CekPoin=0; SetJarak.ResetJarak();
                                        Menu.close = 1; Menu.level = 0;
                                        yj=0; Jalan.py = 0;
                                        LB=0; LBc=0;
                                        sy=0; cy=0;
                                        Player.ResetMobil(); StartPlayer.ResetMobil();
                                        Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                        Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                        Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                        Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                        Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                        Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                        Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                        Start=0;

                                        if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                            Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                            Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                                        {
                                            cekNyawa=3;
                                            Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                            Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                            Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                        }
                                    }
                                }
                            }
                        }

                        pelor.SetPosPeluru(Player.MMx,StartPlayer.MMy); pelor.Tembak(); pelor.PeluruKeAtas();
                        pelor.HitBoxPeluru(Lawan1a.MLy1, Lawan2a.MLy2, Lawan3a.MLy3, Halang1a.Py1, Halang2a.Py2, Halang3a.Py3);
                        pelor.HitBoxPeluru(Lawan1b.MLy1, Lawan2b.MLy2, Lawan3b.MLy3, Halang1b.Py1, Halang2b.Py2, Halang3b.Py3);
                        pelor.HitBoxPeluru(Lawan1c.MLy1, Lawan2c.MLy2, Lawan3c.MLy3, Halang1c.Py1, Halang2c.Py2, Halang3c.Py3);

                        Player.Draw(); Player.MMMove();
                        Lawan1a.MMMove(); Lawan1b.MMMove(); Lawan1a.Move1(); Lawan1b.Move1();
                        Lawan2a.MMMove(); Lawan2b.MMMove(); Lawan2a.Move2(); Lawan2b.Move2();
                        Lawan3a.MMMove(); Lawan3b.MMMove(); Lawan3a.Move3(); Lawan3b.Move3();
                        Halang1a.MMMove(); Halang1b.MMMove(); Halang1a.Move1(); Halang1b.Move1();
                        Halang2a.MMMove(); Halang2b.MMMove(); Halang2a.Move2(); Halang2b.Move2();
                        Halang3a.MMMove(); Halang3b.MMMove(); Halang3a.Move3(); Halang3b.Move3();

                        if(Lawan1a.MLy1<1200){Lawan1a.Draw();} if(Halang1a.Py1<1200){Halang1a.Draw();}
                        if(Lawan2a.MLy2<1200){Lawan2a.Draw();} if(Halang2a.Py2<1200){Halang2a.Draw();}
                        if(Lawan3a.MLy3<1200){Lawan3a.Draw();} if(Halang3a.Py3<1200){Halang3a.Draw();}
                        if(Lawan1b.MLy1<1200){Lawan1b.Draw();} if(Halang1b.Py1<1200){Halang1b.Draw();}
                        if(Lawan2b.MLy2<1200){Lawan2b.Draw();} if(Halang2b.Py2<1200){Halang2b.Draw();}
                        if(Lawan3b.MLy3<1200){Lawan3b.Draw();} if(Halang3b.Py3<1200){Halang3b.Draw();}

                        Player.HitBox();
                        Lawan1a.HitBox(); Lawan1b.HitBox();
                        Lawan2a.HitBox(); Lawan2b.HitBox();
                        Lawan3a.HitBox(); Lawan3b.HitBox();
                        Halang1a.HitBox(); Halang1b.HitBox();
                        Halang2a.HitBox(); Halang2b.HitBox();
                        Halang3a.HitBox(); Halang3b.HitBox();

                        countrand1+=1;
                        if(randJalan1==-1){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;}}
                        if(countrand1==110){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1b.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1b.Py1=-100;}}
                        if(countrand1==220){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1c.MLy1=-100;}if(randJalan1>=11 && randJalan1<=20){Halang1c.Py1=-100;}}
                        if(countrand1==330){randJalan1=rand() % 30 +1;if(randJalan1>=1 && randJalan1<=10){Lawan1a.MLy1=-100;countrand1=0;}if(randJalan1>=11 && randJalan1<=20){Halang1a.Py1=-100;countrand1=0;}if(randJalan1>=21){countrand1=0;}}
                        countrand2+=1;
                        if(randJalan2==-1){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;}}
                        if(countrand2==110){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2b.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2b.Py2=-100;}}
                        if(countrand2==220){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2c.MLy2=-100;}if(randJalan2>=11 && randJalan2<=20){Halang2c.Py2=-100;}}
                        if(countrand2==330){randJalan2=rand() % 30 +1;if(randJalan2>=1 && randJalan2<=10){Lawan2a.MLy2=-100;countrand2=0;}if(randJalan2>=11 && randJalan2<=20){Halang2a.Py2=-100;countrand2=0;}if(randJalan2>=21){countrand2=0;}}
                        countrand3+=1;
                        if(randJalan3==-1){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;}}
                        if(countrand3==110){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3b.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3b.Py3=-100;}}
                        if(countrand3==220){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3c.MLy3=-100;}if(randJalan3>=11 && randJalan3<=20){Halang3c.Py3=-100;}}
                        if(countrand3==330){randJalan3=rand() % 30 +1;if(randJalan3>=1 && randJalan3<=10){Lawan3a.MLy3=-100;countrand3=0;}if(randJalan3>=11 && randJalan3<=20){Halang3a.Py3=-100;countrand3=0;}if(randJalan3>=21){countrand3=0;}}

                        if(Lawan1a.setNyawa==3)
                        {
                            cekNyawa=3;
                        }
                        if(Lawan1a.setNyawa==2 || Lawan2a.setNyawa==2 || Lawan3a.setNyawa==2 || Halang1a.setNyawa==2 || Halang2a.setNyawa==2 || Halang3a.setNyawa==2 ||
                            Lawan1b.setNyawa==2 || Lawan2b.setNyawa==2 || Lawan3b.setNyawa==2 || Halang1b.setNyawa==2 || Halang2b.setNyawa==2 || Halang3b.setNyawa==2 ||
                            Lawan1c.setNyawa==2 || Lawan2c.setNyawa==2 || Lawan3c.setNyawa==2 || Halang1c.setNyawa==2 || Halang2c.setNyawa==2 || Halang3c.setNyawa==2 )
                        {
                            cekNyawa=2;
                            if(Lawan1a.setNyawa>2 || Lawan2a.setNyawa>2 || Lawan3a.setNyawa>2 || Halang1a.setNyawa>2 || Halang2a.setNyawa>2 || Halang3a.setNyawa>2 ||
                                Lawan1b.setNyawa>2 || Lawan2b.setNyawa>2 || Lawan3b.setNyawa>2 || Halang1b.setNyawa>2 || Halang2b.setNyawa>2 || Halang3b.setNyawa>2 ||
                                Lawan1c.setNyawa>2 || Lawan2c.setNyawa>2 || Lawan3c.setNyawa>2 || Halang1c.setNyawa>2 || Halang2c.setNyawa>2 || Halang3c.setNyawa>2 )
                            {
                                Lawan1a.setNyawa=2; Lawan2a.setNyawa=2; Lawan3a.setNyawa=2; Halang1a.setNyawa=2; Halang2a.setNyawa=2; Halang3a.setNyawa=2;
                                Lawan1b.setNyawa=2; Lawan2b.setNyawa=2; Lawan3b.setNyawa=2; Halang1b.setNyawa=2; Halang2b.setNyawa=2; Halang3b.setNyawa=2;
                                Lawan1c.setNyawa=2; Lawan2c.setNyawa=2; Lawan3c.setNyawa=2; Halang1c.setNyawa=2; Halang2c.setNyawa=2; Halang3c.setNyawa=2;
                            }
                        }
                        if(Lawan1a.setNyawa==1 || Lawan2a.setNyawa==1 || Lawan3a.setNyawa==1 || Halang1a.setNyawa==1 || Halang2a.setNyawa==1 || Halang3a.setNyawa==1 ||
                            Lawan1b.setNyawa==1 || Lawan2b.setNyawa==1 || Lawan3b.setNyawa==1 || Halang1b.setNyawa==1 || Halang2b.setNyawa==1 || Halang3b.setNyawa==1 ||
                            Lawan1c.setNyawa==1 || Lawan2c.setNyawa==1 || Lawan3c.setNyawa==1 || Halang1c.setNyawa==1 || Halang2c.setNyawa==1 || Halang3c.setNyawa==1 )
                        {
                            cekNyawa=1;
                            if(Lawan1a.setNyawa>1 || Lawan2a.setNyawa>1 || Lawan3a.setNyawa>1 || Halang1a.setNyawa>1 || Halang2a.setNyawa>1 || Halang3a.setNyawa>1 ||
                                Lawan1b.setNyawa>1 || Lawan2b.setNyawa>1 || Lawan3b.setNyawa>1 || Halang1b.setNyawa>1 || Halang2b.setNyawa>1 || Halang3b.setNyawa>1 ||
                                Lawan1c.setNyawa>1 || Lawan2c.setNyawa>1 || Lawan3c.setNyawa>1 || Halang1c.setNyawa>1 || Halang2c.setNyawa>1 || Halang3c.setNyawa>1 )
                            {
                                Lawan1a.setNyawa=1; Lawan2a.setNyawa=1; Lawan3a.setNyawa=1; Halang1a.setNyawa=1; Halang2a.setNyawa=1; Halang3a.setNyawa=1;
                                Lawan1b.setNyawa=1; Lawan2b.setNyawa=1; Lawan3b.setNyawa=1; Halang1b.setNyawa=1; Halang2b.setNyawa=1; Halang3b.setNyawa=1;
                                Lawan1c.setNyawa=1; Lawan2c.setNyawa=1; Lawan3c.setNyawa=1; Halang1c.setNyawa=1; Halang2c.setNyawa=1; Halang3c.setNyawa=1;
                            }
                        }
                        if(Lawan1a.setNyawa==0 || Lawan2a.setNyawa==0 || Lawan3a.setNyawa==0 || Halang1a.setNyawa==0 || Halang2a.setNyawa==0 || Halang3a.setNyawa==0 ||
                            Lawan1b.setNyawa==0 || Lawan2b.setNyawa==0 || Lawan3b.setNyawa==0 || Halang1b.setNyawa==0 || Halang2b.setNyawa==0 || Halang3b.setNyawa==0 ||
                            Lawan1c.setNyawa==0 || Lawan2c.setNyawa==0 || Lawan3c.setNyawa==0 || Halang1c.setNyawa==0 || Halang2c.setNyawa==0 || Halang3c.setNyawa==0 )
                        {
                            cekNyawa=0;
                            if(Lawan1a.setNyawa>0 || Lawan2a.setNyawa>0 || Lawan3a.setNyawa>0 || Halang1a.setNyawa>0 || Halang2a.setNyawa>0 || Halang3a.setNyawa>0 ||
                                Lawan1b.setNyawa>0 || Lawan2b.setNyawa>0 || Lawan3b.setNyawa>0 || Halang1b.setNyawa>0 || Halang2b.setNyawa>0 || Halang3b.setNyawa>0 ||
                                Lawan1c.setNyawa>0 || Lawan2c.setNyawa>0 || Lawan3c.setNyawa>0 || Halang1c.setNyawa>0 || Halang2c.setNyawa>0 || Halang3c.setNyawa>0 )
                            {
                                Lawan1a.setNyawa=0; Lawan2a.setNyawa=0; Lawan3a.setNyawa=0; Halang1a.setNyawa=0; Halang2a.setNyawa=0; Halang3a.setNyawa=0;
                                Lawan1b.setNyawa=0; Lawan2b.setNyawa=0; Lawan3b.setNyawa=0; Halang1b.setNyawa=0; Halang2b.setNyawa=0; Halang3b.setNyawa=0;
                                Lawan1c.setNyawa=0; Lawan2c.setNyawa=0; Lawan3c.setNyawa=0; Halang1c.setNyawa=0; Halang2c.setNyawa=0; Halang3c.setNyawa=0;
                            }
                        }
                        if(Lawan1a.setNyawa==-1 || Lawan2a.setNyawa==-1 || Lawan3a.setNyawa==-1 || Halang1a.setNyawa==-1 || Halang2a.setNyawa==-1 || Halang3a.setNyawa==-1 ||
                            Lawan1b.setNyawa==-1 || Lawan2b.setNyawa==-1 || Lawan3b.setNyawa==-1 || Halang1b.setNyawa==-1 || Halang2b.setNyawa==-1 || Halang3b.setNyawa==-1 ||
                            Lawan1c.setNyawa==-1 || Lawan2c.setNyawa==-1 || Lawan3c.setNyawa==-1 || Halang1c.setNyawa==-1 || Halang2c.setNyawa==-1 || Halang3c.setNyawa==-1 )
                        {
                            Poin5=CekPoin;
                            PapanScore.Set();
                            PapanScore.SetScore(1,0,Poin1,200,Poin1+200);
                            PapanScore.SetScore(2,100,Poin2,300,Poin2+300);
                            PapanScore.SetScore(3,200,Poin3,400,Poin3+400);
                            PapanScore.SetScore(4,300,Poin4,500,Poin4+500);
                            PapanScore.SetScore(5,400,Poin5,0,Poin5+0);
                            PapanScore.TotalScore(Poin1+200+Poin2+300+Poin3+400+Poin4+500+Poin5+0);
                            settextstyle(10, 0, 3);
                            outtextxy(720, 970, "Tekan Spasi Untuk Kembali Ke Menu");
                            if(GetAsyncKeyState(VK_SPACE) & (0x8000) != 0)
                            {
                                countsc=0; countlb=0;
                                CekPoin=0; SetJarak.ResetJarak();
                                Menu.close = 1; Menu.level = 0;
                                yj=0; Jalan.py = 0;
                                LB=0; LBc=0;
                                sy=0; cy=0;
                                Player.ResetMobil(); StartPlayer.ResetMobil();
                                Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                                Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                                Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                                Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                                Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                                Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                                Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                                Start=0;

                                if(Lawan1a.setNyawa<0 || Lawan2a.setNyawa<0 || Lawan3a.setNyawa<0 || Halang1a.setNyawa<0 || Halang2a.setNyawa<0 || Halang3a.setNyawa<0 ||
                                    Lawan1b.setNyawa<0 || Lawan2b.setNyawa<0 || Lawan3b.setNyawa<0 || Halang1b.setNyawa<0 || Halang2b.setNyawa<0 || Halang3b.setNyawa<0 ||
                                    Lawan1c.setNyawa<0 || Lawan2c.setNyawa<0 || Lawan3c.setNyawa<0 || Halang1c.setNyawa<0 || Halang2c.setNyawa<0 || Halang3c.setNyawa<0 )
                                {
                                    cekNyawa=3;
                                    Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                    Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                    Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                                }
                            }
                        }

                        if(pelor.Ketembak1==1)
                        {
                            if(Lawan1a.MLy1<900){ if(Lawan1b.MLy1>Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1b.MLy1<Lawan1a.MLy1){ Lawan1a.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1b.MLy1<900){ if(Lawan1c.MLy1>Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan1c.MLy1<Lawan1b.MLy1){ Lawan1b.resetMLy1(); pelor.Ketembak1=0; }}
                            else if(Lawan1c.MLy1<900){ if(Lawan1a.MLy1>Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; } else if(Lawan3a.MLy1<Lawan3c.MLy1){ Lawan1c.resetMLy1(); pelor.Ketembak1=0; }}
                        }
                        else if(pelor.Ketembak2==1)
                        {
                            if(Lawan2a.MLy2<900){ if(Lawan2b.MLy2>Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2b.MLy2<Lawan2a.MLy2){ Lawan2a.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2b.MLy2<900){ if(Lawan2c.MLy2>Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2c.MLy2<Lawan2b.MLy2){ Lawan2b.resetMLy2(); pelor.Ketembak2=0; }}
                            else if(Lawan2c.MLy2<900){ if(Lawan2a.MLy2>Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; } else if(Lawan2a.MLy2<Lawan2c.MLy2){ Lawan2c.resetMLy2(); pelor.Ketembak2=0; }}
                        }
                        else if(pelor.Ketembak3==1)
                        {
                            if(Lawan3a.MLy3<900){ if(Lawan3b.MLy3>Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3b.MLy3<Lawan3a.MLy3){ Lawan3a.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3b.MLy3<900){ if(Lawan3c.MLy3>Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3c.MLy3<Lawan3b.MLy3){ Lawan3b.resetMLy3(); pelor.Ketembak3=0; }}
                            else if(Lawan3c.MLy3<900){ if(Lawan3a.MLy3>Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; } else if(Lawan3a.MLy3<Lawan3c.MLy3){ Lawan3c.resetMLy3(); pelor.Ketembak3=0; }}
                        }
                        else if(pelor.Ketembak4==1)
                        {
                            pelor.Ketembak4=0;
                        }
                        else if(pelor.Ketembak5==1)
                        {
                            pelor.Ketembak5=0;
                        }
                        else if(pelor.Ketembak6==1)
                        {
                            pelor.Ketembak6=0;
                        }

                        if(pelor.poinNambah==1)
                        {
                            CekPoin = CekPoin + 15;
                            pelor.poinNambah=pelor.poinNambah-1;
                        }

                        if(setMobil.Ketabrak==0){ Player.s=2.5; }
                        if(Lawan1a.Ketabrak>0 && Lawan1a.Ketabrak<4){ Lawan1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1b.Ketabrak>0 && Lawan1b.Ketabrak<4){ Lawan1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan1c.Ketabrak>0 && Lawan1c.Ketabrak<4){ Lawan1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2a.Ketabrak>0 && Lawan2a.Ketabrak<4){ Lawan2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2b.Ketabrak>0 && Lawan2b.Ketabrak<4){ Lawan2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan2c.Ketabrak>0 && Lawan2c.Ketabrak<4){ Lawan2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3a.Ketabrak>0 && Lawan3a.Ketabrak<4){ Lawan3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3b.Ketabrak>0 && Lawan3b.Ketabrak<4){ Lawan3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Lawan3c.Ketabrak>0 && Lawan3c.Ketabrak<4){ Lawan3c.RespawnKetabrak(); Player.RespawnKetabrak(); }

                        if(Halang1a.Ketabrak>0 && Halang1a.Ketabrak<4){ Halang1a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1b.Ketabrak>0 && Halang1b.Ketabrak<4){ Halang1b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang1c.Ketabrak>0 && Halang1c.Ketabrak<4){ Halang1c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2a.Ketabrak>0 && Halang2a.Ketabrak<4){ Halang2a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2b.Ketabrak>0 && Halang2b.Ketabrak<4){ Halang2b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang2c.Ketabrak>0 && Halang2c.Ketabrak<4){ Halang2c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3a.Ketabrak>0 && Halang3a.Ketabrak<4){ Halang3a.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3b.Ketabrak>0 && Halang3b.Ketabrak<4){ Halang3b.RespawnKetabrak(); Player.RespawnKetabrak(); }
                        if(Halang3c.Ketabrak>0 && Halang3c.Ketabrak<4){ Halang3c.RespawnKetabrak(); Player.RespawnKetabrak(); }
                    }

                    if(Pause.pause==1)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.setPause(); Pause.Draw(); Pause.PilihPause(); Pause.SetPilihanPause();
                    }

                    if(Pause.pause==2)
                    {
                        setfillstyle(1,GREEN);
                        bar(0,0,1920,1080);
                        Pause.DrawYakin(); Pause.PilihYakin(); Pause.SetPilihanYakin();
                        if(Pause.pause==3)
                        {
                            countsc=0; countlb=0;
                            CekPoin=0; SetJarak.ResetJarak();
                            Menu.close = 1; Menu.level = 0;
                            Pause.pause=0; Pause.PilihanPause=0;
                            yj=0; Jalan.py = 0;
                            LB=0; LBc=0;
                            sy=0; cy=0;
                            Player.ResetMobil(); StartPlayer.ResetMobil();
                            Lawan1a.resetMLy1(); Lawan1b.resetMLy1(); Lawan1c.resetMLy1();
                            Lawan2a.resetMLy2(); Lawan2b.resetMLy2(); Lawan2c.resetMLy2();
                            Lawan3a.resetMLy3(); Lawan3b.resetMLy3(); Lawan3c.resetMLy3();
                            Halang1a.resetPy1(); Halang1b.resetPy1(); Halang1c.resetPy1();
                            Halang2a.resetPy2(); Halang2b.resetPy2(); Halang2c.resetPy2();
                            Halang3a.resetPy3(); Halang3b.resetPy3(); Halang3c.resetPy3();
                            Poin1=0; Poin2=0; Poin3=0; Poin4=0; Poin5=0;
                            Start=0;

                            if(Lawan1a.setNyawa>-1 || Lawan2a.setNyawa>-1 || Lawan3a.setNyawa>-1 || Halang1a.setNyawa>-1 || Halang2a.setNyawa>-1 || Halang3a.setNyawa>-1 ||
                                Lawan1b.setNyawa>-1 || Lawan2b.setNyawa>-1 || Lawan3b.setNyawa>-1 || Halang1b.setNyawa>-1 || Halang2b.setNyawa>-1 || Halang3b.setNyawa>-1 ||
                                Lawan1c.setNyawa>-1 || Lawan2c.setNyawa>-1 || Lawan3c.setNyawa>-1 || Halang1c.setNyawa>-1 || Halang2c.setNyawa>-1 || Halang3c.setNyawa>-1 )
                            {
                                cekNyawa=3;
                                Lawan1a.setNyawa=3; Lawan2a.setNyawa=3; Lawan3a.setNyawa=3; Halang1a.setNyawa=3; Halang2a.setNyawa=3; Halang3a.setNyawa=3;
                                Lawan1b.setNyawa=3; Lawan2b.setNyawa=3; Lawan3b.setNyawa=3; Halang1b.setNyawa=3; Halang2b.setNyawa=3; Halang3b.setNyawa=3;
                                Lawan1c.setNyawa=3; Lawan2c.setNyawa=3; Lawan3c.setNyawa=3; Halang1c.setNyawa=3; Halang2c.setNyawa=3; Halang3c.setNyawa=3;
                            }
                        }
                    }
                }
            }
        }

        page = 1 - page;
        delay(5);
        }

    setvisualpage(1 - page);
    getch();
    closegraph();
}
