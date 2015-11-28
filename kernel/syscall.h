/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*!
\file
\brief \~russian Заголовок системных вызовов.

\warning Все содержимое файла для внутреннего использования!

\~english System call header.

\warning This file content is internal usage!
*/

// System call numbers!
#define SYSCALL_PROC_RUN                        ((syscall_t)(1))                                /*!< \~russian \brief Запуск процесса. \~english \brief A process launch. */
#define SYSCALL_PROC_RESTART                    (SYSCALL_PROC_RUN + (syscall_t)(1))             /*!< \~russian \brief Перезапуск процесса. \~english \brief A Process restart. */
#define SYSCALL_PROC_STOP                       (SYSCALL_PROC_RESTART + (syscall_t)(1))         /*!< \~russian \brief Останов процесса. \~english \brief A process stop. */
#define SYSCALL_PROC_SELF_STOP                  (SYSCALL_PROC_STOP + (syscall_t)(1))            /*!< \~russian \brief Самоостанов процесса. \~english \brief A process self stop. */
#define SYSCALL_PROC_TERMINATE                  (SYSCALL_PROC_SELF_STOP + (syscall_t)(1))       /*!< \~russian \brief Завершение работы процесса. \~english \brief A process termination. */
#define SYSCALL_PROC_LOCK                       (SYSCALL_PROC_TERMINATE + (syscall_t)(1))       /*!< \~russian \brief Установить флаг #PROC_FLG_LOCK для вызывающего процесса. \~english \brief #PROC_FLG_LOCK for caller process. */
#define SYSCALL_PROC_FREE                       (SYSCALL_PROC_LOCK + (syscall_t)(1))            /*!< \~russian \brief Останов процесса по флагу #PROC_FLG_PRE_STOP. \~english \brief #PROC_FLG_PRE_STOP flag processing. */
#define SYSCALL_PROC_RESET_WATCHDOG             (SYSCALL_PROC_FREE + (syscall_t)(1))            /*!< \~russian \brief Сброс watchdog процесса реального времени. \~english \brief A real time process watchdog reset. */
#define SYSCALL_PROC_SET_PRIO                   (SYSCALL_PROC_RESET_WATCHDOG + (syscall_t)(1))  /*!< \~russian \brief Установить приоритет процесса \~english \brief Set a process priority. */

#define SYSCALL_SCHED_PROC_YELD                 (SYSCALL_PROC_SET_PRIO + (syscall_t)(1))        /*!< \~russian \brief Передача управления другому процессу. \~english \brief Transfer control to another process. */

#define SYSCALL_SYNC_SET_OWNER                 (SYSCALL_SCHED_PROC_YELD + (syscall_t)(1))       /*!< \~russian \brief Установить нового хозяина объекта типа #sync_t. \~english \brief Set new #sync_t object owner. */
#define SYSCALL_SYNC_OWN                       (SYSCALL_SYNC_SET_OWNER + (syscall_t)(1))        /*!< \~russian \brief Завладеть объектом типа #sync_t. \~english \brief Own #sync_t object. */
#define SYSCALL_SYNC_TOUCH                     (SYSCALL_SYNC_OWN + (syscall_t)(1))              /*!< \~russian \brief заблокировать пробуждение процессов. \~english \brief Block process wake*/
#define SYSCALL_SYNC_SLEEP                     (SYSCALL_SYNC_TOUCH + (syscall_t)(1))            /*!< \~russian \brief Заблокировать процесс в ожидании синхронизации. \~english \brief Block process for synchronization. */
#define SYSCALL_SYNC_WAKE                      (SYSCALL_SYNC_SLEEP + (syscall_t)(1))            /*!< \~russian \brief Запустить процесс, ожидающий синхронизации. \~english \brief Run a process waiting for synchronization. */

#define SYSCALL_SYNC_WAIT                      (SYSCALL_SYNC_WAKE + (syscall_t)(1))             /*!< \~russian \brief Подождать блокировки процесса на объекте типа #sync_t. \~english \brief Wait for process to block on #sync_t object*/
#define SYSCALL_SYNC_WAKE_AND_SLEEP            (SYSCALL_SYNC_WAIT + (syscall_t)(1))             /*!< \~russian \brief Смотри #SYSCALL_SYNC_WAKE и #SYSCALL_SYNC_SLEEP. \~english \brief Watch #SYSCALL_SYNC_WAKE and #SYSCALL_SYNC_SLEEP. */
#define SYSCALL_SYNC_WAKE_AND_WAIT             (SYSCALL_SYNC_WAKE_AND_SLEEP + (syscall_t)(1))   /*!< \~russian \brief Смотри #SYSCALL_SYNC_WAKE и #SYSCALL_SYNC_WAIT. \~english \brief Watch #SYSCALL_SYNC_WAKE and #SYSCALL_SYNC_WAIT. */
#define SYSCALL_SYNC_PROC_TIMEOUT              (SYSCALL_SYNC_WAKE_AND_WAIT + (syscall_t)(1))   /*!< \~russian \brief Разбудить процесс по таймауту. \~english \brief Wake a process on timeout. */
#define SYSCALL_USER                           (SYSCALL_SYNC_PROC_TIMEOUT + (syscall_t)(1))    /*!< \~russian \brief Пользовательский системный вызов. \~english \brief User system call. */
/*!
\~russian
\brief
Обработка системного вызова.

Запускает обработчик системного вызова и передает ему аргумент.

\~english
\brief
System call processing routine.

This function calls system call handlers and passes arguments to them.
*/
void do_syscall(
                syscall_t syscall_num,  /*!< \~russian \brief Номер системного вызова. \~english \brief System call number.*/
                void * syscall_arg      /*!< \~russian \brief Aргумент системного вызова. \~english \brief System call argument.*/
                );

/*****************************************************************************************/
/*                               System call handlers !!!                                */
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_USER.
\~english
\brief
A #SYSCALL_USER handler.
*/
void scall_user(void * arg);
#endif // _SYSCALL_H_
