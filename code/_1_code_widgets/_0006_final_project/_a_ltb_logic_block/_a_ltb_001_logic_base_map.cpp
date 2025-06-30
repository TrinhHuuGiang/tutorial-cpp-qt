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




#include "_a_ltb_001_logic_base_map.h"



/* ===============================================================
 * Definitions
=============================================================== */

// list of function init Widget for each logic block controller UI
const create_UI_polymorphism_fp logic_block_controller_UI_list[] =
{
    // (0 - 7) B0 _ test
    // "T_000",
    // "T_001",
    // "T_002",
    // "T_003",
    // "T_004",
    // "T_005",
    // "T_006",
    // "T_007",

    // (8 - 9) B0 _ default
    // "DF_000",
    // "DF_001"



};

const char* logic_block_controller_UI_code[] =
{
    // (0 - 7) B0 _ test
    // "T_000",
    // "T_001",
    // "T_002",
    // "T_003",
    // "T_004",
    // "T_005",
    // "T_006",
    // "T_007",

    // (8 - 9) B0 _ default
    // "DF_000",
    // "DF_001"

};

// total , calculate when compiler check
const uint32_t logic_block_UI_count = sizeof(logic_block_controller_UI_code) / sizeof(char*);




/* ===============================================================
 * Codes
=============================================================== */

/*
 * Helper helps find and create widgets from input requests
 *  - input an empty pointer QWidget
 *  - example: QWidget* wid_get = nullptr;
 *              if(Check_logic_block_code_then_init_widget(  & wid_get  ) )
 *              {
 *                  // * wid_get not change
 *                  // error catch
 *              }
 *
 *              else dosomething with this QWidget
 *
 *  - return 0 if ok, else return !0
 *
 */
uint8_t Check_logic_block_code_then_init_widget(QWidget **Widget_created, const QString& LB_Code, const  QString& LB_index, QMqttClient* mqtt_client)
{
    // Check LB code
    uint32_t count = 0;
    for(count; count < logic_block_UI_count; count++)
    {
        if(LB_Code == logic_block_controller_UI_code[count]) // QString can compare with string
        {
            // create widget and return 0
            *Widget_created = logic_block_controller_UI_list[count](mqtt_client,LB_Code, LB_index);

            // okey done
            break;
        }
    }


    // nothing match
    if(count >= logic_block_UI_count) return 1;

    // ok
    else if(count < logic_block_UI_count) return 0;

    // :( hmm seen never reach
    else return 2;

}
