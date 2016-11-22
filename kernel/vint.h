/**************************************************************************
    BuguRTOS-2.0.x (Bugurt real time operating system)
    Copyright (C) 2016 anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
#ifndef _VINT_H_
#define _VINT_H_

#ifndef BGRT_VINT_CS_START
#   define BGRT_VINT_CS_START() BGRT_INT_LOCK()
#endif //BGRT_VINT_CS_START

#ifndef BGRT_VINT_CS_END
#   define BGRT_VINT_CS_END() BGRT_INT_FREE()
#endif //BGRT_VINT_CS_END
/*!
\file
\brief \~russian Заголовок виртуальных прерываний. \~english A virtual interrupt header.
*/
//Виртуальное прерывание
typedef struct _bgrt_vint_t bgrt_vint_t;
//Свойства
/*!
\~russian
\brief
Виртуальное прерывание.

\~english
\brief
A virtual interrupt.
*/
struct _bgrt_vint_t
{
    bgrt_pitem_t parent; /*!< \~russian Родитель - #bgrt_item_t. \~english A parent - #bgrt_item_t. */
    bgrt_code_t  func;   /*!< \~russian Указатель на обработчик. \~english A virtual ISR pointer.*/
    void * arg;          /*!< \~russian Аргумент обработчика. \~english A virtual ISR arg. */
};

//Виртуальный контроллер прерываний
typedef struct _bgrt_vic_t bgrt_vic_t;
//Свойства
/*!
\~russian
\brief
Виртуальный контроллер прерываний.

\~english
\brief
A virtual interrupt controller.
*/
struct _bgrt_vic_t
{
    bgrt_xlist_t list; /*!< \~russian Родитель - #bgrt_xlist_t. \~english A parent - #bgrt_xlist_t. */
    bgrt_prio_t  prio; /*!< \~russian Текущий приоритет. \~english Current priority. */
};

//Методы
/*!
\~russian
\brief
Инициализация объект а типа #bgrt_vint_t.

\warning Для внутреннего использования.

\param vint Указатель на объект #bgrt_vint_t.
\param prio Приоритет элемента.
\param func Указатель на обработчик.
\param arg  Указатель на аргумент.

\~english
\brief
A #bgrt_vint_t object initiation.

\warning For internal usage.

\param vint A #bgrt_vint_t pointer.
\param prio A priority.
\param func An ISR pointer.
\param arg  An ISR arg pointer.
*/
void bgrt_vint_init(bgrt_vint_t * vint, bgrt_prio_t prio, bgrt_code_t func, void * arg);
/*!
\~russian
\brief
Поставить объект типа #bgrt_vint_t на обработку из обработчика прерывания.

\warning Для внутреннего использования.

\param vint Указатель на объект #bgrt_vint_t.
\param vic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Insert #bgrt_vint_t object to #bgrt_vic_t container for processing (for ISR usage).

\warning For internal usage.

\param vint A #bgrt_vint_t pointer.
\param vic A pointer to destination #bgrt_vic_t object.
*/
bgrt_st_t bgrt_vint_push_isr(bgrt_vint_t * vint, bgrt_vic_t * vic);
/*!
\~russian
\brief
Поставить объект типа #bgrt_vint_t на обработку.

\warning Для внутреннего использования.

\param vint Указатель на объект #bgrt_vint_t.
\param vic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Insert #bgrt_vint_t object to #bgrt_xlist_t container for processing.

\warning For internal usage.

\param vint A #bgrt_vint_t pointer.
\param vic A pointer to destination #bgrt_vic_t object.
*/
bgrt_st_t bgrt_vint_push(bgrt_vint_t * vint, bgrt_vic_t * vic);
/*!
\~russian
\brief
Инициализация виртуального контроллера прерываний.

\warning Для внутреннего использования.

\param vic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt controller initialization.

\warning For internal usage.

\param vic A pointer to a #bgrt_vic_t object.
*/
void bgrt_vic_init(bgrt_vic_t * vic);

/*!
\~russian
\brief
Обработка виртуальных прерываний.

\warning Для внутреннего использования.

\param vic  Указатель на виртуальный контроллер прерываний.
\return BGRT_ST_ROLL если нужна еще итерация, BGRT_ST_OK если вся работа выполнена.

\~english
\brief
Virtual interrupt processing.

\warning For internal usage.

\param vic A pointer to a #bgrt_vic_t object.
\return BGRT_ST_ROLL if next iteration needed, BGRT_ST_OK if all done.
*/
bgrt_st_t bgrt_vic_iterator(bgrt_vic_t * vic);

/*!
\~russian
\brief
Обработка виртуальных прерываний.

\warning Для внутреннего использования.

\param vic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt processing.

\warning For internal usage.

\param vic A pointer to a #bgrt_vic_t object.
*/
void bgrt_vic_do_work(bgrt_vic_t * vic);

//Виртуальный контроллер прерываний
typedef struct _bgrt_fic_t bgrt_fic_t;
//Свойства
/*!
\~russian
\brief
Виртуальный контроллер "быстрых" прерываний.

\~english
\brief
A virtual fast interrupt controller.
*/
#if defined(BGRT_CONFIG_MP) && defined(BGRT_CONFIG_FIC_LOCKED)
#   define BGRT_FIC_LOCK_OBJ bgrt_lock_t lock; /*!< \~russian Спин-блокировка. \~english A spin-lock. */
#   define BGRT_FIC_LO_INIT BGRT_SPIN_INIT
#   define BGRT_FIC_LOCK    BGRT_SPIN_LOCK
#   define BGRT_FIC_FREE    BGRT_SPIN_LOCK
#else
#   define BGRT_FIC_LOCK_OBJ
#   define BGRT_FIC_LO_INIT(a) do{}while(0)
#   define BGRT_FIC_LOCK(a)    do{}while(0)
#   define BGRT_FIC_FREE(a)    do{}while(0)
#endif // BGRT_CONFIG_MP

struct _bgrt_fic_t
{
    bgrt_index_t map;      /*!< \~russian Карта векторов "быстрых" прерываний. \~english A fast interrupt vector map.*/
    BGRT_FIC_LOCK_OBJ
};
/*!
\~russian
\brief
Инициализация виртуального контроллера "быстрых" прерываний.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt controller initialization.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_vic_t object.
*/
static inline void bgrt_fic_init_isr(bgrt_fic_t * fic)
{
    BGRT_FIC_LO_INIT(fic);
    BGRT_FIC_LOCK(fic);
    fic->map = (bgrt_index_t)0; /* ADLINT:SL:[W0422] NULL ptr deref*/
    BGRT_FIC_FREE(fic);
}
/*!
\~russian
\brief
Инициализация виртуального контроллера "быстрых" прерываний.

\param fic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt controller initialization.

\param fic A pointer to a #bgrt_vic_t object.
*/
static inline void bgrt_fic_init(bgrt_fic_t * fic) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_VINT_CS_START();
    bgrt_fic_init_isr(fic);
    BGRT_VINT_CS_END();
}
/*!
\~russian
\brief
Поставить прерывания на обработку

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.

\~english
\brief
Push vectors to fic.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
*/
static inline void bgrt_fic_push_int_isr(bgrt_fic_t * fic, bgrt_index_t msk)
{
    BGRT_FIC_LOCK(fic);
    fic->map |= msk;   /* ADLINT:SL:[W0422,W0165] NULL ptr deref*/
    BGRT_FIC_FREE(fic);
}


/*!
\~russian
\brief
Поставить прерывания на обработку.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.

\~english
\brief
Push vectors to fic.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
*/
static inline void bgrt_fic_push_int(bgrt_fic_t * fic, bgrt_index_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_VINT_CS_START();
    bgrt_fic_push_int_isr(fic,msk);
    BGRT_VINT_CS_END();
}

/*!
\~russian
\brief
Считать сотояние векторов по маске.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Masked vectirs state.
*/
static inline bgrt_index_t bgrt_fic_read_int_isr(bgrt_fic_t * fic, bgrt_index_t msk)
{
    bgrt_index_t ret;
    BGRT_FIC_LOCK(fic);
    //Get states
    ret = fic->map & msk; /* ADLINT:SL:[W0422,W0165] NULL ptr deref*/
    BGRT_FIC_FREE(fic);
    return ret; /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

/*!
\~russian
\brief
Считать сотояние векторов по маске.

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Masked vectirs state.
*/
static inline bgrt_index_t bgrt_fic_read_int(bgrt_fic_t * fic, bgrt_index_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_index_t ret;
    BGRT_VINT_CS_START();
    ret = bgrt_fic_read_int_isr(fic,msk);
    BGRT_VINT_CS_END();
    return ret; /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}
/*!
\~russian
\brief
Извлечь вектора прерываний для обработки.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Последнее состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Last masked vectors state.
*/
static inline bgrt_index_t bgrt_fic_pop_int_isr(bgrt_fic_t * fic, bgrt_index_t msk)
{
    bgrt_index_t ret;
    BGRT_FIC_LOCK(fic);
    //Get states
    ret = fic->map & msk; /* ADLINT:SL:[W0422,W0165] NULL ptr deref*/
    //Clear states
    fic->map &= ~msk;     /* ADLINT:SL:[W0422,W0165,W0578] NULL ptr deref*/
    BGRT_FIC_FREE(fic);
    return ret;           /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}
/*!
\~russian
\brief
Извлечь вектора прерываний для обработки.

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Последнее состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Last masked vectors state.
*/
static inline bgrt_index_t bgrt_fic_pop_int(bgrt_fic_t * fic, bgrt_index_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_index_t ret;
    BGRT_VINT_CS_START();
    ret = bgrt_fic_pop_int_isr(fic,msk);
    BGRT_VINT_CS_END();
    return ret;         /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

#endif // _VINT_H_
