/*
    Copyright (C) 2025  Giang Trinh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _A_LTB_001_LOGIC_BASE_MAP_H
#define _A_LTB_001_LOGIC_BASE_MAP_H


#include <QWidget>
#include <QString>

#include <QMqttClient>

#include <stdint.h>


/* =================================================================
 * About
 * - This library define a method helper for "_a_login_to_broker.h"
 *      + Define an array callback to construct Logic block by "create_polymorphism"
 *          in each Derived class of "_a_ltb_001_logic_base_ui.h"
 *      + Define an array contain map the the 'Logic block code' design for each
 *          block code in database with respective Derived class
================================================================= */



/*=================================================================
 * Definitions
================================================================= */

// function pointer to create_polymorphism() of each Derived logic control block class
typedef QWidget* (*create_UI_polymorphism_fp) (QMqttClient* mqtt_client, const QString& LB_Code, const  QString& LB_index);



/*=================================================================
 * APIs
================================================================= */

/*
 * Helper helps find and create widgets from input requests
 *  - input an empty pointer QWidget
 *  - input Logicblock code + index (distinguish between repeating blocks)
 *  - input mqtt_client of block send, receive
 *
 *  - example: QWidget* wid_get = nullptr;
 *              if(Check_logic_block_code_then_init_widget(  & wid_get , "Logic block code","logic block index", mqtt_client ) )
 *              {
 *                  // * wid_get not change
 *                  // error catch
 *              }
 *
 *              else dosomething with this QWidget
 *
 *  - return 0 if ok
 *  - else return !0 if nothing match
 *
 */
uint8_t Check_logic_block_code_then_init_widget(QWidget **Widget_created, const QString& LB_Code, const  QString& LB_index , QMqttClient* mqtt_client);




#endif // _A_LTB_001_LOGIC_BASE_MAP_H
