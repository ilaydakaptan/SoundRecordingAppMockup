#include "icb_gui.h"
#include "ic_media.h"

extern ICBDIAG diag;

int MLE, F1, BMP_BTN_RECORD, BMP_BTN_TRANSFORM, BMP_BTN_SUBMIT;
int flagSuccess = 0;
int flagSubmit = 0;
int BMP_BTN;
int MLE_Button1, MLE_Button2, MLE_Button3;
int Button_1, Button_2, Button_3;
int FRM, FRM2, FRM3, FRM4;

unsigned int randSeed = 123456789;

unsigned int customRand() {
    randSeed = randSeed * 1103515245 + 12345;
    return (randSeed / 65536) % 32768;
}

void ICGUI_Create()
{
    ICG_MWTitle("Batuhan A�AN / �layda KAPTAN Mockup");
    ICG_MWSize(480, 970);
}

void* wave(LPVOID vv) {

    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    int x = 255;
    unsigned background_color = 0x001D49;
    CreateImage(Button_Image, 275, 85, ICB_UINT);
    Button_Image = background_color;

    while (1) {
        FillRect(Button_Image, 0, 0, 275, 85, background_color);
        int waveAmplitude = 20;
        int waveWidth = 10;
        int waveSpacing = 5;

        int xPosition = -150;
        int waveHeight = (customRand() % (2 * waveAmplitude + 1)) - waveAmplitude;

        while (xPosition < 275) {
            if (waveHeight > 0) {
                FillRect(Button_Image, xPosition, 85 / 2 - waveHeight, waveWidth, 2 * waveHeight, 0xff00);
            }
            else {
                FillRect(Button_Image, xPosition, 85 / 2, waveWidth, -2 * waveHeight, 0xff00);
            }
            xPosition += waveWidth + waveSpacing;
            waveHeight = (customRand() % (2 * waveAmplitude + 1)) - waveAmplitude;
        }
        DisplayImage(FRM2, Button_Image);

        Sleep(120);
        x -= 10;
        if (x < -275) x = -265;
    }

}

void* recordButton(LPVOID vv)
{

    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    unsigned background_color = 0x3e9bed;
    CreateImage(Button_Image, 150, 40, ICB_UINT);
    Button_Image = background_color;

    const char* den = "RECORD";
    Impress12x20(Button_Image, 55, 15, den, 0xffffff);

    int x = 30;
    int radius = 14;
    Circle(Button_Image, x, 20, 15, 0xffffff);

    while (1)
    {
        int flag = 0;
        FillCircle(Button_Image, x, 20, radius, 0x2400a6);
        FillRect(Button_Image, x - 5, 15, 10, 10, 0x2400a6);
        SetButtonBitmap(BMP_BTN_RECORD, Button_Image);
        Sleep(100);
        radius -= 1;

        if (radius <= 1) {
            flag = 1; // En k���k halinde flag'i ayarla
        }

        FillCircle(Button_Image, x, 20, 14, background_color); // Temizle

        // �kinci i� d�ng�: flag kontrol� ile

        while (flag == 1)
        {
            FillCircle(Button_Image, x, 20, radius, 0x2400a6);
            FillRect(Button_Image, x - 5, 15, 10, 10, 0x2400a6);
            SetButtonBitmap(BMP_BTN_RECORD, Button_Image);
            Sleep(100);
            radius += 1;

            if (radius >= 14) {
                flag = 0; // flag'i s�f�rla ve i� d�ng�den ��k
            }
        }
    }

}

void Record()
{
    int parameter = 5;
    DWORD dw;

    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)wave, &parameter, 0, &dw);

    ICG_printf(MLE, "Recording voices\n");
}

void* transformButton(LPVOID vv)
{
    // transform butonuna t�klan�nca ger�ekle�enler

    flagSuccess = 1;

    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    unsigned background_color = 0x51e062;
    CreateImage(Button_Image, 150, 40, ICB_UINT);
    Button_Image = background_color;

    ICBYTES check, success;

    int counter = 0;

    while (1) {

        if (counter <= 4 && flagSuccess == 1) {
            FillRect(Button_Image, 50, 5, 40, 32, 0x51e062); //Temizle

            HalfRect(Button_Image, 70, 10, 6, -6, 0x000000);
            HalfRect(Button_Image, 70, 10, 6, 6, 0x000000);
            Circle(Button_Image, 70, 21, 12, 0x000000);
            FillRect(Button_Image, 76, 10, 7, 15, 0x51e062);
            SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
            Sleep(200);

            FillRect(Button_Image, 50, 5, 40, 32, 0x51e062); //Temizle

            HalfRect(Button_Image, 81, 20, 6, 6, 0x000000);
            HalfRect(Button_Image, 81, 20, -6, 6, 0x000000);
            Circle(Button_Image, 70, 21, 12, 0x000000);
            FillRect(Button_Image, 66, 26, 15, 8, 0x51e062);
            SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
            Sleep(200);

            FillRect(Button_Image, 50, 5, 40, 32, 0x51e062); //Temizle

            HalfRect(Button_Image, 70, 32, -6, -6, 0x000000);
            HalfRect(Button_Image, 70, 32, -6, 6, 0x000000);
            Circle(Button_Image, 70, 21, 12, 0x000000);
            FillRect(Button_Image, 57, 16, 7, 15, 0x51e062);
            SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
            Sleep(200);

            FillRect(Button_Image, 50, 5, 40, 32, 0x51e062); //Temizle

            HalfRect(Button_Image, 59, 20, 6, -6, 0x000000);
            HalfRect(Button_Image, 59, 20, -6, -6, 0x000000);
            Circle(Button_Image, 70, 21, 12, 0x000000);
            FillRect(Button_Image, 60, 6, 15, 8, 0x51e062);
            SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
            Sleep(200);

        }
        else {
            FillRect(Button_Image, 1, 1, 150, 40, 0x000000); //Temizle

            ReadImage("tick.bmp", check);
            Copy(check, 1, 1, 34, 34, success);
            PasteNon0(success, 57, 5, Button_Image);
            DisplayImage(F1, Button_Image);
            SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
            Sleep(200);

            flagSuccess = 0;
        }

        counter++;
    }

    return(0);
}

void* transformButtonDefault(LPVOID vv)
{
    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    unsigned background_color = 0x3e9bed;
    CreateImage(Button_Image, 150, 40, ICB_UINT);
    Button_Image = background_color;

    const char* den = "TRANSFORM";
    Impress12x20(Button_Image, 17, 15, den, 0x2400a6);

    while (flagSuccess == 0) {
        SetButtonBitmap(BMP_BTN_TRANSFORM, Button_Image);
        Sleep(100);
    }

    return(0);
}

void Transform()
{
    int parameter = 5;
    DWORD dw;

    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)transformButton, &parameter, 0, &dw);

    ICG_printf(MLE, "Transforming voice file\n");
}

void* submitButton(LPVOID vv)
{
    // submit butonuna t�klan�nca ger�ekle�enler

    flagSubmit = 1;

    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    unsigned background_color = 0x3e9bed;
    CreateImage(Button_Image, 150, 40, ICB_UINT);
    Button_Image = background_color;

    const char* den = "PROCESSING";
    Impress12x20(Button_Image, 7, 15, den, 0x2400a6);

    int x = 1;
    while (flagSubmit == 1) {

        FillRect(Button_Image, 1, 1, 150, 40, 0x3e9bed); //Temizle

        int i;
        for (i = 0; i < 70; i++) {
            FillRect(Button_Image, x, 1, 15, 40, 0x2400a6);
            SetButtonBitmap(BMP_BTN_SUBMIT, Button_Image);
            Sleep(100);
            x += 2;
        }

        FillRect(Button_Image, 1, 1, 150, 40, 0x51e062); //Temizle

        const char* den = "SUCCESSFUL";
        Impress12x20(Button_Image, 12, 15, den, 0xffffff);

        SetButtonBitmap(BMP_BTN_SUBMIT, Button_Image);
        Sleep(200);

        flagSubmit = 0;
    }

    return(0);
}

void* submitButtonDefault(LPVOID vv)
{
    int* tmp = (int*)vv;
    int cnt = 0, id;
    id = *tmp;
    DWORD dwWaitResult;

    ICBYTES Button_Image(__LINE__);
    unsigned background_color = 0x3e9bed;
    CreateImage(Button_Image, 150, 40, ICB_UINT);
    Button_Image = background_color;

    const char* den = "SUBMIT";
    Impress12x20(Button_Image, 37, 15, den, 0x2400a6);

    while (flagSubmit == 0) {
        SetButtonBitmap(BMP_BTN_SUBMIT, Button_Image);
        Sleep(100);
    }

    return(0);
}

void Submit()
{
    int parameter = 5;
    DWORD dw;

    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)submitButton, &parameter, 0, &dw);

    ICG_printf(MLE, "Submiting voice file\n");
}

void Info() {
    MessageBox(ICG_GetMainWindow(), "Bu Mockup ICBYTES K�t�phanesi kullan�larak yap�lm��t�r.\n[Ses Kaydetme Aplikasyonu]\nThis Mockup was made using ICBYTES Library", "B�LG�LEND�RME", MB_OK);
}

void ICGUI_main()
{
    ICGUI_Create();

    FRM = ICG_FramePanel(5, 5, 450, 850);
    FRM2 = ICG_FramePanel(85, 215, 290, 102);
    FRM3 = ICG_FramePanel(85, 215, 290, 102);
    FRM4 = ICG_FrameMedium(85, 215 + 50, 290, 5); //d�z

    HMENU AnaMenu, DosyaMenu, HakkindaMenu;
    AnaMenu = CreateMenu();
    HakkindaMenu = CreatePopupMenu();
    ICG_AppendMenuItem(HakkindaMenu, "HAKKINDA", Info);
    AppendMenu(AnaMenu, MF_POPUP, (UINT_PTR)HakkindaMenu, "MEN�");
    ICG_SetMenu(AnaMenu);
    static ICBYTES arkaplan;
    arkaplan = 0;
    ReadImage("background.jpeg", arkaplan);
    DisplayImage(FRM, arkaplan);

    int parameter = 5;
    DWORD dw;

    //toggle button yerine thread kulland�k
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)recordButton, &parameter, 0, &dw);
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)transformButtonDefault, &parameter, 0, &dw);
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)submitButtonDefault, &parameter, 0, &dw);

    MLE = ICG_MLEditThick(5, 820, 450, 80, "", SCROLLBAR_V);

    BMP_BTN_RECORD = ICG_BitmapButton(160, 415, 150, 40, Record);
    BMP_BTN_TRANSFORM = ICG_BitmapButton(160, 495, 150, 40, Transform);
    BMP_BTN_SUBMIT = ICG_BitmapButton(160, 575, 150, 40, Submit);

}