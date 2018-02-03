//=============================================================================
//! \mainpage
//!
//! \brief      Простейшая графическая библиотека Win32 (TXLib)
//! \brief      c функциями эмулирующими Borland BGI
//!
//! \version    [Version 0.01 alpha, build 01]
//! \author     Copyright (C) Ded (TX), VV (BGI)
//! \date       2005-06
//!
//! \bug        Если кодовая страница для консоли установлена неверно, русский
//!             текст может отображаться некорректно.
//!
//! \warning    Это альфа-версия.
//!
//! \warning    Требуется во время выполнения: msvcrt.dll
//!
//! \warning    В BGI эмуляторе не поддерживаются режимы с количеством цветов >16,
//!                             работа с палитрами
//!             (для работы с TXLib эти возможности не нужны),
//!                             работа с битовыми образами.
//!             Используйте соответствующие tx-функции
//!

//! \par        Протестировано
//!             MinGW 3.4.2 + Dev-CPP 4.9.9.2, MSVS 6.0, MSVS 7.1
//!             Win 2000 SP4 ru, Win 95 en
//!
//! \par        Благодарности
//!             pasha_nik (Тестирование в Win95:)
//!
//! \todo
//!
//! \par        ChangeLog (существенные изменения:)
//!
//! <hr>
//-----------------------------------------------------------------------------
//! \defgroup Drawing   Рисование
//! \defgroup Mouse     Поддержка мыши
//! \defgroup Service   Служебное
//! \defgroup Misc      Разное

//! \defgroup Technical Технические детали

//! \defgroup BGI       Поддержка Borland BGI
//! \defgroup ADDON     Расширения TXLib
//! \cond Internal
//! \defgroup Internal  Реализация
//! \endcond
//=============================================================================

#ifndef __TXLIB_H
#define __TXLIB_H

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <windows.h>


extern HWND             _txCanvas_Wnd         ;
extern HDC              _txCanvas_BackBuf[2]  ;
extern UINT             _txCanvas_Timer       ;
extern HANDLE           _txCanvas_Thread      ;
extern CRITICAL_SECTION _txCanvas_LockBackBuf ;
extern int              _txCanvas_LockRefresh ;

extern HWND             _txConsole_Wnd        ;
extern HANDLE           _txConsole_Thread     ;

extern bool             _txConsole_CursorMode ;

extern bool             _txRunning            ;
extern bool             _txExit               ;

extern int              _txMouseX             ;
extern int              _txMouseY             ;
extern int              _txMouseButtons       ;

//-----------------------------------------------------------------------------

HWND             _txCanvas_Wnd         = NULL;
HDC              _txCanvas_BackBuf[2]  = {NULL, NULL};
UINT             _txCanvas_Timer       = 0;
HANDLE           _txCanvas_Thread      = NULL;
CRITICAL_SECTION _txCanvas_LockBackBuf = {0};
int              _txCanvas_LockRefresh = 0;

HWND             _txConsole_Wnd        = NULL;
HANDLE           _txConsole_Thread     = NULL;

bool             _txConsole_CursorMode = false;

bool             _txRunning            = false;
bool             _txExit               = false;

int              _txMouseX             = 0;
int              _txMouseY             = 0;
int              _txMouseButtons       = 0;


//=============================================================================
//! \cond Namespaces



namespace {
namespace TX {

//! \endcond Namespaces
//=============================================================================

//=============================================================================
//  \name    Цвета
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Названия предопределенных цветов
//! \see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel()
//  \note    The TX_* constants are the wrappers around my teacher's bug at 20050915 :)

enum txColors
    {
    txBLACK        = RGB (  0,   0,   0), TX_BLACK         = txBLACK,        //!< Черный
    txBLUE         = RGB (  0,   0, 128), TX_BLUE          = txBLUE,         //!< Синий
    txGREEN        = RGB (  0, 128,   0), TX_GREEN         = txGREEN,        //!< Зеленый
    txCYAN         = RGB (  0, 128, 128), TX_CYAN          = txCYAN,         //!< Бирюзовый
    txRED          = RGB (128,   0,   0), TX_RED           = txRED,          //!< Красный
    txMAGENTA      = RGB (128,   0, 128), TX_MAGENTA       = txMAGENTA,      //!< Малиновый
    txBROWN        = RGB (128, 128,   0), TX_BROWN         = txBROWN,        //!< Коричневый
    txORANGE       = RGB (255, 128,   0), TX_ORANGE        = txORANGE,       //!< Оранжевый
    txGRAY         = RGB (160, 160, 160), TX_GRAY          = txGRAY,         //!< Серый
    txDARKGRAY     = RGB (128, 128, 128), TX_DARKGRAY      = txDARKGRAY,     //!< Темно-серый
    txLIGHTGRAY    = RGB (192, 192, 192), TX_LIGHTGRAY     = txLIGHTGRAY,    //!< Светло-серый
    txLIGHTBLUE    = RGB (  0,   0, 255), TX_LIGHTBLUE     = txLIGHTBLUE,    //!< Светло-синий
    txLIGHTGREEN   = RGB (  0, 255, 128), TX_LIGHTGREEN    = txLIGHTGREEN,   //!< Светло-зеленый
    txLIGHTCYAN    = RGB (  0, 255, 255), TX_LIGHTCYAN     = txLIGHTCYAN,    //!< Светло-бирюзовый
    txLIGHTRED     = RGB (255,   0, 128), TX_LIGHTRED      = txLIGHTRED,     //!< Светло-красный
    txLIGHTMAGENTA = RGB (255,   0, 255), TX_LIGHTMAGENTA  = txLIGHTMAGENTA, //!< Светло-малиновый
    txPINK         = RGB (255, 128, 255), TX_PINK          = txPINK,         //!< Розовый
    txYELLOW       = RGB (255, 255, 128), TX_YELLOW        = txYELLOW,       //!< Желтый
    txWHITE        = RGB (255, 255, 255), TX_WHITE         = txWHITE,        //!< Белый
    txTRANSPARENT  = 0xFFFFFFFF,          TX_TRANSPARENT   = txTRANSPARENT,  //!< Прозрачный
    txNULL         = txTRANSPARENT,       TX_NULL          = txNULL,         //!< Прозрачный

//! Цветовые каналы (компоненты)

    txHUE          = 0x04000000,          TX_HUE           = txHUE,          //!< Цветовой тон
    txSATURATION   = 0x05000000,          TX_SATURATION    = txSATURATION,   //!< Насыщенность
    txLIGHTNESS    = 0x06000000,          TX_LIGHTNESS     = txLIGHTNESS     //!< Светлота
    };

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//! \return  Созданный цвет в формате COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB()

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (red,       //!< Количество красного цвета в интервале [0; 255]
              green,     //!< Количество зеленого цвета в интервале [0; 255]
              blue       //!< Количество синего цвета в интервале [0; 255]
              );
#endif

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//! \return  Цветовая компонента, см. \ref txColors
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors

int txExtractColor (COLORREF color,     //!< Смешанный цвет
                    COLORREF component  //!< Извлекаемая компонента, см. \ref txColors
                    );

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Преобразует цвет из формата RGB в формат HSL.
//!
//!          Формат RGB определяется как
//!
//!          - Красная компонента цвета (Red), от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя компонента цвета (Blue), от 0 до 255.
//!
//!          Формат HSL определяется как
//!
//!          - Цветовой тон (Hue), от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота (Lightness), от 0 до 255.
//!
//! \return  Созданный цвет в виде COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors

COLORREF txRGB2HSL (COLORREF rgbColor   //!< Преобразуемый цвет в формате RGB
                    );

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Преобразует цвет из формата HSL в формат RGB.
//!
//!          Формат RGB определяется как
//!
//!          - Красная компонента цвета (Red), от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя компонента цвета (Blue), от 0 до 255.
//!
//!          Формат HSL определяется как
//!
//!          - Цветовой тон (Hue), от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота (Lightness), от 0 до 255.
//!
//! \return  Созданный цвет в виде COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors

COLORREF txHSL2RGB (COLORREF hslColor   //!< Преобразуемый цвет в формате HSL
                    );

//=============================================================================
//  \name    Инициализация и параметры рисования
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создание окна рисования
//! \return  Успех операции
//! \see     txOk()

bool  txCreateWindow (double sizeX,        //!< Размер окна по горизонтали (пикс)
                      double sizeY,        //!< Размер окна по горизонтали (пикс)
                      bool centered = true //!< Центрирование окна на дисплее
                      );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Проверка правильности работы библиотеки
//! \return  Состояние библиотеки
//! \see     txCreateWindow()

bool  txOK();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает размер окна рисования в виде структуры POINT.
//! \return  Размер окна рисования в виде структуры POINT.
//! \see     txGetExtentX(), txGetExtentY()

POINT txGetExtent();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает ширину окна рисования.
//! \return  Ширина окна рисования.
//! \see     txGetExtent(), txGetExtentY()

int txGetExtentX();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает высоту окна рисования.
//! \return  Высота окна рисования.
//! \see     txGetExtent(), txGetExtentX()

int txGetExtentY();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Установка параметров рисования по умолчанию.
//!
//!          Параметры по умолчанию:\n
//!          - Линии - цвет белый (TX_WHITE), толщина 1
//!          - Заливка - цвет белый (TX_WHITE)
//!          - Шрифт - Системный шрифт, цвет белый (TX_WHITE)
//!          - Логическая растровая операция - копирование цвета (R2_COPYPEN)
//!
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()

bool txSetDefaults();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//! \return  Успех операции.
//! \see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()

bool txSetColor (COLORREF color,   //!< Цвет линий и текста, см. \ref txColors, RGB()
                 int thickness = 1 //!< Толщина линий
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет линий и текста.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()

bool txColor (double red,     //!< Количество красного цвета в интервале [0; 1]
              double green,   //!< Количество зеленого цвета в интервале [0; 1]
              double blue     //!< Количество синего цвета в интервале [0; 1]
              );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет линий и текста.
//! \return  Текущий цвет линий и текста, см. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()

COLORREF txGetColor();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет заполнения фигур.
//! \return  Успех операции.
//! \see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), \ref txColors, RGB()

bool txSetFillColor (COLORREF color  //!< Цвет заполнения, см. \ref txColors, RGB()
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет заполнения фигур.
//! \return  Успех операции.
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()

bool txFillColor (double red,   //!< Количество красного цвета в интервале [0; 1]
                  double green, //!< Количество зеленого цвета в интервале [0; 1]
                  double blue   //!< Количество синего цвета в интервале [0; 1]
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет заполнения фигур.
//! \return  Текущий цвет заполнения фигур, см. \ref txColors, RGB()
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), \ref txColors, RGB()

COLORREF txGetFillColor();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает режим взаимодействия цветов при рисовании.
//!
//!          При рисовании графическая библиотека может не просто красить пиксели
//!          на экране, а смешивать цвета экрана и текущие цвета линий и заполнения.
//!
//!          Режимы взаимодействия цветов:
//!
//!          \table
//!          \tr R2_COPYPEN     \td Пиксели = цвета кисти (самый нормальный режим :) \endtr
//!          \tr R2_NOTCOPYPEN  \td Пиксели = ~кисть\n \endtr
//!
//!          \tr R2_BLACK       \td Пиксели = черный цвет (цвет кисти игнорируется)    \endtr
//!          \tr R2_WHITE       \td Пиксели = белый  цвет (цвет кисти игнорируется)    \endtr
//!          \tr R2_NOT         \td Пиксели = ~пиксели    (цвет кисти игнорируется)\n  \endtr
//!
//!          \tr R2_XORPEN      \td Пиксели =    пиксели ^  кисть    \endtr
//!          \tr R2_NOTXORPEN   \td Пиксели = ~ (пиксели ^  кисть)\n \endtr
//!
//!          \tr R2_MASKPEN     \td Пиксели =    пиксели &  кисть    \endtr
//!          \tr R2_NOTMASKPEN  \td Пиксели = ~ (пиксели &  кисть)   \endtr
//!          \tr R2_MASKNOTPEN  \td Пиксели =    пиксели & ~кисть    \endtr
//!          \tr R2_MASKPENNOT  \td Пиксели =   ~пиксели &  кисть\n  \endtr
//!
//!          \tr R2_MERGEPEN    \td Пиксели =    пиксели |  кисть    \endtr
//!          \tr R2_NOTMERGEPEN \td Пиксели = ~ (пиксели |  кисть)   \endtr
//!          \tr R2_MERGENOTPEN \td Пиксели =    пиксели | ~кисть    \endtr
//!          \tr R2_MERGEPENNOT \td Пиксели =   ~пиксели |  кисть\n  \endtr
//!
//!          \tr R2_NOP         \td Пиксели вообще не изменяются.    \endtr
//!          \endtable
//!
//! \return  Предыдущий режим взаимодействия цветов, см. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool txSetROP2 (int mode         //!< Режим смешивания цветов
                );

//=============================================================================
//  \name    Фигуры
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Стирает холст текущим цветом заполнения.
//! \return  Успех операции.
//! \see     txSetFillColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()

bool  txClear();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует пиксель (точку на экране).
//! \return  Успех операции.
//! \see     txSetPixel (double, double, double, double, double), txGetPixel(), \ref txColors, RGB()

bool  txSetPixel (double x,      //!< Х-координата точки
                  double y,      //!< Y-координата точки
                  COLORREF color //!< Цвет точки, см. \ref txColors, RGB()
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует пиксель (точку на экране).
//! \return  Успех операции.
//! \see     txSetPixel (double, double, COLORREF), txGetPixel()

bool  txSetPixel (double x,     //!< Х-координата точки
                  double y,     //!< Y-координата точки
                  double red,   //!< Количество красного цвета в интервале [0; 1]
                  double green, //!< Количество зеленого цвета в интервале [0; 1]
                  double blue   //!< Количество синего цвета в интервале [0; 1]
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет точки (пикселя) на экране.
//! \return  Текущий цвет пикселя, см. \ref txColors, RGB()
//! \see     \ref txColors, RGB()

COLORREF txGetPixel (double x,  //!< Х-координата точки
                     double y   //!< Y-координата точки
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует линию.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txLine (double x0,        //!< X-координата начальной точки
              double y0,        //!< Y-координата начальной точки
              double x1,        //!< X-координата конечной точки
              double y1         //!< Y-координата конечной точки
              );

//-----------------------------------------------------------------------------
// VV
//! \ingroup Drawing
//! \brief   Возращает X текущей точки (ее координаты изменяются фунциями txLineTo и txMoveTo).
//! \return  Значение X.
//! \see     txGetCurrentY (), txMoveTo(), txLineTo(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()  \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

double txGetCurrentX ();

//-----------------------------------------------------------------------------
// VV

//! \ingroup Drawing
//! \brief   Возращает Y текущей точки (ее координаты изменяются фунциями txLineTo и txMoveTo).
//! \return  Значение Y.
//! \see     txGetCurrentX (), txMoveTo(), txLineTo(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()  \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

double txGetCurrentY ();

//-----------------------------------------------------------------------------
// VV

//! \ingroup Drawing
//! \brief   Перемещает текущую точку (ее координаты изменяются фунциями txLineTo и txMoveTo).
//! \return  Успех операции.
//! \see     txGetCurrentX (), txLineTo(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()  \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txMoveTo (double x,        //!< X-координата конечной точки
                double y         //!< Y-координата конечной точки
               );

//-----------------------------------------------------------------------------
// VV

//! \ingroup Drawing
//! \brief   Рисует линию от текущей точки (ее координаты изменяются фунциями txLineTo и txMoveTo).
//! \return  Успех операции.
//! \see     txGetCurrentX (), txGetCurrentY (), txMoveTo(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txMoveTo() \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txLineTo (double x,        //!< X-координата конечной точки
                double y         //!< Y-координата конечной точки
               );

//-----------------------------------------------------------------------------

//! \ingroup Drawing
//! \brief   Рисует прямоугольник.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txRectangle (double x0,   //!< X-координата верхнего левого угла
                   double y0,   //!< Y-координата верхнего левого угла
                   double x1,   //!< X-координата нижнего правого угла
                   double y1    //!< Y-координата нижнего правого угла
                   );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует ломаную линию или многоугольник.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txPolygon (POINT* points, //!< Массив структур POINT с координатами точек
                 int npoints    //!< Количество точек в массиве
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует эллипс.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txEllipse (double x0,     //!< X-координата верхнего левого угла описанного прямоугольника
                 double y0,     //!< Y-координата верхнего левого угла описанного прямоугольника
                 double x1,     //!< X-координата нижнего правого угла описанного прямоугольника
                 double y1      //!< Y-координата нижнего правого угла описанного прямоугольника
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует окружность или круг.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txCircle (double x,       //!< Х-координата центра
                double y,       //!< Y-координата центра
                double r        //!< Радиус
                );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует дугу эллипса.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txArc (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                                //!<   описанного вокруг эллипса, содержащего дугу
             double y0,         //!< Y-координата верхнего левого угла прямоугольника
             double x1,         //!< X-координата нижнего правого угла прямоугольника
             double y1,         //!< Y-координата нижнего правого угла прямоугольника
             double startAngle, //!< Угол между направлением оси OX и началом дуги (в градусах)
             double totalAngle  //!< Величина дуги (в градусах)
             );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует сектор эллипса.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txPie (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                                //!<   описанного вокруг эллипса, содержащего сектор
             double y0,         //!< Y-координата верхнего левого угла прямоугольника
             double x1,         //!< X-координата нижнего правого угла прямоугольника
             double y1,         //!< Y-координата нижнего правого угла прямоугольника
             double startAngle, //!< Угол между направлением оси OX и началом сектора (в градусах)
             double totalAngle  //!< Величина сектора (в градусах)
             );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует хорду эллипса.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool  txChord (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                                  //!<   описанного вокруг эллипса, содержащего хорду
               double y0,         //!< Y-координата верхнего левого угла прямоугольника
               double x1,         //!< X-координата нижнего правого угла прямоугольника
               double y1,         //!< Y-координата нижнего правого угла прямоугольника
               double startAngle, //!< Угол между направлением оси OX и началом хорды (в градусах)
               double totalAngle  //!< Величина хорды (в градусах)
               );

//=============================================================================
//  \name    Работа с текстом
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует текст.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()

bool  txTextOut (double x,         //!< Х-координата начальной точки текста
                 double y,         //!< Y-координата начальной точки текста
                 const char text[] //!< Текстовая строка
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Выбирает текущий шрифт.
//! \return  Успех операции.
//! \see     txTextOut()

bool  txSelectFont (const char* name,       //!< Название шрифта
                    double sizeY,           //!< Высота букв (размер по Y)
                    double sizeX = 0,       //!< Ширина букв
                    int bold = FW_DONTCARE, //!< Жирность шрифта (от 0 до 1000)
                    bool italic = false,    //!< Курсив
                    bool underline = false, //!< Подчеркивание
                    bool strikeout = false  //!< Зачеркивание
                    );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет размеры текстовой надписи.
//! \return  Размеры надписи в структуре SIZE.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()

SIZE  txGetTextExtent (const char* text     //!< Текстовая строка
                      );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет ширину текстовой надписи.
//! \return  Ширина надписи.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()

int txGetTextExtentX (const char* text      //!< Текстовая строка
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет высоту текстовой надписи.
//! \return  Высота надписи.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()

int txGetTextExtentY (const char* text      //!< Текстовая строка
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущее выравнивание текста.
//!
//!          Флаги выравнивания:
//!
//!          \table
//!          \tr TA_BASELINE \td Точка (X,Y) определяет базовую линию текста. \endtr
//!          \tr TA_BOTTOM   \td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника\n
//!                              (текст лежит выше этой точки).   \endtr
//!          \tr TA_TOP      \td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника\n
//!                              (текст лежит ниже этой точки).\n \endtr
//!
//!          \tr TA_CENTER   \td Текст будет выровнен по горизонтали относительно точки (X,Y). \endtr
//!          \tr TA_LEFT     \td Точка (X,Y) определяет левую сторону описанного прямоугольника\n
//!                              (текст лежит правее этой точки). \endtr
//!          \tr TA_RIGHT    \td Точка (X,Y) определяет правую сторону описанного прямоугольника\n
//!                              (текст лежит левее этой точки).  \endtr
//!          \endtable
//!
//! \return  Успех операции.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()

bool txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE //!< Флаги выравнивания
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Ищет шрифт по его названию.
//! \return  Информация о шрифте в структуре LOGFONT.
//!          Если шрифт не найден, возвращает NULL.
//! \see     txTextOut(), txSelectFont()

LOGFONT* txFontExist (const char* name      //!< Название шрифта
                     );

//=============================================================================
//  \name    Разное
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Заливает произвольный контур текущим цветом заполнения.
//!
//!          Режимы заливки:
//!
//!          FLOODFILLSURFACE - Заливать область, куазанную цветом color.\n
//!          FLOODFILLBORDER  - Заливать до границы, указанной цветом color.
//!
//! \return  Успех операции.
//! \see     txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()

bool txFloodFill (double x,                        //!< Х-координата точки начала заливки
                  double y,                        //!< Y-координата точки начала заливки
                  COLORREF color = TX_TRANSPARENT, //!< Цвет заливаемой области (TX_TRANSPARENT - автоопределение)
                  DWORD mode = FLOODFILLSURFACE    //!< Режим заливки (FLOODFILLSURFACE - заливка однородного фона)
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий прямоугольный регион отсечения.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()

bool txSelectRegion (double x0,   //!< X-координата верхнего левого угла
                     double y0,   //!< Y-координата верхнего левого угла
                     double x1,   //!< X-координата нижнего правого угла
                     double y1    //!< Y-координата нижнего правого угла
                     );

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Устанавливает текущий объект GDI.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion()

bool txSelectObject (HGDIOBJ obj     //!< Дескриптор объекта GDI
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//! \warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! \return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()

int txBegin();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Разблокирует обновление окна, заблокированное функцией txBegin().
//!
//! \warning Если txBegin() вызывалась несколько раз, то для снятия блокировки
//!          требуется столько же раз вызвать txEnd().
//!
//! \return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()

int txEnd();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Блокирует или разблокирует обновление изображения в окне.
//!
//!          В отличие от txBegin() и txEnd(), позволяет явно установить или
//!          снять блокировку.
//!
//! \warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! \return  Предыдущее состояние режима обновления.
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()

bool txUpdateWindow (bool update = true //!< Режим обновления (false - запретить обновление)
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Блокирует или разблокирует рисование мигающего курсора в окне.
//! \return  Предыдущее значение блокировки.
//! \see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()

bool txTextCursor (bool blink = true    //!< false - блокировать мигающий курсор
                   );

//=============================================================================
//  \name    Рисование в памяти и загрузка изображений
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создает дополнительный холст (контекст рисования, DC) в памяти.
//! \return  Дескриптор (обозначение) созданного контекста рисования.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! \remarks Созданный контекст затем будет нужно удалить при помощи txDeleteDC().

HDC txCreateCompatibleDC (double sizeX,            //!< Ширина холста
                          double sizeY,            //!< Высота холста
                          HBITMAP bitmap = NULL    //!< Bitmap associated with DC
                          );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Загружает из файла изображение в формате BMP.
//! \return  Дескриптор созданного контекста рисования в памяти, с загруженным изображением.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt(),
//!
//! \remarks Изображение загружается в создаваемый контекст рисования (холст),
//!          который затем будет нужно удалить при помощи txDeleteDC().

HDC txLoadImage (LPCTSTR name, double sizeX, double sizeY);     //!< Имя файла с изображением

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Уничтожает холст (контекст рисования, DC) в памяти.
//! \return  Успех операции.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()

bool txDeleteDC (HDC dc            //!< Контекст рисования для уничтожения
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой.
//!
//!          Режимы копирования:
//!
//!          \table
//!          \tr SRCCOPY     \td Просто копирует :) - самый распространенный режим\n \endtr
//!
//!          \tr BLACKNESS   \td Заполняет холст-приемник черным цветом (холст-источник игнорируется). \endtr
//!          \tr WHITENESS   \td Заполняет холст-приемник белым цветом (холст-источник игнорируется). \endtr
//!          \tr DSTINVERT   \td Инвертирует цвета на холсте-приемнике (холст-источник игнорируется). \endtr
//!          \tr PATCOPY     \td Копирует цвет текущей кисти холста-приемника.\n \endtr
//!
//!          \tr MERGECOPY   \td Приемник =   приемник & цвет текущей кисти источника. \endtr
//!          \tr MERGEPAINT  \td Приемник = ~ приемник | источник \endtr
//!          \tr NOTSRCCOPY  \td Приемник = ~ источник \endtr
//!          \tr NOTSRCERASE \td Приемник = ~ (приемник | источник) \endtr
//!          \tr PATINVERT   \td Приемник =  кисть приемника ^  приемник \endtr
//!          \tr PATPAINT    \td Приемник = (кисть приемника | ~источник) | приемник \endtr
//!          \tr SRCAND      \td Приемник =  приемник & источник \endtr
//!          \tr SRCERASE    \td Приемник = ~приемник & источник \endtr
//!          \tr SRCINVERT   \td Приемник =  приемник ^ источник \endtr
//!          \tr SRCPAINT    \td Приемник =  приемник | источник \endtr
//!          \endtable
//!
//! \return  Успех операции.
//! \see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()

bool txBitBlt (HDC dest,           //!< Контекст назначения (куда копировать)
               double xDest,       //!< Х-координата верхнего левого угла изображения-приемника
               double yDest,       //!< Y-координата верхнего левого угла изображения-приемника
               double width,       //!< Ширина копируемого изображения
               double height,      //!< Высота копируемого изображения
               HDC src,            //!< Контекст источника (откуда копировать)
               double xSrc,        //!< Х-координата верхнего левого угла изображения-источника
               double ySrc,        //!< Y-координата верхнего левого угла изображения-источника
               DWORD rOp = SRCCOPY //!< Растровая операция копирования
               );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! \brief   с учетом прозрачности.
//! \return  Успех операции.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()

bool txTransparentBlt (HDC dest,                 //!< Контекст назначения (куда копировать)
                       double xDest,             //!< Х-координата верхнего левого угла изображения-приемника
                       double yDest,             //!< Y-координата верхнего левого угла изображения-приемника
                       double width,             //!< Ширина копируемого изображения
                       double height,            //!< Высота копируемого изображения
                       HDC src,                  //!< Контекст источника (откуда копировать)
                       double xSrc,              //!< Х-координата верхнего левого угла изображения-источника
                       double ySrc,              //!< Y-координата верхнего левого угла изображения-источника
                       COLORREF transColor = TX_BLACK //!< Цвет, который будет считаться прозрачным
                       );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! \brief   с учетом прозрачности.
//!
//!          Изображение должно быть загружено с помощью txLoadImage() и иметь
//!          32-битовый RGBA-формат. Дополнительный канал (альфа-канал) этого
//!          формата отвечает за прозрачность участков изображения.
//!
//!          Альфа-канал можно сделать, например, в Adobe Photoshop, командой
//!          "Новый канал (New Channel)" в палитре каналов (Channels). Черный
//!          цвет в альфа-канале соответствует полной прозрачности, белый -
//!          полной непрозрачности.
//!
//! \return  Успех операции.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()

bool txAlphaBlend (HDC dest,                     //!< Контекст назначения (куда копировать)
                   double xDest,                 //!< Х-координата верхнего левого угла изображения-приемника
                   double yDest,                 //!< Y-координата верхнего левого угла изображения-приемника
                   double width,                 //!< Ширина копируемого изображения
                   double height,                //!< Высота копируемого изображения
                   HDC src,                      //!< Контекст источника (откуда копировать)
                   double xSrc,                  //!< Х-координата верхнего левого угла изображения-источника
                   double ySrc,                  //!< Y-координата верхнего левого угла изображения-источника
                   double alpha = 1.0            //!< Общая прозрачность изображения, в дополнение к альфа-каналу.\n
                                                 //!<   (0 - все прозрачно, 1 - использовать только альфа-канал)
                   );

//=============================================================================
//
//  \name    Работа с мышью
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает Х-Координату Мыши!
//! \return  Х-координата мыши.
//! \see     txMouseX(), txMouseY(), txMouseButtons()

double txMouseX();

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает Y-Координату Мыши!
//! \return  Y-координата мыши.
//! \see     txMouseX(), txMouseY(), txMouseButtons()

double txMouseY();

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает состояние Кнопок Мыши!
//! \return  Состояние кнопок мыши.
//! \see     txMouseX(), txMouseY(), txMouseButtons()

int txMouseButtons();

//=============================================================================
//
// \name     Back-hole (I hope, not an ass-hole:) of the library)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Возвращает дескриптор контекста рисования холста
//! \return  Дескриптор контекста рисования холста
//! \see     txWindow(), txLock(), txUnlock(), txGDI()

HDC  txDC();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Возвращает дескриптор окна холста
//! \return  Дескриптор окна холста
//! \see     txDC(), txLock(), txUnlock(), txGDI()

HWND txWindow();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Блокировка холста (поверхности рисования).
//!
//!          Перед вызовом любых функций Win32 GDI необходимо заблокировать
//!          холст функцией txLock() и затем разблокировать с помощью txUnlock().
//!          Это связано с тем, что обновление содержимого окна (для тех, кто
//!          знает - обработка сообщения WM_PAINT :) происходит в отдельном
//!          потоке. Надолго блокировать нельзя - при заблокированном холсте
//!          окно не обновляется.
//!
//!          txLock() использует EnterCriticalSection(), и физически
//!          приостанавливает поток, обновляющий окно, так что надолго
//!          блокировать нельзя.
//!
//!          txLock()/txUnlock() - низкоуровневый механизм, он отличается от
//!          высокоуровневого механизма txBegin()/txEnd()/txUpdateWindow(),
//!          который не приостанавливает поток, а просто отключает операции
//!          по обновлению окна.
//!
//! \return  Состояние блокировки
//! \see     txDC(), txLock(), txUnlock(), txGDI()

bool txLock();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Разблокировка холста
//! \return  Состояние блокировки
//! \see     txDC(), txLock(), txUnlock(), txGDI()

bool txUnlock();

//! \cond    Internal
template <typename T> inline T txUnlock (T value);
//! \endcond Internal

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой
//! \return  Значение, возвращаемое вызываемой функцией GDI.
//! \param   cmd Команда GDI (возможно, возвращающая значение)
//! \note    Если в вызове функции GDI используются запятые, то используйте
//!          двойные скобки, так как это все-таки макрос:
//!          txGDI <b>((</b> Rectangle (txDC(), x1, y1, x2, y2) <b>))</b>;
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \hideinitializer

#define txGDI( cmd ) txUnlock ((txLock(), (cmd)))

//-----------------------------------------------------------------------------
//! \ingroup Technical
//! \brief   Возвращает строку с информацией о текущей версии библиотеки.
//! \return  Строка с информацией о текущей версии библиотеки.

const char* txVersion();

//=============================================================================
//
// \name     Misc functions
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Проверка, находится ли параметр х внутри замкнутого интервала [a; b]
//! \return  Если a <= x && x <= b, то истина, если нет - ложь
//! \hideinitializer

template <typename T>
inline bool In (T x, //!< Проверяемый параметр
                T a, //!< Левая граница (включительно)
                T b  //!< Правая граница (включительно)
                )
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Проверка, находится ли точка pt внутри прямоугольника rect
//! \return  Результат проверки

inline bool In (const COORD& pt,       //!< Проверяемая точка
                const SMALL_RECT& rect //!< Прямоугольник
                )
    {
    return In (pt.X, rect.Left, rect.Right) && In (pt.Y, rect.Top, rect.Bottom);
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Возвращает максимальное из двух чисел
//! \param   a Одно из чисел :)
//! \param   b Другое из чисел :)
//! \return  Максимальное из двух чисел a и b
//! \hideinitializer

#define MAX( a, b )      ( (a) > (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Возвращает минимальное из двух чисел
//! \param   a Одно из чисел :)
//! \param   b Другое из чисел :)
//! \return  Минимальное из двух чисел a и b
//! \hideinitializer

#define MIN( a, b )      ( (a) < (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Генератор случайных чисел
//! \param   range Правая граница диапазона (не включая саму границу).
//! \return  Случайное целое число в диапазоне [0; range).\n
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
//! \hideinitializer

#define random( range )  ( rand() % (range) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Задерживает выполнение программы на определенное время.
//!
//!          Во время задержки обновление изображения в окне всегда
//!          автоматически разблокируется.
//!
//! \return  Состояние блокировки обновления окна.
//! \see     txUpdateWindow()

bool txSleep (int time   //!< Задержка в миллисекундах
              );

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Воспроизводит звуковой файл.
//!
//!          Режимы воспроизведения:
//!
//!          \table
//!          \tr SND_ASYNC       \td Звук проигрывается одновременно с работой программы.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL). \endtr
//!          \tr SND_SYNC        \td Выполнение программы приостанавливается до окончания
//!                                  воспроизведения звука. \endtr
//!          \tr SND_LOOP        \td Зацикливать звук при воспроизведении.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).\n \endtr
//!
//!          \tr SND_NODEFAULT   \td Не использовать звук по умолчанию, если нельзя проиграть
//!                                  указанный звуковой файл. \endtr
//!          \tr SND_NOSTOP      \td Если какой-либо звук уже проигрывается, не останавливать
//!                                  его для воспроизведения указанного звука. \endtr
//!          \tr SND_APPLICATION \td Проигрывать звук, используя программу, зарегистрированную
//!                                  для данного типа звуковых файлов. \endtr
//!          \endtable
//!
//! \return  Успех операции.

bool txPlaySound (const char* filename = NULL, //!< Имя звукового файла.
                                               //!< Если NULL - останавливает звук.
                  DWORD mode = SND_ASYNC       //!< Режим воспроизведения
                  );

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Число Пи
//! \return  Число Пи

const double txPI = asin (1.0) * 2;

//=============================================================================
// Настроечные константы
//=============================================================================

//! \ingroup Technical
//! \brief   Интервал мигания курсора консоли (мс)

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//! \ingroup Technical
//! \brief   Шрифт консоли

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//! \ingroup Technical
//! \brief   Цвет шрифта консоли

const COLORREF _TX_CONSOLE_COLOR          = txLIGHTGRAY;

//! \ingroup Technical
//! \brief   Таймаут операций ожидания (мс)

const int    _TX_TIMEOUT                  = 1000;

//! \ingroup Technical
//! \brief   Интервал обновления холста (мс)

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//! \ingroup Technical
//! \brief   Использовать добавочный поток вместо таймера для обновления холста

#define      _TX_USE_CONSOLE_THREAD         0

//! \ingroup Technical
//! \brief   Текущая версия библиотеки.
//!          Эта константа автоматически обновляется при обновлении версии.
//! \see     txVersion()

#define      _TX_VERSION                    "[Version 0.01 alpha, build 01]"

//=============================================================================
//! \cond    Internal
//@{

namespace Internal
{

//-----------------------------------------------------------------------------

bool _txInitialize (int sizeX, int sizeY, bool centered);
bool _txCleanup();
void _txOnExit();

bool _txCanvas_SetDefaults();
bool _txConsole_SetDefaults();

HWND _txCanvas_CreateWindow (POINT size);
bool _txCanvas_OK();
bool _txCanvas_DestroyWindow();
int  _txCanvas_SetLockRefresh (int count);
bool _txCanvas_OnCreate (HWND wnd);
bool _txCanvas_OnDestroy (HWND wnd);
bool _txCanvas_OnClose (HWND);
bool _txCanvas_OnPaint (HWND wnd);
bool _txCanvas_OnChar (HWND wnd, WPARAM ch);
bool _txCanvas_OnTimer (HWND wnd, WPARAM id);
bool _txCanvas_OnMouse (HWND wnd, WPARAM buttons, LPARAM coords);
bool _txCanvas_OnCmdAbout (HWND wnd, WPARAM cmd);
bool _txCanvas_OnCmdConsole (HWND wnd, WPARAM cmd);
DWORD WINAPI _txCanvas_ThreadProc (LPVOID data);
LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC  _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool _txBuffer_Delete (HDC dc);
bool _txSelect (HGDIOBJ obj, HDC dc = txDC());

bool _txConsole_Attach();
bool _txConsole_OK();
bool _txConsole_Detach();
bool _txConsole_Draw (HDC dc);
HWND _txConsole_GetWindow();
DWORD WINAPI _txConsole_ThreadProc (LPVOID);

//-----------------------------------------------------------------------------

bool _Throw (const char file[], int line, const char func[], DWORD error, const char msg[], ...);

#ifdef __FUNCTION__
#define THROW(msg)    _Throw (__FILE__, __LINE__, __FUNCTION__, GetLastError(), msg)
#else
#define THROW(msg)    _Throw (__FILE__, __LINE__, NULL,         GetLastError(), msg)
#endif

#define _             ,
#define NEEDED        ;
//|| THROW (NULL)

//-----------------------------------------------------------------------------

#define PRINT_HERE()  printf ("%s (%d) %s(): Here... :)\n", __FILE__, __LINE__, __FUNCTION__)

#ifndef NDEBUG
#undef  assert
#define assert(p)     ( !(p)? (THROW ("\aAssertion failed: \"%s\"" _ #p), 0) : _txDummy() )
#else
#undef  assert
#define assert(p)     ( 1 )
#endif

#define _txWaitFor(p)  { for (int __i##__LINE__ = 0; __i##__LINE__ < _TX_TIMEOUT/10; __i##__LINE__++) \
                             { if (p) break; Sleep (10); } }

inline int _txDummy()  { return 1; }

//-----------------------------------------------------------------------------

#define IMPORT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, true)

#define IMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, false)

FARPROC _txImport (const char lib[], const char name[], int required = true);

//-----------------------------------------------------------------------------
// Dev-CPP doesn't link with GDI32 by default, so do sunrise by hand. :(
// <tears>

//! \cond Namespaces
namespace Win32 {
//! \endcond Namespaces

IMPORT ("GDI32", int,      GetDeviceCaps,          (HDC dc, int index));
IMPORT ("GDI32", HDC,      CreateCompatibleDC,     (HDC dc));
IMPORT ("GDI32", HBITMAP,  CreateCompatibleBitmap, (HDC dc, int width, int height));
IMPORT ("GDI32", HGDIOBJ,  GetStockObject,         (int object));
IMPORT ("GDI32", HGDIOBJ,  SelectObject,           (HDC dc, HGDIOBJ object));
IMPORT ("GDI32", HGDIOBJ,  GetCurrentObject,       (HDC dc, UINT objectType));
IMPORT ("GDI32", int,      GetObjectA,             (HGDIOBJ obj, int bufsize, LPVOID buffer));
IMPORT ("GDI32", BOOL,     DeleteDC,               (HDC dc));
IMPORT ("GDI32", BOOL,     DeleteObject,           (HGDIOBJ object));
IMPORT ("GDI32", COLORREF, SetTextColor,           (HDC dc, COLORREF color));
IMPORT ("GDI32", int,      SetBkMode,              (HDC dc, int bkMode));
IMPORT ("GDI32", HFONT,    CreateFontA,            (int height, int width, int escapement, int orientation,
                                                    int weight, DWORD italic, DWORD underline, DWORD strikeout,
                                                    DWORD charSet, DWORD outputPrec, DWORD clipPrec,
                                                    DWORD quality, DWORD pitchAndFamily, LPCTSTR face));
IMPORT ("GDI32", int,      EnumFontFamiliesExA,    (HDC dc, LPLOGFONT logFont, FONTENUMPROC enumProc,
                                                    LPARAM lParam, DWORD reserved));
IMPORT ("GDI32", COLORREF, SetPixel,               (HDC dc, int x, int y, COLORREF color));
IMPORT ("GDI32", COLORREF, GetPixel,               (HDC dc, int x, int y));
IMPORT ("GDI32", HPEN,     CreatePen,              (int penStyle, int width, COLORREF color));
IMPORT ("GDI32", HBRUSH,   CreateSolidBrush,       (COLORREF color));
IMPORT ("GDI32", BOOL,     MoveToEx,               (HDC dc, int x, int y, LPPOINT point));
IMPORT ("GDI32", BOOL,     LineTo,                 (HDC dc, int x, int y));
IMPORT ("GDI32", BOOL,     Polygon,                (HDC dc, CONST POINT* points, int n));
IMPORT ("GDI32", BOOL,     Rectangle,              (HDC dc, int x0, int y0, int x1, int y1));
IMPORT ("GDI32", BOOL,     Ellipse,                (HDC dc, int x0, int y0, int x1, int y1));
IMPORT ("GDI32", BOOL,     Arc,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                    int xStart, int yStart, int xEnd, int yEnd));
IMPORT ("GDI32", BOOL,     Pie,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                    int xStart, int yStart, int xEnd, int yEnd));
IMPORT ("GDI32", BOOL,     Chord,                  (HDC dc, int x0, int y0, int x1, int y1,
                                                    int xStart, int yStart, int xEnd, int yEnd));
IMPORT ("GDI32", BOOL,     TextOutA,               (HDC dc, int x, int y, LPCTSTR string, int length));
IMPORT ("GDI32", UINT,     SetTextAlign,           (HDC dc, UINT mode));
IMPORT ("GDI32", BOOL,     GetTextExtentPoint32A,  (HDC dc, LPCTSTR string, int length, LPSIZE size));
IMPORT ("GDI32", BOOL,     ExtFloodFill,           (HDC dc, int x, int y, COLORREF color, UINT type));
IMPORT ("GDI32", BOOL,     BitBlt,                 (HDC dest, int xDest, int yDest, int width, int height,
                                                    HDC src,  int xSrc,  int ySrc,  DWORD rOp));
IMPORT ("GDI32", BOOL,     PatBlt,                 (HDC dc, int x0, int y0, int width, int height, DWORD rOp));
IMPORT ("GDI32", int,      SetROP2,                (HDC dc, int mode));
IMPORT ("GDI32", HRGN,     CreateRectRgn,          (int x0, int y0, int x1, int y1));
IMPORT ("GDI32", BOOL,     GetBitmapDimensionEx,   (HBITMAP bitmap, LPSIZE dimensions));

IMPORT ("USER32",HANDLE,   LoadImageA,             (HINSTANCE inst, LPCTSTR name, UINT type,
                                                    int sizex, int sizey, UINT mode));

IMPORT ("WinMM", BOOL,     PlaySound,              (LPCSTR sound, HMODULE mod, DWORD mode));

IMPORT_OPT ("MSImg32",BOOL,TransparentBlt,         (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                    HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                    UINT transparentColor));
IMPORT_OPT ("MSImg32",BOOL,AlphaBlend,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                    HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                    BLENDFUNCTION blending));
//VV
IMPORT     ("GDI32", int,  GetCurrentPositionEx,   (HDC dc, POINT *point));
IMPORT     ("GDI32", int,  GetDIBits,              (HDC dc, HBITMAP hbmp, UINT uStartScan, UINT cScanLines,
                                                    LPVOID lpvBits, LPBITMAPINFO lpbi, UINT uUsage));





//! \cond Namespaces
}; // namespace Win32
using namespace Win32;
//! \endcond Namespaces

// </tears>
//=============================================================================
//...
#define _txIDM_ABOUT        40000
#define _txIDM_CONSOLE      40001

//-----------------------------------------------------------------------------

//! \cond Namespaces
}; // namespace Internal
using namespace Internal;
//! \endcond Namespaces

//=============================================================================

bool txCreateWindow (double sizeX, double sizeY, bool centered)
{
if (txOK()) return false;
return _txInitialize ((int)sizeX, (int)sizeY, centered);
}

//-----------------------------------------------------------------------------

bool txOK()
{
return _txConsole_OK() &&
       _txCanvas_OK();
}

//-----------------------------------------------------------------------------

const char* txVersion()
{
return _TX_VERSION;
}

//-----------------------------------------------------------------------------

inline HDC  txDC()           { return _txCanvas_BackBuf[0]; }
inline HWND txWindow()       { return _txCanvas_Wnd;        }

//-----------------------------------------------------------------------------

POINT txGetExtent()
{
assert (txOK());

RECT r = {0};
GetClientRect (txWindow(), &r);
POINT size = { r.right - r.left, r.bottom - r.top };
return size;
}

int txGetExtentX() { return txGetExtent().x; }
int txGetExtentY() { return txGetExtent().y; }

//-----------------------------------------------------------------------------

bool txClear()
{
assert (txOK());
POINT size = txGetExtent();

return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
}

//-----------------------------------------------------------------------------

//VV
int linethickness = 1;

bool txSetColor (COLORREF color, int thickness)
{
assert (txOK());
//VV
linethickness = thickness;

return _txSelect (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color)) &&
        txGDI   ((Win32::SetTextColor (txDC(), color) != 0));
}

//-----------------------------------------------------------------------------

bool txColor (double r, double g, double b)
{
if (r > 1) r = 1; if (r < 0) r = 0;
if (g > 1) g = 1; if (g < 0) g = 0;
if (b > 1) b = 1; if (b < 0) b = 0;
return txSetColor (RGB (r*255, g*255, b*255));
}

//-----------------------------------------------------------------------------

COLORREF txGetColor()
{
assert (txOK());

HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); obj NEEDED;

char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

int size = GetObject (obj, 0, NULL);
GetObject (obj, sizeof (buf), buf) NEEDED;

return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
}

//-----------------------------------------------------------------------------

bool txSetFillColor (COLORREF color)
{
assert (txOK());

return _txSelect ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                             Win32::CreateSolidBrush (color));
}

//-----------------------------------------------------------------------------

bool txFillColor (double r, double g, double b)
{
if (r > 1) r = 1; if (r < 0) r = 0;
if (g > 1) g = 1; if (g < 0) g = 0;
if (b > 1) b = 1; if (b < 0) b = 0;
return txSetFillColor (RGB (r*255, g*255, b*255));
}

//-----------------------------------------------------------------------------

COLORREF txGetFillColor()
{
assert (txOK());

HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); obj NEEDED;

LOGBRUSH buf = {0};
txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) NEEDED;

return buf.lbColor;
}

//-----------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component)
{
switch (component)
    {
    case TX_RED:
    case TX_HUE:        return (BYTE)(color >>  0);

    case TX_GREEN:
    case TX_SATURATION: return (BYTE)(color >>  8);

    case TX_BLUE:
    case TX_LIGHTNESS:  return (BYTE)(color >> 16);

    default:            return -1;
    }
}

//---------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF color)
{
int r = txExtractColor (color, TX_RED),
    g = txExtractColor (color, TX_GREEN),
    b = txExtractColor (color, TX_BLUE);

double m1 = MAX (MAX (r, g), b) / 255.0,
	   m2 = MIN (MIN (r, g), b) / 255.0,
	   dm = m1 - m2,
	   sm = m1 + m2,

	   ir = r / 255.0,
	   ig = g / 255.0,
	   ib = b / 255.0,

	   ih = 0,
	   is = 0,
	   il = sm / 2;

if (dm != 0)
	{
	is = dm / ((sm <= 1)? sm : (2-sm));

	double cr = (m1 - ir) / dm,
		   cg = (m1 - ig) / dm,
		   cb = (m1 - ib) / dm;

	if (ir == m1) ih =     cb - cg;
	if (ig == m1) ih = 2 + cr - cb;
	if (ib == m1) ih = 4 + cg - cr;
	}

return RGB ((int)(ih >= 0? ih*60 : ih*60 + 360), (int)(is*255), (int)(il*255));
}

//---------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF color)
{
struct xRGB
    {
    static double calc (double h, double m1, double m2)
        {
	    if (h < 0)   h += 360;
	    if (h > 360) h -= 360;

	    return (h <  60)? m1 + (m2-m1) *      h  / 60 :
               (h < 180)? m2 :
	           (h < 240)? m1 + (m2-m1) * (240-h) / 60 :
                          m1;
        }
    };

int h = txExtractColor (color, TX_HUE),
    s = txExtractColor (color, TX_SATURATION),
    l = txExtractColor (color, TX_LIGHTNESS);

double ih = h,
       il = l / 100.0,
       is = s / 100.0,

       m2 = (il <= 0.5)? il * (1 + is) : il + is - il * is,
       m1 = 2 * il - m2,

	   ir = s? xRGB::calc (ih + 120, m1, m2) : il,
	   ig = s? xRGB::calc (ih,       m1, m2) : il,
	   ib = s? xRGB::calc (ih - 120, m1, m2) : il;

return RGB (ir * 255, ig * 255, ib * 255);
}

//-----------------------------------------------------------------------------

bool txSetPixel (double x, double y, COLORREF color)
{
assert (txOK());

txGDI ((Win32::SetPixel (txDC(), (int)x, (int)y, color))); //?? on MingW NEEDED;

RECT r = { (int)x, (int)y, (int)x, (int)y };
InvalidateRect (txWindow(), &r, false) NEEDED;
return true;
}

//-----------------------------------------------------------------------------

bool txSetPixel (double x, double y, double r, double g, double b)
{
if (r > 1) r = 1; if (r < 0) r = 0;
if (g > 1) g = 1; if (g < 0) g = 0;
if (b > 1) b = 1; if (b < 0) b = 0;
return txSetPixel (x, y, RGB (r*255, g*255, b*255));
}

//-----------------------------------------------------------------------------

COLORREF txGetPixel (double x, double y)
{
assert (txOK());

return txGDI ((Win32::GetPixel (txDC(), (int)x, (int)y)));
}

//-----------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1)
{
assert (txOK());

txGDI ((Win32::MoveToEx (txDC(), (int)x0, (int)y0, NULL))) NEEDED;
txGDI ((Win32::LineTo   (txDC(), (int)x1, (int)y1)))       NEEDED;

RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
InvalidateRect (txWindow(), &r, false) NEEDED;
return true;
}


//-----------------------------------------------------------------------------
// VV

double txGetCurrentX ()
{
assert (txOK());

POINT point;
Win32::GetCurrentPositionEx(txDC(), &point);

return point.x;
}

//-----------------------------------------------------------------------------
// VV

double txGetCurrentY ()
{
assert (txOK());

POINT point;

Win32::GetCurrentPositionEx(txDC(), &point);

return point.y;
}


//-----------------------------------------------------------------------------
// VV

bool txLineTo (double x, double y)
{
assert (txOK());

POINT oldPoint;

Win32::GetCurrentPositionEx(txDC(), &oldPoint);


txGDI ((Win32::LineTo   (txDC(), (int)x, (int)y)))                       NEEDED;

RECT r = { (int)oldPoint.x, (int)oldPoint.y, (int)x, (int)y };
InvalidateRect (txWindow(), &r, false)                                   NEEDED;
return true;
}

//-----------------------------------------------------------------------------
// VV

bool txMoveTo (double x, double y)
{
assert (txOK());

POINT point;

Win32::MoveToEx   (txDC(), (int)x, (int)y, &point)                       NEEDED;

return true;
}

//-----------------------------------------------------------------------------


bool txRectangle (double x0, double y0, double x1, double y1)
{
assert (txOK());

txGDI ((Win32::Rectangle (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) NEEDED;

RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
InvalidateRect (txWindow(), &r, false) NEEDED;
return true;
}

//-----------------------------------------------------------------------------

bool txPolygon (POINT* points, int npoints)
{
assert (txOK());

return txGDI ((Win32::Polygon (txDC(), points, npoints) != 0));
}

//-----------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1)
{
assert (txOK());

txGDI ((Win32::Ellipse (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) NEEDED;

RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
InvalidateRect (txWindow(), &r, false) NEEDED;
return true;
}

bool txCircle (double x, double y, double r)
{
return txEllipse (x-r, y-r, x+r, y+r);
}

//-----------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
{
assert (txOK());

double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

return txGDI ((Win32::Arc (txDC(),    (int)x0, (int)y0, (int)x1, (int)y1,
                           center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                           center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
}

//-----------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
{
assert (txOK());

double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

return txGDI ((Win32::Pie (txDC(),    (int)x0, (int)y0, (int)x1, (int)y1,
                           center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                           center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
}

//-----------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
{
assert (txOK());

double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

return txGDI ((Win32::Chord (txDC(),    (int)x0, (int)y0, (int)x1, (int)y1,
                             center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                             center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
}

//-----------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[])
{
assert (txOK());

int len = (int) strlen (text);
txGDI ((Win32::TextOut (txDC(), (int)x, (int)y, text, len))) NEEDED;

SIZE size = {0};
txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, len, &size))) NEEDED;

RECT r = { (int)x, (int)y, (int)x + size.cx, (int)y + size.cy };
InvalidateRect (txWindow(), &r, false) NEEDED;
return true;
}

//-----------------------------------------------------------------------------

SIZE txGetTextExtent (const char* text)
{
assert (txOK());

SIZE size = {0};
txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) NEEDED;

return size;
}

int txGetTextExtentX (const char* text) { return txGetTextExtent (text) . cx; }
int txGetTextExtentY (const char* text) { return txGetTextExtent (text) . cy; }

//-----------------------------------------------------------------------------

bool txSelectFont (const char* name, double sizeY, double sizeX,
                   int bold, bool italic, bool underline, bool strikeout)
{
assert (txOK());

_txSelect (txFontExist (name)? CreateFont ((int)sizeY, (int)(sizeX? sizeX : sizeY*10/25), 0, 0,
                                           bold, italic, underline, strikeout,
                                           DEFAULT_CHARSET,
                                           OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                           DEFAULT_QUALITY, FIXED_PITCH, name)
                               :
                               GetStockObject (SYSTEM_FIXED_FONT));
return true;
}

//-----------------------------------------------------------------------------

bool txSetTextAlign (unsigned align)
{
assert (txOK());

txGDI ((Win32::SetTextAlign (txDC(), align)));
return true;
}

//-----------------------------------------------------------------------------

LOGFONT* txFontExist (const char* name)
{
assert (txOK());

LOGFONT font   = {0};
font.lfCharSet = DEFAULT_CHARSET;
strncpy (font.lfFaceName, name, sizeof font.lfFaceName);

struct enumFonts
    {
    static int CALLBACK Proc (const LOGFONT* font, const TEXTMETRIC*, DWORD, LPARAM data)
        {
        assert (font); assert (data);
        return strnicmp (font->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
        }
    };

return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
}

//-----------------------------------------------------------------------------

bool txFloodFill (double x, double y, COLORREF color, DWORD mode)
{
assert (txOK());
if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

return txGDI ((Win32::ExtFloodFill (txDC(), (int)x, (int)y, color, mode) != 0));
}

//-----------------------------------------------------------------------------

bool txSetROP2 (int mode)
{
assert (txOK());

return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
}

//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap)
{
assert (txOK());
POINT size = { (int)sizeX, (int)sizeY };
HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); dc NEEDED;
return dc;
}

//-----------------------------------------------------------------------------

HDC txLoadImage (LPCTSTR name, double sizeX = 0, double sizeY = 0 )
{


HBITMAP image = (HBITMAP) LoadImage (NULL, name, IMAGE_BITMAP, (int)sizeX, (int)sizeY, LR_LOADFROMFILE);
if (!image) return NULL;

HDC dc = txCreateCompatibleDC (sizeX, sizeY, image);

_txSelect (image, dc);
return dc;
}

//-----------------------------------------------------------------------------

bool txDeleteCanvas (HDC dc)
{
assert (txOK());
return _txBuffer_Delete (dc);
}

//-----------------------------------------------------------------------------

bool txBitBlt (HDC dest, double xDest, double yDest, double width, double height,
               HDC src,  double xSrc,  double ySrc,  DWORD rOp)
{
assert (txOK());

return txGDI ((Win32::BitBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                              src,  (int)xSrc,  (int)ySrc, rOp) != 0));
}

//-----------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, double destX, double destY, double sizeX, double sizeY,
                       HDC src,  double srcX,  double srcY,  COLORREF transColor)
{
assert (txOK());
if (!TransparentBlt) return false;

return Win32::TransparentBlt (dest, (int)destX, (int)destY, (int)sizeX, (int)sizeY,
                              src,  (int)srcX,  (int)srcY,  (int)sizeX, (int)sizeY, transColor);
}

//-----------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, double destX, double destY, double sizeX, double sizeY,
                   HDC src,  double srcX,  double srcY,  double alpha)
{
assert (txOK());
if (!AlphaBlend) return false;

if (alpha < 0) alpha = 0;
if (alpha > 0) alpha = 1;

#ifndef AC_SRC_ALPHA
#define AC_SRC_ALPHA 0x01   // On some old MinGW versions, this is not defined.
#endif

BLENDFUNCTION blend = {AC_SRC_OVER, 0, (BYTE) (alpha * 255), AC_SRC_ALPHA};

return Win32::AlphaBlend (dest, (int)destX, (int)destY, (int)sizeX, (int)sizeY,
                          src,  (int)srcX,  (int)srcY,  (int)sizeX, (int)sizeY, blend);
}

//-----------------------------------------------------------------------------

bool txSelectRegion (double x0, double y0, double x1, double y1)
{
assert (txOK());

HRGN rgn = CreateRectRgn ((int)x0, (int)y0, (int)x1, (int)y1);
return txSelectObject (rgn);
}

//-----------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj)
{
assert (txOK());
return _txSelect (obj);
}

//-----------------------------------------------------------------------------

int txBegin()
{
_txCanvas_SetLockRefresh (_txCanvas_LockRefresh + 1);
return _txCanvas_LockRefresh;
}

//-----------------------------------------------------------------------------

int txEnd()
{
_txCanvas_SetLockRefresh (_txCanvas_LockRefresh - 1);
return _txCanvas_LockRefresh;
}

//-----------------------------------------------------------------------------

bool txUpdateWindow (bool update)
{
return _txCanvas_SetLockRefresh (update? 0 : 1);
}

//-----------------------------------------------------------------------------

bool txSleep (int time)
{
int old = _txCanvas_SetLockRefresh (0);

Sleep (time);

_txCanvas_SetLockRefresh (old);
return old;
}

//-----------------------------------------------------------------------------

bool txTextCursor (bool mode)
{
bool old = _txConsole_CursorMode;

_txConsole_CursorMode = mode;

return old;
}

//-----------------------------------------------------------------------------

inline bool txLock()
{
EnterCriticalSection (&_txCanvas_LockBackBuf);
return true;
}

//-----------------------------------------------------------------------------

inline bool txUnlock()
{
LeaveCriticalSection (&_txCanvas_LockBackBuf);
return true;

}

//-----------------------------------------------------------------------------

template <typename T> inline
T txUnlock (T value)
{
txUnlock();
return value;
}

//-----------------------------------------------------------------------------

inline double  txMouseX()       { return _txMouseX; }
inline double  txMouseY()       { return _txMouseY; }
inline int     txMouseButtons() { return _txMouseButtons; }

//-----------------------------------------------------------------------------

bool txPlaySound (const char* filename, DWORD mode)
{
mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
if (mode & SND_LOOP) mode = mode & ~SND_SYNC | SND_ASYNC;
if (!filename) mode = SND_PURGE;

return PlaySound (filename, NULL, mode);
}

//-----------------------------------------------------------------------------

bool txSetDefaults()
{
assert (txOK());

return _txCanvas_SetDefaults() &&
       _txConsole_SetDefaults();
}

//=============================================================================

//! \cond Namespaces
namespace Internal {
//! \endcond Namespaces

//=============================================================================

bool _txCanvas_SetDefaults()
{
assert (txOK());

txLock();

RECT r = {0};
GetClientRect (_txConsole_Wnd, &r) NEEDED;
POINT size = { r.right - r.left, r.bottom - r.top };

_txSelect (GetStockObject (WHITE_PEN))   NEEDED;
_txSelect (GetStockObject (WHITE_BRUSH)) NEEDED;
_txSelect (CreateFont (size.y/25, size.y/50, 0, 0,
                       FW_REGULAR, FALSE, FALSE, FALSE,
                       DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                       DEFAULT_QUALITY, DEFAULT_PITCH, NULL)) NEEDED;

Win32::SetTextColor (txDC(), RGB (255, 255, 255));
Win32::SetBkMode    (txDC(), TRANSPARENT) NEEDED;

Win32::SetROP2      (txDC(), R2_COPYPEN) NEEDED;

txUnlock();
return true;
}

//-----------------------------------------------------------------------------

bool _txConsole_SetDefaults()
{
assert (txOK());

txLock();

HDC dc = _txCanvas_BackBuf[1];

CONSOLE_SCREEN_BUFFER_INFO con = {0};
GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) NEEDED;

RECT r = {0};
GetClientRect (_txConsole_Wnd, &r) NEEDED;

POINT phy = { r.right - r.left, r.bottom - r.top };
COORD log = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
              (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

GetClientRect (_txCanvas_Wnd, &r) NEEDED;
POINT size = { r.right - r.left, r.bottom - r.top };

POINT fontSize = { (SHORT) ((1.0 * phy.x / log.X) / (1.0 * phy.x / size.x)),
                   (SHORT) ((1.0 * phy.y / log.Y) / (1.0 * phy.y / size.y)) };

_txSelect (txFontExist (_TX_CONSOLE_FONT)? CreateFont (fontSize.y, fontSize.x, 0, 0,
                                                       FW_REGULAR, FALSE, FALSE, FALSE,
                                                       DEFAULT_CHARSET,
                                                       OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                       DEFAULT_QUALITY, FIXED_PITCH, _TX_CONSOLE_FONT)
                                           :
                                           GetStockObject (SYSTEM_FIXED_FONT),
                                           dc) NEEDED;

Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
Win32::SetBkMode    (dc, TRANSPARENT) NEEDED;

txUnlock();

return true;
}

//=============================================================================

bool _txInitialize (int sizeX, int sizeY, bool centered)
{
atexit (_txOnExit);

txUpdateWindow (false);

InitializeCriticalSection (&_txCanvas_LockBackBuf);

_txConsole_Attach();

POINT size = { sizeX, sizeY };
if (centered) { size.x *= -1; size.y *= -1; }

DWORD id = 0;
_txCanvas_Thread = CreateThread (NULL, 0, _txCanvas_ThreadProc, &size, 0, &id);
_txCanvas_Thread || THROW ("Cannot create _txCanvas_Thread: CreateThread() failed");
_txWaitFor (_txCanvas_OK());

#if _TX_USE_CONSOLE_THREAD
_txConsole_Thread = CreateThread (NULL, 0, _txConsole_ThreadProc, NULL, 0, &id);
_txConsole_Thread || THROW ("Cannot create _txConsole_Thread: CreateThread() failed");
_txWaitFor (_txConsole_OK());
#endif

txSetDefaults();

txUpdateWindow (true);

return true;
}

//-----------------------------------------------------------------------------

void _txOnExit()
{
_txRunning = false;
long style = GetWindowLong(_txCanvas_Wnd, GWL_STYLE);

if (style & WS_CAPTION)
   {
   if (!_txExit) WaitForSingleObject (_txCanvas_Thread, INFINITE);
   }

_txCleanup();
}

//-----------------------------------------------------------------------------

bool _txCleanup()
{
if (_txCanvas_Thread)  CloseHandle (_txCanvas_Thread)  NEEDED; _txCanvas_Thread  = NULL;
if (_txConsole_Thread) CloseHandle (_txConsole_Thread) NEEDED; _txConsole_Thread = NULL;

_txConsole_Detach();

DeleteCriticalSection (&_txCanvas_LockBackBuf);

return true;
}

//=============================================================================

DWORD WINAPI _txCanvas_ThreadProc (LPVOID data)
{
assert (data);

_txCanvas_CreateWindow (*(POINT*) data);
_txCanvas_Wnd || THROW ("Cannot create canvas: _txCanvas_CreateWindow() failed");

MSG msg = {0};
while (GetMessage (&msg, NULL, 0, 0))
   {
   TranslateMessage (&msg);
   DispatchMessage  (&msg);
   }

return (DWORD) msg.wParam;
}
//-----------------------------------------------------------------------------
HWND _txCanvas_CreateWindow (POINT clientSize)
 {
 const char className[] = __FILE__ "\\_txCanvas\\Class";

 //VV
 bool windowed    = true;

 WNDCLASSEX wc    = {0};
 wc.cbSize        = sizeof (wc);
 wc.style         = CS_HREDRAW | CS_VREDRAW;
 wc.lpfnWndProc   = _txCanvas_WndProc;
 wc.hInstance     = GetModuleHandle (NULL);
 wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
 wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
 wc.lpszClassName = className;
 RegisterClassEx (&wc) || THROW ("RegisterClass (\"%s\") failed"_ className);

 char name[256] = ""; GetModuleFileName (NULL, name, sizeof name) NEEDED;
 int centered = false;
 if (clientSize.x < 0 && clientSize.y < 0) { clientSize.x *= -1; clientSize.y *= -1; centered = true; }

 POINT scr     = { GetSystemMetrics (SM_CXSCREEN),
 GetSystemMetrics (SM_CYSCREEN) };
 POINT frame   = { GetSystemMetrics (SM_CXFIXEDFRAME),
 GetSystemMetrics (SM_CYFIXEDFRAME) };
 POINT caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
 POINT size    = { clientSize.x + 2*frame.x, clientSize.y + 2*frame.y + caption.y };
 POINT center  = { scr.x / 2, scr.y / 2};

 //VV
 if (clientSize.x == 0 || clientSize.y == 0)
    {
    windowed      = false;
    clientSize    = scr;
    size          = scr;
    centered      = true;
    }

 if (!centered)
    {
    RECT r = {0}; GetWindowRect (_txConsole_Wnd, &r) NEEDED;
    center.x = (r.right + r.left) / 2;
    center.y = (r.bottom + r.top) / 2;
    }
//VV
DWORD wStyle = WS_POPUP;

if (windowed)
   {
   wStyle |= WS_BORDER | WS_CAPTION | WS_SYSMENU;
   }

_txCanvas_Wnd = CreateWindowEx (0, className, name, wStyle,
                                center.x - size.x/2, center.y - size.y/2, size.x, size.y,
                                NULL, NULL, GetModuleHandle (NULL), NULL);

_txCanvas_Wnd || THROW ("Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className);


 ShowWindow   (_txCanvas_Wnd, SW_SHOW);
 UpdateWindow (_txCanvas_Wnd) NEEDED;

 if (_txConsole_Wnd)
     {
     SetWindowPos (_txConsole_Wnd, HWND_NOTOPMOST, center.x -
                   size.x*2/5, center.y - size.y*2/5, 0, 0,
                   SWP_NOSIZE | SWP_NOACTIVATE | SWP_HIDEWINDOW) NEEDED;
     }
 //VV
 if (windowed)
    {
    HMENU menu = GetSystemMenu (_txCanvas_Wnd, false); menu NEEDED;
    AppendMenu (menu, MF_SEPARATOR, 0, NULL) NEEDED;
    AppendMenu (menu, MF_STRING | MF_UNCHECKED,_txIDM_CONSOLE, "Show Console")     NEEDED;
    AppendMenu (menu, MF_STRING | MF_UNCHECKED,_txIDM_ABOUT,   "About Library...") NEEDED;
    CheckMenuItem (menu,  _txIDM_CONSOLE, (IsWindowVisible (_txConsole_Wnd))? MF_CHECKED : MF_UNCHECKED);
    }

 return _txCanvas_Wnd;
 }


bool _txCanvas_OK()
{
return _txCanvas_Thread &&
       _txCanvas_Wnd &&
       _txCanvas_BackBuf[0] &&
       _txCanvas_BackBuf[1];
}

//-----------------------------------------------------------------------------

bool _txCanvas_DestroyWindow()
{
if (!_txCanvas_Wnd) return false;

char className[128] = "";
GetClassName (_txCanvas_Wnd, className, sizeof className) NEEDED;

DestroyWindow (_txCanvas_Wnd) NEEDED;
UnregisterClass (className, GetModuleHandle (NULL)) NEEDED;

_txCanvas_Wnd = NULL;
return true;
}

//-----------------------------------------------------------------------------

int _txCanvas_SetLockRefresh (int count)
{
int old = _txCanvas_LockRefresh;

_txCanvas_LockRefresh = count;

if (!_txCanvas_LockRefresh) InvalidateRect (txWindow(), NULL, false);

return old;
}

//=============================================================================

bool _txCanvas_OnCreate (HWND wnd)
{
_txRunning = true;

(_txCanvas_BackBuf[0] = _txBuffer_Create (wnd)) NEEDED;
(_txCanvas_BackBuf[1] = _txBuffer_Create (wnd)) NEEDED;

#if !_TX_USE_CONSOLE_THREAD
SetTimer (wnd, _txCanvas_Timer, _TX_WINDOW_UPDATE_INTERVAL, NULL) NEEDED;
#endif

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnDestroy (HWND wnd)
{
if (_txCanvas_Timer) KillTimer (wnd, _txCanvas_Timer) NEEDED;

if (_txCanvas_BackBuf[0]) _txBuffer_Delete (_txCanvas_BackBuf[0]); _txCanvas_BackBuf[0] = NULL;
if (_txCanvas_BackBuf[1]) _txBuffer_Delete (_txCanvas_BackBuf[1]); _txCanvas_BackBuf[1] = NULL;

PostQuitMessage (0);

// Should terminate user process (main() etc.) even if they are not finished.
// So, use exit().

if (_txRunning) { _txExit = true; exit (0); }

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnClose (HWND)
{
assert (_txCanvas_OK());

char name[256] = __FILE__;
GetModuleFileName (NULL, name, sizeof name) NEEDED;

if (_txRunning &&
    MessageBox (_txCanvas_Wnd, "The program is still running. Terminate anyway?    ", name,
                MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnPaint (HWND wnd)
{
assert (wnd);                      // assert (_txCanvas_OK()); ??W95 - Failed at window close
if (!_txCanvas_OK()) return false; //                          ??W95 - Changed-to

PAINTSTRUCT ps = {0};
HDC dc = BeginPaint (wnd, &ps); dc NEEDED;

RECT r = {0};
GetClientRect (wnd, &r) NEEDED;
POINT size = { r.right - r.left, r.bottom - r.top };

if (!_txCanvas_LockRefresh)
    {
    txGDI ((Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC(), 0, 0, SRCCOPY))) NEEDED;

    if (_txConsole_OK()) _txConsole_Draw (_txCanvas_BackBuf[1]);
    }

txGDI ((Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY))) NEEDED;

EndPaint (wnd, &ps) NEEDED;
return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnChar (HWND, WPARAM ch)
{
// assert (_txCanvas_OK()); !!!W95 - Faied at window close

INPUT_RECORD evt = {0};

evt.EventType                        = KEY_EVENT;
evt.Event.KeyEvent.bKeyDown          = true;
evt.Event.KeyEvent.wRepeatCount      = 1;
evt.Event.KeyEvent.wVirtualKeyCode   = 0;
evt.Event.KeyEvent.wVirtualScanCode  = 0;
evt.Event.KeyEvent.uChar.AsciiChar   = (char) ch;
evt.Event.KeyEvent.dwControlKeyState = 0;

DWORD written = 0;
WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written) NEEDED;

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnMouse (HWND, WPARAM buttons, LPARAM coords)
{
// assert (_txCanvas_OK()); !!!W95 - Faied at window close

_txMouseX       = LOWORD (coords);
_txMouseY       = HIWORD (coords);
_txMouseButtons = (int) buttons;

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnTimer (HWND, WPARAM)
{
// assert (_txCanvas_OK()); ??Win95 On exit App - Check failed

InvalidateRect (_txCanvas_Wnd, NULL, false) NEEDED;
UpdateWindow   (_txCanvas_Wnd)              NEEDED;

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnCmdConsole (HWND wnd, WPARAM cmd)
{
assert (wnd); assert (_txCanvas_OK()); assert (_txConsole_OK());

bool visible = IsWindowVisible (_txConsole_Wnd) != 0;

ShowWindow (_txConsole_Wnd, visible? SW_HIDE : SW_SHOW);

visible = IsWindowVisible (_txConsole_Wnd) != 0;
CheckMenuItem (GetSystemMenu (wnd, false), (int)cmd, visible? MF_CHECKED : MF_UNCHECKED);

return true;
}

//-----------------------------------------------------------------------------

bool _txCanvas_OnCmdAbout (HWND wnd, WPARAM cmd)
{
assert (wnd);

MessageBox (NULL, "\nSimple Graphics Library with BGI Emulation\n\n"
                  _TX_VERSION "  (c) Ded (TX), VV (BGI) 2005-06\n\n"
                  "Compiled with: " __FILE__ ", at "__DATE__ " " __TIME__"      \n",
                  "About TX Library",
                  MB_ICONINFORMATION);

return true;
}

//-----------------------------------------------------------------------------

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
{
switch (msg)
    {
    case WM_CREATE:       _txCanvas_OnCreate     (wnd);         break;

    case WM_CLOSE:        if (!_txCanvas_OnClose (wnd))         return 0;
    case WM_DESTROY:      _txCanvas_OnDestroy    (wnd);         break;

    case WM_PAINT:        _txCanvas_OnPaint      (wnd);         break;
    case WM_CHAR:         _txCanvas_OnChar       (wnd, wpar);   break;
    case WM_TIMER:        _txCanvas_OnTimer      (wnd, wpar);   break;

    case WM_LBUTTONUP:
    case WM_LBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MOUSEMOVE:    _txCanvas_OnMouse  (wnd, wpar, lpar); break;
    }

if (msg == WM_SYSCOMMAND) switch (wpar)
    {
    case _txIDM_ABOUT:    _txCanvas_OnCmdAbout   (wnd, wpar);   break;
    case _txIDM_CONSOLE:  _txCanvas_OnCmdConsole (wnd, wpar);   break;
    }

return DefWindowProc (wnd, msg, wpar, lpar);
}

//=============================================================================

bool _txConsole_Attach()
{
FreeConsole();
AllocConsole();

HANDLE con = GetStdHandle (STD_OUTPUT_HANDLE); con NEEDED;
COORD size = { 80, 25 };
SetConsoleScreenBufferSize (con, size) NEEDED;

_txConsole_Wnd = _txConsole_GetWindow();

return true;
}

//-----------------------------------------------------------------------------

bool _txConsole_OK()
{
return
#if _TX_USE_CONSOLE_THREAD
      _txConsole_Thread &&
#endif
      _txConsole_Wnd != NULL;
}

//-----------------------------------------------------------------------------

bool _txConsole_Detach()
{
FreeConsole();
return true;
}

//-----------------------------------------------------------------------------

DWORD WINAPI _txConsole_ThreadProc (LPVOID)
{
assert (_txConsole_OK()); assert (_txCanvas_OK());

SetThreadPriority (GetCurrentThread(), THREAD_PRIORITY_IDLE) NEEDED;

while (_txDummy())
    {
    InvalidateRect (_txCanvas_Wnd, NULL, false) NEEDED;
    UpdateWindow   (_txCanvas_Wnd)              NEEDED;

    Sleep (_TX_WINDOW_UPDATE_INTERVAL);
    }

return 0;
}

//-----------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
{
assert (_txConsole_OK()); assert (_txCanvas_OK());

txLock();

CONSOLE_SCREEN_BUFFER_INFO con = {0};
GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) NEEDED;

TCHAR* buf = new TCHAR [con.dwSize.X * con.dwSize.Y + 1]; buf NEEDED;

COORD zero = {0};
DWORD read = 0;
ReadConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE), buf,
                            con.dwSize.X * con.dwSize.Y * sizeof (TCHAR),
                            zero, &read) NEEDED;
//OemToCharBuff (buf, buf, read) NEEDED;

SIZE fontSz = {0};
Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz) NEEDED;

int sizeX = con.srWindow.Right - con.srWindow.Left + 1;
for (int y = con.srWindow.Top; y <= con.srWindow.Bottom; y++)
    Win32::TextOut (dc, 0, y*fontSz.cy, buf + y*con.dwSize.X + con.srWindow.Left, sizeX) NEEDED;

delete[] buf;

if (_txConsole_CursorMode &&
    GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
    In (con.dwCursorPosition, con.srWindow))
    {
    Win32::TextOut (dc,
                   (con.dwCursorPosition.X - con.srWindow.Left)*fontSz.cx,
                   (con.dwCursorPosition.Y - con.srWindow.Top) *fontSz.cy + 1,
                    "_", 1) NEEDED;
    }

txUnlock();
return true;
}

//-----------------------------------------------------------------------------

HWND _txConsole_GetWindow()
{
static HWND (WINAPI* GetConsoleWindow) () =
      (HWND (WINAPI*)()) _txImport ("Kernel32", "GetConsoleWindow", false);

if (GetConsoleWindow) return GetConsoleWindow();

SetLastError (0);

char title[1024] = "";
GetConsoleTitle (title, sizeof (title));

char unique [128] = "";
LARGE_INTEGER time = {0};
QueryPerformanceCounter (&time) NEEDED;
sprintf (unique, __FILE__ "(%d)\\Temp Title %08lx%08lx", __LINE__, time.HighPart, time.LowPart);

SetConsoleTitle (unique) NEEDED;

HWND con = NULL;
_txWaitFor (con = FindWindow (NULL, unique));

SetConsoleTitle (title) NEEDED;

con || THROW ("Cannot find console window");
return con;
}

//=============================================================================

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bmap)
{
assert (wnd);

txLock();

HDC wndDC = GetDC (wnd); wndDC NEEDED;
(Win32::GetDeviceCaps (wndDC, RASTERCAPS) & RC_BITBLT) || THROW ("GetDeviceCaps(): RASTERCAPS: RC_BITBLT not supported");

RECT r = {0};
GetClientRect (wnd, &r) NEEDED;
POINT sz = { r.right - r.left, r.bottom - r.top };
if (!size) size = &sz;

HDC dc = Win32::CreateCompatibleDC (wndDC);
dc || THROW ("Cannot create buffer: CreateCompatibleDC() failed");

if (!bmap) bmap = Win32::CreateCompatibleBitmap (wndDC, size->x, size->y);
bmap || THROW ("Cannot create buffer: CreateCompatibleBitmap() failed");

Win32::SelectObject (dc, bmap) NEEDED;

Win32::PatBlt (dc, 0, 0, size->x, size->y, BLACKNESS) NEEDED;

ReleaseDC (wnd, wndDC) NEEDED;

txUnlock();
return dc;
}

//-----------------------------------------------------------------------------

bool _txBuffer_Delete (HDC dc)
{
if (!dc) return false;

txLock();

HBITMAP zeroBitmap = Win32::CreateCompatibleBitmap (dc, 0, 0); zeroBitmap NEEDED;
HRGN    zeroRgn    = Win32::CreateRectRgn (0, 0, 0, 0);        zeroRgn    NEEDED;

_txSelect (Win32::GetStockObject (NULL_PEN),    dc) NEEDED;
_txSelect (Win32::GetStockObject (NULL_BRUSH),  dc) NEEDED;
_txSelect (Win32::GetStockObject (SYSTEM_FONT), dc) NEEDED;
_txSelect (zeroBitmap,                          dc) NEEDED;
_txSelect (zeroRgn,                             dc); // ??W95 NEEDED;
Win32::DeleteDC (dc)                            NEEDED;

Win32::DeleteObject (zeroBitmap)                NEEDED;
Win32::DeleteObject (zeroRgn)                   NEEDED;

txUnlock();
return true;
}

//=============================================================================

bool _txSelect (HGDIOBJ obj, HDC dc)
{
txLock();

obj = Win32::SelectObject (dc, obj); obj NEEDED;
if (obj) Win32::DeleteObject (obj); // NEEDED; ??Win95 - On exit App - Check Failed

txUnlock();

return obj != NULL;
}

//=============================================================================

bool _Throw (const char file[], int line, const char func[], DWORD error,
             const char msg[], ...)
{
 const size_t MAXSTR = 1024;

bool fatal = (msg && *msg == '\a')? (msg++, true) : false;
va_list arg; va_start (arg, msg);
char str[MAXSTR] = "", *s = str;

if (file)
    s += sprintf (s, "THROW(): %s", file);

if (line)
    s += sprintf (s, " (%d)", line);

if (func)
    s += sprintf (s, " %s()", func);

if (error)
    s += sprintf (s, ": Error %lu: ", error),
    s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL, error, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                        s, (DWORD) (sizeof (str) - (s - str)), NULL) - 3;
if (msg && *msg)
    s +=  sprintf (s, ": "),
    s += vsprintf (s, msg, arg);

s += sprintf (s, "    \n");

printf (str);
OutputDebugString (str);
MessageBox (NULL, str, fatal? "System: Fatal Error" : "System",
            MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

if (fatal) abort();

va_end (arg);
return false;
}

//=============================================================================

FARPROC _txImport (const char lib[], const char name[], int required)
{
FARPROC addr = GetProcAddress (LoadLibrary (lib), name);

if (!addr && required) THROW ("\aCannot import %s\\%s" _ lib _ name);

return addr;
}

//@}
//! \endcond Internal
//=============================================================================
//! \cond Namespaces

} // namespace Internal
} // namespace TX
} // anonymous namespace

using namespace TX;
using namespace TX::Internal::Win32;

//! \endcond Namespaces
//=============================================================================

#endif // __TXLIB_H

//=============================================================================
//  \name    Примеры использования
//=============================================================================

//-----------------------------------------------------------------------------
/*! \page    Tutorial_1st Пример: Простейший

	\section Tutorial_1st_01 Структура простейшей программы

	Простейшая программа на С (или С++) состоит из двух частей: раздела
	подключения библиотек и главной функции программы. Рассмотрим пример,
	в котором рисуется на экране простой рисунок.

	\section Tutorial_1st_02 Раздел подключения библиотек

	Директивы (команды) подключения библиотек находятся обычно в начале
	файла программы и выглядят обычно так:

	\code
    #include <stdio.h>
    #include "Graphics.h"
	\endcode

	\c Stdio.h и \c Graphics.h - файлы библиотек, которые подключаются к вашей
	программе. После этого вы можете использовать команды, функции и переменные,
	объявленные в этих файлах. Больше, чем нужно, библиотек подключать не стоит,
	хотя это и не вредно. Когда используется много библиотек, раздел может быть
	очень большим.

	\section Tutorial_1st_03 Главная функция программы

	Программа на С (С++) состоит из функций. Функция - это описание каких-либо
	действий с заданным именем (названием).

	Например,

	\code
    void main()
    {
    txCreateWindow (800, 600);
    txLine (320, 290, 320, 220);
    }
	\endcode

	Главная функция - это функция, с которой начинается исполнение программы.
	Ее имя - \c main(). Скобки показывают, что речь идет именно о функции, т.е.,
	об описании каких-то действий. Для того, чтобы функция начала работу, ее
	нужно \a вызвать. Функцию \c main() вызывает сама операционная система
	компьютера. Слово \c void означает, что \c main() не будет передавать
	тому, кто ее вызывал, каких-либо результатов своих вычислений. Это
	неудивительно, т.к. мы ничего и не вычисляем, а просто рисуем на экране.

	Действия, записанные в функции, заключаются в фигурные скобки \c { и \c }.
	Они обозначают начало и конец функции.

	Внутри функции записаны вызовы команд, которые что-то рисуют на экране.
	Между командами, там, где это логически необходимо, стоят пустые строки,
	отделяющие одни части программы от других. Это способствует большей
	понятности программы. Пустая строка в программировании соответствует
	началу абзаца текста в русском языке.

	Для понимания программы и того, чтобы в ней не появлялись ошибки, очень
	важно, чтобы в нужных местах в ней стояли пробелы. Обычно их ставят до
	открывающих круглых скобок, после запятых, до и после знаков операций.
	Наличие пробелов делает программу приятной на вид, и предотвращает
	напряжение глаз при работе с компьютером. Работа с плохо оформленным
	текстом программы может нанести вред глазам, снизить зрение.

	Пример плохо написанной программы:

	\code
    #include "Graphics.h"
    void   main(){
    txCreateWindow(800,600);  // По-моему, про зрение все ясно. :)
    txLine(320,290,320,220);
     txLine (320, 290,280,350);
      txLine(320, 290,360,350);
     txLine(320,230,270,275);
    txLine(320,230, 400,220);
    txCircle(320,190,30);
      txSelectFont( "Times",60);
    txTextOut(240,400,"Hello, world!");
    }
    \endcode

	Для задания положения рисуемых фигур используется координатная система,
	у которой верхний левый угол расположен слева-вверху, а ось OY смотрит
	вниз. Это несколько непривычно, но деваться некуда. :) Например, команда

	\code
    txLine (320, 290, 320, 220);
    \endcode

    проводит линию из точки x=320 и у=290 в точку с x=320 и y=220.

	Каждая команда заканчивается точкой с запятой. Это - аналог точки в русском
	языке. Точка с запятой ставится в конце каждого \a законченного действия
	или объявления. Например, в строке с \c txCreateWindow (800, 600) точка с
	запятой ставится, т.к. в этой строке "закончена мысль" о том, что надо
	создать окно для рисования. В строке с <tt>void main()</tt> - не ставится,
	т.к. описание функции \c main() не закончено (на самом деле, оно там только
	начато).

	Если в программе используются строки, они заключаются в двойные кавычки,
	например:

	\code
    txTextOut (240, 400, "Hello, world!");
    \endcode

	Если в программе присутствут числа с дробной частью, то эта часть
	отделяется от целой части точкой, а не запятой, как в русском языке.

	\section Tutorial_1st_04 Распространенные ошибки

	В простых программах ошибки бывают двух видов:

	- Ошибки записи (орфография, пунктуация) - их называют синтаксическими
	  ошибками <i>(syntax error).</i> Они происходят до запуска программы,
	  на стадии перевода программы в машинный код (стадии компиляции). Поэтому
	  их называют ошибками времени компиляции. Исполняемый файл при этом не
	  создается и программа не запускается.

	- Логические ошибки - они происходят после запуска программы, при этом
	  при компиляции ошибок нет (иногда имеются предупреждения, \a warnings).
	  Их называют ошибками времени исполнения.

	Практически все синтаксические ошибки на этой стадии происходят из-за
	невнимательности. Распространенные синтаксические ошибки:

	- Путают ключевые слова, названия библиотек и команд:
	  \code
	  #iclude "grafics.h"
	  vod maim()
	  tx Line (10, 10, 20, 20)
	  \endcode

	- Путают большие и маленькие буквы:
	  \code
	  txcircle (100, 100, 10)
	  \endcode

	- Не ставят скобки:
	  \code
	  void main
	  \endcode

	- Забывают запятые:
	  \code
	  txСircle (100 100 10)
	  \endcode

	- Забывают точки с запятой:
	  \code
	  txSelectFont ("Times", 60)
	  \endcode

	- Забывают или путают кавычки:
	  \code
	  txSelectFont (Times, 60)
	  txSelectFont ('Times', 60)
	  \endcode

	- Ставят лишние точки с запятой:
	  \code
	  void main();
	  \endcode

	- Указвают дробную часть числа через запятую:
	  \code
	  3,1415
	  \endcode

	- Забывают фигурные скобки:
  	  \code
      void main()
      txCreateWindow (800, 600);
      txLine (320, 290, 320, 220);
	  \endcode

	- Забывают писать открывающие или закрывающие скобки, или пишут лишние,
	  отчего появляются непарные скобки, или путают виды скобок:
  	  \code
      void main()
      {
      txCreateWindow (800, 600);

      txLine (320, 290, 320, 220;  // Не закрыта круглая скобка
      }
	  \endcode
  	  \code
      void main()
      {
      txCreateWindow {800, 600};   // Фигурные скобки вместо круглых
      }

      txLine (320, 290, 320, 220;  // Команда за пределами функции main()
      }                            // Лишняя скобка
	  \endcode

	- Помещают команды за пределы фигурных скобок
  	  \code
      void main()
      {
      txCreateWindow (800, 600);
      }

      txLine (320, 290, 320, 220); // Команда за пределами функции main()
	  \endcode

	Бывают и логические ошибки. Например, мы не выбрали нужный цвет рисования
	(по умолчанию он белый), или нарисовали одну фигуру поверх другой, и она
	закрыла предыдущую, или задали неверные координаты. Эти ошибки появляются
	после запуска программы. Их легко понять, если выполнить на листе бумаги
	все команды одну за другой, в том порядке, в котором они заданы в программе.

	\section Tutorial_1st_Code Законченный пример
    \include TXEx01.cpp
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_1stEx Пример: Улучшенный :)

	\section Tutorial_1stEx_Code Законченный пример
    \include TXEx02.cpp
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Functions Пример: Функции

	\section Tutorial_Functions_Code Законченный пример
    \include TXEx03.cpp
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Parameters Пример: Функции с параметрами

	\section Tutorial_Parameters_Code Законченный пример
    \include TXEx04.cpp
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_While Пример: Циклы

	\section Tutorial_While_Code Законченный пример
    \include TXEx05.cpp
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_For Пример: Циклы (2)

	\section Tutorial_For_Code Законченный пример
    \include TXEx06.cpp
*/





///////////////////////////////////////////////////////////////////////////////
// BGI Support
///////////////////////////////////////////////////////////////////////////////

#ifndef __TX_GRAPHICS_H
#define __TX_GRAPHICS_H


#ifdef BGISUPPORTCHECK
#define BGINOSUPPORT printf ("Unsupported BGI function: %s", __FUNCTION__);
#else
#define BGINOSUPPORT
#endif

// BGI Colors------------------------------------------------------------------

//! \cond Namespaces
namespace {
namespace TX_BGI {
//! \endcond Namespaces


//! \cond Internal
enum COLORS {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE,
};


COLORREF ColorBGI2TX(int color){
   COLORREF txcol = TX_WHITE;
   switch (color){
       case BLACK:           txcol = TX_BLACK;       break;
       case BLUE:            txcol = TX_BLUE;        break;
       case GREEN:           txcol = TX_GREEN;       break;
       case CYAN:            txcol = TX_CYAN;        break;
       case RED:             txcol = TX_RED;         break;
       case MAGENTA:         txcol = TX_BLACK;       break;
       case BROWN:           txcol = TX_BROWN;       break;
       case LIGHTGRAY:       txcol = TX_LIGHTGRAY;   break;
       case DARKGRAY:        txcol = TX_DARKGRAY;    break;
       case LIGHTBLUE:       txcol = TX_LIGHTBLUE;   break;
       case LIGHTGREEN:      txcol = TX_LIGHTGREEN;  break;
       case LIGHTCYAN:       txcol = TX_LIGHTCYAN;   break;
       case LIGHTRED:        txcol = TX_LIGHTRED;    break;
       case LIGHTMAGENTA:    txcol = TX_LIGHTMAGENTA;break;
       case YELLOW:          txcol = TX_YELLOW;      break;
       case WHITE:           txcol = TX_WHITE;       break;
       default:              txcol = color;
  }
  return txcol;
}

int  ColorTX2BGI(int color){
   int  txcol = WHITE;
   switch (color){
       case TX_BLACK:           txcol = BLACK;       break;
       case TX_BLUE:            txcol = BLUE;        break;
       case TX_GREEN:           txcol = GREEN;       break;
       case TX_CYAN:            txcol = CYAN;        break;
       case TX_RED:             txcol = RED;         break;
       case TX_MAGENTA:         txcol = BLACK;       break;
       case TX_BROWN:           txcol = BROWN;       break;
       case TX_LIGHTGRAY:       txcol = LIGHTGRAY;   break;
       case TX_DARKGRAY:        txcol = DARKGRAY;    break;
       case TX_LIGHTBLUE:       txcol = LIGHTBLUE;   break;
       case TX_LIGHTGREEN:      txcol = LIGHTGREEN;  break;
       case TX_LIGHTCYAN:       txcol = LIGHTCYAN;   break;
       case TX_LIGHTRED:        txcol = LIGHTRED;    break;
       case TX_LIGHTMAGENTA:    txcol = LIGHTMAGENTA;break;
       case TX_YELLOW:          txcol = YELLOW;      break;
       case TX_WHITE:           txcol = WHITE;       break;
       default:              txcol = color;
  }
  return txcol;
}

// Fonts ----------------------------------------------------------------------

const char *BGIFontNames[]={
  "System",
  "Tahoma",
  "Times New Roman",
  "Verdana",
  "Arial",
  "System",
  "Tahoma",
  "Times New Roman",
  "Verdana",
  "Arial"
};

// Other constants ------------------------------------------------------------

enum graphics_errors {      /* graphresult error return codes */
    grOk               =   0,
    grNoInitGraph      =  -1,
    grNotDetected      =  -2,
    grFileNotFound     =  -3,
    grInvalidDriver    =  -4,
    grNoLoadMem        =  -5,
    grNoScanMem        =  -6,
    grNoFloodMem       =  -7,
    grFontNotFound     =  -8,
    grNoFontMem        =  -9,
    grInvalidMode      = -10,
    grError            = -11,   /* generic error */
    grIOerror          = -12,
    grInvalidFont      = -13,
    grInvalidFontNum   = -14,
    grInvalidVersion   = -18
};

enum graphics_drivers {     /* define graphics drivers */
    DETECT,         /* requests autodetection */
    CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514,    /* 1 - 6 */
    HERCMONO, ATT400, VGA, PC3270,          /* 7 - 10 */
    CURRENT_DRIVER = -1
};

enum graphics_modes {       /* graphics modes for each driver */
    CGAC0      = 0,  /* 320x200 palette 0; 1 page   */
    CGAC1      = 1,  /* 320x200 palette 1; 1 page   */
    CGAC2      = 2,  /* 320x200 palette 2: 1 page   */
    CGAC3      = 3,  /* 320x200 palette 3; 1 page   */
    CGAHI      = 4,  /* 640x200 1 page          */
    MCGAC0     = 0,  /* 320x200 palette 0; 1 page   */
    MCGAC1     = 1,  /* 320x200 palette 1; 1 page   */
    MCGAC2     = 2,  /* 320x200 palette 2; 1 page   */
    MCGAC3     = 3,  /* 320x200 palette 3; 1 page   */
    MCGAMED    = 4,  /* 640x200 1 page          */
    MCGAHI     = 5,  /* 640x480 1 page          */
    EGALO      = 0,  /* 640x200 16 color 4 pages    */
    EGAHI      = 1,  /* 640x350 16 color 2 pages    */
    EGA64LO    = 0,  /* 640x200 16 color 1 page     */
    EGA64HI    = 1,  /* 640x350 4 color  1 page     */
    EGAMONOHI  = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
    HERCMONOHI = 0,  /* 720x348 2 pages         */
    ATT400C0   = 0,  /* 320x200 palette 0; 1 page   */
    ATT400C1   = 1,  /* 320x200 palette 1; 1 page   */
    ATT400C2   = 2,  /* 320x200 palette 2; 1 page   */
    ATT400C3   = 3,  /* 320x200 palette 3; 1 page   */
    ATT400MED  = 4,  /* 640x200 1 page          */
    ATT400HI   = 5,  /* 640x400 1 page          */
    VGALO      = 0,  /* 640x200 16 color 4 pages    */
    VGAMED     = 1,  /* 640x350 16 color 2 pages    */
    VGAHI      = 2,  /* 640x480 16 color 1 page     */
    PC3270HI   = 0,  /* 720x350 1 page          */
    IBM8514LO  = 0,  /* 640x480 256 colors      */
    IBM8514HI  = 1   /*1024x768 256 colors      */
};

enum line_styles {      /* Line styles for get/setlinestyle */
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,   /* User defined line style */
};

enum line_widths {      /* Line widths for get/setlinestyle */
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

enum font_names {
    DEFAULT_FONT    = 0,    /* 8x8 bit mapped font */
    TRIPLEX_FONT    = 1,    /* "Stroked" fonts */
    SMALL_FONT  = 2,
    SANS_SERIF_FONT = 3,
    GOTHIC_FONT = 4,
    SCRIPT_FONT = 5,
    SIMPLEX_FONT = 6,
    TRIPLEX_SCR_FONT = 7,
    COMPLEX_FONT = 8,
    EUROPEAN_FONT = 9,
    BOLD_FONT = 10
};

#define HORIZ_DIR   0   /* left to right */
#define VERT_DIR    1   /* bottom to top */

enum fill_patterns {        /* Fill patterns for get/setfillstyle */
    EMPTY_FILL,     /* fills area in background color */
    SOLID_FILL,     /* fills area in solid fill color */
    LINE_FILL,      /* --- fill */
    LTSLASH_FILL,       /* /// fill */
    SLASH_FILL,     /* /// fill with thick lines */
    BKSLASH_FILL,       /* \\\ fill with thick lines */
    LTBKSLASH_FILL,     /* \\\ fill */
    HATCH_FILL,     /* light hatch fill */
    XHATCH_FILL,        /* heavy cross hatch fill */
    INTERLEAVE_FILL,    /* interleaving line fill */
    WIDE_DOT_FILL,      /* Widely spaced dot fill */
    CLOSE_DOT_FILL,     /* Closely spaced dot fill */
    USER_FILL       /* user defined fill */
};

enum putimage_ops {     /* BitBlt operators for putimage */
    COPY_PUT,        /* MOV */
    XOR_PUT,        /* XOR */
    OR_PUT,         /* OR  */
    AND_PUT,        /* AND */
    NOT_PUT         /* NOT */
};

enum text_just {        /* Horizontal and vertical justification
                           for settextjustify */
    LEFT_TEXT,
    CENTER_TEXT,
    RIGHT_TEXT,

    BOTTOM_TEXT,
     /* CENTER_TEXT = 1,  already defined above */
    TOP_TEXT,
};

#define MAXCOLORS 15

struct palettetype {
    unsigned char size;
    signed char colors[MAXCOLORS+1];
};

struct linesettingstype {
    int linestyle;
    unsigned upattern;
    int thickness;
};

struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
};

struct fillsettingstype {
    int pattern;
    int color;
};

struct pointtype {
    int x, y;
};

struct viewporttype {
    int left, top, right, bottom;
    int clip;
};

struct arccoordstype {
    int x, y;
    int xstart, ystart, xend, yend;
};
//! \endcond Internal

// BGI functions --------------------------------------------------------------
//! \ingroup BGI
void arc(int _x, int _y, int _stangle, int _endangle, int _radius);

//! \ingroup BGI
void bar(int _left, int _top, int _right, int _bottom);

//! \ingroup BGI
void circle(int _x, int _y, int _radius);

//! \ingroup BGI
void cleardevice(void);

//! \ingroup BGI
void clearviewport(void);

//! \ingroup BGI
void closegraph(void);

//! \ingroup BGI
void fillpoly(int _numpoints, const int *_polypoints);

//! \ingroup BGI
void drawpoly(int _numpoints, const int *_polypoints);

//! \ingroup BGI
void ellipse(int _x, int _y, int _stangle, int _endangle,
             int _xradius, int _yradius);

//! \ingroup BGI
void fillellipse( int _x, int _y, int _xradius, int _yradius );


//! \ingroup BGI
void floodfill(int _x, int _y, int _border);

//void getarccoords(struct arccoordstype *_arccoords);

void getaspectratio(int *_xasp, int *_yasp);

//! \ingroup BGI
int getbkcolor(void);

//! \ingroup BGI
int getcolor(void);

//struct palettetype *  getdefaultpalette( void );

//char* getdrivername(void);


void getfillpattern(char *_pattern);

//void  getfillsettings(struct fillsettingstype *_fillinfo);

int getgraphmode(void);


void getimage(int _left, int _top, int _right, int _bottom,
                   void *_bitmap);

//void getlinesettings(struct linesettingstype *_lineinfo);

//! \ingroup BGI
int getmaxcolor(void);

int getmaxmode(void);

//! \ingroup BGI
int getmaxx(void);

//! \ingroup BGI
int getmaxy(void);

char *getmodename( int _mode_number );

void getmoderange(int _graphdriver, int *_lomode,
                   int *_himode);

//! \ingroup BGI
unsigned  getpixel(int _x, int _y);

// void getpalette(struct palettetype *_palette);

//! \ingroup BGI
int getpalettesize( void );

// void gettextsettings(struct textsettingstype *_texttypeinfo);

// void getviewsettings(struct viewporttype *_viewport);

//! \ingroup BGI
int getx(void);

//! \ingroup BGI
int gety(void);

//! \ingroup BGI
void graphdefaults(void);

char* grapherrormsg(int _errorcode);

void   _graphfreemem(void *_ptr, unsigned _size);

void * _graphgetmem(unsigned _size);

int    graphresult(void);

unsigned  imagesize(int _left, int _top, int _right, int _bottom);

//! \ingroup BGI
void initgraph(int  *_graphdriver = NULL,
               int  *_graphmode = NULL,
               const char *_pathtodriver = NULL);


//int     installuserdriver( const char *_name,
//                int huge (*detect)(void) );

int installuserfont( const char *_name );

//! \ingroup BGI
void line(int _x1, int _y1, int _x2, int _y2);

//! \ingroup BGI
void linerel(int _dx, int _dy);

//! \ingroup BGI
void lineto(int _x, int _y);

//! \ingroup BGI
void moverel(int _dx, int _dy);

//! \ingroup BGI
void moveto(int _x, int _y);

//! \ingroup BGI
void outtext(const char *_textstring);

//! \ingroup BGI
void outtextxy(int _x, int _y, const char *_textstring);

//! \ingroup BGI
void pieslice(int _x, int _y, int _stangle, int _endangle,
                   int _radius);


void putimage(int _left, int _top, const void *_bitmap, int _op);

//! \ingroup BGI
void putpixel(int _x, int _y, int _color);

//! \ingroup BGI
void rectangle(int _left, int _top, int _right, int _bottom);

//! \ingroup BGI
void restorecrtmode(void);

void sector( int _X, int _Y, int _StAngle, int _EndAngle,
                  int _XRadius, int _YRadius );

void setactivepage(int _page);

//void setallpalette(const struct palettetype *_palette);

//void        setaspectratio( int _xasp, int _yasp );

//! \ingroup BGI

void setbkcolor(int _color);

//! \ingroup BGI
void setcolor(int _color);

void  setfillpattern(const char *_upattern, int _color);

//! \ingroup BGI
//! \brief   используется только цвет заливки, стиль игнорируются.
void  setfillstyle(int _pattern, int _color);

unsigned setgraphbufsize(unsigned _bufsize);

void setgraphmode(int _mode);

//! \ingroup BGI
//! \brief   используется только толщина линии, стили игнорируются.
void setlinestyle(int _linestyle, unsigned _upattern,
                   int _thickness);

void setpalette(int _colornum, int _color);


void setrgbpalette(int _colornum,
                   int _red, int _green, int _blue);

//! \ingroup BGI
void settextjustify(int _horiz, int _vert);

//! \ingroup BGI
//! \brief Используются шрифты Windows, точные соответствия размеров не соблюдаются.
void settextstyle(int _font, int _direction, int _charsize);


void setusercharsize(int _multx, int _divx,
                      int _multy, int _divy);
//! \ingroup BGI
void setviewport(int _left, int _top, int _right, int _bottom,
                  int _clip);

void setvisualpage(int _page);

//! \ingroup BGI
void setwritemode(int _mode);

//! \ingroup BGI
int textheight(const char *_textstring);

//! \ingroup BGI
int  textwidth(const char *_textstring);


//== Other functions ===========================================================
//! \ingroup BGI
//! \brief   Весьма популярная функция для BGI-программ :-)
void delay(int msecs);


//-----------------------------------------------------------------------------


//! \cond Internal

void arc(int _x, int _y, int _stangle, int _endangle, int _radius){
  txArc((double)_x, (double)_y, (double)_x + 2 * _radius, (double)_y + 2 * _radius, (double)_stangle,
        (double)_endangle - _stangle);
}

void bar(int _left, int _top, int _right, int _bottom){
  txRectangle((double)_left, (double)_top, (double)_right, (double)_bottom);
}

void bar3d(int _left, int _top, int _right, int _bottom,
                int _depth, int _topflag){                          BGINOSUPPORT
}

void circle(int _x, int _y, int _radius){
  COLORREF currentColor = txGetFillColor();
  txSetFillColor(TX_TRANSPARENT);
  txCircle((double)_x, (double)_y, (double)_radius);
  txSetFillColor(currentColor);
}

void cleardevice(void){
  txClear();
}

void clearviewport(void){
  txClear();
}

void closegraph(void){
  txSetFillColor(TX_BLACK);
  txClear();
}


void  fillpoly(int _numpoints, const int *_polypoints){

  POINT *points = new POINT[_numpoints];

  for (int i = 0; i < _numpoints; i++){
    points[i].x = _polypoints[i * 2];
    points[i].y = _polypoints[i * 2 + 1];
  }

  txPolygon(points, _numpoints);

  delete[] points;
}

void drawpoly(int _numpoints, const int *_polypoints){
  COLORREF currentColor = txGetFillColor();
  txSetFillColor(TX_TRANSPARENT);
  fillpoly(_numpoints,_polypoints);
  txSetFillColor(currentColor);
}

void ellipse(int _x, int _y, int _stangle, int _endangle,
              int _xradius, int _yradius){
  COLORREF currentColor = txGetFillColor();
  txSetFillColor(TX_TRANSPARENT);
  txEllipse((double)_x, (double)_y, (double)_x + 2 * (double)_xradius,
            (double)_y + 2 * (double)_yradius);
  txSetFillColor(currentColor);
}

void  fillellipse( int _x, int _y, int _xradius, int _yradius ){
  txEllipse((double)_x, (double)_y, (double)_x + 2 * _xradius, (double)_y + 2 * _yradius);
}



void  floodfill(int _x, int _y, int _border){
  txFloodFill((double)_x, (double)_y, ColorBGI2TX(_border), FLOODFILLBORDER);
}

//void getarccoords(struct arccoordstype *_arccoords);


int getbkcolor(void){
  return ColorTX2BGI(txGetColor());
}

int getcolor(void){
 return ColorTX2BGI(txGetColor());
}

//struct palettetype *  getdefaultpalette( void );

//char* getdrivername(void){
//     return (char*)NULL;
//}



//void  getfillsettings(struct fillsettingstype *_fillinfo);

int getgraphmode(void){
  return 0;
}


void getimage(int _left, int _top, int _right, int _bottom,
                   void *_bitmap);

//void getlinesettings(struct linesettingstype *_lineinfo);


int getmaxcolor(void){
  return 16;
}

int getmaxmode(void){
  return 0;
}

int getmaxx(void){
  return txGetExtentX();
}


int getmaxy(void){
  return txGetExtentY();
}

char *getmodename( int _mode_number ){
  return NULL;
}

void getmoderange(int _graphdriver, int *_lomode,
                   int *_himode){
}

int getpalettesize( void ){
  return 16;
}
// void gettextsettings(struct textsettingstype *_texttypeinfo);

// void getviewsettings(struct viewporttype *_viewport);


int getx(void){
    return (int)txGetCurrentX();
}


int gety(void){
    return (int)txGetCurrentY();
}


void graphdefaults(void){
  txSetDefaults();
}

char* grapherrormsg(int _errorcode){
	return 0;
}


int    graphresult(void){
  return txOK();
}



void initgraph(int  *_graphdriver,
               int  *_graphmode,
               const char *_pathtodrive){
  txCreateWindow(0, 0, true);
  txTextCursor(false);
}

//int     installuserdriver( const char *_name,
//                int huge (*detect)(void) );

int installuserfont( const char *_name ){
	return 0;
}


void line(int _x1, int _y1, int _x2, int _y2){
  txLine((double)_x1, (double)_y1, (double)_x2, (double)_y2);
}


void linerel(int _dx, int _dy){
  txLineTo(txGetCurrentX() + _dx, txGetCurrentY() + _dx);
}


void lineto(int _x, int _y){
  txLineTo((double)_x, (double)_y);
}


void moverel(int _dx, int _dy){
  txMoveTo(txGetCurrentX() + _dx, txGetCurrentY() + _dx);
}


void moveto(int _x, int _y){
     txMoveTo(_x, _y);
}


void outtext(const char *_textstring){
  txTextOut(txGetCurrentX(), txGetCurrentY(), _textstring);
}


void outtextxy(int _x, int _y, const char *_textstring){
  txTextOut(_x, _y, _textstring);
}


void pieslice(int _x, int _y, int _stangle, int _endangle,
                   int _radius){
  txPie(_x, _y, _x + 2 * _radius, _y + 2 * _radius, _stangle, _endangle);
}

void putimage(int _left, int _top, const void *_bitmap, int _op);


void putpixel(int _x, int _y, int _color){
  txSetPixel(_x, _y, ColorBGI2TX(_color));
}


void rectangle(int _left, int _top, int _right, int _bottom){
  COLORREF currentColor = txGetFillColor();
  txSetFillColor(TX_TRANSPARENT);
  txRectangle((double)_left, (double)_top, (double)_right, (double)_bottom);
  txSetFillColor(currentColor);
}


void restorecrtmode(void){
  txSetFillColor(TX_BLACK);
  txClear();
  txSetDefaults();
}

void sector( int _X, int _Y, int _StAngle, int _EndAngle,
                  int _XRadius, int _YRadius ){                     BGINOSUPPORT
}



//void        setallpalette(const struct palettetype *_palette);

//void        setaspectratio( int _xasp, int _yasp );


void setbkcolor(int _color){
  txSetFillColor(ColorBGI2TX(_color));
}


void setcolor(int _color){
  txSetColor(ColorBGI2TX(_color), linethickness);
}

void  setfillpattern(const char *_upattern, int _color){            BGINOSUPPORT
}

void  setfillstyle(int _pattern, int _color){
  txSetFillColor(ColorBGI2TX(_color));
}

unsigned setgraphbufsize(unsigned _bufsize){                        BGINOSUPPORT
  return 0;
}
void setgraphmode(int _mode){
}

void setlinestyle(int _linestyle, unsigned _upattern,
                   int _thickness){
  txSetColor(txGetColor(), _thickness);
}

void setpalette(int _colornum, int _color){
}


void setrgbpalette(int _colornum,
                   int _red, int _green, int _blue){
}


void settextjustify(int _horiz, int _vert){

  switch (_horiz){
    case LEFT_TEXT :  _horiz = TA_LEFT;         break;
    case RIGHT_TEXT:  _horiz = TA_RIGHT;        break;
    case CENTER_TEXT: _horiz = TA_CENTER;       break;
  }

  switch (_vert){
    case TOP_TEXT :   _vert = TA_TOP;          break;
    case BOTTOM_TEXT: _vert = TA_BOTTOM;       break;
  }

  txSetTextAlign  (_horiz | _vert);
}

void settextstyle(int _font, int _direction, int _charsize){
  txSelectFont(BGIFontNames[_font], _charsize * 10, 10);
}
void setusercharsize(int _multx, int _divx,
                      int _multy, int _divy){
}

void setviewport(int _left, int _top, int _right, int _bottom,
                  int _clip){
  txSelectRegion((double)_left, (double)_top, (double)_right, (double)_bottom);
}

void setwritemode(int _mode){
  switch (_mode){
    case COPY_PUT:   _mode = R2_COPYPEN;       break;
    case XOR_PUT:    _mode = R2_XORPEN;        break;
  }
  txSetROP2(_mode);
}


int textheight(const char *_textstring){
   return txGetTextExtentY(_textstring);
}


int  textwidth(const char *_textstring){
   return txGetTextExtentX(_textstring);
}


//== Other functions ===========================================================

void delay(int msecs){
  txSleep(msecs);
}

//! \endcond Internal


//! \cond Namespaces

} //namespace TX_BGI
} //namespace anonymous


using namespace TX_BGI;
//! \endcond Namespaces

// Prior build 50 compatibility
#define txSetBkColor txSetFillColor
#define txBkColor    txFillColor
#define txGetBkColor txGetFillColor


//=============================================================================

#endif // _TX_GRAPHICS_H

//=============================================================================


///////////////////////////////////////////////////////////////////////////////
// ADDON
///////////////////////////////////////////////////////////////////////////////


#ifndef __TX_ADDON
#define __TX_ADDON


//! \cond Namespaces
namespace {
namespace TX_ADDON {
//! \endcond Namespaces

//-----------------------------------------------------------------------------
//! \ingroup ADDON
//! \brief   Сохраняет в файл изображение в формате BMP.
//! \return  Успех операции
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(),  txBitBlt(), txAlphaBlend(), txTransparentBlt()
//! \remark  функция разработана Птахиным А. (FiveStars)

bool txeSaveImage(LPCSTR filename, //!< Имя сохраняемого файла
                  HDC fromDC,      //!< Холст с которого сохраняется изображение
                  int x,           //!< х-координата левого верхнего угла сохраняемого фрагмента холста
                  int y,           //!< y-координата левого верхнего угла сохраняемого фрагмента холста
                  int sizeX,       //!< Ширина сохраняемого фрагмента
                  int sizeY        //!< Высота сохраняемого фрагмента
                  );

//------------------------------------------------------------------------------

//! \cond Internal
bool txeSaveImage(LPCSTR filename, HDC fromDC, int x, int y, int sizeX, int sizeY)
{
  assert (txOK());

        HBITMAP HBM;
        BITMAP BM;
        BITMAPFILEHEADER BFH;
        BITMAPINFO BI = {0};
        LPBITMAPINFO BIH;
        DWORD dwTemp;
        DWORD ColorSize,DataSize;
        WORD BitCount;
        HANDLE FP;
        HDC DC;
        char * Buf;
        char s[10];

        DC = txCreateCompatibleDC(sizeX, sizeY);
        txBitBlt(DC, 0, 0, sizeX, sizeY, fromDC, x, y);

        HBM = (HBITMAP) Win32::GetCurrentObject(DC, OBJ_BITMAP);
        Win32::GetObject(HBM, sizeof(BITMAP), (LPSTR) &BM);

        BitCount = (WORD) BM.bmPlanes * BM.bmBitsPixel;

        switch(BitCount)
        {
            case 1:
            case 4:
            case 8:
            case 32:
               ColorSize = sizeof(RGBQUAD) * (1 << BitCount);
               break;
            case 24:
               ColorSize = 0;
                break;
        }

        DWORD t = BM.bmWidth * BitCount;
        DataSize = (t % 32 + t) / 8 * BM.bmHeight;

        BIH = &BI;
        BIH -> bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);
        BIH -> bmiHeader.biWidth         = BM.bmWidth;
        BIH -> bmiHeader.biHeight        = BM.bmHeight;
        BIH -> bmiHeader.biPlanes        = 1;
        BIH -> bmiHeader.biBitCount      = BitCount;
        BIH -> bmiHeader.biCompression   = 0;
        BIH -> bmiHeader.biSizeImage     = DataSize;
        BIH -> bmiHeader.biXPelsPerMeter = 0;
        BIH -> bmiHeader.biYPelsPerMeter = 0;
        if (BitCount < 24)
        {
           BIH -> bmiHeader.biClrUsed       = (1 << BitCount);
        }
        BIH -> bmiHeader.biClrImportant  = 0;

        BFH.bfType                     = 0x4d42;
        BFH.bfOffBits                  = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)+ BIH->bmiHeader.biClrUsed * sizeof(RGBQUAD);
        BFH.bfReserved1                = 'V';
        BFH.bfReserved2                = 'V';
        BFH.bfSize                     = BFH.bfOffBits + DataSize;
        Buf = new char[DataSize];

        Win32::GetDIBits(DC, HBM, 0, (WORD) BM.bmHeight, Buf, BIH, DIB_RGB_COLORS);
        FILE * F = fopen(filename, "wb");

        fwrite(&BFH, sizeof(BFH),  1, F);
        fwrite(BIH,  sizeof(*BIH), 1, F);
        fwrite(Buf,  DataSize,     1, F);

        fclose(F);

        delete[] BIH;
        delete[] Buf;

        return true;
}

//! \endcond Internal

//! \cond Namespaces

} //namespace TX_ADDON
} //namespace anonymous

using namespace TX_ADDON;

//! \endcond Namespaces




#endif // __TX_ADDON


//=============================================================================
// EOF
//=============================================================================
