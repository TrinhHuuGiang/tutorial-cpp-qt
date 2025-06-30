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


#ifndef _002_B0_MQTT_TOPIC_H
#define _002_B0_MQTT_TOPIC_H


/* ====================================================================
* TOPIC GROUP 2 (Test send / feed back default services on BO board)
==================================================================== */
// DF_000 test service check baterry
#define _001_MQTT_TOPIC_DF_000_BATTERY_CHECK_LOGIC_BLOCK_ALIAS      "LBA" // block alias

#define _001_MQTT_TOPIC_DF_000_BATTERY_CHECK_ONOFF_MEASURE_ALIAS    "OM"  // on off measure
#define _001_MQTT_TOPIC_DF_000_BATTERY_CHECK_VOLTAGE_FEEDBACK       "FV"  // feedback voltage




// DF_001 test service audio test
#define _001_MQTT_TOPIC_DF_001_AUDIO_TEST_LOGIC_BLOCK_ALIAS         "LBA" // block alias

#define _001_MQTT_TOPIC_DF_001_AUDIO_TEST_ONOFF_SPEAKER             "OS"  // on off speaker
#define _001_MQTT_TOPIC_DF_001_FEEDBACK_ONOFF_ONOFF_FEEDBACK        "FO"  // on off feedback






#endif // _002_B0_MQTT_TOPIC_H
