#ifndef __GENERAL_HANDSHAKE_TOPIC_H
#define __GENERAL_HANDSHAKE_TOPIC_H

#include <QMqttClient>

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


/* ============================================================
 * QOS
============================================================== */
#define MQTT_GENERAL_HANDSHAKE_SUBCRIBE_DEFAULT_MAX_QOS  1 // 0 1 2 . QOS1 is the most economical and reliable

#define MQTT_GENERAL_HANDSHAKE_PUBLIC_DEFAULT_QOS        1 // 0 1 2

#define MQTT_GENERAL_HANDSHAKE_PUBLIC_DEFAULT_RETAIN     1 // 1 retain, 0 not retain (mqtt client use bool tocheck)
            // should retain for recover mode


/* ============================================================
 * IMPORTANT HANDSHAKE TOPIC (MUST HAVE) (TOPIC MUST UNIQUE)
============================================================== */

// maintain flag
#define MQTT_GENERAL_HANDSHAKE_TOPIC_MAINTAIN_FLAG     "MF"
#define MQTT_GENERAL_HANDSHAKE_MAINTAIN_FLAG_BUSY      1
#define MQTT_GENERAL_HANDSHAKE_MAINTAIN_FLAG_GOOD      0

// dev board config
#define MQTT_GENERAL_HANDSHAKE_TOPIC_DEV_BOARD_CONFIG_INFO   "BC"




#endif // __GENERAL_HANDSHAKE_TOPIC_H


