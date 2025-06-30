/*
    Copyright (C) 2025  Giang Trinh

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


/*
 * Note: for convenient find, modidy, manage topic:
 *  - create header file like "_xxx_mqtt_topic.h"
 *  - add 5 - 10 logic block topic, not too many
 */


#ifndef _001_B0_MQTT_TOPIC_H
#define _001_B0_MQTT_TOPIC_H


/* ====================================================================
* TOPIC GROUP 1 (Test send / feed back designed port BO board type)
==================================================================== */
// T_000 test expand spi port for spi bus





// T_001test expand i2c port for spi bus






// T_002 test expand logic output port 595
#define _001_MQTT_TOPIC_T_002_595_OUTPUT_LOGIC_BLOCK_ALIAS   "LBA" // block alias


#define _001_MQTT_TOPIC_T_002_595_OUTPUT_ONOFF_PORT_ALIAS    "OA"  // outport alias
#define _001_MQTT_TOPIC_T_002_595_OUTPUT_ONOFF_PORT_CONTROL  "OC"  // outport signal
#define _001_MQTT_TOPIC_T_002_595_OUTPUT_ONOFF_PORT_FEEDBACK "OF"  // feedback change





// T_003 test expand sound output port i2s






// T_004 test expand pwm ledc port







// T_005 test expand analog input port 4067






// T_006 test expand logic input port 595






// T_007 test expand mcpwm port 595










#endif // _001_B0_MQTT_TOPICH_H
