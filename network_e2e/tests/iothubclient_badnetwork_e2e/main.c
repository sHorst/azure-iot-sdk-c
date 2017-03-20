// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"
#include "iothub_client_ll.h"
#include "iothubtransportamqp.h"
#include "iothubtransporthttp.h"
#include "iothubtransportmqtt.h"
#include "iothubtransportamqp_websockets.h"
#include "iothubtransportmqtt_websockets.h"

extern void set_badnetwork_test_protocol(IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol);

int main(int argc, char* argv[])
{
    IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol = NULL;
    size_t failedTestCount = 0;
    if (argc == 1)
    {
        printf("Using AMQP\r\n");
        protocol = AMQP_Protocol;
    }
    if (argc == 2)
    {
        
        if (strcmp(argv[1], "AMQP") == 0)
        {
            printf("Using AMQP\r\n");
            protocol = AMQP_Protocol;
        }
        if (strcmp(argv[1], "AMQP-WS") == 0)
        {
            printf("Using AMQP-WS\r\n");
            protocol = AMQP_Protocol_over_WebSocketsTls;
        }
        else if (strcmp(argv[1], "MQTT") == 0)
        {
            printf("Using MQTT\r\n");
            protocol = MQTT_Protocol;
        }
        else if (strcmp(argv[1], "MQTT-WS") == 0)
        {
            printf("Using MQTT-WS\r\n");
            protocol = MQTT_WebSocket_Protocol;
        }
        else if (strcmp(argv[1], "HTTP") == 0)
        {
            printf("Using HTTP\r\n");
            protocol = HTTP_Protocol;
        }
    }

    if (protocol == NULL)
    {
        printf("Usage: iothubclient_badnetwork_e2e [protocol]\n");
        printf("protocol = one of [AMQP, AMQP-WS, MQTT, MQTT-WS, HTTP]\n");
    }
    set_badnetwork_test_protocol(protocol);
    RUN_TEST_SUITE(iothubclient_badnetwork_e2e, failedTestCount);
    return failedTestCount;
}
